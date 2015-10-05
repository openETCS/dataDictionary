
#ifndef INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_H_INCLUDED
#define INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_H_INCLUDED

#include "Bitstream.h"

struct Inhibition_of_balise_group_message_consistency_reaction
{
    // TransmissionMedia=Balise
    // Indication to on-board that the balise group message consistency reaction (service
    // brake command) can be inhibited for this balise group message only,
    // in case one or more balise telegram(s) of the group is/are
    // missed or is/are detected but not decoded.    
    // Packet Number = 145

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
};

typedef struct Inhibition_of_balise_group_message_consistency_reaction Inhibition_of_balise_group_message_consistency_reaction;

#define INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_BITSIZE 15

/*@
    logic integer BitSize{L}(Inhibition_of_balise_group_message_consistency_reaction* p) = INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_BITSIZE;

    logic integer MaxBitSize{L}(Inhibition_of_balise_group_message_consistency_reaction* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Inhibition_of_balise_group_message_consistency_reaction* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Inhibition_of_balise_group_message_consistency_reaction* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(Inhibition_of_balise_group_message_consistency_reaction* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, Inhibition_of_balise_group_message_consistency_reaction* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);


    predicate UpperBitsNotSet(Inhibition_of_balise_group_message_consistency_reaction* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

#endif // INHIBITION_OF_BALISE_GROUP_MESSAGE_CONSISTENCY_REACTION_H_INCLUDED

