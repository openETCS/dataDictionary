
#ifndef DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_H_INCLUDED
#define DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_H_INCLUDED

#include "Bitstream.h"

struct Default_balise_or_Loop_or_RIU_information
{
    // TransmissionMedia=Balise, Loop, RIU
    // Indication to on-board that balise telegram, loop message or RIU information
    // contains default information due to a fault of the trackside equipment.
    // Packet Number = 254

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
};

typedef struct Default_balise_or_Loop_or_RIU_information Default_balise_or_Loop_or_RIU_information;

#define DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_BITSIZE 15

/*@
    logic integer BitSize{L}(Default_balise_or_Loop_or_RIU_information* p) = DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(Default_balise_or_Loop_or_RIU_information* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Default_balise_or_Loop_or_RIU_information* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Default_balise_or_Loop_or_RIU_information* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(Default_balise_or_Loop_or_RIU_information* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, Default_balise_or_Loop_or_RIU_information* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);


    predicate UpperBitsNotSet(Default_balise_or_Loop_or_RIU_information* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

#endif // DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_H_INCLUDED

