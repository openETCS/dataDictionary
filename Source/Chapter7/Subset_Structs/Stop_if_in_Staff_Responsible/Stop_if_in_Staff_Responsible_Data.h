
#ifndef STOP_IF_IN_STAFF_RESPONSIBLE_DATA_H_INCLUDED
#define STOP_IF_IN_STAFF_RESPONSIBLE_DATA_H_INCLUDED

#include "Bitstream.h"

struct Stop_if_in_Staff_Responsible_Data
{
    // TransmissionMedia=Balise
    // Information to stop a train in staff responsible.
    // Packet Number = 137

    uint32_t  Q_DIR;            // # 2
    uint32_t  Q_SRSTOP;         // # 1
};

typedef struct Stop_if_in_Staff_Responsible_Data Stop_if_in_Staff_Responsible_Data;

#define STOP_IF_IN_STAFF_RESPONSIBLE_DATA_BITSIZE 16

/*@
    logic integer BitSize{L}(Stop_if_in_Staff_Responsible_Data* p) = STOP_IF_IN_STAFF_RESPONSIBLE_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Stop_if_in_Staff_Responsible_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Stop_if_in_Staff_Responsible_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Stop_if_in_Staff_Responsible_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->Q_SRSTOP);

    predicate ZeroInitialized(Stop_if_in_Staff_Responsible_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->Q_SRSTOP);

    predicate EqualBits(Bitstream* stream, integer pos, Stop_if_in_Staff_Responsible_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_SRSTOP);


    predicate UpperBitsNotSet(Stop_if_in_Staff_Responsible_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->Q_SRSTOP,         1);

*/

#endif // STOP_IF_IN_STAFF_RESPONSIBLE_DATA_H_INCLUDED

