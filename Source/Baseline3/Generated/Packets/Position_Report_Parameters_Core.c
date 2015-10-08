
#include "Position_Report_Parameters_Core.h"
#include "Bit64.h"

int Position_Report_Parameters_UpperBitsNotSet(const Position_Report_Parameters_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->T_CYCLOC,          8) ;
    status = status && UpperBitsNotSet64(p->D_CYCLOC,          15);
    status = status && UpperBitsNotSet64(p->M_LOC,             3) ;
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && Position_Report_Parameters_Core_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int Position_Report_Parameters_Encode_Bit(Bitstream* stream, const Position_Report_Parameters_Core* p)
{
    if (Bitstream_Normal(stream, POSITION_REPORT_PARAMETERS_CORE_BITSIZE))
    {
        if (Position_Report_Parameters_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 8,  p->T_CYCLOC);
            Bitstream_Write(stream, 15, p->D_CYCLOC);
            Bitstream_Write(stream, 3,  p->M_LOC);
            Bitstream_Write(stream, 5,  p->N_ITER_1);

            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                Position_Report_Parameters_Core_1_Encode_Bit(stream, &(p->sub_1[i]));
            }


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert T_CYCLOC:          EqualBits(stream, pos + 17,  pos + 25,  p->T_CYCLOC);
            //@ assert D_CYCLOC:          EqualBits(stream, pos + 25,  pos + 40,  p->D_CYCLOC);
            //@ assert M_LOC:             EqualBits(stream, pos + 40,  pos + 43,  p->M_LOC);

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

int Position_Report_Parameters_Decode_Bit(Bitstream* stream, Position_Report_Parameters_Core* p)
{
    if (Bitstream_Normal(stream, POSITION_REPORT_PARAMETERS_CORE_BITSIZE))
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
          requires T_CYCLOC:       stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->T_CYCLOC;
          ensures  T_CYCLOC:       stream->bitpos == pos + 25;
          ensures  T_CYCLOC:       EqualBits(stream, pos + 17, pos + 25, p->T_CYCLOC);
          ensures  T_CYCLOC:       UpperBitsNotSet(p->T_CYCLOC, 8);
        */
        {
            p->T_CYCLOC        = Bitstream_Read(stream, 8);
        }

        /*@
          requires D_CYCLOC:       stream->bitpos == pos + 25;
          assigns                  stream->bitpos;
          assigns                  p->D_CYCLOC;
          ensures  D_CYCLOC:       stream->bitpos == pos + 40;
          ensures  D_CYCLOC:       EqualBits(stream, pos + 25, pos + 40, p->D_CYCLOC);
          ensures  D_CYCLOC:       UpperBitsNotSet(p->D_CYCLOC, 15);
        */
        {
            p->D_CYCLOC        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_LOC:          stream->bitpos == pos + 40;
          assigns                  stream->bitpos;
          assigns                  p->M_LOC;
          ensures  M_LOC:          stream->bitpos == pos + 43;
          ensures  M_LOC:          EqualBits(stream, pos + 40, pos + 43, p->M_LOC);
          ensures  M_LOC:          UpperBitsNotSet(p->M_LOC, 3);
        */
        {
            p->M_LOC        = Bitstream_Read(stream, 3);
        }

        {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            Position_Report_Parameters_Core_1_Decode_Bit(stream, &(p->sub_1[i]));
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert T_CYCLOC:          EqualBits(stream, pos + 17,  pos + 25,  p->T_CYCLOC);
        //@ assert D_CYCLOC:          EqualBits(stream, pos + 25,  pos + 40,  p->D_CYCLOC);
        //@ assert M_LOC:             EqualBits(stream, pos + 40,  pos + 43,  p->M_LOC);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert T_CYCLOC:          UpperBitsNotSet(p->T_CYCLOC,          8);
        //@ assert D_CYCLOC:          UpperBitsNotSet(p->D_CYCLOC,          15);
        //@ assert M_LOC:             UpperBitsNotSet(p->M_LOC,             3);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Position_Report_Parameters_Encode_Int(PacketInfo* data, kcg_int* stream, const Position_Report_Parameters_Core* p)
{
    stream[data->startAddress++] = p->Q_DIR;
    stream[data->startAddress++] = p->L_PACKET;
    stream[data->startAddress++] = p->Q_SCALE;
    stream[data->startAddress++] = p->T_CYCLOC;
    stream[data->startAddress++] = p->D_CYCLOC;
    stream[data->startAddress++] = p->M_LOC;
    stream[data->startAddress++] = p->N_ITER_1;

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        Position_Report_Parameters_Core_1_Encode_Int(data, stream, &(p->sub_1[i]));
    }

    return 1;
}

int Position_Report_Parameters_Decode_Int(PacketInfo* data, const kcg_int* stream, Position_Report_Parameters_Core* p)
{
    p->Q_DIR = stream[data->startAddress++];
    p->L_PACKET = stream[data->startAddress++];
    p->Q_SCALE = stream[data->startAddress++];
    p->T_CYCLOC = stream[data->startAddress++];
    p->D_CYCLOC = stream[data->startAddress++];
    p->M_LOC = stream[data->startAddress++];
    p->N_ITER_1 = stream[data->startAddress++];

    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        Position_Report_Parameters_Core_1_Decode_Int(data, stream, &(p->sub_1[i]));
    }

    return 1;
}

