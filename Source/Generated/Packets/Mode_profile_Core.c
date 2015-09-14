
#include "Mode_profile_Core.h"
#include "Bit64.h"

int Mode_profile_UpperBitsNotSet(const Mode_profile_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_MAMODE,          15);
    status = status && UpperBitsNotSet64(p->M_MAMODE,          2) ;
    status = status && UpperBitsNotSet64(p->V_MAMODE,          7) ;
    status = status && UpperBitsNotSet64(p->L_MAMODE,          15);
    status = status && UpperBitsNotSet64(p->L_ACKMAMODE,       15);
    status = status && UpperBitsNotSet64(p->Q_MAMODE,          1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Mode_profile_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int Mode_profile_Encode_Bit(Bitstream* stream, const Mode_profile_Core* p)
{
    if (Bitstream_Normal(stream, MODE_PROFILE_CORE_BITSIZE))
    {
        if (Mode_profile_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_MAMODE);
            Bitstream_Write(stream, 2,  p->M_MAMODE);
            Bitstream_Write(stream, 7,  p->V_MAMODE);
            Bitstream_Write(stream, 15, p->L_MAMODE);
            Bitstream_Write(stream, 15, p->L_ACKMAMODE);
            Bitstream_Write(stream, 1,  p->Q_MAMODE);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Mode_profile_Core_1_Encode_Bit(stream, &(p->sub_1[i]));
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_MAMODE:          EqualBits(stream, pos + 17,  pos + 32,  p->D_MAMODE);
            //@ assert M_MAMODE:          EqualBits(stream, pos + 32,  pos + 34,  p->M_MAMODE);
            //@ assert V_MAMODE:          EqualBits(stream, pos + 34,  pos + 41,  p->V_MAMODE);
            //@ assert L_MAMODE:          EqualBits(stream, pos + 41,  pos + 56,  p->L_MAMODE);
            //@ assert L_ACKMAMODE:       EqualBits(stream, pos + 56,  pos + 71,  p->L_ACKMAMODE);
            //@ assert Q_MAMODE:          EqualBits(stream, pos + 71,  pos + 72,  p->Q_MAMODE);

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

int Mode_profile_Decode_Bit(Bitstream* stream, Mode_profile_Core* p)
{
    if (Bitstream_Normal(stream, MODE_PROFILE_CORE_BITSIZE))
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
          requires D_MAMODE:       stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_MAMODE;
          ensures  D_MAMODE:       stream->bitpos == pos + 32;
          ensures  D_MAMODE:       EqualBits(stream, pos + 17, pos + 32, p->D_MAMODE);
          ensures  D_MAMODE:       UpperBitsNotSet(p->D_MAMODE, 15);
        */
        {
            p->D_MAMODE        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_MAMODE:       stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->M_MAMODE;
          ensures  M_MAMODE:       stream->bitpos == pos + 34;
          ensures  M_MAMODE:       EqualBits(stream, pos + 32, pos + 34, p->M_MAMODE);
          ensures  M_MAMODE:       UpperBitsNotSet(p->M_MAMODE, 2);
        */
        {
            p->M_MAMODE        = Bitstream_Read(stream, 2);
        }

        /*@
          requires V_MAMODE:       stream->bitpos == pos + 34;
          assigns                  stream->bitpos;
          assigns                  p->V_MAMODE;
          ensures  V_MAMODE:       stream->bitpos == pos + 41;
          ensures  V_MAMODE:       EqualBits(stream, pos + 34, pos + 41, p->V_MAMODE);
          ensures  V_MAMODE:       UpperBitsNotSet(p->V_MAMODE, 7);
        */
        {
            p->V_MAMODE        = Bitstream_Read(stream, 7);
        }

        /*@
          requires L_MAMODE:       stream->bitpos == pos + 41;
          assigns                  stream->bitpos;
          assigns                  p->L_MAMODE;
          ensures  L_MAMODE:       stream->bitpos == pos + 56;
          ensures  L_MAMODE:       EqualBits(stream, pos + 41, pos + 56, p->L_MAMODE);
          ensures  L_MAMODE:       UpperBitsNotSet(p->L_MAMODE, 15);
        */
        {
            p->L_MAMODE        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_ACKMAMODE:    stream->bitpos == pos + 56;
          assigns                  stream->bitpos;
          assigns                  p->L_ACKMAMODE;
          ensures  L_ACKMAMODE:    stream->bitpos == pos + 71;
          ensures  L_ACKMAMODE:    EqualBits(stream, pos + 56, pos + 71, p->L_ACKMAMODE);
          ensures  L_ACKMAMODE:    UpperBitsNotSet(p->L_ACKMAMODE, 15);
        */
        {
            p->L_ACKMAMODE        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_MAMODE:       stream->bitpos == pos + 71;
          assigns                  stream->bitpos;
          assigns                  p->Q_MAMODE;
          ensures  Q_MAMODE:       stream->bitpos == pos + 72;
          ensures  Q_MAMODE:       EqualBits(stream, pos + 71, pos + 72, p->Q_MAMODE);
          ensures  Q_MAMODE:       UpperBitsNotSet(p->Q_MAMODE, 1);
        */
        {
            p->Q_MAMODE        = Bitstream_Read(stream, 1);
        }

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Mode_profile_Core_1_Decode_Bit(stream, &(p->sub_1[i]));
        }
        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_MAMODE:          EqualBits(stream, pos + 17,  pos + 32,  p->D_MAMODE);
        //@ assert M_MAMODE:          EqualBits(stream, pos + 32,  pos + 34,  p->M_MAMODE);
        //@ assert V_MAMODE:          EqualBits(stream, pos + 34,  pos + 41,  p->V_MAMODE);
        //@ assert L_MAMODE:          EqualBits(stream, pos + 41,  pos + 56,  p->L_MAMODE);
        //@ assert L_ACKMAMODE:       EqualBits(stream, pos + 56,  pos + 71,  p->L_ACKMAMODE);
        //@ assert Q_MAMODE:          EqualBits(stream, pos + 71,  pos + 72,  p->Q_MAMODE);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_MAMODE:          UpperBitsNotSet(p->D_MAMODE,          15);
        //@ assert M_MAMODE:          UpperBitsNotSet(p->M_MAMODE,          2);
        //@ assert V_MAMODE:          UpperBitsNotSet(p->V_MAMODE,          7);
        //@ assert L_MAMODE:          UpperBitsNotSet(p->L_MAMODE,          15);
        //@ assert L_ACKMAMODE:       UpperBitsNotSet(p->L_ACKMAMODE,       15);
        //@ assert Q_MAMODE:          UpperBitsNotSet(p->Q_MAMODE,          1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Mode_profile_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Mode_profile_Core* p)
{
    std::cerr << "encode int function not implemented for packet " << 80 << " yet." << std::endl;
    return 0;
}

int Mode_profile_Decode_Int(const Packet_Info* data, const kcg_int* stream, Mode_profile_Core* p)
{
    std::cerr << "decode int function not implemented for packet " << 80 << " yet." << std::endl;
    return 0;
}

