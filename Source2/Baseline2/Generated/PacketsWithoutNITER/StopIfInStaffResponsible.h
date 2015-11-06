
#ifndef STOPIFINSTAFFRESPONSIBLE_H_INCLUDED
#define STOPIFINSTAFFRESPONSIBLE_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_StopIfInStaffResponsible
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

struct StopIfInStaffResponsible
{
    PacketHeader header;

    // TransmissionMedia=Balise
    // Information to stop a train in staff responsible.
    // Packet Number = 137

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SRSTOP;         // # 1
};

typedef struct StopIfInStaffResponsible StopIfInStaffResponsible;

#define STOPIFINSTAFFRESPONSIBLE_BITSIZE 16

StopIfInStaffResponsible*  StopIfInStaffResponsible_New(void);

void   StopIfInStaffResponsible_Delete(StopIfInStaffResponsible*);

static inline void StopIfInStaffResponsible_Init(StopIfInStaffResponsible* p)
{
    p->header.NID_PACKET = 137;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_SRSTOP = 0;
}

/*@
    logic integer BitSize{L}(StopIfInStaffResponsible* p) = STOPIFINSTAFFRESPONSIBLE_BITSIZE;

    logic integer MaxBitSize{L}(StopIfInStaffResponsible* p) = BitSize(p);

    predicate Separated(Bitstream* stream, StopIfInStaffResponsible* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(StopIfInStaffResponsible* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SRSTOP);

    predicate ZeroInitialized(StopIfInStaffResponsible* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SRSTOP);

    predicate EqualBits(Bitstream* stream, integer pos, StopIfInStaffResponsible* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_SRSTOP);

    predicate UpperBitsNotSet(StopIfInStaffResponsible* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SRSTOP,         1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int StopIfInStaffResponsible_UpperBitsNotSet(const StopIfInStaffResponsible* p);

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
int StopIfInStaffResponsible_EncodeBit(const StopIfInStaffResponsible* p, Bitstream* stream);

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
int StopIfInStaffResponsible_DecodeBit(StopIfInStaffResponsible* p, Bitstream* stream);

static inline void StopIfInStaffResponsible_Print(const StopIfInStaffResponsible* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu)",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_SRSTOP);
}

static inline int StopIfInStaffResponsible_Equal(const StopIfInStaffResponsible* a, const StopIfInStaffResponsible* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_SRSTOP == b->Q_SRSTOP);

    return status;
}

static inline uint32_t StopIfInStaffResponsible_Length(const StopIfInStaffResponsible* p)
{
    return (uint32_t)(p->L_PACKET);
}

int StopIfInStaffResponsible_EncodeInt(const StopIfInStaffResponsible* p, Metadata* data, kcg_int* stream);

int StopIfInStaffResponsible_DecodeInt(StopIfInStaffResponsible* p, const Metadata* data, const kcg_int* stream);

#endif // STOPIFINSTAFFRESPONSIBLE_H_INCLUDED

