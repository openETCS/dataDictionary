
#ifndef ONBOARDTELEPHONENUMBERS_H_INCLUDED
#define ONBOARDTELEPHONENUMBERS_H_INCLUDED

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
#include "OnboardTelephoneNumbers_1.h"

struct OnboardTelephoneNumbers
{
    PacketHeader header;

    // TransmissionMedia=Radio
    // Telephone numbers associated to the onboard equipment
    // Packet Number = 3

    uint64_t  L_PACKET;         // # 13
    uint64_t   N_ITER_1;         // # 5
    OnboardTelephoneNumbers_1   sub_1[31];
};

typedef struct OnboardTelephoneNumbers OnboardTelephoneNumbers;

#define ONBOARDTELEPHONENUMBERS_BITSIZE 18

OnboardTelephoneNumbers*  OnboardTelephoneNumbers_New(void);

void   OnboardTelephoneNumbers_Delete(OnboardTelephoneNumbers*);

static inline void OnboardTelephoneNumbers_Init(OnboardTelephoneNumbers* p)
{
    p->header.NID_PACKET = 3;
    p->header.list = TRAINTOTRACK;
    p->L_PACKET = 0;
    p->N_ITER_1 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        OnboardTelephoneNumbers_1_Init(&(p->sub_1[i]));
    }

}

/*@
    logic integer BitSize{L}(OnboardTelephoneNumbers* p) = ONBOARDTELEPHONENUMBERS_BITSIZE;

    logic integer MaxBitSize{L}(OnboardTelephoneNumbers* p) = BitSize(p);

    predicate Separated(Bitstream* stream, OnboardTelephoneNumbers* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(OnboardTelephoneNumbers* p) =
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(OnboardTelephoneNumbers* p) =
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, OnboardTelephoneNumbers* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET);

    predicate UpperBitsNotSet(OnboardTelephoneNumbers* p) =
      UpperBitsNotSet(p->L_PACKET,         13);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int OnboardTelephoneNumbers_UpperBitsNotSet(const OnboardTelephoneNumbers* p);

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
int OnboardTelephoneNumbers_EncodeBit(const OnboardTelephoneNumbers* p, Bitstream* stream);

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
int OnboardTelephoneNumbers_DecodeBit(OnboardTelephoneNumbers* p, Bitstream* stream);

static inline void OnboardTelephoneNumbers_Print(const OnboardTelephoneNumbers* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu",
            p->L_PACKET,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        OnboardTelephoneNumbers_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int OnboardTelephoneNumbers_Equal(const OnboardTelephoneNumbers* a, const OnboardTelephoneNumbers* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && OnboardTelephoneNumbers_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t OnboardTelephoneNumbers_Length(const OnboardTelephoneNumbers* p)
{
    return (uint32_t)(p->L_PACKET);
}

int OnboardTelephoneNumbers_EncodeInt(const OnboardTelephoneNumbers* p, Metadata* data, kcg_int* stream);

int OnboardTelephoneNumbers_DecodeInt(OnboardTelephoneNumbers* p, const Metadata* data, const kcg_int* stream);

#endif // ONBOARDTELEPHONENUMBERS_H_INCLUDED

