
#ifndef GRADIENTPROFILE_H_INCLUDED
#define GRADIENTPROFILE_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"
#include "GradientProfile_1.h"

struct GradientProfile
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Transmission of the gradient.D_GRADIENT gives the distance to the next change
    // of the gradient value. The gradient value is the minimum gradient
    // for the given distance.
    // Packet Number = 21

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_GRADIENT;       // # 15
    uint64_t   Q_GDIR;           // # 1
    uint64_t   G_A;              // # 8
    uint64_t   N_ITER_1;         // # 5
    GradientProfile_1   sub_1[31];
};

typedef struct GradientProfile GradientProfile;

#define GRADIENTPROFILE_BITSIZE 46

GradientProfile*  GradientProfile_New(void);

void   GradientProfile_Delete(GradientProfile*);

static inline void GradientProfile_Init(GradientProfile* p)
{
    p->header.NID_PACKET = 21;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->D_GRADIENT = 0;
    p->Q_GDIR = 0;
    p->G_A = 0;
    p->N_ITER_1 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        GradientProfile_1_Init(&(p->sub_1[i]));
    }

}

/*@
    logic integer BitSize{L}(GradientProfile* p) = GRADIENTPROFILE_BITSIZE;

    logic integer MaxBitSize{L}(GradientProfile* p) = BitSize(p);

    predicate Separated(Bitstream* stream, GradientProfile* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(GradientProfile* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_GRADIENT)        &&
      Invariant(p->Q_GDIR)            &&
      Invariant(p->G_A);

    predicate ZeroInitialized(GradientProfile* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_GRADIENT)        &&
      ZeroInitialized(p->Q_GDIR)            &&
      ZeroInitialized(p->G_A);

    predicate EqualBits(Bitstream* stream, integer pos, GradientProfile* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_GRADIENT)        &&
      EqualBits(stream, pos + 32,  pos + 33,  p->Q_GDIR)            &&
      EqualBits(stream, pos + 33,  pos + 41,  p->G_A);

    predicate UpperBitsNotSet(GradientProfile* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
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
int GradientProfile_UpperBitsNotSet(const GradientProfile* p);

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
int GradientProfile_EncodeBit(const GradientProfile* p, Bitstream* stream);

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
int GradientProfile_DecodeBit(GradientProfile* p, Bitstream* stream);

static inline void GradientProfile_Print(const GradientProfile* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64"",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->D_GRADIENT,
            p->Q_GDIR,
            p->G_A,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        GradientProfile_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int GradientProfile_Equal(const GradientProfile* a, const GradientProfile* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->D_GRADIENT == b->D_GRADIENT);
    status = status && (a->Q_GDIR == b->Q_GDIR);
    status = status && (a->G_A == b->G_A);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && GradientProfile_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t GradientProfile_Length(const GradientProfile* p)
{
    return (uint32_t)(p->L_PACKET);
}

int GradientProfile_EncodeInt(const GradientProfile* p, PacketInfo* data, kcg_int* stream);

int GradientProfile_DecodeInt(GradientProfile* p, const PacketInfo* data, const kcg_int* stream);

#endif // GRADIENTPROFILE_H_INCLUDED

