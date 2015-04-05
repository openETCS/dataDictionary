
#include "Adhesion_Factor_Decoder.h"
#include "Bitstream_Read.h"

int Adhesion_Factor_Decoder(Bitstream* stream, Adhesion_Factor* p)
{
    if (NormalBitstream(stream, ADHESION_FACTOR_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        p->Q_DIR              = Bitstream_Read(stream, 2);
        //@ assert Q_DIR:     stream->bitpos == pos + 2;
        //@ assert Q_DIR:     EqualBits(stream, pos,       pos + 2,   p->Q_DIR);

	p->L_PACKET           = Bitstream_Read(stream, 13);
        //@ assert L_PACKET:  stream->bitpos == pos + 15;
	//@ assert L_PACKET:  EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

        p->Q_SCALE            = Bitstream_Read(stream, 2);
        //@ assert Q_SCALE:   stream->bitpos == pos + 17;
        //@ assert Q_SCALE:   EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);

        p->D_ADHESION         = Bitstream_Read(stream, 15);
        //@ assert D_ADHESION:   stream->bitpos == pos + 32;
        //@ assert D_ADHESION:   EqualBits(stream, pos + 17,  pos + 32,  p->D_ADHESION);

        p->L_ADHESION         = Bitstream_Read(stream, 15);
        //@ assert L_ADHESION:   stream->bitpos == pos + 47;
        //@ assert L_ADHESION:   EqualBits(stream, pos + 32,  pos + 47,  p->L_ADHESION);

        p->M_ADHESION         = Bitstream_Read(stream, 1);
        //@ assert M_ADHESION:   stream->bitpos == pos + 48;
        //@ assert M_ADHESION:   EqualBits(stream, pos + 47,  pos + 48,  p->M_ADHESION);

        //@ assert stream->bitpos == \at(stream->bitpos,Pre) + ADHESION_FACTOR_BITSIZE;


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

