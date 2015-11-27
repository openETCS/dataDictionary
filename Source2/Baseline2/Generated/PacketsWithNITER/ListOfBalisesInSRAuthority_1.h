
#ifndef LISTOFBALISESINSRAUTHORITY_1_H_INCLUDED
#define LISTOFBALISESINSRAUTHORITY_1_H_INCLUDED

/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_ListOfBalisesInSRAuthority
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

struct ListOfBalisesInSRAuthority_1
{

    uint64_t   Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
};

typedef struct ListOfBalisesInSRAuthority_1 ListOfBalisesInSRAuthority_1;

#define LISTOFBALISESINSRAUTHORITY_1_BITSIZE 15

/*@
    logic integer BitSize{L}(ListOfBalisesInSRAuthority_1* p) = LISTOFBALISESINSRAUTHORITY_1_BITSIZE;

    logic integer MaxBitSize{L}(ListOfBalisesInSRAuthority_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ListOfBalisesInSRAuthority_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ListOfBalisesInSRAuthority_1* p) =
      Invariant(p->Q_NEWCOUNTRY);

    predicate ZeroInitialized(ListOfBalisesInSRAuthority_1* p) =
      ZeroInitialized(p->Q_NEWCOUNTRY);

    predicate EqualBits(Bitstream* stream, integer pos, ListOfBalisesInSRAuthority_1* p) =
      EqualBits(stream, pos,       pos + 1,   p->Q_NEWCOUNTRY);

    predicate UpperBitsNotSet(ListOfBalisesInSRAuthority_1* p) =
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ListOfBalisesInSRAuthority_1_UpperBitsNotSet(const ListOfBalisesInSRAuthority_1* p);

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
int ListOfBalisesInSRAuthority_1_EncodeBit(const ListOfBalisesInSRAuthority_1* p, Bitstream* stream);

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
int ListOfBalisesInSRAuthority_1_DecodeBit(ListOfBalisesInSRAuthority_1* p, Bitstream* stream);

#ifndef FRAMAC_IGNORE

static inline void ListOfBalisesInSRAuthority_1_Init(ListOfBalisesInSRAuthority_1* p)
{
    p->Q_NEWCOUNTRY = 0;
    p->NID_C = 0;
    p->NID_BG = 0;
}

static inline void ListOfBalisesInSRAuthority_1_Print(const ListOfBalisesInSRAuthority_1* p, FILE* stream)
{
    fprintf(stream, "(%lu,%lu,%lu)",
            p->Q_NEWCOUNTRY,
            p->NID_C,
            p->NID_BG);
}

static inline int ListOfBalisesInSRAuthority_1_Equal(const ListOfBalisesInSRAuthority_1* a, const ListOfBalisesInSRAuthority_1* b)
{
    int status = 1;

    status = status && (a->Q_NEWCOUNTRY == b->Q_NEWCOUNTRY);

    if (a->Q_NEWCOUNTRY == 1)
    {
        status = status && (a->NID_C == b->NID_C);
    }
    status = status && (a->NID_BG == b->NID_BG);

    return status;
}

int ListOfBalisesInSRAuthority_1_EncodeInt(const ListOfBalisesInSRAuthority_1* p, kcg_int* startAddress, kcg_int* stream);

int ListOfBalisesInSRAuthority_1_DecodeInt(ListOfBalisesInSRAuthority_1* p, kcg_int* startAddress, const kcg_int* stream);

#endif // FRAMAC_IGNORE

#endif // LISTOFBALISESINSRAUTHORITY_1_H_INCLUDED

