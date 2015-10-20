
#include "ListOfBalisesForSHArea_1.h"
#include "Bit64.h"

ListOfBalisesForSHArea_1* ListOfBalisesForSHArea_1_New(void)
{
    void* raw = malloc(sizeof(ListOfBalisesForSHArea_1));
    ListOfBalisesForSHArea_1* ptr = (ListOfBalisesForSHArea_1*)raw;
    ListOfBalisesForSHArea_1_Init(ptr);
    return ptr;
}


void ListOfBalisesForSHArea_1_Delete(ListOfBalisesForSHArea_1* ptr)
{
    free(ptr);
}


int ListOfBalisesForSHArea_1_UpperBitsNotSet(const ListOfBalisesForSHArea_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1) ;
    if (p->Q_NEWCOUNTRY == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_C,             10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG,            14);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ListOfBalisesForSHArea_1_EncodeBit(const ListOfBalisesForSHArea_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LISTOFBALISESFORSHAREA_1_BITSIZE))
    {
        if (ListOfBalisesForSHArea_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY);
            if (p->Q_NEWCOUNTRY == 1)
            {
                Bitstream_Write(stream, 10, p->NID_C);
            }

            Bitstream_Write(stream, 14, p->NID_BG);


            //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos,       pos + 1,   p->Q_NEWCOUNTRY);

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

int ListOfBalisesForSHArea_1_DecodeBit(ListOfBalisesForSHArea_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, LISTOFBALISESFORSHAREA_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires Q_NEWCOUNTRY:   stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->Q_NEWCOUNTRY;
          ensures  Q_NEWCOUNTRY:   stream->bitpos == pos + 1;
          ensures  Q_NEWCOUNTRY:   EqualBits(stream, pos + 0, pos + 1, p->Q_NEWCOUNTRY);
          ensures  Q_NEWCOUNTRY:   UpperBitsNotSet(p->Q_NEWCOUNTRY, 1);
        */
        {
            p->Q_NEWCOUNTRY        = Bitstream_Read(stream, 1);
        }

        if (p->Q_NEWCOUNTRY == 1)
        {
            {
                p->NID_C        = Bitstream_Read(stream, 10);
            }

        }

        {
            p->NID_BG        = Bitstream_Read(stream, 14);
        }

        //@ assert Q_NEWCOUNTRY:      EqualBits(stream, pos,       pos + 1,   p->Q_NEWCOUNTRY);

        //@ assert Q_NEWCOUNTRY:      UpperBitsNotSet(p->Q_NEWCOUNTRY,      1);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

/*
int ListOfBalisesForSHArea_1_EncodeInt(const ListOfBalisesForSHArea_1* p, PacketInfo* data, kcg_int* stream)
{

}

int ListOfBalisesForSHArea_1_DecodeInt(ListOfBalisesForSHArea_1* p, PacketInfo* data, kcg_int* stream)
{

}
*/

