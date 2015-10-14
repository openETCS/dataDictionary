
#ifndef PACKET_H_INCLUDED
#define PACKET_H_INCLUDED

#include "PacketHeader.h"


uint32_t TrainToTrack_Length(const PacketHeader* header);

uint32_t TrackToTrain_Length(const PacketHeader* header);

uint32_t Packet_Length(const PacketHeader* header);

#endif /* PACKET_H_INCLUDED */

