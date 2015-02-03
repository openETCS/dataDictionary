
#include "TrainToTrack_Header_Encoder.h"
#include "TrainToTrack_Header_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int TrainToTrack_Header_Encoder(Bitstream* stream, const TrainToTrack_Header* p)
{
    if (NormalBitstream(stream, TRAINTOTRACK_HEADER_BITSIZE))
    {
        if (TrainToTrack_Header_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,  	 8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   13, p->L_PACKET);

            stream->bitpos += TRAINTOTRACK_HEADER_BITSIZE;

            //@ assert NID_PACKET:           EqualBits(stream, pos,       pos + 8,  p->NID_PACKET);
            //@ assert L_PACKET:             EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);

            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

