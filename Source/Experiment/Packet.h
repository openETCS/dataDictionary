
#ifndef PACKET_H_INCLUDED
#define PACKET_H_INCLUDED

#include "PacketHeader.h"

int TrainToTrack_DecodeBit(PacketHeader* header, Bitstream* stream);

int TrackToTrain_DecodeBit(PacketHeader* header, Bitstream* stream);

int TrainToTrack_Length(const PacketHeader* header);

int TrackToTrain_Length(const PacketHeader* header);

#endif /* PACKET_H_INCLUDED */

