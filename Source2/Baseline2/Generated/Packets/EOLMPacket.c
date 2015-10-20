
#include "EOLMPacket.h"
#include "Bit64.h"

EOLMPacket* EOLMPacket_New(void)
{
    void* raw = malloc(sizeof(EOLMPacket));
    EOLMPacket* ptr = (EOLMPacket*)raw;
    EOLMPacket_Init(ptr);
    return ptr;
}


void EOLMPacket_Delete(EOLMPacket* ptr)
{
    free(ptr);
}


int EOLMPacket_UpperBitsNotSet(const EOLMPacket* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->NID_LOOP,          14);
    status = status && UpperBitsNotSet64(p->D_LOOP,            15);
    status = status && UpperBitsNotSet64(p->L_LOOP,            15);
    status = status && UpperBitsNotSet64(p->Q_LOOPDIR,         1) ;
    status = status && UpperBitsNotSet64(p->Q_SSCODE,          4) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int EOLMPacket_EncodeBit(const EOLMPacket* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, EOLMPACKET_BITSIZE))
    {
        if (EOLMPacket_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 14, p->NID_LOOP);
            Bitstream_Write(stream, 15, p->D_LOOP);
            Bitstream_Write(stream, 15, p->L_LOOP);
            Bitstream_Write(stream, 1,  p->Q_LOOPDIR);
            Bitstream_Write(stream, 4,  p->Q_SSCODE);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert NID_LOOP:          EqualBits(stream, pos + 17,  pos + 31,  p->NID_LOOP);
            //@ assert D_LOOP:            EqualBits(stream, pos + 31,  pos + 46,  p->D_LOOP);
            //@ assert L_LOOP:            EqualBits(stream, pos + 46,  pos + 61,  p->L_LOOP);
            //@ assert Q_LOOPDIR:         EqualBits(stream, pos + 61,  pos + 62,  p->Q_LOOPDIR);
            //@ assert Q_SSCODE:          EqualBits(stream, pos + 62,  pos + 66,  p->Q_SSCODE);

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

int EOLMPacket_DecodeBit(EOLMPacket* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, EOLMPACKET_BITSIZE))
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
          requires NID_LOOP:       stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->NID_LOOP;
          ensures  NID_LOOP:       stream->bitpos == pos + 31;
          ensures  NID_LOOP:       EqualBits(stream, pos + 17, pos + 31, p->NID_LOOP);
          ensures  NID_LOOP:       UpperBitsNotSet(p->NID_LOOP, 14);
        */
        {
            p->NID_LOOP        = Bitstream_Read(stream, 14);
        }

        /*@
          requires D_LOOP:         stream->bitpos == pos + 31;
          assigns                  stream->bitpos;
          assigns                  p->D_LOOP;
          ensures  D_LOOP:         stream->bitpos == pos + 46;
          ensures  D_LOOP:         EqualBits(stream, pos + 31, pos + 46, p->D_LOOP);
          ensures  D_LOOP:         UpperBitsNotSet(p->D_LOOP, 15);
        */
        {
            p->D_LOOP        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_LOOP:         stream->bitpos == pos + 46;
          assigns                  stream->bitpos;
          assigns                  p->L_LOOP;
          ensures  L_LOOP:         stream->bitpos == pos + 61;
          ensures  L_LOOP:         EqualBits(stream, pos + 46, pos + 61, p->L_LOOP);
          ensures  L_LOOP:         UpperBitsNotSet(p->L_LOOP, 15);
        */
        {
            p->L_LOOP        = Bitstream_Read(stream, 15);
        }

        /*@
          requires Q_LOOPDIR:      stream->bitpos == pos + 61;
          assigns                  stream->bitpos;
          assigns                  p->Q_LOOPDIR;
          ensures  Q_LOOPDIR:      stream->bitpos == pos + 62;
          ensures  Q_LOOPDIR:      EqualBits(stream, pos + 61, pos + 62, p->Q_LOOPDIR);
          ensures  Q_LOOPDIR:      UpperBitsNotSet(p->Q_LOOPDIR, 1);
        */
        {
            p->Q_LOOPDIR        = Bitstream_Read(stream, 1);
        }

        /*@
          requires Q_SSCODE:       stream->bitpos == pos + 62;
          assigns                  stream->bitpos;
          assigns                  p->Q_SSCODE;
          ensures  Q_SSCODE:       stream->bitpos == pos + 66;
          ensures  Q_SSCODE:       EqualBits(stream, pos + 62, pos + 66, p->Q_SSCODE);
          ensures  Q_SSCODE:       UpperBitsNotSet(p->Q_SSCODE, 4);
        */
        {
            p->Q_SSCODE        = Bitstream_Read(stream, 4);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert NID_LOOP:          EqualBits(stream, pos + 17,  pos + 31,  p->NID_LOOP);
        //@ assert D_LOOP:            EqualBits(stream, pos + 31,  pos + 46,  p->D_LOOP);
        //@ assert L_LOOP:            EqualBits(stream, pos + 46,  pos + 61,  p->L_LOOP);
        //@ assert Q_LOOPDIR:         EqualBits(stream, pos + 61,  pos + 62,  p->Q_LOOPDIR);
        //@ assert Q_SSCODE:          EqualBits(stream, pos + 62,  pos + 66,  p->Q_SSCODE);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert NID_LOOP:          UpperBitsNotSet(p->NID_LOOP,          14);
        //@ assert D_LOOP:            UpperBitsNotSet(p->D_LOOP,            15);
        //@ assert L_LOOP:            UpperBitsNotSet(p->L_LOOP,            15);
        //@ assert Q_LOOPDIR:         UpperBitsNotSet(p->Q_LOOPDIR,         1);
        //@ assert Q_SSCODE:          UpperBitsNotSet(p->Q_SSCODE,          4);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

/*
int EOLMPacket_EncodeInt(const EOLMPacket* p, PacketInfo* data, kcg_int* stream)
{

}

int EOLMPacket_DecodeInt(EOLMPacket* p, PacketInfo* data, kcg_int* stream)
{

}
*/

