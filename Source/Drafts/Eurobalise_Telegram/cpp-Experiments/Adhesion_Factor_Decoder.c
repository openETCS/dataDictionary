
#include "Adhesion_Factor_Decoder.h"
#include "Bitstream_Read.h"

int Adhesion_Factor_Decoder(Bitstream* stream, Adhesion_Factor_Core* p)
{
    if (NormalBitstream(stream, ADHESION_FACTOR_CORE_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

        /*@
           requires Q_DIR: stream->bitpos == pos;
           assigns         stream->bitpos;
           assigns         p->Q_DIR;
           ensures  Q_DIR: stream->bitpos == pos + 2;
           ensures  Q_DIR: EqualBits(stream, pos, pos + 2, p->Q_DIR);
           ensures  Q_DIR: UpperBitsNotSet(p->Q_DIR, 2);
        */
        { p->Q_DIR              = Bitstream_Read(stream, 2); }

	/*@
           requires L_PACKET: stream->bitpos == pos + 2;
           assigns            stream->bitpos;
           assigns            p->L_PACKET;
           ensures  L_PACKET: stream->bitpos == pos + 15;
           ensures  L_PACKET: EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
	   ensures  L_PACKET: UpperBitsNotSet(p->L_PACKET, 13);
        */
        { p->L_PACKET           = Bitstream_Read(stream, 13); }

        /*@
           requires Q_SCALE: stream->bitpos == pos + 15;
           assigns           stream->bitpos;
           assigns         p->Q_SCALE;
           ensures  Q_SCALE: stream->bitpos == pos + 17;
           ensures  Q_SCALE: EqualBits(stream, pos + 15, pos + 17, p->Q_SCALE);
	   ensures  Q_SCALE: UpperBitsNotSet(p->Q_SCALE, 2);
        */
        { p->Q_SCALE            = Bitstream_Read(stream, 2); }

        /*@
           requires D_ADHESION: stream->bitpos == pos + 17;
           assigns              stream->bitpos;
           assigns              p->D_ADHESION;
           ensures  D_ADHESION: stream->bitpos == pos + 32;
           ensures  D_ADHESION: EqualBits(stream, pos + 17, pos + 32, p->D_ADHESION);
	   ensures  D_ADHESION: UpperBitsNotSet(p->D_ADHESION, 15);
        */
        { p->D_ADHESION         = Bitstream_Read(stream, 15); }

        /*@
           requires L_ADHESION: stream->bitpos == pos + 32;
           assigns              stream->bitpos;
           assigns              p->L_ADHESION;
           ensures  L_ADHESION: stream->bitpos == pos + 47;
           ensures  L_ADHESION: EqualBits(stream, pos + 32, pos + 47, p->L_ADHESION);
	   ensures  L_ADHESION: UpperBitsNotSet(p->L_ADHESION, 15);
        */
        { p->L_ADHESION         = Bitstream_Read(stream, 15); }

        /*@
           requires M_ADHESION: stream->bitpos == pos + 47;
           assigns              stream->bitpos;
           assigns              p->M_ADHESION;
           ensures  M_ADHESION: stream->bitpos == pos + 48;
           ensures  M_ADHESION: EqualBits(stream, pos + 47, pos + 48, p->M_ADHESION);
	   ensures  M_ADHESION: UpperBitsNotSet(p->M_ADHESION, 1);
        */
        { p->M_ADHESION         = Bitstream_Read(stream, 1); }

        //@ assert stream->bitpos == \at(stream->bitpos,Pre) + ADHESION_FACTOR_CORE_BITSIZE;

        //@ assert Q_DIR:             EqualBits(stream, pos, pos + 2, p->Q_DIR);
        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);

        //@ assert L_PACKET:          EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
	//@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);

        //@ assert Q_SCALE:           EqualBits(stream, pos + 15, pos + 17, p->Q_SCALE);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);

        //@ assert D_ADHESION:        EqualBits(stream, pos + 17, pos + 32, p->D_ADHESION);
        //@ assert D_ADHESION:        UpperBitsNotSet(p->D_ADHESION,        15);

        //@ assert L_ADHESION:        EqualBits(stream, pos + 32, pos + 47, p->L_ADHESION);
        //@ assert L_ADHESION:        UpperBitsNotSet(p->L_ADHESION,        15);

        //@ assert M_ADHESION:        EqualBits(stream, pos + 47, pos + 48, p->M_ADHESION);
        //@ assert M_ADHESION:        UpperBitsNotSet(p->M_ADHESION,        1);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

