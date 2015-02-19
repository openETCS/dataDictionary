
#ifndef INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_DATA_H_INCLUDED
#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_DATA_H_INCLUDED

#include "Bitstream.h"

struct Inhibition_of_revocable_TSRs_from_balises_in_L23_Data
{
    // TransmissionMedia=RBC
    // This packet is used to inhibit revocable TSRs from balises in level 2 or 3.
    // Packet Number = 64

    uint32_t  Q_DIR;            // # 2
};

typedef struct Inhibition_of_revocable_TSRs_from_balises_in_L23_Data Inhibition_of_revocable_TSRs_from_balises_in_L23_Data;

#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_DATA_BITSIZE 15

/*@
    logic integer BitSize{L}(Inhibition_of_revocable_TSRs_from_balises_in_L23_Data* p) = INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Inhibition_of_revocable_TSRs_from_balises_in_L23_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Inhibition_of_revocable_TSRs_from_balises_in_L23_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Inhibition_of_revocable_TSRs_from_balises_in_L23_Data* p) =
      Invariant(p->Q_DIR);

    predicate ZeroInitialized(Inhibition_of_revocable_TSRs_from_balises_in_L23_Data* p) =
      ZeroInitialized(p->Q_DIR);

    predicate EqualBits(Bitstream* stream, integer pos, Inhibition_of_revocable_TSRs_from_balises_in_L23_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR);


    predicate UpperBitsNotSet(Inhibition_of_revocable_TSRs_from_balises_in_L23_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2);

*/

#endif // INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_DATA_H_INCLUDED

