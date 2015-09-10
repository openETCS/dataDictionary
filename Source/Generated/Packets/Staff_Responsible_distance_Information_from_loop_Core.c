
#include "Staff_Responsible_distance_Information_from_loop_Core.h"
#include "Bit64.h"

int Staff_Responsible_distance_Information_from_loop_UpperBitsNotSet(const Staff_Responsible_distance_Information_from_loop_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_0,    1) ;
    if (p->Q_NEWCOUNTRY_0 == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_C_0,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_0,          14);
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_1,    1) ;
    if (p->Q_NEWCOUNTRY_1 == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_C_1,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_1,          14);
    status = status && UpperBitsNotSet64(p->D_SR,              15);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Staff_Responsible_distance_Information_from_loop_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int Staff_Responsible_distance_Information_from_loop_Encoder(Bitstream* stream, const Staff_Responsible_distance_Information_from_loop_Core* p)
{
    if (Bitstream_Normal(stream, STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_BITSIZE))
    {
        if (Staff_Responsible_distance_Information_from_loop_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_0);
            if (p->Q_NEWCOUNTRY_0 == 1)
            {
                Bitstream_Write(stream, 10, p->NID_C_0);
            }

            Bitstream_Write(stream, 14, p->NID_BG_0);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_1);
            if (p->Q_NEWCOUNTRY_1 == 1)
            {
                Bitstream_Write(stream, 10, p->NID_C_1);
            }

            Bitstream_Write(stream, 14, p->NID_BG_1);
            Bitstream_Write(stream, 15, p->D_SR);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Staff_Responsible_distance_Information_from_loop_Core_1_Encoder(stream, &(p->sub_1[i]));
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert Q_NEWCOUNTRY_0:    EqualBits(stream, pos + 17,  pos + 18,  p->Q_NEWCOUNTRY_0);

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

int Staff_Responsible_distance_Information_from_loop_Decoder(Bitstream* stream, Staff_Responsible_distance_Information_from_loop_Core* p)
{
    if (Bitstream_Normal(stream, STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_BITSIZE))
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
          requires Q_NEWCOUNTRY_0: stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->Q_NEWCOUNTRY_0;
          ensures  Q_NEWCOUNTRY_0: stream->bitpos == pos + 18;
          ensures  Q_NEWCOUNTRY_0: EqualBits(stream, pos + 17, pos + 18, p->Q_NEWCOUNTRY_0);
          ensures  Q_NEWCOUNTRY_0: UpperBitsNotSet(p->Q_NEWCOUNTRY_0, 1);
        */
        {
            p->Q_NEWCOUNTRY_0        = Bitstream_Read(stream, 1);
        }

        if (p->Q_NEWCOUNTRY_0 == 1)
        {
            {
                p->NID_C_0        = Bitstream_Read(stream, 10);
            }

        }

        {
            p->NID_BG_0        = Bitstream_Read(stream, 14);
        }

        {
            p->Q_NEWCOUNTRY_1        = Bitstream_Read(stream, 1);
        }

        if (p->Q_NEWCOUNTRY_1 == 1)
        {
            {
                p->NID_C_1        = Bitstream_Read(stream, 10);
            }

        }

        {
            p->NID_BG_1        = Bitstream_Read(stream, 14);
        }

        {
            p->D_SR        = Bitstream_Read(stream, 15);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Staff_Responsible_distance_Information_from_loop_Core_1_Decoder(stream, &(p->sub_1[i]));
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert Q_NEWCOUNTRY_0:    EqualBits(stream, pos + 17,  pos + 18,  p->Q_NEWCOUNTRY_0);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert Q_NEWCOUNTRY_0:    UpperBitsNotSet(p->Q_NEWCOUNTRY_0,    1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

