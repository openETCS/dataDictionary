
#ifndef SESSION_MANAGEMENT_CORE_H_INCLUDED
#define SESSION_MANAGEMENT_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Session_Management_Core
{
    // TransmissionMedia=Balise, RBC
    // Packet to give the identity and telephone number of the RBC
    // with which a session shall be established or terminated.  
    // Packet Number = 42

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_RBC;            // # 1
    uint16_t  NID_C;            // # 10
    uint16_t  NID_RBC;          // # 14
    uint64_t  NID_RADIO;        // # 64
    uint32_t  Q_SLEEPSESSION;   // # 1
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Session_Management_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_RBC << ','
       << +p.NID_C << ','
       << +p.NID_RBC << ','
       << +p.NID_RADIO << ','
       << +p.Q_SLEEPSESSION;

    return stream;
}

inline bool operator==(const Session_Management_Core& a, const Session_Management_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_RBC == b.Q_RBC);
    status = status && (a.NID_C == b.NID_C);
    status = status && (a.NID_RBC == b.NID_RBC);
    status = status && (a.NID_RADIO == b.NID_RADIO);
    status = status && (a.Q_SLEEPSESSION == b.Q_SLEEPSESSION);

    return status;
}

inline bool operator!=(const Session_Management_Core& a, const Session_Management_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Session_Management_Core Session_Management_Core;

#define SESSION_MANAGEMENT_CORE_BITSIZE 1615

/*@
    logic integer BitSize{L}(Session_Management_Core* p) = SESSION_MANAGEMENT_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Session_Management_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Session_Management_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Session_Management_Core* p) = \true;

    predicate ZeroInitialized(Session_Management_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Session_Management_Core* p) = \true;

    predicate UpperBitsNotSet(Session_Management_Core* p) = \true;

*/

#endif // SESSION_MANAGEMENT_CORE_H_INCLUDED

