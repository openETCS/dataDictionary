
#ifndef GEOGRAPHICALPOSITIONINFORMATION_1_H_INCLUDED
#define GEOGRAPHICALPOSITIONINFORMATION_1_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_GeographicalPositionInformation
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

struct GeographicalPositionInformation_1
{

    uint64_t   Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
    uint64_t  D_POSOFF;         // # 15
    uint64_t   Q_MPOSITION;      // # 1
    uint64_t  M_POSITION;       // # 20
};

typedef struct GeographicalPositionInformation_1 GeographicalPositionInformation_1;

#define GEOGRAPHICALPOSITIONINFORMATION_1_BITSIZE 51

/*@
    logic integer BitSize{L}(GeographicalPositionInformation_1* p) = GEOGRAPHICALPOSITIONINFORMATION_1_BITSIZE;

    logic integer MaxBitSize{L}(GeographicalPositionInformation_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, GeographicalPositionInformation_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(GeographicalPositionInformation_1* p) =
      Invariant(p->Q_NEWCOUNTRY);

    predicate ZeroInitialized(GeographicalPositionInformation_1* p) =
      ZeroInitialized(p->Q_NEWCOUNTRY);

    predicate EqualBits(Bitstream* stream, integer pos, GeographicalPositionInformation_1* p) =
      EqualBits(stream, pos,       pos + 1,   p->Q_NEWCOUNTRY);

    predicate UpperBitsNotSet(GeographicalPositionInformation_1* p) =
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int GeographicalPositionInformation_1_UpperBitsNotSet(const GeographicalPositionInformation_1* p);

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
int GeographicalPositionInformation_1_EncodeBit(const GeographicalPositionInformation_1* p, Bitstream* stream);

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
int GeographicalPositionInformation_1_DecodeBit(GeographicalPositionInformation_1* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

static inline void GeographicalPositionInformation_1_Init(GeographicalPositionInformation_1* p)
{
    p->Q_NEWCOUNTRY = 0;
    p->NID_C = 0;
    p->NID_BG = 0;
    p->D_POSOFF = 0;
    p->Q_MPOSITION = 0;
    p->M_POSITION = 0;
}

static inline void GeographicalPositionInformation_1_Print(const GeographicalPositionInformation_1* p, FILE* stream)
{
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu,%lu)",
            p->Q_NEWCOUNTRY,
            p->NID_C,
            p->NID_BG,
            p->D_POSOFF,
            p->Q_MPOSITION,
            p->M_POSITION);
}

static inline int GeographicalPositionInformation_1_Equal(const GeographicalPositionInformation_1* a, const GeographicalPositionInformation_1* b)
{
    int status = 1;

    status = status && (a->Q_NEWCOUNTRY == b->Q_NEWCOUNTRY);

    if (a->Q_NEWCOUNTRY == 1)
    {
        status = status && (a->NID_C == b->NID_C);
    }
    status = status && (a->NID_BG == b->NID_BG);
    status = status && (a->D_POSOFF == b->D_POSOFF);
    status = status && (a->Q_MPOSITION == b->Q_MPOSITION);
    status = status && (a->M_POSITION == b->M_POSITION);

    return status;
}

int GeographicalPositionInformation_1_EncodeInt(const GeographicalPositionInformation_1* p, kcg_int* startAddress, kcg_int* stream);

int GeographicalPositionInformation_1_DecodeInt(GeographicalPositionInformation_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // GEOGRAPHICALPOSITIONINFORMATION_1_H_INCLUDED

