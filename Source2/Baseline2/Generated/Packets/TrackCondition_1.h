
#ifndef TRACKCONDITION_1_H_INCLUDED
#define TRACKCONDITION_1_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"

struct TrackCondition_1
{

    uint64_t  D_TRACKCOND;      // # 15
    uint64_t  L_TRACKCOND;      // # 15
    uint64_t   M_TRACKCOND;      // # 4
};

typedef struct TrackCondition_1 TrackCondition_1;

#define TRACKCONDITION_1_BITSIZE 34

TrackCondition_1*  TrackCondition_1_New();

void   TrackCondition_1_Delete(TrackCondition_1*);

static inline void TrackCondition_1_Init(TrackCondition_1* p)
{
}

/*@
    logic integer BitSize{L}(TrackCondition_1* p) = TRACKCONDITION_1_BITSIZE;

    logic integer MaxBitSize{L}(TrackCondition_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, TrackCondition_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(TrackCondition_1* p) =
      Invariant(p->D_TRACKCOND)       &&
      Invariant(p->L_TRACKCOND)       &&
      Invariant(p->M_TRACKCOND);

    predicate ZeroInitialized(TrackCondition_1* p) =
      ZeroInitialized(p->D_TRACKCOND)       &&
      ZeroInitialized(p->L_TRACKCOND)       &&
      ZeroInitialized(p->M_TRACKCOND);

    predicate EqualBits(Bitstream* stream, integer pos, TrackCondition_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_TRACKCOND)       &&
      EqualBits(stream, pos + 15,  pos + 30,  p->L_TRACKCOND)       &&
      EqualBits(stream, pos + 30,  pos + 34,  p->M_TRACKCOND);

    predicate UpperBitsNotSet(TrackCondition_1* p) =
      UpperBitsNotSet(p->D_TRACKCOND,      15)  &&
      UpperBitsNotSet(p->L_TRACKCOND,      15)  &&
      UpperBitsNotSet(p->M_TRACKCOND,      4);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int TrackCondition_1_UpperBitsNotSet(const TrackCondition_1* p);

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
int TrackCondition_1_EncodeBit(const TrackCondition_1* p, Bitstream* stream);

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
int TrackCondition_1_DecodeBit(TrackCondition_1* p, Bitstream* stream);

static inline void TrackCondition_1_Print(const TrackCondition_1* p, FILE* stream)
{
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64")",
            p->D_TRACKCOND,
            p->L_TRACKCOND,
            p->M_TRACKCOND);
}

static inline int TrackCondition_1_Equal(const TrackCondition_1* a, const TrackCondition_1* b)
{
    int status = 1;

    status = status && (a->D_TRACKCOND == b->D_TRACKCOND);
    status = status && (a->L_TRACKCOND == b->L_TRACKCOND);
    status = status && (a->M_TRACKCOND == b->M_TRACKCOND);

    return status;
}

#endif // TRACKCONDITION_1_H_INCLUDED

