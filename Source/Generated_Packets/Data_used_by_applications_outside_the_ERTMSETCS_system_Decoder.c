
#include "Data_used_by_applications_outside_the_ERTMSETCS_system_Decoder.h"
#include "Bitstream_Read.h"

int Data_used_by_applications_outside_the_ERTMSETCS_system_Decoder(Bitstream* stream, Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p)
{
    if (NormalBitstream(stream, DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->NID_XUSER		= Bitstream_Read(stream, 9); }

        if (p->NID_XUSER == 102)
        {
	{ p->NID_NTC		= Bitstream_Read(stream, 8); }
        }

	{ p->Other_data_depending_on__NID_XUSER		= Bitstream_Read(stream, 8); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

