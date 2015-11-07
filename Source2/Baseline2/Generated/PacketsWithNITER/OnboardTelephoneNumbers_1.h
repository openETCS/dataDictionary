
#ifndef ONBOARDTELEPHONENUMBERS_1_H_INCLUDED
#define ONBOARDTELEPHONENUMBERS_1_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrainToTrack_OnboardTelephoneNumbers
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

struct OnboardTelephoneNumbers_1
{

    uint64_t  NID_RADIO;        // # 64
};

typedef struct OnboardTelephoneNumbers_1 OnboardTelephoneNumbers_1;

#define ONBOARDTELEPHONENUMBERS_1_BITSIZE 64

/*@
    logic integer BitSize{L}(OnboardTelephoneNumbers_1* p) = ONBOARDTELEPHONENUMBERS_1_BITSIZE;

    logic integer MaxBitSize{L}(OnboardTelephoneNumbers_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, OnboardTelephoneNumbers_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(OnboardTelephoneNumbers_1* p) =
      Invariant(p->NID_RADIO);

    predicate ZeroInitialized(OnboardTelephoneNumbers_1* p) =
      ZeroInitialized(p->NID_RADIO);

    predicate EqualBits(Bitstream* stream, integer pos, OnboardTelephoneNumbers_1* p) =
      EqualBits(stream, pos,       pos + 64,  p->NID_RADIO);

    predicate UpperBitsNotSet(OnboardTelephoneNumbers_1* p) =
      UpperBitsNotSet(p->NID_RADIO,        64);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int OnboardTelephoneNumbers_1_UpperBitsNotSet(const OnboardTelephoneNumbers_1* p);

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
int OnboardTelephoneNumbers_1_EncodeBit(const OnboardTelephoneNumbers_1* p, Bitstream* stream);

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
int OnboardTelephoneNumbers_1_DecodeBit(OnboardTelephoneNumbers_1* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

static inline void OnboardTelephoneNumbers_1_Init(OnboardTelephoneNumbers_1* p)
{
    p->NID_RADIO = 0;
}

static inline void OnboardTelephoneNumbers_1_Print(const OnboardTelephoneNumbers_1* p, FILE* stream)
{
    fprintf(stream, "(%lu)",
            p->NID_RADIO);
}

static inline int OnboardTelephoneNumbers_1_Equal(const OnboardTelephoneNumbers_1* a, const OnboardTelephoneNumbers_1* b)
{
    int status = 1;

    status = status && (a->NID_RADIO == b->NID_RADIO);

    return status;
}

int OnboardTelephoneNumbers_1_EncodeInt(const OnboardTelephoneNumbers_1* p, kcg_int* startAddress, kcg_int* stream);

int OnboardTelephoneNumbers_1_DecodeInt(OnboardTelephoneNumbers_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // ONBOARDTELEPHONENUMBERS_1_H_INCLUDED

