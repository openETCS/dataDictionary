
#ifndef TEMPORARYSPEEDRESTRICTIONREVOCATION_H_INCLUDED
#define TEMPORARYSPEEDRESTRICTIONREVOCATION_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_TemporarySpeedRestrictionRevocation
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

struct TemporarySpeedRestrictionRevocation
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Transmission of temporary speed restriction revocation.
    // Packet Number = 66

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   NID_TSR;          // # 8
};

typedef struct TemporarySpeedRestrictionRevocation TemporarySpeedRestrictionRevocation;

#define TEMPORARYSPEEDRESTRICTIONREVOCATION_BITSIZE 23

/*@
    logic integer BitSize{L}(TemporarySpeedRestrictionRevocation* p) = TEMPORARYSPEEDRESTRICTIONREVOCATION_BITSIZE;

    logic integer MaxBitSize{L}(TemporarySpeedRestrictionRevocation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, TemporarySpeedRestrictionRevocation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(TemporarySpeedRestrictionRevocation* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_TSR);

    predicate ZeroInitialized(TemporarySpeedRestrictionRevocation* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_TSR);

    predicate EqualBits(Bitstream* stream, integer pos, TemporarySpeedRestrictionRevocation* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 23,  p->NID_TSR);

    predicate UpperBitsNotSet(TemporarySpeedRestrictionRevocation* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_TSR,          8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int TemporarySpeedRestrictionRevocation_UpperBitsNotSet(const TemporarySpeedRestrictionRevocation* p);

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
int TemporarySpeedRestrictionRevocation_EncodeBit(const TemporarySpeedRestrictionRevocation* p, Bitstream* stream);

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
int TemporarySpeedRestrictionRevocation_DecodeBit(TemporarySpeedRestrictionRevocation* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

TemporarySpeedRestrictionRevocation*  TemporarySpeedRestrictionRevocation_New(void);

void   TemporarySpeedRestrictionRevocation_Delete(TemporarySpeedRestrictionRevocation*);

static inline void TemporarySpeedRestrictionRevocation_Init(TemporarySpeedRestrictionRevocation* p)
{
    p->header.NID_PACKET = 66;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->NID_TSR = 0;
}

static inline void TemporarySpeedRestrictionRevocation_Print(const TemporarySpeedRestrictionRevocation* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu)",
            p->Q_DIR,
            p->L_PACKET,
            p->NID_TSR);
}

static inline int TemporarySpeedRestrictionRevocation_Equal(const TemporarySpeedRestrictionRevocation* a, const TemporarySpeedRestrictionRevocation* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->NID_TSR == b->NID_TSR);

    return status;
}

static inline uint32_t TemporarySpeedRestrictionRevocation_Length(const TemporarySpeedRestrictionRevocation* p)
{
    return (uint32_t)(p->L_PACKET);
}

int TemporarySpeedRestrictionRevocation_EncodeInt(const TemporarySpeedRestrictionRevocation* p, Metadata* data, kcg_int* stream);

int TemporarySpeedRestrictionRevocation_DecodeInt(TemporarySpeedRestrictionRevocation* p, const Metadata* data, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // TEMPORARYSPEEDRESTRICTIONREVOCATION_H_INCLUDED


