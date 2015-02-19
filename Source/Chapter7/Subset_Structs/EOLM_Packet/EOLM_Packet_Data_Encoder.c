
#include "EOLM_Packet_Data_Encoder.h"
#include "EOLM_Packet_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int EOLM_Packet_Data_Encoder(Bitstream* stream, const EOLM_Packet_Data* p)
{
    if (NormalBitstream(stream, EOLM_PACKET_DATA_BITSIZE))
    {
        if (EOLM_Packet_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 15,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 17,  14, p->NID_LOOP);
            Bitwalker_Poke_Normal(addr, size, pos + 31,  15, p->D_LOOP);
            Bitwalker_Poke_Normal(addr, size, pos + 46,  15, p->L_LOOP);
            Bitwalker_Poke_Normal(addr, size, pos + 61,  1,  p->Q_LOOPDIR);
            Bitwalker_Poke_Normal(addr, size, pos + 62,  4,  p->Q_SSCODE);

            stream->bitpos += EOLM_PACKET_DATA_BITSIZE;

            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert NID_LOOP:          EqualBits(stream, pos + 17,  pos + 31,  p->NID_LOOP);
            //@ assert D_LOOP:            EqualBits(stream, pos + 31,  pos + 46,  p->D_LOOP);
            //@ assert L_LOOP:            EqualBits(stream, pos + 46,  pos + 61,  p->L_LOOP);
            //@ assert Q_LOOPDIR:         EqualBits(stream, pos + 61,  pos + 62,  p->Q_LOOPDIR);
            //@ assert Q_SSCODE:          EqualBits(stream, pos + 62,  pos + 66,  p->Q_SSCODE);

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

