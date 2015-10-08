
#ifndef TEMPORARY_SPEED_RESTRICTION_REVOCATION_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_REVOCATION_H_INCLUDED

#include "Bitstream.h"

struct Temporary_Speed_Restriction_Revocation
{
    // TransmissionMedia=Any
    // Transmission of temporary speed restriction revocation.     
    // Packet Number = 66

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint8_t   NID_TSR;          // # 8
};

typedef struct Temporary_Speed_Restriction_Revocation Temporary_Speed_Restriction_Revocation;

#define TEMPORARY_SPEED_RESTRICTION_REVOCATION_BITSIZE 23

/*@
    logic integer BitSize{L}(Temporary_Speed_Restriction_Revocation* p) = TEMPORARY_SPEED_RESTRICTION_REVOCATION_BITSIZE;

    logic integer MaxBitSize{L}(Temporary_Speed_Restriction_Revocation* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Temporary_Speed_Restriction_Revocation* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Temporary_Speed_Restriction_Revocation* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_TSR);

    predicate ZeroInitialized(Temporary_Speed_Restriction_Revocation* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_TSR);

    predicate EqualBits(Bitstream* stream, integer pos, Temporary_Speed_Restriction_Revocation* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 23,  p->NID_TSR);


    predicate UpperBitsNotSet(Temporary_Speed_Restriction_Revocation* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_TSR,          8);

*/

#endif // TEMPORARY_SPEED_RESTRICTION_REVOCATION_H_INCLUDED

