
#include "Danger_for_Shunting_information_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Danger_for_Shunting_information_UpperBitsNotSet(const Danger_for_Shunting_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_ASPECT,          1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Danger_for_Shunting_information_Encoder(Bitstream* stream, const Danger_for_Shunting_information_Core* p)
{
    if (NormalBitstream(stream, DANGER_FOR_SHUNTING_INFORMATION_CORE_BITSIZE))
    {
        if (Danger_for_Shunting_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_ASPECT);



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

int Danger_for_Shunting_information_Decoder(Bitstream* stream, Danger_for_Shunting_information_Core* p)
{
    if (NormalBitstream(stream, DANGER_FOR_SHUNTING_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_ASPECT		= Bitstream_Read(stream, 1); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

