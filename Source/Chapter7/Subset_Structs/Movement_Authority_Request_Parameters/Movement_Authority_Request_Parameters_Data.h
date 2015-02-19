
#ifndef MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_DATA_H_INCLUDED
#define MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_DATA_H_INCLUDED

#include "Bitstream.h"

struct Movement_Authority_Request_Parameters_Data
{
    // TransmissionMedia=RBC
    // This packet is intended to give parameters telling when and how often the train has to ask for a movement authority.
    // Packet Number = 57

    uint32_t  Q_DIR;            // # 2
    uint8_t   T_MAR;            // # 8
    uint16_t  T_TIMEOUTRQST;    // # 10
    uint8_t   T_CYCRQST;        // # 8
};

typedef struct Movement_Authority_Request_Parameters_Data Movement_Authority_Request_Parameters_Data;

#define MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_DATA_BITSIZE 41

/*@
    logic integer BitSize{L}(Movement_Authority_Request_Parameters_Data* p) = MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Movement_Authority_Request_Parameters_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Movement_Authority_Request_Parameters_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Movement_Authority_Request_Parameters_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->T_MAR)             &&
      Invariant(p->T_TIMEOUTRQST)     &&
      Invariant(p->T_CYCRQST);

    predicate ZeroInitialized(Movement_Authority_Request_Parameters_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->T_MAR)             &&
      ZeroInitialized(p->T_TIMEOUTRQST)     &&
      ZeroInitialized(p->T_CYCRQST);

    predicate EqualBits(Bitstream* stream, integer pos, Movement_Authority_Request_Parameters_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 23,  p->T_MAR)             &&
      EqualBits(stream, pos + 23,  pos + 33,  p->T_TIMEOUTRQST)     &&
      EqualBits(stream, pos + 33,  pos + 41,  p->T_CYCRQST);


    predicate UpperBitsNotSet(Movement_Authority_Request_Parameters_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->T_MAR,            8)   &&
      UpperBitsNotSet(p->T_TIMEOUTRQST,    10)  &&
      UpperBitsNotSet(p->T_CYCRQST,        8);

*/

#endif // MOVEMENT_AUTHORITY_REQUEST_PARAMETERS_DATA_H_INCLUDED

