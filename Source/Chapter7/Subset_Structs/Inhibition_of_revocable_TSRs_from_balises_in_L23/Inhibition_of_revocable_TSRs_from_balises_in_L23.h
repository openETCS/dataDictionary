
#ifndef INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_H_INCLUDED
#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_H_INCLUDED

#include "Bitstream.h"

struct Inhibition_of_revocable_TSRs_from_balises_in_L23
{
    // TransmissionMedia=RBC
    // This packet is used to inhibit revocable TSRs from balises in level 2 or 3.
    // Packet Number = 64

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
};

typedef struct Inhibition_of_revocable_TSRs_from_balises_in_L23 Inhibition_of_revocable_TSRs_from_balises_in_L23;

#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_BITSIZE 23

/*@
    logic integer BitSize{L}(Inhibition_of_revocable_TSRs_from_balises_in_L23* p) = INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_BITSIZE;

    logic integer MaxBitSize{L}(Inhibition_of_revocable_TSRs_from_balises_in_L23* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Inhibition_of_revocable_TSRs_from_balises_in_L23* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Inhibition_of_revocable_TSRs_from_balises_in_L23* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(Inhibition_of_revocable_TSRs_from_balises_in_L23* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, Inhibition_of_revocable_TSRs_from_balises_in_L23* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);


    predicate UpperBitsNotSet(Inhibition_of_revocable_TSRs_from_balises_in_L23* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

#endif // INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_H_INCLUDED

