
#include "ReversingAreaInformation.h"
#include "Bit64.h"

ReversingAreaInformation* ReversingAreaInformation_New(void)
{
    void* raw = malloc(sizeof(ReversingAreaInformation));
    ReversingAreaInformation* ptr = (ReversingAreaInformation*)raw;
    ReversingAreaInformation_Init(ptr);
    return ptr;
}


void ReversingAreaInformation_Delete(ReversingAreaInformation* ptr)
{
    free(ptr);
}


int ReversingAreaInformation_UpperBitsNotSet(const ReversingAreaInformation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_STARTREVERSE,    15);
    status = status && UpperBitsNotSet64(p->L_REVERSEAREA,     15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ReversingAreaInformation_EncodeBit(const ReversingAreaInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, REVERSINGAREAINFORMATION_BITSIZE))
    {
        if (ReversingAreaInformation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_STARTREVERSE);
            Bitstream_Write(stream, 15, p->L_REVERSEAREA);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_STARTREVERSE:    EqualBits(stream, pos + 17,  pos + 32,  p->D_STARTREVERSE);
            //@ assert L_REVERSEAREA:     EqualBits(stream, pos + 32,  pos + 47,  p->L_REVERSEAREA);

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

int ReversingAreaInformation_DecodeBit(ReversingAreaInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, REVERSINGAREAINFORMATION_BITSIZE))
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
          requires D_STARTREVERSE: stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_STARTREVERSE;
          ensures  D_STARTREVERSE: stream->bitpos == pos + 32;
          ensures  D_STARTREVERSE: EqualBits(stream, pos + 17, pos + 32, p->D_STARTREVERSE);
          ensures  D_STARTREVERSE: UpperBitsNotSet(p->D_STARTREVERSE, 15);
        */
        {
            p->D_STARTREVERSE        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_REVERSEAREA:  stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->L_REVERSEAREA;
          ensures  L_REVERSEAREA:  stream->bitpos == pos + 47;
          ensures  L_REVERSEAREA:  EqualBits(stream, pos + 32, pos + 47, p->L_REVERSEAREA);
          ensures  L_REVERSEAREA:  UpperBitsNotSet(p->L_REVERSEAREA, 15);
        */
        {
            p->L_REVERSEAREA        = Bitstream_Read(stream, 15);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_STARTREVERSE:    EqualBits(stream, pos + 17,  pos + 32,  p->D_STARTREVERSE);
        //@ assert L_REVERSEAREA:     EqualBits(stream, pos + 32,  pos + 47,  p->L_REVERSEAREA);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_STARTREVERSE:    UpperBitsNotSet(p->D_STARTREVERSE,    15);
        //@ assert L_REVERSEAREA:     UpperBitsNotSet(p->L_REVERSEAREA,     15);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int ReversingAreaInformation_EncodeInt(const ReversingAreaInformation* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 138;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->D_STARTREVERSE;
    stream[startAddress++] = p->L_REVERSEAREA;

    data->endAddress = startAddress-1;

    return 1;
}

int ReversingAreaInformation_DecodeInt(ReversingAreaInformation* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 138)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->D_STARTREVERSE = stream[startAddress++];
    p->L_REVERSEAREA = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

