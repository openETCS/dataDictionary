
#ifndef PACKETFACTORY_H_INCLUDED
#define PACKETFACTORY_H_INCLUDED

#include "BasePacket.h"
#include "Packets.h"

BasePacketPtr PacketFactory_TrainToTrack(uint8_t nid);

BasePacketPtr PacketFactory_TrackToTrain(uint8_t nid);

#endif // PACKETFACTORY_H_INCLUDED

