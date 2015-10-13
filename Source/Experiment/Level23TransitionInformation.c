
#include "Level23TransitionInformation.h"
#include "Bit64.h"


Level23TransitionInformation* Level23TransitionInformation_New(void)
{
    void* raw = malloc(sizeof(Level23TransitionInformation));
    Level23TransitionInformation* ptr = (Level23TransitionInformation*)raw;
    Level23TransitionInformation_Init(ptr);
    return ptr;
}


void Level23TransitionInformation_Delete(Level23TransitionInformation* ptr)
{
    free(ptr);
}


int Level23TransitionInformation_UpperBitsNotSet(const Level23TransitionInformation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_LTRBG,         24);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Level23TransitionInformation_EncodeBit(Bitstream* stream, const Level23TransitionInformation* p)
{
    if (Bitstream_Normal(stream, LEVEL23TRANSITIONINFORMATION_BITSIZE))
    {
        if (Level23TransitionInformation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 24, p->NID_LTRBG);


            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert NID_LTRBG:         EqualBits(stream, pos + 13,  pos + 37,  p->NID_LTRBG);

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

int Level23TransitionInformation_DecodeBit(Bitstream* stream, Level23TransitionInformation* p)
{
    if (Bitstream_Normal(stream, LEVEL23TRANSITIONINFORMATION_BITSIZE))
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
          requires NID_LTRBG:      stream->bitpos == pos + 13;
          assigns                  stream->bitpos;
          assigns                  p->NID_LTRBG;
          ensures  NID_LTRBG:      stream->bitpos == pos + 37;
          ensures  NID_LTRBG:      EqualBits(stream, pos + 13, pos + 37, p->NID_LTRBG);
          ensures  NID_LTRBG:      UpperBitsNotSet(p->NID_LTRBG, 24);
        */
        {
            p->NID_LTRBG        = Bitstream_Read(stream, 24);
        }

        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert NID_LTRBG:         EqualBits(stream, pos + 13,  pos + 37,  p->NID_LTRBG);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_LTRBG:         UpperBitsNotSet(p->NID_LTRBG,         24);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}
/*
int Level23TransitionInformation_EncodeInt(PacketInfo* data, kcg_int* stream, const Level23TransitionInformation* p)
{
    stream[data->startAddress++] = p->L_PACKET;
    stream[data->startAddress++] = p->NID_LTRBG;

    return 1;
}

int Level23TransitionInformation_DecodeInt(PacketInfo* data, const kcg_int* stream, Level23TransitionInformation* p)
{
    p->L_PACKET = stream[data->startAddress++];
    p->NID_LTRBG = stream[data->startAddress++];

    return 1;
}
*/
