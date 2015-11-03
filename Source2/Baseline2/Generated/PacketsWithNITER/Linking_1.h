
#ifndef LINKING_1_H_INCLUDED
#define LINKING_1_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct Linking_1
{

    uint64_t  D_LINK;           // # 15
    uint64_t   Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
    uint64_t   Q_LINKORIENTATION;// # 1
    uint64_t   Q_LINKREACTION;   // # 2
    uint64_t   Q_LOCACC;         // # 6
};

typedef struct Linking_1 Linking_1;

#define LINKING_1_BITSIZE 39

static inline void Linking_1_Init(Linking_1* p)
{
    p->D_LINK = 0;
    p->Q_NEWCOUNTRY = 0;
    p->NID_C = 0;
    p->NID_BG = 0;
    p->Q_LINKORIENTATION = 0;
    p->Q_LINKREACTION = 0;
    p->Q_LOCACC = 0;
}

/*@
    logic integer BitSize{L}(Linking_1* p) = LINKING_1_BITSIZE;

    logic integer MaxBitSize{L}(Linking_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Linking_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Linking_1* p) =
      Invariant(p->D_LINK)            &&
      Invariant(p->Q_NEWCOUNTRY);

    predicate ZeroInitialized(Linking_1* p) =
      ZeroInitialized(p->D_LINK)            &&
      ZeroInitialized(p->Q_NEWCOUNTRY);

    predicate EqualBits(Bitstream* stream, integer pos, Linking_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_LINK)            &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

    predicate UpperBitsNotSet(Linking_1* p) =
      UpperBitsNotSet(p->D_LINK,           15)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Linking_1_UpperBitsNotSet(const Linking_1* p);

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
int Linking_1_EncodeBit(const Linking_1* p, Bitstream* stream);

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

      ensures result: \result == 0; complete behaviors;
    disjoint behaviors;
*/
int Linking_1_DecodeBit(Linking_1* p, Bitstream* stream);

static inline void Linking_1_Print(const Linking_1* p, FILE* stream)
{
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu,%lu,%lu)",
            p->D_LINK,
            p->Q_NEWCOUNTRY,
            p->NID_C,
            p->NID_BG,
            p->Q_LINKORIENTATION,
            p->Q_LINKREACTION,
            p->Q_LOCACC);
}

static inline int Linking_1_Equal(const Linking_1* a, const Linking_1* b)
{
    int status = 1;

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

    return status;
}

int Linking_1_EncodeInt(const Linking_1* p, kcg_int* startAddress, kcg_int* stream);

int Linking_1_DecodeInt(Linking_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // LINKING_1_H_INCLUDED

