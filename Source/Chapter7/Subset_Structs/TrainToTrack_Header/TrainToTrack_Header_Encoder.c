
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
            Bitwalker_Poke_Normal(addr, size, pos + 8,   10, p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  23, p->L_PACKET);

            stream->bitpos += TRAINTOTRACK_HEADER_BITSIZE;

            //@ assert NID_PACKET:           EqualBits(stream, pos + 23,  pos + 25,  p->NID_PACKET);
            //@ assert Q_DIR:                EqualBits(stream, pos + 25,  pos + 40,  p->Q_DIR);
            //@ assert L_PACKET:             EqualBits(stream, pos + 40,  pos + 55,  p->L_PACKET);

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

