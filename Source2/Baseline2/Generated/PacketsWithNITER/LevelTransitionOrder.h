
#ifndef LEVELTRANSITIONORDER_H_INCLUDED
#define LEVELTRANSITIONORDER_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_LevelTransitionOrder
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) 

- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): Fraunhofer FOKUS

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.       
============================================================================= */

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"
#include "LevelTransitionOrder_1.h"

struct LevelTransitionOrder
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Packet to identify where a level transition shall take place. In
    // case of mixed levels, the successive M_LEVELTRís go from the highest
    // priority level to the lowest one.
    // Packet Number = 41

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_LEVELTR;        // # 15
    uint64_t   M_LEVELTR;        // # 3
    uint64_t   NID_STM;          // # 8
    uint64_t  L_ACKLEVELTR;     // # 15
    uint64_t   N_ITER_1;         // # 5
    LevelTransitionOrder_1   sub_1[31];
};

typedef struct LevelTransitionOrder LevelTransitionOrder;

#define LEVELTRANSITIONORDER_BITSIZE 55

/*@
    logic integer BitSize{L}(LevelTransitionOrder* p) = LEVELTRANSITIONORDER_BITSIZE;

    logic integer MaxBitSize{L}(LevelTransitionOrder* p) = BitSize(p);

    predicate Separated(Bitstream* stream, LevelTransitionOrder* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(LevelTransitionOrder* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_LEVELTR)         &&
      Invariant(p->M_LEVELTR);

    predicate ZeroInitialized(LevelTransitionOrder* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_LEVELTR)         &&
      ZeroInitialized(p->M_LEVELTR);

    predicate EqualBits(Bitstream* stream, integer pos, LevelTransitionOrder* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_LEVELTR)         &&
      EqualBits(stream, pos + 32,  pos + 35,  p->M_LEVELTR);

    predicate UpperBitsNotSet(LevelTransitionOrder* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_LEVELTR,        15)  &&
      UpperBitsNotSet(p->M_LEVELTR,        3);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int LevelTransitionOrder_UpperBitsNotSet(const LevelTransitionOrder* p);

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid_read(p);
    requires invariant:         Invariant(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures left:       Unchanged{Here,Old}(stream, 0, \old(stream->bitpos));
      ensures middle:     EqualBits(stream, \old(stream->bitpos), p);
      ensures right:      Unchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    behavior values_too_big:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures result:        \result == -2;

    behavior invalid_bit_sequence:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result:       \result == -1;

    complete behaviors;
    disjoint behaviors;
*/
int LevelTransitionOrder_EncodeBit(const LevelTransitionOrder* p, Bitstream* stream);

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          Unchanged{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures invariant:  Invariant(p);
      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), p);
      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int LevelTransitionOrder_DecodeBit(LevelTransitionOrder* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

LevelTransitionOrder*  LevelTransitionOrder_New(void);

void   LevelTransitionOrder_Delete(LevelTransitionOrder*);

static inline void LevelTransitionOrder_Init(LevelTransitionOrder* p)
{
    p->header.NID_PACKET = 41;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->D_LEVELTR = 0;
    p->M_LEVELTR = 0;
    p->NID_STM = 0;
    p->L_ACKLEVELTR = 0;
    p->N_ITER_1 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        LevelTransitionOrder_1_Init(&(p->sub_1[i]));
    }

}

static inline void LevelTransitionOrder_Print(const LevelTransitionOrder* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->D_LEVELTR,
            p->M_LEVELTR,
            p->NID_STM,
            p->L_ACKLEVELTR,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        LevelTransitionOrder_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int LevelTransitionOrder_Equal(const LevelTransitionOrder* a, const LevelTransitionOrder* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->D_LEVELTR == b->D_LEVELTR);
    status = status && (a->M_LEVELTR == b->M_LEVELTR);

    if (a->M_LEVELTR == 1)
    {
        status = status && (a->NID_STM == b->NID_STM);
    }
    status = status && (a->L_ACKLEVELTR == b->L_ACKLEVELTR);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && LevelTransitionOrder_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t LevelTransitionOrder_Length(const LevelTransitionOrder* p)
{
    return (uint32_t)(p->L_PACKET);
}

int LevelTransitionOrder_EncodeInt(const LevelTransitionOrder* p, Metadata* data, kcg_int* stream);

int LevelTransitionOrder_DecodeInt(LevelTransitionOrder* p, const Metadata* data, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // LEVELTRANSITIONORDER_H_INCLUDED


