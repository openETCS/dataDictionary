
#include "Route_Suitability_Data_Encoder.h"
#include "Route_Suitability_Data_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Route_Suitability_Data_Encoder(Bitstream* stream, const Route_Suitability_Data* p)
{
    if (NormalBitstream(stream, ROUTE_SUITABILITY_DATA_BITSIZE))
    {
        if (Route_Suitability_Data_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  1,  p->Q_TRACKINIT);
            Bitwalker_Poke_Normal(addr, size, pos + 26,  15, p->D_TRACKINIT);
            Bitwalker_Poke_Normal(addr, size, pos + 41,  15, p->D_SUITABILITY);
            Bitwalker_Poke_Normal(addr, size, pos + 56,  2,  p->Q_SUITABILITY);
            Bitwalker_Poke_Normal(addr, size, pos + 58,  8,  p->M_LINEGAUGE);
            Bitwalker_Poke_Normal(addr, size, pos + 66,  7,  p->M_AXLELOADCAT);
            Bitwalker_Poke_Normal(addr, size, pos + 73,  4,  p->M_VOLTAGE);
            Bitwalker_Poke_Normal(addr, size, pos + 77,  10, p->NID_CTRACTION);
            Bitwalker_Poke_Normal(addr, size, pos + 87,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 92,  15, p->D_SUITABILITY(k));
            Bitwalker_Poke_Normal(addr, size, pos + 107, 2,  p->Q_SUITABILITY(k));
            Bitwalker_Poke_Normal(addr, size, pos + 109, 8,  p->M_LINEGAUGE(k));
            Bitwalker_Poke_Normal(addr, size, pos + 117, 7,  p->M_AXLELOADCAT(k));
            Bitwalker_Poke_Normal(addr, size, pos + 124, 4,  p->M_VOLTAGE(k));
            Bitwalker_Poke_Normal(addr, size, pos + 128, 10, p->NID_CTRACTION(k));

            stream->bitpos += ROUTE_SUITABILITY_DATA_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert Q_TRACKINIT:       EqualBits(stream, pos + 25,  pos + 26,  p->Q_TRACKINIT);
            //@ assert D_TRACKINIT:       EqualBits(stream, pos + 26,  pos + 41,  p->D_TRACKINIT);
            //@ assert D_SUITABILITY:     EqualBits(stream, pos + 41,  pos + 56,  p->D_SUITABILITY);
            //@ assert Q_SUITABILITY:     EqualBits(stream, pos + 56,  pos + 58,  p->Q_SUITABILITY);
            //@ assert M_LINEGAUGE:       EqualBits(stream, pos + 58,  pos + 66,  p->M_LINEGAUGE);
            //@ assert M_AXLELOADCAT:     EqualBits(stream, pos + 66,  pos + 73,  p->M_AXLELOADCAT);
            //@ assert M_VOLTAGE:         EqualBits(stream, pos + 73,  pos + 77,  p->M_VOLTAGE);
            //@ assert NID_CTRACTION:     EqualBits(stream, pos + 77,  pos + 87,  p->NID_CTRACTION);
            //@ assert N_ITER:            EqualBits(stream, pos + 87,  pos + 92,  p->N_ITER);
            //@ assert D_SUITABILITY(k):  EqualBits(stream, pos + 92,  pos + 107, p->D_SUITABILITY(k));
            //@ assert Q_SUITABILITY(k):  EqualBits(stream, pos + 107, pos + 109, p->Q_SUITABILITY(k));
            //@ assert M_LINEGAUGE(k):    EqualBits(stream, pos + 109, pos + 117, p->M_LINEGAUGE(k));
            //@ assert M_AXLELOADCAT(k):  EqualBits(stream, pos + 117, pos + 124, p->M_AXLELOADCAT(k));
            //@ assert M_VOLTAGE(k):      EqualBits(stream, pos + 124, pos + 128, p->M_VOLTAGE(k));
            //@ assert NID_CTRACTION(k):  EqualBits(stream, pos + 128, pos + 138, p->NID_CTRACTION(k));

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

