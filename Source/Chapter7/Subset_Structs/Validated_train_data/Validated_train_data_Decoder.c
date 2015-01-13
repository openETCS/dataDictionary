
#include "Validated_train_data_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Validated_train_data_Decoder(Bitstream* stream, Validated_train_data* p)
{
    if (NormalBitstream(stream, VALIDATED_TRAIN_DATA_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 8,   13);
        p->NC_CDTRAIN         = Bitwalker_Peek_Normal(addr, size, pos + 21,  4);
        p->NC_TRAIN           = Bitwalker_Peek_Normal(addr, size, pos + 25,  15);
        p->L_TRAIN            = Bitwalker_Peek_Normal(addr, size, pos + 40,  12);
        p->V_MAXTRAIN         = Bitwalker_Peek_Normal(addr, size, pos + 52,  7);
        p->M_LOADINGGAUGE     = Bitwalker_Peek_Normal(addr, size, pos + 59,  8);
        p->M_AXLELOADCAT      = Bitwalker_Peek_Normal(addr, size, pos + 67,  7);
        p->M_AIRTIGHT         = Bitwalker_Peek_Normal(addr, size, pos + 74,  2);
        p->N_AXLE             = Bitwalker_Peek_Normal(addr, size, pos + 76,  10);
        p->N_ITER             = Bitwalker_Peek_Normal(addr, size, pos + 86,  5);
        p->M_VOLTAGE(k)       = Bitwalker_Peek_Normal(addr, size, pos + 91,  4);
        p->NID_CTRACTION(k)   = Bitwalker_Peek_Normal(addr, size, pos + 95,  10);
        p->N_ITER             = Bitwalker_Peek_Normal(addr, size, pos + 105, 5);
        p->NID_NTC(n)         = Bitwalker_Peek_Normal(addr, size, pos + 110, 8);

        stream->bitpos += VALIDATED_TRAIN_DATA_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
        //@ assert NC_CDTRAIN:        EqualBits(stream, pos + 21,  pos + 25,  p->NC_CDTRAIN);
        //@ assert NC_TRAIN:          EqualBits(stream, pos + 25,  pos + 40,  p->NC_TRAIN);
        //@ assert L_TRAIN:           EqualBits(stream, pos + 40,  pos + 52,  p->L_TRAIN);
        //@ assert V_MAXTRAIN:        EqualBits(stream, pos + 52,  pos + 59,  p->V_MAXTRAIN);
        //@ assert M_LOADINGGAUGE:    EqualBits(stream, pos + 59,  pos + 67,  p->M_LOADINGGAUGE);
        //@ assert M_AXLELOADCAT:     EqualBits(stream, pos + 67,  pos + 74,  p->M_AXLELOADCAT);
        //@ assert M_AIRTIGHT:        EqualBits(stream, pos + 74,  pos + 76,  p->M_AIRTIGHT);
        //@ assert N_AXLE:            EqualBits(stream, pos + 76,  pos + 86,  p->N_AXLE);
        //@ assert N_ITER:            EqualBits(stream, pos + 86,  pos + 91,  p->N_ITER);
        //@ assert M_VOLTAGE(k):      EqualBits(stream, pos + 91,  pos + 95,  p->M_VOLTAGE(k));
        //@ assert NID_CTRACTION(k):  EqualBits(stream, pos + 95,  pos + 105, p->NID_CTRACTION(k));
        //@ assert N_ITER:            EqualBits(stream, pos + 105, pos + 110, p->N_ITER);
        //@ assert NID_NTC(n):        EqualBits(stream, pos + 110, pos + 118, p->NID_NTC(n));

        return 1;
    }
    else
    {
        return 0;
    }
}

