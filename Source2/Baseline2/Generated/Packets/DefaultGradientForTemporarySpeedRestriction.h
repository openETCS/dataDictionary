
#ifndef DEFAULTGRADIENTFORTEMPORARYSPEEDRESTRICTION_H_INCLUDED
#define DEFAULTGRADIENTFORTEMPORARYSPEEDRESTRICTION_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct DefaultGradientForTemporarySpeedRestriction
{
    PacketHeader header;

    // TransmissionMedia=Balise
    // It defines a default gradient to be used for TSR supervision
    // when no gradient profile (packet 21) is available
    // Packet Number = 141

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_GDIR;           // # 1
    uint64_t   G_TSR;            // # 8
};

typedef struct DefaultGradientForTemporarySpeedRestriction DefaultGradientForTemporarySpeedRestriction;

#define DEFAULTGRADIENTFORTEMPORARYSPEEDRESTRICTION_BITSIZE 24

DefaultGradientForTemporarySpeedRestriction*  DefaultGradientForTemporarySpeedRestriction_New(void);

void   DefaultGradientForTemporarySpeedRestriction_Delete(DefaultGradientForTemporarySpeedRestriction*);

static inline void DefaultGradientForTemporarySpeedRestriction_Init(DefaultGradientForTemporarySpeedRestriction* p)
{
    p->header.NID_PACKET = 141;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_GDIR = 0;
    p->G_TSR = 0;
}

/*@
    logic integer BitSize{L}(DefaultGradientForTemporarySpeedRestriction* p) = DEFAULTGRADIENTFORTEMPORARYSPEEDRESTRICTION_BITSIZE;

    logic integer MaxBitSize{L}(DefaultGradientForTemporarySpeedRestriction* p) = BitSize(p);

    predicate Separated(Bitstream* stream, DefaultGradientForTemporarySpeedRestriction* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(DefaultGradientForTemporarySpeedRestriction* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_GDIR)            &&
      Invariant(p->G_TSR);

    predicate ZeroInitialized(DefaultGradientForTemporarySpeedRestriction* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_GDIR)            &&
      ZeroInitialized(p->G_TSR);

    predicate EqualBits(Bitstream* stream, integer pos, DefaultGradientForTemporarySpeedRestriction* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR)            &&
      EqualBits(stream, pos + 16,  pos + 24,  p->G_TSR);

    predicate UpperBitsNotSet(DefaultGradientForTemporarySpeedRestriction* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_GDIR,           1)   &&
      UpperBitsNotSet(p->G_TSR,            8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int DefaultGradientForTemporarySpeedRestriction_UpperBitsNotSet(const DefaultGradientForTemporarySpeedRestriction* p);

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
int DefaultGradientForTemporarySpeedRestriction_EncodeBit(const DefaultGradientForTemporarySpeedRestriction* p, Bitstream* stream);

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
int DefaultGradientForTemporarySpeedRestriction_DecodeBit(DefaultGradientForTemporarySpeedRestriction* p, Bitstream* stream);

static inline void DefaultGradientForTemporarySpeedRestriction_Print(const DefaultGradientForTemporarySpeedRestriction* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64")",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_GDIR,
            p->G_TSR);
}

static inline int DefaultGradientForTemporarySpeedRestriction_Equal(const DefaultGradientForTemporarySpeedRestriction* a, const DefaultGradientForTemporarySpeedRestriction* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_GDIR == b->Q_GDIR);
    status = status && (a->G_TSR == b->G_TSR);

    return status;
}

static inline uint32_t DefaultGradientForTemporarySpeedRestriction_Length(const DefaultGradientForTemporarySpeedRestriction* p)
{
    return (uint32_t)(p->L_PACKET);
}

int DefaultGradientForTemporarySpeedRestriction_EncodeInt(const DefaultGradientForTemporarySpeedRestriction* p, PacketInfo* data, kcg_int* stream);

int DefaultGradientForTemporarySpeedRestriction_DecodeInt(DefaultGradientForTemporarySpeedRestriction* p, PacketInfo* data, kcg_int* stream);

#endif // DEFAULTGRADIENTFORTEMPORARYSPEEDRESTRICTION_H_INCLUDED

