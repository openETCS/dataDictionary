
#include "Level_23_transition_information_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Level_23_transition_information_UpperBitsNotSet(const Level_23_transition_information_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_LTRBG,         24);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Level_23_transition_information_Encoder(Bitstream* stream, const Level_23_transition_information_Core* p)
{
    if (NormalBitstream(stream, LEVEL_23_TRANSITION_INFORMATION_CORE_BITSIZE))
    {
        if (Level_23_transition_information_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 24, p->NID_LTRBG);



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

int Level_23_transition_information_Decoder(Bitstream* stream, Level_23_transition_information_Core* p)
{
    if (NormalBitstream(stream, LEVEL_23_TRANSITION_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->NID_LTRBG		= Bitstream_Read(stream, 24); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

