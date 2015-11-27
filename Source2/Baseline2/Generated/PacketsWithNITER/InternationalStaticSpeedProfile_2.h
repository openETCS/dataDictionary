
#ifndef INTERNATIONALSTATICSPEEDPROFILE_2_H_INCLUDED
#define INTERNATIONALSTATICSPEEDPROFILE_2_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_InternationalStaticSpeedProfile
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
#include "InternationalStaticSpeedProfile_2_1.h"

struct InternationalStaticSpeedProfile_2
{

    uint64_t  D_STATIC;         // # 15
    uint64_t   V_STATIC;         // # 7
    uint64_t   Q_FRONT;          // # 1
    uint64_t   N_ITER_2_1;       // # 5
    InternationalStaticSpeedProfile_2_1   sub_2_1[31];
};

typedef struct InternationalStaticSpeedProfile_2 InternationalStaticSpeedProfile_2;

#define INTERNATIONALSTATICSPEEDPROFILE_2_BITSIZE 28

/*@
    logic integer BitSize{L}(InternationalStaticSpeedProfile_2* p) = INTERNATIONALSTATICSPEEDPROFILE_2_BITSIZE;

    logic integer MaxBitSize{L}(InternationalStaticSpeedProfile_2* p) = BitSize(p);

    predicate Separated(Bitstream* stream, InternationalStaticSpeedProfile_2* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(InternationalStaticSpeedProfile_2* p) =
      Invariant(p->D_STATIC)          &&
      Invariant(p->V_STATIC)          &&
      Invariant(p->Q_FRONT);

    predicate ZeroInitialized(InternationalStaticSpeedProfile_2* p) =
      ZeroInitialized(p->D_STATIC)          &&
      ZeroInitialized(p->V_STATIC)          &&
      ZeroInitialized(p->Q_FRONT);

    predicate EqualBits(Bitstream* stream, integer pos, InternationalStaticSpeedProfile_2* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_STATIC)          &&
      EqualBits(stream, pos + 15,  pos + 22,  p->V_STATIC)          &&
      EqualBits(stream, pos + 22,  pos + 23,  p->Q_FRONT);

    predicate UpperBitsNotSet(InternationalStaticSpeedProfile_2* p) =
      UpperBitsNotSet(p->D_STATIC,         15)  &&
      UpperBitsNotSet(p->V_STATIC,         7)   &&
      UpperBitsNotSet(p->Q_FRONT,          1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int InternationalStaticSpeedProfile_2_UpperBitsNotSet(const InternationalStaticSpeedProfile_2* p);

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
int InternationalStaticSpeedProfile_2_EncodeBit(const InternationalStaticSpeedProfile_2* p, Bitstream* stream);

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
int InternationalStaticSpeedProfile_2_DecodeBit(InternationalStaticSpeedProfile_2* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

static inline void InternationalStaticSpeedProfile_2_Init(InternationalStaticSpeedProfile_2* p)
{
    p->D_STATIC = 0;
    p->V_STATIC = 0;
    p->Q_FRONT = 0;
    p->N_ITER_2_1 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        InternationalStaticSpeedProfile_2_1_Init(&(p->sub_2_1[i]));
    }

}

static inline void InternationalStaticSpeedProfile_2_Print(const InternationalStaticSpeedProfile_2* p, FILE* stream)
{
    fprintf(stream, "(%lu,%lu,%lu,%lu",
            p->D_STATIC,
            p->V_STATIC,
            p->Q_FRONT,
            p->N_ITER_2_1);

    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        InternationalStaticSpeedProfile_2_1_Print(&p->sub_2_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int InternationalStaticSpeedProfile_2_Equal(const InternationalStaticSpeedProfile_2* a, const InternationalStaticSpeedProfile_2* b)
{
    int status = 1;

    status = status && (a->D_STATIC == b->D_STATIC);
    status = status && (a->V_STATIC == b->V_STATIC);
    status = status && (a->Q_FRONT == b->Q_FRONT);
    status = status && (a->N_ITER_2_1 == b->N_ITER_2_1);
    if (a->N_ITER_2_1 == b->N_ITER_2_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_2_1; ++i)
        {
            status = status && InternationalStaticSpeedProfile_2_1_Equal(&a->sub_2_1[i], &b->sub_2_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

int InternationalStaticSpeedProfile_2_EncodeInt(const InternationalStaticSpeedProfile_2* p, kcg_int* startAddress, kcg_int* stream);

int InternationalStaticSpeedProfile_2_DecodeInt(InternationalStaticSpeedProfile_2* p, kcg_int* startAddress, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // INTERNATIONALSTATICSPEEDPROFILE_2_H_INCLUDED

