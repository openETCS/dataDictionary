
#ifndef ENCODER_BRANCH_H_INCLUDED
#define ENCODER_BRANCH_H_INCLUDED

#include "Bitstream.h"
#include "subsets.h"
#include "Packet_Header.h"
#include "BasePacket.h"

bool Encoder_Branch(Bitstream& stream, BasePacketPtr packet);

#endif // ENCODER_BRANCH_H_INCLUDED

