
#include "National_Values_Encoder.h"
#include "National_Values_UpperBitsNotSet.h"
#include "Bitwalker_Poke_Normal.h"

int National_Values_Encoder(Bitstream* stream, const National_Values* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_BITSIZE))
    {
        if (National_Values_UpperBitsNotSet(p))
        {
            uint8_t* addr = stream->addr;
            const uint32_t size = stream->size;
            const uint32_t pos = stream->bitpos;

            Bitwalker_Poke_Normal(addr, size, pos,       8,  p->NID_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 8,   2,  p->Q_DIR);
            Bitwalker_Poke_Normal(addr, size, pos + 10,  13, p->L_PACKET);
            Bitwalker_Poke_Normal(addr, size, pos + 23,  2,  p->Q_SCALE);
            Bitwalker_Poke_Normal(addr, size, pos + 25,  15, p->D_VALIDNV);
            Bitwalker_Poke_Normal(addr, size, pos + 40,  10, p->NID_C);
            Bitwalker_Poke_Normal(addr, size, pos + 50,  5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 55,  10, p->NID_C(p));
            Bitwalker_Poke_Normal(addr, size, pos + 65,  7,  p->V_NVSHUNT);
            Bitwalker_Poke_Normal(addr, size, pos + 72,  7,  p->V_NVSTFF);
            Bitwalker_Poke_Normal(addr, size, pos + 79,  7,  p->V_NVONSIGHT);
            Bitwalker_Poke_Normal(addr, size, pos + 86,  7,  p->V_NVLIMSUPERV);
            Bitwalker_Poke_Normal(addr, size, pos + 93,  7,  p->V_NVUNFIT);
            Bitwalker_Poke_Normal(addr, size, pos + 100, 7,  p->V_NVREL);
            Bitwalker_Poke_Normal(addr, size, pos + 107, 15, p->D_NVROLL);
            Bitwalker_Poke_Normal(addr, size, pos + 122, 1,  p->Q_NVSBTSMPERM);
            Bitwalker_Poke_Normal(addr, size, pos + 123, 1,  p->Q_NVEMRRLS);
            Bitwalker_Poke_Normal(addr, size, pos + 124, 1,  p->Q_NVGUIPERM);
            Bitwalker_Poke_Normal(addr, size, pos + 125, 1,  p->Q_NVSBFBPERM);
            Bitwalker_Poke_Normal(addr, size, pos + 126, 1,  p->Q_NVINHSMICPERM);
            Bitwalker_Poke_Normal(addr, size, pos + 127, 7,  p->V_NVALLOWOVTRP);
            Bitwalker_Poke_Normal(addr, size, pos + 134, 7,  p->V_NVSUPOVTRP);
            Bitwalker_Poke_Normal(addr, size, pos + 141, 15, p->D_NVOVTRP);
            Bitwalker_Poke_Normal(addr, size, pos + 156, 8,  p->T_NVOVTRP);
            Bitwalker_Poke_Normal(addr, size, pos + 164, 15, p->D_NVPOTRP);
            Bitwalker_Poke_Normal(addr, size, pos + 179, 2,  p->M_NVCONTACT);
            Bitwalker_Poke_Normal(addr, size, pos + 181, 8,  p->T_NVCONTACT);
            Bitwalker_Poke_Normal(addr, size, pos + 189, 1,  p->M_NVDERUN);
            Bitwalker_Poke_Normal(addr, size, pos + 190, 15, p->D_NVSTFF);
            Bitwalker_Poke_Normal(addr, size, pos + 205, 1,  p->Q_NVDRIVER_ADHES);
            Bitwalker_Poke_Normal(addr, size, pos + 206, 6,  p->A_NVMAXREDADH1);
            Bitwalker_Poke_Normal(addr, size, pos + 212, 6,  p->A_NVMAXREDADH2);
            Bitwalker_Poke_Normal(addr, size, pos + 218, 6,  p->A_NVMAXREDADH3);
            Bitwalker_Poke_Normal(addr, size, pos + 224, 6,  p->Q_NVLOCACC);
            Bitwalker_Poke_Normal(addr, size, pos + 230, 5,  p->M_NVAVADH);
            Bitwalker_Poke_Normal(addr, size, pos + 235, 4,  p->M_NVEBCL);
            Bitwalker_Poke_Normal(addr, size, pos + 239, 1,  p->Q_NVKINT);
            Bitwalker_Poke_Normal(addr, size, pos + 240, 2,  p->Q_NVKVINTSET);
            Bitwalker_Poke_Normal(addr, size, pos + 242, 6,  p->A_NVP12);
            Bitwalker_Poke_Normal(addr, size, pos + 248, 6,  p->A_NVP23);
            Bitwalker_Poke_Normal(addr, size, pos + 254, 7,  p->V_NVKVINT);
            Bitwalker_Poke_Normal(addr, size, pos + 261, 7,  p->M_NVKVINT);
            Bitwalker_Poke_Normal(addr, size, pos + 268, 5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 273, 7,  p->V_NVKVINT(n));
            Bitwalker_Poke_Normal(addr, size, pos + 280, 7,  p->M_NVKVINT(n));
            Bitwalker_Poke_Normal(addr, size, pos + 287, 5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 292, 2,  p->Q_NVKVINTSET(k));
            Bitwalker_Poke_Normal(addr, size, pos + 294, 6,  p->A_NVP12(k));
            Bitwalker_Poke_Normal(addr, size, pos + 300, 6,  p->A_NVP23(k));
            Bitwalker_Poke_Normal(addr, size, pos + 306, 7,  p->V_NVKVINT(k));
            Bitwalker_Poke_Normal(addr, size, pos + 313, 7,  p->M_NVKVINT(k));
            Bitwalker_Poke_Normal(addr, size, pos + 320, 5,  p->N_ITER(k));
            Bitwalker_Poke_Normal(addr, size, pos + 325, 7,  p->V_NVKVINT(k,m));
            Bitwalker_Poke_Normal(addr, size, pos + 332, 7,  p->M_NVKVINT(k,m));
            Bitwalker_Poke_Normal(addr, size, pos + 339, 5,  p->L_NVKRINT);
            Bitwalker_Poke_Normal(addr, size, pos + 344, 5,  p->M_NVKRINT);
            Bitwalker_Poke_Normal(addr, size, pos + 349, 5,  p->N_ITER);
            Bitwalker_Poke_Normal(addr, size, pos + 354, 5,  p->L_NVKRINT(l));
            Bitwalker_Poke_Normal(addr, size, pos + 359, 5,  p->M_NVKRINT(l));
            Bitwalker_Poke_Normal(addr, size, pos + 364, 5,  p->M_NVKTINT);

            stream->bitpos += NATIONAL_VALUES_BITSIZE;

            //@ assert NID_PACKET:        EqualBits(stream, pos,       pos + 8,   p->NID_PACKET);
            //@ assert Q_DIR:             EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE);
            //@ assert D_VALIDNV:         EqualBits(stream, pos + 25,  pos + 40,  p->D_VALIDNV);
            //@ assert NID_C:             EqualBits(stream, pos + 40,  pos + 50,  p->NID_C);
            //@ assert N_ITER:            EqualBits(stream, pos + 50,  pos + 55,  p->N_ITER);
            //@ assert NID_C(p):          EqualBits(stream, pos + 55,  pos + 65,  p->NID_C(p));
            //@ assert V_NVSHUNT:         EqualBits(stream, pos + 65,  pos + 72,  p->V_NVSHUNT);
            //@ assert V_NVSTFF:          EqualBits(stream, pos + 72,  pos + 79,  p->V_NVSTFF);
            //@ assert V_NVONSIGHT:       EqualBits(stream, pos + 79,  pos + 86,  p->V_NVONSIGHT);
            //@ assert V_NVLIMSUPERV:     EqualBits(stream, pos + 86,  pos + 93,  p->V_NVLIMSUPERV);
            //@ assert V_NVUNFIT:         EqualBits(stream, pos + 93,  pos + 100, p->V_NVUNFIT);
            //@ assert V_NVREL:           EqualBits(stream, pos + 100, pos + 107, p->V_NVREL);
            //@ assert D_NVROLL:          EqualBits(stream, pos + 107, pos + 122, p->D_NVROLL);
            //@ assert Q_NVSBTSMPERM:     EqualBits(stream, pos + 122, pos + 123, p->Q_NVSBTSMPERM);
            //@ assert Q_NVEMRRLS:        EqualBits(stream, pos + 123, pos + 124, p->Q_NVEMRRLS);
            //@ assert Q_NVGUIPERM:       EqualBits(stream, pos + 124, pos + 125, p->Q_NVGUIPERM);
            //@ assert Q_NVSBFBPERM:      EqualBits(stream, pos + 125, pos + 126, p->Q_NVSBFBPERM);
            //@ assert Q_NVINHSMICPERM:   EqualBits(stream, pos + 126, pos + 127, p->Q_NVINHSMICPERM);
            //@ assert V_NVALLOWOVTRP:    EqualBits(stream, pos + 127, pos + 134, p->V_NVALLOWOVTRP);
            //@ assert V_NVSUPOVTRP:      EqualBits(stream, pos + 134, pos + 141, p->V_NVSUPOVTRP);
            //@ assert D_NVOVTRP:         EqualBits(stream, pos + 141, pos + 156, p->D_NVOVTRP);
            //@ assert T_NVOVTRP:         EqualBits(stream, pos + 156, pos + 164, p->T_NVOVTRP);
            //@ assert D_NVPOTRP:         EqualBits(stream, pos + 164, pos + 179, p->D_NVPOTRP);
            //@ assert M_NVCONTACT:       EqualBits(stream, pos + 179, pos + 181, p->M_NVCONTACT);
            //@ assert T_NVCONTACT:       EqualBits(stream, pos + 181, pos + 189, p->T_NVCONTACT);
            //@ assert M_NVDERUN:         EqualBits(stream, pos + 189, pos + 190, p->M_NVDERUN);
            //@ assert D_NVSTFF:          EqualBits(stream, pos + 190, pos + 205, p->D_NVSTFF);
            //@ assert Q_NVDRIVER_ADHES:  EqualBits(stream, pos + 205, pos + 206, p->Q_NVDRIVER_ADHES);
            //@ assert A_NVMAXREDADH1:    EqualBits(stream, pos + 206, pos + 212, p->A_NVMAXREDADH1);
            //@ assert A_NVMAXREDADH2:    EqualBits(stream, pos + 212, pos + 218, p->A_NVMAXREDADH2);
            //@ assert A_NVMAXREDADH3:    EqualBits(stream, pos + 218, pos + 224, p->A_NVMAXREDADH3);
            //@ assert Q_NVLOCACC:        EqualBits(stream, pos + 224, pos + 230, p->Q_NVLOCACC);
            //@ assert M_NVAVADH:         EqualBits(stream, pos + 230, pos + 235, p->M_NVAVADH);
            //@ assert M_NVEBCL:          EqualBits(stream, pos + 235, pos + 239, p->M_NVEBCL);
            //@ assert Q_NVKINT:          EqualBits(stream, pos + 239, pos + 240, p->Q_NVKINT);
            //@ assert Q_NVKVINTSET:      EqualBits(stream, pos + 240, pos + 242, p->Q_NVKVINTSET);
            //@ assert A_NVP12:           EqualBits(stream, pos + 242, pos + 248, p->A_NVP12);
            //@ assert A_NVP23:           EqualBits(stream, pos + 248, pos + 254, p->A_NVP23);
            //@ assert V_NVKVINT:         EqualBits(stream, pos + 254, pos + 261, p->V_NVKVINT);
            //@ assert M_NVKVINT:         EqualBits(stream, pos + 261, pos + 268, p->M_NVKVINT);
            //@ assert N_ITER:            EqualBits(stream, pos + 268, pos + 273, p->N_ITER);
            //@ assert V_NVKVINT(n):      EqualBits(stream, pos + 273, pos + 280, p->V_NVKVINT(n));
            //@ assert M_NVKVINT(n):      EqualBits(stream, pos + 280, pos + 287, p->M_NVKVINT(n));
            //@ assert N_ITER:            EqualBits(stream, pos + 287, pos + 292, p->N_ITER);
            //@ assert Q_NVKVINTSET(k):   EqualBits(stream, pos + 292, pos + 294, p->Q_NVKVINTSET(k));
            //@ assert A_NVP12(k):        EqualBits(stream, pos + 294, pos + 300, p->A_NVP12(k));
            //@ assert A_NVP23(k):        EqualBits(stream, pos + 300, pos + 306, p->A_NVP23(k));
            //@ assert V_NVKVINT(k):      EqualBits(stream, pos + 306, pos + 313, p->V_NVKVINT(k));
            //@ assert M_NVKVINT(k):      EqualBits(stream, pos + 313, pos + 320, p->M_NVKVINT(k));
            //@ assert N_ITER(k):         EqualBits(stream, pos + 320, pos + 325, p->N_ITER(k));
            //@ assert V_NVKVINT(k,m):    EqualBits(stream, pos + 325, pos + 332, p->V_NVKVINT(k,m));
            //@ assert M_NVKVINT(k,m):    EqualBits(stream, pos + 332, pos + 339, p->M_NVKVINT(k,m));
            //@ assert L_NVKRINT:         EqualBits(stream, pos + 339, pos + 344, p->L_NVKRINT);
            //@ assert M_NVKRINT:         EqualBits(stream, pos + 344, pos + 349, p->M_NVKRINT);
            //@ assert N_ITER:            EqualBits(stream, pos + 349, pos + 354, p->N_ITER);
            //@ assert L_NVKRINT(l):      EqualBits(stream, pos + 354, pos + 359, p->L_NVKRINT(l));
            //@ assert M_NVKRINT(l):      EqualBits(stream, pos + 359, pos + 364, p->M_NVKRINT(l));
            //@ assert M_NVKTINT:         EqualBits(stream, pos + 364, pos + 369, p->M_NVKTINT);

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

