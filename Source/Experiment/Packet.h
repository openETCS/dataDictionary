
#ifndef PACKET_H_INCLUDED
#define PACKET_H_INCLUDED

#include "PacketHeader.h"

int TrainToTrack_DecodeBit(PacketHeader* header, Bitstream* stream);

int TrackToTrain_DecodeBit(PacketHeader* header, Bitstream* stream);

int BothWays_DecodeBit(PacketHeader* header, Bitstream* stream);

int Packet_DecodeBit(PacketHeader* header, Bitstream* stream);

void TrainToTrack_Print(FILE* stream, PacketHeader* header);

void TrackToTrain_Print(FILE* stream, PacketHeader* header);

void BothWays_Print(FILE* stream, PacketHeader* header);

void Packet_Print(FILE* stream, PacketHeader* header);

int TrainToTrack_Length(const PacketHeader* header);

int TrackToTrain_Length(const PacketHeader* header);

int Packet_Length(const PacketHeader* header);

#endif /* PACKET_H_INCLUDED */

