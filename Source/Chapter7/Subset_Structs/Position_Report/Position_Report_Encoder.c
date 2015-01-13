
#include "Position_Report_Encoder.h"
#include "Position_Report_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Position_Report_Encoder(Bitstream* stream, const Position_Report* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_BITSIZE))
    {
        if (Position_Report_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 21,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  24, p->NID_LRBG);
            Bitwalker_Poke_Normal(addr, size, pos + 47,  15, p->D_LRBG);
            Bitwalker_Poke_Normal(addr, size, pos + 62,  2,  p->Q_DIRLRBG);
            Bitwalker_Poke_Normal(addr, size, pos + 64,  2,  p->Q_DLRBG);
            Bitwalker_Poke_Normal(addr, size, pos + 66,  15, p->L_DOUBTOVER);
            Bitwalker_Poke_Normal(addr, size, pos + 81,  15, p->L_DOUBTUNDER);
            Bitwalker_Poke_Normal(addr, size, pos + 96,  2,  p->Q_LENGTH);
            Bitwalker_Poke_Normal(addr, size, pos + 98,  15, p->L_TRAININT);
            Bitwalker_Poke_Normal(addr, size, pos + 113, 7,  p->V_TRAIN);
            Bitwalker_Poke_Normal(addr, size, pos + 120, 2,  p->Q_DIRTRAIN);
            Bitwalker_Poke_Normal(addr, size, pos + 122, 4,  p->M_MODE);
            Bitwalker_Poke_Normal(addr, size, pos + 126, 3,  p->M_LEVEL);
            Bitwalker_Poke_Normal(addr, size, pos + 129, 8,  p->NID_NTC);

            stream->bitpos += POSITION_REPORT_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 21,  pos + 23,  p->Q_SCALE);
            //@ assert NID_LRBG:          EqualBits(stream, pos + 23,  pos + 47,  p->NID_LRBG);
            //@ assert D_LRBG:            EqualBits(stream, pos + 47,  pos + 62,  p->D_LRBG);
            //@ assert Q_DIRLRBG:         EqualBits(stream, pos + 62,  pos + 64,  p->Q_DIRLRBG);
            //@ assert Q_DLRBG:           EqualBits(stream, pos + 64,  pos + 66,  p->Q_DLRBG);
            //@ assert L_DOUBTOVER:       EqualBits(stream, pos + 66,  pos + 81,  p->L_DOUBTOVER);
            //@ assert L_DOUBTUNDER:      EqualBits(stream, pos + 81,  pos + 96,  p->L_DOUBTUNDER);
            //@ assert Q_LENGTH:          EqualBits(stream, pos + 96,  pos + 98,  p->Q_LENGTH);
            //@ assert L_TRAININT:        EqualBits(stream, pos + 98,  pos + 113, p->L_TRAININT);
            //@ assert V_TRAIN:           EqualBits(stream, pos + 113, pos + 120, p->V_TRAIN);
            //@ assert Q_DIRTRAIN:        EqualBits(stream, pos + 120, pos + 122, p->Q_DIRTRAIN);
            //@ assert M_MODE:            EqualBits(stream, pos + 122, pos + 126, p->M_MODE);
            //@ assert M_LEVEL:           EqualBits(stream, pos + 126, pos + 129, p->M_LEVEL);
            //@ assert NID_NTC:           EqualBits(stream, pos + 129, pos + 137, p->NID_NTC);

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

