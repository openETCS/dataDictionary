
#ifndef RADIO_INFILL_AREA_INFORMATION_H_INCLUDED
#define RADIO_INFILL_AREA_INFORMATION_H_INCLUDED

#include "Bitstream.h"

struct Radio_infill_area_information
{
    // TransmissionMedia=Balise
    // Packet Number = 133

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint32_t  Q_RIU;            // # 1
    uint16_t  NID_C;            // # 10
    uint16_t  NID_RIU;          // # 14
    uint64_t  NID_RADIO;        // # 64
    uint16_t  D_INFILL;         // # 15
    uint16_t  NID_BG;           // # 14
};

typedef struct Radio_infill_area_information Radio_infill_area_information;

#define RADIO_INFILL_AREA_INFORMATION_BITSIZE 135

/*@
    logic integer BitSize{L}(Radio_infill_area_information* p) = RADIO_INFILL_AREA_INFORMATION_BITSIZE;

    logic integer MaxBitSize{L}(Radio_infill_area_information* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Radio_infill_area_information* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Radio_infill_area_information* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_RIU)             &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_RIU)           &&
      Invariant(p->NID_RADIO)         &&
      Invariant(p->D_INFILL)          &&
      Invariant(p->NID_BG);

    predicate ZeroInitialized(Radio_infill_area_information* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_RIU)             &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_RIU)           &&
      ZeroInitialized(p->NID_RADIO)         &&
      ZeroInitialized(p->D_INFILL)          &&
      ZeroInitialized(p->NID_BG);

    predicate EqualBits(Bitstream* stream, integer pos, Radio_infill_area_information* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 18,  p->Q_RIU)             &&
      EqualBits(stream, pos + 18,  pos + 28,  p->NID_C)             &&
      EqualBits(stream, pos + 28,  pos + 42,  p->NID_RIU)           &&
      EqualBits(stream, pos + 42,  pos + 106, p->NID_RADIO)         &&
      EqualBits(stream, pos + 106, pos + 121, p->D_INFILL)          &&
      EqualBits(stream, pos + 121, pos + 135, p->NID_BG);


    predicate UpperBitsNotSet(Radio_infill_area_information* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_RIU,            1)   &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_RIU,          14)  &&
      UpperBitsNotSet(p->NID_RADIO,        64)  &&
      UpperBitsNotSet(p->D_INFILL,         15)  &&
      UpperBitsNotSet(p->NID_BG,           14);

*/

#endif // RADIO_INFILL_AREA_INFORMATION_H_INCLUDED

