
#include "Validated_Train_Data_Message.h"
#include "Packet_Header_Decoder.h"
#include "Packet_Header_Encoder.h"
#include "Decoder_Branch.h"
#include "Encoder_Branch.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

#include "Bitwalker_Peek_Normal.h"
#include <iostream>
#include <cassert>


std::ostream& operator<< (std::ostream& stream, const Validated_Train_Data_Message& p)
{
    stream << '('
           << +p.NID_MESSAGE << ","
           << +p.L_MESSAGE << ","
           << +p.T_TRAIN << ","
	   << +p.NID_ENGINE << ","
           << *(p.packet_0_1) << ","
           << *(p.packet_11) << ")";

    return stream;
}

bool operator==(const Validated_Train_Data_Message& a, const Validated_Train_Data_Message& b)
{
    bool result = true;
    
    result = result && (a.NID_MESSAGE == b.NID_MESSAGE);
    result = result && (a.L_MESSAGE == b.L_MESSAGE);
    result = result && (a.T_TRAIN == b.T_TRAIN);
    result = result && (a.NID_ENGINE == b.NID_ENGINE);
    result = result && (*(a.packet_0_1) == *(b.packet_0_1));
    result = result && (*(a.packet_11) == *(b.packet_11));

    return result;
}

bool operator!=(const Validated_Train_Data_Message& a, const Validated_Train_Data_Message& b)
{
    return !(a == b);
}

bool Validated_Train_Data_Message::decode(Bitstream& stream)
{
    uint32_t old_pos = stream.bitpos;

    NID_MESSAGE = Bitstream_Read(&stream, 8);
    L_MESSAGE = Bitstream_Read(&stream, 10);
    T_TRAIN = Bitstream_Read(&stream, 32);
    NID_ENGINE = Bitstream_Read(&stream, 24);

    Packet_Header packetID;
    Packet_Header_Decoder(&stream, &packetID);

    packet_0_1 = Decoder_Branch_TrainToTrack(stream, packetID);
    if (!packet_0_1)
    {
        return false;
    }

    Packet_Header_Decoder(&stream, &packetID);
    packet_11 = Decoder_Branch_TrainToTrack(stream, packetID);
    if (!packet_11)
    {
        return false;
    }

    if (stream.bitpos > old_pos + (8 * L_MESSAGE))
    {
        return false;
    }

    stream.bitpos = old_pos + (8 * L_MESSAGE);

    return true;
}

bool Validated_Train_Data_Message::encode(Bitstream& stream) const
{
    uint32_t old_pos = stream.bitpos;

    Bitstream_Write(&stream, 8, NID_MESSAGE);
    Bitstream_Write(&stream, 10, L_MESSAGE);
    Bitstream_Write(&stream, 32, T_TRAIN);
    Bitstream_Write(&stream, 24, NID_ENGINE);

    Packet_Header packetID;
    packetID.NID_PACKET = packet_0_1->id;

    if (Packet_Header_Encoder(&stream, &packetID) != 1)
    {
        return false;
    }
    if (Encoder_Branch_TrainToTrack(stream, packet_0_1) != 1)
    {
        return false;
    }

    packetID.NID_PACKET = packet_11->id;

    if (Packet_Header_Encoder(&stream, &packetID) != 1)
    {
        return false;
    }
    if (Encoder_Branch_TrainToTrack(stream, packet_11) != 1)
    {
        return false;
    }

    if (stream.bitpos > old_pos + (8 * L_MESSAGE))
    {
        return false;
    }

    stream.bitpos = old_pos + (8 * L_MESSAGE);

    return true;
} 
