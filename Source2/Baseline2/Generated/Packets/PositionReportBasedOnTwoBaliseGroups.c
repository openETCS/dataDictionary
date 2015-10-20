
#include "PositionReportBasedOnTwoBaliseGroups.h"
#include "Bit64.h"

PositionReportBasedOnTwoBaliseGroups* PositionReportBasedOnTwoBaliseGroups_New(void)
{
    void* raw = malloc(sizeof(PositionReportBasedOnTwoBaliseGroups));
    PositionReportBasedOnTwoBaliseGroups* ptr = (PositionReportBasedOnTwoBaliseGroups*)raw;
    PositionReportBasedOnTwoBaliseGroups_Init(ptr);
    return ptr;
}


void PositionReportBasedOnTwoBaliseGroups_Delete(PositionReportBasedOnTwoBaliseGroups* ptr)
{
    free(ptr);
}


int PositionReportBasedOnTwoBaliseGroups_UpperBitsNotSet(const PositionReportBasedOnTwoBaliseGroups* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->NID_LRBG,          24);
    status = status && UpperBitsNotSet64(p->NID_PRVLRBG,       24);
    status = status && UpperBitsNotSet64(p->D_LRBG,            15);
    status = status && UpperBitsNotSet64(p->Q_DIRLRBG,         2) ;
    status = status && UpperBitsNotSet64(p->Q_DLRBG,           2) ;
    status = status && UpperBitsNotSet64(p->L_DOUBTOVER,       15);
    status = status && UpperBitsNotSet64(p->L_DOUBTUNDER,      15);
    status = status && UpperBitsNotSet64(p->Q_LENGTH,          2) ;
    if ((p-> Q_LENGTH == 1  ) || (p-> Q_LENGTH == 2))
    {
        status = status && UpperBitsNotSet64(p->L_TRAININT,        15);
    }
    status = status && UpperBitsNotSet64(p->V_TRAIN,           7) ;
    status = status && UpperBitsNotSet64(p->Q_DIRTRAIN,        2) ;
    status = status && UpperBitsNotSet64(p->M_MODE,            4) ;
    status = status && UpperBitsNotSet64(p->M_LEVEL,           3) ;
    if (p-> M_LEVEL == 1 )
    {
        status = status && UpperBitsNotSet64(p->NID_STM,           8) ;
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

int PositionReportBasedOnTwoBaliseGroups_EncodeBit(const PositionReportBasedOnTwoBaliseGroups* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, POSITIONREPORTBASEDONTWOBALISEGROUPS_BITSIZE))
    {
        if (PositionReportBasedOnTwoBaliseGroups_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 24, p->NID_LRBG);
            Bitstream_Write(stream, 24, p->NID_PRVLRBG);
            Bitstream_Write(stream, 15, p->D_LRBG);
            Bitstream_Write(stream, 2,  p->Q_DIRLRBG);
            Bitstream_Write(stream, 2,  p->Q_DLRBG);
            Bitstream_Write(stream, 15, p->L_DOUBTOVER);
            Bitstream_Write(stream, 15, p->L_DOUBTUNDER);
            Bitstream_Write(stream, 2,  p->Q_LENGTH);
            if ((p-> Q_LENGTH == 1  ) || (p-> Q_LENGTH == 2))
            {
                Bitstream_Write(stream, 15, p->L_TRAININT);
            }

            Bitstream_Write(stream, 7,  p->V_TRAIN);
            Bitstream_Write(stream, 2,  p->Q_DIRTRAIN);
            Bitstream_Write(stream, 4,  p->M_MODE);
            Bitstream_Write(stream, 3,  p->M_LEVEL);
            if (p-> M_LEVEL == 1 )
            {
                Bitstream_Write(stream, 8,  p->NID_STM);
            }



            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 13,  pos + 15,  p->Q_SCALE);
            //@ assert NID_LRBG:          EqualBits(stream, pos + 15,  pos + 39,  p->NID_LRBG);
            //@ assert NID_PRVLRBG:       EqualBits(stream, pos + 39,  pos + 63,  p->NID_PRVLRBG);
            //@ assert D_LRBG:            EqualBits(stream, pos + 63,  pos + 78,  p->D_LRBG);
            //@ assert Q_DIRLRBG:         EqualBits(stream, pos + 78,  pos + 80,  p->Q_DIRLRBG);
            //@ assert Q_DLRBG:           EqualBits(stream, pos + 80,  pos + 82,  p->Q_DLRBG);
            //@ assert L_DOUBTOVER:       EqualBits(stream, pos + 82,  pos + 97,  p->L_DOUBTOVER);
            //@ assert L_DOUBTUNDER:      EqualBits(stream, pos + 97,  pos + 112, p->L_DOUBTUNDER);
            //@ assert Q_LENGTH:          EqualBits(stream, pos + 112, pos + 114, p->Q_LENGTH);

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

int PositionReportBasedOnTwoBaliseGroups_DecodeBit(PositionReportBasedOnTwoBaliseGroups* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, POSITIONREPORTBASEDONTWOBALISEGROUPS_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires L_PACKET:       stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->L_PACKET;
          ensures  L_PACKET:       stream->bitpos == pos + 13;
          ensures  L_PACKET:       EqualBits(stream, pos + 0, pos + 13, p->L_PACKET);
          ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
        */
        {
            p->L_PACKET        = Bitstream_Read(stream, 13);
        }

        /*@
          requires Q_SCALE:        stream->bitpos == pos + 13;
          assigns                  stream->bitpos;
          assigns                  p->Q_SCALE;
          ensures  Q_SCALE:        stream->bitpos == pos + 15;
          ensures  Q_SCALE:        EqualBits(stream, pos + 13, pos + 15, p->Q_SCALE);
          ensures  Q_SCALE:        UpperBitsNotSet(p->Q_SCALE, 2);
        */
        {
            p->Q_SCALE        = Bitstream_Read(stream, 2);
        }

        /*@
          requires NID_LRBG:       stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->NID_LRBG;
          ensures  NID_LRBG:       stream->bitpos == pos + 39;
          ensures  NID_LRBG:       EqualBits(stream, pos + 15, pos + 39, p->NID_LRBG);
          ensures  NID_LRBG:       UpperBitsNotSet(p->NID_LRBG, 24);
        */
        {
            p->NID_LRBG        = Bitstream_Read(stream, 24);
        }

        /*@
          requires NID_PRVLRBG:    stream->bitpos == pos + 39;
          assigns                  stream->bitpos;
          assigns                  p->NID_PRVLRBG;
          ensures  NID_PRVLRBG:    stream->bitpos == pos + 63;
          ensures  NID_PRVLRBG:    EqualBits(stream, pos + 39, pos + 63, p->NID_PRVLRBG);
          ensures  NID_PRVLRBG:    UpperBitsNotSet(p->NID_PRVLRBG, 24);
        */
        {
            p->NID_PRVLRBG        = Bitstream_Read(stream, 24);
        }

        /*@
          requires D_LRBG:         stream->bitpos == pos + 63;
          assigns                  stream->bitpos;
          assigns                  p->D_LRBG;
          ensures  D_LRBG:         stream->bitpos == pos + 78;
          ensures  D_LRBG:         EqualBits(stream, pos + 63, pos + 78, p->D_LRBG);
          ensures  D_LRBG:         UpperBitsNotSet(p->D_LRBG, 15);
        */
        {
            p->D_LRBG        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_DIRLRBG:      stream->bitpos == pos + 78;
          assigns                  stream->bitpos;
          assigns                  p->Q_DIRLRBG;
          ensures  Q_DIRLRBG:      stream->bitpos == pos + 80;
          ensures  Q_DIRLRBG:      EqualBits(stream, pos + 78, pos + 80, p->Q_DIRLRBG);
          ensures  Q_DIRLRBG:      UpperBitsNotSet(p->Q_DIRLRBG, 2);
        */
        {
            p->Q_DIRLRBG        = Bitstream_Read(stream, 2);
        }

        /*@
          requires Q_DLRBG:        stream->bitpos == pos + 80;
          assigns                  stream->bitpos;
          assigns                  p->Q_DLRBG;
          ensures  Q_DLRBG:        stream->bitpos == pos + 82;
          ensures  Q_DLRBG:        EqualBits(stream, pos + 80, pos + 82, p->Q_DLRBG);
          ensures  Q_DLRBG:        UpperBitsNotSet(p->Q_DLRBG, 2);
        */
        {
            p->Q_DLRBG        = Bitstream_Read(stream, 2);
        }

        /*@
          requires L_DOUBTOVER:    stream->bitpos == pos + 82;
          assigns                  stream->bitpos;
          assigns                  p->L_DOUBTOVER;
          ensures  L_DOUBTOVER:    stream->bitpos == pos + 97;
          ensures  L_DOUBTOVER:    EqualBits(stream, pos + 82, pos + 97, p->L_DOUBTOVER);
          ensures  L_DOUBTOVER:    UpperBitsNotSet(p->L_DOUBTOVER, 15);
        */
        {
            p->L_DOUBTOVER        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_DOUBTUNDER:   stream->bitpos == pos + 97;
          assigns                  stream->bitpos;
          assigns                  p->L_DOUBTUNDER;
          ensures  L_DOUBTUNDER:   stream->bitpos == pos + 112;
          ensures  L_DOUBTUNDER:   EqualBits(stream, pos + 97, pos + 112, p->L_DOUBTUNDER);
          ensures  L_DOUBTUNDER:   UpperBitsNotSet(p->L_DOUBTUNDER, 15);
        */
        {
            p->L_DOUBTUNDER        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_LENGTH:       stream->bitpos == pos + 112;
          assigns                  stream->bitpos;
          assigns                  p->Q_LENGTH;
          ensures  Q_LENGTH:       stream->bitpos == pos + 114;
          ensures  Q_LENGTH:       EqualBits(stream, pos + 112, pos + 114, p->Q_LENGTH);
          ensures  Q_LENGTH:       UpperBitsNotSet(p->Q_LENGTH, 2);
        */
        {
            p->Q_LENGTH        = Bitstream_Read(stream, 2);
        }

        if ((p-> Q_LENGTH == 1  ) || (p-> Q_LENGTH == 2))
        {
            {
                p->L_TRAININT        = Bitstream_Read(stream, 15);
            }

        }

        {
            p->V_TRAIN        = Bitstream_Read(stream, 7);
        }

        {
            p->Q_DIRTRAIN        = Bitstream_Read(stream, 2);
        }

        {
            p->M_MODE        = Bitstream_Read(stream, 4);
        }

        {
            p->M_LEVEL        = Bitstream_Read(stream, 3);
        }

        if (p-> M_LEVEL == 1 )
        {
            {
                p->NID_STM        = Bitstream_Read(stream, 8);
            }

        }

        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 13,  pos + 15,  p->Q_SCALE);
        //@ assert NID_LRBG:          EqualBits(stream, pos + 15,  pos + 39,  p->NID_LRBG);
        //@ assert NID_PRVLRBG:       EqualBits(stream, pos + 39,  pos + 63,  p->NID_PRVLRBG);
        //@ assert D_LRBG:            EqualBits(stream, pos + 63,  pos + 78,  p->D_LRBG);
        //@ assert Q_DIRLRBG:         EqualBits(stream, pos + 78,  pos + 80,  p->Q_DIRLRBG);
        //@ assert Q_DLRBG:           EqualBits(stream, pos + 80,  pos + 82,  p->Q_DLRBG);
        //@ assert L_DOUBTOVER:       EqualBits(stream, pos + 82,  pos + 97,  p->L_DOUBTOVER);
        //@ assert L_DOUBTUNDER:      EqualBits(stream, pos + 97,  pos + 112, p->L_DOUBTUNDER);
        //@ assert Q_LENGTH:          EqualBits(stream, pos + 112, pos + 114, p->Q_LENGTH);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert NID_LRBG:          UpperBitsNotSet(p->NID_LRBG,          24);
        //@ assert NID_PRVLRBG:       UpperBitsNotSet(p->NID_PRVLRBG,       24);
        //@ assert D_LRBG:            UpperBitsNotSet(p->D_LRBG,            15);
        //@ assert Q_DIRLRBG:         UpperBitsNotSet(p->Q_DIRLRBG,         2);
        //@ assert Q_DLRBG:           UpperBitsNotSet(p->Q_DLRBG,           2);
        //@ assert L_DOUBTOVER:       UpperBitsNotSet(p->L_DOUBTOVER,       15);
        //@ assert L_DOUBTUNDER:      UpperBitsNotSet(p->L_DOUBTUNDER,      15);
        //@ assert Q_LENGTH:          UpperBitsNotSet(p->Q_LENGTH,          2);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

/*
int PositionReportBasedOnTwoBaliseGroups_EncodeInt(const PositionReportBasedOnTwoBaliseGroups* p, PacketInfo* data, kcg_int* stream)
{

}

int PositionReportBasedOnTwoBaliseGroups_DecodeInt(PositionReportBasedOnTwoBaliseGroups* p, PacketInfo* data, kcg_int* stream)
{

}
*/

