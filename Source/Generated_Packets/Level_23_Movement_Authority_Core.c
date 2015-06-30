
#include "Level_23_Movement_Authority_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Level_23_Movement_Authority_UpperBitsNotSet(const Level_23_Movement_Authority_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->V_LOA,             7) ;
    status = status && UpperBitsNotSet64(p->T_LOA,             10);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Level_23_Movement_Authority_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->L_ENDSECTION,      15);
    status = status && UpperBitsNotSet64(p->Q_SECTIONTIMER,    1) ;
    status = status && UpperBitsNotSet64(p->T_SECTIONTIMER,    10);
    status = status && UpperBitsNotSet64(p->D_SECTIONTIMERSTOPLOC, 15);
    status = status && UpperBitsNotSet64(p->Q_ENDTIMER,        1) ;
    status = status && UpperBitsNotSet64(p->T_ENDTIMER,        10);
    status = status && UpperBitsNotSet64(p->D_ENDTIMERSTARTLOC, 15);
    status = status && UpperBitsNotSet64(p->Q_DANGERPOINT,     1) ;
    status = status && UpperBitsNotSet64(p->D_DP,              15);
    status = status && UpperBitsNotSet64(p->V_RELEASEDP,       7) ;
    status = status && UpperBitsNotSet64(p->Q_OVERLAP,         1) ;
    status = status && UpperBitsNotSet64(p->D_STARTOL,         15);
    status = status && UpperBitsNotSet64(p->T_OL,              10);
    status = status && UpperBitsNotSet64(p->D_OL,              15);
    status = status && UpperBitsNotSet64(p->V_RELEASEOL,       7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Level_23_Movement_Authority_Encoder(Bitstream* stream, const Level_23_Movement_Authority_Core* p)
{
    if (NormalBitstream(stream, LEVEL_23_MOVEMENT_AUTHORITY_CORE_BITSIZE))
    {
        if (Level_23_Movement_Authority_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 7,  p->V_LOA);
            Bitstream_Write(stream, 10, p->T_LOA);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Level_23_Movement_Authority_Core_1_Encoder(stream, &(p->sub_1[i]));
            }
            Bitstream_Write(stream, 15, p->L_ENDSECTION);
            Bitstream_Write(stream, 1,  p->Q_SECTIONTIMER);
            Bitstream_Write(stream, 10, p->T_SECTIONTIMER);
            Bitstream_Write(stream, 15, p->D_SECTIONTIMERSTOPLOC);
            Bitstream_Write(stream, 1,  p->Q_ENDTIMER);
            Bitstream_Write(stream, 10, p->T_ENDTIMER);
            Bitstream_Write(stream, 15, p->D_ENDTIMERSTARTLOC);
            Bitstream_Write(stream, 1,  p->Q_DANGERPOINT);
            Bitstream_Write(stream, 15, p->D_DP);
            Bitstream_Write(stream, 7,  p->V_RELEASEDP);
            Bitstream_Write(stream, 1,  p->Q_OVERLAP);
            Bitstream_Write(stream, 15, p->D_STARTOL);
            Bitstream_Write(stream, 10, p->T_OL);
            Bitstream_Write(stream, 15, p->D_OL);
            Bitstream_Write(stream, 7,  p->V_RELEASEOL);



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

