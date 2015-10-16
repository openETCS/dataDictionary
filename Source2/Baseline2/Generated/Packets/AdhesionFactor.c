
#include "AdhesionFactor.h"
#include "Bit64.h"

AdhesionFactor* AdhesionFactor_New(void)
{
    void* raw = malloc(sizeof(AdhesionFactor));
    AdhesionFactor* ptr = (AdhesionFactor*)raw;
    AdhesionFactor_Init(ptr);
    return ptr;
}


void AdhesionFactor_Delete(AdhesionFactor* ptr)
{
    free(ptr);
}


int AdhesionFactor_UpperBitsNotSet(const AdhesionFactor* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->D_ADHESION,        15);
    status = status && UpperBitsNotSet64(p->L_ADHESION,        15);
    status = status && UpperBitsNotSet64(p->M_ADHESION,        1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int AdhesionFactor_EncodeBit(const AdhesionFactor* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ADHESIONFACTOR_BITSIZE))
    {
        if (AdhesionFactor_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->D_ADHESION);
            Bitstream_Write(stream, 15, p->L_ADHESION);
            Bitstream_Write(stream, 1,  p->M_ADHESION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert D_ADHESION:        EqualBits(stream, pos + 17,  pos + 32,  p->D_ADHESION);
            //@ assert L_ADHESION:        EqualBits(stream, pos + 32,  pos + 47,  p->L_ADHESION);
            //@ assert M_ADHESION:        EqualBits(stream, pos + 47,  pos + 48,  p->M_ADHESION);

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

int AdhesionFactor_DecodeBit(AdhesionFactor* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, ADHESIONFACTOR_BITSIZE))
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
          requires D_ADHESION:     stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->D_ADHESION;
          ensures  D_ADHESION:     stream->bitpos == pos + 32;
          ensures  D_ADHESION:     EqualBits(stream, pos + 17, pos + 32, p->D_ADHESION);
          ensures  D_ADHESION:     UpperBitsNotSet(p->D_ADHESION, 15);
        */
        {
            p->D_ADHESION        = Bitstream_Read(stream, 15);
        }

        /*@
          requires L_ADHESION:     stream->bitpos == pos + 32;
          assigns                  stream->bitpos;
          assigns                  p->L_ADHESION;
          ensures  L_ADHESION:     stream->bitpos == pos + 47;
          ensures  L_ADHESION:     EqualBits(stream, pos + 32, pos + 47, p->L_ADHESION);
          ensures  L_ADHESION:     UpperBitsNotSet(p->L_ADHESION, 15);
        */
        {
            p->L_ADHESION        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_ADHESION:     stream->bitpos == pos + 47;
          assigns                  stream->bitpos;
          assigns                  p->M_ADHESION;
          ensures  M_ADHESION:     stream->bitpos == pos + 48;
          ensures  M_ADHESION:     EqualBits(stream, pos + 47, pos + 48, p->M_ADHESION);
          ensures  M_ADHESION:     UpperBitsNotSet(p->M_ADHESION, 1);
        */
        {
            p->M_ADHESION        = Bitstream_Read(stream, 1);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert D_ADHESION:        EqualBits(stream, pos + 17,  pos + 32,  p->D_ADHESION);
        //@ assert L_ADHESION:        EqualBits(stream, pos + 32,  pos + 47,  p->L_ADHESION);
        //@ assert M_ADHESION:        EqualBits(stream, pos + 47,  pos + 48,  p->M_ADHESION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert D_ADHESION:        UpperBitsNotSet(p->D_ADHESION,        15);
        //@ assert L_ADHESION:        UpperBitsNotSet(p->L_ADHESION,        15);
        //@ assert M_ADHESION:        UpperBitsNotSet(p->M_ADHESION,        1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}
/*
int AdhesionFactor_EncodeInt(PacketInfo* data, kcg_int* stream, const AdhesionFactor* p)
{
    stream[data->startAddress++] = p->Q_DIR;
    stream[data->startAddress++] = p->L_PACKET;
    stream[data->startAddress++] = p->Q_SCALE;
    stream[data->startAddress++] = p->D_ADHESION;
    stream[data->startAddress++] = p->L_ADHESION;
    stream[data->startAddress++] = p->M_ADHESION;

    return 1;
}

int AdhesionFactor_DecodeInt(PacketInfo* data, const kcg_int* stream, AdhesionFactor* p)
{
    p->Q_DIR = stream[data->startAddress++];
    p->L_PACKET = stream[data->startAddress++];
    p->Q_SCALE = stream[data->startAddress++];
    p->D_ADHESION = stream[data->startAddress++];
    p->L_ADHESION = stream[data->startAddress++];
    p->M_ADHESION = stream[data->startAddress++];

    return 1;
}
*/

