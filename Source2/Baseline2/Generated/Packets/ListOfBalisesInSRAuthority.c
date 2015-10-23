
#include "ListOfBalisesInSRAuthority.h"
#include "Bit64.h"

ListOfBalisesInSRAuthority* ListOfBalisesInSRAuthority_New(void)
{
    void* raw = malloc(sizeof(ListOfBalisesInSRAuthority));
    ListOfBalisesInSRAuthority* ptr = (ListOfBalisesInSRAuthority*)raw;
    ListOfBalisesInSRAuthority_Init(ptr);
    return ptr;
}


void ListOfBalisesInSRAuthority_Delete(ListOfBalisesInSRAuthority* ptr)
{
    free(ptr);
}


int ListOfBalisesInSRAuthority_UpperBitsNotSet(const ListOfBalisesInSRAuthority* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->N_ITER_1,          5) ;
    for (uint32_t i = 0; i < p->N_ITER_1; ++i)
    {
        status = status && ListOfBalisesInSRAuthority_1_UpperBitsNotSet(&(p->sub_1[i]));
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

int ListOfBalisesInSRAuthority_EncodeBit(const ListOfBalisesInSRAuthority* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LISTOFBALISESINSRAUTHORITY_BITSIZE))
    {
        if (ListOfBalisesInSRAuthority_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 5,  p->N_ITER_1);
            for (uint32_t i = 0; i < p->N_ITER_1; ++i)
            {
                ListOfBalisesInSRAuthority_1_EncodeBit(&(p->sub_1[i]), stream);
            }


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

int ListOfBalisesInSRAuthority_DecodeBit(ListOfBalisesInSRAuthority* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LISTOFBALISESINSRAUTHORITY_BITSIZE))
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

    {
            p->N_ITER_1        = Bitstream_Read(stream, 5);
        }

        for (uint32_t i = 0; i < p->N_ITER_1; ++i)
        {
            ListOfBalisesInSRAuthority_1_DecodeBit(&(p->sub_1[i]), stream);
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

int ListOfBalisesInSRAuthority_EncodeInt(const ListOfBalisesInSRAuthority* p, PacketInfo* data, kcg_int* stream)
{
    return 0;
}

int ListOfBalisesInSRAuthority_DecodeInt(ListOfBalisesInSRAuthority* p, PacketInfo* data, kcg_int* stream)
{
    return 0;
}

