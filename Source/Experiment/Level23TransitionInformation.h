
#ifndef LEVEL23TRANSITIONINFORMATION_H_INCLUDED
#define LEVEL23TRANSITIONINFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"

struct Level23TransitionInformation
{
    // TransmissionMedia=Radio
    // Identity of the level 2/3 transition balise group
    // Packet Number = 9

    PacketHeader header;
    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_LTRBG;        // # 24
};

typedef struct Level23TransitionInformation Level23TransitionInformation;

#define LEVEL23TRANSITIONINFORMATION_BITSIZE 37


Level23TransitionInformation*  Level23TransitionInformation_New(void);

void   Level23TransitionInformation_Delete(Level23TransitionInformation*);

static inline void Level23TransitionInformation_Init(Level23TransitionInformation* p)
{
    p->header.NID_PACKET = 9;
    p->header.list = TRAINTOTRACK;
    p->L_PACKET          = 0;
    p->NID_LTRBG         = 0;
}


/*@
    logic integer BitSize{L}(Level23TransitionInformation* p) = LEVEL23TRANSITIONINFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(Level23TransitionInformation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level23TransitionInformation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level23TransitionInformation* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_LTRBG);

    predicate ZeroInitialized(Level23TransitionInformation* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_LTRBG);

    predicate EqualBits(Bitstream* stream, integer pos, Level23TransitionInformation* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 37,  p->NID_LTRBG);

    predicate UpperBitsNotSet(Level23TransitionInformation* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_LTRBG,        24);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level23TransitionInformation_UpperBitsNotSet(const Level23TransitionInformation* p);

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
int Level23TransitionInformation_EncodeBit(const Level23TransitionInformation* p, Bitstream* stream);

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
int Level23TransitionInformation_DecodeBit(Level23TransitionInformation* p, Bitstream* stream);
/*
int Level23TransitionInformation_EncodeInt(PacketInfo* data, kcg_int* stream, const Level23TransitionInformation* p);

int Level23TransitionInformation_DecodeInt(PacketInfo* data, const kcg_int* stream, Level23TransitionInformation* p);
*/

static inline void Level23TransitionInformation_Print(FILE* stream, const Level23TransitionInformation* p)
{
    fprintf(stream, "(%llu,%llu,%llu)",
            p->header.NID_PACKET,
            p->L_PACKET,
            p->NID_LTRBG);
}

static inline int
Level23TransitionInformation_Equal(const Level23TransitionInformation* a, const Level23TransitionInformation* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);

    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->NID_LTRBG == b->NID_LTRBG);

    return status;
}

#endif // LEVEL23TRANSITIONINFORMATION_H_INCLUDED

