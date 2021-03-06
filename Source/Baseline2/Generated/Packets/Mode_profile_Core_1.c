
#include "Mode_profile_Core_1.h"
#include "Bit64.h"

int Mode_profile_Core_1_UpperBitsNotSet(const Mode_profile_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_MAMODE,          15);
    status = status && UpperBitsNotSet64(p->M_MAMODE,          2) ;
    status = status && UpperBitsNotSet64(p->V_MAMODE,          7) ;
    status = status && UpperBitsNotSet64(p->L_MAMODE,          15);
    status = status && UpperBitsNotSet64(p->L_ACKMAMODE,       15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Mode_profile_Core_1_Encode_Bit(Bitstream* stream, const Mode_profile_Core_1* p)
{
    if (Bitstream_Normal(stream, MODE_PROFILE_CORE_1_CORE_BITSIZE))
    {
        if (Mode_profile_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_MAMODE);
            Bitstream_Write(stream, 2,  p->M_MAMODE);
            Bitstream_Write(stream, 7,  p->V_MAMODE);
            Bitstream_Write(stream, 15, p->L_MAMODE);
            Bitstream_Write(stream, 15, p->L_ACKMAMODE);


            //@ assert D_MAMODE:          EqualBits(stream, pos,       pos + 15,  p->D_MAMODE);
            //@ assert M_MAMODE:          EqualBits(stream, pos + 15,  pos + 17,  p->M_MAMODE);
            //@ assert V_MAMODE:          EqualBits(stream, pos + 17,  pos + 24,  p->V_MAMODE);
            //@ assert L_MAMODE:          EqualBits(stream, pos + 24,  pos + 39,  p->L_MAMODE);
            //@ assert L_ACKMAMODE:       EqualBits(stream, pos + 39,  pos + 54,  p->L_ACKMAMODE);

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

int Mode_profile_Core_1_Decode_Bit(Bitstream* stream, Mode_profile_Core_1* p)
{
    if (Bitstream_Normal(stream, MODE_PROFILE_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_MAMODE:       stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->D_MAMODE;
          ensures  D_MAMODE:       stream->bitpos == pos + 15;
          ensures  D_MAMODE:       EqualBits(stream, pos + 0, pos + 15, p->D_MAMODE);
          ensures  D_MAMODE:       UpperBitsNotSet(p->D_MAMODE, 15);
        */
        {
            p->D_MAMODE        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_MAMODE:       stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->M_MAMODE;
          ensures  M_MAMODE:       stream->bitpos == pos + 17;
          ensures  M_MAMODE:       EqualBits(stream, pos + 15, pos + 17, p->M_MAMODE);
          ensures  M_MAMODE:       UpperBitsNotSet(p->M_MAMODE, 2);
        */
        {
            p->M_MAMODE        = Bitstream_Read(stream, 2);
        }

        /*@
          requires V_MAMODE:       stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->V_MAMODE;
          ensures  V_MAMODE:       stream->bitpos == pos + 24;
          ensures  V_MAMODE:       EqualBits(stream, pos + 17, pos + 24, p->V_MAMODE);
          ensures  V_MAMODE:       UpperBitsNotSet(p->V_MAMODE, 7);
        */
        {
            p->V_MAMODE        = Bitstream_Read(stream, 7);
        }

        /*@
          requires L_MAMODE:       stream->bitpos == pos + 24;
          assigns                  stream->bitpos;
          assigns                  p->L_MAMODE;
          ensures  L_MAMODE:       stream->bitpos == pos + 39;
          ensures  L_MAMODE:       EqualBits(stream, pos + 24, pos + 39, p->L_MAMODE);
          ensures  L_MAMODE:       UpperBitsNotSet(p->L_MAMODE, 15);
        */
        {
            p->L_MAMODE        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_ACKMAMODE:    stream->bitpos == pos + 39;
          assigns                  stream->bitpos;
          assigns                  p->L_ACKMAMODE;
          ensures  L_ACKMAMODE:    stream->bitpos == pos + 54;
          ensures  L_ACKMAMODE:    EqualBits(stream, pos + 39, pos + 54, p->L_ACKMAMODE);
          ensures  L_ACKMAMODE:    UpperBitsNotSet(p->L_ACKMAMODE, 15);
        */
        {
            p->L_ACKMAMODE        = Bitstream_Read(stream, 15);
        }

        //@ assert D_MAMODE:          EqualBits(stream, pos,       pos + 15,  p->D_MAMODE);
        //@ assert M_MAMODE:          EqualBits(stream, pos + 15,  pos + 17,  p->M_MAMODE);
        //@ assert V_MAMODE:          EqualBits(stream, pos + 17,  pos + 24,  p->V_MAMODE);
        //@ assert L_MAMODE:          EqualBits(stream, pos + 24,  pos + 39,  p->L_MAMODE);
        //@ assert L_ACKMAMODE:       EqualBits(stream, pos + 39,  pos + 54,  p->L_ACKMAMODE);

        //@ assert D_MAMODE:          UpperBitsNotSet(p->D_MAMODE,          15);
        //@ assert M_MAMODE:          UpperBitsNotSet(p->M_MAMODE,          2);
        //@ assert V_MAMODE:          UpperBitsNotSet(p->V_MAMODE,          7);
        //@ assert L_MAMODE:          UpperBitsNotSet(p->L_MAMODE,          15);
        //@ assert L_ACKMAMODE:       UpperBitsNotSet(p->L_ACKMAMODE,       15);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Mode_profile_Core_1_Encode_Int(PacketInfo* data, kcg_int* stream, const Mode_profile_Core_1* p)
{
    return 0;
}

int Mode_profile_Core_1_Decode_Int(PacketInfo* data, const kcg_int* stream, Mode_profile_Core_1* p)
{
    return 0;
}

