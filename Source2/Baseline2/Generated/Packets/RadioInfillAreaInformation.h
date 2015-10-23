
#ifndef RADIOINFILLAREAINFORMATION_H_INCLUDED
#define RADIOINFILLAREAINFORMATION_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"

struct RadioInfillAreaInformation
{
    PacketHeader header;

    // TransmissionMedia=Balise
    // Packet Number = 133

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t   Q_RIU;            // # 1
    uint64_t  NID_C_0;          // # 10
    uint64_t  NID_RIU;          // # 14
    uint64_t  NID_RADIO;        // # 64
    uint64_t  D_INFILL;         // # 15
    uint64_t  NID_C_1;          // # 10
    uint64_t  NID_BG;           // # 14
};

typedef struct RadioInfillAreaInformation RadioInfillAreaInformation;

#define RADIOINFILLAREAINFORMATION_BITSIZE 145

RadioInfillAreaInformation*  RadioInfillAreaInformation_New(void);

void   RadioInfillAreaInformation_Delete(RadioInfillAreaInformation*);

static inline void RadioInfillAreaInformation_Init(RadioInfillAreaInformation* p)
{
    p->header.NID_PACKET = 133;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->Q_RIU = 0;
    p->NID_C_0 = 0;
    p->NID_RIU = 0;
    p->NID_RADIO = 0;
    p->D_INFILL = 0;
    p->NID_C_1 = 0;
    p->NID_BG = 0;
}

/*@
    logic integer BitSize{L}(RadioInfillAreaInformation* p) = RADIOINFILLAREAINFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(RadioInfillAreaInformation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, RadioInfillAreaInformation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(RadioInfillAreaInformation* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_RIU)             &&
      Invariant(p->NID_C_0)           &&
      Invariant(p->NID_RIU)           &&
      Invariant(p->NID_RADIO)         &&
      Invariant(p->D_INFILL)          &&
      Invariant(p->NID_C_1)           &&
      Invariant(p->NID_BG);

    predicate ZeroInitialized(RadioInfillAreaInformation* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_RIU)             &&
      ZeroInitialized(p->NID_C_0)           &&
      ZeroInitialized(p->NID_RIU)           &&
      ZeroInitialized(p->NID_RADIO)         &&
      ZeroInitialized(p->D_INFILL)          &&
      ZeroInitialized(p->NID_C_1)           &&
      ZeroInitialized(p->NID_BG);

    predicate EqualBits(Bitstream* stream, integer pos, RadioInfillAreaInformation* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 18,  p->Q_RIU)             &&
      EqualBits(stream, pos + 18,  pos + 28,  p->NID_C_0)           &&
      EqualBits(stream, pos + 28,  pos + 42,  p->NID_RIU)           &&
      EqualBits(stream, pos + 42,  pos + 106, p->NID_RADIO)         &&
      EqualBits(stream, pos + 106, pos + 121, p->D_INFILL)          &&
      EqualBits(stream, pos + 121, pos + 131, p->NID_C_1)           &&
      EqualBits(stream, pos + 131, pos + 145, p->NID_BG);

    predicate UpperBitsNotSet(RadioInfillAreaInformation* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_RIU,            1)   &&
      UpperBitsNotSet(p->NID_C_0,          10)  &&
      UpperBitsNotSet(p->NID_RIU,          14)  &&
      UpperBitsNotSet(p->NID_RADIO,        64)  &&
      UpperBitsNotSet(p->D_INFILL,         15)  &&
      UpperBitsNotSet(p->NID_C_1,          10)  &&
      UpperBitsNotSet(p->NID_BG,           14);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int RadioInfillAreaInformation_UpperBitsNotSet(const RadioInfillAreaInformation* p);

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
int RadioInfillAreaInformation_EncodeBit(const RadioInfillAreaInformation* p, Bitstream* stream);

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
int RadioInfillAreaInformation_DecodeBit(RadioInfillAreaInformation* p, Bitstream* stream);

static inline void RadioInfillAreaInformation_Print(const RadioInfillAreaInformation* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64")",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->Q_RIU,
            p->NID_C_0,
            p->NID_RIU,
            p->NID_RADIO,
            p->D_INFILL,
            p->NID_C_1,
            p->NID_BG);
}

static inline int RadioInfillAreaInformation_Equal(const RadioInfillAreaInformation* a, const RadioInfillAreaInformation* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->Q_RIU == b->Q_RIU);
    status = status && (a->NID_C_0 == b->NID_C_0);
    status = status && (a->NID_RIU == b->NID_RIU);
    status = status && (a->NID_RADIO == b->NID_RADIO);
    status = status && (a->D_INFILL == b->D_INFILL);
    status = status && (a->NID_C_1 == b->NID_C_1);
    status = status && (a->NID_BG == b->NID_BG);

    return status;
}

static inline uint32_t RadioInfillAreaInformation_Length(const RadioInfillAreaInformation* p)
{
    return (uint32_t)(p->L_PACKET);
}

int RadioInfillAreaInformation_EncodeInt(const RadioInfillAreaInformation* p, PacketInfo* data, kcg_int* stream);

int RadioInfillAreaInformation_DecodeInt(RadioInfillAreaInformation* p, PacketInfo* data, kcg_int* stream);

#endif // RADIOINFILLAREAINFORMATION_H_INCLUDED

