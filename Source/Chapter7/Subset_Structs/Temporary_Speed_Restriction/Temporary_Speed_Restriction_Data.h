
#ifndef TEMPORARY_SPEED_RESTRICTION_DATA_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_DATA_H_INCLUDED

#include "Bitstream.h"

struct Temporary_Speed_Restriction_Data
{
    // TransmissionMedia=Any
    // Transmission of temporary speed restriction.
    // Packet Number = 65

    uint32_t  Q_DIR;            // # 2
    uint32_t  Q_SCALE;          // # 2
    uint8_t   NID_TSR;          // # 8
    uint16_t  D_TSR;            // # 15
    uint16_t  L_TSR;            // # 15
    uint32_t  Q_FRONT;          // # 1
    uint8_t   V_TSR;            // # 7
};

typedef struct Temporary_Speed_Restriction_Data Temporary_Speed_Restriction_Data;

#define TEMPORARY_SPEED_RESTRICTION_DATA_BITSIZE 63

/*@
    logic integer BitSize{L}(Temporary_Speed_Restriction_Data* p) = TEMPORARY_SPEED_RESTRICTION_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Temporary_Speed_Restriction_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Temporary_Speed_Restriction_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Temporary_Speed_Restriction_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->NID_TSR)           &&
      Invariant(p->D_TSR)             &&
      Invariant(p->L_TSR)             &&
      Invariant(p->Q_FRONT)           &&
      Invariant(p->V_TSR);

    predicate ZeroInitialized(Temporary_Speed_Restriction_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->NID_TSR)           &&
      ZeroInitialized(p->D_TSR)             &&
      ZeroInitialized(p->L_TSR)             &&
      ZeroInitialized(p->Q_FRONT)           &&
      ZeroInitialized(p->V_TSR);

    predicate EqualBits(Bitstream* stream, integer pos, Temporary_Speed_Restriction_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 25,  p->NID_TSR)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_TSR)             &&
      EqualBits(stream, pos + 40,  pos + 55,  p->L_TSR)             &&
      EqualBits(stream, pos + 55,  pos + 56,  p->Q_FRONT)           &&
      EqualBits(stream, pos + 56,  pos + 63,  p->V_TSR);


    predicate UpperBitsNotSet(Temporary_Speed_Restriction_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->NID_TSR,          8)   &&
      UpperBitsNotSet(p->D_TSR,            15)  &&
      UpperBitsNotSet(p->L_TSR,            15)  &&
      UpperBitsNotSet(p->Q_FRONT,          1)   &&
      UpperBitsNotSet(p->V_TSR,            7);

*/

#endif // TEMPORARY_SPEED_RESTRICTION_DATA_H_INCLUDED

