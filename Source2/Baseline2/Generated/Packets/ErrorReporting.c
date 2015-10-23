
#include "ErrorReporting.h"
#include "Bit64.h"

ErrorReporting* ErrorReporting_New(void)
{
    void* raw = malloc(sizeof(ErrorReporting));
    ErrorReporting* ptr = (ErrorReporting*)raw;
    ErrorReporting_Init(ptr);
    return ptr;
}


void ErrorReporting_Delete(ErrorReporting* ptr)
{
    free(ptr);
}


int ErrorReporting_UpperBitsNotSet(const ErrorReporting* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->M_ERROR,           8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ErrorReporting_EncodeBit(const ErrorReporting* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ERRORREPORTING_BITSIZE))
    {
        if (ErrorReporting_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 8,  p->M_ERROR);


            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert M_ERROR:           EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);

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

int ErrorReporting_DecodeBit(ErrorReporting* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ERRORREPORTING_BITSIZE))
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
          requires M_ERROR:        stream->bitpos == pos + 13;
          assigns                  stream->bitpos;
          assigns                  p->M_ERROR;
          ensures  M_ERROR:        stream->bitpos == pos + 21;
          ensures  M_ERROR:        EqualBits(stream, pos + 13, pos + 21, p->M_ERROR);
          ensures  M_ERROR:        UpperBitsNotSet(p->M_ERROR, 8);
        */
        {
            p->M_ERROR        = Bitstream_Read(stream, 8);
        }

        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert M_ERROR:           EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert M_ERROR:           UpperBitsNotSet(p->M_ERROR,           8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int ErrorReporting_EncodeInt(const ErrorReporting* p, PacketInfo* data, kcg_int* stream)
{
    stream[data->startAddress++] = p->L_PACKET;
    stream[data->startAddress++] = p->M_ERROR;

    return 1;
}

int ErrorReporting_DecodeInt(ErrorReporting* p, PacketInfo* data, kcg_int* stream)
{
    p->L_PACKET = stream[data->startAddress++];
    p->M_ERROR = stream[data->startAddress++];

    return 1;
}

