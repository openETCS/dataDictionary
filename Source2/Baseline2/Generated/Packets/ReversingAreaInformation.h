
#ifndef REVERSINGAREAINFORMATION_H_INCLUDED
#define REVERSINGAREAINFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct ReversingAreaInformation
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Used to send start and length of reversing area to the
    // on-board
    // Packet Number = 138

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_STARTREVERSE;   // # 15
    uint64_t  L_REVERSEAREA;    // # 15
};

typedef struct ReversingAreaInformation ReversingAreaInformation;

#define REVERSINGAREAINFORMATION_BITSIZE 47

ReversingAreaInformation*  ReversingAreaInformation_New(void);

void   ReversingAreaInformation_Delete(ReversingAreaInformation*);

static inline void ReversingAreaInformation_Init(ReversingAreaInformation* p)
{
    p->header.NID_PACKET = 138;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->D_STARTREVERSE = 0;
    p->L_REVERSEAREA = 0;
}

/*@
    logic integer BitSize{L}(ReversingAreaInformation* p) = REVERSINGAREAINFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(ReversingAreaInformation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ReversingAreaInformation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ReversingAreaInformation* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_STARTREVERSE)    &&
      Invariant(p->L_REVERSEAREA);

    predicate ZeroInitialized(ReversingAreaInformation* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_STARTREVERSE)    &&
      ZeroInitialized(p->L_REVERSEAREA);

    predicate EqualBits(Bitstream* stream, integer pos, ReversingAreaInformation* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_STARTREVERSE)    &&
      EqualBits(stream, pos + 32,  pos + 47,  p->L_REVERSEAREA);

    predicate UpperBitsNotSet(ReversingAreaInformation* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_STARTREVERSE,   15)  &&
      UpperBitsNotSet(p->L_REVERSEAREA,    15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ReversingAreaInformation_UpperBitsNotSet(const ReversingAreaInformation* p);

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
int ReversingAreaInformation_EncodeBit(const ReversingAreaInformation* p, Bitstream* stream);

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
int ReversingAreaInformation_DecodeBit(ReversingAreaInformation* p, Bitstream* stream);

static inline void ReversingAreaInformation_Print(const ReversingAreaInformation* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64")",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->D_STARTREVERSE,
            p->L_REVERSEAREA);
}

static inline int ReversingAreaInformation_Equal(const ReversingAreaInformation* a, const ReversingAreaInformation* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->D_STARTREVERSE == b->D_STARTREVERSE);
    status = status && (a->L_REVERSEAREA == b->L_REVERSEAREA);

    return status;
}

static inline uint32_t ReversingAreaInformation_Length(const ReversingAreaInformation* p)
{
    return (uint32_t)(p->L_PACKET);
}

int ReversingAreaInformation_EncodeInt(const ReversingAreaInformation* p, PacketInfo* data, kcg_int* stream);

int ReversingAreaInformation_DecodeInt(ReversingAreaInformation* p, PacketInfo* data, kcg_int* stream);

#endif // REVERSINGAREAINFORMATION_H_INCLUDED

