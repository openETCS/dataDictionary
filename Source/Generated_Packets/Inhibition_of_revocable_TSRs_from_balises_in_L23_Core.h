
#ifndef INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_CORE_H_INCLUDED
#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Inhibition_of_revocable_TSRs_from_balises_in_L23_Core
{
    // TransmissionMedia=RBC
    // This packet is used to inhibit revocable TSRs from balises in
    // level 2 or 3.       
    // Packet Number = 64

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET;

    return stream;
}

inline bool operator==(const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& a, const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);

    return status;
}

inline bool operator!=(const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& a, const Inhibition_of_revocable_TSRs_from_balises_in_L23_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Inhibition_of_revocable_TSRs_from_balises_in_L23_Core Inhibition_of_revocable_TSRs_from_balises_in_L23_Core;

#define INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_CORE_BITSIZE 2232

/*@
    logic integer BitSize{L}(Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) = INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) = \true;

    predicate ZeroInitialized(Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) = \true;

    predicate UpperBitsNotSet(Inhibition_of_revocable_TSRs_from_balises_in_L23_Core* p) = \true;

*/

#endif // INHIBITION_OF_REVOCABLE_TSRS_FROM_BALISES_IN_L23_CORE_H_INCLUDED

