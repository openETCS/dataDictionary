
#include "Level_1_Movement_Authority_Core_1_Decoder.h"
#include "Bitstream_Read.h"

int Level_1_Movement_Authority_Core_1_Decoder(Bitstream* stream, Level_1_Movement_Authority_Core_1* p)
{
    if (NormalBitstream(stream, LEVEL_1_MOVEMENT_AUTHORITY_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->L_SECTION_k		= Bitstream_Read(stream, 15); }

	{ p->Q_SECTIONTIMER_k		= Bitstream_Read(stream, 1); }

	{ p->T_SECTIONTIMER_k		= Bitstream_Read(stream, 10); }

	{ p->D_SECTIONTIMERSTOPLOC_k		= Bitstream_Read(stream, 15); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

