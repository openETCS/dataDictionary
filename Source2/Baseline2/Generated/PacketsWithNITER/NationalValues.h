
#ifndef NATIONALVALUES_H_INCLUDED
#define NATIONALVALUES_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_NationalValues
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
#include "NationalValues_1.h"

struct NationalValues
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Downloads a set of National Values to the train
    // Packet Number = 3

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_VALIDNV;        // # 15
    uint64_t   N_ITER_1;         // # 5
    NationalValues_1   sub_1[31];
    uint64_t   V_NVSHUNT;        // # 7
    uint64_t   V_NVSTFF;         // # 7
    uint64_t   V_NVONSIGHT;      // # 7
    uint64_t   V_NVUNFIT;        // # 7
    uint64_t   V_NVREL;          // # 7
    uint64_t  D_NVROLL;         // # 15
    uint64_t   Q_NVSRBKTRG;      // # 1
    uint64_t   Q_NVEMRRLS;       // # 1
    uint64_t   V_NVALLOWOVTRP;   // # 7
    uint64_t   V_NVSUPOVTRP;     // # 7
    uint64_t  D_NVOVTRP;        // # 15
    uint64_t   T_NVOVTRP;        // # 8
    uint64_t  D_NVPOTRP;        // # 15
    uint64_t   M_NVCONTACT;      // # 2
    uint64_t   T_NVCONTACT;      // # 8
    uint64_t   M_NVDERUN;        // # 1
    uint64_t  D_NVSTFF;         // # 15
    uint64_t   Q_NVDRIVER_ADHES; // # 1
};

typedef struct NationalValues NationalValues;

#define NATIONALVALUES_BITSIZE 168

NationalValues*  NationalValues_New(void);

void   NationalValues_Delete(NationalValues*);

static inline void NationalValues_Init(NationalValues* p)
{
    p->header.NID_PACKET = 3;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->D_VALIDNV = 0;
    p->N_ITER_1 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        NationalValues_1_Init(&(p->sub_1[i]));
    }

    p->V_NVSHUNT = 0;
    p->V_NVSTFF = 0;
    p->V_NVONSIGHT = 0;
    p->V_NVUNFIT = 0;
    p->V_NVREL = 0;
    p->D_NVROLL = 0;
    p->Q_NVSRBKTRG = 0;
    p->Q_NVEMRRLS = 0;
    p->V_NVALLOWOVTRP = 0;
    p->V_NVSUPOVTRP = 0;
    p->D_NVOVTRP = 0;
    p->T_NVOVTRP = 0;
    p->D_NVPOTRP = 0;
    p->M_NVCONTACT = 0;
    p->T_NVCONTACT = 0;
    p->M_NVDERUN = 0;
    p->D_NVSTFF = 0;
    p->Q_NVDRIVER_ADHES = 0;
}

/*@
    logic integer BitSize{L}(NationalValues* p) = NATIONALVALUES_BITSIZE;

    logic integer MaxBitSize{L}(NationalValues* p) = BitSize(p);

    predicate Separated(Bitstream* stream, NationalValues* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(NationalValues* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_VALIDNV);

    predicate ZeroInitialized(NationalValues* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_VALIDNV);

    predicate EqualBits(Bitstream* stream, integer pos, NationalValues* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_VALIDNV);

    predicate UpperBitsNotSet(NationalValues* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_VALIDNV,        15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int NationalValues_UpperBitsNotSet(const NationalValues* p);

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
int NationalValues_EncodeBit(const NationalValues* p, Bitstream* stream);

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
int NationalValues_DecodeBit(NationalValues* p, Bitstream* stream);

static inline void NationalValues_Print(const NationalValues* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->D_VALIDNV,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        NationalValues_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, "%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu)",
            p->V_NVSHUNT,
            p->V_NVSTFF,
            p->V_NVONSIGHT,
            p->V_NVUNFIT,
            p->V_NVREL,
            p->D_NVROLL,
            p->Q_NVSRBKTRG,
            p->Q_NVEMRRLS,
            p->V_NVALLOWOVTRP,
            p->V_NVSUPOVTRP,
            p->D_NVOVTRP,
            p->T_NVOVTRP,
            p->D_NVPOTRP,
            p->M_NVCONTACT,
            p->T_NVCONTACT,
            p->M_NVDERUN,
            p->D_NVSTFF,
            p->Q_NVDRIVER_ADHES);
}

static inline int NationalValues_Equal(const NationalValues* a, const NationalValues* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->D_VALIDNV == b->D_VALIDNV);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && NationalValues_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }
    status = status && (a->V_NVSHUNT == b->V_NVSHUNT);
    status = status && (a->V_NVSTFF == b->V_NVSTFF);
    status = status && (a->V_NVONSIGHT == b->V_NVONSIGHT);
    status = status && (a->V_NVUNFIT == b->V_NVUNFIT);
    status = status && (a->V_NVREL == b->V_NVREL);
    status = status && (a->D_NVROLL == b->D_NVROLL);
    status = status && (a->Q_NVSRBKTRG == b->Q_NVSRBKTRG);
    status = status && (a->Q_NVEMRRLS == b->Q_NVEMRRLS);
    status = status && (a->V_NVALLOWOVTRP == b->V_NVALLOWOVTRP);
    status = status && (a->V_NVSUPOVTRP == b->V_NVSUPOVTRP);
    status = status && (a->D_NVOVTRP == b->D_NVOVTRP);
    status = status && (a->T_NVOVTRP == b->T_NVOVTRP);
    status = status && (a->D_NVPOTRP == b->D_NVPOTRP);
    status = status && (a->M_NVCONTACT == b->M_NVCONTACT);
    status = status && (a->T_NVCONTACT == b->T_NVCONTACT);
    status = status && (a->M_NVDERUN == b->M_NVDERUN);
    status = status && (a->D_NVSTFF == b->D_NVSTFF);
    status = status && (a->Q_NVDRIVER_ADHES == b->Q_NVDRIVER_ADHES);

    return status;
}

static inline uint32_t NationalValues_Length(const NationalValues* p)
{
    return (uint32_t)(p->L_PACKET);
}

int NationalValues_EncodeInt(const NationalValues* p, Metadata* data, kcg_int* stream);

int NationalValues_DecodeInt(NationalValues* p, const Metadata* data, const kcg_int* stream);

#endif // NATIONALVALUES_H_INCLUDED

