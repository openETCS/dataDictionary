
#include "TrackCondition_1.h"
#include "Bit64.h"

int TrackCondition_1_UpperBitsNotSet(const TrackCondition_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->D_TRACKCOND,       15);
    status = status && UpperBitsNotSet64(p->L_TRACKCOND,       15);
    status = status && UpperBitsNotSet64(p->M_TRACKCOND,       4) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int TrackCondition_1_EncodeBit(const TrackCondition_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TRACKCONDITION_1_BITSIZE))
    {
        if (TrackCondition_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_TRACKCOND);
            Bitstream_Write(stream, 15, p->L_TRACKCOND);
            Bitstream_Write(stream, 4,  p->M_TRACKCOND);


            //@ assert D_TRACKCOND:       EqualBits(stream, pos,       pos + 15,  p->D_TRACKCOND);
            //@ assert L_TRACKCOND:       EqualBits(stream, pos + 15,  pos + 30,  p->L_TRACKCOND);
            //@ assert M_TRACKCOND:       EqualBits(stream, pos + 30,  pos + 34,  p->M_TRACKCOND);

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

int TrackCondition_1_DecodeBit(TrackCondition_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TRACKCONDITION_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires D_TRACKCOND:    stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->D_TRACKCOND;
          ensures  D_TRACKCOND:    stream->bitpos == pos + 15;
          ensures  D_TRACKCOND:    EqualBits(stream, pos + 0, pos + 15, p->D_TRACKCOND);
          ensures  D_TRACKCOND:    UpperBitsNotSet(p->D_TRACKCOND, 15);
        */
        {
            p->D_TRACKCOND        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_TRACKCOND:    stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->L_TRACKCOND;
          ensures  L_TRACKCOND:    stream->bitpos == pos + 30;
          ensures  L_TRACKCOND:    EqualBits(stream, pos + 15, pos + 30, p->L_TRACKCOND);
          ensures  L_TRACKCOND:    UpperBitsNotSet(p->L_TRACKCOND, 15);
        */
        {
            p->L_TRACKCOND        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_TRACKCOND:    stream->bitpos == pos + 30;
          assigns                  stream->bitpos;
          assigns                  p->M_TRACKCOND;
          ensures  M_TRACKCOND:    stream->bitpos == pos + 34;
          ensures  M_TRACKCOND:    EqualBits(stream, pos + 30, pos + 34, p->M_TRACKCOND);
          ensures  M_TRACKCOND:    UpperBitsNotSet(p->M_TRACKCOND, 4);
        */
        {
            p->M_TRACKCOND        = Bitstream_Read(stream, 4);
        }

        //@ assert D_TRACKCOND:       EqualBits(stream, pos,       pos + 15,  p->D_TRACKCOND);
        //@ assert L_TRACKCOND:       EqualBits(stream, pos + 15,  pos + 30,  p->L_TRACKCOND);
        //@ assert M_TRACKCOND:       EqualBits(stream, pos + 30,  pos + 34,  p->M_TRACKCOND);

        //@ assert D_TRACKCOND:       UpperBitsNotSet(p->D_TRACKCOND,       15);
        //@ assert L_TRACKCOND:       UpperBitsNotSet(p->L_TRACKCOND,       15);
        //@ assert M_TRACKCOND:       UpperBitsNotSet(p->M_TRACKCOND,       4);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int TrackCondition_1_EncodeInt(const TrackCondition_1* p, kcg_int* startAddress, kcg_int* stream)
{
    stream[(*startAddress)++] = p->D_TRACKCOND;
    stream[(*startAddress)++] = p->L_TRACKCOND;
    stream[(*startAddress)++] = p->M_TRACKCOND;

    return 1;
}

int TrackCondition_1_DecodeInt(TrackCondition_1* p, kcg_int* startAddress, const kcg_int* stream)
{
    p->D_TRACKCOND = stream[(*startAddress)++];
    p->L_TRACKCOND = stream[(*startAddress)++];
    p->M_TRACKCOND = stream[(*startAddress)++];

    return 1;
}

