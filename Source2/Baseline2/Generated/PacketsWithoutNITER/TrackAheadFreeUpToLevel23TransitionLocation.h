
#ifndef TRACKAHEADFREEUPTOLEVEL23TRANSITIONLOCATION_H_INCLUDED
#define TRACKAHEADFREEUPTOLEVEL23TRANSITIONLOCATION_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_TrackAheadFreeUpToLevel23TransitionLocation
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

struct TrackAheadFreeUpToLevel23TransitionLocation
{
    PacketHeader header;

    // TransmissionMedia=Balise
    // Notification to on-board that track ahead is free from the balise
    // group transmitting this information up to the level 2/3 transition location
    // Packet Number = 90

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
};

typedef struct TrackAheadFreeUpToLevel23TransitionLocation TrackAheadFreeUpToLevel23TransitionLocation;

#define TRACKAHEADFREEUPTOLEVEL23TRANSITIONLOCATION_BITSIZE 30

TrackAheadFreeUpToLevel23TransitionLocation*  TrackAheadFreeUpToLevel23TransitionLocation_New(void);

void   TrackAheadFreeUpToLevel23TransitionLocation_Delete(TrackAheadFreeUpToLevel23TransitionLocation*);

static inline void TrackAheadFreeUpToLevel23TransitionLocation_Init(TrackAheadFreeUpToLevel23TransitionLocation* p)
{
    p->header.NID_PACKET = 90;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
    p->Q_NEWCOUNTRY = 0;
    p->NID_C = 0;
    p->NID_BG = 0;
}

/*@
    logic integer BitSize{L}(TrackAheadFreeUpToLevel23TransitionLocation* p) = TRACKAHEADFREEUPTOLEVEL23TRANSITIONLOCATION_BITSIZE;

    logic integer MaxBitSize{L}(TrackAheadFreeUpToLevel23TransitionLocation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, TrackAheadFreeUpToLevel23TransitionLocation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(TrackAheadFreeUpToLevel23TransitionLocation* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_NEWCOUNTRY);

    predicate ZeroInitialized(TrackAheadFreeUpToLevel23TransitionLocation* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_NEWCOUNTRY);

    predicate EqualBits(Bitstream* stream, integer pos, TrackAheadFreeUpToLevel23TransitionLocation* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY);

    predicate UpperBitsNotSet(TrackAheadFreeUpToLevel23TransitionLocation* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int TrackAheadFreeUpToLevel23TransitionLocation_UpperBitsNotSet(const TrackAheadFreeUpToLevel23TransitionLocation* p);

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
int TrackAheadFreeUpToLevel23TransitionLocation_EncodeBit(const TrackAheadFreeUpToLevel23TransitionLocation* p, Bitstream* stream);

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
int TrackAheadFreeUpToLevel23TransitionLocation_DecodeBit(TrackAheadFreeUpToLevel23TransitionLocation* p, Bitstream* stream);

static inline void TrackAheadFreeUpToLevel23TransitionLocation_Print(const TrackAheadFreeUpToLevel23TransitionLocation* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu)",
            p->Q_DIR,
            p->L_PACKET,
            p->Q_NEWCOUNTRY,
            p->NID_C,
            p->NID_BG);
}

static inline int TrackAheadFreeUpToLevel23TransitionLocation_Equal(const TrackAheadFreeUpToLevel23TransitionLocation* a, const TrackAheadFreeUpToLevel23TransitionLocation* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->Q_NEWCOUNTRY == b->Q_NEWCOUNTRY);

    if (a->Q_NEWCOUNTRY == 1)
    {
        status = status && (a->NID_C == b->NID_C);
    }
    status = status && (a->NID_BG == b->NID_BG);

    return status;
}

static inline uint32_t TrackAheadFreeUpToLevel23TransitionLocation_Length(const TrackAheadFreeUpToLevel23TransitionLocation* p)
{
    return (uint32_t)(p->L_PACKET);
}

int TrackAheadFreeUpToLevel23TransitionLocation_EncodeInt(const TrackAheadFreeUpToLevel23TransitionLocation* p, Metadata* data, kcg_int* stream);

int TrackAheadFreeUpToLevel23TransitionLocation_DecodeInt(TrackAheadFreeUpToLevel23TransitionLocation* p, const Metadata* data, const kcg_int* stream);

#endif // TRACKAHEADFREEUPTOLEVEL23TRANSITIONLOCATION_H_INCLUDED

