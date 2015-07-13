
#include "Level_1_Movement_Authority_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Level_1_Movement_Authority_UpperBitsNotSet(const Level_1_Movement_Authority_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->V_MAIN,            7) ;
    status = status && UpperBitsNotSet64(p->V_LOA,             7) ;
    status = status && UpperBitsNotSet64(p->T_LOA,             10);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Level_1_Movement_Authority_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int Level_1_Movement_Authority_Encoder(Bitstream* stream, const Level_1_Movement_Authority_Core* p)
{
    if (NormalBitstream(stream, LEVEL_1_MOVEMENT_AUTHORITY_CORE_BITSIZE))
    {
        if (Level_1_Movement_Authority_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 7,  p->V_MAIN);
            Bitstream_Write(stream, 7,  p->V_LOA);
            Bitstream_Write(stream, 10, p->T_LOA);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Level_1_Movement_Authority_Core_1_Encoder(stream, &(p->sub_1[i]));
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
            //@ assert V_MAIN:            EqualBits(stream, pos + 17,  pos + 24,  p->V_MAIN);
            //@ assert V_LOA:             EqualBits(stream, pos + 24,  pos + 31,  p->V_LOA);
            //@ assert T_LOA:             EqualBits(stream, pos + 31,  pos + 41,  p->T_LOA);
            //@ assert L_ENDSECTION:      EqualBits(stream, pos + 41,  pos + 56,  p->L_ENDSECTION);
            //@ assert Q_SECTIONTIMER:    EqualBits(stream, pos + 56,  pos + 57,  p->Q_SECTIONTIMER);
            //@ assert T_SECTIONTIMER:    EqualBits(stream, pos + 57,  pos + 67,  p->T_SECTIONTIMER);
            //@ assert D_SECTIONTIMERSTOPLOC: EqualBits(stream, pos + 67,  pos + 82,  p->D_SECTIONTIMERSTOPLOC);
            //@ assert Q_ENDTIMER:        EqualBits(stream, pos + 82,  pos + 83,  p->Q_ENDTIMER);
            //@ assert T_ENDTIMER:        EqualBits(stream, pos + 83,  pos + 93,  p->T_ENDTIMER);
            //@ assert D_ENDTIMERSTARTLOC: EqualBits(stream, pos + 93,  pos + 108, p->D_ENDTIMERSTARTLOC);
            //@ assert Q_DANGERPOINT:     EqualBits(stream, pos + 108, pos + 109, p->Q_DANGERPOINT);
            //@ assert D_DP:              EqualBits(stream, pos + 109, pos + 124, p->D_DP);
            //@ assert V_RELEASEDP:       EqualBits(stream, pos + 124, pos + 131, p->V_RELEASEDP);
            //@ assert Q_OVERLAP:         EqualBits(stream, pos + 131, pos + 132, p->Q_OVERLAP);
            //@ assert D_STARTOL:         EqualBits(stream, pos + 132, pos + 147, p->D_STARTOL);
            //@ assert T_OL:              EqualBits(stream, pos + 147, pos + 157, p->T_OL);
            //@ assert D_OL:              EqualBits(stream, pos + 157, pos + 172, p->D_OL);
            //@ assert V_RELEASEOL:       EqualBits(stream, pos + 172, pos + 179, p->V_RELEASEOL);

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

int Level_1_Movement_Authority_Decoder(Bitstream* stream, Level_1_Movement_Authority_Core* p)
{
    if (NormalBitstream(stream, LEVEL_1_MOVEMENT_AUTHORITY_CORE_BITSIZE))
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
	  requires V_MAIN:         stream->bitpos == pos + 17;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_MAIN;
	  ensures  V_MAIN:         stream->bitpos == pos + 24;
	  ensures  V_MAIN:         EqualBits(stream, pos + 17, pos + 24, p->V_MAIN);
	  ensures  V_MAIN:         UpperBitsNotSet(p->V_MAIN, 7);
	*/
	{ p->V_MAIN		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_LOA:          stream->bitpos == pos + 24;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_LOA;
	  ensures  V_LOA:          stream->bitpos == pos + 31;
	  ensures  V_LOA:          EqualBits(stream, pos + 24, pos + 31, p->V_LOA);
	  ensures  V_LOA:          UpperBitsNotSet(p->V_LOA, 7);
	*/
	{ p->V_LOA		= Bitstream_Read(stream, 7); }

	/*@
	  requires T_LOA:          stream->bitpos == pos + 31;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_LOA;
	  ensures  T_LOA:          stream->bitpos == pos + 41;
	  ensures  T_LOA:          EqualBits(stream, pos + 31, pos + 41, p->T_LOA);
	  ensures  T_LOA:          UpperBitsNotSet(p->T_LOA, 10);
	*/
	{ p->T_LOA		= Bitstream_Read(stream, 10); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Level_1_Movement_Authority_Core_1_Decoder(stream, &(p->sub_1[i]));
        }
	/*@
	  requires L_ENDSECTION:   stream->bitpos == pos + 41;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_ENDSECTION;
	  ensures  L_ENDSECTION:   stream->bitpos == pos + 56;
	  ensures  L_ENDSECTION:   EqualBits(stream, pos + 41, pos + 56, p->L_ENDSECTION);
	  ensures  L_ENDSECTION:   UpperBitsNotSet(p->L_ENDSECTION, 15);
	*/
	{ p->L_ENDSECTION		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_SECTIONTIMER: stream->bitpos == pos + 56;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_SECTIONTIMER;
	  ensures  Q_SECTIONTIMER: stream->bitpos == pos + 57;
	  ensures  Q_SECTIONTIMER: EqualBits(stream, pos + 56, pos + 57, p->Q_SECTIONTIMER);
	  ensures  Q_SECTIONTIMER: UpperBitsNotSet(p->Q_SECTIONTIMER, 1);
	*/
	{ p->Q_SECTIONTIMER		= Bitstream_Read(stream, 1); }

	/*@
	  requires T_SECTIONTIMER: stream->bitpos == pos + 57;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_SECTIONTIMER;
	  ensures  T_SECTIONTIMER: stream->bitpos == pos + 67;
	  ensures  T_SECTIONTIMER: EqualBits(stream, pos + 57, pos + 67, p->T_SECTIONTIMER);
	  ensures  T_SECTIONTIMER: UpperBitsNotSet(p->T_SECTIONTIMER, 10);
	*/
	{ p->T_SECTIONTIMER		= Bitstream_Read(stream, 10); }

	/*@
	  requires D_SECTIONTIMERSTOPLOC: stream->bitpos == pos + 67;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_SECTIONTIMERSTOPLOC;
	  ensures  D_SECTIONTIMERSTOPLOC: stream->bitpos == pos + 82;
	  ensures  D_SECTIONTIMERSTOPLOC: EqualBits(stream, pos + 67, pos + 82, p->D_SECTIONTIMERSTOPLOC);
	  ensures  D_SECTIONTIMERSTOPLOC: UpperBitsNotSet(p->D_SECTIONTIMERSTOPLOC, 15);
	*/
	{ p->D_SECTIONTIMERSTOPLOC		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_ENDTIMER:     stream->bitpos == pos + 82;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_ENDTIMER;
	  ensures  Q_ENDTIMER:     stream->bitpos == pos + 83;
	  ensures  Q_ENDTIMER:     EqualBits(stream, pos + 82, pos + 83, p->Q_ENDTIMER);
	  ensures  Q_ENDTIMER:     UpperBitsNotSet(p->Q_ENDTIMER, 1);
	*/
	{ p->Q_ENDTIMER		= Bitstream_Read(stream, 1); }

	/*@
	  requires T_ENDTIMER:     stream->bitpos == pos + 83;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_ENDTIMER;
	  ensures  T_ENDTIMER:     stream->bitpos == pos + 93;
	  ensures  T_ENDTIMER:     EqualBits(stream, pos + 83, pos + 93, p->T_ENDTIMER);
	  ensures  T_ENDTIMER:     UpperBitsNotSet(p->T_ENDTIMER, 10);
	*/
	{ p->T_ENDTIMER		= Bitstream_Read(stream, 10); }

	/*@
	  requires D_ENDTIMERSTARTLOC: stream->bitpos == pos + 93;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_ENDTIMERSTARTLOC;
	  ensures  D_ENDTIMERSTARTLOC: stream->bitpos == pos + 108;
	  ensures  D_ENDTIMERSTARTLOC: EqualBits(stream, pos + 93, pos + 108, p->D_ENDTIMERSTARTLOC);
	  ensures  D_ENDTIMERSTARTLOC: UpperBitsNotSet(p->D_ENDTIMERSTARTLOC, 15);
	*/
	{ p->D_ENDTIMERSTARTLOC		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_DANGERPOINT:  stream->bitpos == pos + 108;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_DANGERPOINT;
	  ensures  Q_DANGERPOINT:  stream->bitpos == pos + 109;
	  ensures  Q_DANGERPOINT:  EqualBits(stream, pos + 108, pos + 109, p->Q_DANGERPOINT);
	  ensures  Q_DANGERPOINT:  UpperBitsNotSet(p->Q_DANGERPOINT, 1);
	*/
	{ p->Q_DANGERPOINT		= Bitstream_Read(stream, 1); }

	/*@
	  requires D_DP:           stream->bitpos == pos + 109;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_DP;
	  ensures  D_DP:           stream->bitpos == pos + 124;
	  ensures  D_DP:           EqualBits(stream, pos + 109, pos + 124, p->D_DP);
	  ensures  D_DP:           UpperBitsNotSet(p->D_DP, 15);
	*/
	{ p->D_DP		= Bitstream_Read(stream, 15); }

	/*@
	  requires V_RELEASEDP:    stream->bitpos == pos + 124;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_RELEASEDP;
	  ensures  V_RELEASEDP:    stream->bitpos == pos + 131;
	  ensures  V_RELEASEDP:    EqualBits(stream, pos + 124, pos + 131, p->V_RELEASEDP);
	  ensures  V_RELEASEDP:    UpperBitsNotSet(p->V_RELEASEDP, 7);
	*/
	{ p->V_RELEASEDP		= Bitstream_Read(stream, 7); }

	/*@
	  requires Q_OVERLAP:      stream->bitpos == pos + 131;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_OVERLAP;
	  ensures  Q_OVERLAP:      stream->bitpos == pos + 132;
	  ensures  Q_OVERLAP:      EqualBits(stream, pos + 131, pos + 132, p->Q_OVERLAP);
	  ensures  Q_OVERLAP:      UpperBitsNotSet(p->Q_OVERLAP, 1);
	*/
	{ p->Q_OVERLAP		= Bitstream_Read(stream, 1); }

	/*@
	  requires D_STARTOL:      stream->bitpos == pos + 132;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_STARTOL;
	  ensures  D_STARTOL:      stream->bitpos == pos + 147;
	  ensures  D_STARTOL:      EqualBits(stream, pos + 132, pos + 147, p->D_STARTOL);
	  ensures  D_STARTOL:      UpperBitsNotSet(p->D_STARTOL, 15);
	*/
	{ p->D_STARTOL		= Bitstream_Read(stream, 15); }

	/*@
	  requires T_OL:           stream->bitpos == pos + 147;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_OL;
	  ensures  T_OL:           stream->bitpos == pos + 157;
	  ensures  T_OL:           EqualBits(stream, pos + 147, pos + 157, p->T_OL);
	  ensures  T_OL:           UpperBitsNotSet(p->T_OL, 10);
	*/
	{ p->T_OL		= Bitstream_Read(stream, 10); }

	/*@
	  requires D_OL:           stream->bitpos == pos + 157;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_OL;
	  ensures  D_OL:           stream->bitpos == pos + 172;
	  ensures  D_OL:           EqualBits(stream, pos + 157, pos + 172, p->D_OL);
	  ensures  D_OL:           UpperBitsNotSet(p->D_OL, 15);
	*/
	{ p->D_OL		= Bitstream_Read(stream, 15); }

	/*@
	  requires V_RELEASEOL:    stream->bitpos == pos + 172;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_RELEASEOL;
	  ensures  V_RELEASEOL:    stream->bitpos == pos + 179;
	  ensures  V_RELEASEOL:    EqualBits(stream, pos + 172, pos + 179, p->V_RELEASEOL);
	  ensures  V_RELEASEOL:    UpperBitsNotSet(p->V_RELEASEOL, 7);
	*/
	{ p->V_RELEASEOL		= Bitstream_Read(stream, 7); }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert V_MAIN:            EqualBits(stream, pos + 17,  pos + 24,  p->V_MAIN);
        //@ assert V_LOA:             EqualBits(stream, pos + 24,  pos + 31,  p->V_LOA);
        //@ assert T_LOA:             EqualBits(stream, pos + 31,  pos + 41,  p->T_LOA);
        //@ assert L_ENDSECTION:      EqualBits(stream, pos + 41,  pos + 56,  p->L_ENDSECTION);
        //@ assert Q_SECTIONTIMER:    EqualBits(stream, pos + 56,  pos + 57,  p->Q_SECTIONTIMER);
        //@ assert T_SECTIONTIMER:    EqualBits(stream, pos + 57,  pos + 67,  p->T_SECTIONTIMER);
        //@ assert D_SECTIONTIMERSTOPLOC: EqualBits(stream, pos + 67,  pos + 82,  p->D_SECTIONTIMERSTOPLOC);
        //@ assert Q_ENDTIMER:        EqualBits(stream, pos + 82,  pos + 83,  p->Q_ENDTIMER);
        //@ assert T_ENDTIMER:        EqualBits(stream, pos + 83,  pos + 93,  p->T_ENDTIMER);
        //@ assert D_ENDTIMERSTARTLOC: EqualBits(stream, pos + 93,  pos + 108, p->D_ENDTIMERSTARTLOC);
        //@ assert Q_DANGERPOINT:     EqualBits(stream, pos + 108, pos + 109, p->Q_DANGERPOINT);
        //@ assert D_DP:              EqualBits(stream, pos + 109, pos + 124, p->D_DP);
        //@ assert V_RELEASEDP:       EqualBits(stream, pos + 124, pos + 131, p->V_RELEASEDP);
        //@ assert Q_OVERLAP:         EqualBits(stream, pos + 131, pos + 132, p->Q_OVERLAP);
        //@ assert D_STARTOL:         EqualBits(stream, pos + 132, pos + 147, p->D_STARTOL);
        //@ assert T_OL:              EqualBits(stream, pos + 147, pos + 157, p->T_OL);
        //@ assert D_OL:              EqualBits(stream, pos + 157, pos + 172, p->D_OL);
        //@ assert V_RELEASEOL:       EqualBits(stream, pos + 172, pos + 179, p->V_RELEASEOL);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert V_MAIN:            UpperBitsNotSet(p->V_MAIN,            7);
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

