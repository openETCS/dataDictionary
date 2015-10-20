
#include "TemporarySpeedRestrictionRevocation.h"
#include "Bit64.h"

TemporarySpeedRestrictionRevocation* TemporarySpeedRestrictionRevocation_New(void)
{
    void* raw = malloc(sizeof(TemporarySpeedRestrictionRevocation));
    TemporarySpeedRestrictionRevocation* ptr = (TemporarySpeedRestrictionRevocation*)raw;
    TemporarySpeedRestrictionRevocation_Init(ptr);
    return ptr;
}


void TemporarySpeedRestrictionRevocation_Delete(TemporarySpeedRestrictionRevocation* ptr)
{
    free(ptr);
}


int TemporarySpeedRestrictionRevocation_UpperBitsNotSet(const TemporarySpeedRestrictionRevocation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_TSR,           8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int TemporarySpeedRestrictionRevocation_EncodeBit(const TemporarySpeedRestrictionRevocation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TEMPORARYSPEEDRESTRICTIONREVOCATION_BITSIZE))
    {
        if (TemporarySpeedRestrictionRevocation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 8,  p->NID_TSR);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert NID_TSR:           EqualBits(stream, pos + 15,  pos + 23,  p->NID_TSR);

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

int TemporarySpeedRestrictionRevocation_DecodeBit(TemporarySpeedRestrictionRevocation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, TEMPORARYSPEEDRESTRICTIONREVOCATION_BITSIZE))
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
          requires NID_TSR:        stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->NID_TSR;
          ensures  NID_TSR:        stream->bitpos == pos + 23;
          ensures  NID_TSR:        EqualBits(stream, pos + 15, pos + 23, p->NID_TSR);
          ensures  NID_TSR:        UpperBitsNotSet(p->NID_TSR, 8);
        */
        {
            p->NID_TSR        = Bitstream_Read(stream, 8);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert NID_TSR:           EqualBits(stream, pos + 15,  pos + 23,  p->NID_TSR);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_TSR:           UpperBitsNotSet(p->NID_TSR,           8);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

/*
int TemporarySpeedRestrictionRevocation_EncodeInt(const TemporarySpeedRestrictionRevocation* p, PacketInfo* data, kcg_int* stream)
{

}

int TemporarySpeedRestrictionRevocation_DecodeInt(TemporarySpeedRestrictionRevocation* p, PacketInfo* data, kcg_int* stream)
{

}
*/

