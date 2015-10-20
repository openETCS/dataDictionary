
#include "InternationalStaticSpeedProfile_1.h"
#include "Bit64.h"

InternationalStaticSpeedProfile_1* InternationalStaticSpeedProfile_1_New(void)
{
    void* raw = malloc(sizeof(InternationalStaticSpeedProfile_1));
    InternationalStaticSpeedProfile_1* ptr = (InternationalStaticSpeedProfile_1*)raw;
    InternationalStaticSpeedProfile_1_Init(ptr);
    return ptr;
}


void InternationalStaticSpeedProfile_1_Delete(InternationalStaticSpeedProfile_1* ptr)
{
    free(ptr);
}


int InternationalStaticSpeedProfile_1_UpperBitsNotSet(const InternationalStaticSpeedProfile_1* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->NC_DIFF,           4) ;
    status = status && UpperBitsNotSet64(p->V_DIFF,            7) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int InternationalStaticSpeedProfile_1_EncodeBit(const InternationalStaticSpeedProfile_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, INTERNATIONALSTATICSPEEDPROFILE_1_BITSIZE))
    {
        if (InternationalStaticSpeedProfile_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 4,  p->NC_DIFF);
            Bitstream_Write(stream, 7,  p->V_DIFF);


            //@ assert NC_DIFF:           EqualBits(stream, pos,       pos + 4,   p->NC_DIFF);
            //@ assert V_DIFF:            EqualBits(stream, pos + 4,   pos + 11,  p->V_DIFF);

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

int InternationalStaticSpeedProfile_1_DecodeBit(InternationalStaticSpeedProfile_1* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, INTERNATIONALSTATICSPEEDPROFILE_1_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires NC_DIFF:        stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->NC_DIFF;
          ensures  NC_DIFF:        stream->bitpos == pos + 4;
          ensures  NC_DIFF:        EqualBits(stream, pos + 0, pos + 4, p->NC_DIFF);
          ensures  NC_DIFF:        UpperBitsNotSet(p->NC_DIFF, 4);
        */
        {
            p->NC_DIFF        = Bitstream_Read(stream, 4);
        }

        /*@
          requires V_DIFF:         stream->bitpos == pos + 4;
          assigns                  stream->bitpos;
          assigns                  p->V_DIFF;
          ensures  V_DIFF:         stream->bitpos == pos + 11;
          ensures  V_DIFF:         EqualBits(stream, pos + 4, pos + 11, p->V_DIFF);
          ensures  V_DIFF:         UpperBitsNotSet(p->V_DIFF, 7);
        */
        {
            p->V_DIFF        = Bitstream_Read(stream, 7);
        }

        //@ assert NC_DIFF:           EqualBits(stream, pos,       pos + 4,   p->NC_DIFF);
        //@ assert V_DIFF:            EqualBits(stream, pos + 4,   pos + 11,  p->V_DIFF);

        //@ assert NC_DIFF:           UpperBitsNotSet(p->NC_DIFF,           4);
        //@ assert V_DIFF:            UpperBitsNotSet(p->V_DIFF,            7);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

/*
int InternationalStaticSpeedProfile_1_EncodeInt(const InternationalStaticSpeedProfile_1* p, PacketInfo* data, kcg_int* stream)
{

}

int InternationalStaticSpeedProfile_1_DecodeInt(InternationalStaticSpeedProfile_1* p, PacketInfo* data, kcg_int* stream)
{

}
*/

