
#ifndef ENCODER_BRANCH_H_INCLUDED
#define ENCODER_BRANCH_H_INCLUDED

#include "Packets.h"
#include "BasePacket.h"

bool Encoder_Branch_TrainToTrack(Bitstream& stream, BasePacketPtr packet);

bool Encoder_Branch_TrackToTrain(Bitstream& stream, BasePacketPtr packet);

#endif // ENCODER_BRANCH_H_INCLUDED

