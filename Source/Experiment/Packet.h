
#ifndef PACKET_H_INCLUDED
#define PACKET_H_INCLUDED

#include "PacketHeader.h"

void TrainToTrack_Print(FILE* stream, const PacketHeader* header);

void TrackToTrain_Print(FILE* stream, const PacketHeader* header);

void BothWays_Print(FILE* stream, const PacketHeader* header);

void Packet_Print(FILE* stream, const PacketHeader* header);

uint32_t TrainToTrack_Length(const PacketHeader* header);

uint32_t TrackToTrain_Length(const PacketHeader* header);

uint32_t Packet_Length(const PacketHeader* header);

int Packet_Delete(PacketHeader* header);

#endif /* PACKET_H_INCLUDED */

