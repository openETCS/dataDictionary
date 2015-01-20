
#ifndef TRACKTOTRAIN_HEADER_H_INCLUDED
#define TRACKTOTRAIN_HEADER_H_INCLUDED

#include "Bitstream.h"

struct TrackToTrain_Header {
    uint64_t  NID_PACKET;         // # 8
    uint64_t  Q_DIR;              // # 2
    uint64_t  L_PACKET;           // # 13
};

#endif // TRACKTOTRAIN_HEADER_H_INCLUDED

