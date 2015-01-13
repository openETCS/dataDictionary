
#include "Level_23_Movement_Authority_Encoder.h"
#include "Level_23_Movement_Authority_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Level_23_Movement_Authority_Encoder(Bitstream* stream, const Level_23_Movement_Authority* p)
{
    if (NormalBitstream(stream, LEVEL_23_MOVEMENT_AUTHORITY_BITSIZE))
    {
        if (Level_23_Movement_Authority_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  7,  p->V_LOA);
            Bitwalker_Poke_Normal(addr, size, pos + 32,  10, p->T_LOA);
            Bitwalker_Poke_Normal(addr, size, pos + 42,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 47,  15, p->L_SECTION(k));
            Bitwalker_Poke_Normal(addr, size, pos + 62,  1,  p->Q_SECTIONTIMER(k));
            Bitwalker_Poke_Normal(addr, size, pos + 63,  10, p->T_SECTIONTIMER(k));
            Bitwalker_Poke_Normal(addr, size, pos + 73,  15, p->D_SECTIONTIMERSTOPLOC(k));
            Bitwalker_Poke_Normal(addr, size, pos + 88,  15, p->L_ENDSECTION);
            Bitwalker_Poke_Normal(addr, size, pos + 103, 1,  p->Q_SECTIONTIMER);
            Bitwalker_Poke_Normal(addr, size, pos + 104, 10, p->T_SECTIONTIMER);
            Bitwalker_Poke_Normal(addr, size, pos + 114, 15, p->D_SECTIONTIMERSTOPLOC);
            Bitwalker_Poke_Normal(addr, size, pos + 129, 1,  p->Q_ENDTIMER);
            Bitwalker_Poke_Normal(addr, size, pos + 130, 10, p->T_ENDTIMER);
            Bitwalker_Poke_Normal(addr, size, pos + 140, 15, p->D_ENDTIMERSTARTLOC);
            Bitwalker_Poke_Normal(addr, size, pos + 155, 1,  p->Q_DANGERPOINT);
            Bitwalker_Poke_Normal(addr, size, pos + 156, 15, p->D_DP);
            Bitwalker_Poke_Normal(addr, size, pos + 171, 7,  p->V_RELEASEDP);
            Bitwalker_Poke_Normal(addr, size, pos + 178, 1,  p->Q_OVERLAP);
            Bitwalker_Poke_Normal(addr, size, pos + 179, 15, p->D_STARTOL);
            Bitwalker_Poke_Normal(addr, size, pos + 194, 10, p->T_OL);
            Bitwalker_Poke_Normal(addr, size, pos + 204, 15, p->D_OL);
            Bitwalker_Poke_Normal(addr, size, pos + 219, 7,  p->V_RELEASEOL);

            stream->bitpos += LEVEL_23_MOVEMENT_AUTHORITY_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert V_LOA:             EqualBits(stream, pos + 25,  pos + 32,  p->V_LOA);
            //@ assert T_LOA:             EqualBits(stream, pos + 32,  pos + 42,  p->T_LOA);
            //@ assert N_ITER:            EqualBits(stream, pos + 42,  pos + 47,  p->N_ITER);
            //@ assert L_SECTION(k):      EqualBits(stream, pos + 47,  pos + 62,  p->L_SECTION(k));
            //@ assert Q_SECTIONTIMER(k): EqualBits(stream, pos + 62,  pos + 63,  p->Q_SECTIONTIMER(k));
            //@ assert T_SECTIONTIMER(k): EqualBits(stream, pos + 63,  pos + 73,  p->T_SECTIONTIMER(k));
            //@ assert D_SECTIONTIMERSTOPLOC(k): EqualBits(stream, pos + 73,  pos + 88,  p->D_SECTIONTIMERSTOPLOC(k));
            //@ assert L_ENDSECTION:      EqualBits(stream, pos + 88,  pos + 103, p->L_ENDSECTION);
            //@ assert Q_SECTIONTIMER:    EqualBits(stream, pos + 103, pos + 104, p->Q_SECTIONTIMER);
            //@ assert T_SECTIONTIMER:    EqualBits(stream, pos + 104, pos + 114, p->T_SECTIONTIMER);
            //@ assert D_SECTIONTIMERSTOPLOC: EqualBits(stream, pos + 114, pos + 129, p->D_SECTIONTIMERSTOPLOC);
            //@ assert Q_ENDTIMER:        EqualBits(stream, pos + 129, pos + 130, p->Q_ENDTIMER);
            //@ assert T_ENDTIMER:        EqualBits(stream, pos + 130, pos + 140, p->T_ENDTIMER);
            //@ assert D_ENDTIMERSTARTLOC: EqualBits(stream, pos + 140, pos + 155, p->D_ENDTIMERSTARTLOC);
            //@ assert Q_DANGERPOINT:     EqualBits(stream, pos + 155, pos + 156, p->Q_DANGERPOINT);
            //@ assert D_DP:              EqualBits(stream, pos + 156, pos + 171, p->D_DP);
            //@ assert V_RELEASEDP:       EqualBits(stream, pos + 171, pos + 178, p->V_RELEASEDP);
            //@ assert Q_OVERLAP:         EqualBits(stream, pos + 178, pos + 179, p->Q_OVERLAP);
            //@ assert D_STARTOL:         EqualBits(stream, pos + 179, pos + 194, p->D_STARTOL);
            //@ assert T_OL:              EqualBits(stream, pos + 194, pos + 204, p->T_OL);
            //@ assert D_OL:              EqualBits(stream, pos + 204, pos + 219, p->D_OL);
            //@ assert V_RELEASEOL:       EqualBits(stream, pos + 219, pos + 226, p->V_RELEASEOL);

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

