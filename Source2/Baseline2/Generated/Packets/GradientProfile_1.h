
#ifndef GRADIENTPROFILE_1_H_INCLUDED
#define GRADIENTPROFILE_1_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct GradientProfile_1
{

    uint64_t  D_GRADIENT;       // # 15
    uint64_t   Q_GDIR;           // # 1
    uint64_t   G_A;              // # 8
};

typedef struct GradientProfile_1 GradientProfile_1;

#define GRADIENTPROFILE_1_BITSIZE 24

GradientProfile_1*  GradientProfile_1_New(void);

void   GradientProfile_1_Delete(GradientProfile_1*);

static inline void GradientProfile_1_Init(GradientProfile_1* p)
{
}

/*@
    logic integer BitSize{L}(GradientProfile_1* p) = GRADIENTPROFILE_1_BITSIZE;

    logic integer MaxBitSize{L}(GradientProfile_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, GradientProfile_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(GradientProfile_1* p) =
      Invariant(p->D_GRADIENT)        &&
      Invariant(p->Q_GDIR)            &&
      Invariant(p->G_A);

    predicate ZeroInitialized(GradientProfile_1* p) =
      ZeroInitialized(p->D_GRADIENT)        &&
      ZeroInitialized(p->Q_GDIR)            &&
      ZeroInitialized(p->G_A);

    predicate EqualBits(Bitstream* stream, integer pos, GradientProfile_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_GRADIENT)        &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR)            &&
      EqualBits(stream, pos + 16,  pos + 24,  p->G_A);

    predicate UpperBitsNotSet(GradientProfile_1* p) =
      UpperBitsNotSet(p->D_GRADIENT,       15)  &&
      UpperBitsNotSet(p->Q_GDIR,           1)   &&
      UpperBitsNotSet(p->G_A,              8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int GradientProfile_1_UpperBitsNotSet(const GradientProfile_1* p);

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
int GradientProfile_1_EncodeBit(const GradientProfile_1* p, Bitstream* stream);

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
int GradientProfile_1_DecodeBit(GradientProfile_1* p, Bitstream* stream);

static inline void GradientProfile_1_Print(const GradientProfile_1* p, FILE* stream)
{
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64")",
            p->D_GRADIENT,
            p->Q_GDIR,
            p->G_A);
}

static inline int GradientProfile_1_Equal(const GradientProfile_1* a, const GradientProfile_1* b)
{
    int status = 1;

    status = status && (a->D_GRADIENT == b->D_GRADIENT);
    status = status && (a->Q_GDIR == b->Q_GDIR);
    status = status && (a->G_A == b->G_A);

    return status;
}

int GradientProfile_1_EncodeInt(const GradientProfile_1* p, kcg_int* startAddress, kcg_int* stream);

int GradientProfile_1_DecodeInt(GradientProfile_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // GRADIENTPROFILE_1_H_INCLUDED

