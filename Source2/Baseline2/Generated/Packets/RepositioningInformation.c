
#include "RepositioningInformation.h"
#include "Bit64.h"

RepositioningInformation* RepositioningInformation_New(void)
{
    void* raw = malloc(sizeof(RepositioningInformation));
    RepositioningInformation* ptr = (RepositioningInformation*)raw;
    RepositioningInformation_Init(ptr);
    return ptr;
}


void RepositioningInformation_Delete(RepositioningInformation* ptr)
{
    free(ptr);
}


int RepositioningInformation_UpperBitsNotSet(const RepositioningInformation* p)
{
    int status = 1;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->L_SECTION,         15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int RepositioningInformation_EncodeBit(const RepositioningInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, REPOSITIONINGINFORMATION_BITSIZE))
    {
        if (RepositioningInformation_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 15, p->L_SECTION);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert L_SECTION:         EqualBits(stream, pos + 17,  pos + 32,  p->L_SECTION);

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

int RepositioningInformation_DecodeBit(RepositioningInformation* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, REPOSITIONINGINFORMATION_BITSIZE))
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
          requires L_SECTION:      stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->L_SECTION;
          ensures  L_SECTION:      stream->bitpos == pos + 32;
          ensures  L_SECTION:      EqualBits(stream, pos + 17, pos + 32, p->L_SECTION);
          ensures  L_SECTION:      UpperBitsNotSet(p->L_SECTION, 15);
        */
        {
            p->L_SECTION        = Bitstream_Read(stream, 15);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert L_SECTION:         EqualBits(stream, pos + 17,  pos + 32,  p->L_SECTION);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert L_SECTION:         UpperBitsNotSet(p->L_SECTION,         15);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

/*
int RepositioningInformation_EncodeInt(const RepositioningInformation* p, PacketInfo* data, kcg_int* stream)
{

}

int RepositioningInformation_DecodeInt(RepositioningInformation* p, PacketInfo* data, kcg_int* stream)
{

}
*/

