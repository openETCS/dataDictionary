
#include "Position_Report_Parameters_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Position_Report_Parameters_Decoder(Bitstream* stream, Position_Report_Parameters* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_PARAMETERS_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos + 8,   2);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 10,  13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 23,  2);
        p->T_CYCLOC           = Bitwalker_Peek_Normal(addr, size, pos + 25,  8);
        p->D_CYCLOC           = Bitwalker_Peek_Normal(addr, size, pos + 33,  15);
        p->M_LOC              = Bitwalker_Peek_Normal(addr, size, pos + 48,  3);
        p->N_ITER             = Bitwalker_Peek_Normal(addr, size, pos + 51,  5);
        p->D_LOC(k)           = Bitwalker_Peek_Normal(addr, size, pos + 56,  15);
        p->Q_LGTLOC(k)        = Bitwalker_Peek_Normal(addr, size, pos + 71,  1);

        stream->bitpos += POSITION_REPORT_PARAMETERS_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
        //@ assert T_CYCLOC:          EqualBits(stream, pos + 25,  pos + 33,  p->T_CYCLOC);
        //@ assert D_CYCLOC:          EqualBits(stream, pos + 33,  pos + 48,  p->D_CYCLOC);
        //@ assert M_LOC:             EqualBits(stream, pos + 48,  pos + 51,  p->M_LOC);
        //@ assert N_ITER:            EqualBits(stream, pos + 51,  pos + 56,  p->N_ITER);
        //@ assert D_LOC(k):          EqualBits(stream, pos + 56,  pos + 71,  p->D_LOC(k));
        //@ assert Q_LGTLOC(k):       EqualBits(stream, pos + 71,  pos + 72,  p->Q_LGTLOC(k));

        return 1;
    }
    else
    {
        return 0;
    }
}

