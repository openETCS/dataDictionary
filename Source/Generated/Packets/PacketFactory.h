
#ifndef PACKETFACTORY_H_INCLUDED
#define PACKETFACTORY_H_INCLUDED

#include "BasePacket.h"
#include "Packets.h"

BasePacketPtr PacketFactory_TrainToTrack(Bitstream& stream, PacketHeader header);

BasePacketPtr PacketFactory_TrackToTrain(Bitstream& stream, PacketHeader header);

#endif // PACKETFACTORY_H_INCLUDED

