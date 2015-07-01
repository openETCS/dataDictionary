
#ifndef MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_H_INCLUDED
#define MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Movement_Authority_Request_Parameters_Core
{
    // TransmissionMedia=RBC
    // This packet is intended to give parameters telling when and how
    // often the train has to ask for a movement authority. 
    // Packet Number = 57

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint8_t   T_MAR;            // # 8
    uint16_t  T_TIMEOUTRQST;    // # 10
    uint8_t   T_CYCRQST;        // # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Movement_Authority_Request_Parameters_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.T_MAR << ','
       << +p.T_TIMEOUTRQST << ','
       << +p.T_CYCRQST;

    return stream;
}

inline bool operator==(const Movement_Authority_Request_Parameters_Core& a, const Movement_Authority_Request_Parameters_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.T_MAR == b.T_MAR);
    status = status && (a.T_TIMEOUTRQST == b.T_TIMEOUTRQST);
    status = status && (a.T_CYCRQST == b.T_CYCRQST);

    return status;
}

inline bool operator!=(const Movement_Authority_Request_Parameters_Core& a, const Movement_Authority_Request_Parameters_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Movement_Authority_Request_Parameters_Core Movement_Authority_Request_Parameters_Core;

#define MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_BITSIZE 41

/*@
    logic integer BitSize{L}(Movement_Authority_Request_Parameters_Core* p) = MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Movement_Authority_Request_Parameters_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Movement_Authority_Request_Parameters_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Movement_Authority_Request_Parameters_Core* p) = \true;

    predicate ZeroInitialized(Movement_Authority_Request_Parameters_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Movement_Authority_Request_Parameters_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 23,  p->T_MAR)             &&
      EqualBits(stream, pos + 23,  pos + 33,  p->T_TIMEOUTRQST)     &&
      EqualBits(stream, pos + 33,  pos + 41,  p->T_CYCRQST);

    predicate UpperBitsNotSet(Movement_Authority_Request_Parameters_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->T_MAR,            8)   &&
      UpperBitsNotSet(p->T_TIMEOUTRQST,    10)  &&
      UpperBitsNotSet(p->T_CYCRQST,        8);

*/

#endif // MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_CORE_H_INCLUDED

