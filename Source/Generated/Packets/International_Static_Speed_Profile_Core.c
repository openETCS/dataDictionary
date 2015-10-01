
#include "International_Static_Speed_Profile_Core.h"
#include "Bit64.h"

int International_Static_Speed_Profile_UpperBitsNotSet(const International_Static_Speed_Profile_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_STATIC,          15);
    status = status && UpperBitsNotSet64(p->V_STATIC,          7) ;
    status = status && UpperBitsNotSet64(p->Q_FRONT,           1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && International_Static_Speed_Profile_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
    }
    status = status && UpperBitsNotSet64(p->N_ITER_2,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_2; ++i)
    {
        status = status && International_Static_Speed_Profile_Core_2_UpperBitsNotSet(&(p->sub_2[i]));
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

int International_Static_Speed_Profile_Encode_Bit(Bitstream* stream, const International_Static_Speed_Profile_Core* p)
{
    if (Bitstream_Normal(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_BITSIZE))
    {
        if (International_Static_Speed_Profile_UpperBitsNotSet(p))
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
                International_Static_Speed_Profile_Core_1_Encode_Bit(stream, &(p->sub_1[i]));
            }
            Bitstream_Write(stream, 5,  p->N_ITER_2);
            for (uint32_t i = 0; i < p->N_ITER_2; ++i)
            {
                International_Static_Speed_Profile_Core_2_Encode_Bit(stream, &(p->sub_2[i]));
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

int International_Static_Speed_Profile_Decode_Bit(Bitstream* stream, International_Static_Speed_Profile_Core* p)
{
    if (Bitstream_Normal(stream, INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_BITSIZE))
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
            International_Static_Speed_Profile_Core_1_Decode_Bit(stream, &(p->sub_1[i]));
        }
    {
            p->N_ITER_2        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_2; ++i)
        {
            International_Static_Speed_Profile_Core_2_Decode_Bit(stream, &(p->sub_2[i]));
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

int International_Static_Speed_Profile_Encode_Int(PacketInfo* data, kcg_int* stream, const International_Static_Speed_Profile_Core* p)
{
    return 0;
}

int International_Static_Speed_Profile_Decode_Int(PacketInfo* data, const kcg_int* stream, International_Static_Speed_Profile_Core* p)
{
    return 0;
}

