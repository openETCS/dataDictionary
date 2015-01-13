
#ifndef MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_H_INCLUDED
#define MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_H_INCLUDED

#include "Bitstream.h"

struct Movement_Authority_Request_Parameters
{
    // TransmissionMedia=RBC
    // This packet is intended to give parameters telling when and how often the train has to ask for a movement authority.
    // Packet Number = 57

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  T_MAR;            // # 8
    uint64_t  T_TIMEOUTRQST;    // # 10
    uint64_t  T_CYCRQST;        // # 8
};

typedef struct Movement_Authority_Request_Parameters Movement_Authority_Request_Parameters;

#define MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_BITSIZE 49

/*@
    logic integer BitSize{L}(Movement_Authority_Request_Parameters* p) = MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_BITSIZE;

    logic integer MaxBitSize{L}(Movement_Authority_Request_Parameters* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Movement_Authority_Request_Parameters* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Movement_Authority_Request_Parameters* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->T_MAR)             &&
      Invariant(p->T_TIMEOUTRQST)     &&
      Invariant(p->T_CYCRQST);

    predicate ZeroInitialized(Movement_Authority_Request_Parameters* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->T_MAR)             &&
      ZeroInitialized(p->T_TIMEOUTRQST)     &&
      ZeroInitialized(p->T_CYCRQST);

    predicate EqualBits(Bitstream* stream, integer pos, Movement_Authority_Request_Parameters* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 31,  p->T_MAR)             &&
      EqualBits(stream, pos + 31,  pos + 41,  p->T_TIMEOUTRQST)     &&
      EqualBits(stream, pos + 41,  pos + 49,  p->T_CYCRQST);


    predicate UpperBitsNotSet(Movement_Authority_Request_Parameters* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->T_MAR,            8)   &&
      UpperBitsNotSet(p->T_TIMEOUTRQST,    10)  &&
      UpperBitsNotSet(p->T_CYCRQST,        8);

*/

#endif // MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_H_INCLUDED

