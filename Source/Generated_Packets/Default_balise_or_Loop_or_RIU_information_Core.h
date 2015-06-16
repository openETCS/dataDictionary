
#ifndef DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_H_INCLUDED
#define DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Default_balise_or_Loop_or_RIU_information_Core
{
    // TransmissionMedia=Balise, Loop, RIU
    // Indication to on-board that balise telegram, loop message or RIU information
    // contains default information due to a fault of the trackside equipment.
    // Packet Number = 254

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Default_balise_or_Loop_or_RIU_information_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET;

    return stream;
}

inline bool operator==(const Default_balise_or_Loop_or_RIU_information_Core& a, const Default_balise_or_Loop_or_RIU_information_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);

    return status;
}

inline bool operator!=(const Default_balise_or_Loop_or_RIU_information_Core& a, const Default_balise_or_Loop_or_RIU_information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Default_balise_or_Loop_or_RIU_information_Core Default_balise_or_Loop_or_RIU_information_Core;

#define DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_BITSIZE 15

/*@
    logic integer BitSize{L}(Default_balise_or_Loop_or_RIU_information_Core* p) = DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Default_balise_or_Loop_or_RIU_information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Default_balise_or_Loop_or_RIU_information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Default_balise_or_Loop_or_RIU_information_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET);

    predicate ZeroInitialized(Default_balise_or_Loop_or_RIU_information_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET);

    predicate EqualBits(Bitstream* stream, integer pos, Default_balise_or_Loop_or_RIU_information_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

    predicate UpperBitsNotSet(Default_balise_or_Loop_or_RIU_information_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13);

*/

#endif // DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_H_INCLUDED

