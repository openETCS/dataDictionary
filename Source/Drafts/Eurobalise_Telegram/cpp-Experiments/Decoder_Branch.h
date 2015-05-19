
#ifndef DECODER_BRANCH_H_INCLUDED
#define DECODER_BRANCH_H_INCLUDED

#include "Bitstream.h"
#include "Adhesion_Factor.h"
#include "BasePacket.h"
#include "Packet_Header.h"
#include "Adhesion_Factor_Decoder.h"

BasePacketPtr Decoder_Branch(Bitstream* stream, Packet_Header header);

#endif // DECODER_BRANCH_H_INCLUDED

