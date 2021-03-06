
#ifndef INTERNATIONALSTATICSPEEDPROFILE_H_INCLUDED
#define INTERNATIONALSTATICSPEEDPROFILE_H_INCLUDED

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
#include "InternationalStaticSpeedProfile_1.h"
#include "InternationalStaticSpeedProfile_2.h"

struct InternationalStaticSpeedProfile
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Static speed profile and optionally speed limits depending on the international
    // train category.
    // Packet Number = 27

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_STATIC;         // # 15
    uint64_t   V_STATIC;         // # 7
    uint64_t   Q_FRONT;          // # 1
    uint64_t   N_ITER_1;         // # 5
    InternationalStaticSpeedProfile_1   sub_1[31];
    uint64_t   N_ITER_2;         // # 5
    InternationalStaticSpeedProfile_2   sub_2[31];
};

typedef struct InternationalStaticSpeedProfile InternationalStaticSpeedProfile;

#define INTERNATIONALSTATICSPEEDPROFILE_BITSIZE 50

/*@
    logic integer BitSize{L}(InternationalStaticSpeedProfile* p) = INTERNATIONALSTATICSPEEDPROFILE_BITSIZE;

    logic integer MaxBitSize{L}(InternationalStaticSpeedProfile* p) = BitSize(p);

    predicate Separated(Bitstream* stream, InternationalStaticSpeedProfile* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(InternationalStaticSpeedProfile* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_STATIC)          &&
      Invariant(p->V_STATIC)          &&
      Invariant(p->Q_FRONT);

    predicate ZeroInitialized(InternationalStaticSpeedProfile* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_STATIC)          &&
      ZeroInitialized(p->V_STATIC)          &&
      ZeroInitialized(p->Q_FRONT);

    predicate EqualBits(Bitstream* stream, integer pos, InternationalStaticSpeedProfile* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_STATIC)          &&
      EqualBits(stream, pos + 32,  pos + 39,  p->V_STATIC)          &&
      EqualBits(stream, pos + 39,  pos + 40,  p->Q_FRONT);

    predicate UpperBitsNotSet(InternationalStaticSpeedProfile* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
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
int InternationalStaticSpeedProfile_UpperBitsNotSet(const InternationalStaticSpeedProfile* p);

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
int InternationalStaticSpeedProfile_EncodeBit(const InternationalStaticSpeedProfile* p, Bitstream* stream);

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
int InternationalStaticSpeedProfile_DecodeBit(InternationalStaticSpeedProfile* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

InternationalStaticSpeedProfile*  InternationalStaticSpeedProfile_New(void);

void   InternationalStaticSpeedProfile_Delete(InternationalStaticSpeedProfile*);

static inline void InternationalStaticSpeedProfile_Init(InternationalStaticSpeedProfile* p)
{
    p->header.NID_PACKET = 27;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->D_STATIC = 0;
    p->V_STATIC = 0;
    p->Q_FRONT = 0;
    p->N_ITER_1 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        InternationalStaticSpeedProfile_1_Init(&(p->sub_1[i]));
    }

    p->N_ITER_2 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        InternationalStaticSpeedProfile_2_Init(&(p->sub_2[i]));
    }

}

static inline void InternationalStaticSpeedProfile_Print(const InternationalStaticSpeedProfile* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu,%lu,%lu",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->D_STATIC,
            p->V_STATIC,
            p->Q_FRONT,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        InternationalStaticSpeedProfile_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, "%lu",
            p->N_ITER_2);

    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        InternationalStaticSpeedProfile_2_Print(&p->sub_2[i], stream);
    }

    fprintf(stream, ")");
}

static inline int InternationalStaticSpeedProfile_Equal(const InternationalStaticSpeedProfile* a, const InternationalStaticSpeedProfile* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->D_STATIC == b->D_STATIC);
    status = status && (a->V_STATIC == b->V_STATIC);
    status = status && (a->Q_FRONT == b->Q_FRONT);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && InternationalStaticSpeedProfile_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }
    status = status && (a->N_ITER_2 == b->N_ITER_2);
    if (a->N_ITER_2 == b->N_ITER_2)
    {
        for (uint32_t i = 0; i < a->N_ITER_2; ++i)
        {
            status = status && InternationalStaticSpeedProfile_2_Equal(&a->sub_2[i], &b->sub_2[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t InternationalStaticSpeedProfile_Length(const InternationalStaticSpeedProfile* p)
{
    return (uint32_t)(p->L_PACKET);
}

int InternationalStaticSpeedProfile_EncodeInt(const InternationalStaticSpeedProfile* p, Metadata* data, kcg_int* stream);

int InternationalStaticSpeedProfile_DecodeInt(InternationalStaticSpeedProfile* p, const Metadata* data, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // INTERNATIONALSTATICSPEEDPROFILE_H_INCLUDED


