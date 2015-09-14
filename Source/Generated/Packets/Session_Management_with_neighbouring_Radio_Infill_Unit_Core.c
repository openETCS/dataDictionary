
#include "Session_Management_with_neighbouring_Radio_Infill_Unit_Core.h"
#include "Bit64.h"

int Session_Management_with_neighbouring_Radio_Infill_Unit_UpperBitsNotSet(const Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_RIU,             1) ;
    status = status && UpperBitsNotSet64(p->NID_C,             10);
    status = status && UpperBitsNotSet64(p->NID_RIU,           14);
    status = status && UpperBitsNotSet64(p->NID_RADIO,         64);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Session_Management_with_neighbouring_Radio_Infill_Unit_Encode_Bit(Bitstream* stream, const Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p)
{
    if (Bitstream_Normal(stream, SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_CORE_BITSIZE))
    {
        if (Session_Management_with_neighbouring_Radio_Infill_Unit_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 1,  p->Q_RIU);
            Bitstream_Write(stream, 10, p->NID_C);
            Bitstream_Write(stream, 14, p->NID_RIU);
            Bitstream_Write(stream, 64, p->NID_RADIO);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_RIU:             EqualBits(stream, pos + 15,  pos + 16,  p->Q_RIU);
            //@ assert NID_C:             EqualBits(stream, pos + 16,  pos + 26,  p->NID_C);
            //@ assert NID_RIU:           EqualBits(stream, pos + 26,  pos + 40,  p->NID_RIU);
            //@ assert NID_RADIO:         EqualBits(stream, pos + 40,  pos + 104, p->NID_RADIO);

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

int Session_Management_with_neighbouring_Radio_Infill_Unit_Decode_Bit(Bitstream* stream, Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p)
{
    if (Bitstream_Normal(stream, SESSION_MANAGEMENT_WITH_NEIGHBOURING_RADIO_INFILL_UNIT_CORE_BITSIZE))
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
          requires Q_RIU:          stream->bitpos == pos + 15;
          assigns                  stream->bitpos;
          assigns                  p->Q_RIU;
          ensures  Q_RIU:          stream->bitpos == pos + 16;
          ensures  Q_RIU:          EqualBits(stream, pos + 15, pos + 16, p->Q_RIU);
          ensures  Q_RIU:          UpperBitsNotSet(p->Q_RIU, 1);
        */
        {
            p->Q_RIU        = Bitstream_Read(stream, 1);
        }

        /*@
          requires NID_C:          stream->bitpos == pos + 16;
          assigns                  stream->bitpos;
          assigns                  p->NID_C;
          ensures  NID_C:          stream->bitpos == pos + 26;
          ensures  NID_C:          EqualBits(stream, pos + 16, pos + 26, p->NID_C);
          ensures  NID_C:          UpperBitsNotSet(p->NID_C, 10);
        */
        {
            p->NID_C        = Bitstream_Read(stream, 10);
        }

        /*@
          requires NID_RIU:        stream->bitpos == pos + 26;
          assigns                  stream->bitpos;
          assigns                  p->NID_RIU;
          ensures  NID_RIU:        stream->bitpos == pos + 40;
          ensures  NID_RIU:        EqualBits(stream, pos + 26, pos + 40, p->NID_RIU);
          ensures  NID_RIU:        UpperBitsNotSet(p->NID_RIU, 14);
        */
        {
            p->NID_RIU        = Bitstream_Read(stream, 14);
        }

        /*@
          requires NID_RADIO:      stream->bitpos == pos + 40;
          assigns                  stream->bitpos;
          assigns                  p->NID_RADIO;
          ensures  NID_RADIO:      stream->bitpos == pos + 104;
          ensures  NID_RADIO:      EqualBits(stream, pos + 40, pos + 104, p->NID_RADIO);
          ensures  NID_RADIO:      UpperBitsNotSet(p->NID_RADIO, 64);
        */
        {
            p->NID_RADIO        = Bitstream_Read(stream, 64);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_RIU:             EqualBits(stream, pos + 15,  pos + 16,  p->Q_RIU);
        //@ assert NID_C:             EqualBits(stream, pos + 16,  pos + 26,  p->NID_C);
        //@ assert NID_RIU:           EqualBits(stream, pos + 26,  pos + 40,  p->NID_RIU);
        //@ assert NID_RADIO:         EqualBits(stream, pos + 40,  pos + 104, p->NID_RADIO);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_RIU:             UpperBitsNotSet(p->Q_RIU,             1);
        //@ assert NID_C:             UpperBitsNotSet(p->NID_C,             10);
        //@ assert NID_RIU:           UpperBitsNotSet(p->NID_RIU,           14);
        //@ assert NID_RADIO:         UpperBitsNotSet(p->NID_RADIO,         64);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Session_Management_with_neighbouring_Radio_Infill_Unit_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p)
{
    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_RIU;
    stream[startAddress++] = p->NID_C;
    stream[startAddress++] = p->NID_RIU;
    stream[startAddress++] = p->NID_RADIO;

    data->endAddress = startAddress-1;

    return 1;
}

int Session_Management_with_neighbouring_Radio_Infill_Unit_Decode_Int(const Packet_Info* data, const kcg_int* stream, Session_Management_with_neighbouring_Radio_Infill_Unit_Core* p)
{
    kcg_int startAddress = data->startAddress+1;

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_RIU = stream[startAddress++];
    p->NID_C = stream[startAddress++];
    p->NID_RIU = stream[startAddress++];
    p->NID_RADIO = stream[startAddress++];

    if(data->endAddress != startAddress-1)
    {
        return false;
    }

    return 1;
}

