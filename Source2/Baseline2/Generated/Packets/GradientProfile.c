
#include "GradientProfile.h"
#include "Bit64.h"

GradientProfile* GradientProfile_New(void)
{
    void* raw = malloc(sizeof(GradientProfile));
    GradientProfile* ptr = (GradientProfile*)raw;
    GradientProfile_Init(ptr);
    return ptr;
}


void GradientProfile_Delete(GradientProfile* ptr)
{
    free(ptr);
}


int GradientProfile_UpperBitsNotSet(const GradientProfile* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_GRADIENT,        15);
    status = status && UpperBitsNotSet64(p->Q_GDIR,            1) ;
    status = status && UpperBitsNotSet64(p->G_A,               8) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && GradientProfile_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int GradientProfile_EncodeBit(const GradientProfile* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, GRADIENTPROFILE_BITSIZE))
    {
        if (GradientProfile_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_GRADIENT);
            Bitstream_Write(stream, 1,  p->Q_GDIR);
            Bitstream_Write(stream, 8,  p->G_A);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                GradientProfile_1_EncodeBit(&(p->sub_1[i]), stream);
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_GRADIENT:        EqualBits(stream, pos + 17,  pos + 32,  p->D_GRADIENT);
            //@ assert Q_GDIR:            EqualBits(stream, pos + 32,  pos + 33,  p->Q_GDIR);
            //@ assert G_A:               EqualBits(stream, pos + 33,  pos + 41,  p->G_A);

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

int GradientProfile_DecodeBit(GradientProfile* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, GRADIENTPROFILE_BITSIZE))
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
          requires D_GRADIENT:     stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_GRADIENT;
          ensures  D_GRADIENT:     stream->bitpos == pos + 32;
          ensures  D_GRADIENT:     EqualBits(stream, pos + 17, pos + 32, p->D_GRADIENT);
          ensures  D_GRADIENT:     UpperBitsNotSet(p->D_GRADIENT, 15);
        */
        {
            p->D_GRADIENT        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_GDIR:         stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->Q_GDIR;
          ensures  Q_GDIR:         stream->bitpos == pos + 33;
          ensures  Q_GDIR:         EqualBits(stream, pos + 32, pos + 33, p->Q_GDIR);
          ensures  Q_GDIR:         UpperBitsNotSet(p->Q_GDIR, 1);
        */
        {
            p->Q_GDIR        = Bitstream_Read(stream, 1);
        }

        /*@
          requires G_A:            stream->bitpos == pos + 33;
          assigns                  stream->bitpos;
          assigns                  p->G_A;
          ensures  G_A:            stream->bitpos == pos + 41;
          ensures  G_A:            EqualBits(stream, pos + 33, pos + 41, p->G_A);
          ensures  G_A:            UpperBitsNotSet(p->G_A, 8);
        */
        {
            p->G_A        = Bitstream_Read(stream, 8);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            GradientProfile_1_DecodeBit(&(p->sub_1[i]), stream);
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_GRADIENT:        EqualBits(stream, pos + 17,  pos + 32,  p->D_GRADIENT);
        //@ assert Q_GDIR:            EqualBits(stream, pos + 32,  pos + 33,  p->Q_GDIR);
        //@ assert G_A:               EqualBits(stream, pos + 33,  pos + 41,  p->G_A);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_GRADIENT:        UpperBitsNotSet(p->D_GRADIENT,        15);
        //@ assert Q_GDIR:            UpperBitsNotSet(p->Q_GDIR,            1);
        //@ assert G_A:               UpperBitsNotSet(p->G_A,               8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

/*
int GradientProfile_EncodeInt(const GradientProfile* p, PacketInfo* data, kcg_int* stream)
{

}

int GradientProfile_DecodeInt(GradientProfile* p, PacketInfo* data, kcg_int* stream)
{

}
*/

