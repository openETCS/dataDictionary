
#ifndef VALIDATEDTRAINDATA_2_H_INCLUDED
#define VALIDATEDTRAINDATA_2_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"

struct ValidatedTrainData_2
{

    uint64_t   NID_STM;          // # 8
};

typedef struct ValidatedTrainData_2 ValidatedTrainData_2;

#define VALIDATEDTRAINDATA_2_BITSIZE 8

ValidatedTrainData_2*  ValidatedTrainData_2_New(void);

void   ValidatedTrainData_2_Delete(ValidatedTrainData_2*);

static inline void ValidatedTrainData_2_Init(ValidatedTrainData_2* p)
{
}

/*@
    logic integer BitSize{L}(ValidatedTrainData_2* p) = VALIDATEDTRAINDATA_2_BITSIZE;

    logic integer MaxBitSize{L}(ValidatedTrainData_2* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ValidatedTrainData_2* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ValidatedTrainData_2* p) =
      Invariant(p->NID_STM);

    predicate ZeroInitialized(ValidatedTrainData_2* p) =
      ZeroInitialized(p->NID_STM);

    predicate EqualBits(Bitstream* stream, integer pos, ValidatedTrainData_2* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_STM);

    predicate UpperBitsNotSet(ValidatedTrainData_2* p) =
      UpperBitsNotSet(p->NID_STM,          8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ValidatedTrainData_2_UpperBitsNotSet(const ValidatedTrainData_2* p);

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
int ValidatedTrainData_2_EncodeBit(const ValidatedTrainData_2* p, Bitstream* stream);

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
int ValidatedTrainData_2_DecodeBit(ValidatedTrainData_2* p, Bitstream* stream);

static inline void ValidatedTrainData_2_Print(const ValidatedTrainData_2* p, FILE* stream)
{
    fprintf(stream, "(%"PRIu64")",
            p->NID_STM);
}

static inline int ValidatedTrainData_2_Equal(const ValidatedTrainData_2* a, const ValidatedTrainData_2* b)
{
    int status = 1;

    status = status && (a->NID_STM == b->NID_STM);

    return status;
}

int ValidatedTrainData_2_EncodeInt(const ValidatedTrainData_2* p, PacketInfo* data, kcg_int* stream);

int ValidatedTrainData_2_DecodeInt(ValidatedTrainData_2* p, PacketInfo* data, kcg_int* stream);

#endif // VALIDATEDTRAINDATA_2_H_INCLUDED

