
#ifndef LIST_OF_BALISES_FOR_SH_AREA_H_INCLUDED
#define LIST_OF_BALISES_FOR_SH_AREA_H_INCLUDED

#include "Bitstream.h"

struct List_of_balises_for_SH_Area
{
    // TransmissionMedia=Any
    // Used to list balise group(s) which the train can pass over in SH mode
    // Packet Number = 49

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  N_ITER;           // # 5// # 1// # 10// # 14
};

typedef struct List_of_balises_for_SH_Area List_of_balises_for_SH_Area;

#define LIST_OF_BALISES_FOR_SH_AREA_BITSIZE 53

/*@
    logic integer BitSize{L}(List_of_balises_for_SH_Area* p) = LIST_OF_BALISES_FOR_SH_AREA_BITSIZE;

    logic integer MaxBitSize{L}(List_of_balises_for_SH_Area* p) = BitSize(p);

    predicate Separated(Bitstream* stream, List_of_balises_for_SH_Area* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(List_of_balises_for_SH_Area* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->N_ITER)            &&
      Invariant(p->Q_NEWCOUNTRY(k))   &&
      Invariant(p->NID_C(k))          &&
      Invariant(p->NID_BG(k));

    predicate ZeroInitialized(List_of_balises_for_SH_Area* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->Q_NEWCOUNTRY(k))   &&
      ZeroInitialized(p->NID_C(k))          &&
      ZeroInitialized(p->NID_BG(k));

    predicate EqualBits(Bitstream* stream, integer pos, List_of_balises_for_SH_Area* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 28,  p->N_ITER)            &&
      EqualBits(stream, pos + 28,  pos + 29,  p->Q_NEWCOUNTRY(k))   &&
      EqualBits(stream, pos + 29,  pos + 39,  p->NID_C(k))          &&
      EqualBits(stream, pos + 39,  pos + 53,  p->NID_BG(k));


    predicate UpperBitsNotSet(List_of_balises_for_SH_Area* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY(k),  1)   &&
      UpperBitsNotSet(p->NID_C(k),         10)  &&
      UpperBitsNotSet(p->NID_BG(k),        14);

*/

#endif // LIST_OF_BALISES_FOR_SH_AREA_H_INCLUDED

