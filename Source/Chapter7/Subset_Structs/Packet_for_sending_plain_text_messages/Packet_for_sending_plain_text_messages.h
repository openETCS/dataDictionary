
#ifndef PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_H_INCLUDED
#define PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_H_INCLUDED

#include "Bitstream.h"

struct Packet_for_sending_plain_text_messages
{
    // TransmissionMedia=Balise, RBC
    // Packet Number = 72

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  Q_TEXTCLASS;      // # 2
    uint64_t  Q_TEXTDISPLAY;    // # 1
    uint64_t  D_TEXTDISPLAY;    // # 15// # 4// # 3// # 8
    uint64_t  L_TEXTDISPLAY;    // # 15
    uint64_t  T_TEXTDISPLAY;    // # 10// # 4// # 3// # 8
    uint64_t  Q_TEXTCONFIRM;    // # 2
    uint64_t  Q_CONFTEXTDISPLAY;// # 1
    uint64_t  Q_TEXTREPORT;     // # 1
    uint64_t  NID_TEXTMESSAGE;  // # 8
    uint64_t  NID_C;            // # 10
    uint64_t  NID_RBC;          // # 14
    uint64_t  L_TEXT;           // # 8
    uint64_t  X_TEXT;           // # 8
};

typedef struct Packet_for_sending_plain_text_messages Packet_for_sending_plain_text_messages;

#define PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_BITSIZE 150

/*@
    logic integer BitSize{L}(Packet_for_sending_plain_text_messages* p) = PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_BITSIZE;

    logic integer MaxBitSize{L}(Packet_for_sending_plain_text_messages* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Packet_for_sending_plain_text_messages* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Packet_for_sending_plain_text_messages* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->Q_TEXTCLASS)       &&
      Invariant(p->Q_TEXTDISPLAY)     &&
      Invariant(p->D_TEXTDISPLAY)     &&
      Invariant(p->M_MODETEXTDISPLAY(0)) &&
      Invariant(p->M_LEVELTEXTDISPLAY(0)) &&
      Invariant(p->NID_NTC(0))        &&
      Invariant(p->L_TEXTDISPLAY)     &&
      Invariant(p->T_TEXTDISPLAY)     &&
      Invariant(p->M_MODETEXTDISPLAY(1)) &&
      Invariant(p->M_LEVELTEXTDISPLAY(1)) &&
      Invariant(p->NID_NTC(1))        &&
      Invariant(p->Q_TEXTCONFIRM)     &&
      Invariant(p->Q_CONFTEXTDISPLAY) &&
      Invariant(p->Q_TEXTREPORT)      &&
      Invariant(p->NID_TEXTMESSAGE)   &&
      Invariant(p->NID_C)             &&
      Invariant(p->NID_RBC)           &&
      Invariant(p->L_TEXT)            &&
      Invariant(p->X_TEXT);

    predicate ZeroInitialized(Packet_for_sending_plain_text_messages* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->Q_TEXTCLASS)       &&
      ZeroInitialized(p->Q_TEXTDISPLAY)     &&
      ZeroInitialized(p->D_TEXTDISPLAY)     &&
      ZeroInitialized(p->M_MODETEXTDISPLAY(0)) &&
      ZeroInitialized(p->M_LEVELTEXTDISPLAY(0)) &&
      ZeroInitialized(p->NID_NTC(0))        &&
      ZeroInitialized(p->L_TEXTDISPLAY)     &&
      ZeroInitialized(p->T_TEXTDISPLAY)     &&
      ZeroInitialized(p->M_MODETEXTDISPLAY(1)) &&
      ZeroInitialized(p->M_LEVELTEXTDISPLAY(1)) &&
      ZeroInitialized(p->NID_NTC(1))        &&
      ZeroInitialized(p->Q_TEXTCONFIRM)     &&
      ZeroInitialized(p->Q_CONFTEXTDISPLAY) &&
      ZeroInitialized(p->Q_TEXTREPORT)      &&
      ZeroInitialized(p->NID_TEXTMESSAGE)   &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->NID_RBC)           &&
      ZeroInitialized(p->L_TEXT)            &&
      ZeroInitialized(p->X_TEXT);

    predicate EqualBits(Bitstream* stream, integer pos, Packet_for_sending_plain_text_messages* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 27,  p->Q_TEXTCLASS)       &&
      EqualBits(stream, pos + 27,  pos + 28,  p->Q_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 28,  pos + 43,  p->D_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 43,  pos + 47,  p->M_MODETEXTDISPLAY(0)) &&
      EqualBits(stream, pos + 47,  pos + 50,  p->M_LEVELTEXTDISPLAY(0)) &&
      EqualBits(stream, pos + 50,  pos + 58,  p->NID_NTC(0))        &&
      EqualBits(stream, pos + 58,  pos + 73,  p->L_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 73,  pos + 83,  p->T_TEXTDISPLAY)     &&
      EqualBits(stream, pos + 83,  pos + 87,  p->M_MODETEXTDISPLAY(1)) &&
      EqualBits(stream, pos + 87,  pos + 90,  p->M_LEVELTEXTDISPLAY(1)) &&
      EqualBits(stream, pos + 90,  pos + 98,  p->NID_NTC(1))        &&
      EqualBits(stream, pos + 98,  pos + 100, p->Q_TEXTCONFIRM)     &&
      EqualBits(stream, pos + 100, pos + 101, p->Q_CONFTEXTDISPLAY) &&
      EqualBits(stream, pos + 101, pos + 102, p->Q_TEXTREPORT)      &&
      EqualBits(stream, pos + 102, pos + 110, p->NID_TEXTMESSAGE)   &&
      EqualBits(stream, pos + 110, pos + 120, p->NID_C)             &&
      EqualBits(stream, pos + 120, pos + 134, p->NID_RBC)           &&
      EqualBits(stream, pos + 134, pos + 142, p->L_TEXT)            &&
      EqualBits(stream, pos + 142, pos + 150, p->X_TEXT);


    predicate UpperBitsNotSet(Packet_for_sending_plain_text_messages* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->Q_TEXTCLASS,      2)   &&
      UpperBitsNotSet(p->Q_TEXTDISPLAY,    1)   &&
      UpperBitsNotSet(p->D_TEXTDISPLAY,    15)  &&
      UpperBitsNotSet(p->M_MODETEXTDISPLAY(0),4)   &&
      UpperBitsNotSet(p->M_LEVELTEXTDISPLAY(0),3)   &&
      UpperBitsNotSet(p->NID_NTC(0),       8)   &&
      UpperBitsNotSet(p->L_TEXTDISPLAY,    15)  &&
      UpperBitsNotSet(p->T_TEXTDISPLAY,    10)  &&
      UpperBitsNotSet(p->M_MODETEXTDISPLAY(1),4)   &&
      UpperBitsNotSet(p->M_LEVELTEXTDISPLAY(1),3)   &&
      UpperBitsNotSet(p->NID_NTC(1),       8)   &&
      UpperBitsNotSet(p->Q_TEXTCONFIRM,    2)   &&
      UpperBitsNotSet(p->Q_CONFTEXTDISPLAY,1)   &&
      UpperBitsNotSet(p->Q_TEXTREPORT,     1)   &&
      UpperBitsNotSet(p->NID_TEXTMESSAGE,  8)   &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->NID_RBC,          14)  &&
      UpperBitsNotSet(p->L_TEXT,           8)   &&
      UpperBitsNotSet(p->X_TEXT,           8);

*/

#endif // PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_H_INCLUDED

