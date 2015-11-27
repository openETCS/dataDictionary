
#ifndef TEMPORARYSPEEDRESTRICTION_H_INCLUDED
#define TEMPORARYSPEEDRESTRICTION_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_TemporarySpeedRestriction
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

struct TemporarySpeedRestriction
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Transmission of temporary speed restriction.
    // Packet Number = 65

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t   NID_TSR;          // # 8
    uint64_t  D_TSR;            // # 15
    uint64_t  L_TSR;            // # 15
    uint64_t   Q_FRONT;          // # 1
    uint64_t   V_TSR;            // # 7
};

typedef struct TemporarySpeedRestriction TemporarySpeedRestriction;

#define TEMPORARYSPEEDRESTRICTION_BITSIZE 63

/*@
    logic integer BitSize{L}(TemporarySpeedRestriction* p) = TEMPORARYSPEEDRESTRICTION_BITSIZE;

    logic integer MaxBitSize{L}(TemporarySpeedRestriction* p) = BitSize(p);

    predicate Separated(Bitstream* stream, TemporarySpeedRestriction* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(TemporarySpeedRestriction* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->NID_TSR)           &&
      Invariant(p->D_TSR)             &&
      Invariant(p->L_TSR)             &&
      Invariant(p->Q_FRONT)           &&
      Invariant(p->V_TSR);

    predicate ZeroInitialized(TemporarySpeedRestriction* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->NID_TSR)           &&
      ZeroInitialized(p->D_TSR)             &&
      ZeroInitialized(p->L_TSR)             &&
      ZeroInitialized(p->Q_FRONT)           &&
      ZeroInitialized(p->V_TSR);

    predicate EqualBits(Bitstream* stream, integer pos, TemporarySpeedRestriction* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 25,  p->NID_TSR)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_TSR)             &&
      EqualBits(stream, pos + 40,  pos + 55,  p->L_TSR)             &&
      EqualBits(stream, pos + 55,  pos + 56,  p->Q_FRONT)           &&
      EqualBits(stream, pos + 56,  pos + 63,  p->V_TSR);

    predicate UpperBitsNotSet(TemporarySpeedRestriction* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->NID_TSR,          8)   &&
      UpperBitsNotSet(p->D_TSR,            15)  &&
      UpperBitsNotSet(p->L_TSR,            15)  &&
      UpperBitsNotSet(p->Q_FRONT,          1)   &&
      UpperBitsNotSet(p->V_TSR,            7);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int TemporarySpeedRestriction_UpperBitsNotSet(const TemporarySpeedRestriction* p);

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
int TemporarySpeedRestriction_EncodeBit(const TemporarySpeedRestriction* p, Bitstream* stream);

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
int TemporarySpeedRestriction_DecodeBit(TemporarySpeedRestriction* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

TemporarySpeedRestriction*  TemporarySpeedRestriction_New(void);

void   TemporarySpeedRestriction_Delete(TemporarySpeedRestriction*);

static inline void TemporarySpeedRestriction_Init(TemporarySpeedRestriction* p)
{
    p->header.NID_PACKET = 65;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SCALE = 0;
    p->NID_TSR = 0;
    p->D_TSR = 0;
    p->L_TSR = 0;
    p->Q_FRONT = 0;
    p->V_TSR = 0;
}

static inline void TemporarySpeedRestriction_Print(const TemporarySpeedRestriction* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu)",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SCALE,
            p->NID_TSR,
            p->D_TSR,
            p->L_TSR,
            p->Q_FRONT,
            p->V_TSR);
}

static inline int TemporarySpeedRestriction_Equal(const TemporarySpeedRestriction* a, const TemporarySpeedRestriction* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SCALE == b->Q_SCALE);
    status = status && (a->NID_TSR == b->NID_TSR);
    status = status && (a->D_TSR == b->D_TSR);
    status = status && (a->L_TSR == b->L_TSR);
    status = status && (a->Q_FRONT == b->Q_FRONT);
    status = status && (a->V_TSR == b->V_TSR);

    return status;
}

static inline uint32_t TemporarySpeedRestriction_Length(const TemporarySpeedRestriction* p)
{
    return (uint32_t)(p->L_PACKET);
}

int TemporarySpeedRestriction_EncodeInt(const TemporarySpeedRestriction* p, Metadata* data, kcg_int* stream);

int TemporarySpeedRestriction_DecodeInt(TemporarySpeedRestriction* p, const Metadata* data, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // TEMPORARYSPEEDRESTRICTION_H_INCLUDED


