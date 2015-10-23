
#ifndef DEFAULTBALISELOOPORRIUINFORMATION_H_INCLUDED
#define DEFAULTBALISELOOPORRIUINFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"

struct DefaultBaliseLoopOrRIUInformation
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Indication to on-board that balise telegram, loop message or RIU information
    // contains default information due to a fault of the trackside equipment.
    // Packet Number = 254

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
};

typedef struct DefaultBaliseLoopOrRIUInformation DefaultBaliseLoopOrRIUInformation;

#define DEFAULTBALISELOOPORRIUINFORMATION_BITSIZE 15

DefaultBaliseLoopOrRIUInformation*  DefaultBaliseLoopOrRIUInformation_New(void);

void   DefaultBaliseLoopOrRIUInformation_Delete(DefaultBaliseLoopOrRIUInformation*);

static inline void DefaultBaliseLoopOrRIUInformation_Init(DefaultBaliseLoopOrRIUInformation* p)
{
    p->header.NID_PACKET = 254;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
}

/*@
    logic integer BitSize{L}(DefaultBaliseLoopOrRIUInformation* p) = DEFAULTBALISELOOPORRIUINFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(DefaultBaliseLoopOrRIUInformation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, DefaultBaliseLoopOrRIUInformation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(DefaultBaliseLoopOrRIUInformation* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(DefaultBaliseLoopOrRIUInformation* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, DefaultBaliseLoopOrRIUInformation* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

    predicate UpperBitsNotSet(DefaultBaliseLoopOrRIUInformation* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int DefaultBaliseLoopOrRIUInformation_UpperBitsNotSet(const DefaultBaliseLoopOrRIUInformation* p);

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
int DefaultBaliseLoopOrRIUInformation_EncodeBit(const DefaultBaliseLoopOrRIUInformation* p, Bitstream* stream);

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
int DefaultBaliseLoopOrRIUInformation_DecodeBit(DefaultBaliseLoopOrRIUInformation* p, Bitstream* stream);

static inline void DefaultBaliseLoopOrRIUInformation_Print(const DefaultBaliseLoopOrRIUInformation* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64")",
            p->Q_DIR,
            p->L_PACKET);
}

static inline int DefaultBaliseLoopOrRIUInformation_Equal(const DefaultBaliseLoopOrRIUInformation* a, const DefaultBaliseLoopOrRIUInformation* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);

    return status;
}

static inline uint32_t DefaultBaliseLoopOrRIUInformation_Length(const DefaultBaliseLoopOrRIUInformation* p)
{
    return (uint32_t)(p->L_PACKET);
}

int DefaultBaliseLoopOrRIUInformation_EncodeInt(const DefaultBaliseLoopOrRIUInformation* p, PacketInfo* data, kcg_int* stream);

int DefaultBaliseLoopOrRIUInformation_DecodeInt(DefaultBaliseLoopOrRIUInformation* p, PacketInfo* data, kcg_int* stream);

#endif // DEFAULTBALISELOOPORRIUINFORMATION_H_INCLUDED

