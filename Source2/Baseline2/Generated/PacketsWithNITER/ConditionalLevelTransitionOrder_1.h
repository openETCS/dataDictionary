
#ifndef CONDITIONALLEVELTRANSITIONORDER_1_H_INCLUDED
#define CONDITIONALLEVELTRANSITIONORDER_1_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct ConditionalLevelTransitionOrder_1
{

    uint64_t   M_LEVELTR;        // # 3
    uint64_t   NID_STM;          // # 8
};

typedef struct ConditionalLevelTransitionOrder_1 ConditionalLevelTransitionOrder_1;

#define CONDITIONALLEVELTRANSITIONORDER_1_BITSIZE 3

static inline void ConditionalLevelTransitionOrder_1_Init(ConditionalLevelTransitionOrder_1* p)
{
    p->M_LEVELTR = 0;
    p->NID_STM = 0;
}

/*@
    logic integer BitSize{L}(ConditionalLevelTransitionOrder_1* p) = CONDITIONALLEVELTRANSITIONORDER_1_BITSIZE;

    logic integer MaxBitSize{L}(ConditionalLevelTransitionOrder_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ConditionalLevelTransitionOrder_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ConditionalLevelTransitionOrder_1* p) =
      Invariant(p->M_LEVELTR);

    predicate ZeroInitialized(ConditionalLevelTransitionOrder_1* p) =
      ZeroInitialized(p->M_LEVELTR);

    predicate EqualBits(Bitstream* stream, integer pos, ConditionalLevelTransitionOrder_1* p) =
      EqualBits(stream, pos,       pos + 3,   p->M_LEVELTR);

    predicate UpperBitsNotSet(ConditionalLevelTransitionOrder_1* p) =
      UpperBitsNotSet(p->M_LEVELTR,        3);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ConditionalLevelTransitionOrder_1_UpperBitsNotSet(const ConditionalLevelTransitionOrder_1* p);

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
int ConditionalLevelTransitionOrder_1_EncodeBit(const ConditionalLevelTransitionOrder_1* p, Bitstream* stream);

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
int ConditionalLevelTransitionOrder_1_DecodeBit(ConditionalLevelTransitionOrder_1* p, Bitstream* stream);

static inline void ConditionalLevelTransitionOrder_1_Print(const ConditionalLevelTransitionOrder_1* p, FILE* stream)
{
    fprintf(stream, "(%lu,%lu)",
            p->M_LEVELTR,
            p->NID_STM);
}

static inline int ConditionalLevelTransitionOrder_1_Equal(const ConditionalLevelTransitionOrder_1* a, const ConditionalLevelTransitionOrder_1* b)
{
    int status = 1;

    status = status && (a->M_LEVELTR == b->M_LEVELTR);

    if (a->M_LEVELTR == 1)
    {
        status = status && (a->NID_STM == b->NID_STM);
    }

    return status;
}

int ConditionalLevelTransitionOrder_1_EncodeInt(const ConditionalLevelTransitionOrder_1* p, kcg_int* startAddress, kcg_int* stream);

int ConditionalLevelTransitionOrder_1_DecodeInt(ConditionalLevelTransitionOrder_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // CONDITIONALLEVELTRANSITIONORDER_1_H_INCLUDED

