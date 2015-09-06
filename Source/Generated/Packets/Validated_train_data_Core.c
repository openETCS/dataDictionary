
#include "Validated_train_data_Core.h"
#include "Bit64.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"
#include "Bitstream_Normal.h"

int Validated_train_data_UpperBitsNotSet(const Validated_train_data_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NC_CDTRAIN,        4) ;
    status = status && UpperBitsNotSet64(p->NC_TRAIN,          15);
    status = status && UpperBitsNotSet64(p->L_TRAIN,           12);
    status = status && UpperBitsNotSet64(p->V_MAXTRAIN,        7) ;
    status = status && UpperBitsNotSet64(p->M_LOADINGGAUGE,    8) ;
    status = status && UpperBitsNotSet64(p->M_AXLELOADCAT,     7) ;
    status = status && UpperBitsNotSet64(p->M_AIRTIGHT,        2) ;
    status = status && UpperBitsNotSet64(p->N_AXLE,            10);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Validated_train_data_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->N_ITER_2,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        status = status && Validated_train_data_Core_2_UpperBitsNotSet(&(p->sub_2[i]));
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

int Validated_train_data_Encoder(Bitstream* stream, const Validated_train_data_Core* p)
{
    if (Bitstream_Normal(stream, VALIDATED_TRAIN_DATA_CORE_BITSIZE))
    {
        if (Validated_train_data_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 4,  p->NC_CDTRAIN);
            Bitstream_Write(stream, 15, p->NC_TRAIN);
            Bitstream_Write(stream, 12, p->L_TRAIN);
            Bitstream_Write(stream, 7,  p->V_MAXTRAIN);
            Bitstream_Write(stream, 8,  p->M_LOADINGGAUGE);
            Bitstream_Write(stream, 7,  p->M_AXLELOADCAT);
            Bitstream_Write(stream, 2,  p->M_AIRTIGHT);
            Bitstream_Write(stream, 10, p->N_AXLE);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Validated_train_data_Core_1_Encoder(stream, &(p->sub_1[i]));
            }
            Bitstream_Write(stream, 5,  p->N_ITER_2);
            for (uint32_t i = 0; i < p->N_ITER_2; ++i)
            {
                Validated_train_data_Core_2_Encoder(stream, &(p->sub_2[i]));
            }


            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert NC_CDTRAIN:        EqualBits(stream, pos + 13,  pos + 17,  p->NC_CDTRAIN);
            //@ assert NC_TRAIN:          EqualBits(stream, pos + 17,  pos + 32,  p->NC_TRAIN);
            //@ assert L_TRAIN:           EqualBits(stream, pos + 32,  pos + 44,  p->L_TRAIN);
            //@ assert V_MAXTRAIN:        EqualBits(stream, pos + 44,  pos + 51,  p->V_MAXTRAIN);
            //@ assert M_LOADINGGAUGE:    EqualBits(stream, pos + 51,  pos + 59,  p->M_LOADINGGAUGE);
            //@ assert M_AXLELOADCAT:     EqualBits(stream, pos + 59,  pos + 66,  p->M_AXLELOADCAT);
            //@ assert M_AIRTIGHT:        EqualBits(stream, pos + 66,  pos + 68,  p->M_AIRTIGHT);
            //@ assert N_AXLE:            EqualBits(stream, pos + 68,  pos + 78,  p->N_AXLE);

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

int Validated_train_data_Decoder(Bitstream* stream, Validated_train_data_Core* p)
{
    if (Bitstream_Normal(stream, VALIDATED_TRAIN_DATA_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires L_PACKET:       stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_PACKET;
	  ensures  L_PACKET:       stream->bitpos == pos + 13;
	  ensures  L_PACKET:       EqualBits(stream, pos + 0, pos + 13, p->L_PACKET);
	  ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
	*/
	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	/*@
	  requires NC_CDTRAIN:     stream->bitpos == pos + 13;
	  assigns        	   stream->bitpos;
	  assigns		   p->NC_CDTRAIN;
	  ensures  NC_CDTRAIN:     stream->bitpos == pos + 17;
	  ensures  NC_CDTRAIN:     EqualBits(stream, pos + 13, pos + 17, p->NC_CDTRAIN);
	  ensures  NC_CDTRAIN:     UpperBitsNotSet(p->NC_CDTRAIN, 4);
	*/
	{ p->NC_CDTRAIN		= Bitstream_Read(stream, 4); }

	/*@
	  requires NC_TRAIN:       stream->bitpos == pos + 17;
	  assigns        	   stream->bitpos;
	  assigns		   p->NC_TRAIN;
	  ensures  NC_TRAIN:       stream->bitpos == pos + 32;
	  ensures  NC_TRAIN:       EqualBits(stream, pos + 17, pos + 32, p->NC_TRAIN);
	  ensures  NC_TRAIN:       UpperBitsNotSet(p->NC_TRAIN, 15);
	*/
	{ p->NC_TRAIN		= Bitstream_Read(stream, 15); }

	/*@
	  requires L_TRAIN:        stream->bitpos == pos + 32;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_TRAIN;
	  ensures  L_TRAIN:        stream->bitpos == pos + 44;
	  ensures  L_TRAIN:        EqualBits(stream, pos + 32, pos + 44, p->L_TRAIN);
	  ensures  L_TRAIN:        UpperBitsNotSet(p->L_TRAIN, 12);
	*/
	{ p->L_TRAIN		= Bitstream_Read(stream, 12); }

	/*@
	  requires V_MAXTRAIN:     stream->bitpos == pos + 44;
	  assigns        	   stream->bitpos;
	  assigns		   p->V_MAXTRAIN;
	  ensures  V_MAXTRAIN:     stream->bitpos == pos + 51;
	  ensures  V_MAXTRAIN:     EqualBits(stream, pos + 44, pos + 51, p->V_MAXTRAIN);
	  ensures  V_MAXTRAIN:     UpperBitsNotSet(p->V_MAXTRAIN, 7);
	*/
	{ p->V_MAXTRAIN		= Bitstream_Read(stream, 7); }

	/*@
	  requires M_LOADINGGAUGE: stream->bitpos == pos + 51;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_LOADINGGAUGE;
	  ensures  M_LOADINGGAUGE: stream->bitpos == pos + 59;
	  ensures  M_LOADINGGAUGE: EqualBits(stream, pos + 51, pos + 59, p->M_LOADINGGAUGE);
	  ensures  M_LOADINGGAUGE: UpperBitsNotSet(p->M_LOADINGGAUGE, 8);
	*/
	{ p->M_LOADINGGAUGE		= Bitstream_Read(stream, 8); }

	/*@
	  requires M_AXLELOADCAT:  stream->bitpos == pos + 59;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_AXLELOADCAT;
	  ensures  M_AXLELOADCAT:  stream->bitpos == pos + 66;
	  ensures  M_AXLELOADCAT:  EqualBits(stream, pos + 59, pos + 66, p->M_AXLELOADCAT);
	  ensures  M_AXLELOADCAT:  UpperBitsNotSet(p->M_AXLELOADCAT, 7);
	*/
	{ p->M_AXLELOADCAT		= Bitstream_Read(stream, 7); }

	/*@
	  requires M_AIRTIGHT:     stream->bitpos == pos + 66;
	  assigns        	   stream->bitpos;
	  assigns		   p->M_AIRTIGHT;
	  ensures  M_AIRTIGHT:     stream->bitpos == pos + 68;
	  ensures  M_AIRTIGHT:     EqualBits(stream, pos + 66, pos + 68, p->M_AIRTIGHT);
	  ensures  M_AIRTIGHT:     UpperBitsNotSet(p->M_AIRTIGHT, 2);
	*/
	{ p->M_AIRTIGHT		= Bitstream_Read(stream, 2); }

	/*@
	  requires N_AXLE:         stream->bitpos == pos + 68;
	  assigns        	   stream->bitpos;
	  assigns		   p->N_AXLE;
	  ensures  N_AXLE:         stream->bitpos == pos + 78;
	  ensures  N_AXLE:         EqualBits(stream, pos + 68, pos + 78, p->N_AXLE);
	  ensures  N_AXLE:         UpperBitsNotSet(p->N_AXLE, 10);
	*/
	{ p->N_AXLE		= Bitstream_Read(stream, 10); }

	{ p->N_ITER_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Validated_train_data_Core_1_Decoder(stream, &(p->sub_1[i]));
        }
	{ p->N_ITER_2		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_2; ++i)
        {
            Validated_train_data_Core_2_Decoder(stream, &(p->sub_2[i]));
        }
        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert NC_CDTRAIN:        EqualBits(stream, pos + 13,  pos + 17,  p->NC_CDTRAIN);
        //@ assert NC_TRAIN:          EqualBits(stream, pos + 17,  pos + 32,  p->NC_TRAIN);
        //@ assert L_TRAIN:           EqualBits(stream, pos + 32,  pos + 44,  p->L_TRAIN);
        //@ assert V_MAXTRAIN:        EqualBits(stream, pos + 44,  pos + 51,  p->V_MAXTRAIN);
        //@ assert M_LOADINGGAUGE:    EqualBits(stream, pos + 51,  pos + 59,  p->M_LOADINGGAUGE);
        //@ assert M_AXLELOADCAT:     EqualBits(stream, pos + 59,  pos + 66,  p->M_AXLELOADCAT);
        //@ assert M_AIRTIGHT:        EqualBits(stream, pos + 66,  pos + 68,  p->M_AIRTIGHT);
        //@ assert N_AXLE:            EqualBits(stream, pos + 68,  pos + 78,  p->N_AXLE);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NC_CDTRAIN:        UpperBitsNotSet(p->NC_CDTRAIN,        4);
        //@ assert NC_TRAIN:          UpperBitsNotSet(p->NC_TRAIN,          15);
        //@ assert L_TRAIN:           UpperBitsNotSet(p->L_TRAIN,           12);
        //@ assert V_MAXTRAIN:        UpperBitsNotSet(p->V_MAXTRAIN,        7);
        //@ assert M_LOADINGGAUGE:    UpperBitsNotSet(p->M_LOADINGGAUGE,    8);
        //@ assert M_AXLELOADCAT:     UpperBitsNotSet(p->M_AXLELOADCAT,     7);
        //@ assert M_AIRTIGHT:        UpperBitsNotSet(p->M_AIRTIGHT,        2);
        //@ assert N_AXLE:            UpperBitsNotSet(p->N_AXLE,            10);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

