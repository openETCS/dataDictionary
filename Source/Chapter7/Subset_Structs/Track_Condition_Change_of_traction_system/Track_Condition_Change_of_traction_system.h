
#ifndef TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_H_INCLUDED
#define TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_H_INCLUDED

#include "Bitstream.h"

struct Track_Condition_Change_of_traction_system
{
    // TransmissionMedia=Any
    // The packet gives information about change of the traction system.
    // Packet Number = 39

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_TRACTION;       // # 15
    uint64_t  M_VOLTAGE;        // # 4
    uint64_t  NID_CTRACTION;    // # 10
};

typedef struct Track_Condition_Change_of_traction_system Track_Condition_Change_of_traction_system;

#define TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_BITSIZE 54

/*@
    logic integer BitSize{L}(Track_Condition_Change_of_traction_system* p) = TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Change_of_traction_system* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Change_of_traction_system* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Change_of_traction_system* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_TRACTION)        &&
      Invariant(p->M_VOLTAGE)         &&
      Invariant(p->NID_CTRACTION);

    predicate ZeroInitialized(Track_Condition_Change_of_traction_system* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_TRACTION)        &&
      ZeroInitialized(p->M_VOLTAGE)         &&
      ZeroInitialized(p->NID_CTRACTION);

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Change_of_traction_system* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_TRACTION)        &&
      EqualBits(stream, pos + 40,  pos + 44,  p->M_VOLTAGE)         &&
      EqualBits(stream, pos + 44,  pos + 54,  p->NID_CTRACTION);


    predicate UpperBitsNotSet(Track_Condition_Change_of_traction_system* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_TRACTION,       15)  &&
      UpperBitsNotSet(p->M_VOLTAGE,        4)   &&
      UpperBitsNotSet(p->NID_CTRACTION,    10);

*/

#endif // TRACK_CONDITION_CHANGE_OF_TRACTION_SYSTEM_H_INCLUDED

