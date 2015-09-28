
#include "Axle_Load_Speed_Profile_Core_2.h"
#include "Bit64.h"

int Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_2* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_AXLELOAD,        15);
    status = status && UpperBitsNotSet64(p->L_AXLELOAD,        15);
    status = status && UpperBitsNotSet64(p->Q_FRONT,           1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_2_1,        5) ;
    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        status = status && Axle_Load_Speed_Profile_Core_2_1_UpperBitsNotSet(&(p->sub_2_1[i]));
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

int Axle_Load_Speed_Profile_Core_2_Encode_Bit(Bitstream* stream, const Axle_Load_Speed_Profile_Core_2* p)
{
    if (Bitstream_Normal(stream, AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_BITSIZE))
    {
        if (Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_AXLELOAD);
            Bitstream_Write(stream, 15, p->L_AXLELOAD);
            Bitstream_Write(stream, 1,  p->Q_FRONT);
            Bitstream_Write(stream, 5,  p->N_ITER_2_1);
            for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
            {
                Axle_Load_Speed_Profile_Core_2_1_Encode_Bit(stream, &(p->sub_2_1[i]));
            }


            //@ assert D_AXLELOAD:        EqualBits(stream, pos,       pos + 15,  p->D_AXLELOAD);
            //@ assert L_AXLELOAD:        EqualBits(stream, pos + 15,  pos + 30,  p->L_AXLELOAD);
            //@ assert Q_FRONT:           EqualBits(stream, pos + 30,  pos + 31,  p->Q_FRONT);

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

int Axle_Load_Speed_Profile_Core_2_Decode_Bit(Bitstream* stream, Axle_Load_Speed_Profile_Core_2* p)
{
    if (Bitstream_Normal(stream, AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_AXLELOAD:     stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->D_AXLELOAD;
          ensures  D_AXLELOAD:     stream->bitpos == pos + 15;
          ensures  D_AXLELOAD:     EqualBits(stream, pos + 0, pos + 15, p->D_AXLELOAD);
          ensures  D_AXLELOAD:     UpperBitsNotSet(p->D_AXLELOAD, 15);
        */
        {
            p->D_AXLELOAD        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_AXLELOAD:     stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->L_AXLELOAD;
          ensures  L_AXLELOAD:     stream->bitpos == pos + 30;
          ensures  L_AXLELOAD:     EqualBits(stream, pos + 15, pos + 30, p->L_AXLELOAD);
          ensures  L_AXLELOAD:     UpperBitsNotSet(p->L_AXLELOAD, 15);
        */
        {
            p->L_AXLELOAD        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_FRONT:        stream->bitpos == pos + 30;
          assigns                  stream->bitpos;
          assigns                  p->Q_FRONT;
          ensures  Q_FRONT:        stream->bitpos == pos + 31;
          ensures  Q_FRONT:        EqualBits(stream, pos + 30, pos + 31, p->Q_FRONT);
          ensures  Q_FRONT:        UpperBitsNotSet(p->Q_FRONT, 1);
        */
        {
            p->Q_FRONT        = Bitstream_Read(stream, 1);
        }

    {
            p->N_ITER_2_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
        {
            Axle_Load_Speed_Profile_Core_2_1_Decode_Bit(stream, &(p->sub_2_1[i]));
        }
        //@ assert D_AXLELOAD:        EqualBits(stream, pos,       pos + 15,  p->D_AXLELOAD);
        //@ assert L_AXLELOAD:        EqualBits(stream, pos + 15,  pos + 30,  p->L_AXLELOAD);
        //@ assert Q_FRONT:           EqualBits(stream, pos + 30,  pos + 31,  p->Q_FRONT);

        //@ assert D_AXLELOAD:        UpperBitsNotSet(p->D_AXLELOAD,        15);
        //@ assert L_AXLELOAD:        UpperBitsNotSet(p->L_AXLELOAD,        15);
        //@ assert Q_FRONT:           UpperBitsNotSet(p->Q_FRONT,           1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Axle_Load_Speed_Profile_Core_2_Encode_Int(PacketInfo* data, kcg_int* stream, const Axle_Load_Speed_Profile_Core_2* p)
{
    stream[data->startAddress++] = p->D_AXLELOAD;
    stream[data->startAddress++] = p->L_AXLELOAD;
    stream[data->startAddress++] = p->Q_FRONT;
    stream[data->startAddress++] = p->N_ITER_2_1;

    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        Axle_Load_Speed_Profile_Core_2_1_Encode_Int(data, stream, &(p->sub_2_1[i]));
    }

    return 1;
}

int Axle_Load_Speed_Profile_Core_2_Decode_Int(PacketInfo* data, const kcg_int* stream, Axle_Load_Speed_Profile_Core_2* p)
{
    p->D_AXLELOAD = stream[data->startAddress++];
    p->L_AXLELOAD = stream[data->startAddress++];
    p->Q_FRONT = stream[data->startAddress++];
    p->N_ITER_2_1 = stream[data->startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        Axle_Load_Speed_Profile_Core_2_1_Decode_Int(data, stream, &(p->sub_2_1[i]));
    }

    return 1;
}

