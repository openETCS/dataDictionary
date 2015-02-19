
#ifndef REPOSITIONING_INFORMATION_DATA_H_INCLUDED
#define REPOSITIONING_INFORMATION_DATA_H_INCLUDED

#include "Bitstream.h"

struct Repositioning_Information_Data
{
    // TransmissionMedia=Balise
    // Transmission of the update of the current distance
    // Packet Number = 16

    uint32_t  Q_DIR;            // # 2
    uint32_t  Q_SCALE;          // # 2
    uint16_t  L_SECTION;        // # 15
};

typedef struct Repositioning_Information_Data Repositioning_Information_Data;

#define REPOSITIONING_INFORMATION_DATA_BITSIZE 32

/*@
    logic integer BitSize{L}(Repositioning_Information_Data* p) = REPOSITIONING_INFORMATION_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Repositioning_Information_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Repositioning_Information_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Repositioning_Information_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->L_SECTION);

    predicate ZeroInitialized(Repositioning_Information_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->L_SECTION);

    predicate EqualBits(Bitstream* stream, integer pos, Repositioning_Information_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->L_SECTION);


    predicate UpperBitsNotSet(Repositioning_Information_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->L_SECTION,        15);

*/

#endif // REPOSITIONING_INFORMATION_DATA_H_INCLUDED

