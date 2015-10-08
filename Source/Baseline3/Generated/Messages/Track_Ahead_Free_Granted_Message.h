
#ifndef TRACK_AHEAD_FREE_GRANTED_Message_H_INCLUDED
#define TRACK_AHEAD_FREE_GRANTED_Message_H_INCLUDED

#include "EuroradioMessage.h"
#include "Bitstream.h"
#include <iostream>

struct Track_Ahead_Free_Granted_Message : public EuroradioMessage
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint32_t  NID_ENGINE       ;  // # 24

    BasePacketPtr  packet_0_1;

    Track_Ahead_Free_Granted_Message() : EuroradioMessage(149) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +NID_ENGINE << ","
               << *(packet_0_1) << ")";
    }

    bool equals(const EuroradioMessage& p) const override
    {
	if (auto q = dynamic_cast<const Track_Ahead_Free_Granted_Message*>(&p))
	{
            bool status = true;
    
            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (NID_ENGINE == q->NID_ENGINE);
            status = status && (*packet_0_1 == *(q->packet_0_1));

            return status;
        }
	return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<Track_Ahead_Free_Granted_Message> Track_Ahead_Free_Granted_MessagePtr;

#endif // TRACK_AHEAD_FREE_GRANTED_Message_H_INCLUDED

