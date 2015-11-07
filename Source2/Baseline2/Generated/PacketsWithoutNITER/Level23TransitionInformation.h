
#ifndef LEVEL23TRANSITIONINFORMATION_H_INCLUDED
#define LEVEL23TRANSITIONINFORMATION_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrainToTrack_Level23TransitionInformation
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

struct Level23TransitionInformation
{
    PacketHeader header;

    // TransmissionMedia=Radio
    // Identity of the level 2/3 transition balise group
    // Packet Number = 9

    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_LTRBG;        // # 24
};

typedef struct Level23TransitionInformation Level23TransitionInformation;

#define LEVEL23TRANSITIONINFORMATION_BITSIZE 37

/*@
    logic integer BitSize{L}(Level23TransitionInformation* p) = LEVEL23TRANSITIONINFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(Level23TransitionInformation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Level23TransitionInformation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Level23TransitionInformation* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_LTRBG);

    predicate ZeroInitialized(Level23TransitionInformation* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_LTRBG);

    predicate EqualBits(Bitstream* stream, integer pos, Level23TransitionInformation* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 37,  p->NID_LTRBG);

    predicate UpperBitsNotSet(Level23TransitionInformation* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_LTRBG,        24);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Level23TransitionInformation_UpperBitsNotSet(const Level23TransitionInformation* p);

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
int Level23TransitionInformation_EncodeBit(const Level23TransitionInformation* p, Bitstream* stream);

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
int Level23TransitionInformation_DecodeBit(Level23TransitionInformation* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

Level23TransitionInformation*  Level23TransitionInformation_New(void);

void   Level23TransitionInformation_Delete(Level23TransitionInformation*);

static inline void Level23TransitionInformation_Init(Level23TransitionInformation* p)
{
    p->header.NID_PACKET = 9;
    p->header.list = TRAINTOTRACK;
    p->L_PACKET = 0;
    p->NID_LTRBG = 0;
}

static inline void Level23TransitionInformation_Print(const Level23TransitionInformation* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%lu,%lu)",
            p->L_PACKET,
            p->NID_LTRBG);
}

static inline int Level23TransitionInformation_Equal(const Level23TransitionInformation* a, const Level23TransitionInformation* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->NID_LTRBG == b->NID_LTRBG);

    return status;
}

static inline uint32_t Level23TransitionInformation_Length(const Level23TransitionInformation* p)
{
    return (uint32_t)(p->L_PACKET);
}

int Level23TransitionInformation_EncodeInt(const Level23TransitionInformation* p, Metadata* data, kcg_int* stream);

int Level23TransitionInformation_DecodeInt(Level23TransitionInformation* p, const Metadata* data, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // LEVEL23TRANSITIONINFORMATION_H_INCLUDED


