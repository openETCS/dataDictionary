
#include "Gradient_Profile_Core_1.h"
#include "Bit64.h"

int Gradient_Profile_Core_1_UpperBitsNotSet(const Gradient_Profile_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_GRADIENT,        15);
    status = status && UpperBitsNotSet64(p->Q_GDIR,            1) ;
    status = status && UpperBitsNotSet64(p->G_A,               8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Gradient_Profile_Core_1_Encode_Bit(Bitstream* stream, const Gradient_Profile_Core_1* p)
{
    if (Bitstream_Normal(stream, GRADIENT_PROFILE_CORE_1_CORE_BITSIZE))
    {
        if (Gradient_Profile_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_GRADIENT);
            Bitstream_Write(stream, 1,  p->Q_GDIR);
            Bitstream_Write(stream, 8,  p->G_A);


            //@ assert D_GRADIENT:        EqualBits(stream, pos,       pos + 15,  p->D_GRADIENT);
            //@ assert Q_GDIR:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR);
            //@ assert G_A:               EqualBits(stream, pos + 16,  pos + 24,  p->G_A);

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

int Gradient_Profile_Core_1_Decode_Bit(Bitstream* stream, Gradient_Profile_Core_1* p)
{
    if (Bitstream_Normal(stream, GRADIENT_PROFILE_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_GRADIENT:     stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->D_GRADIENT;
          ensures  D_GRADIENT:     stream->bitpos == pos + 15;
          ensures  D_GRADIENT:     EqualBits(stream, pos + 0, pos + 15, p->D_GRADIENT);
          ensures  D_GRADIENT:     UpperBitsNotSet(p->D_GRADIENT, 15);
        */
        {
            p->D_GRADIENT        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_GDIR:         stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_GDIR;
          ensures  Q_GDIR:         stream->bitpos == pos + 16;
          ensures  Q_GDIR:         EqualBits(stream, pos + 15, pos + 16, p->Q_GDIR);
          ensures  Q_GDIR:         UpperBitsNotSet(p->Q_GDIR, 1);
        */
        {
            p->Q_GDIR        = Bitstream_Read(stream, 1);
        }

        /*@
          requires G_A:            stream->bitpos == pos + 16;
          assigns                  stream->bitpos;
          assigns                  p->G_A;
          ensures  G_A:            stream->bitpos == pos + 24;
          ensures  G_A:            EqualBits(stream, pos + 16, pos + 24, p->G_A);
          ensures  G_A:            UpperBitsNotSet(p->G_A, 8);
        */
        {
            p->G_A        = Bitstream_Read(stream, 8);
        }

        //@ assert D_GRADIENT:        EqualBits(stream, pos,       pos + 15,  p->D_GRADIENT);
        //@ assert Q_GDIR:            EqualBits(stream, pos + 15,  pos + 16,  p->Q_GDIR);
        //@ assert G_A:               EqualBits(stream, pos + 16,  pos + 24,  p->G_A);

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

int Gradient_Profile_Core_1_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Gradient_Profile_Core_1* p)
{

    return 0;
}

int Gradient_Profile_Core_1_Decode_Int(const Packet_Info* data, const kcg_int* stream, Gradient_Profile_Core_1* p)
{

    return 0;
}

