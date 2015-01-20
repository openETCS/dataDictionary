
#ifndef ADHESION_FACTOR_H_INCLUDED
#define ADHESION_FACTOR_H_INCLUDED

#include "TrackToTrain_Header.h"
#include "Bitstream.h"

struct Adhesion_Factor
{
    // TransmissionMedia=Any
    // This packet is used when the trackside requests a change of the adhesion factor to be used in the brake model.
    // Packet Number = 71

    struct TrackToTrain_Header Header;
    struct Adhesion_Factor_Data {
    	uint64_t  Q_SCALE;          // # 2
    	uint64_t  D_ADHESION;       // # 15
    	uint64_t  L_ADHESION;       // # 15
    	uint64_t  M_ADHESION;       // # 1
    } Data;
};

typedef struct Adhesion_Factor Adhesion_Factor;

#define ADHESION_FACTOR_BITSIZE 56

/*@
    logic integer BitSize{L}(Adhesion_Factor* p) = ADHESION_FACTOR_BITSIZE;

    logic integer MaxBitSize{L}(Adhesion_Factor* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Adhesion_Factor* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Adhesion_Factor* p) =
      Invariant(p->Header.NID_PACKET)        &&
      Invariant(p->Header.Q_DIR)             &&
      Invariant(p->Header.L_PACKET)          &&
      Invariant(p->Data.Q_SCALE)           &&
      Invariant(p->Data.D_ADHESION)        &&
      Invariant(p->Data.L_ADHESION)        &&
      Invariant(p->Data.M_ADHESION);

    predicate ZeroInitialized(Adhesion_Factor* p) =
      ZeroInitialized(p->Header.NID_PACKET)        &&
      ZeroInitialized(p->Header.Q_DIR)             &&
      ZeroInitialized(p->Header.L_PACKET)          &&
      ZeroInitialized(p->Data.Q_SCALE)           &&
      ZeroInitialized(p->Data.D_ADHESION)        &&
      ZeroInitialized(p->Data.L_ADHESION)        &&
      ZeroInitialized(p->Data.M_ADHESION);

    predicate EqualBits(Bitstream* stream, integer pos, Adhesion_Factor* p) =
      EqualBits(stream, pos,       pos + 8,   p->Header.NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Header.Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->Header.L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Data.Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->Data.D_ADHESION)        &&
      EqualBits(stream, pos + 40,  pos + 55,  p->Data.L_ADHESION)        &&
      EqualBits(stream, pos + 55,  pos + 56,  p->Data.M_ADHESION);


    predicate UpperBitsNotSet(Adhesion_Factor* p) =
      UpperBitsNotSet(p->Header.NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Header.Q_DIR,            2)   &&
      UpperBitsNotSet(p->Header.L_PACKET,         13)  &&
      UpperBitsNotSet(p->Data.Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Data.D_ADHESION,       15)  &&
      UpperBitsNotSet(p->Data.L_ADHESION,       15)  &&
      UpperBitsNotSet(p->Data.M_ADHESION,       1);

*/

#endif // ADHESION_FACTOR_H_INCLUDED

