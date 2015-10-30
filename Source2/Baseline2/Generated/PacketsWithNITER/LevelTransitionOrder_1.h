
#ifndef LEVELTRANSITIONORDER_1_H_INCLUDED
#define LEVELTRANSITIONORDER_1_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct LevelTransitionOrder_1
{

    uint64_t   M_LEVELTR;        // # 3
    uint64_t   NID_STM;          // # 8
    uint64_t  L_ACKLEVELTR;     // # 15
};

typedef struct LevelTransitionOrder_1 LevelTransitionOrder_1;

#define LEVELTRANSITIONORDER_1_BITSIZE 18

static inline void LevelTransitionOrder_1_Init(LevelTransitionOrder_1* p)
{
    p->M_LEVELTR = 0;
    p->NID_STM = 0;
    p->L_ACKLEVELTR = 0;
}

/*@
    logic integer BitSize{L}(LevelTransitionOrder_1* p) = LEVELTRANSITIONORDER_1_BITSIZE;

    logic integer MaxBitSize{L}(LevelTransitionOrder_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, LevelTransitionOrder_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(LevelTransitionOrder_1* p) =
      Invariant(p->M_LEVELTR);

    predicate ZeroInitialized(LevelTransitionOrder_1* p) =
      ZeroInitialized(p->M_LEVELTR);

    predicate EqualBits(Bitstream* stream, integer pos, LevelTransitionOrder_1* p) =
      EqualBits(stream, pos,       pos + 3,   p->M_LEVELTR);

    predicate UpperBitsNotSet(LevelTransitionOrder_1* p) =
      UpperBitsNotSet(p->M_LEVELTR,        3);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int LevelTransitionOrder_1_UpperBitsNotSet(const LevelTransitionOrder_1* p);

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
int LevelTransitionOrder_1_EncodeBit(const LevelTransitionOrder_1* p, Bitstream* stream);

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
int LevelTransitionOrder_1_DecodeBit(LevelTransitionOrder_1* p, Bitstream* stream);

static inline void LevelTransitionOrder_1_Print(const LevelTransitionOrder_1* p, FILE* stream)
{
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64")",
            p->M_LEVELTR,
            p->NID_STM,
            p->L_ACKLEVELTR);
}

static inline int LevelTransitionOrder_1_Equal(const LevelTransitionOrder_1* a, const LevelTransitionOrder_1* b)
{
    int status = 1;

    status = status && (a->M_LEVELTR == b->M_LEVELTR);

    if (a->M_LEVELTR == 1)
    {
        status = status && (a->NID_STM == b->NID_STM);
    }
    status = status && (a->L_ACKLEVELTR == b->L_ACKLEVELTR);

    return status;
}

int LevelTransitionOrder_1_EncodeInt(const LevelTransitionOrder_1* p, kcg_int* startAddress, kcg_int* stream);

int LevelTransitionOrder_1_DecodeInt(LevelTransitionOrder_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // LEVELTRANSITIONORDER_1_H_INCLUDED

