
#ifndef INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_DATA_H_INCLUDED
#define INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_DATA_H_INCLUDED

#include "Bitstream.h"

struct Inhibition_of_balise_group_message_consistency_reaction_Data
{
    // TransmissionMedia=Balise
    // Indication to on-board that the balise group message consistency reaction (service brake command) can be inhibited for this balise group message only, in case one or more balise telegram(s) of the group is/are missed or is/are detected but not decoded.
    // Packet Number = 145

    uint32_t  Q_DIR;            // # 2
};

typedef struct Inhibition_of_balise_group_message_consistency_reaction_Data Inhibition_of_balise_group_message_consistency_reaction_Data;

#define INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_DATA_BITSIZE 15

/*@
    logic integer BitSize{L}(Inhibition_of_balise_group_message_consistency_reaction_Data* p) = INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Inhibition_of_balise_group_message_consistency_reaction_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Inhibition_of_balise_group_message_consistency_reaction_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Inhibition_of_balise_group_message_consistency_reaction_Data* p) =
      Invariant(p->Q_DIR);

    predicate ZeroInitialized(Inhibition_of_balise_group_message_consistency_reaction_Data* p) =
      ZeroInitialized(p->Q_DIR);

    predicate EqualBits(Bitstream* stream, integer pos, Inhibition_of_balise_group_message_consistency_reaction_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR);


    predicate UpperBitsNotSet(Inhibition_of_balise_group_message_consistency_reaction_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2);

*/

#endif // INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_DATA_H_INCLUDED

