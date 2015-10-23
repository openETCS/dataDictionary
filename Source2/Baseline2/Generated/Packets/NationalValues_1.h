
#ifndef NATIONALVALUES_1_H_INCLUDED
#define NATIONALVALUES_1_H_INCLUDED

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct NationalValues_1
{

    uint64_t  NID_C;            // # 10
};

typedef struct NationalValues_1 NationalValues_1;

#define NATIONALVALUES_1_BITSIZE 10

NationalValues_1*  NationalValues_1_New(void);

void   NationalValues_1_Delete(NationalValues_1*);

static inline void NationalValues_1_Init(NationalValues_1* p)
{
}

/*@
    logic integer BitSize{L}(NationalValues_1* p) = NATIONALVALUES_1_BITSIZE;

    logic integer MaxBitSize{L}(NationalValues_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, NationalValues_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(NationalValues_1* p) =
      Invariant(p->NID_C);

    predicate ZeroInitialized(NationalValues_1* p) =
      ZeroInitialized(p->NID_C);

    predicate EqualBits(Bitstream* stream, integer pos, NationalValues_1* p) =
      EqualBits(stream, pos,       pos + 10,  p->NID_C);

    predicate UpperBitsNotSet(NationalValues_1* p) =
      UpperBitsNotSet(p->NID_C,            10);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int NationalValues_1_UpperBitsNotSet(const NationalValues_1* p);

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
int NationalValues_1_EncodeBit(const NationalValues_1* p, Bitstream* stream);

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
int NationalValues_1_DecodeBit(NationalValues_1* p, Bitstream* stream);

static inline void NationalValues_1_Print(const NationalValues_1* p, FILE* stream)
{
    fprintf(stream, "(%"PRIu64")",
            p->NID_C);
}

static inline int NationalValues_1_Equal(const NationalValues_1* a, const NationalValues_1* b)
{
    int status = 1;

    status = status && (a->NID_C == b->NID_C);

    return status;
}

int NationalValues_1_EncodeInt(const NationalValues_1* p, kcg_int* startAddress, kcg_int* stream);

int NationalValues_1_DecodeInt(NationalValues_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // NATIONALVALUES_1_H_INCLUDED

