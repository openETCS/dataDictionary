
#ifndef INFILLLOCATIONREFERENCE_H_INCLUDED
#define INFILLLOCATIONREFERENCE_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"

struct InfillLocationReference
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Defines location reference for all data contained in the same radio
    // message or balise/loop telegram respectively, following this packet.
    // Packet Number = 136

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
};

typedef struct InfillLocationReference InfillLocationReference;

#define INFILLLOCATIONREFERENCE_BITSIZE 30

InfillLocationReference*  InfillLocationReference_New(void);

void   InfillLocationReference_Delete(InfillLocationReference*);

static inline void InfillLocationReference_Init(InfillLocationReference* p)
{
    p->header.NID_PACKET = 136;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_NEWCOUNTRY = 0;
    p->NID_C = 0;
    p->NID_BG = 0;
}

/*@
    logic integer BitSize{L}(InfillLocationReference* p) = INFILLLOCATIONREFERENCE_BITSIZE;

    logic integer MaxBitSize{L}(InfillLocationReference* p) = BitSize(p);

    predicate Separated(Bitstream* stream, InfillLocationReference* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(InfillLocationReference* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_NEWCOUNTRY);

    predicate ZeroInitialized(InfillLocationReference* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_NEWCOUNTRY);

    predicate EqualBits(Bitstream* stream, integer pos, InfillLocationReference* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

    predicate UpperBitsNotSet(InfillLocationReference* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int InfillLocationReference_UpperBitsNotSet(const InfillLocationReference* p);

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
int InfillLocationReference_EncodeBit(const InfillLocationReference* p, Bitstream* stream);

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
int InfillLocationReference_DecodeBit(InfillLocationReference* p, Bitstream* stream);

static inline void InfillLocationReference_Print(const InfillLocationReference* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64")",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_NEWCOUNTRY,
            p->NID_C,
            p->NID_BG);
}

static inline int InfillLocationReference_Equal(const InfillLocationReference* a, const InfillLocationReference* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_NEWCOUNTRY == b->Q_NEWCOUNTRY);

    if (a->Q_NEWCOUNTRY == 1)
    {
        status = status && (a->NID_C == b->NID_C);
    }
    status = status && (a->NID_BG == b->NID_BG);

    return status;
}

static inline uint32_t InfillLocationReference_Length(const InfillLocationReference* p)
{
    return (uint32_t)(p->L_PACKET);
}

int InfillLocationReference_EncodeInt(const InfillLocationReference* p, PacketInfo* data, kcg_int* stream);

int InfillLocationReference_DecodeInt(InfillLocationReference* p, PacketInfo* data, kcg_int* stream);

#endif // INFILLLOCATIONREFERENCE_H_INCLUDED

