
#ifndef PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_H_INCLUDED
#define PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_H_INCLUDED

#include "Bitstream.h"
#include "Packet_for_sending_plain_text_messages_Core.h"
#include "BasePacket.h"

struct Packet_for_sending_plain_text_messages : public BasePacket
{
    Packet_for_sending_plain_text_messages_Core core;

    Packet_for_sending_plain_text_messages() : BasePacket(72) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
	       << +id << ','
               << +core.Q_DIR << ','
               << +core.L_PACKET << ','
               << +core.Q_SCALE << ','
               << +core.Q_TEXTCLASS << ','
               << +core.Q_TEXTDISPLAY << ','
               << +core.D_TEXTDISPLAY << ','
               << +core.M_MODETEXTDISPLAY0 << ','
               << +core.M_LEVELTEXTDISPLAY0 << ','
               << +core.NID_NTC0 << ','
               << +core.L_TEXTDISPLAY << ','
               << +core.T_TEXTDISPLAY << ','
               << +core.M_MODETEXTDISPLAY1 << ','
               << +core.M_LEVELTEXTDISPLAY1 << ','
               << +core.NID_NTC1 << ','
               << +core.Q_TEXTCONFIRM << ','
               << +core.Q_CONFTEXTDISPLAY << ','
               << +core.Q_TEXTREPORT << ','
               << +core.NID_TEXTMESSAGE << ','
               << +core.NID_C << ','
               << +core.NID_RBC << ','
               << +core.L_TEXT << ','
               << +core.X_TEXT << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Packet_for_sending_plain_text_messages*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.Q_TEXTCLASS == q->core.Q_TEXTCLASS) &&
                (core.Q_TEXTDISPLAY == q->core.Q_TEXTDISPLAY) &&
                (core.D_TEXTDISPLAY == q->core.D_TEXTDISPLAY) &&
                (core.M_MODETEXTDISPLAY0 == q->core.M_MODETEXTDISPLAY0) &&
                (core.M_LEVELTEXTDISPLAY0 == q->core.M_LEVELTEXTDISPLAY0) &&
                ((!core.M_LEVELTEXTDISPLAY0 == 1) || (
                (core.NID_NTC0 == q->core.NID_NTC0)
                )) &&
                ((!core.M_LEVELTEXTDISPLAY1 == 1) || (
                (core.NID_NTC1 == q->core.NID_NTC1)
                )) &&
                ((!core.Q_TEXTCONFIRM != 0) || (
                (core.Q_CONFTEXTDISPLAY == q->core.Q_CONFTEXTDISPLAY) &&
                (core.Q_TEXTREPORT == q->core.Q_TEXTREPORT)
                )) &&
                ((!(core.|| (core.)) || (
                (core.NID_TEXTMESSAGE == q->core.NID_TEXTMESSAGE) &&
                (core.NID_C == q->core.NID_C) &&
                (core.NID_RBC == q->core.NID_RBC)
                ));
	}
	return false;
    }
};

typedef std::shared_ptr<Packet_for_sending_plain_text_messages> Packet_for_sending_plain_text_messagesPtr;

#endif // PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_H_INCLUDED

