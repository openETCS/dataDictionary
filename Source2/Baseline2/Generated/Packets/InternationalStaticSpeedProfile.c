
#include "InternationalStaticSpeedProfile.h"
#include "Bit64.h"

InternationalStaticSpeedProfile* InternationalStaticSpeedProfile_New(void)
{
    void* raw = malloc(sizeof(InternationalStaticSpeedProfile));
    InternationalStaticSpeedProfile* ptr = (InternationalStaticSpeedProfile*)raw;
    InternationalStaticSpeedProfile_Init(ptr);
    return ptr;
}


void InternationalStaticSpeedProfile_Delete(InternationalStaticSpeedProfile* ptr)
{
    free(ptr);
}


int InternationalStaticSpeedProfile_UpperBitsNotSet(const InternationalStaticSpeedProfile* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_STATIC,          15);
    status = status && UpperBitsNotSet64(p->V_STATIC,          7) ;
    status = status && UpperBitsNotSet64(p->Q_FRONT,           1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && InternationalStaticSpeedProfile_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->N_ITER_2,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        status = status && InternationalStaticSpeedProfile_2_UpperBitsNotSet(&(p->sub_2[i]));
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

int InternationalStaticSpeedProfile_EncodeBit(const InternationalStaticSpeedProfile* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, INTERNATIONALSTATICSPEEDPROFILE_BITSIZE))
    {
        if (InternationalStaticSpeedProfile_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_STATIC);
            Bitstream_Write(stream, 7,  p->V_STATIC);
            Bitstream_Write(stream, 1,  p->Q_FRONT);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                InternationalStaticSpeedProfile_1_EncodeBit(&(p->sub_1[i]), stream);
            }
            Bitstream_Write(stream, 5,  p->N_ITER_2);
            for (uint32_t i = 0; i < p->N_ITER_2; ++i)
            {
                InternationalStaticSpeedProfile_2_EncodeBit(&(p->sub_2[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_STATIC:          EqualBits(stream, pos + 17,  pos + 32,  p->D_STATIC);
            //@ assert V_STATIC:          EqualBits(stream, pos + 32,  pos + 39,  p->V_STATIC);
            //@ assert Q_FRONT:           EqualBits(stream, pos + 39,  pos + 40,  p->Q_FRONT);

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

int InternationalStaticSpeedProfile_DecodeBit(InternationalStaticSpeedProfile* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, INTERNATIONALSTATICSPEEDPROFILE_BITSIZE))
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
          requires D_STATIC:       stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_STATIC;
          ensures  D_STATIC:       stream->bitpos == pos + 32;
          ensures  D_STATIC:       EqualBits(stream, pos + 17, pos + 32, p->D_STATIC);
          ensures  D_STATIC:       UpperBitsNotSet(p->D_STATIC, 15);
        */
        {
            p->D_STATIC        = Bitstream_Read(stream, 15);
        }

        /*@
          requires V_STATIC:       stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->V_STATIC;
          ensures  V_STATIC:       stream->bitpos == pos + 39;
          ensures  V_STATIC:       EqualBits(stream, pos + 32, pos + 39, p->V_STATIC);
          ensures  V_STATIC:       UpperBitsNotSet(p->V_STATIC, 7);
        */
        {
            p->V_STATIC        = Bitstream_Read(stream, 7);
        }

        /*@
          requires Q_FRONT:        stream->bitpos == pos + 39;
          assigns                  stream->bitpos;
          assigns                  p->Q_FRONT;
          ensures  Q_FRONT:        stream->bitpos == pos + 40;
          ensures  Q_FRONT:        EqualBits(stream, pos + 39, pos + 40, p->Q_FRONT);
          ensures  Q_FRONT:        UpperBitsNotSet(p->Q_FRONT, 1);
        */
        {
            p->Q_FRONT        = Bitstream_Read(stream, 1);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            InternationalStaticSpeedProfile_1_DecodeBit(&(p->sub_1[i]), stream);
        }
    {
            p->N_ITER_2        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_2; ++i)
        {
            InternationalStaticSpeedProfile_2_DecodeBit(&(p->sub_2[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_STATIC:          EqualBits(stream, pos + 17,  pos + 32,  p->D_STATIC);
        //@ assert V_STATIC:          EqualBits(stream, pos + 32,  pos + 39,  p->V_STATIC);
        //@ assert Q_FRONT:           EqualBits(stream, pos + 39,  pos + 40,  p->Q_FRONT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_STATIC:          UpperBitsNotSet(p->D_STATIC,          15);
        //@ assert V_STATIC:          UpperBitsNotSet(p->V_STATIC,          7);
        //@ assert Q_FRONT:           UpperBitsNotSet(p->Q_FRONT,           1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int InternationalStaticSpeedProfile_EncodeInt(const InternationalStaticSpeedProfile* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 27;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->D_STATIC;
    stream[startAddress++] = p->V_STATIC;
    stream[startAddress++] = p->Q_FRONT;
    stream[startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        InternationalStaticSpeedProfile_1_EncodeInt(&(p->sub_1[i]), &startAddress, stream);
    }

    stream[startAddress++] = p->N_ITER_2;

    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        InternationalStaticSpeedProfile_2_EncodeInt(&(p->sub_2[i]), &startAddress, stream);
    }


    data->endAddress = startAddress-1;

    return 1;
}

int InternationalStaticSpeedProfile_DecodeInt(InternationalStaticSpeedProfile* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 27)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->D_STATIC = stream[startAddress++];
    p->V_STATIC = stream[startAddress++];
    p->Q_FRONT = stream[startAddress++];
    p->N_ITER_1 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        InternationalStaticSpeedProfile_1_DecodeInt(&(p->sub_1[i]), &startAddress, stream);
    }

    p->N_ITER_2 = stream[startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        InternationalStaticSpeedProfile_2_DecodeInt(&(p->sub_2[i]), &startAddress, stream);
    }


    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

