
#include "ValidatedTrainData.h"
#include "Bit64.h"

ValidatedTrainData* ValidatedTrainData_New(void)
{
    void* raw = malloc(sizeof(ValidatedTrainData));
    ValidatedTrainData* ptr = (ValidatedTrainData*)raw;
    ValidatedTrainData_Init(ptr);
    return ptr;
}


void ValidatedTrainData_Delete(ValidatedTrainData* ptr)
{
    free(ptr);
}


int ValidatedTrainData_UpperBitsNotSet(const ValidatedTrainData* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_OPERATIONAL,   32);
    status = status && UpperBitsNotSet64(p->NC_TRAIN,          15);
    status = status && UpperBitsNotSet64(p->L_TRAIN,           12);
    status = status && UpperBitsNotSet64(p->V_MAXTRAIN,        7) ;
    status = status && UpperBitsNotSet64(p->M_LOADINGGAUGE,    8) ;
    status = status && UpperBitsNotSet64(p->M_AXLELOAD,        7) ;
    status = status && UpperBitsNotSet64(p->M_AIRTIGHT,        2) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && ValidatedTrainData_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->N_ITER_2,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        status = status && ValidatedTrainData_2_UpperBitsNotSet(&(p->sub_2[i]));
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

int ValidatedTrainData_EncodeBit(const ValidatedTrainData* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, VALIDATEDTRAINDATA_BITSIZE))
    {
        if (ValidatedTrainData_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 32, p->NID_OPERATIONAL);
            Bitstream_Write(stream, 15, p->NC_TRAIN);
            Bitstream_Write(stream, 12, p->L_TRAIN);
            Bitstream_Write(stream, 7,  p->V_MAXTRAIN);
            Bitstream_Write(stream, 8,  p->M_LOADINGGAUGE);
            Bitstream_Write(stream, 7,  p->M_AXLELOAD);
            Bitstream_Write(stream, 2,  p->M_AIRTIGHT);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                ValidatedTrainData_1_EncodeBit(&(p->sub_1[i]), stream);
            }
            Bitstream_Write(stream, 5,  p->N_ITER_2);
            for (uint32_t i = 0; i < p->N_ITER_2; ++i)
            {
                ValidatedTrainData_2_EncodeBit(&(p->sub_2[i]), stream);
            }


            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 13,  pos + 45,  p->NID_OPERATIONAL);
            //@ assert NC_TRAIN:          EqualBits(stream, pos + 45,  pos + 60,  p->NC_TRAIN);
            //@ assert L_TRAIN:           EqualBits(stream, pos + 60,  pos + 72,  p->L_TRAIN);
            //@ assert V_MAXTRAIN:        EqualBits(stream, pos + 72,  pos + 79,  p->V_MAXTRAIN);
            //@ assert M_LOADINGGAUGE:    EqualBits(stream, pos + 79,  pos + 87,  p->M_LOADINGGAUGE);
            //@ assert M_AXLELOAD:        EqualBits(stream, pos + 87,  pos + 94,  p->M_AXLELOAD);
            //@ assert M_AIRTIGHT:        EqualBits(stream, pos + 94,  pos + 96,  p->M_AIRTIGHT);

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

int ValidatedTrainData_DecodeBit(ValidatedTrainData* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, VALIDATEDTRAINDATA_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires L_PACKET:       stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->L_PACKET;
          ensures  L_PACKET:       stream->bitpos == pos + 13;
          ensures  L_PACKET:       EqualBits(stream, pos + 0, pos + 13, p->L_PACKET);
          ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
        */
        {
            p->L_PACKET        = Bitstream_Read(stream, 13);
        }

        /*@
          requires NID_OPERATIONAL: stream->bitpos == pos + 13;
          assigns                  stream->bitpos;
          assigns                  p->NID_OPERATIONAL;
          ensures  NID_OPERATIONAL: stream->bitpos == pos + 45;
          ensures  NID_OPERATIONAL: EqualBits(stream, pos + 13, pos + 45, p->NID_OPERATIONAL);
          ensures  NID_OPERATIONAL: UpperBitsNotSet(p->NID_OPERATIONAL, 32);
        */
        {
            p->NID_OPERATIONAL        = Bitstream_Read(stream, 32);
        }

        /*@
          requires NC_TRAIN:       stream->bitpos == pos + 45;
          assigns                  stream->bitpos;
          assigns                  p->NC_TRAIN;
          ensures  NC_TRAIN:       stream->bitpos == pos + 60;
          ensures  NC_TRAIN:       EqualBits(stream, pos + 45, pos + 60, p->NC_TRAIN);
          ensures  NC_TRAIN:       UpperBitsNotSet(p->NC_TRAIN, 15);
        */
        {
            p->NC_TRAIN        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_TRAIN:        stream->bitpos == pos + 60;
          assigns                  stream->bitpos;
          assigns                  p->L_TRAIN;
          ensures  L_TRAIN:        stream->bitpos == pos + 72;
          ensures  L_TRAIN:        EqualBits(stream, pos + 60, pos + 72, p->L_TRAIN);
          ensures  L_TRAIN:        UpperBitsNotSet(p->L_TRAIN, 12);
        */
        {
            p->L_TRAIN        = Bitstream_Read(stream, 12);
        }

        /*@
          requires V_MAXTRAIN:     stream->bitpos == pos + 72;
          assigns                  stream->bitpos;
          assigns                  p->V_MAXTRAIN;
          ensures  V_MAXTRAIN:     stream->bitpos == pos + 79;
          ensures  V_MAXTRAIN:     EqualBits(stream, pos + 72, pos + 79, p->V_MAXTRAIN);
          ensures  V_MAXTRAIN:     UpperBitsNotSet(p->V_MAXTRAIN, 7);
        */
        {
            p->V_MAXTRAIN        = Bitstream_Read(stream, 7);
        }

        /*@
          requires M_LOADINGGAUGE: stream->bitpos == pos + 79;
          assigns                  stream->bitpos;
          assigns                  p->M_LOADINGGAUGE;
          ensures  M_LOADINGGAUGE: stream->bitpos == pos + 87;
          ensures  M_LOADINGGAUGE: EqualBits(stream, pos + 79, pos + 87, p->M_LOADINGGAUGE);
          ensures  M_LOADINGGAUGE: UpperBitsNotSet(p->M_LOADINGGAUGE, 8);
        */
        {
            p->M_LOADINGGAUGE        = Bitstream_Read(stream, 8);
        }

        /*@
          requires M_AXLELOAD:     stream->bitpos == pos + 87;
          assigns                  stream->bitpos;
          assigns                  p->M_AXLELOAD;
          ensures  M_AXLELOAD:     stream->bitpos == pos + 94;
          ensures  M_AXLELOAD:     EqualBits(stream, pos + 87, pos + 94, p->M_AXLELOAD);
          ensures  M_AXLELOAD:     UpperBitsNotSet(p->M_AXLELOAD, 7);
        */
        {
            p->M_AXLELOAD        = Bitstream_Read(stream, 7);
        }

        /*@
          requires M_AIRTIGHT:     stream->bitpos == pos + 94;
          assigns                  stream->bitpos;
          assigns                  p->M_AIRTIGHT;
          ensures  M_AIRTIGHT:     stream->bitpos == pos + 96;
          ensures  M_AIRTIGHT:     EqualBits(stream, pos + 94, pos + 96, p->M_AIRTIGHT);
          ensures  M_AIRTIGHT:     UpperBitsNotSet(p->M_AIRTIGHT, 2);
        */
        {
            p->M_AIRTIGHT        = Bitstream_Read(stream, 2);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            ValidatedTrainData_1_DecodeBit(&(p->sub_1[i]), stream);
        }
    {
            p->N_ITER_2        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_2; ++i)
        {
            ValidatedTrainData_2_DecodeBit(&(p->sub_2[i]), stream);
        }
        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert NID_OPERATIONAL:   EqualBits(stream, pos + 13,  pos + 45,  p->NID_OPERATIONAL);
        //@ assert NC_TRAIN:          EqualBits(stream, pos + 45,  pos + 60,  p->NC_TRAIN);
        //@ assert L_TRAIN:           EqualBits(stream, pos + 60,  pos + 72,  p->L_TRAIN);
        //@ assert V_MAXTRAIN:        EqualBits(stream, pos + 72,  pos + 79,  p->V_MAXTRAIN);
        //@ assert M_LOADINGGAUGE:    EqualBits(stream, pos + 79,  pos + 87,  p->M_LOADINGGAUGE);
        //@ assert M_AXLELOAD:        EqualBits(stream, pos + 87,  pos + 94,  p->M_AXLELOAD);
        //@ assert M_AIRTIGHT:        EqualBits(stream, pos + 94,  pos + 96,  p->M_AIRTIGHT);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_OPERATIONAL:   UpperBitsNotSet(p->NID_OPERATIONAL,   32);
        //@ assert NC_TRAIN:          UpperBitsNotSet(p->NC_TRAIN,          15);
        //@ assert L_TRAIN:           UpperBitsNotSet(p->L_TRAIN,           12);
        //@ assert V_MAXTRAIN:        UpperBitsNotSet(p->V_MAXTRAIN,        7);
        //@ assert M_LOADINGGAUGE:    UpperBitsNotSet(p->M_LOADINGGAUGE,    8);
        //@ assert M_AXLELOAD:        UpperBitsNotSet(p->M_AXLELOAD,        7);
        //@ assert M_AIRTIGHT:        UpperBitsNotSet(p->M_AIRTIGHT,        2);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

/*
int ValidatedTrainData_EncodeInt(const ValidatedTrainData* p, PacketInfo* data, kcg_int* stream)
{

}

int ValidatedTrainData_DecodeInt(ValidatedTrainData* p, PacketInfo* data, kcg_int* stream)
{

}
*/

