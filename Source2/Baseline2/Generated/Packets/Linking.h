
#ifndef LINKING_H_INCLUDED
#define LINKING_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"
#include "Linking_1.h"

struct Linking
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Linking Information.
    // Packet Number = 5

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_LINK;           // # 15
    uint64_t   Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
    uint64_t   Q_LINKORIENTATION;// # 1
    uint64_t   Q_LINKREACTION;   // # 2
    uint64_t   Q_LOCACC;         // # 6
    uint64_t   N_ITER_1;         // # 5
    Linking_1   sub_1[31];
};

typedef struct Linking Linking;

#define LINKING_BITSIZE 61

Linking*  Linking_New(void);

void   Linking_Delete(Linking*);

static inline void Linking_Init(Linking* p)
{
    p->header.NID_PACKET = 5;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->D_LINK = 0;
    p->Q_NEWCOUNTRY = 0;
    p->NID_C = 0;
    p->NID_BG = 0;
    p->Q_LINKORIENTATION = 0;
    p->Q_LINKREACTION = 0;
    p->Q_LOCACC = 0;
}

/*@
    logic integer BitSize{L}(Linking* p) = LINKING_BITSIZE;

    logic integer MaxBitSize{L}(Linking* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Linking* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Linking* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_LINK)            &&
      Invariant(p->Q_NEWCOUNTRY);

    predicate ZeroInitialized(Linking* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_LINK)            &&
      ZeroInitialized(p->Q_NEWCOUNTRY);

    predicate EqualBits(Bitstream* stream, integer pos, Linking* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_LINK)            &&
      EqualBits(stream, pos + 32,  pos + 33,  p->Q_NEWCOUNTRY);

    predicate UpperBitsNotSet(Linking* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_LINK,           15)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Linking_UpperBitsNotSet(const Linking* p);

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
int Linking_EncodeBit(const Linking* p, Bitstream* stream);

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
int Linking_DecodeBit(Linking* p, Bitstream* stream);

static inline void Linking_Print(const Linking* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64",%"PRIu64"",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->D_LINK,
            p->Q_NEWCOUNTRY,
            p->NID_C,
            p->NID_BG,
            p->Q_LINKORIENTATION,
            p->Q_LINKREACTION,
            p->Q_LOCACC,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        Linking_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int Linking_Equal(const Linking* a, const Linking* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->D_LINK == b->D_LINK);
    status = status && (a->Q_NEWCOUNTRY == b->Q_NEWCOUNTRY);

    if (a->Q_NEWCOUNTRY == 1)
    {
        status = status && (a->NID_C == b->NID_C);
    }
    status = status && (a->NID_BG == b->NID_BG);
    status = status && (a->Q_LINKORIENTATION == b->Q_LINKORIENTATION);
    status = status && (a->Q_LINKREACTION == b->Q_LINKREACTION);
    status = status && (a->Q_LOCACC == b->Q_LOCACC);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && Linking_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t Linking_Length(const Linking* p)
{
    return (uint32_t)(p->L_PACKET);
}

int Linking_EncodeInt(const Linking* p, PacketInfo* data, kcg_int* stream);

int Linking_DecodeInt(Linking* p, PacketInfo* data, kcg_int* stream);

#endif // LINKING_H_INCLUDED

