
#include "Stop_Shunting_on_desk_opening_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Stop_Shunting_on_desk_opening_UpperBitsNotSet(const Stop_Shunting_on_desk_opening_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stop_Shunting_on_desk_opening_Encoder(Bitstream* stream, const Stop_Shunting_on_desk_opening_Core* p)
{
    if (NormalBitstream(stream, STOP_SHUNTING_ON_DESK_OPENING_CORE_BITSIZE))
    {
        if (Stop_Shunting_on_desk_opening_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);



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

int Stop_Shunting_on_desk_opening_Decoder(Bitstream* stream, Stop_Shunting_on_desk_opening_Core* p)
{
    if (NormalBitstream(stream, STOP_SHUNTING_ON_DESK_OPENING_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

