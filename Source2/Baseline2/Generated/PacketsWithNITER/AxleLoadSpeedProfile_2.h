
#ifndef AXLELOADSPEEDPROFILE_2_H_INCLUDED
#define AXLELOADSPEEDPROFILE_2_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_AxleLoadSpeedProfile
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
#include "AxleLoadSpeedProfile_2_1.h"

struct AxleLoadSpeedProfile_2
{

    uint64_t  D_AXLELOAD;       // # 15
    uint64_t  L_AXLELOAD;       // # 15
    uint64_t   Q_FRONT;          // # 1
    uint64_t   N_ITER_2_1;       // # 5
    AxleLoadSpeedProfile_2_1   sub_2_1[31];
};

typedef struct AxleLoadSpeedProfile_2 AxleLoadSpeedProfile_2;

#define AXLELOADSPEEDPROFILE_2_BITSIZE 36

/*@
    logic integer BitSize{L}(AxleLoadSpeedProfile_2* p) = AXLELOADSPEEDPROFILE_2_BITSIZE;

    logic integer MaxBitSize{L}(AxleLoadSpeedProfile_2* p) = BitSize(p);

    predicate Separated(Bitstream* stream, AxleLoadSpeedProfile_2* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(AxleLoadSpeedProfile_2* p) =
      Invariant(p->D_AXLELOAD)        &&
      Invariant(p->L_AXLELOAD)        &&
      Invariant(p->Q_FRONT);

    predicate ZeroInitialized(AxleLoadSpeedProfile_2* p) =
      ZeroInitialized(p->D_AXLELOAD)        &&
      ZeroInitialized(p->L_AXLELOAD)        &&
      ZeroInitialized(p->Q_FRONT);

    predicate EqualBits(Bitstream* stream, integer pos, AxleLoadSpeedProfile_2* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_AXLELOAD)        &&
      EqualBits(stream, pos + 15,  pos + 30,  p->L_AXLELOAD)        &&
      EqualBits(stream, pos + 30,  pos + 31,  p->Q_FRONT);

    predicate UpperBitsNotSet(AxleLoadSpeedProfile_2* p) =
      UpperBitsNotSet(p->D_AXLELOAD,       15)  &&
      UpperBitsNotSet(p->L_AXLELOAD,       15)  &&
      UpperBitsNotSet(p->Q_FRONT,          1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int AxleLoadSpeedProfile_2_UpperBitsNotSet(const AxleLoadSpeedProfile_2* p);

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
int AxleLoadSpeedProfile_2_EncodeBit(const AxleLoadSpeedProfile_2* p, Bitstream* stream);

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

      ensures result: \result == 0; complete behaviors;
    disjoint behaviors;
*/
int AxleLoadSpeedProfile_2_DecodeBit(AxleLoadSpeedProfile_2* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

static inline void AxleLoadSpeedProfile_2_Init(AxleLoadSpeedProfile_2* p)
{
    p->D_AXLELOAD = 0;
    p->L_AXLELOAD = 0;
    p->Q_FRONT = 0;
    p->N_ITER_2_1 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        AxleLoadSpeedProfile_2_1_Init(&(p->sub_2_1[i]));
    }

}

static inline void AxleLoadSpeedProfile_2_Print(const AxleLoadSpeedProfile_2* p, FILE* stream)
{
    fprintf(stream, "(%lu,%lu,%lu,%lu",
            p->D_AXLELOAD,
            p->L_AXLELOAD,
            p->Q_FRONT,
            p->N_ITER_2_1);

    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        AxleLoadSpeedProfile_2_1_Print(&p->sub_2_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int AxleLoadSpeedProfile_2_Equal(const AxleLoadSpeedProfile_2* a, const AxleLoadSpeedProfile_2* b)
{
    int status = 1;

    status = status && (a->D_AXLELOAD == b->D_AXLELOAD);
    status = status && (a->L_AXLELOAD == b->L_AXLELOAD);
    status = status && (a->Q_FRONT == b->Q_FRONT);
    status = status && (a->N_ITER_2_1 == b->N_ITER_2_1);
    if (a->N_ITER_2_1 == b->N_ITER_2_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_2_1; ++i)
        {
            status = status && AxleLoadSpeedProfile_2_1_Equal(&a->sub_2_1[i], &b->sub_2_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

int AxleLoadSpeedProfile_2_EncodeInt(const AxleLoadSpeedProfile_2* p, kcg_int* startAddress, kcg_int* stream);

int AxleLoadSpeedProfile_2_DecodeInt(AxleLoadSpeedProfile_2* p, kcg_int* startAddress, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // AXLELOADSPEEDPROFILE_2_H_INCLUDED

