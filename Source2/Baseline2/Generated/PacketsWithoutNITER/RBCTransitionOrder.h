
#ifndef RBCTRANSITIONORDER_H_INCLUDED
#define RBCTRANSITIONORDER_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_RBCTransitionOrder
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

struct RBCTransitionOrder
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Packet to order an RBC transition
    // Packet Number = 131

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_RBCTR;          // # 15
    uint64_t  NID_C;            // # 10
    uint64_t  NID_RBC;          // # 14
    uint64_t  NID_RADIO;        // # 64
    uint64_t   Q_SLEEPSESSION;   // # 1
};

typedef struct RBCTransitionOrder RBCTransitionOrder;

#define RBCTRANSITIONORDER_BITSIZE 121

RBCTransitionOrder*  RBCTransitionOrder_New(void);

void   RBCTransitionOrder_Delete(RBCTransitionOrder*);

static inline void RBCTransitionOrder_Init(RBCTransitionOrder* p)
{
    p->header.NID_PACKET = 131;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->D_RBCTR = 0;
    p->NID_C = 0;
    p->NID_RBC = 0;
    p->NID_RADIO = 0;
    p->Q_SLEEPSESSION = 0;
}

/*@
    logic integer BitSize{L}(RBCTransitionOrder* p) = RBCTRANSITIONORDER_BITSIZE;

    logic integer MaxBitSize{L}(RBCTransitionOrder* p) = BitSize(p);

    predicate Separated(Bitstream* stream, RBCTransitionOrder* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(RBCTransitionOrder* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_RBCTR)           &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_RBC)           &&
      Invariant(p->NID_RADIO)         &&
      Invariant(p->Q_SLEEPSESSION);

    predicate ZeroInitialized(RBCTransitionOrder* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_RBCTR)           &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_RBC)           &&
      ZeroInitialized(p->NID_RADIO)         &&
      ZeroInitialized(p->Q_SLEEPSESSION);

    predicate EqualBits(Bitstream* stream, integer pos, RBCTransitionOrder* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_RBCTR)           &&
      EqualBits(stream, pos + 32,  pos + 42,  p->NID_C)             &&
      EqualBits(stream, pos + 42,  pos + 56,  p->NID_RBC)           &&
      EqualBits(stream, pos + 56,  pos + 120, p->NID_RADIO)         &&
      EqualBits(stream, pos + 120, pos + 121, p->Q_SLEEPSESSION);

    predicate UpperBitsNotSet(RBCTransitionOrder* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_RBCTR,          15)  &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_RBC,          14)  &&
      UpperBitsNotSet(p->NID_RADIO,        64)  &&
      UpperBitsNotSet(p->Q_SLEEPSESSION,   1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int RBCTransitionOrder_UpperBitsNotSet(const RBCTransitionOrder* p);

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
int RBCTransitionOrder_EncodeBit(const RBCTransitionOrder* p, Bitstream* stream);

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
int RBCTransitionOrder_DecodeBit(RBCTransitionOrder* p, Bitstream* stream);

static inline void RBCTransitionOrder_Print(const RBCTransitionOrder* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu)",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->D_RBCTR,
            p->NID_C,
            p->NID_RBC,
            p->NID_RADIO,
            p->Q_SLEEPSESSION);
}

static inline int RBCTransitionOrder_Equal(const RBCTransitionOrder* a, const RBCTransitionOrder* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->D_RBCTR == b->D_RBCTR);
    status = status && (a->NID_C == b->NID_C);
    status = status && (a->NID_RBC == b->NID_RBC);
    status = status && (a->NID_RADIO == b->NID_RADIO);
    status = status && (a->Q_SLEEPSESSION == b->Q_SLEEPSESSION);

    return status;
}

static inline uint32_t RBCTransitionOrder_Length(const RBCTransitionOrder* p)
{
    return (uint32_t)(p->L_PACKET);
}

int RBCTransitionOrder_EncodeInt(const RBCTransitionOrder* p, Metadata* data, kcg_int* stream);

int RBCTransitionOrder_DecodeInt(RBCTransitionOrder* p, const Metadata* data, const kcg_int* stream);

#endif // RBCTRANSITIONORDER_H_INCLUDED

