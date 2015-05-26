
#ifndef DECODER_BRANCH_H_INCLUDED
#define DECODER_BRANCH_H_INCLUDED

#include "Bitstream.h"
#include "subsets.h"
#include "Packet_Header.h"
#include "BasePacket.h"

BasePacketPtr Decoder_Branch(Bitstream* stream, Packet_Header header);

#endif // DECODER_BRANCH_H_INCLUDED

