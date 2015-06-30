
#ifndef STOP_IF_IN_STAFF_RESPONSIBLE_CORE_H_INCLUDED
#define STOP_IF_IN_STAFF_RESPONSIBLE_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Stop_if_in_Staff_Responsible_Core
{
    // TransmissionMedia=Balise
    // Information to stop a train in staff responsible.   
    // Packet Number = 137

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SRSTOP;         // # 1
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Stop_if_in_Staff_Responsible_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SRSTOP;

    return stream;
}

inline bool operator==(const Stop_if_in_Staff_Responsible_Core& a, const Stop_if_in_Staff_Responsible_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SRSTOP == b.Q_SRSTOP);

    return status;
}

inline bool operator!=(const Stop_if_in_Staff_Responsible_Core& a, const Stop_if_in_Staff_Responsible_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Stop_if_in_Staff_Responsible_Core Stop_if_in_Staff_Responsible_Core;

#define STOP_IF_IN_STAFF_RESPONSIBLE_CORE_BITSIZE 3882

/*@
    logic integer BitSize{L}(Stop_if_in_Staff_Responsible_Core* p) = STOP_IF_IN_STAFF_RESPONSIBLE_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Stop_if_in_Staff_Responsible_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Stop_if_in_Staff_Responsible_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Stop_if_in_Staff_Responsible_Core* p) = \true;

    predicate ZeroInitialized(Stop_if_in_Staff_Responsible_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Stop_if_in_Staff_Responsible_Core* p) = \true;

    predicate UpperBitsNotSet(Stop_if_in_Staff_Responsible_Core* p) = \true;

*/

#endif // STOP_IF_IN_STAFF_RESPONSIBLE_CORE_H_INCLUDED

