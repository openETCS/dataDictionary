
#ifndef AXLELOADSPEEDPROFILE_2_1_H_INCLUDED
#define AXLELOADSPEEDPROFILE_2_1_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_AxleLoadSpeedProfile
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

struct AxleLoadSpeedProfile_2_1
{

    uint64_t   M_AXLELOAD;       // # 7
    uint64_t   V_AXLELOAD;       // # 7
};

typedef struct AxleLoadSpeedProfile_2_1 AxleLoadSpeedProfile_2_1;

#define AXLELOADSPEEDPROFILE_2_1_BITSIZE 14

static inline void AxleLoadSpeedProfile_2_1_Init(AxleLoadSpeedProfile_2_1* p)
{
    p->M_AXLELOAD = 0;
    p->V_AXLELOAD = 0;
}

/*@
    logic integer BitSize{L}(AxleLoadSpeedProfile_2_1* p) = AXLELOADSPEEDPROFILE_2_1_BITSIZE;

    logic integer MaxBitSize{L}(AxleLoadSpeedProfile_2_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, AxleLoadSpeedProfile_2_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(AxleLoadSpeedProfile_2_1* p) =
      Invariant(p->M_AXLELOAD)        &&
      Invariant(p->V_AXLELOAD);

    predicate ZeroInitialized(AxleLoadSpeedProfile_2_1* p) =
      ZeroInitialized(p->M_AXLELOAD)        &&
      ZeroInitialized(p->V_AXLELOAD);

    predicate EqualBits(Bitstream* stream, integer pos, AxleLoadSpeedProfile_2_1* p) =
      EqualBits(stream, pos,       pos + 7,   p->M_AXLELOAD)        &&
      EqualBits(stream, pos + 7,   pos + 14,  p->V_AXLELOAD);

    predicate UpperBitsNotSet(AxleLoadSpeedProfile_2_1* p) =
      UpperBitsNotSet(p->M_AXLELOAD,       7)   &&
      UpperBitsNotSet(p->V_AXLELOAD,       7);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int AxleLoadSpeedProfile_2_1_UpperBitsNotSet(const AxleLoadSpeedProfile_2_1* p);

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
int AxleLoadSpeedProfile_2_1_EncodeBit(const AxleLoadSpeedProfile_2_1* p, Bitstream* stream);

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
int AxleLoadSpeedProfile_2_1_DecodeBit(AxleLoadSpeedProfile_2_1* p, Bitstream* stream);

static inline void AxleLoadSpeedProfile_2_1_Print(const AxleLoadSpeedProfile_2_1* p, FILE* stream)
{
    fprintf(stream, "(%lu,%lu)",
            p->M_AXLELOAD,
            p->V_AXLELOAD);
}

static inline int AxleLoadSpeedProfile_2_1_Equal(const AxleLoadSpeedProfile_2_1* a, const AxleLoadSpeedProfile_2_1* b)
{
    int status = 1;

    status = status && (a->M_AXLELOAD == b->M_AXLELOAD);
    status = status && (a->V_AXLELOAD == b->V_AXLELOAD);

    return status;
}

int AxleLoadSpeedProfile_2_1_EncodeInt(const AxleLoadSpeedProfile_2_1* p, kcg_int* startAddress, kcg_int* stream);

int AxleLoadSpeedProfile_2_1_DecodeInt(AxleLoadSpeedProfile_2_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // AXLELOADSPEEDPROFILE_2_1_H_INCLUDED

