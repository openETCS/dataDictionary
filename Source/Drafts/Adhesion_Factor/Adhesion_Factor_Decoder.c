
#include "Adhesion_Factor_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int Adhesion_Factor_Decoder(Bitstream* stream, Adhesion_Factor* p)
{
    if (NormalBitstream(stream, ADHESION_FACTOR_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitwalker_Peek_Normal(addr, size, pos,       2);
	p->L_PACKET           = Bitwalker_Peek_Normal(addr, size, pos + 2,   13);
        p->Q_SCALE            = Bitwalker_Peek_Normal(addr, size, pos + 15,  2);
        p->D_ADHESION         = Bitwalker_Peek_Normal(addr, size, pos + 17,  15);
        p->L_ADHESION         = Bitwalker_Peek_Normal(addr, size, pos + 32,  15);
        p->M_ADHESION         = Bitwalker_Peek_Normal(addr, size, pos + 47,  1);

        stream->bitpos += ADHESION_FACTOR_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
	//@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_ADHESION:        EqualBits(stream, pos + 17,  pos + 32,  p->D_ADHESION);
        //@ assert L_ADHESION:        EqualBits(stream, pos + 32,  pos + 47,  p->L_ADHESION);
        //@ assert M_ADHESION:        EqualBits(stream, pos + 47,  pos + 48,  p->M_ADHESION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
	//@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_ADHESION:        UpperBitsNotSet(p->D_ADHESION,        15);
        //@ assert L_ADHESION:        UpperBitsNotSet(p->L_ADHESION,        15);
        //@ assert M_ADHESION:        UpperBitsNotSet(p->M_ADHESION,        1);

        return 1;
    }
    else
    {
        return 0;
    }
}

