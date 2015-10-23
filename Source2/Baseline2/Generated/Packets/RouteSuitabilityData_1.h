
#ifndef ROUTESUITABILITYDATA_1_H_INCLUDED
#define ROUTESUITABILITYDATA_1_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct RouteSuitabilityData_1
{

    uint64_t  D_SUITABILITY;    // # 15
    uint64_t   Q_SUITABILITY;    // # 2
    uint64_t   M_LOADINGGAUGE;   // # 8
    uint64_t   M_AXLELOAD;       // # 7
    uint64_t   M_TRACTION;       // # 8
};

typedef struct RouteSuitabilityData_1 RouteSuitabilityData_1;

#define ROUTESUITABILITYDATA_1_BITSIZE 17

RouteSuitabilityData_1*  RouteSuitabilityData_1_New(void);

void   RouteSuitabilityData_1_Delete(RouteSuitabilityData_1*);

static inline void RouteSuitabilityData_1_Init(RouteSuitabilityData_1* p)
{
}

/*@
    logic integer BitSize{L}(RouteSuitabilityData_1* p) = ROUTESUITABILITYDATA_1_BITSIZE;

    logic integer MaxBitSize{L}(RouteSuitabilityData_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, RouteSuitabilityData_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(RouteSuitabilityData_1* p) =
      Invariant(p->D_SUITABILITY)     &&
      Invariant(p->Q_SUITABILITY);

    predicate ZeroInitialized(RouteSuitabilityData_1* p) =
      ZeroInitialized(p->D_SUITABILITY)     &&
      ZeroInitialized(p->Q_SUITABILITY);

    predicate EqualBits(Bitstream* stream, integer pos, RouteSuitabilityData_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_SUITABILITY)     &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SUITABILITY);

    predicate UpperBitsNotSet(RouteSuitabilityData_1* p) =
      UpperBitsNotSet(p->D_SUITABILITY,    15)  &&
      UpperBitsNotSet(p->Q_SUITABILITY,    2);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int RouteSuitabilityData_1_UpperBitsNotSet(const RouteSuitabilityData_1* p);

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
int RouteSuitabilityData_1_EncodeBit(const RouteSuitabilityData_1* p, Bitstream* stream);

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
int RouteSuitabilityData_1_DecodeBit(RouteSuitabilityData_1* p, Bitstream* stream);

static inline void RouteSuitabilityData_1_Print(const RouteSuitabilityData_1* p, FILE* stream)
{
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64")",
            p->D_SUITABILITY,
            p->Q_SUITABILITY,
            p->M_LOADINGGAUGE,
            p->M_AXLELOAD,
            p->M_TRACTION);
}

static inline int RouteSuitabilityData_1_Equal(const RouteSuitabilityData_1* a, const RouteSuitabilityData_1* b)
{
    int status = 1;

    status = status && (a->D_SUITABILITY == b->D_SUITABILITY);
    status = status && (a->Q_SUITABILITY == b->Q_SUITABILITY);

    if (a->Q_SUITABILITY == 0)
    {
        status = status && (a->M_LOADINGGAUGE == b->M_LOADINGGAUGE);
    }

    if (a->Q_SUITABILITY == 1)
    {
        status = status && (a->M_AXLELOAD == b->M_AXLELOAD);
    }

    if (a->Q_SUITABILITY == 2)
    {
        status = status && (a->M_TRACTION == b->M_TRACTION);
    }

    return status;
}

int RouteSuitabilityData_1_EncodeInt(const RouteSuitabilityData_1* p, PacketInfo* data, kcg_int* stream);

int RouteSuitabilityData_1_DecodeInt(RouteSuitabilityData_1* p, PacketInfo* data, kcg_int* stream);

#endif // ROUTESUITABILITYDATA_1_H_INCLUDED

