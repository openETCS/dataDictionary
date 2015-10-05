
#include "Data_used_by_applications_outside_the_ERTMSETCS_system_Core.h"
#include "Bit64.h"

int Data_used_by_applications_outside_the_ERTMSETCS_system_UpperBitsNotSet(const Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->NID_XUSER,         9) ;
    status = status && UpperBitsNotSet64(p->Other_data_depending_on__NID_XUSER, 64);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Data_used_by_applications_outside_the_ERTMSETCS_system_Encode_Bit(Bitstream* stream, const Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p)
{
    if (Bitstream_Normal(stream, DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_BITSIZE))
    {
        if (Data_used_by_applications_outside_the_ERTMSETCS_system_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 9,  p->NID_XUSER);
            Bitstream_Write(stream, 64, p->Other_data_depending_on__NID_XUSER);


            //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
            //@ assert NID_XUSER:         EqualBits(stream, pos + 13,  pos + 22,  p->NID_XUSER);
            //@ assert Other_data_depending_on__NID_XUSER: EqualBits(stream, pos + 22,  pos + 86,  p->Other_data_depending_on__NID_XUSER);

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

int Data_used_by_applications_outside_the_ERTMSETCS_system_Decode_Bit(Bitstream* stream, Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p)
{
    if (Bitstream_Normal(stream, DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires L_PACKET:       stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->L_PACKET;
          ensures  L_PACKET:       stream->bitpos == pos + 13;
          ensures  L_PACKET:       EqualBits(stream, pos + 0, pos + 13, p->L_PACKET);
          ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
        */
        {
            p->L_PACKET        = Bitstream_Read(stream, 13);
        }

        /*@
          requires NID_XUSER:      stream->bitpos == pos + 13;
          assigns                  stream->bitpos;
          assigns                  p->NID_XUSER;
          ensures  NID_XUSER:      stream->bitpos == pos + 22;
          ensures  NID_XUSER:      EqualBits(stream, pos + 13, pos + 22, p->NID_XUSER);
          ensures  NID_XUSER:      UpperBitsNotSet(p->NID_XUSER, 9);
        */
        {
            p->NID_XUSER        = Bitstream_Read(stream, 9);
        }

        /*@
          requires Other_data_depending_on__NID_XUSER: stream->bitpos == pos + 22;
          assigns                  stream->bitpos;
          assigns                  p->Other_data_depending_on__NID_XUSER;
          ensures  Other_data_depending_on__NID_XUSER: stream->bitpos == pos + 86;
          ensures  Other_data_depending_on__NID_XUSER: EqualBits(stream, pos + 22, pos + 86, p->Other_data_depending_on__NID_XUSER);
          ensures  Other_data_depending_on__NID_XUSER: UpperBitsNotSet(p->Other_data_depending_on__NID_XUSER, 64);
        */
        {
            p->Other_data_depending_on__NID_XUSER        = Bitstream_Read(stream, 64);
        }

        //@ assert L_PACKET:          EqualBits(stream, pos,       pos + 13,  p->L_PACKET);
        //@ assert NID_XUSER:         EqualBits(stream, pos + 13,  pos + 22,  p->NID_XUSER);
        //@ assert Other_data_depending_on__NID_XUSER: EqualBits(stream, pos + 22,  pos + 86,  p->Other_data_depending_on__NID_XUSER);

        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_XUSER:         UpperBitsNotSet(p->NID_XUSER,         9);
        //@ assert Other_data_depending_on__NID_XUSER: UpperBitsNotSet(p->Other_data_depending_on__NID_XUSER, 64);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Data_used_by_applications_outside_the_ERTMSETCS_system_Encode_Int(PacketInfo* data, kcg_int* stream, const Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p)
{
    stream[data->startAddress++] = p->L_PACKET;
    stream[data->startAddress++] = p->NID_XUSER;
    stream[data->startAddress++] = p->Other_data_depending_on__NID_XUSER;

    return 1;
}

int Data_used_by_applications_outside_the_ERTMSETCS_system_Decode_Int(PacketInfo* data, const kcg_int* stream, Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p)
{
    p->L_PACKET = stream[data->startAddress++];
    p->NID_XUSER = stream[data->startAddress++];
    p->Other_data_depending_on__NID_XUSER = stream[data->startAddress++];

    return 1;
}

