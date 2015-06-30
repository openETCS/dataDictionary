
#include "National_Values_Core.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int National_Values_UpperBitsNotSet(const National_Values_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_VALIDNV,         15);
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && National_Values_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->V_NVSHUNT,         7) ;
    status = status && UpperBitsNotSet64(p->V_NVSTFF,          7) ;
    status = status && UpperBitsNotSet64(p->V_NVONSIGHT,       7) ;
    status = status && UpperBitsNotSet64(p->V_NVLIMSUPERV,     7) ;
    status = status && UpperBitsNotSet64(p->V_NVUNFIT,         7) ;
    status = status && UpperBitsNotSet64(p->V_NVREL,           7) ;
    status = status && UpperBitsNotSet64(p->D_NVROLL,          15);
    status = status && UpperBitsNotSet64(p->Q_NVSBTSMPERM,     1) ;
    status = status && UpperBitsNotSet64(p->Q_NVEMRRLS,        1) ;
    status = status && UpperBitsNotSet64(p->Q_NVGUIPERM,       1) ;
    status = status && UpperBitsNotSet64(p->Q_NVSBFBPERM,      1) ;
    status = status && UpperBitsNotSet64(p->Q_NVINHSMICPERM,   1) ;
    status = status && UpperBitsNotSet64(p->V_NVALLOWOVTRP,    7) ;
    status = status && UpperBitsNotSet64(p->V_NVSUPOVTRP,      7) ;
    status = status && UpperBitsNotSet64(p->D_NVOVTRP,         15);
    status = status && UpperBitsNotSet64(p->T_NVOVTRP,         8) ;
    status = status && UpperBitsNotSet64(p->D_NVPOTRP,         15);
    status = status && UpperBitsNotSet64(p->M_NVCONTACT,       2) ;
    status = status && UpperBitsNotSet64(p->T_NVCONTACT,       8) ;
    status = status && UpperBitsNotSet64(p->M_NVDERUN,         1) ;
    status = status && UpperBitsNotSet64(p->D_NVSTFF,          15);
    status = status && UpperBitsNotSet64(p->Q_NVDRIVER_ADHES,  1) ;
    status = status && UpperBitsNotSet64(p->A_NVMAXREDADH1,    6) ;
    status = status && UpperBitsNotSet64(p->A_NVMAXREDADH2,    6) ;
    status = status && UpperBitsNotSet64(p->A_NVMAXREDADH3,    6) ;
    status = status && UpperBitsNotSet64(p->Q_NVLOCACC,        6) ;
    status = status && UpperBitsNotSet64(p->M_NVAVADH,         5) ;
    status = status && UpperBitsNotSet64(p->M_NVEBCL,          4) ;
    status = status && UpperBitsNotSet64(p->Q_NVKINT,          1) ;
    if (p->Q_NVKINT == 1)
    {
    status = status && UpperBitsNotSet64(p->Q_NVKVINTSET,      2) ;
    if (p->Q_NVKVINTSET == 1)
    {
    status = status && UpperBitsNotSet64(p->A_NVP12,           6) ;
    status = status && UpperBitsNotSet64(p->A_NVP23,           6) ;
    }
    status = status && UpperBitsNotSet64(p->V_NVKVINT,         7) ;
    status = status && UpperBitsNotSet64(p->M_NVKVINT,         7) ;
    status = status && UpperBitsNotSet64(p->N_ITER_2,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        status = status && National_Values_Core_2_UpperBitsNotSet(&(p->sub_2[i]));
    }
    status = status && UpperBitsNotSet64(p->N_ITER_3,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_3; ++i)
    {
        status = status && National_Values_Core_3_UpperBitsNotSet(&(p->sub_3[i]));
    }
    status = status && UpperBitsNotSet64(p->L_NVKRINT,         5) ;
    status = status && UpperBitsNotSet64(p->M_NVKRINT,         5) ;
    status = status && UpperBitsNotSet64(p->N_ITER_4,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_4; ++i)
    {
        status = status && National_Values_Core_4_UpperBitsNotSet(&(p->sub_4[i]));
    }
    status = status && UpperBitsNotSet64(p->M_NVKTINT,         5) ;
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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



            //@ assert Q_DIR:             EqualBits(stream, pos + 28,  pos + 30,  p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 30,  pos + 43,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 43,  pos + 45,  p->Q_SCALE);
            //@ assert D_VALIDNV:         EqualBits(stream, pos + 45,  pos + 60,  p->D_VALIDNV);
            //@ assert NID_C:             EqualBits(stream, pos + 60,  pos + 70,  p->NID_C);
            //@ assert V_NVSHUNT:         EqualBits(stream, pos + 85,  pos + 92,  p->V_NVSHUNT);
            //@ assert V_NVSTFF:          EqualBits(stream, pos + 92,  pos + 99,  p->V_NVSTFF);
            //@ assert V_NVONSIGHT:       EqualBits(stream, pos + 99,  pos + 106, p->V_NVONSIGHT);
            //@ assert V_NVLIMSUPERV:     EqualBits(stream, pos + 106, pos + 113, p->V_NVLIMSUPERV);
            //@ assert V_NVUNFIT:         EqualBits(stream, pos + 113, pos + 120, p->V_NVUNFIT);
            //@ assert V_NVREL:           EqualBits(stream, pos + 120, pos + 127, p->V_NVREL);
            //@ assert D_NVROLL:          EqualBits(stream, pos + 127, pos + 142, p->D_NVROLL);
            //@ assert Q_NVSBTSMPERM:     EqualBits(stream, pos + 142, pos + 143, p->Q_NVSBTSMPERM);
            //@ assert Q_NVEMRRLS:        EqualBits(stream, pos + 143, pos + 144, p->Q_NVEMRRLS);
            //@ assert Q_NVGUIPERM:       EqualBits(stream, pos + 144, pos + 145, p->Q_NVGUIPERM);
            //@ assert Q_NVSBFBPERM:      EqualBits(stream, pos + 145, pos + 146, p->Q_NVSBFBPERM);
            //@ assert Q_NVINHSMICPERM:   EqualBits(stream, pos + 146, pos + 147, p->Q_NVINHSMICPERM);
            //@ assert V_NVALLOWOVTRP:    EqualBits(stream, pos + 147, pos + 154, p->V_NVALLOWOVTRP);
            //@ assert V_NVSUPOVTRP:      EqualBits(stream, pos + 154, pos + 161, p->V_NVSUPOVTRP);
            //@ assert D_NVOVTRP:         EqualBits(stream, pos + 161, pos + 176, p->D_NVOVTRP);
            //@ assert T_NVOVTRP:         EqualBits(stream, pos + 176, pos + 184, p->T_NVOVTRP);
            //@ assert D_NVPOTRP:         EqualBits(stream, pos + 184, pos + 199, p->D_NVPOTRP);
            //@ assert M_NVCONTACT:       EqualBits(stream, pos + 199, pos + 201, p->M_NVCONTACT);
            //@ assert T_NVCONTACT:       EqualBits(stream, pos + 201, pos + 209, p->T_NVCONTACT);
            //@ assert M_NVDERUN:         EqualBits(stream, pos + 209, pos + 210, p->M_NVDERUN);
            //@ assert D_NVSTFF:          EqualBits(stream, pos + 210, pos + 225, p->D_NVSTFF);
            //@ assert Q_NVDRIVER_ADHES:  EqualBits(stream, pos + 225, pos + 226, p->Q_NVDRIVER_ADHES);
            //@ assert A_NVMAXREDADH1:    EqualBits(stream, pos + 226, pos + 232, p->A_NVMAXREDADH1);
            //@ assert A_NVMAXREDADH2:    EqualBits(stream, pos + 232, pos + 238, p->A_NVMAXREDADH2);
            //@ assert A_NVMAXREDADH3:    EqualBits(stream, pos + 238, pos + 244, p->A_NVMAXREDADH3);
            //@ assert Q_NVLOCACC:        EqualBits(stream, pos + 244, pos + 250, p->Q_NVLOCACC);
            //@ assert M_NVAVADH:         EqualBits(stream, pos + 250, pos + 255, p->M_NVAVADH);
            //@ assert M_NVEBCL:          EqualBits(stream, pos + 255, pos + 259, p->M_NVEBCL);
            //@ assert Q_NVKINT:          EqualBits(stream, pos + 259, pos + 260, p->Q_NVKINT);

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

int National_Values_Decoder(Bitstream* stream, National_Values_Core* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires Q_DIR:          stream->bitpos == pos + 28;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_DIR;
	  ensures  Q_DIR:          stream->bitpos == pos + 30;
	  ensures  Q_DIR:          EqualBits(stream, pos + 28, pos + 30, p->Q_DIR);
	  ensures  Q_DIR:          UpperBitsNotSet(p->Q_DIR, 2);
	*/
	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	/*@
	  requires L_PACKET:       stream->bitpos == pos + 30;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_PACKET;
	  ensures  L_PACKET:       stream->bitpos == pos + 43;
	  ensures  L_PACKET:       EqualBits(stream, pos + 30, pos + 43, p->L_PACKET);
	  ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
	*/
	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	/*@
	  requires Q_SCALE:        stream->bitpos == pos + 43;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_SCALE;
	  ensures  Q_SCALE:        stream->bitpos == pos + 45;
	  ensures  Q_SCALE:        EqualBits(stream, pos + 43, pos + 45, p->Q_SCALE);
	  ensures  Q_SCALE:        UpperBitsNotSet(p->Q_SCALE, 2);
	*/
	{ p->Q_SCALE		= Bitstream_Read(stream, 2); }

	/*@
	  requires D_VALIDNV:      stream->bitpos == pos + 45;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_VALIDNV;
	  ensures  D_VALIDNV:      stream->bitpos == pos + 60;
	  ensures  D_VALIDNV:      EqualBits(stream, pos + 45, pos + 60, p->D_VALIDNV);
	  ensures  D_VALIDNV:      UpperBitsNotSet(p->D_VALIDNV, 15);
	*/
	{ p->D_VALIDNV		= Bitstream_Read(stream, 15); }

	/*@
	  requires NID_C:          stream->bitpos == pos + 60;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_C;
	  ensures  NID_C:          stream->bitpos == pos + 70;
	  ensures  NID_C:          EqualBits(stream, pos + 60, pos + 70, p->NID_C);
	  ensures  NID_C:          UpperBitsNotSet(p->NID_C, 10);
	*/
	{ p->NID_C		= Bitstream_Read(stream, 10); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            National_Values_Core_1_Decoder(stream, &(p->sub_1[i]));
        }
	/*@
	  requires V_NVSHUNT:      stream->bitpos == pos + 85;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVSHUNT;
	  ensures  V_NVSHUNT:      stream->bitpos == pos + 92;
	  ensures  V_NVSHUNT:      EqualBits(stream, pos + 85, pos + 92, p->V_NVSHUNT);
	  ensures  V_NVSHUNT:      UpperBitsNotSet(p->V_NVSHUNT, 7);
	*/
	{ p->V_NVSHUNT		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_NVSTFF:       stream->bitpos == pos + 92;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVSTFF;
	  ensures  V_NVSTFF:       stream->bitpos == pos + 99;
	  ensures  V_NVSTFF:       EqualBits(stream, pos + 92, pos + 99, p->V_NVSTFF);
	  ensures  V_NVSTFF:       UpperBitsNotSet(p->V_NVSTFF, 7);
	*/
	{ p->V_NVSTFF		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_NVONSIGHT:    stream->bitpos == pos + 99;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVONSIGHT;
	  ensures  V_NVONSIGHT:    stream->bitpos == pos + 106;
	  ensures  V_NVONSIGHT:    EqualBits(stream, pos + 99, pos + 106, p->V_NVONSIGHT);
	  ensures  V_NVONSIGHT:    UpperBitsNotSet(p->V_NVONSIGHT, 7);
	*/
	{ p->V_NVONSIGHT		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_NVLIMSUPERV:  stream->bitpos == pos + 106;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVLIMSUPERV;
	  ensures  V_NVLIMSUPERV:  stream->bitpos == pos + 113;
	  ensures  V_NVLIMSUPERV:  EqualBits(stream, pos + 106, pos + 113, p->V_NVLIMSUPERV);
	  ensures  V_NVLIMSUPERV:  UpperBitsNotSet(p->V_NVLIMSUPERV, 7);
	*/
	{ p->V_NVLIMSUPERV		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_NVUNFIT:      stream->bitpos == pos + 113;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVUNFIT;
	  ensures  V_NVUNFIT:      stream->bitpos == pos + 120;
	  ensures  V_NVUNFIT:      EqualBits(stream, pos + 113, pos + 120, p->V_NVUNFIT);
	  ensures  V_NVUNFIT:      UpperBitsNotSet(p->V_NVUNFIT, 7);
	*/
	{ p->V_NVUNFIT		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_NVREL:        stream->bitpos == pos + 120;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVREL;
	  ensures  V_NVREL:        stream->bitpos == pos + 127;
	  ensures  V_NVREL:        EqualBits(stream, pos + 120, pos + 127, p->V_NVREL);
	  ensures  V_NVREL:        UpperBitsNotSet(p->V_NVREL, 7);
	*/
	{ p->V_NVREL		= Bitstream_Read(stream, 7); }

	/*@
	  requires D_NVROLL:       stream->bitpos == pos + 127;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_NVROLL;
	  ensures  D_NVROLL:       stream->bitpos == pos + 142;
	  ensures  D_NVROLL:       EqualBits(stream, pos + 127, pos + 142, p->D_NVROLL);
	  ensures  D_NVROLL:       UpperBitsNotSet(p->D_NVROLL, 15);
	*/
	{ p->D_NVROLL		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_NVSBTSMPERM:  stream->bitpos == pos + 142;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVSBTSMPERM;
	  ensures  Q_NVSBTSMPERM:  stream->bitpos == pos + 143;
	  ensures  Q_NVSBTSMPERM:  EqualBits(stream, pos + 142, pos + 143, p->Q_NVSBTSMPERM);
	  ensures  Q_NVSBTSMPERM:  UpperBitsNotSet(p->Q_NVSBTSMPERM, 1);
	*/
	{ p->Q_NVSBTSMPERM		= Bitstream_Read(stream, 1); }

	/*@
	  requires Q_NVEMRRLS:     stream->bitpos == pos + 143;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVEMRRLS;
	  ensures  Q_NVEMRRLS:     stream->bitpos == pos + 144;
	  ensures  Q_NVEMRRLS:     EqualBits(stream, pos + 143, pos + 144, p->Q_NVEMRRLS);
	  ensures  Q_NVEMRRLS:     UpperBitsNotSet(p->Q_NVEMRRLS, 1);
	*/
	{ p->Q_NVEMRRLS		= Bitstream_Read(stream, 1); }

	/*@
	  requires Q_NVGUIPERM:    stream->bitpos == pos + 144;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVGUIPERM;
	  ensures  Q_NVGUIPERM:    stream->bitpos == pos + 145;
	  ensures  Q_NVGUIPERM:    EqualBits(stream, pos + 144, pos + 145, p->Q_NVGUIPERM);
	  ensures  Q_NVGUIPERM:    UpperBitsNotSet(p->Q_NVGUIPERM, 1);
	*/
	{ p->Q_NVGUIPERM		= Bitstream_Read(stream, 1); }

	/*@
	  requires Q_NVSBFBPERM:   stream->bitpos == pos + 145;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVSBFBPERM;
	  ensures  Q_NVSBFBPERM:   stream->bitpos == pos + 146;
	  ensures  Q_NVSBFBPERM:   EqualBits(stream, pos + 145, pos + 146, p->Q_NVSBFBPERM);
	  ensures  Q_NVSBFBPERM:   UpperBitsNotSet(p->Q_NVSBFBPERM, 1);
	*/
	{ p->Q_NVSBFBPERM		= Bitstream_Read(stream, 1); }

	/*@
	  requires Q_NVINHSMICPERM: stream->bitpos == pos + 146;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVINHSMICPERM;
	  ensures  Q_NVINHSMICPERM: stream->bitpos == pos + 147;
	  ensures  Q_NVINHSMICPERM: EqualBits(stream, pos + 146, pos + 147, p->Q_NVINHSMICPERM);
	  ensures  Q_NVINHSMICPERM: UpperBitsNotSet(p->Q_NVINHSMICPERM, 1);
	*/
	{ p->Q_NVINHSMICPERM		= Bitstream_Read(stream, 1); }

	/*@
	  requires V_NVALLOWOVTRP: stream->bitpos == pos + 147;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVALLOWOVTRP;
	  ensures  V_NVALLOWOVTRP: stream->bitpos == pos + 154;
	  ensures  V_NVALLOWOVTRP: EqualBits(stream, pos + 147, pos + 154, p->V_NVALLOWOVTRP);
	  ensures  V_NVALLOWOVTRP: UpperBitsNotSet(p->V_NVALLOWOVTRP, 7);
	*/
	{ p->V_NVALLOWOVTRP		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_NVSUPOVTRP:   stream->bitpos == pos + 154;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVSUPOVTRP;
	  ensures  V_NVSUPOVTRP:   stream->bitpos == pos + 161;
	  ensures  V_NVSUPOVTRP:   EqualBits(stream, pos + 154, pos + 161, p->V_NVSUPOVTRP);
	  ensures  V_NVSUPOVTRP:   UpperBitsNotSet(p->V_NVSUPOVTRP, 7);
	*/
	{ p->V_NVSUPOVTRP		= Bitstream_Read(stream, 7); }

	/*@
	  requires D_NVOVTRP:      stream->bitpos == pos + 161;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_NVOVTRP;
	  ensures  D_NVOVTRP:      stream->bitpos == pos + 176;
	  ensures  D_NVOVTRP:      EqualBits(stream, pos + 161, pos + 176, p->D_NVOVTRP);
	  ensures  D_NVOVTRP:      UpperBitsNotSet(p->D_NVOVTRP, 15);
	*/
	{ p->D_NVOVTRP		= Bitstream_Read(stream, 15); }

	/*@
	  requires T_NVOVTRP:      stream->bitpos == pos + 176;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_NVOVTRP;
	  ensures  T_NVOVTRP:      stream->bitpos == pos + 184;
	  ensures  T_NVOVTRP:      EqualBits(stream, pos + 176, pos + 184, p->T_NVOVTRP);
	  ensures  T_NVOVTRP:      UpperBitsNotSet(p->T_NVOVTRP, 8);
	*/
	{ p->T_NVOVTRP		= Bitstream_Read(stream, 8); }

	/*@
	  requires D_NVPOTRP:      stream->bitpos == pos + 184;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_NVPOTRP;
	  ensures  D_NVPOTRP:      stream->bitpos == pos + 199;
	  ensures  D_NVPOTRP:      EqualBits(stream, pos + 184, pos + 199, p->D_NVPOTRP);
	  ensures  D_NVPOTRP:      UpperBitsNotSet(p->D_NVPOTRP, 15);
	*/
	{ p->D_NVPOTRP		= Bitstream_Read(stream, 15); }

	/*@
	  requires M_NVCONTACT:    stream->bitpos == pos + 199;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_NVCONTACT;
	  ensures  M_NVCONTACT:    stream->bitpos == pos + 201;
	  ensures  M_NVCONTACT:    EqualBits(stream, pos + 199, pos + 201, p->M_NVCONTACT);
	  ensures  M_NVCONTACT:    UpperBitsNotSet(p->M_NVCONTACT, 2);
	*/
	{ p->M_NVCONTACT		= Bitstream_Read(stream, 2); }

	/*@
	  requires T_NVCONTACT:    stream->bitpos == pos + 201;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_NVCONTACT;
	  ensures  T_NVCONTACT:    stream->bitpos == pos + 209;
	  ensures  T_NVCONTACT:    EqualBits(stream, pos + 201, pos + 209, p->T_NVCONTACT);
	  ensures  T_NVCONTACT:    UpperBitsNotSet(p->T_NVCONTACT, 8);
	*/
	{ p->T_NVCONTACT		= Bitstream_Read(stream, 8); }

	/*@
	  requires M_NVDERUN:      stream->bitpos == pos + 209;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_NVDERUN;
	  ensures  M_NVDERUN:      stream->bitpos == pos + 210;
	  ensures  M_NVDERUN:      EqualBits(stream, pos + 209, pos + 210, p->M_NVDERUN);
	  ensures  M_NVDERUN:      UpperBitsNotSet(p->M_NVDERUN, 1);
	*/
	{ p->M_NVDERUN		= Bitstream_Read(stream, 1); }

	/*@
	  requires D_NVSTFF:       stream->bitpos == pos + 210;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_NVSTFF;
	  ensures  D_NVSTFF:       stream->bitpos == pos + 225;
	  ensures  D_NVSTFF:       EqualBits(stream, pos + 210, pos + 225, p->D_NVSTFF);
	  ensures  D_NVSTFF:       UpperBitsNotSet(p->D_NVSTFF, 15);
	*/
	{ p->D_NVSTFF		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_NVDRIVER_ADHES: stream->bitpos == pos + 225;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVDRIVER_ADHES;
	  ensures  Q_NVDRIVER_ADHES: stream->bitpos == pos + 226;
	  ensures  Q_NVDRIVER_ADHES: EqualBits(stream, pos + 225, pos + 226, p->Q_NVDRIVER_ADHES);
	  ensures  Q_NVDRIVER_ADHES: UpperBitsNotSet(p->Q_NVDRIVER_ADHES, 1);
	*/
	{ p->Q_NVDRIVER_ADHES		= Bitstream_Read(stream, 1); }

	/*@
	  requires A_NVMAXREDADH1: stream->bitpos == pos + 226;
	  assigns        	   stream->bitpos;
	  assigns		   p->A_NVMAXREDADH1;
	  ensures  A_NVMAXREDADH1: stream->bitpos == pos + 232;
	  ensures  A_NVMAXREDADH1: EqualBits(stream, pos + 226, pos + 232, p->A_NVMAXREDADH1);
	  ensures  A_NVMAXREDADH1: UpperBitsNotSet(p->A_NVMAXREDADH1, 6);
	*/
	{ p->A_NVMAXREDADH1		= Bitstream_Read(stream, 6); }

	/*@
	  requires A_NVMAXREDADH2: stream->bitpos == pos + 232;
	  assigns        	   stream->bitpos;
	  assigns		   p->A_NVMAXREDADH2;
	  ensures  A_NVMAXREDADH2: stream->bitpos == pos + 238;
	  ensures  A_NVMAXREDADH2: EqualBits(stream, pos + 232, pos + 238, p->A_NVMAXREDADH2);
	  ensures  A_NVMAXREDADH2: UpperBitsNotSet(p->A_NVMAXREDADH2, 6);
	*/
	{ p->A_NVMAXREDADH2		= Bitstream_Read(stream, 6); }

	/*@
	  requires A_NVMAXREDADH3: stream->bitpos == pos + 238;
	  assigns        	   stream->bitpos;
	  assigns		   p->A_NVMAXREDADH3;
	  ensures  A_NVMAXREDADH3: stream->bitpos == pos + 244;
	  ensures  A_NVMAXREDADH3: EqualBits(stream, pos + 238, pos + 244, p->A_NVMAXREDADH3);
	  ensures  A_NVMAXREDADH3: UpperBitsNotSet(p->A_NVMAXREDADH3, 6);
	*/
	{ p->A_NVMAXREDADH3		= Bitstream_Read(stream, 6); }

	/*@
	  requires Q_NVLOCACC:     stream->bitpos == pos + 244;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVLOCACC;
	  ensures  Q_NVLOCACC:     stream->bitpos == pos + 250;
	  ensures  Q_NVLOCACC:     EqualBits(stream, pos + 244, pos + 250, p->Q_NVLOCACC);
	  ensures  Q_NVLOCACC:     UpperBitsNotSet(p->Q_NVLOCACC, 6);
	*/
	{ p->Q_NVLOCACC		= Bitstream_Read(stream, 6); }

	/*@
	  requires M_NVAVADH:      stream->bitpos == pos + 250;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_NVAVADH;
	  ensures  M_NVAVADH:      stream->bitpos == pos + 255;
	  ensures  M_NVAVADH:      EqualBits(stream, pos + 250, pos + 255, p->M_NVAVADH);
	  ensures  M_NVAVADH:      UpperBitsNotSet(p->M_NVAVADH, 5);
	*/
	{ p->M_NVAVADH		= Bitstream_Read(stream, 5); }

	/*@
	  requires M_NVEBCL:       stream->bitpos == pos + 255;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_NVEBCL;
	  ensures  M_NVEBCL:       stream->bitpos == pos + 259;
	  ensures  M_NVEBCL:       EqualBits(stream, pos + 255, pos + 259, p->M_NVEBCL);
	  ensures  M_NVEBCL:       UpperBitsNotSet(p->M_NVEBCL, 4);
	*/
	{ p->M_NVEBCL		= Bitstream_Read(stream, 4); }

	/*@
	  requires Q_NVKINT:       stream->bitpos == pos + 259;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVKINT;
	  ensures  Q_NVKINT:       stream->bitpos == pos + 260;
	  ensures  Q_NVKINT:       EqualBits(stream, pos + 259, pos + 260, p->Q_NVKINT);
	  ensures  Q_NVKINT:       UpperBitsNotSet(p->Q_NVKINT, 1);
	*/
	{ p->Q_NVKINT		= Bitstream_Read(stream, 1); }

        if (p->Q_NVKINT == 1)
        {
	{ p->Q_NVKVINTSET		= Bitstream_Read(stream, 2); }

        if (p->Q_NVKVINTSET == 1)
        {
	{ p->A_NVP12		= Bitstream_Read(stream, 6); }

	{ p->A_NVP23		= Bitstream_Read(stream, 6); }
        }

	{ p->V_NVKVINT		= Bitstream_Read(stream, 7); }

	{ p->M_NVKVINT		= Bitstream_Read(stream, 7); }

	{ p->N_ITER_2		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_2; ++i)
        {
            National_Values_Core_2_Decoder(stream, &(p->sub_2[i]));
        }
	{ p->N_ITER_3		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_3; ++i)
        {
            National_Values_Core_3_Decoder(stream, &(p->sub_3[i]));
        }
	{ p->L_NVKRINT		= Bitstream_Read(stream, 5); }

	{ p->M_NVKRINT		= Bitstream_Read(stream, 5); }

	{ p->N_ITER_4		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_4; ++i)
        {
            National_Values_Core_4_Decoder(stream, &(p->sub_4[i]));
        }
	{ p->M_NVKTINT		= Bitstream_Read(stream, 5); }
        }

        //@ assert Q_DIR:             EqualBits(stream, pos + 28,  pos + 30,  p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 30,  pos + 43,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 43,  pos + 45,  p->Q_SCALE);
        //@ assert D_VALIDNV:         EqualBits(stream, pos + 45,  pos + 60,  p->D_VALIDNV);
        //@ assert NID_C:             EqualBits(stream, pos + 60,  pos + 70,  p->NID_C);
        //@ assert V_NVSHUNT:         EqualBits(stream, pos + 85,  pos + 92,  p->V_NVSHUNT);
        //@ assert V_NVSTFF:          EqualBits(stream, pos + 92,  pos + 99,  p->V_NVSTFF);
        //@ assert V_NVONSIGHT:       EqualBits(stream, pos + 99,  pos + 106, p->V_NVONSIGHT);
        //@ assert V_NVLIMSUPERV:     EqualBits(stream, pos + 106, pos + 113, p->V_NVLIMSUPERV);
        //@ assert V_NVUNFIT:         EqualBits(stream, pos + 113, pos + 120, p->V_NVUNFIT);
        //@ assert V_NVREL:           EqualBits(stream, pos + 120, pos + 127, p->V_NVREL);
        //@ assert D_NVROLL:          EqualBits(stream, pos + 127, pos + 142, p->D_NVROLL);
        //@ assert Q_NVSBTSMPERM:     EqualBits(stream, pos + 142, pos + 143, p->Q_NVSBTSMPERM);
        //@ assert Q_NVEMRRLS:        EqualBits(stream, pos + 143, pos + 144, p->Q_NVEMRRLS);
        //@ assert Q_NVGUIPERM:       EqualBits(stream, pos + 144, pos + 145, p->Q_NVGUIPERM);
        //@ assert Q_NVSBFBPERM:      EqualBits(stream, pos + 145, pos + 146, p->Q_NVSBFBPERM);
        //@ assert Q_NVINHSMICPERM:   EqualBits(stream, pos + 146, pos + 147, p->Q_NVINHSMICPERM);
        //@ assert V_NVALLOWOVTRP:    EqualBits(stream, pos + 147, pos + 154, p->V_NVALLOWOVTRP);
        //@ assert V_NVSUPOVTRP:      EqualBits(stream, pos + 154, pos + 161, p->V_NVSUPOVTRP);
        //@ assert D_NVOVTRP:         EqualBits(stream, pos + 161, pos + 176, p->D_NVOVTRP);
        //@ assert T_NVOVTRP:         EqualBits(stream, pos + 176, pos + 184, p->T_NVOVTRP);
        //@ assert D_NVPOTRP:         EqualBits(stream, pos + 184, pos + 199, p->D_NVPOTRP);
        //@ assert M_NVCONTACT:       EqualBits(stream, pos + 199, pos + 201, p->M_NVCONTACT);
        //@ assert T_NVCONTACT:       EqualBits(stream, pos + 201, pos + 209, p->T_NVCONTACT);
        //@ assert M_NVDERUN:         EqualBits(stream, pos + 209, pos + 210, p->M_NVDERUN);
        //@ assert D_NVSTFF:          EqualBits(stream, pos + 210, pos + 225, p->D_NVSTFF);
        //@ assert Q_NVDRIVER_ADHES:  EqualBits(stream, pos + 225, pos + 226, p->Q_NVDRIVER_ADHES);
        //@ assert A_NVMAXREDADH1:    EqualBits(stream, pos + 226, pos + 232, p->A_NVMAXREDADH1);
        //@ assert A_NVMAXREDADH2:    EqualBits(stream, pos + 232, pos + 238, p->A_NVMAXREDADH2);
        //@ assert A_NVMAXREDADH3:    EqualBits(stream, pos + 238, pos + 244, p->A_NVMAXREDADH3);
        //@ assert Q_NVLOCACC:        EqualBits(stream, pos + 244, pos + 250, p->Q_NVLOCACC);
        //@ assert M_NVAVADH:         EqualBits(stream, pos + 250, pos + 255, p->M_NVAVADH);
        //@ assert M_NVEBCL:          EqualBits(stream, pos + 255, pos + 259, p->M_NVEBCL);
        //@ assert Q_NVKINT:          EqualBits(stream, pos + 259, pos + 260, p->Q_NVKINT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_VALIDNV:         UpperBitsNotSet(p->D_VALIDNV,         15);
        //@ assert NID_C:             UpperBitsNotSet(p->NID_C,             10);
        //@ assert V_NVSHUNT:         UpperBitsNotSet(p->V_NVSHUNT,         7);
        //@ assert V_NVSTFF:          UpperBitsNotSet(p->V_NVSTFF,          7);
        //@ assert V_NVONSIGHT:       UpperBitsNotSet(p->V_NVONSIGHT,       7);
        //@ assert V_NVLIMSUPERV:     UpperBitsNotSet(p->V_NVLIMSUPERV,     7);
        //@ assert V_NVUNFIT:         UpperBitsNotSet(p->V_NVUNFIT,         7);
        //@ assert V_NVREL:           UpperBitsNotSet(p->V_NVREL,           7);
        //@ assert D_NVROLL:          UpperBitsNotSet(p->D_NVROLL,          15);
        //@ assert Q_NVSBTSMPERM:     UpperBitsNotSet(p->Q_NVSBTSMPERM,     1);
        //@ assert Q_NVEMRRLS:        UpperBitsNotSet(p->Q_NVEMRRLS,        1);
        //@ assert Q_NVGUIPERM:       UpperBitsNotSet(p->Q_NVGUIPERM,       1);
        //@ assert Q_NVSBFBPERM:      UpperBitsNotSet(p->Q_NVSBFBPERM,      1);
        //@ assert Q_NVINHSMICPERM:   UpperBitsNotSet(p->Q_NVINHSMICPERM,   1);
        //@ assert V_NVALLOWOVTRP:    UpperBitsNotSet(p->V_NVALLOWOVTRP,    7);
        //@ assert V_NVSUPOVTRP:      UpperBitsNotSet(p->V_NVSUPOVTRP,      7);
        //@ assert D_NVOVTRP:         UpperBitsNotSet(p->D_NVOVTRP,         15);
        //@ assert T_NVOVTRP:         UpperBitsNotSet(p->T_NVOVTRP,         8);
        //@ assert D_NVPOTRP:         UpperBitsNotSet(p->D_NVPOTRP,         15);
        //@ assert M_NVCONTACT:       UpperBitsNotSet(p->M_NVCONTACT,       2);
        //@ assert T_NVCONTACT:       UpperBitsNotSet(p->T_NVCONTACT,       8);
        //@ assert M_NVDERUN:         UpperBitsNotSet(p->M_NVDERUN,         1);
        //@ assert D_NVSTFF:          UpperBitsNotSet(p->D_NVSTFF,          15);
        //@ assert Q_NVDRIVER_ADHES:  UpperBitsNotSet(p->Q_NVDRIVER_ADHES,  1);
        //@ assert A_NVMAXREDADH1:    UpperBitsNotSet(p->A_NVMAXREDADH1,    6);
        //@ assert A_NVMAXREDADH2:    UpperBitsNotSet(p->A_NVMAXREDADH2,    6);
        //@ assert A_NVMAXREDADH3:    UpperBitsNotSet(p->A_NVMAXREDADH3,    6);
        //@ assert Q_NVLOCACC:        UpperBitsNotSet(p->Q_NVLOCACC,        6);
        //@ assert M_NVAVADH:         UpperBitsNotSet(p->M_NVAVADH,         5);
        //@ assert M_NVEBCL:          UpperBitsNotSet(p->M_NVEBCL,          4);
        //@ assert Q_NVKINT:          UpperBitsNotSet(p->Q_NVKINT,          1);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

