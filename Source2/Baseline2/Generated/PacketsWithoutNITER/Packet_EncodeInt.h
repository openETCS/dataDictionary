
#ifndef PACKET_ENCODEINT_H_INCLUDE
#define PACKET_ENCODEINT_H_INCLUDE

#include "PacketHeader.h"
#include "Bitstream.h"
#include "CompressedPackets.h"

int Packet_EncodeInt(const PacketHeader* header, Metadata* data, kcg_int* stream);

#endif // PACKET_ENCODEINT_H_INCLUDE

