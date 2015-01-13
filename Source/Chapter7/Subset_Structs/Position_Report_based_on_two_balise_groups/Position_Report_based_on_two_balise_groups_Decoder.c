
#include "Position_Report_based_on_two_balise_groups_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Position_Report_based_on_two_balise_groups_Decoder(Bitstream* stream, Position_Report_based_on_two_balise_groups* p)
{
    if (NormalBitstream(stream, POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->NID_PACKET         = Bitwalker_Peek_Normal(addr, size, pos,       8);
        p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 8,   13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 21,  2);
        p->NID_LRBG           = Bitwalker_Peek_Normal(addr, size, pos + 23,  24);
        p->NID_PRVLRBG        = Bitwalker_Peek_Normal(addr, size, pos + 47,  24);
        p->D_LRBG             = Bitwalker_Peek_Normal(addr, size, pos + 71,  15);
        p->Q_DIRLRBG          = Bitwalker_Peek_Normal(addr, size, pos + 86,  2);
        p->Q_DLRBG            = Bitwalker_Peek_Normal(addr, size, pos + 88,  2);
        p->L_DOUBTOVER        = Bitwalker_Peek_Normal(addr, size, pos + 90,  15);
        p->L_DOUBTUNDER       = Bitwalker_Peek_Normal(addr, size, pos + 105, 15);
        p->Q_LENGTH           = Bitwalker_Peek_Normal(addr, size, pos + 120, 2);
        p->L_TRAININT         = Bitwalker_Peek_Normal(addr, size, pos + 122, 15);
        p->V_TRAIN            = Bitwalker_Peek_Normal(addr, size, pos + 137, 7);
        p->Q_DIRTRAIN         = Bitwalker_Peek_Normal(addr, size, pos + 144, 2);
        p->M_MODE             = Bitwalker_Peek_Normal(addr, size, pos + 146, 4);
        p->M_LEVEL            = Bitwalker_Peek_Normal(addr, size, pos + 150, 3);
        p->NID_NTC            = Bitwalker_Peek_Normal(addr, size, pos + 153, 8);

        stream->bitpos += POSITION_REPORT_BASED_ON_TWO_BALISE_GROUPS_BITSIZE;

        //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
        //@ assert L_PACKET:          EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 21,  pos + 23,  p->Q_SCALE);
        //@ assert NID_LRBG:          EqualBits(stream, pos + 23,  pos + 47,  p->NID_LRBG);
        //@ assert NID_PRVLRBG:       EqualBits(stream, pos + 47,  pos + 71,  p->NID_PRVLRBG);
        //@ assert D_LRBG:            EqualBits(stream, pos + 71,  pos + 86,  p->D_LRBG);
        //@ assert Q_DIRLRBG:         EqualBits(stream, pos + 86,  pos + 88,  p->Q_DIRLRBG);
        //@ assert Q_DLRBG:           EqualBits(stream, pos + 88,  pos + 90,  p->Q_DLRBG);
        //@ assert L_DOUBTOVER:       EqualBits(stream, pos + 90,  pos + 105, p->L_DOUBTOVER);
        //@ assert L_DOUBTUNDER:      EqualBits(stream, pos + 105, pos + 120, p->L_DOUBTUNDER);
        //@ assert Q_LENGTH:          EqualBits(stream, pos + 120, pos + 122, p->Q_LENGTH);
        //@ assert L_TRAININT:        EqualBits(stream, pos + 122, pos + 137, p->L_TRAININT);
        //@ assert V_TRAIN:           EqualBits(stream, pos + 137, pos + 144, p->V_TRAIN);
        //@ assert Q_DIRTRAIN:        EqualBits(stream, pos + 144, pos + 146, p->Q_DIRTRAIN);
        //@ assert M_MODE:            EqualBits(stream, pos + 146, pos + 150, p->M_MODE);
        //@ assert M_LEVEL:           EqualBits(stream, pos + 150, pos + 153, p->M_LEVEL);
        //@ assert NID_NTC:           EqualBits(stream, pos + 153, pos + 161, p->NID_NTC);

        return 1;
    }
    else
    {
        return 0;
    }
}

