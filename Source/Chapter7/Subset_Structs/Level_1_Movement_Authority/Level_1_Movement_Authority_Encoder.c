
#include "Level_1_Movement_Authority_Encoder.h"
#include "Level_1_Movement_Authority_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int Level_1_Movement_Authority_Encoder(Bitstream* stream, const Level_1_Movement_Authority* p)
{
    if (NormalBitstream(stream, LEVEL_1_MOVEMENT_AUTHORITY_BITSIZE))
    {
        if (Level_1_Movement_Authority_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  7,  p->V_MAIN);
            Bitwalker_Poke_Normal(addr, size, pos + 32,  7,  p->V_LOA);
            Bitwalker_Poke_Normal(addr, size, pos + 39,  10, p->T_LOA);
            Bitwalker_Poke_Normal(addr, size, pos + 49,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 54,  15, p->L_SECTION(k));
            Bitwalker_Poke_Normal(addr, size, pos + 69,  1,  p->Q_SECTIONTIMER(k));
            Bitwalker_Poke_Normal(addr, size, pos + 70,  10, p->T_SECTIONTIMER(k));
            Bitwalker_Poke_Normal(addr, size, pos + 80,  15, p->D_SECTIONTIMERSTOPLOC(k));
            Bitwalker_Poke_Normal(addr, size, pos + 95,  15, p->L_ENDSECTION);
            Bitwalker_Poke_Normal(addr, size, pos + 110, 1,  p->Q_SECTIONTIMER);
            Bitwalker_Poke_Normal(addr, size, pos + 111, 10, p->T_SECTIONTIMER);
            Bitwalker_Poke_Normal(addr, size, pos + 121, 15, p->D_SECTIONTIMERSTOPLOC);
            Bitwalker_Poke_Normal(addr, size, pos + 136, 1,  p->Q_ENDTIMER);
            Bitwalker_Poke_Normal(addr, size, pos + 137, 10, p->T_ENDTIMER);
            Bitwalker_Poke_Normal(addr, size, pos + 147, 15, p->D_ENDTIMERSTARTLOC);
            Bitwalker_Poke_Normal(addr, size, pos + 162, 1,  p->Q_DANGERPOINT);
            Bitwalker_Poke_Normal(addr, size, pos + 163, 15, p->D_DP);
            Bitwalker_Poke_Normal(addr, size, pos + 178, 7,  p->V_RELEASEDP);
            Bitwalker_Poke_Normal(addr, size, pos + 185, 1,  p->Q_OVERLAP);
            Bitwalker_Poke_Normal(addr, size, pos + 186, 15, p->D_STARTOL);
            Bitwalker_Poke_Normal(addr, size, pos + 201, 10, p->T_OL);
            Bitwalker_Poke_Normal(addr, size, pos + 211, 15, p->D_OL);
            Bitwalker_Poke_Normal(addr, size, pos + 226, 7,  p->V_RELEASEOL);

            stream->bitpos += LEVEL_1_MOVEMENT_AUTHORITY_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert V_MAIN:            EqualBits(stream, pos + 25,  pos + 32,  p->V_MAIN);
            //@ assert V_LOA:             EqualBits(stream, pos + 32,  pos + 39,  p->V_LOA);
            //@ assert T_LOA:             EqualBits(stream, pos + 39,  pos + 49,  p->T_LOA);
            //@ assert N_ITER:            EqualBits(stream, pos + 49,  pos + 54,  p->N_ITER);
            //@ assert L_SECTION(k):      EqualBits(stream, pos + 54,  pos + 69,  p->L_SECTION(k));
            //@ assert Q_SECTIONTIMER(k): EqualBits(stream, pos + 69,  pos + 70,  p->Q_SECTIONTIMER(k));
            //@ assert T_SECTIONTIMER(k): EqualBits(stream, pos + 70,  pos + 80,  p->T_SECTIONTIMER(k));
            //@ assert D_SECTIONTIMERSTOPLOC(k): EqualBits(stream, pos + 80,  pos + 95,  p->D_SECTIONTIMERSTOPLOC(k));
            //@ assert L_ENDSECTION:      EqualBits(stream, pos + 95,  pos + 110, p->L_ENDSECTION);
            //@ assert Q_SECTIONTIMER:    EqualBits(stream, pos + 110, pos + 111, p->Q_SECTIONTIMER);
            //@ assert T_SECTIONTIMER:    EqualBits(stream, pos + 111, pos + 121, p->T_SECTIONTIMER);
            //@ assert D_SECTIONTIMERSTOPLOC: EqualBits(stream, pos + 121, pos + 136, p->D_SECTIONTIMERSTOPLOC);
            //@ assert Q_ENDTIMER:        EqualBits(stream, pos + 136, pos + 137, p->Q_ENDTIMER);
            //@ assert T_ENDTIMER:        EqualBits(stream, pos + 137, pos + 147, p->T_ENDTIMER);
            //@ assert D_ENDTIMERSTARTLOC: EqualBits(stream, pos + 147, pos + 162, p->D_ENDTIMERSTARTLOC);
            //@ assert Q_DANGERPOINT:     EqualBits(stream, pos + 162, pos + 163, p->Q_DANGERPOINT);
            //@ assert D_DP:              EqualBits(stream, pos + 163, pos + 178, p->D_DP);
            //@ assert V_RELEASEDP:       EqualBits(stream, pos + 178, pos + 185, p->V_RELEASEDP);
            //@ assert Q_OVERLAP:         EqualBits(stream, pos + 185, pos + 186, p->Q_OVERLAP);
            //@ assert D_STARTOL:         EqualBits(stream, pos + 186, pos + 201, p->D_STARTOL);
            //@ assert T_OL:              EqualBits(stream, pos + 201, pos + 211, p->T_OL);
            //@ assert D_OL:              EqualBits(stream, pos + 211, pos + 226, p->D_OL);
            //@ assert V_RELEASEOL:       EqualBits(stream, pos + 226, pos + 233, p->V_RELEASEOL);

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

