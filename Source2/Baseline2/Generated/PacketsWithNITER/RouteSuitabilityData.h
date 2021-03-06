
#ifndef ROUTESUITABILITYDATA_H_INCLUDED
#define ROUTESUITABILITYDATA_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_RouteSuitabilityData
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
#include "RouteSuitabilityData_1.h"

struct RouteSuitabilityData
{
    PacketHeader header;

    // TransmissionMedia=Any
    // The packet gives the characteristics needed to enter a route.
    // Packet Number = 70

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t   Q_TRACKINIT;      // # 1
    uint64_t  D_TRACKINIT;      // # 15
    uint64_t  D_SUITABILITY;    // # 15
    uint64_t   Q_SUITABILITY;    // # 2
    uint64_t   M_LOADINGGAUGE;   // # 8
    uint64_t   M_AXLELOAD;       // # 7
    uint64_t   M_TRACTION;       // # 8
    uint64_t   N_ITER_1;         // # 5
    RouteSuitabilityData_1   sub_1[31];
};

typedef struct RouteSuitabilityData RouteSuitabilityData;

#define ROUTESUITABILITYDATA_BITSIZE 25

/*@
    logic integer BitSize{L}(RouteSuitabilityData* p) = ROUTESUITABILITYDATA_BITSIZE;

    logic integer MaxBitSize{L}(RouteSuitabilityData* p) = BitSize(p);

    predicate Separated(Bitstream* stream, RouteSuitabilityData* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(RouteSuitabilityData* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_TRACKINIT);

    predicate ZeroInitialized(RouteSuitabilityData* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_TRACKINIT);

    predicate EqualBits(Bitstream* stream, integer pos, RouteSuitabilityData* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 18,  p->Q_TRACKINIT);

    predicate UpperBitsNotSet(RouteSuitabilityData* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TRACKINIT,      1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int RouteSuitabilityData_UpperBitsNotSet(const RouteSuitabilityData* p);

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
int RouteSuitabilityData_EncodeBit(const RouteSuitabilityData* p, Bitstream* stream);

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
int RouteSuitabilityData_DecodeBit(RouteSuitabilityData* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

RouteSuitabilityData*  RouteSuitabilityData_New(void);

void   RouteSuitabilityData_Delete(RouteSuitabilityData*);

static inline void RouteSuitabilityData_Init(RouteSuitabilityData* p)
{
    p->header.NID_PACKET = 70;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->Q_TRACKINIT = 0;
    p->D_TRACKINIT = 0;
    p->D_SUITABILITY = 0;
    p->Q_SUITABILITY = 0;
    p->M_LOADINGGAUGE = 0;
    p->M_AXLELOAD = 0;
    p->M_TRACTION = 0;
    p->N_ITER_1 = 0;

    for (uint32_t i = 0; i < 31; ++i)
    {
        RouteSuitabilityData_1_Init(&(p->sub_1[i]));
    }

}

static inline void RouteSuitabilityData_Print(const RouteSuitabilityData* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->Q_TRACKINIT,
            p->D_TRACKINIT,
            p->D_SUITABILITY,
            p->Q_SUITABILITY,
            p->M_LOADINGGAUGE,
            p->M_AXLELOAD,
            p->M_TRACTION,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        RouteSuitabilityData_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int RouteSuitabilityData_Equal(const RouteSuitabilityData* a, const RouteSuitabilityData* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->Q_TRACKINIT == b->Q_TRACKINIT);

    if (a->Q_TRACKINIT == 1)
    {
        status = status && (a->D_TRACKINIT == b->D_TRACKINIT);
    }

    if (a->Q_TRACKINIT == 0)
    {
        status = status && (a->D_SUITABILITY == b->D_SUITABILITY);
    }
    status = status && (a->Q_SUITABILITY == b->Q_SUITABILITY);

    if (a->Q_SUITABILITY == 0)
    {
        status = status && (a->M_LOADINGGAUGE == b->M_LOADINGGAUGE);
    }

    if (a->Q_SUITABILITY == 1)
    {
        status = status && (a->M_AXLELOAD == b->M_AXLELOAD);
    }

    if (a->Q_SUITABILITY == 2)
    {
        status = status && (a->M_TRACTION == b->M_TRACTION);
    }
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && RouteSuitabilityData_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t RouteSuitabilityData_Length(const RouteSuitabilityData* p)
{
    return (uint32_t)(p->L_PACKET);
}

int RouteSuitabilityData_EncodeInt(const RouteSuitabilityData* p, Metadata* data, kcg_int* stream);

int RouteSuitabilityData_DecodeInt(RouteSuitabilityData* p, const Metadata* data, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // ROUTESUITABILITYDATA_H_INCLUDED


