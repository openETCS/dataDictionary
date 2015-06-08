
#ifndef REVERSING_SUPERVISION_INFORMATION_H_INCLUDED
#define REVERSING_SUPERVISION_INFORMATION_H_INCLUDED

#include "Bitstream.h"

struct Reversing_supervision_information
{
    // TransmissionMedia=Any
    // Used to send supervision parameters (distance to run, speed) of reversing
    // area to the on-board       
    // Packet Number = 139

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_REVERSE;        // # 15
    uint8_t   V_REVERSE;        // # 7
};

typedef struct Reversing_supervision_information Reversing_supervision_information;

#define REVERSING_SUPERVISION_INFORMATION_BITSIZE 39

/*@
    logic integer BitSize{L}(Reversing_supervision_information* p) = REVERSING_SUPERVISION_INFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(Reversing_supervision_information* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Reversing_supervision_information* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Reversing_supervision_information* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_REVERSE)         &&
      Invariant(p->V_REVERSE);

    predicate ZeroInitialized(Reversing_supervision_information* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_REVERSE)         &&
      ZeroInitialized(p->V_REVERSE);

    predicate EqualBits(Bitstream* stream, integer pos, Reversing_supervision_information* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_REVERSE)         &&
      EqualBits(stream, pos + 32,  pos + 39,  p->V_REVERSE);


    predicate UpperBitsNotSet(Reversing_supervision_information* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_REVERSE,        15)  &&
      UpperBitsNotSet(p->V_REVERSE,        7);

*/

#endif // REVERSING_SUPERVISION_INFORMATION_H_INCLUDED

