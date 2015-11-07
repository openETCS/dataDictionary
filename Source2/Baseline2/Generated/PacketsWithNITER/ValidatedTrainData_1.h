
#ifndef VALIDATEDTRAINDATA_1_H_INCLUDED
#define VALIDATEDTRAINDATA_1_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrainToTrack_ValidatedTrainData
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) 

- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): Fraunhofer FOKUS

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.       
============================================================================= */

#include "Bitstream.h"
#include "CompressedPackets.h"
#include "PacketHeader.h"

struct ValidatedTrainData_1
{

    uint64_t   M_TRACTION;       // # 8
};

typedef struct ValidatedTrainData_1 ValidatedTrainData_1;

#define VALIDATEDTRAINDATA_1_BITSIZE 8

/*@
    logic integer BitSize{L}(ValidatedTrainData_1* p) = VALIDATEDTRAINDATA_1_BITSIZE;

    logic integer MaxBitSize{L}(ValidatedTrainData_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ValidatedTrainData_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ValidatedTrainData_1* p) =
      Invariant(p->M_TRACTION);

    predicate ZeroInitialized(ValidatedTrainData_1* p) =
      ZeroInitialized(p->M_TRACTION);

    predicate EqualBits(Bitstream* stream, integer pos, ValidatedTrainData_1* p) =
      EqualBits(stream, pos,       pos + 8,   p->M_TRACTION);

    predicate UpperBitsNotSet(ValidatedTrainData_1* p) =
      UpperBitsNotSet(p->M_TRACTION,       8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ValidatedTrainData_1_UpperBitsNotSet(const ValidatedTrainData_1* p);

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
int ValidatedTrainData_1_EncodeBit(const ValidatedTrainData_1* p, Bitstream* stream);

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
int ValidatedTrainData_1_DecodeBit(ValidatedTrainData_1* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

static inline void ValidatedTrainData_1_Init(ValidatedTrainData_1* p)
{
    p->M_TRACTION = 0;
}

static inline void ValidatedTrainData_1_Print(const ValidatedTrainData_1* p, FILE* stream)
{
    fprintf(stream, "(%lu)",
            p->M_TRACTION);
}

static inline int ValidatedTrainData_1_Equal(const ValidatedTrainData_1* a, const ValidatedTrainData_1* b)
{
    int status = 1;

    status = status && (a->M_TRACTION == b->M_TRACTION);

    return status;
}

int ValidatedTrainData_1_EncodeInt(const ValidatedTrainData_1* p, kcg_int* startAddress, kcg_int* stream);

int ValidatedTrainData_1_DecodeInt(ValidatedTrainData_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // VALIDATEDTRAINDATA_1_H_INCLUDED

