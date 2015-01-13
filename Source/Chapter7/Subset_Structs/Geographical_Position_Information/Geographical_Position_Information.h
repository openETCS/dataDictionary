
#ifndef GEOGRAPHICAL_POSITION_INFORMATION_H_INCLUDED
#define GEOGRAPHICAL_POSITION_INFORMATION_H_INCLUDED

#include "Bitstream.h"

struct Geographical_Position_Information
{
    // TransmissionMedia=Balise, RBC
    // This packet gives geographical location information for one or multiple references to the train.
    // Packet Number = 79

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  Q_NEWCOUNTRY;     // # 1
    uint64_t  NID_C;            // # 10
    uint64_t  NID_BG;           // # 14
    uint64_t  D_POSOFF;         // # 15
    uint64_t  Q_MPOSITION;      // # 1
    uint64_t  M_POSITION;       // # 24
    uint64_t  N_ITER;           // # 5// # 1// # 10// # 14// # 15// # 1// # 24
};

typedef struct Geographical_Position_Information Geographical_Position_Information;

#define GEOGRAPHICAL_POSITION_INFORMATION_BITSIZE 160

/*@
    logic integer BitSize{L}(Geographical_Position_Information* p) = GEOGRAPHICAL_POSITION_INFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(Geographical_Position_Information* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Geographical_Position_Information* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Geographical_Position_Information* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_NEWCOUNTRY)      &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_BG)            &&
      Invariant(p->D_POSOFF)          &&
      Invariant(p->Q_MPOSITION)       &&
      Invariant(p->M_POSITION)        &&
      Invariant(p->N_ITER)            &&
      Invariant(p->Q_NEWCOUNTRY(k))   &&
      Invariant(p->NID_C(k))          &&
      Invariant(p->NID_BG(k))         &&
      Invariant(p->D_POSOFF(k))       &&
      Invariant(p->Q_MPOSITION(k))    &&
      Invariant(p->M_POSITION(k));

    predicate ZeroInitialized(Geographical_Position_Information* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_NEWCOUNTRY)      &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_BG)            &&
      ZeroInitialized(p->D_POSOFF)          &&
      ZeroInitialized(p->Q_MPOSITION)       &&
      ZeroInitialized(p->M_POSITION)        &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->Q_NEWCOUNTRY(k))   &&
      ZeroInitialized(p->NID_C(k))          &&
      ZeroInitialized(p->NID_BG(k))         &&
      ZeroInitialized(p->D_POSOFF(k))       &&
      ZeroInitialized(p->Q_MPOSITION(k))    &&
      ZeroInitialized(p->M_POSITION(k));

    predicate EqualBits(Bitstream* stream, integer pos, Geographical_Position_Information* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 26,  p->Q_NEWCOUNTRY)      &&
      EqualBits(stream, pos + 26,  pos + 36,  p->NID_C)             &&
      EqualBits(stream, pos + 36,  pos + 50,  p->NID_BG)            &&
      EqualBits(stream, pos + 50,  pos + 65,  p->D_POSOFF)          &&
      EqualBits(stream, pos + 65,  pos + 66,  p->Q_MPOSITION)       &&
      EqualBits(stream, pos + 66,  pos + 90,  p->M_POSITION)        &&
      EqualBits(stream, pos + 90,  pos + 95,  p->N_ITER)            &&
      EqualBits(stream, pos + 95,  pos + 96,  p->Q_NEWCOUNTRY(k))   &&
      EqualBits(stream, pos + 96,  pos + 106, p->NID_C(k))          &&
      EqualBits(stream, pos + 106, pos + 120, p->NID_BG(k))         &&
      EqualBits(stream, pos + 120, pos + 135, p->D_POSOFF(k))       &&
      EqualBits(stream, pos + 135, pos + 136, p->Q_MPOSITION(k))    &&
      EqualBits(stream, pos + 136, pos + 160, p->M_POSITION(k));


    predicate UpperBitsNotSet(Geographical_Position_Information* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1)   &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_BG,           14)  &&
      UpperBitsNotSet(p->D_POSOFF,         15)  &&
      UpperBitsNotSet(p->Q_MPOSITION,      1)   &&
      UpperBitsNotSet(p->M_POSITION,       24)  &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY(k),  1)   &&
      UpperBitsNotSet(p->NID_C(k),         10)  &&
      UpperBitsNotSet(p->NID_BG(k),        14)  &&
      UpperBitsNotSet(p->D_POSOFF(k),      15)  &&
      UpperBitsNotSet(p->Q_MPOSITION(k),   1)   &&
      UpperBitsNotSet(p->M_POSITION(k),    24);

*/

#endif // GEOGRAPHICAL_POSITION_INFORMATION_H_INCLUDED

