
#include "National_Values_Encoder.h"
#include "National_Values_UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "National_Values_Core_1_Encoder.h"
#include "National_Values_Core_2_Encoder.h"
#include "National_Values_Core_3_Encoder.h"
#include "National_Values_Core_4_Encoder.h"

int National_Values_Encoder(Bitstream* stream, const National_Values_Core* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_BITSIZE))
    {
        if (National_Values_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_VALIDNV);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                National_Values_Core_1_Encoder(stream, &(p->sub_1[i]));
            }
            Bitstream_Write(stream, 7,  p->V_NVSHUNT);
            Bitstream_Write(stream, 7,  p->V_NVSTFF);
            Bitstream_Write(stream, 7,  p->V_NVONSIGHT);
            Bitstream_Write(stream, 7,  p->V_NVLIMSUPERV);
            Bitstream_Write(stream, 7,  p->V_NVUNFIT);
            Bitstream_Write(stream, 7,  p->V_NVREL);
            Bitstream_Write(stream, 15, p->D_NVROLL);
            Bitstream_Write(stream, 1,  p->Q_NVSBTSMPERM);
            Bitstream_Write(stream, 1,  p->Q_NVEMRRLS);
            Bitstream_Write(stream, 1,  p->Q_NVGUIPERM);
            Bitstream_Write(stream, 1,  p->Q_NVSBFBPERM);
            Bitstream_Write(stream, 1,  p->Q_NVINHSMICPERM);
            Bitstream_Write(stream, 7,  p->V_NVALLOWOVTRP);
            Bitstream_Write(stream, 7,  p->V_NVSUPOVTRP);
            Bitstream_Write(stream, 15, p->D_NVOVTRP);
            Bitstream_Write(stream, 8,  p->T_NVOVTRP);
            Bitstream_Write(stream, 15, p->D_NVPOTRP);
            Bitstream_Write(stream, 2,  p->M_NVCONTACT);
            Bitstream_Write(stream, 8,  p->T_NVCONTACT);
            Bitstream_Write(stream, 1,  p->M_NVDERUN);
            Bitstream_Write(stream, 15, p->D_NVSTFF);
            Bitstream_Write(stream, 1,  p->Q_NVDRIVER_ADHES);
            Bitstream_Write(stream, 6,  p->A_NVMAXREDADH1);
            Bitstream_Write(stream, 6,  p->A_NVMAXREDADH2);
            Bitstream_Write(stream, 6,  p->A_NVMAXREDADH3);
            Bitstream_Write(stream, 6,  p->Q_NVLOCACC);
            Bitstream_Write(stream, 5,  p->M_NVAVADH);
            Bitstream_Write(stream, 4,  p->M_NVEBCL);
            Bitstream_Write(stream, 1,  p->Q_NVKINT);
            if (p->Q_NVKINT == 1)
            {
            Bitstream_Write(stream, 2,  p->Q_NVKVINTSET);
            if (p->Q_NVKVINTSET == 1)
            {
            Bitstream_Write(stream, 6,  p->A_NVP12);
            Bitstream_Write(stream, 6,  p->A_NVP23);
            }

            Bitstream_Write(stream, 7,  p->V_NVKVINT);
            Bitstream_Write(stream, 7,  p->M_NVKVINT);
            Bitstream_Write(stream, 5,  p->N_ITER_2);
            for (uint32_t i = 0; i < p->N_ITER_2; ++i)
            {
                National_Values_Core_2_Encoder(stream, &(p->sub_2[i]));
            }
            Bitstream_Write(stream, 5,  p->N_ITER_3);
            for (uint32_t i = 0; i < p->N_ITER_3; ++i)
            {
                National_Values_Core_3_Encoder(stream, &(p->sub_3[i]));
            }
            Bitstream_Write(stream, 5,  p->L_NVKRINT);
            Bitstream_Write(stream, 5,  p->M_NVKRINT);
            Bitstream_Write(stream, 5,  p->N_ITER_4);
            for (uint32_t i = 0; i < p->N_ITER_4; ++i)
            {
                National_Values_Core_4_Encoder(stream, &(p->sub_4[i]));
            }
            Bitstream_Write(stream, 5,  p->M_NVKTINT);
            }



            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_VALIDNV:         EqualBits(stream, pos + 17,  pos + 32,  p->D_VALIDNV);
            //@ assert NID_C:             EqualBits(stream, pos + 32,  pos + 42,  p->NID_C);
            //@ assert V_NVSHUNT:         EqualBits(stream, pos + 57,  pos + 64,  p->V_NVSHUNT);
            //@ assert V_NVSTFF:          EqualBits(stream, pos + 64,  pos + 71,  p->V_NVSTFF);
            //@ assert V_NVONSIGHT:       EqualBits(stream, pos + 71,  pos + 78,  p->V_NVONSIGHT);
            //@ assert V_NVLIMSUPERV:     EqualBits(stream, pos + 78,  pos + 85,  p->V_NVLIMSUPERV);
            //@ assert V_NVUNFIT:         EqualBits(stream, pos + 85,  pos + 92,  p->V_NVUNFIT);
            //@ assert V_NVREL:           EqualBits(stream, pos + 92,  pos + 99,  p->V_NVREL);
            //@ assert D_NVROLL:          EqualBits(stream, pos + 99,  pos + 114, p->D_NVROLL);
            //@ assert Q_NVSBTSMPERM:     EqualBits(stream, pos + 114, pos + 115, p->Q_NVSBTSMPERM);
            //@ assert Q_NVEMRRLS:        EqualBits(stream, pos + 115, pos + 116, p->Q_NVEMRRLS);
            //@ assert Q_NVGUIPERM:       EqualBits(stream, pos + 116, pos + 117, p->Q_NVGUIPERM);
            //@ assert Q_NVSBFBPERM:      EqualBits(stream, pos + 117, pos + 118, p->Q_NVSBFBPERM);
            //@ assert Q_NVINHSMICPERM:   EqualBits(stream, pos + 118, pos + 119, p->Q_NVINHSMICPERM);
            //@ assert V_NVALLOWOVTRP:    EqualBits(stream, pos + 119, pos + 126, p->V_NVALLOWOVTRP);
            //@ assert V_NVSUPOVTRP:      EqualBits(stream, pos + 126, pos + 133, p->V_NVSUPOVTRP);
            //@ assert D_NVOVTRP:         EqualBits(stream, pos + 133, pos + 148, p->D_NVOVTRP);
            //@ assert T_NVOVTRP:         EqualBits(stream, pos + 148, pos + 156, p->T_NVOVTRP);
            //@ assert D_NVPOTRP:         EqualBits(stream, pos + 156, pos + 171, p->D_NVPOTRP);
            //@ assert M_NVCONTACT:       EqualBits(stream, pos + 171, pos + 173, p->M_NVCONTACT);
            //@ assert T_NVCONTACT:       EqualBits(stream, pos + 173, pos + 181, p->T_NVCONTACT);
            //@ assert M_NVDERUN:         EqualBits(stream, pos + 181, pos + 182, p->M_NVDERUN);
            //@ assert D_NVSTFF:          EqualBits(stream, pos + 182, pos + 197, p->D_NVSTFF);
            //@ assert Q_NVDRIVER_ADHES:  EqualBits(stream, pos + 197, pos + 198, p->Q_NVDRIVER_ADHES);
            //@ assert A_NVMAXREDADH1:    EqualBits(stream, pos + 198, pos + 204, p->A_NVMAXREDADH1);
            //@ assert A_NVMAXREDADH2:    EqualBits(stream, pos + 204, pos + 210, p->A_NVMAXREDADH2);
            //@ assert A_NVMAXREDADH3:    EqualBits(stream, pos + 210, pos + 216, p->A_NVMAXREDADH3);
            //@ assert Q_NVLOCACC:        EqualBits(stream, pos + 216, pos + 222, p->Q_NVLOCACC);
            //@ assert M_NVAVADH:         EqualBits(stream, pos + 222, pos + 227, p->M_NVAVADH);
            //@ assert M_NVEBCL:          EqualBits(stream, pos + 227, pos + 231, p->M_NVEBCL);
            //@ assert Q_NVKINT:          EqualBits(stream, pos + 231, pos + 232, p->Q_NVKINT);

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

