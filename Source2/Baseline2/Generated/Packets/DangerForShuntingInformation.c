
#include "DangerForShuntingInformation.h"
#include "Bit64.h"

DangerForShuntingInformation* DangerForShuntingInformation_New(void)
{
    void* raw = malloc(sizeof(DangerForShuntingInformation));
    DangerForShuntingInformation* ptr = (DangerForShuntingInformation*)raw;
    DangerForShuntingInformation_Init(ptr);
    return ptr;
}


void DangerForShuntingInformation_Delete(DangerForShuntingInformation* ptr)
{
    free(ptr);
}


int DangerForShuntingInformation_UpperBitsNotSet(const DangerForShuntingInformation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_ASPECT,          1) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DangerForShuntingInformation_EncodeBit(const DangerForShuntingInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, DANGERFORSHUNTINGINFORMATION_BITSIZE))
    {
        if (DangerForShuntingInformation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_ASPECT);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_ASPECT:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

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

int DangerForShuntingInformation_DecodeBit(DangerForShuntingInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, DANGERFORSHUNTINGINFORMATION_BITSIZE))
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
          requires Q_ASPECT:       stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_ASPECT;
          ensures  Q_ASPECT:       stream->bitpos == pos + 16;
          ensures  Q_ASPECT:       EqualBits(stream, pos + 15, pos + 16, p->Q_ASPECT);
          ensures  Q_ASPECT:       UpperBitsNotSet(p->Q_ASPECT, 1);
        */
        {
            p->Q_ASPECT        = Bitstream_Read(stream, 1);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_ASPECT:          EqualBits(stream, pos + 15,  pos + 16,  p->Q_ASPECT);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_ASPECT:          UpperBitsNotSet(p->Q_ASPECT,          1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int DangerForShuntingInformation_EncodeInt(const DangerForShuntingInformation* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 132;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_ASPECT;

    data->endAddress = startAddress-1;

    return 1;
}

int DangerForShuntingInformation_DecodeInt(DangerForShuntingInformation* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 132)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_ASPECT = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

