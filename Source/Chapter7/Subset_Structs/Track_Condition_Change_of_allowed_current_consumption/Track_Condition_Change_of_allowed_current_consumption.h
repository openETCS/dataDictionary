
#ifndef TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_H_INCLUDED
#define TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_H_INCLUDED

#include "Bitstream.h"

struct Track_Condition_Change_of_allowed_current_consumption
{
    // TransmissionMedia=Any
    // The packet gives information about change of the allowed current consumption.
    // Packet Number = 40

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_CURRENT;        // # 15
    uint64_t  M_CURRENT;        // # 10
};

typedef struct Track_Condition_Change_of_allowed_current_consumption Track_Condition_Change_of_allowed_current_consumption;

#define TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_BITSIZE 50

/*@
    logic integer BitSize{L}(Track_Condition_Change_of_allowed_current_consumption* p) = TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Change_of_allowed_current_consumption* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Change_of_allowed_current_consumption* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Change_of_allowed_current_consumption* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_CURRENT)         &&
      Invariant(p->M_CURRENT);

    predicate ZeroInitialized(Track_Condition_Change_of_allowed_current_consumption* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_CURRENT)         &&
      ZeroInitialized(p->M_CURRENT);

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Change_of_allowed_current_consumption* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_CURRENT)         &&
      EqualBits(stream, pos + 40,  pos + 50,  p->M_CURRENT);


    predicate UpperBitsNotSet(Track_Condition_Change_of_allowed_current_consumption* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_CURRENT,        15)  &&
      UpperBitsNotSet(p->M_CURRENT,        10);

*/

#endif // TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_H_INCLUDED

