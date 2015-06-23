
#include "National_Values_Decoder.h"
#include "Bitstream_Read.h"
#include "National_Values_Core_1_Decoder.h"
#include "National_Values_Core_2_Decoder.h"
#include "National_Values_Core_3_Decoder.h"
#include "National_Values_Core_4_Decoder.h"

int National_Values_Decoder(Bitstream* stream, National_Values_Core* p)
{
    if (NormalBitstream(stream, NATIONAL_VALUES_CORE_BITSIZE))
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
	  requires D_VALIDNV:      stream->bitpos == pos + 17;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_VALIDNV;
	  ensures  D_VALIDNV:      stream->bitpos == pos + 32;
	  ensures  D_VALIDNV:      EqualBits(stream, pos + 17, pos + 32, p->D_VALIDNV);
	  ensures  D_VALIDNV:      UpperBitsNotSet(p->D_VALIDNV, 15);
	*/
	{ p->D_VALIDNV		= Bitstream_Read(stream, 15); }

	/*@
	  requires NID_C:          stream->bitpos == pos + 32;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_C;
	  ensures  NID_C:          stream->bitpos == pos + 42;
	  ensures  NID_C:          EqualBits(stream, pos + 32, pos + 42, p->NID_C);
	  ensures  NID_C:          UpperBitsNotSet(p->NID_C, 10);
	*/
	{ p->NID_C		= Bitstream_Read(stream, 10); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            National_Values_Core_1_Decoder(stream, &(p->sub_1[i]));
        }
	/*@
	  requires V_NVSHUNT:      stream->bitpos == pos + 57;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVSHUNT;
	  ensures  V_NVSHUNT:      stream->bitpos == pos + 64;
	  ensures  V_NVSHUNT:      EqualBits(stream, pos + 57, pos + 64, p->V_NVSHUNT);
	  ensures  V_NVSHUNT:      UpperBitsNotSet(p->V_NVSHUNT, 7);
	*/
	{ p->V_NVSHUNT		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_NVSTFF:       stream->bitpos == pos + 64;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVSTFF;
	  ensures  V_NVSTFF:       stream->bitpos == pos + 71;
	  ensures  V_NVSTFF:       EqualBits(stream, pos + 64, pos + 71, p->V_NVSTFF);
	  ensures  V_NVSTFF:       UpperBitsNotSet(p->V_NVSTFF, 7);
	*/
	{ p->V_NVSTFF		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_NVONSIGHT:    stream->bitpos == pos + 71;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVONSIGHT;
	  ensures  V_NVONSIGHT:    stream->bitpos == pos + 78;
	  ensures  V_NVONSIGHT:    EqualBits(stream, pos + 71, pos + 78, p->V_NVONSIGHT);
	  ensures  V_NVONSIGHT:    UpperBitsNotSet(p->V_NVONSIGHT, 7);
	*/
	{ p->V_NVONSIGHT		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_NVLIMSUPERV:  stream->bitpos == pos + 78;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVLIMSUPERV;
	  ensures  V_NVLIMSUPERV:  stream->bitpos == pos + 85;
	  ensures  V_NVLIMSUPERV:  EqualBits(stream, pos + 78, pos + 85, p->V_NVLIMSUPERV);
	  ensures  V_NVLIMSUPERV:  UpperBitsNotSet(p->V_NVLIMSUPERV, 7);
	*/
	{ p->V_NVLIMSUPERV		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_NVUNFIT:      stream->bitpos == pos + 85;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVUNFIT;
	  ensures  V_NVUNFIT:      stream->bitpos == pos + 92;
	  ensures  V_NVUNFIT:      EqualBits(stream, pos + 85, pos + 92, p->V_NVUNFIT);
	  ensures  V_NVUNFIT:      UpperBitsNotSet(p->V_NVUNFIT, 7);
	*/
	{ p->V_NVUNFIT		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_NVREL:        stream->bitpos == pos + 92;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVREL;
	  ensures  V_NVREL:        stream->bitpos == pos + 99;
	  ensures  V_NVREL:        EqualBits(stream, pos + 92, pos + 99, p->V_NVREL);
	  ensures  V_NVREL:        UpperBitsNotSet(p->V_NVREL, 7);
	*/
	{ p->V_NVREL		= Bitstream_Read(stream, 7); }

	/*@
	  requires D_NVROLL:       stream->bitpos == pos + 99;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_NVROLL;
	  ensures  D_NVROLL:       stream->bitpos == pos + 114;
	  ensures  D_NVROLL:       EqualBits(stream, pos + 99, pos + 114, p->D_NVROLL);
	  ensures  D_NVROLL:       UpperBitsNotSet(p->D_NVROLL, 15);
	*/
	{ p->D_NVROLL		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_NVSBTSMPERM:  stream->bitpos == pos + 114;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVSBTSMPERM;
	  ensures  Q_NVSBTSMPERM:  stream->bitpos == pos + 115;
	  ensures  Q_NVSBTSMPERM:  EqualBits(stream, pos + 114, pos + 115, p->Q_NVSBTSMPERM);
	  ensures  Q_NVSBTSMPERM:  UpperBitsNotSet(p->Q_NVSBTSMPERM, 1);
	*/
	{ p->Q_NVSBTSMPERM		= Bitstream_Read(stream, 1); }

	/*@
	  requires Q_NVEMRRLS:     stream->bitpos == pos + 115;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVEMRRLS;
	  ensures  Q_NVEMRRLS:     stream->bitpos == pos + 116;
	  ensures  Q_NVEMRRLS:     EqualBits(stream, pos + 115, pos + 116, p->Q_NVEMRRLS);
	  ensures  Q_NVEMRRLS:     UpperBitsNotSet(p->Q_NVEMRRLS, 1);
	*/
	{ p->Q_NVEMRRLS		= Bitstream_Read(stream, 1); }

	/*@
	  requires Q_NVGUIPERM:    stream->bitpos == pos + 116;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVGUIPERM;
	  ensures  Q_NVGUIPERM:    stream->bitpos == pos + 117;
	  ensures  Q_NVGUIPERM:    EqualBits(stream, pos + 116, pos + 117, p->Q_NVGUIPERM);
	  ensures  Q_NVGUIPERM:    UpperBitsNotSet(p->Q_NVGUIPERM, 1);
	*/
	{ p->Q_NVGUIPERM		= Bitstream_Read(stream, 1); }

	/*@
	  requires Q_NVSBFBPERM:   stream->bitpos == pos + 117;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVSBFBPERM;
	  ensures  Q_NVSBFBPERM:   stream->bitpos == pos + 118;
	  ensures  Q_NVSBFBPERM:   EqualBits(stream, pos + 117, pos + 118, p->Q_NVSBFBPERM);
	  ensures  Q_NVSBFBPERM:   UpperBitsNotSet(p->Q_NVSBFBPERM, 1);
	*/
	{ p->Q_NVSBFBPERM		= Bitstream_Read(stream, 1); }

	/*@
	  requires Q_NVINHSMICPERM: stream->bitpos == pos + 118;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVINHSMICPERM;
	  ensures  Q_NVINHSMICPERM: stream->bitpos == pos + 119;
	  ensures  Q_NVINHSMICPERM: EqualBits(stream, pos + 118, pos + 119, p->Q_NVINHSMICPERM);
	  ensures  Q_NVINHSMICPERM: UpperBitsNotSet(p->Q_NVINHSMICPERM, 1);
	*/
	{ p->Q_NVINHSMICPERM		= Bitstream_Read(stream, 1); }

	/*@
	  requires V_NVALLOWOVTRP: stream->bitpos == pos + 119;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVALLOWOVTRP;
	  ensures  V_NVALLOWOVTRP: stream->bitpos == pos + 126;
	  ensures  V_NVALLOWOVTRP: EqualBits(stream, pos + 119, pos + 126, p->V_NVALLOWOVTRP);
	  ensures  V_NVALLOWOVTRP: UpperBitsNotSet(p->V_NVALLOWOVTRP, 7);
	*/
	{ p->V_NVALLOWOVTRP		= Bitstream_Read(stream, 7); }

	/*@
	  requires V_NVSUPOVTRP:   stream->bitpos == pos + 126;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_NVSUPOVTRP;
	  ensures  V_NVSUPOVTRP:   stream->bitpos == pos + 133;
	  ensures  V_NVSUPOVTRP:   EqualBits(stream, pos + 126, pos + 133, p->V_NVSUPOVTRP);
	  ensures  V_NVSUPOVTRP:   UpperBitsNotSet(p->V_NVSUPOVTRP, 7);
	*/
	{ p->V_NVSUPOVTRP		= Bitstream_Read(stream, 7); }

	/*@
	  requires D_NVOVTRP:      stream->bitpos == pos + 133;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_NVOVTRP;
	  ensures  D_NVOVTRP:      stream->bitpos == pos + 148;
	  ensures  D_NVOVTRP:      EqualBits(stream, pos + 133, pos + 148, p->D_NVOVTRP);
	  ensures  D_NVOVTRP:      UpperBitsNotSet(p->D_NVOVTRP, 15);
	*/
	{ p->D_NVOVTRP		= Bitstream_Read(stream, 15); }

	/*@
	  requires T_NVOVTRP:      stream->bitpos == pos + 148;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_NVOVTRP;
	  ensures  T_NVOVTRP:      stream->bitpos == pos + 156;
	  ensures  T_NVOVTRP:      EqualBits(stream, pos + 148, pos + 156, p->T_NVOVTRP);
	  ensures  T_NVOVTRP:      UpperBitsNotSet(p->T_NVOVTRP, 8);
	*/
	{ p->T_NVOVTRP		= Bitstream_Read(stream, 8); }

	/*@
	  requires D_NVPOTRP:      stream->bitpos == pos + 156;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_NVPOTRP;
	  ensures  D_NVPOTRP:      stream->bitpos == pos + 171;
	  ensures  D_NVPOTRP:      EqualBits(stream, pos + 156, pos + 171, p->D_NVPOTRP);
	  ensures  D_NVPOTRP:      UpperBitsNotSet(p->D_NVPOTRP, 15);
	*/
	{ p->D_NVPOTRP		= Bitstream_Read(stream, 15); }

	/*@
	  requires M_NVCONTACT:    stream->bitpos == pos + 171;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_NVCONTACT;
	  ensures  M_NVCONTACT:    stream->bitpos == pos + 173;
	  ensures  M_NVCONTACT:    EqualBits(stream, pos + 171, pos + 173, p->M_NVCONTACT);
	  ensures  M_NVCONTACT:    UpperBitsNotSet(p->M_NVCONTACT, 2);
	*/
	{ p->M_NVCONTACT		= Bitstream_Read(stream, 2); }

	/*@
	  requires T_NVCONTACT:    stream->bitpos == pos + 173;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_NVCONTACT;
	  ensures  T_NVCONTACT:    stream->bitpos == pos + 181;
	  ensures  T_NVCONTACT:    EqualBits(stream, pos + 173, pos + 181, p->T_NVCONTACT);
	  ensures  T_NVCONTACT:    UpperBitsNotSet(p->T_NVCONTACT, 8);
	*/
	{ p->T_NVCONTACT		= Bitstream_Read(stream, 8); }

	/*@
	  requires M_NVDERUN:      stream->bitpos == pos + 181;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_NVDERUN;
	  ensures  M_NVDERUN:      stream->bitpos == pos + 182;
	  ensures  M_NVDERUN:      EqualBits(stream, pos + 181, pos + 182, p->M_NVDERUN);
	  ensures  M_NVDERUN:      UpperBitsNotSet(p->M_NVDERUN, 1);
	*/
	{ p->M_NVDERUN		= Bitstream_Read(stream, 1); }

	/*@
	  requires D_NVSTFF:       stream->bitpos == pos + 182;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_NVSTFF;
	  ensures  D_NVSTFF:       stream->bitpos == pos + 197;
	  ensures  D_NVSTFF:       EqualBits(stream, pos + 182, pos + 197, p->D_NVSTFF);
	  ensures  D_NVSTFF:       UpperBitsNotSet(p->D_NVSTFF, 15);
	*/
	{ p->D_NVSTFF		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_NVDRIVER_ADHES: stream->bitpos == pos + 197;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVDRIVER_ADHES;
	  ensures  Q_NVDRIVER_ADHES: stream->bitpos == pos + 198;
	  ensures  Q_NVDRIVER_ADHES: EqualBits(stream, pos + 197, pos + 198, p->Q_NVDRIVER_ADHES);
	  ensures  Q_NVDRIVER_ADHES: UpperBitsNotSet(p->Q_NVDRIVER_ADHES, 1);
	*/
	{ p->Q_NVDRIVER_ADHES		= Bitstream_Read(stream, 1); }

	/*@
	  requires A_NVMAXREDADH1: stream->bitpos == pos + 198;
	  assigns        	   stream->bitpos;
	  assigns		   p->A_NVMAXREDADH1;
	  ensures  A_NVMAXREDADH1: stream->bitpos == pos + 204;
	  ensures  A_NVMAXREDADH1: EqualBits(stream, pos + 198, pos + 204, p->A_NVMAXREDADH1);
	  ensures  A_NVMAXREDADH1: UpperBitsNotSet(p->A_NVMAXREDADH1, 6);
	*/
	{ p->A_NVMAXREDADH1		= Bitstream_Read(stream, 6); }

	/*@
	  requires A_NVMAXREDADH2: stream->bitpos == pos + 204;
	  assigns        	   stream->bitpos;
	  assigns		   p->A_NVMAXREDADH2;
	  ensures  A_NVMAXREDADH2: stream->bitpos == pos + 210;
	  ensures  A_NVMAXREDADH2: EqualBits(stream, pos + 204, pos + 210, p->A_NVMAXREDADH2);
	  ensures  A_NVMAXREDADH2: UpperBitsNotSet(p->A_NVMAXREDADH2, 6);
	*/
	{ p->A_NVMAXREDADH2		= Bitstream_Read(stream, 6); }

	/*@
	  requires A_NVMAXREDADH3: stream->bitpos == pos + 210;
	  assigns        	   stream->bitpos;
	  assigns		   p->A_NVMAXREDADH3;
	  ensures  A_NVMAXREDADH3: stream->bitpos == pos + 216;
	  ensures  A_NVMAXREDADH3: EqualBits(stream, pos + 210, pos + 216, p->A_NVMAXREDADH3);
	  ensures  A_NVMAXREDADH3: UpperBitsNotSet(p->A_NVMAXREDADH3, 6);
	*/
	{ p->A_NVMAXREDADH3		= Bitstream_Read(stream, 6); }

	/*@
	  requires Q_NVLOCACC:     stream->bitpos == pos + 216;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVLOCACC;
	  ensures  Q_NVLOCACC:     stream->bitpos == pos + 222;
	  ensures  Q_NVLOCACC:     EqualBits(stream, pos + 216, pos + 222, p->Q_NVLOCACC);
	  ensures  Q_NVLOCACC:     UpperBitsNotSet(p->Q_NVLOCACC, 6);
	*/
	{ p->Q_NVLOCACC		= Bitstream_Read(stream, 6); }

	/*@
	  requires M_NVAVADH:      stream->bitpos == pos + 222;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_NVAVADH;
	  ensures  M_NVAVADH:      stream->bitpos == pos + 227;
	  ensures  M_NVAVADH:      EqualBits(stream, pos + 222, pos + 227, p->M_NVAVADH);
	  ensures  M_NVAVADH:      UpperBitsNotSet(p->M_NVAVADH, 5);
	*/
	{ p->M_NVAVADH		= Bitstream_Read(stream, 5); }

	/*@
	  requires M_NVEBCL:       stream->bitpos == pos + 227;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_NVEBCL;
	  ensures  M_NVEBCL:       stream->bitpos == pos + 231;
	  ensures  M_NVEBCL:       EqualBits(stream, pos + 227, pos + 231, p->M_NVEBCL);
	  ensures  M_NVEBCL:       UpperBitsNotSet(p->M_NVEBCL, 4);
	*/
	{ p->M_NVEBCL		= Bitstream_Read(stream, 4); }

	/*@
	  requires Q_NVKINT:       stream->bitpos == pos + 231;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NVKINT;
	  ensures  Q_NVKINT:       stream->bitpos == pos + 232;
	  ensures  Q_NVKINT:       EqualBits(stream, pos + 231, pos + 232, p->Q_NVKINT);
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

