
#ifndef DECODER_BRANCH_H_INCLUDED
#define DECODER_BRANCH_H_INCLUDED

#include "BasePacket.h"
#include "Packets.h"

BasePacketPtr Decoder_Branch_TrackToTrain(Bitstream& stream, PacketHeader header);

BasePacketPtr Decoder_Branch_TrainToTrack(Bitstream& stream, PacketHeader header);

#endif // DECODER_BRANCH_H_INCLUDED

