
#ifndef CONDITIONALLEVELTRANSITIONORDER_H_INCLUDED
#define CONDITIONALLEVELTRANSITIONORDER_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"
#include "ConditionalLevelTransitionOrder_1.h"

struct ConditionalLevelTransitionOrder
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Packet for a conditional level transition. The successive M_LEVELTR’s go from
    // the highest priority level to the lowest one.
    // Packet Number = 46

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   M_LEVELTR;        // # 3
    uint64_t   NID_STM;          // # 8
    uint64_t   N_ITER_1;         // # 5
    ConditionalLevelTransitionOrder_1   sub_1[31];
};

typedef struct ConditionalLevelTransitionOrder ConditionalLevelTransitionOrder;

#define CONDITIONALLEVELTRANSITIONORDER_BITSIZE 23

ConditionalLevelTransitionOrder*  ConditionalLevelTransitionOrder_New(void);

void   ConditionalLevelTransitionOrder_Delete(ConditionalLevelTransitionOrder*);

static inline void ConditionalLevelTransitionOrder_Init(ConditionalLevelTransitionOrder* p)
{
    p->header.NID_PACKET = 46;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->M_LEVELTR = 0;
    p->NID_STM = 0;
    p->N_ITER_1 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        ConditionalLevelTransitionOrder_1_Init(&(p->sub_1[i]));
    }

}

/*@
    logic integer BitSize{L}(ConditionalLevelTransitionOrder* p) = CONDITIONALLEVELTRANSITIONORDER_BITSIZE;

    logic integer MaxBitSize{L}(ConditionalLevelTransitionOrder* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ConditionalLevelTransitionOrder* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ConditionalLevelTransitionOrder* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->M_LEVELTR);

    predicate ZeroInitialized(ConditionalLevelTransitionOrder* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->M_LEVELTR);

    predicate EqualBits(Bitstream* stream, integer pos, ConditionalLevelTransitionOrder* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 18,  p->M_LEVELTR);

    predicate UpperBitsNotSet(ConditionalLevelTransitionOrder* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->M_LEVELTR,        3);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ConditionalLevelTransitionOrder_UpperBitsNotSet(const ConditionalLevelTransitionOrder* p);

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
int ConditionalLevelTransitionOrder_EncodeBit(const ConditionalLevelTransitionOrder* p, Bitstream* stream);

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
int ConditionalLevelTransitionOrder_DecodeBit(ConditionalLevelTransitionOrder* p, Bitstream* stream);

static inline void ConditionalLevelTransitionOrder_Print(const ConditionalLevelTransitionOrder* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64"",
            p->Q_DIR,
            p->L_PACKET,
            p->M_LEVELTR,
            p->NID_STM,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        ConditionalLevelTransitionOrder_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int ConditionalLevelTransitionOrder_Equal(const ConditionalLevelTransitionOrder* a, const ConditionalLevelTransitionOrder* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->M_LEVELTR == b->M_LEVELTR);

    if (a->M_LEVELTR == 1)
    {
        status = status && (a->NID_STM == b->NID_STM);
    }
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && ConditionalLevelTransitionOrder_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t ConditionalLevelTransitionOrder_Length(const ConditionalLevelTransitionOrder* p)
{
    return (uint32_t)(p->L_PACKET);
}

int ConditionalLevelTransitionOrder_EncodeInt(const ConditionalLevelTransitionOrder* p, PacketInfo* data, kcg_int* stream);

int ConditionalLevelTransitionOrder_DecodeInt(ConditionalLevelTransitionOrder* p, const PacketInfo* data, const kcg_int* stream);

#endif // CONDITIONALLEVELTRANSITIONORDER_H_INCLUDED

