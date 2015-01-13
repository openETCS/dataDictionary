
#ifndef ONBOARD_TELEPHONE_90S_H_INCLUDED
#define ONBOARD_TELEPHONE_90S_H_INCLUDED

#include "Bitstream.h"

struct Onboard_telephone_numbers
{
    // TransmissionMedia=RBC, RIU
    // Telephone numbers associated to the onboard equipment
    // Packet Number = 3

    uint64_t  NID_PACKET;       // # 8
    uint64_t  L_PACKET;         // # 13
    uint64_t  N_ITER;           // # 5// # 64
};

typedef struct Onboard_telephone_numbers Onboard_telephone_numbers;

#define ONBOARD_TELEPHONE_90S_BITSIZE 90

/*@
    logic integer BitSize{L}(Onboard_telephone_numbers* p) = ONBOARD_TELEPHONE_90S_BITSIZE;

    logic integer MaxBitSize{L}(Onboard_telephone_numbers* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Onboard_telephone_numbers* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Onboard_telephone_numbers* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->N_ITER)            &&
      Invariant(p->NID_RADIO_(k));

    predicate ZeroInitialized(Onboard_telephone_numbers* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->NID_RADIO_(k));

    predicate EqualBits(Bitstream* stream, integer pos, Onboard_telephone_numbers* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET)          &&
      EqualBits(stream, pos + 21,  pos + 26,  p->N_ITER)            &&
      EqualBits(stream, pos + 26,  pos + 90,  p->NID_RADIO_(k));


    predicate UpperBitsNotSet(Onboard_telephone_numbers* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->NID_RADIO_(k),    64);

*/

#endif // ONBOARD_TELEPHONE_90S_H_INCLUDED

