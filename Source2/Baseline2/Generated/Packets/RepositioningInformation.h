
#ifndef REPOSITIONINGINFORMATION_H_INCLUDED
#define REPOSITIONINGINFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct RepositioningInformation
{
    PacketHeader header;

    // TransmissionMedia=Balise
    // Transmission of the update of the current distance
    // Packet Number = 16

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  L_SECTION;        // # 15
};

typedef struct RepositioningInformation RepositioningInformation;

#define REPOSITIONINGINFORMATION_BITSIZE 32

RepositioningInformation*  RepositioningInformation_New(void);

void   RepositioningInformation_Delete(RepositioningInformation*);

static inline void RepositioningInformation_Init(RepositioningInformation* p)
{
    p->header.NID_PACKET = 16;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->L_SECTION = 0;
}

/*@
    logic integer BitSize{L}(RepositioningInformation* p) = REPOSITIONINGINFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(RepositioningInformation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, RepositioningInformation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(RepositioningInformation* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->L_SECTION);

    predicate ZeroInitialized(RepositioningInformation* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->L_SECTION);

    predicate EqualBits(Bitstream* stream, integer pos, RepositioningInformation* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->L_SECTION);

    predicate UpperBitsNotSet(RepositioningInformation* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->L_SECTION,        15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int RepositioningInformation_UpperBitsNotSet(const RepositioningInformation* p);

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
int RepositioningInformation_EncodeBit(const RepositioningInformation* p, Bitstream* stream);

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
int RepositioningInformation_DecodeBit(RepositioningInformation* p, Bitstream* stream);

static inline void RepositioningInformation_Print(const RepositioningInformation* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64")",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->L_SECTION);
}

static inline int RepositioningInformation_Equal(const RepositioningInformation* a, const RepositioningInformation* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->L_SECTION == b->L_SECTION);

    return status;
}

static inline uint32_t RepositioningInformation_Length(const RepositioningInformation* p)
{
    return (uint32_t)(p->L_PACKET);
}

int RepositioningInformation_EncodeInt(const RepositioningInformation* p, PacketInfo* data, kcg_int* stream);

int RepositioningInformation_DecodeInt(RepositioningInformation* p, PacketInfo* data, kcg_int* stream);

#endif // REPOSITIONINGINFORMATION_H_INCLUDED

