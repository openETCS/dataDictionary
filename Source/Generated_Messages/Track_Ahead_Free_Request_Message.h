
#ifndef TRACK_AHEAD_FREE_REQUEST_Message_H_INCLUDED
#define TRACK_AHEAD_FREE_REQUEST_Message_H_INCLUDED

#include "Euroradio_Message.h"
#include "Bitstream.h"
#include <iostream>

struct Track_Ahead_Free_Request_Message : public Euroradio_Message
{
    uint16_t  L_MESSAGE        ;  // # 10
    uint32_t  T_TRAIN          ;  // # 32
    uint8_t  M_ACK             ;  // # 1
    uint32_t  NID_LRBG         ;  // # 24
    uint8_t  Q_SCALE           ;  // # 2
    uint16_t  D_REF            ;  // # 16
    uint8_t  Q_DIR             ;  // # 2
    uint16_t  D_TAFDISPLAY     ;  // # 15
    uint16_t  L_TAFDISPLAY     ;  // # 15


    Track_Ahead_Free_Request_Message() : Euroradio_Message(34) {}

    void print(std::ostream& stream) const override
    {
        stream << '('
               << +header.NID_MESSAGE  << ","
               << +L_MESSAGE << ","
               << +T_TRAIN << ","
               << +M_ACK << ","
               << +NID_LRBG << ","
               << +Q_SCALE << ","
               << +D_REF << ","
               << +Q_DIR << ","
               << +D_TAFDISPLAY << ","
               << +L_TAFDISPLAY << ")";
    }

    bool equals(const Euroradio_Message& p) const override
    {
	if (auto q = dynamic_cast<const Track_Ahead_Free_Request_Message*>(&p))
	{
            bool status = true;
    
            status = status && (header.NID_MESSAGE == q->header.NID_MESSAGE);
            status = status && (L_MESSAGE == q->L_MESSAGE);
            status = status && (T_TRAIN == q->T_TRAIN);
            status = status && (M_ACK == q->M_ACK);
            status = status && (NID_LRBG == q->NID_LRBG);
            status = status && (Q_SCALE == q->Q_SCALE);
            status = status && (D_REF == q->D_REF);
            status = status && (Q_DIR == q->Q_DIR);
            status = status && (D_TAFDISPLAY == q->D_TAFDISPLAY);
            status = status && (L_TAFDISPLAY == q->L_TAFDISPLAY);

            return status;
        }
	return false;
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

typedef std::shared_ptr<Track_Ahead_Free_Request_Message> Track_Ahead_Free_Request_MessagePtr;

#endif // TRACK_AHEAD_FREE_REQUEST_Message_H_INCLUDED

