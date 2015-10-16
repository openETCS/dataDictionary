
#ifndef PACKETFACTORY_H_INCLUDED
#define PACKETFACTORY_H_INCLUDED

#include "PacketHeader.h"

PacketHeader* PacketFactory_TrackToTrain(PacketHeader header);

PacketHeader* PacketFactory_TrainToTrack(PacketHeader header);

PacketHeader* PacketFactory_BothWays(PacketHeader header);

#endif /* PACKETFACTORY_H_INCLUDED */

