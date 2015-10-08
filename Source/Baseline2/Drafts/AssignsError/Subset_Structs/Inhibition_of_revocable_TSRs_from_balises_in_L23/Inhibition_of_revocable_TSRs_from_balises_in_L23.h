
#ifndef INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_H_INCLUDED
#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_H_INCLUDED

#include "Bitstream.h"

struct Inhibition_of_revocable_TSRs_from_balises_in_L23
{
    // TransmissionMedia=RBC
    // This packet is used to inhibit revocable TSRs from balises in
    // level 2 or 3.       
    // Packet Number = 64

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
};

typedef struct Inhibition_of_revocable_TSRs_from_balises_in_L23 Inhibition_of_revocable_TSRs_from_balises_in_L23;

#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_BITSIZE 15

/*@
    logic integer BitSize{L}(Inhibition_of_revocable_TSRs_from_balises_in_L23* p) = INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_BITSIZE;

    logic integer MaxBitSize{L}(Inhibition_of_revocable_TSRs_from_balises_in_L23* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Inhibition_of_revocable_TSRs_from_balises_in_L23* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Inhibition_of_revocable_TSRs_from_balises_in_L23* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(Inhibition_of_revocable_TSRs_from_balises_in_L23* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, Inhibition_of_revocable_TSRs_from_balises_in_L23* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);


    predicate UpperBitsNotSet(Inhibition_of_revocable_TSRs_from_balises_in_L23* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

#endif // INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_H_INCLUDED

