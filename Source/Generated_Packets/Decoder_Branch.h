
#ifndef DECODER_BRANCH_H_INCLUDED
#define DECODER_BRANCH_H_INCLUDED

#include "Bitstream.h"
#include "Packets.h"
#include "Packet_Header.h"
#include "BasePacket.h"

BasePacketPtr Decoder_Branch_TrackToTrain(Bitstream& stream, Packet_Header header);

BasePacketPtr Decoder_Branch_TrainToTrack(Bitstream& stream, Packet_Header header);

#endif // DECODER_BRANCH_H_INCLUDED

