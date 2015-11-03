
#ifndef TRACKCONDITIONBIGMETALMASSES_1_H_INCLUDED
#define TRACKCONDITIONBIGMETALMASSES_1_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct TrackConditionBigMetalMasses_1
{

    uint64_t  D_TRACKCOND;      // # 15
    uint64_t  L_TRACKCOND;      // # 15
};

typedef struct TrackConditionBigMetalMasses_1 TrackConditionBigMetalMasses_1;

#define TRACKCONDITIONBIGMETALMASSES_1_BITSIZE 30

static inline void TrackConditionBigMetalMasses_1_Init(TrackConditionBigMetalMasses_1* p)
{
    p->D_TRACKCOND = 0;
    p->L_TRACKCOND = 0;
}

/*@
    logic integer BitSize{L}(TrackConditionBigMetalMasses_1* p) = TRACKCONDITIONBIGMETALMASSES_1_BITSIZE;

    logic integer MaxBitSize{L}(TrackConditionBigMetalMasses_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, TrackConditionBigMetalMasses_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(TrackConditionBigMetalMasses_1* p) =
      Invariant(p->D_TRACKCOND)       &&
      Invariant(p->L_TRACKCOND);

    predicate ZeroInitialized(TrackConditionBigMetalMasses_1* p) =
      ZeroInitialized(p->D_TRACKCOND)       &&
      ZeroInitialized(p->L_TRACKCOND);

    predicate EqualBits(Bitstream* stream, integer pos, TrackConditionBigMetalMasses_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_TRACKCOND)       &&
      EqualBits(stream, pos + 15,  pos + 30,  p->L_TRACKCOND);

    predicate UpperBitsNotSet(TrackConditionBigMetalMasses_1* p) =
      UpperBitsNotSet(p->D_TRACKCOND,      15)  &&
      UpperBitsNotSet(p->L_TRACKCOND,      15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int TrackConditionBigMetalMasses_1_UpperBitsNotSet(const TrackConditionBigMetalMasses_1* p);

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
int TrackConditionBigMetalMasses_1_EncodeBit(const TrackConditionBigMetalMasses_1* p, Bitstream* stream);

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
int TrackConditionBigMetalMasses_1_DecodeBit(TrackConditionBigMetalMasses_1* p, Bitstream* stream);

static inline void TrackConditionBigMetalMasses_1_Print(const TrackConditionBigMetalMasses_1* p, FILE* stream)
{
    fprintf(stream, "(%lu,%lu)",
            p->D_TRACKCOND,
            p->L_TRACKCOND);
}

static inline int TrackConditionBigMetalMasses_1_Equal(const TrackConditionBigMetalMasses_1* a, const TrackConditionBigMetalMasses_1* b)
{
    int status = 1;

    status = status && (a->D_TRACKCOND == b->D_TRACKCOND);
    status = status && (a->L_TRACKCOND == b->L_TRACKCOND);

    return status;
}

int TrackConditionBigMetalMasses_1_EncodeInt(const TrackConditionBigMetalMasses_1* p, kcg_int* startAddress, kcg_int* stream);

int TrackConditionBigMetalMasses_1_DecodeInt(TrackConditionBigMetalMasses_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // TRACKCONDITIONBIGMETALMASSES_1_H_INCLUDED

