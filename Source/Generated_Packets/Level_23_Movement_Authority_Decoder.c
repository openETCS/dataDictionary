
#include "Level_23_Movement_Authority_Decoder.h"
#include "Bitstream_Read.h"
#include "Level_23_Movement_Authority_Core_1_Decoder.h"

int Level_23_Movement_Authority_Decoder(Bitstream* stream, Level_23_Movement_Authority_Core* p)
{
    if (NormalBitstream(stream, LEVEL_23_MOVEMENT_AUTHORITY_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	{ p->V_LOA		= Bitstream_Read(stream, 7); }

	{ p->T_LOA		= Bitstream_Read(stream, 10); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Level_23_Movement_Authority_Core_1_Decoder(stream, &(p->sub_1[i]));
        }
	{ p->L_ENDSECTION		= Bitstream_Read(stream, 15); }

	{ p->Q_SECTIONTIMER		= Bitstream_Read(stream, 1); }

	{ p->T_SECTIONTIMER		= Bitstream_Read(stream, 10); }

	{ p->D_SECTIONTIMERSTOPLOC		= Bitstream_Read(stream, 15); }

	{ p->Q_ENDTIMER		= Bitstream_Read(stream, 1); }

	{ p->T_ENDTIMER		= Bitstream_Read(stream, 10); }

	{ p->D_ENDTIMERSTARTLOC		= Bitstream_Read(stream, 15); }

	{ p->Q_DANGERPOINT		= Bitstream_Read(stream, 1); }

	{ p->D_DP		= Bitstream_Read(stream, 15); }

	{ p->V_RELEASEDP		= Bitstream_Read(stream, 7); }

	{ p->Q_OVERLAP		= Bitstream_Read(stream, 1); }

	{ p->D_STARTOL		= Bitstream_Read(stream, 15); }

	{ p->T_OL		= Bitstream_Read(stream, 10); }

	{ p->D_OL		= Bitstream_Read(stream, 15); }

	{ p->V_RELEASEOL		= Bitstream_Read(stream, 7); }



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

