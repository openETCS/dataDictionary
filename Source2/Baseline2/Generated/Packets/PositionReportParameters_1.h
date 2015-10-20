
#ifndef POSITIONREPORTPARAMETERS_1_H_INCLUDED
#define POSITIONREPORTPARAMETERS_1_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"

struct PositionReportParameters_1
{

    uint64_t  D_LOC;            // # 15
    uint64_t   Q_LGTLOC;         // # 1
};

typedef struct PositionReportParameters_1 PositionReportParameters_1;

#define POSITIONREPORTPARAMETERS_1_BITSIZE 16

PositionReportParameters_1*  PositionReportParameters_1_New(void);

void   PositionReportParameters_1_Delete(PositionReportParameters_1*);

static inline void PositionReportParameters_1_Init(PositionReportParameters_1* p)
{
}

/*@
    logic integer BitSize{L}(PositionReportParameters_1* p) = POSITIONREPORTPARAMETERS_1_BITSIZE;

    logic integer MaxBitSize{L}(PositionReportParameters_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, PositionReportParameters_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(PositionReportParameters_1* p) =
      Invariant(p->D_LOC)             &&
      Invariant(p->Q_LGTLOC);

    predicate ZeroInitialized(PositionReportParameters_1* p) =
      ZeroInitialized(p->D_LOC)             &&
      ZeroInitialized(p->Q_LGTLOC);

    predicate EqualBits(Bitstream* stream, integer pos, PositionReportParameters_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_LOC)             &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_LGTLOC);

    predicate UpperBitsNotSet(PositionReportParameters_1* p) =
      UpperBitsNotSet(p->D_LOC,            15)  &&
      UpperBitsNotSet(p->Q_LGTLOC,         1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int PositionReportParameters_1_UpperBitsNotSet(const PositionReportParameters_1* p);

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
int PositionReportParameters_1_EncodeBit(const PositionReportParameters_1* p, Bitstream* stream);

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
int PositionReportParameters_1_DecodeBit(PositionReportParameters_1* p, Bitstream* stream);

static inline void PositionReportParameters_1_Print(const PositionReportParameters_1* p, FILE* stream)
{
    fprintf(stream, "(%"PRIu64",%"PRIu64")",
            p->D_LOC,
            p->Q_LGTLOC);
}

static inline int PositionReportParameters_1_Equal(const PositionReportParameters_1* a, const PositionReportParameters_1* b)
{
    int status = 1;

    status = status && (a->D_LOC == b->D_LOC);
    status = status && (a->Q_LGTLOC == b->Q_LGTLOC);

    return status;
}

#endif // POSITIONREPORTPARAMETERS_1_H_INCLUDED

