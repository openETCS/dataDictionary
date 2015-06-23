
#ifndef PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_CORE_H_INCLUDED
#define PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Packet_for_sending_plain_text_messages_Core
{
    // TransmissionMedia=Balise, RBC
    // Packet Number = 72

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint32_t  Q_TEXTCLASS;      // # 2
    uint32_t  Q_TEXTDISPLAY;    // # 1
    uint16_t  D_TEXTDISPLAY;    // # 15
    uint8_t   M_MODETEXTDISPLAY_0;// # 4
    uint8_t   M_LEVELTEXTDISPLAY_0;// # 3
    uint8_t   NID_NTC_0;        // # 8
    uint16_t  L_TEXTDISPLAY;    // # 15
    uint16_t  T_TEXTDISPLAY;    // # 10
    uint8_t   M_MODETEXTDISPLAY_1;// # 4
    uint8_t   M_LEVELTEXTDISPLAY_1;// # 3
    uint8_t   NID_NTC_1;        // # 8
    uint32_t  Q_TEXTCONFIRM;    // # 2
    uint32_t  Q_CONFTEXTDISPLAY;// # 1
    uint32_t  Q_TEXTREPORT;     // # 1
    uint8_t   NID_TEXTMESSAGE;  // # 8
    uint16_t  NID_C;            // # 10
    uint16_t  NID_RBC;          // # 14
    uint8_t   L_TEXT;           // # 8
    uint8_t   X_TEXT;           // # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Packet_for_sending_plain_text_messages_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.Q_TEXTCLASS << ','
       << +p.Q_TEXTDISPLAY << ','
       << +p.D_TEXTDISPLAY << ','
       << +p.M_MODETEXTDISPLAY_0 << ','
       << +p.M_LEVELTEXTDISPLAY_0 << ','
       << +p.NID_NTC_0 << ','
       << +p.L_TEXTDISPLAY << ','
       << +p.T_TEXTDISPLAY << ','
       << +p.M_MODETEXTDISPLAY_1 << ','
       << +p.M_LEVELTEXTDISPLAY_1 << ','
       << +p.NID_NTC_1 << ','
       << +p.Q_TEXTCONFIRM << ','
       << +p.Q_CONFTEXTDISPLAY << ','
       << +p.Q_TEXTREPORT << ','
       << +p.NID_TEXTMESSAGE << ','
       << +p.NID_C << ','
       << +p.NID_RBC << ','
       << +p.L_TEXT << ','
       << +p.X_TEXT;

    return stream;
}

inline bool operator==(const Packet_for_sending_plain_text_messages_Core& a, const Packet_for_sending_plain_text_messages_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.Q_TEXTCLASS == b.Q_TEXTCLASS);
    status = status && (a.Q_TEXTDISPLAY == b.Q_TEXTDISPLAY);
    status = status && (a.D_TEXTDISPLAY == b.D_TEXTDISPLAY);
    status = status && (a.M_MODETEXTDISPLAY_0 == b.M_MODETEXTDISPLAY_0);
    status = status && (a.M_LEVELTEXTDISPLAY_0 == b.M_LEVELTEXTDISPLAY_0);
    if (a.M_LEVELTEXTDISPLAY_0 == 1)
    {
    status = status && (a.NID_NTC_0 == b.NID_NTC_0);
    }
    status = status && (a.L_TEXTDISPLAY == b.L_TEXTDISPLAY);
    status = status && (a.T_TEXTDISPLAY == b.T_TEXTDISPLAY);
    status = status && (a.M_MODETEXTDISPLAY_1 == b.M_MODETEXTDISPLAY_1);
    status = status && (a.M_LEVELTEXTDISPLAY_1 == b.M_LEVELTEXTDISPLAY_1);
    if (a.M_LEVELTEXTDISPLAY_1 == 1)
    {
    status = status && (a.NID_NTC_1 == b.NID_NTC_1);
    }
    status = status && (a.Q_TEXTCONFIRM == b.Q_TEXTCONFIRM);
    if (a.Q_TEXTCONFIRM != 0)
    {
    status = status && (a.Q_CONFTEXTDISPLAY == b.Q_CONFTEXTDISPLAY);
    status = status && (a.Q_TEXTREPORT == b.Q_TEXTREPORT);
    }
    if (a.Q_TEXTREPORT == 1)
    {
    status = status && (a.NID_TEXTMESSAGE == b.NID_TEXTMESSAGE);
    status = status && (a.NID_C == b.NID_C);
    status = status && (a.NID_RBC == b.NID_RBC);
    }
    status = status && (a.L_TEXT == b.L_TEXT);
    status = status && (a.X_TEXT == b.X_TEXT);

    return status;
}

inline bool operator!=(const Packet_for_sending_plain_text_messages_Core& a, const Packet_for_sending_plain_text_messages_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Packet_for_sending_plain_text_messages_Core Packet_for_sending_plain_text_messages_Core;

#define PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_CORE_BITSIZE 142

/*@
    logic integer BitSize{L}(Packet_for_sending_plain_text_messages_Core* p) = PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Packet_for_sending_plain_text_messages_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Packet_for_sending_plain_text_messages_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Packet_for_sending_plain_text_messages_Core* p) = \true;

    predicate ZeroInitialized(Packet_for_sending_plain_text_messages_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Packet_for_sending_plain_text_messages_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 19,  p->Q_TEXTCLASS)       &&
      EqualBits(stream, pos + 19,  pos + 20,  p->Q_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 20,  pos + 35,  p->D_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 35,  pos + 39,  p->M_MODETEXTDISPLAY_0) &&
      EqualBits(stream, pos + 39,  pos + 42,  p->M_LEVELTEXTDISPLAY_0) &&
      EqualBits(stream, pos + 50,  pos + 65,  p->L_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 65,  pos + 75,  p->T_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 75,  pos + 79,  p->M_MODETEXTDISPLAY_1) &&
      EqualBits(stream, pos + 79,  pos + 82,  p->M_LEVELTEXTDISPLAY_1) &&
      EqualBits(stream, pos + 90,  pos + 92,  p->Q_TEXTCONFIRM)     &&
      EqualBits(stream, pos + 126, pos + 134, p->L_TEXT)            &&
      EqualBits(stream, pos + 134, pos + 142, p->X_TEXT);

    predicate UpperBitsNotSet(Packet_for_sending_plain_text_messages_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TEXTCLASS,      2)   &&
      UpperBitsNotSet(p->Q_TEXTDISPLAY,    1)   &&
      UpperBitsNotSet(p->D_TEXTDISPLAY,    15)  &&
      UpperBitsNotSet(p->M_MODETEXTDISPLAY_0,4)   &&
      UpperBitsNotSet(p->M_LEVELTEXTDISPLAY_0,3)   &&
      UpperBitsNotSet(p->L_TEXTDISPLAY,    15)  &&
      UpperBitsNotSet(p->T_TEXTDISPLAY,    10)  &&
      UpperBitsNotSet(p->M_MODETEXTDISPLAY_1,4)   &&
      UpperBitsNotSet(p->M_LEVELTEXTDISPLAY_1,3)   &&
      UpperBitsNotSet(p->Q_TEXTCONFIRM,    2)   &&
      UpperBitsNotSet(p->L_TEXT,           8)   &&
      UpperBitsNotSet(p->X_TEXT,           8);

*/

#endif // PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_CORE_H_INCLUDED

