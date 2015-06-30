
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


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert V_LOA:             EqualBits(stream, pos + 17,  pos + 24,  p->V_LOA);
            //@ assert T_LOA:             EqualBits(stream, pos + 24,  pos + 34,  p->T_LOA);
            //@ assert L_ENDSECTION:      EqualBits(stream, pos + 80,  pos + 95,  p->L_ENDSECTION);
            //@ assert Q_SECTIONTIMER:    EqualBits(stream, pos + 95,  pos + 96,  p->Q_SECTIONTIMER);
            //@ assert T_SECTIONTIMER:    EqualBits(stream, pos + 96,  pos + 106, p->T_SECTIONTIMER);
            //@ assert D_SECTIONTIMERSTOPLOC: EqualBits(stream, pos + 106, pos + 121, p->D_SECTIONTIMERSTOPLOC);
            //@ assert Q_ENDTIMER:        EqualBits(stream, pos + 121, pos + 122, p->Q_ENDTIMER);
            //@ assert T_ENDTIMER:        EqualBits(stream, pos + 122, pos + 132, p->T_ENDTIMER);
            //@ assert D_ENDTIMERSTARTLOC: EqualBits(stream, pos + 132, pos + 147, p->D_ENDTIMERSTARTLOC);
            //@ assert Q_DANGERPOINT:     EqualBits(stream, pos + 147, pos + 148, p->Q_DANGERPOINT);
            //@ assert D_DP:              EqualBits(stream, pos + 148, pos + 163, p->D_DP);
            //@ assert V_RELEASEDP:       EqualBits(stream, pos + 163, pos + 170, p->V_RELEASEDP);
            //@ assert Q_OVERLAP:         EqualBits(stream, pos + 170, pos + 171, p->Q_OVERLAP);
            //@ assert D_STARTOL:         EqualBits(stream, pos + 171, pos + 186, p->D_STARTOL);
            //@ assert T_OL:              EqualBits(stream, pos + 186, pos + 196, p->T_OL);
            //@ assert D_OL:              EqualBits(stream, pos + 196, pos + 211, p->D_OL);
            //@ assert V_RELEASEOL:       EqualBits(stream, pos + 211, pos + 218, p->V_RELEASEOL);

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

	/*@
	  requires Q_DIR:          stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_DIR;
	  ensures  Q_DIR:          stream->bitpos == pos + 2;
	  ensures  Q_DIR:          EqualBits(stream, pos + 0, pos + 2, p->Q_DIR);
	  ensures  Q_DIR:          UpperBitsNotSet(p->Q_DIR, 2);
	*/
	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	/*@
	  requires L_PACKET:       stream->bitpos == pos + 2;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_PACKET;
	  ensures  L_PACKET:       stream->bitpos == pos + 15;
	  ensures  L_PACKET:       EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
	  ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
	*/
	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	/*@
	  requires Q_SCALE:        stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_SCALE;
	  ensures  Q_SCALE:        stream->bitpos == pos + 17;
	  ensures  Q_SCALE:        EqualBits(stream, pos + 15, pos + 17, p->Q_SCALE);
	  ensures  Q_SCALE:        UpperBitsNotSet(p->Q_SCALE, 2);
	*/
	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	/*@
	  requires V_LOA:          stream->bitpos == pos + 17;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_LOA;
	  ensures  V_LOA:          stream->bitpos == pos + 24;
	  ensures  V_LOA:          EqualBits(stream, pos + 17, pos + 24, p->V_LOA);
	  ensures  V_LOA:          UpperBitsNotSet(p->V_LOA, 7);
	*/
	{ p->V_LOA		= Bitstream_Read(stream, 7); }

	/*@
	  requires T_LOA:          stream->bitpos == pos + 24;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_LOA;
	  ensures  T_LOA:          stream->bitpos == pos + 34;
	  ensures  T_LOA:          EqualBits(stream, pos + 24, pos + 34, p->T_LOA);
	  ensures  T_LOA:          UpperBitsNotSet(p->T_LOA, 10);
	*/
	{ p->T_LOA		= Bitstream_Read(stream, 10); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Level_23_Movement_Authority_Core_1_Decoder(stream, &(p->sub_1[i]));
        }
	/*@
	  requires L_ENDSECTION:   stream->bitpos == pos + 80;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_ENDSECTION;
	  ensures  L_ENDSECTION:   stream->bitpos == pos + 95;
	  ensures  L_ENDSECTION:   EqualBits(stream, pos + 80, pos + 95, p->L_ENDSECTION);
	  ensures  L_ENDSECTION:   UpperBitsNotSet(p->L_ENDSECTION, 15);
	*/
	{ p->L_ENDSECTION		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_SECTIONTIMER: stream->bitpos == pos + 95;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_SECTIONTIMER;
	  ensures  Q_SECTIONTIMER: stream->bitpos == pos + 96;
	  ensures  Q_SECTIONTIMER: EqualBits(stream, pos + 95, pos + 96, p->Q_SECTIONTIMER);
	  ensures  Q_SECTIONTIMER: UpperBitsNotSet(p->Q_SECTIONTIMER, 1);
	*/
	{ p->Q_SECTIONTIMER		= Bitstream_Read(stream, 1); }

	/*@
	  requires T_SECTIONTIMER: stream->bitpos == pos + 96;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_SECTIONTIMER;
	  ensures  T_SECTIONTIMER: stream->bitpos == pos + 106;
	  ensures  T_SECTIONTIMER: EqualBits(stream, pos + 96, pos + 106, p->T_SECTIONTIMER);
	  ensures  T_SECTIONTIMER: UpperBitsNotSet(p->T_SECTIONTIMER, 10);
	*/
	{ p->T_SECTIONTIMER		= Bitstream_Read(stream, 10); }

	/*@
	  requires D_SECTIONTIMERSTOPLOC: stream->bitpos == pos + 106;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_SECTIONTIMERSTOPLOC;
	  ensures  D_SECTIONTIMERSTOPLOC: stream->bitpos == pos + 121;
	  ensures  D_SECTIONTIMERSTOPLOC: EqualBits(stream, pos + 106, pos + 121, p->D_SECTIONTIMERSTOPLOC);
	  ensures  D_SECTIONTIMERSTOPLOC: UpperBitsNotSet(p->D_SECTIONTIMERSTOPLOC, 15);
	*/
	{ p->D_SECTIONTIMERSTOPLOC		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_ENDTIMER:     stream->bitpos == pos + 121;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_ENDTIMER;
	  ensures  Q_ENDTIMER:     stream->bitpos == pos + 122;
	  ensures  Q_ENDTIMER:     EqualBits(stream, pos + 121, pos + 122, p->Q_ENDTIMER);
	  ensures  Q_ENDTIMER:     UpperBitsNotSet(p->Q_ENDTIMER, 1);
	*/
	{ p->Q_ENDTIMER		= Bitstream_Read(stream, 1); }

	/*@
	  requires T_ENDTIMER:     stream->bitpos == pos + 122;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_ENDTIMER;
	  ensures  T_ENDTIMER:     stream->bitpos == pos + 132;
	  ensures  T_ENDTIMER:     EqualBits(stream, pos + 122, pos + 132, p->T_ENDTIMER);
	  ensures  T_ENDTIMER:     UpperBitsNotSet(p->T_ENDTIMER, 10);
	*/
	{ p->T_ENDTIMER		= Bitstream_Read(stream, 10); }

	/*@
	  requires D_ENDTIMERSTARTLOC: stream->bitpos == pos + 132;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_ENDTIMERSTARTLOC;
	  ensures  D_ENDTIMERSTARTLOC: stream->bitpos == pos + 147;
	  ensures  D_ENDTIMERSTARTLOC: EqualBits(stream, pos + 132, pos + 147, p->D_ENDTIMERSTARTLOC);
	  ensures  D_ENDTIMERSTARTLOC: UpperBitsNotSet(p->D_ENDTIMERSTARTLOC, 15);
	*/
	{ p->D_ENDTIMERSTARTLOC		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_DANGERPOINT:  stream->bitpos == pos + 147;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_DANGERPOINT;
	  ensures  Q_DANGERPOINT:  stream->bitpos == pos + 148;
	  ensures  Q_DANGERPOINT:  EqualBits(stream, pos + 147, pos + 148, p->Q_DANGERPOINT);
	  ensures  Q_DANGERPOINT:  UpperBitsNotSet(p->Q_DANGERPOINT, 1);
	*/
	{ p->Q_DANGERPOINT		= Bitstream_Read(stream, 1); }

	/*@
	  requires D_DP:           stream->bitpos == pos + 148;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_DP;
	  ensures  D_DP:           stream->bitpos == pos + 163;
	  ensures  D_DP:           EqualBits(stream, pos + 148, pos + 163, p->D_DP);
	  ensures  D_DP:           UpperBitsNotSet(p->D_DP, 15);
	*/
	{ p->D_DP		= Bitstream_Read(stream, 15); }

	/*@
	  requires V_RELEASEDP:    stream->bitpos == pos + 163;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_RELEASEDP;
	  ensures  V_RELEASEDP:    stream->bitpos == pos + 170;
	  ensures  V_RELEASEDP:    EqualBits(stream, pos + 163, pos + 170, p->V_RELEASEDP);
	  ensures  V_RELEASEDP:    UpperBitsNotSet(p->V_RELEASEDP, 7);
	*/
	{ p->V_RELEASEDP		= Bitstream_Read(stream, 7); }

	/*@
	  requires Q_OVERLAP:      stream->bitpos == pos + 170;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_OVERLAP;
	  ensures  Q_OVERLAP:      stream->bitpos == pos + 171;
	  ensures  Q_OVERLAP:      EqualBits(stream, pos + 170, pos + 171, p->Q_OVERLAP);
	  ensures  Q_OVERLAP:      UpperBitsNotSet(p->Q_OVERLAP, 1);
	*/
	{ p->Q_OVERLAP		= Bitstream_Read(stream, 1); }

	/*@
	  requires D_STARTOL:      stream->bitpos == pos + 171;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_STARTOL;
	  ensures  D_STARTOL:      stream->bitpos == pos + 186;
	  ensures  D_STARTOL:      EqualBits(stream, pos + 171, pos + 186, p->D_STARTOL);
	  ensures  D_STARTOL:      UpperBitsNotSet(p->D_STARTOL, 15);
	*/
	{ p->D_STARTOL		= Bitstream_Read(stream, 15); }

	/*@
	  requires T_OL:           stream->bitpos == pos + 186;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_OL;
	  ensures  T_OL:           stream->bitpos == pos + 196;
	  ensures  T_OL:           EqualBits(stream, pos + 186, pos + 196, p->T_OL);
	  ensures  T_OL:           UpperBitsNotSet(p->T_OL, 10);
	*/
	{ p->T_OL		= Bitstream_Read(stream, 10); }

	/*@
	  requires D_OL:           stream->bitpos == pos + 196;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_OL;
	  ensures  D_OL:           stream->bitpos == pos + 211;
	  ensures  D_OL:           EqualBits(stream, pos + 196, pos + 211, p->D_OL);
	  ensures  D_OL:           UpperBitsNotSet(p->D_OL, 15);
	*/
	{ p->D_OL		= Bitstream_Read(stream, 15); }

	/*@
	  requires V_RELEASEOL:    stream->bitpos == pos + 211;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_RELEASEOL;
	  ensures  V_RELEASEOL:    stream->bitpos == pos + 218;
	  ensures  V_RELEASEOL:    EqualBits(stream, pos + 211, pos + 218, p->V_RELEASEOL);
	  ensures  V_RELEASEOL:    UpperBitsNotSet(p->V_RELEASEOL, 7);
	*/
	{ p->V_RELEASEOL		= Bitstream_Read(stream, 7); }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert V_LOA:             EqualBits(stream, pos + 17,  pos + 24,  p->V_LOA);
        //@ assert T_LOA:             EqualBits(stream, pos + 24,  pos + 34,  p->T_LOA);
        //@ assert L_ENDSECTION:      EqualBits(stream, pos + 80,  pos + 95,  p->L_ENDSECTION);
        //@ assert Q_SECTIONTIMER:    EqualBits(stream, pos + 95,  pos + 96,  p->Q_SECTIONTIMER);
        //@ assert T_SECTIONTIMER:    EqualBits(stream, pos + 96,  pos + 106, p->T_SECTIONTIMER);
        //@ assert D_SECTIONTIMERSTOPLOC: EqualBits(stream, pos + 106, pos + 121, p->D_SECTIONTIMERSTOPLOC);
        //@ assert Q_ENDTIMER:        EqualBits(stream, pos + 121, pos + 122, p->Q_ENDTIMER);
        //@ assert T_ENDTIMER:        EqualBits(stream, pos + 122, pos + 132, p->T_ENDTIMER);
        //@ assert D_ENDTIMERSTARTLOC: EqualBits(stream, pos + 132, pos + 147, p->D_ENDTIMERSTARTLOC);
        //@ assert Q_DANGERPOINT:     EqualBits(stream, pos + 147, pos + 148, p->Q_DANGERPOINT);
        //@ assert D_DP:              EqualBits(stream, pos + 148, pos + 163, p->D_DP);
        //@ assert V_RELEASEDP:       EqualBits(stream, pos + 163, pos + 170, p->V_RELEASEDP);
        //@ assert Q_OVERLAP:         EqualBits(stream, pos + 170, pos + 171, p->Q_OVERLAP);
        //@ assert D_STARTOL:         EqualBits(stream, pos + 171, pos + 186, p->D_STARTOL);
        //@ assert T_OL:              EqualBits(stream, pos + 186, pos + 196, p->T_OL);
        //@ assert D_OL:              EqualBits(stream, pos + 196, pos + 211, p->D_OL);
        //@ assert V_RELEASEOL:       EqualBits(stream, pos + 211, pos + 218, p->V_RELEASEOL);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert V_LOA:             UpperBitsNotSet(p->V_LOA,             7);
        //@ assert T_LOA:             UpperBitsNotSet(p->T_LOA,             10);
        //@ assert L_ENDSECTION:      UpperBitsNotSet(p->L_ENDSECTION,      15);
        //@ assert Q_SECTIONTIMER:    UpperBitsNotSet(p->Q_SECTIONTIMER,    1);
        //@ assert T_SECTIONTIMER:    UpperBitsNotSet(p->T_SECTIONTIMER,    10);
        //@ assert D_SECTIONTIMERSTOPLOC: UpperBitsNotSet(p->D_SECTIONTIMERSTOPLOC, 15);
        //@ assert Q_ENDTIMER:        UpperBitsNotSet(p->Q_ENDTIMER,        1);
        //@ assert T_ENDTIMER:        UpperBitsNotSet(p->T_ENDTIMER,        10);
        //@ assert D_ENDTIMERSTARTLOC: UpperBitsNotSet(p->D_ENDTIMERSTARTLOC, 15);
        //@ assert Q_DANGERPOINT:     UpperBitsNotSet(p->Q_DANGERPOINT,     1);
        //@ assert D_DP:              UpperBitsNotSet(p->D_DP,              15);
        //@ assert V_RELEASEDP:       UpperBitsNotSet(p->V_RELEASEDP,       7);
        //@ assert Q_OVERLAP:         UpperBitsNotSet(p->Q_OVERLAP,         1);
        //@ assert D_STARTOL:         UpperBitsNotSet(p->D_STARTOL,         15);
        //@ assert T_OL:              UpperBitsNotSet(p->T_OL,              10);
        //@ assert D_OL:              UpperBitsNotSet(p->D_OL,              15);
        //@ assert V_RELEASEOL:       UpperBitsNotSet(p->V_RELEASEOL,       7);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

