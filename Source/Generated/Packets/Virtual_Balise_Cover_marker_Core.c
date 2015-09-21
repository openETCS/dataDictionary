
#include "Virtual_Balise_Cover_marker_Core.h"
#include "Bit64.h"

int Virtual_Balise_Cover_marker_UpperBitsNotSet(const Virtual_Balise_Cover_marker_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->NID_VBCMK,         6) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Virtual_Balise_Cover_marker_Encode_Bit(Bitstream* stream, const Virtual_Balise_Cover_marker_Core* p)
{
    if (Bitstream_Normal(stream, VIRTUAL_BALISE_COVER_MARKER_CORE_BITSIZE))
    {
        if (Virtual_Balise_Cover_marker_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 6,  p->NID_VBCMK);


            //@ assert NID_VBCMK:         EqualBits(stream, pos,       pos + 6,   p->NID_VBCMK);

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

int Virtual_Balise_Cover_marker_Decode_Bit(Bitstream* stream, Virtual_Balise_Cover_marker_Core* p)
{
    if (Bitstream_Normal(stream, VIRTUAL_BALISE_COVER_MARKER_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires NID_VBCMK:      stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->NID_VBCMK;
          ensures  NID_VBCMK:      stream->bitpos == pos + 6;
          ensures  NID_VBCMK:      EqualBits(stream, pos + 0, pos + 6, p->NID_VBCMK);
          ensures  NID_VBCMK:      UpperBitsNotSet(p->NID_VBCMK, 6);
        */
        {
            p->NID_VBCMK        = Bitstream_Read(stream, 6);
        }

        //@ assert NID_VBCMK:         EqualBits(stream, pos,       pos + 6,   p->NID_VBCMK);

        //@ assert NID_VBCMK:         UpperBitsNotSet(p->NID_VBCMK,         6);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Virtual_Balise_Cover_marker_Encode_Int(Packet_Info* data, kcg_int* stream, const Virtual_Balise_Cover_marker_Core* p)
{
    stream[data->startAddress++] = p->NID_VBCMK;

    return 1;
}

int Virtual_Balise_Cover_marker_Decode_Int(Packet_Info* data, const kcg_int* stream, Virtual_Balise_Cover_marker_Core* p)
{
    p->NID_VBCMK = stream[data->startAddress++];

    return 1;
}

