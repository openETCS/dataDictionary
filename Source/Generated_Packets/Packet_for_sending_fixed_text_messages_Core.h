
#ifndef PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_CORE_H_INCLUDED
#define PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_CORE_H_INCLUDED

#include "Bitstream.h"

struct Packet_for_sending_fixed_text_messages_Core
{
    // TransmissionMedia=Balise, RBC
    // Packet Number = 76

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint32_t  Q_TEXTCLASS;      // # 2
    uint32_t  Q_TEXTDISPLAY;    // # 1
    uint16_t  D_TEXTDISPLAY;    // # 15
    uint8_t   M_MODETEXTDISPLAY0;// # 4
    uint8_t   M_LEVELTEXTDISPLAY0;// # 3
    uint8_t   NID_NTC0;         // # 8
    uint16_t  L_TEXTDISPLAY;    // # 15
    uint16_t  T_TEXTDISPLAY;    // # 10
    uint8_t   M_MODETEXTDISPLAY1;// # 4
    uint8_t   M_LEVELTEXTDISPLAY1;// # 3
    uint8_t   NID_NTC1;         // # 8
    uint32_t  Q_TEXTCONFIRM;    // # 2
    uint32_t  Q_CONFTEXTDISPLAY;// # 1
    uint32_t  Q_TEXTREPORT;     // # 1
    uint8_t   NID_TEXTMESSAGE;  // # 8
    uint16_t  NID_C;            // # 10
    uint16_t  NID_RBC;          // # 14
    uint32_t  Q_TEXT;           // # 8
};

#ifdef __cplusplus

inline bool operator==(const Packet_for_sending_fixed_text_messages_Core& a, const Packet_for_sending_fixed_text_messages_Core& b)
{
    return
        (a.Q_DIR == b.Q_DIR) &&
        (a.L_PACKET == b.L_PACKET) &&
        (a.Q_SCALE == b.Q_SCALE) &&
        (a.Q_TEXTCLASS == b.Q_TEXTCLASS) &&
        (a.Q_TEXTDISPLAY == b.Q_TEXTDISPLAY) &&
        (a.D_TEXTDISPLAY == b.D_TEXTDISPLAY) &&
        (a.M_MODETEXTDISPLAY0 == b.M_MODETEXTDISPLAY0) &&
        (a.M_LEVELTEXTDISPLAY0 == b.M_LEVELTEXTDISPLAY0) &&
        (a.NID_NTC0 == b.NID_NTC0) &&
        (a.L_TEXTDISPLAY == b.L_TEXTDISPLAY) &&
        (a.T_TEXTDISPLAY == b.T_TEXTDISPLAY) &&
        (a.M_MODETEXTDISPLAY1 == b.M_MODETEXTDISPLAY1) &&
        (a.M_LEVELTEXTDISPLAY1 == b.M_LEVELTEXTDISPLAY1) &&
        (a.NID_NTC1 == b.NID_NTC1) &&
        (a.Q_TEXTCONFIRM == b.Q_TEXTCONFIRM) &&
        (a.Q_CONFTEXTDISPLAY == b.Q_CONFTEXTDISPLAY) &&
        (a.Q_TEXTREPORT == b.Q_TEXTREPORT) &&
        (a.NID_TEXTMESSAGE == b.NID_TEXTMESSAGE) &&
        (a.NID_C == b.NID_C) &&
        (a.NID_RBC == b.NID_RBC) &&
        (a.Q_TEXT == b.Q_TEXT);
}

inline bool operator!=(const Packet_for_sending_fixed_text_messages_Core& a, const Packet_for_sending_fixed_text_messages_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Packet_for_sending_fixed_text_messages_Core Packet_for_sending_fixed_text_messages_Core;

#define PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_CORE_BITSIZE 134

/*@
    logic integer BitSize{L}(Packet_for_sending_fixed_text_messages_Core* p) = PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Packet_for_sending_fixed_text_messages_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Packet_for_sending_fixed_text_messages_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Packet_for_sending_fixed_text_messages_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_TEXTCLASS)       &&
      Invariant(p->Q_TEXTDISPLAY)     &&
      Invariant(p->D_TEXTDISPLAY)     &&
      Invariant(p->M_MODETEXTDISPLAY0) &&
      Invariant(p->M_LEVELTEXTDISPLAY0) &&
      Invariant(p->L_TEXTDISPLAY)     &&
      Invariant(p->T_TEXTDISPLAY)     &&
      Invariant(p->M_MODETEXTDISPLAY1) &&
      Invariant(p->M_LEVELTEXTDISPLAY1) &&
      Invariant(p->Q_TEXTCONFIRM)     &&
      Invariant(p->Q_TEXT);

    predicate ZeroInitialized(Packet_for_sending_fixed_text_messages_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_TEXTCLASS)       &&
      ZeroInitialized(p->Q_TEXTDISPLAY)     &&
      ZeroInitialized(p->D_TEXTDISPLAY)     &&
      ZeroInitialized(p->M_MODETEXTDISPLAY0) &&
      ZeroInitialized(p->M_LEVELTEXTDISPLAY0) &&
      ZeroInitialized(p->L_TEXTDISPLAY)     &&
      ZeroInitialized(p->T_TEXTDISPLAY)     &&
      ZeroInitialized(p->M_MODETEXTDISPLAY1) &&
      ZeroInitialized(p->M_LEVELTEXTDISPLAY1) &&
      ZeroInitialized(p->Q_TEXTCONFIRM)     &&
      ZeroInitialized(p->Q_TEXT);

    predicate EqualBits(Bitstream* stream, integer pos, Packet_for_sending_fixed_text_messages_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 19,  p->Q_TEXTCLASS)       &&
      EqualBits(stream, pos + 19,  pos + 20,  p->Q_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 20,  pos + 35,  p->D_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 35,  pos + 39,  p->M_MODETEXTDISPLAY0) &&
      EqualBits(stream, pos + 39,  pos + 42,  p->M_LEVELTEXTDISPLAY0) &&
      EqualBits(stream, pos + 50,  pos + 65,  p->L_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 65,  pos + 75,  p->T_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 75,  pos + 79,  p->M_MODETEXTDISPLAY1) &&
      EqualBits(stream, pos + 79,  pos + 82,  p->M_LEVELTEXTDISPLAY1) &&
      EqualBits(stream, pos + 90,  pos + 92,  p->Q_TEXTCONFIRM)     &&
      EqualBits(stream, pos + 126, pos + 134, p->Q_TEXT);

    predicate UpperBitsNotSet(Packet_for_sending_fixed_text_messages_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TEXTCLASS,      2)   &&
      UpperBitsNotSet(p->Q_TEXTDISPLAY,    1)   &&
      UpperBitsNotSet(p->D_TEXTDISPLAY,    15)  &&
      UpperBitsNotSet(p->M_MODETEXTDISPLAY0,4)   &&
      UpperBitsNotSet(p->M_LEVELTEXTDISPLAY0,3)   &&
      UpperBitsNotSet(p->L_TEXTDISPLAY,    15)  &&
      UpperBitsNotSet(p->T_TEXTDISPLAY,    10)  &&
      UpperBitsNotSet(p->M_MODETEXTDISPLAY1,4)   &&
      UpperBitsNotSet(p->M_LEVELTEXTDISPLAY1,3)   &&
      UpperBitsNotSet(p->Q_TEXTCONFIRM,    2)   &&
      UpperBitsNotSet(p->Q_TEXT,           8);

*/

#endif // PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_CORE_H_INCLUDED

