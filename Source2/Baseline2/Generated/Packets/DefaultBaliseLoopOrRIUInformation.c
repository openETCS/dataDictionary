
#include "DefaultBaliseLoopOrRIUInformation.h"
#include "Bit64.h"

DefaultBaliseLoopOrRIUInformation* DefaultBaliseLoopOrRIUInformation_New(void)
{
    void* raw = malloc(sizeof(DefaultBaliseLoopOrRIUInformation));
    DefaultBaliseLoopOrRIUInformation* ptr = (DefaultBaliseLoopOrRIUInformation*)raw;
    DefaultBaliseLoopOrRIUInformation_Init(ptr);
    return ptr;
}


void DefaultBaliseLoopOrRIUInformation_Delete(DefaultBaliseLoopOrRIUInformation* ptr)
{
    free(ptr);
}


int DefaultBaliseLoopOrRIUInformation_UpperBitsNotSet(const DefaultBaliseLoopOrRIUInformation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DefaultBaliseLoopOrRIUInformation_EncodeBit(const DefaultBaliseLoopOrRIUInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, DEFAULTBALISELOOPORRIUINFORMATION_BITSIZE))
    {
        if (DefaultBaliseLoopOrRIUInformation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

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

int DefaultBaliseLoopOrRIUInformation_DecodeBit(DefaultBaliseLoopOrRIUInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, DEFAULTBALISELOOPORRIUINFORMATION_BITSIZE))
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

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int DefaultBaliseLoopOrRIUInformation_EncodeInt(const DefaultBaliseLoopOrRIUInformation* p, PacketInfo* data, kcg_int* stream)
{
    stream[data->startAddress++] = p->Q_DIR;
    stream[data->startAddress++] = p->L_PACKET;

    return 1;
}

int DefaultBaliseLoopOrRIUInformation_DecodeInt(DefaultBaliseLoopOrRIUInformation* p, PacketInfo* data, kcg_int* stream)
{
    p->Q_DIR = stream[data->startAddress++];
    p->L_PACKET = stream[data->startAddress++];

    return 1;
}

