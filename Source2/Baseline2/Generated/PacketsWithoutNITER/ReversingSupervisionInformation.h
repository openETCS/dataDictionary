
#ifndef REVERSINGSUPERVISIONINFORMATION_H_INCLUDED
#define REVERSINGSUPERVISIONINFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct ReversingSupervisionInformation
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Used to send supervision parameters (distance to run, speed) of reversing
    // area to the on-board
    // Packet Number = 139

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_REVERSE;        // # 15
    uint64_t   V_REVERSE;        // # 7
};

typedef struct ReversingSupervisionInformation ReversingSupervisionInformation;

#define REVERSINGSUPERVISIONINFORMATION_BITSIZE 39

ReversingSupervisionInformation*  ReversingSupervisionInformation_New(void);

void   ReversingSupervisionInformation_Delete(ReversingSupervisionInformation*);

static inline void ReversingSupervisionInformation_Init(ReversingSupervisionInformation* p)
{
    p->header.NID_PACKET = 139;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->D_REVERSE = 0;
    p->V_REVERSE = 0;
}

/*@
    logic integer BitSize{L}(ReversingSupervisionInformation* p) = REVERSINGSUPERVISIONINFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(ReversingSupervisionInformation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ReversingSupervisionInformation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ReversingSupervisionInformation* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_REVERSE)         &&
      Invariant(p->V_REVERSE);

    predicate ZeroInitialized(ReversingSupervisionInformation* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_REVERSE)         &&
      ZeroInitialized(p->V_REVERSE);

    predicate EqualBits(Bitstream* stream, integer pos, ReversingSupervisionInformation* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_REVERSE)         &&
      EqualBits(stream, pos + 32,  pos + 39,  p->V_REVERSE);

    predicate UpperBitsNotSet(ReversingSupervisionInformation* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_REVERSE,        15)  &&
      UpperBitsNotSet(p->V_REVERSE,        7);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ReversingSupervisionInformation_UpperBitsNotSet(const ReversingSupervisionInformation* p);

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
int ReversingSupervisionInformation_EncodeBit(const ReversingSupervisionInformation* p, Bitstream* stream);

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
int ReversingSupervisionInformation_DecodeBit(ReversingSupervisionInformation* p, Bitstream* stream);

static inline void ReversingSupervisionInformation_Print(const ReversingSupervisionInformation* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu)",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->D_REVERSE,
            p->V_REVERSE);
}

static inline int ReversingSupervisionInformation_Equal(const ReversingSupervisionInformation* a, const ReversingSupervisionInformation* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->D_REVERSE == b->D_REVERSE);
    status = status && (a->V_REVERSE == b->V_REVERSE);

    return status;
}

static inline uint32_t ReversingSupervisionInformation_Length(const ReversingSupervisionInformation* p)
{
    return (uint32_t)(p->L_PACKET);
}

int ReversingSupervisionInformation_EncodeInt(const ReversingSupervisionInformation* p, Metadata* data, kcg_int* stream);

int ReversingSupervisionInformation_DecodeInt(ReversingSupervisionInformation* p, const Metadata* data, const kcg_int* stream);

#endif // REVERSINGSUPERVISIONINFORMATION_H_INCLUDED

