
#ifndef INTERNATIONALSTATICSPEEDPROFILE_2_1_H_INCLUDED
#define INTERNATIONALSTATICSPEEDPROFILE_2_1_H_INCLUDED

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

struct InternationalStaticSpeedProfile_2_1
{

    uint64_t   NC_DIFF;          // # 4
    uint64_t   V_DIFF;           // # 7
};

typedef struct InternationalStaticSpeedProfile_2_1 InternationalStaticSpeedProfile_2_1;

#define INTERNATIONALSTATICSPEEDPROFILE_2_1_BITSIZE 11

static inline void InternationalStaticSpeedProfile_2_1_Init(InternationalStaticSpeedProfile_2_1* p)
{
    p->NC_DIFF = 0;
    p->V_DIFF = 0;
}

/*@
    logic integer BitSize{L}(InternationalStaticSpeedProfile_2_1* p) = INTERNATIONALSTATICSPEEDPROFILE_2_1_BITSIZE;

    logic integer MaxBitSize{L}(InternationalStaticSpeedProfile_2_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, InternationalStaticSpeedProfile_2_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(InternationalStaticSpeedProfile_2_1* p) =
      Invariant(p->NC_DIFF)           &&
      Invariant(p->V_DIFF);

    predicate ZeroInitialized(InternationalStaticSpeedProfile_2_1* p) =
      ZeroInitialized(p->NC_DIFF)           &&
      ZeroInitialized(p->V_DIFF);

    predicate EqualBits(Bitstream* stream, integer pos, InternationalStaticSpeedProfile_2_1* p) =
      EqualBits(stream, pos,       pos + 4,   p->NC_DIFF)           &&
      EqualBits(stream, pos + 4,   pos + 11,  p->V_DIFF);

    predicate UpperBitsNotSet(InternationalStaticSpeedProfile_2_1* p) =
      UpperBitsNotSet(p->NC_DIFF,          4)   &&
      UpperBitsNotSet(p->V_DIFF,           7);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int InternationalStaticSpeedProfile_2_1_UpperBitsNotSet(const InternationalStaticSpeedProfile_2_1* p);

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
int InternationalStaticSpeedProfile_2_1_EncodeBit(const InternationalStaticSpeedProfile_2_1* p, Bitstream* stream);

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
int InternationalStaticSpeedProfile_2_1_DecodeBit(InternationalStaticSpeedProfile_2_1* p, Bitstream* stream);

static inline void InternationalStaticSpeedProfile_2_1_Print(const InternationalStaticSpeedProfile_2_1* p, FILE* stream)
{
    fprintf(stream, "(%lu,%lu)",
            p->NC_DIFF,
            p->V_DIFF);
}

static inline int InternationalStaticSpeedProfile_2_1_Equal(const InternationalStaticSpeedProfile_2_1* a, const InternationalStaticSpeedProfile_2_1* b)
{
    int status = 1;

    status = status && (a->NC_DIFF == b->NC_DIFF);
    status = status && (a->V_DIFF == b->V_DIFF);

    return status;
}

int InternationalStaticSpeedProfile_2_1_EncodeInt(const InternationalStaticSpeedProfile_2_1* p, kcg_int* startAddress, kcg_int* stream);

int InternationalStaticSpeedProfile_2_1_DecodeInt(InternationalStaticSpeedProfile_2_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // INTERNATIONALSTATICSPEEDPROFILE_2_1_H_INCLUDED

