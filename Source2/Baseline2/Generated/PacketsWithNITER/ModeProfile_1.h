
#ifndef MODEPROFILE_1_H_INCLUDED
#define MODEPROFILE_1_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_ModeProfile
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

struct ModeProfile_1
{

    uint64_t  D_MAMODE;         // # 15
    uint64_t   M_MAMODE;         // # 2
    uint64_t   V_MAMODE;         // # 7
    uint64_t  L_MAMODE;         // # 15
    uint64_t  L_ACKMAMODE;      // # 15
};

typedef struct ModeProfile_1 ModeProfile_1;

#define MODEPROFILE_1_BITSIZE 54

/*@
    logic integer BitSize{L}(ModeProfile_1* p) = MODEPROFILE_1_BITSIZE;

    logic integer MaxBitSize{L}(ModeProfile_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ModeProfile_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ModeProfile_1* p) =
      Invariant(p->D_MAMODE)          &&
      Invariant(p->M_MAMODE)          &&
      Invariant(p->V_MAMODE)          &&
      Invariant(p->L_MAMODE)          &&
      Invariant(p->L_ACKMAMODE);

    predicate ZeroInitialized(ModeProfile_1* p) =
      ZeroInitialized(p->D_MAMODE)          &&
      ZeroInitialized(p->M_MAMODE)          &&
      ZeroInitialized(p->V_MAMODE)          &&
      ZeroInitialized(p->L_MAMODE)          &&
      ZeroInitialized(p->L_ACKMAMODE);

    predicate EqualBits(Bitstream* stream, integer pos, ModeProfile_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_MAMODE)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->M_MAMODE)          &&
      EqualBits(stream, pos + 17,  pos + 24,  p->V_MAMODE)          &&
      EqualBits(stream, pos + 24,  pos + 39,  p->L_MAMODE)          &&
      EqualBits(stream, pos + 39,  pos + 54,  p->L_ACKMAMODE);

    predicate UpperBitsNotSet(ModeProfile_1* p) =
      UpperBitsNotSet(p->D_MAMODE,         15)  &&
      UpperBitsNotSet(p->M_MAMODE,         2)   &&
      UpperBitsNotSet(p->V_MAMODE,         7)   &&
      UpperBitsNotSet(p->L_MAMODE,         15)  &&
      UpperBitsNotSet(p->L_ACKMAMODE,      15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ModeProfile_1_UpperBitsNotSet(const ModeProfile_1* p);

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
int ModeProfile_1_EncodeBit(const ModeProfile_1* p, Bitstream* stream);

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
int ModeProfile_1_DecodeBit(ModeProfile_1* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

static inline void ModeProfile_1_Init(ModeProfile_1* p)
{
    p->D_MAMODE = 0;
    p->M_MAMODE = 0;
    p->V_MAMODE = 0;
    p->L_MAMODE = 0;
    p->L_ACKMAMODE = 0;
}

static inline void ModeProfile_1_Print(const ModeProfile_1* p, FILE* stream)
{
    fprintf(stream, "(%lu,%lu,%lu,%lu,%lu)",
            p->D_MAMODE,
            p->M_MAMODE,
            p->V_MAMODE,
            p->L_MAMODE,
            p->L_ACKMAMODE);
}

static inline int ModeProfile_1_Equal(const ModeProfile_1* a, const ModeProfile_1* b)
{
    int status = 1;

    status = status && (a->D_MAMODE == b->D_MAMODE);
    status = status && (a->M_MAMODE == b->M_MAMODE);
    status = status && (a->V_MAMODE == b->V_MAMODE);
    status = status && (a->L_MAMODE == b->L_MAMODE);
    status = status && (a->L_ACKMAMODE == b->L_ACKMAMODE);

    return status;
}

int ModeProfile_1_EncodeInt(const ModeProfile_1* p, kcg_int* startAddress, kcg_int* stream);

int ModeProfile_1_DecodeInt(ModeProfile_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // MODEPROFILE_1_H_INCLUDED

