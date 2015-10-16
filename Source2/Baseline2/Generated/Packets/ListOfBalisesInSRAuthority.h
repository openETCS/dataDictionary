
#ifndef LISTOFBALISESINSRAUTHORITY_H_INCLUDED
#define LISTOFBALISESINSRAUTHORITY_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"
#include "ListOfBalisesInSRAuthority_1.h"

struct ListOfBalisesInSRAuthority
{
    PacketHeader header;

    // TransmissionMedia=Radio
    // Used to list balise group(s) which the train can pass over
    // in SR mode
    // Packet Number = 63

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   N_ITER_1;         // # 5
    ListOfBalisesInSRAuthority_1   sub_1[31];
};

typedef struct ListOfBalisesInSRAuthority ListOfBalisesInSRAuthority;

#define LISTOFBALISESINSRAUTHORITY_BITSIZE 20

ListOfBalisesInSRAuthority*  ListOfBalisesInSRAuthority_New(void);

void   ListOfBalisesInSRAuthority_Delete(ListOfBalisesInSRAuthority*);

static inline void ListOfBalisesInSRAuthority_Init(ListOfBalisesInSRAuthority* p)
{
    p->header.NID_PACKET = 63;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
}

/*@
    logic integer BitSize{L}(ListOfBalisesInSRAuthority* p) = LISTOFBALISESINSRAUTHORITY_BITSIZE;

    logic integer MaxBitSize{L}(ListOfBalisesInSRAuthority* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ListOfBalisesInSRAuthority* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ListOfBalisesInSRAuthority* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(ListOfBalisesInSRAuthority* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, ListOfBalisesInSRAuthority* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

    predicate UpperBitsNotSet(ListOfBalisesInSRAuthority* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ListOfBalisesInSRAuthority_UpperBitsNotSet(const ListOfBalisesInSRAuthority* p);

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
int ListOfBalisesInSRAuthority_EncodeBit(const ListOfBalisesInSRAuthority* p, Bitstream* stream);

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
int ListOfBalisesInSRAuthority_DecodeBit(ListOfBalisesInSRAuthority* p, Bitstream* stream);

static inline void ListOfBalisesInSRAuthority_Print(const ListOfBalisesInSRAuthority* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64"",
            p->Q_DIR,
            p->L_PACKET,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        ListOfBalisesInSRAuthority_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int ListOfBalisesInSRAuthority_Equal(const ListOfBalisesInSRAuthority* a, const ListOfBalisesInSRAuthority* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && ListOfBalisesInSRAuthority_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t ListOfBalisesInSRAuthority_Length(const ListOfBalisesInSRAuthority* p)
{
    return (uint32_t)(p->L_PACKET);
}

#endif // LISTOFBALISESINSRAUTHORITY_H_INCLUDED

