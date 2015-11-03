
#ifndef PACKET_DECODEINT_H_INCLUDE
#define PACKET_DECODEINT_H_INCLUDE

#include "PacketHeader.h"
#include "Bitstream.h"
#include "CompressedPackets.h"

int Packet_DecodeBit(PacketHeader* header, const Metadata* data, const kcg_int* stream);

#endif // PACKET_DECODEINT_H_INCLUDE

