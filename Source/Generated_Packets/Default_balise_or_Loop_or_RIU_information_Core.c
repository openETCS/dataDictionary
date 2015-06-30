
#include "Default_balise_or_Loop_or_RIU_information_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Default_balise_or_Loop_or_RIU_information_UpperBitsNotSet(const Default_balise_or_Loop_or_RIU_information_Core* p)
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

int Default_balise_or_Loop_or_RIU_information_Encoder(Bitstream* stream, const Default_balise_or_Loop_or_RIU_information_Core* p)
{
    if (NormalBitstream(stream, DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_BITSIZE))
    {
        if (Default_balise_or_Loop_or_RIU_information_UpperBitsNotSet(p))
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

int Default_balise_or_Loop_or_RIU_information_Decoder(Bitstream* stream, Default_balise_or_Loop_or_RIU_information_Core* p)
{
    if (NormalBitstream(stream, DEFAULT_BALISE_OR_LOOP_OR_RIU_INFORMATION_CORE_BITSIZE))
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

