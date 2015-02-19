
#ifndef SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_DATA_H_INCLUDED
#define SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_DATA_H_INCLUDED

#include "Bitstream.h"

struct Session_Management_with_neighbouring_Radio_Infill_Unit_Data
{
    // TransmissionMedia=RIU
    // Packet to give the identity and telephone number of the neighbouring Radio Infill Unit with which a session shall be established or terminated.
    // Packet Number = 143

    uint32_t  Q_DIR;            // # 2
    uint32_t  Q_RIU;            // # 1
    uint16_t  NID_C;            // # 10
    uint16_t  NID_RIU;          // # 14
    uint64_t  NID_RADIO;        // # 64
};

typedef struct Session_Management_with_neighbouring_Radio_Infill_Unit_Data Session_Management_with_neighbouring_Radio_Infill_Unit_Data;

#define SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_DATA_BITSIZE 104

/*@
    logic integer BitSize{L}(Session_Management_with_neighbouring_Radio_Infill_Unit_Data* p) = SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Session_Management_with_neighbouring_Radio_Infill_Unit_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Session_Management_with_neighbouring_Radio_Infill_Unit_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Session_Management_with_neighbouring_Radio_Infill_Unit_Data* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->Q_RIU)             &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_RIU)           &&
      Invariant(p->NID_RADIO);

    predicate ZeroInitialized(Session_Management_with_neighbouring_Radio_Infill_Unit_Data* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->Q_RIU)             &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_RIU)           &&
      ZeroInitialized(p->NID_RADIO);

    predicate EqualBits(Bitstream* stream, integer pos, Session_Management_with_neighbouring_Radio_Infill_Unit_Data* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 15,  pos + 16,  p->Q_RIU)             &&
      EqualBits(stream, pos + 16,  pos + 26,  p->NID_C)             &&
      EqualBits(stream, pos + 26,  pos + 40,  p->NID_RIU)           &&
      EqualBits(stream, pos + 40,  pos + 104, p->NID_RADIO);


    predicate UpperBitsNotSet(Session_Management_with_neighbouring_Radio_Infill_Unit_Data* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->Q_RIU,            1)   &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_RIU,          14)  &&
      UpperBitsNotSet(p->NID_RADIO,        64);

*/

#endif // SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_DATA_H_INCLUDED

