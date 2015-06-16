
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

#define STOP_IF_IN_STAFF_RESPONSIBLE_CORE_BITSIZE 16

/*@
    logic integer BitSize{L}(Stop_if_in_Staff_Responsible_Core* p) = STOP_IF_IN_STAFF_RESPONSIBLE_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Stop_if_in_Staff_Responsible_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Stop_if_in_Staff_Responsible_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Stop_if_in_Staff_Responsible_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SRSTOP);

    predicate ZeroInitialized(Stop_if_in_Staff_Responsible_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SRSTOP);

    predicate EqualBits(Bitstream* stream, integer pos, Stop_if_in_Staff_Responsible_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_SRSTOP);

    predicate UpperBitsNotSet(Stop_if_in_Staff_Responsible_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SRSTOP,         1);

*/

#endif // STOP_IF_IN_STAFF_RESPONSIBLE_CORE_H_INCLUDED

