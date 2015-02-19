
#ifndef DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_H_INCLUDED
#define DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_H_INCLUDED

#include "Bitstream.h"

struct Default_balise_or_Loop_or_RIU_information_Data
{
    // TransmissionMedia=Balise, Loop, RIU
    // Indication to on-board that balise telegram, loop message or RIU information contains default information due to a fault of the trackside equipment.
    // Packet Number = 254

    uint32_t  Q_DIR;            // # 2
};

typedef struct Default_balise_or_Loop_or_RIU_information_Data Default_balise_or_Loop_or_RIU_information_Data;

#define DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_BITSIZE 15

/*@
    logic integer BitSize{L}(Default_balise_or_Loop_or_RIU_information_Data* p) = DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Default_balise_or_Loop_or_RIU_information_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Default_balise_or_Loop_or_RIU_information_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Default_balise_or_Loop_or_RIU_information_Data* p) =
      Invariant(p->Q_DIR);

    predicate ZeroInitialized(Default_balise_or_Loop_or_RIU_information_Data* p) =
      ZeroInitialized(p->Q_DIR);

    predicate EqualBits(Bitstream* stream, integer pos, Default_balise_or_Loop_or_RIU_information_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR);


    predicate UpperBitsNotSet(Default_balise_or_Loop_or_RIU_information_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2);

*/

#endif // DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_DATA_H_INCLUDED

