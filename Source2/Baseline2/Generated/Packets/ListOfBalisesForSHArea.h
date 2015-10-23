
#ifndef LISTOFBALISESFORSHAREA_H_INCLUDED
#define LISTOFBALISESFORSHAREA_H_INCLUDED

#include "Bitstream.h"
#include "PacketHeader.h"
#include "ListOfBalisesForSHArea_1.h"

struct ListOfBalisesForSHArea
{
    PacketHeader header;

    // TransmissionMedia=Any
    // Used to list balise group(s) which the train can pass over
    // in SH mode
    // Packet Number = 49

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   N_ITER_1;         // # 5
    ListOfBalisesForSHArea_1   sub_1[31];
};

typedef struct ListOfBalisesForSHArea ListOfBalisesForSHArea;

#define LISTOFBALISESFORSHAREA_BITSIZE 20

ListOfBalisesForSHArea*  ListOfBalisesForSHArea_New(void);

void   ListOfBalisesForSHArea_Delete(ListOfBalisesForSHArea*);

static inline void ListOfBalisesForSHArea_Init(ListOfBalisesForSHArea* p)
{
    p->header.NID_PACKET = 49;
    p->header.list = TRACKTOTRAIN;
    p->Q_DIR = 0;
    p->L_PACKET = 0;
}

/*@
    logic integer BitSize{L}(ListOfBalisesForSHArea* p) = LISTOFBALISESFORSHAREA_BITSIZE;

    logic integer MaxBitSize{L}(ListOfBalisesForSHArea* p) = BitSize(p);

    predicate Separated(Bitstream* stream, ListOfBalisesForSHArea* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(ListOfBalisesForSHArea* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(ListOfBalisesForSHArea* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, ListOfBalisesForSHArea* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

    predicate UpperBitsNotSet(ListOfBalisesForSHArea* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int ListOfBalisesForSHArea_UpperBitsNotSet(const ListOfBalisesForSHArea* p);

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
int ListOfBalisesForSHArea_EncodeBit(const ListOfBalisesForSHArea* p, Bitstream* stream);

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
int ListOfBalisesForSHArea_DecodeBit(ListOfBalisesForSHArea* p, Bitstream* stream);

static inline void ListOfBalisesForSHArea_Print(const ListOfBalisesForSHArea* p, FILE* stream)
{
    PacketHeader_Print(&p->header, stream);
    fprintf(stream, "(%"PRIu64",%"PRIu64",%"PRIu64"",
            p->Q_DIR,
            p->L_PACKET,
            p->N_ITER_1);

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        ListOfBalisesForSHArea_1_Print(&p->sub_1[i], stream);
    }

    fprintf(stream, ")");
}

static inline int ListOfBalisesForSHArea_Equal(const ListOfBalisesForSHArea* a, const ListOfBalisesForSHArea* b)
{
    int status = PacketHeader_Equal(&a->header, &b->header);
    
    status = status && (a->Q_DIR == b->Q_DIR);
    status = status && (a->L_PACKET == b->L_PACKET);
    status = status && (a->N_ITER_1 == b->N_ITER_1);
    if (a->N_ITER_1 == b->N_ITER_1)
    {
        for (uint32_t i = 0; i < a->N_ITER_1; ++i)
        {
            status = status && ListOfBalisesForSHArea_1_Equal(&a->sub_1[i], &b->sub_1[i]);
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static inline uint32_t ListOfBalisesForSHArea_Length(const ListOfBalisesForSHArea* p)
{
    return (uint32_t)(p->L_PACKET);
}

int ListOfBalisesForSHArea_EncodeInt(const ListOfBalisesForSHArea* p, PacketInfo* data, kcg_int* stream);

int ListOfBalisesForSHArea_DecodeInt(ListOfBalisesForSHArea* p, PacketInfo* data, kcg_int* stream);

#endif // LISTOFBALISESFORSHAREA_H_INCLUDED

