
#include "LevelTransitionOrder.h"
#include "Bit64.h"

LevelTransitionOrder* LevelTransitionOrder_New(void)
{
    void* raw = malloc(sizeof(LevelTransitionOrder));
    LevelTransitionOrder* ptr = (LevelTransitionOrder*)raw;
    LevelTransitionOrder_Init(ptr);
    return ptr;
}


void LevelTransitionOrder_Delete(LevelTransitionOrder* ptr)
{
    free(ptr);
}


int LevelTransitionOrder_UpperBitsNotSet(const LevelTransitionOrder* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_LEVELTR,         15);
    status = status && UpperBitsNotSet64(p->M_LEVELTR,         3) ;
    if (p->M_LEVELTR == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_STM,           8) ;
    }
    status = status && UpperBitsNotSet64(p->L_ACKLEVELTR,      15);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && LevelTransitionOrder_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int LevelTransitionOrder_EncodeBit(const LevelTransitionOrder* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LEVELTRANSITIONORDER_BITSIZE))
    {
        if (LevelTransitionOrder_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_LEVELTR);
            Bitstream_Write(stream, 3,  p->M_LEVELTR);
            if (p->M_LEVELTR == 1)
            {
                Bitstream_Write(stream, 8,  p->NID_STM);
            }

            Bitstream_Write(stream, 15, p->L_ACKLEVELTR);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                LevelTransitionOrder_1_EncodeBit(&(p->sub_1[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_LEVELTR:         EqualBits(stream, pos + 17,  pos + 32,  p->D_LEVELTR);
            //@ assert M_LEVELTR:         EqualBits(stream, pos + 32,  pos + 35,  p->M_LEVELTR);

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

int LevelTransitionOrder_DecodeBit(LevelTransitionOrder* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LEVELTRANSITIONORDER_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires Q_DIR:          stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->Q_DIR;
          ensures  Q_DIR:          stream->bitpos == pos + 2;
          ensures  Q_DIR:          EqualBits(stream, pos + 0, pos + 2, p->Q_DIR);
          ensures  Q_DIR:          UpperBitsNotSet(p->Q_DIR, 2);
        */
        {
            p->Q_DIR        = Bitstream_Read(stream, 2);
        }

        /*@
          requires L_PACKET:       stream->bitpos == pos + 2;
          assigns                  stream->bitpos;
          assigns                  p->L_PACKET;
          ensures  L_PACKET:       stream->bitpos == pos + 15;
          ensures  L_PACKET:       EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
          ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
        */
        {
            p->L_PACKET        = Bitstream_Read(stream, 13);
        }

        /*@
          requires Q_SCALE:        stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_SCALE;
          ensures  Q_SCALE:        stream->bitpos == pos + 17;
          ensures  Q_SCALE:        EqualBits(stream, pos + 15, pos + 17, p->Q_SCALE);
          ensures  Q_SCALE:        UpperBitsNotSet(p->Q_SCALE, 2);
        */
        {
            p->Q_SCALE        = Bitstream_Read(stream, 2);
        }

        /*@
          requires D_LEVELTR:      stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_LEVELTR;
          ensures  D_LEVELTR:      stream->bitpos == pos + 32;
          ensures  D_LEVELTR:      EqualBits(stream, pos + 17, pos + 32, p->D_LEVELTR);
          ensures  D_LEVELTR:      UpperBitsNotSet(p->D_LEVELTR, 15);
        */
        {
            p->D_LEVELTR        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_LEVELTR:      stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->M_LEVELTR;
          ensures  M_LEVELTR:      stream->bitpos == pos + 35;
          ensures  M_LEVELTR:      EqualBits(stream, pos + 32, pos + 35, p->M_LEVELTR);
          ensures  M_LEVELTR:      UpperBitsNotSet(p->M_LEVELTR, 3);
        */
        {
            p->M_LEVELTR        = Bitstream_Read(stream, 3);
        }

        if (p->M_LEVELTR == 1)
        {
            {
                p->NID_STM        = Bitstream_Read(stream, 8);
            }

        }

        {
            p->L_ACKLEVELTR        = Bitstream_Read(stream, 15);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            LevelTransitionOrder_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_LEVELTR:         EqualBits(stream, pos + 17,  pos + 32,  p->D_LEVELTR);
        //@ assert M_LEVELTR:         EqualBits(stream, pos + 32,  pos + 35,  p->M_LEVELTR);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_LEVELTR:         UpperBitsNotSet(p->D_LEVELTR,         15);
        //@ assert M_LEVELTR:         UpperBitsNotSet(p->M_LEVELTR,         3);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int LevelTransitionOrder_EncodeInt(const LevelTransitionOrder* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 41;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->D_LEVELTR;
    stream[startAddress++] = p->M_LEVELTR;
    stream[startAddress++] = p->NID_STM;
    stream[startAddress++] = p->L_ACKLEVELTR;
    stream[startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        LevelTransitionOrder_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int LevelTransitionOrder_DecodeInt(LevelTransitionOrder* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 41)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->D_LEVELTR = stream[startAddress++];
    p->M_LEVELTR = stream[startAddress++];
    p->NID_STM = stream[startAddress++];
    p->L_ACKLEVELTR = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        LevelTransitionOrder_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

