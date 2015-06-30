
#include "EOLM_Packet_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int EOLM_Packet_UpperBitsNotSet(const EOLM_Packet_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->NID_LOOP,          14);
    status = status && UpperBitsNotSet64(p->D_LOOP,            15);
    status = status && UpperBitsNotSet64(p->L_LOOP,            15);
    status = status && UpperBitsNotSet64(p->Q_LOOPDIR,         1) ;
    status = status && UpperBitsNotSet64(p->Q_SSCODE,          4) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int EOLM_Packet_Encoder(Bitstream* stream, const EOLM_Packet_Core* p)
{
    if (NormalBitstream(stream, EOLM_PACKET_CORE_BITSIZE))
    {
        if (EOLM_Packet_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 14, p->NID_LOOP);
            Bitstream_Write(stream, 15, p->D_LOOP);
            Bitstream_Write(stream, 15, p->L_LOOP);
            Bitstream_Write(stream, 1,  p->Q_LOOPDIR);
            Bitstream_Write(stream, 4,  p->Q_SSCODE);



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

int EOLM_Packet_Decoder(Bitstream* stream, EOLM_Packet_Core* p)
{
    if (NormalBitstream(stream, EOLM_PACKET_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->NID_LOOP		= Bitstream_Read(stream, 14); }

	{ p->D_LOOP		= Bitstream_Read(stream, 15); }

	{ p->L_LOOP		= Bitstream_Read(stream, 15); }

	{ p->Q_LOOPDIR		= Bitstream_Read(stream, 1); }

	{ p->Q_SSCODE		= Bitstream_Read(stream, 4); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

