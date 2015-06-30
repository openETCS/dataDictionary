
#ifndef PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_CORE_H_INCLUDED
#define PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

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
    uint32_t  Q_TEXT;           // # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Packet_for_sending_fixed_text_messages_Core& p)
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
       << +p.Q_TEXT;

    return stream;
}

inline bool operator==(const Packet_for_sending_fixed_text_messages_Core& a, const Packet_for_sending_fixed_text_messages_Core& b)
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
    status = status && (a.Q_TEXT == b.Q_TEXT);

    return status;
}

inline bool operator!=(const Packet_for_sending_fixed_text_messages_Core& a, const Packet_for_sending_fixed_text_messages_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Packet_for_sending_fixed_text_messages_Core Packet_for_sending_fixed_text_messages_Core;

#define PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_CORE_BITSIZE 3070

/*@
    logic integer BitSize{L}(Packet_for_sending_fixed_text_messages_Core* p) = PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Packet_for_sending_fixed_text_messages_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Packet_for_sending_fixed_text_messages_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Packet_for_sending_fixed_text_messages_Core* p) = \true;

    predicate ZeroInitialized(Packet_for_sending_fixed_text_messages_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Packet_for_sending_fixed_text_messages_Core* p) = \true;

    predicate UpperBitsNotSet(Packet_for_sending_fixed_text_messages_Core* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Packet_for_sending_fixed_text_messages_UpperBitsNotSet(const Packet_for_sending_fixed_text_messages_Core* p);

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid_read(p);
    requires invariant:         Invariant(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures left:       Unchanged{Here,Old}(stream, 0, \old(stream->bitpos));
      ensures middle:     EqualBits(stream, \old(stream->bitpos), p);
      ensures right:      Unchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    behavior values_too_big:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures result:        \result == -2;

    behavior invalid_bit_sequence:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result:       \result == -1;

    complete behaviors;
    disjoint behaviors;
*/
int Packet_for_sending_fixed_text_messages_Encoder(Bitstream* stream, const Packet_for_sending_fixed_text_messages_Core* p);

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          Unchanged{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures invariant:  Invariant(p);
      ensures result:     \result == 1; 
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), p);
      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Packet_for_sending_fixed_text_messages_Decoder(Bitstream* stream, Packet_for_sending_fixed_text_messages_Core* p);

#endif // PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_CORE_H_INCLUDED

