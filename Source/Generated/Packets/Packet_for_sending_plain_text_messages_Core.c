
#include "Packet_for_sending_plain_text_messages_Core.h"
#include "Bit64.h"

int Packet_for_sending_plain_text_messages_UpperBitsNotSet(const Packet_for_sending_plain_text_messages_Core* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->Q_DIR,             2) ;
    status = status && UpperBitsNotSet64(p->L_PACKET,          13);
    status = status && UpperBitsNotSet64(p->Q_SCALE,           2) ;
    status = status && UpperBitsNotSet64(p->Q_TEXTCLASS,       2) ;
    status = status && UpperBitsNotSet64(p->Q_TEXTDISPLAY,     1) ;
    status = status && UpperBitsNotSet64(p->D_TEXTDISPLAY,     15);
    status = status && UpperBitsNotSet64(p->M_MODETEXTDISPLAY_0, 4) ;
    status = status && UpperBitsNotSet64(p->M_LEVELTEXTDISPLAY_0, 3) ;
    if (p->M_LEVELTEXTDISPLAY_0 == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_NTC_0,         8) ;
    }
    status = status && UpperBitsNotSet64(p->L_TEXTDISPLAY,     15);
    status = status && UpperBitsNotSet64(p->T_TEXTDISPLAY,     10);
    status = status && UpperBitsNotSet64(p->M_MODETEXTDISPLAY_1, 4) ;
    status = status && UpperBitsNotSet64(p->M_LEVELTEXTDISPLAY_1, 3) ;
    if (p->M_LEVELTEXTDISPLAY_1 == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_NTC_1,         8) ;
    }
    status = status && UpperBitsNotSet64(p->Q_TEXTCONFIRM,     2) ;
    if (p->Q_TEXTCONFIRM != 0)
    {
        status = status && UpperBitsNotSet64(p->Q_CONFTEXTDISPLAY, 1) ;
        status = status && UpperBitsNotSet64(p->Q_TEXTREPORT,      1) ;
    }
    if (p->Q_TEXTREPORT == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_TEXTMESSAGE,   8) ;
        status = status && UpperBitsNotSet64(p->NID_C,             10);
        status = status && UpperBitsNotSet64(p->NID_RBC,           14);
    }
    status = status && UpperBitsNotSet64(p->L_TEXT,            8) ;
    status = status && UpperBitsNotSet64(p->X_TEXT,            8) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Packet_for_sending_plain_text_messages_Encode_Bit(Bitstream* stream, const Packet_for_sending_plain_text_messages_Core* p)
{
    if (Bitstream_Normal(stream, PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_CORE_BITSIZE))
    {
        if (Packet_for_sending_plain_text_messages_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 2,  p->Q_DIR);
            Bitstream_Write(stream, 13, p->L_PACKET);
            Bitstream_Write(stream, 2,  p->Q_SCALE);
            Bitstream_Write(stream, 2,  p->Q_TEXTCLASS);
            Bitstream_Write(stream, 1,  p->Q_TEXTDISPLAY);
            Bitstream_Write(stream, 15, p->D_TEXTDISPLAY);
            Bitstream_Write(stream, 4,  p->M_MODETEXTDISPLAY_0);
            Bitstream_Write(stream, 3,  p->M_LEVELTEXTDISPLAY_0);
            if (p->M_LEVELTEXTDISPLAY_0 == 1)
            {
                Bitstream_Write(stream, 8,  p->NID_NTC_0);
            }

            Bitstream_Write(stream, 15, p->L_TEXTDISPLAY);
            Bitstream_Write(stream, 10, p->T_TEXTDISPLAY);
            Bitstream_Write(stream, 4,  p->M_MODETEXTDISPLAY_1);
            Bitstream_Write(stream, 3,  p->M_LEVELTEXTDISPLAY_1);
            if (p->M_LEVELTEXTDISPLAY_1 == 1)
            {
                Bitstream_Write(stream, 8,  p->NID_NTC_1);
            }

            Bitstream_Write(stream, 2,  p->Q_TEXTCONFIRM);
            if (p->Q_TEXTCONFIRM != 0)
            {
                Bitstream_Write(stream, 1,  p->Q_CONFTEXTDISPLAY);
                Bitstream_Write(stream, 1,  p->Q_TEXTREPORT);
            }

            if (p->Q_TEXTREPORT == 1)
            {
                Bitstream_Write(stream, 8,  p->NID_TEXTMESSAGE);
                Bitstream_Write(stream, 10, p->NID_C);
                Bitstream_Write(stream, 14, p->NID_RBC);
            }

            Bitstream_Write(stream, 8,  p->L_TEXT);
            Bitstream_Write(stream, 8,  p->X_TEXT);


            //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
            //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
            //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
            //@ assert Q_TEXTCLASS:       EqualBits(stream, pos + 17,  pos + 19,  p->Q_TEXTCLASS);
            //@ assert Q_TEXTDISPLAY:     EqualBits(stream, pos + 19,  pos + 20,  p->Q_TEXTDISPLAY);
            //@ assert D_TEXTDISPLAY:     EqualBits(stream, pos + 20,  pos + 35,  p->D_TEXTDISPLAY);
            //@ assert M_MODETEXTDISPLAY_0: EqualBits(stream, pos + 35,  pos + 39,  p->M_MODETEXTDISPLAY_0);
            //@ assert M_LEVELTEXTDISPLAY_0: EqualBits(stream, pos + 39,  pos + 42,  p->M_LEVELTEXTDISPLAY_0);

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

int Packet_for_sending_plain_text_messages_Decode_Bit(Bitstream* stream, Packet_for_sending_plain_text_messages_Core* p)
{
    if (Bitstream_Normal(stream, PACKET_FOR_SENDING_PLAIN_TEXT_MESSAGES_CORE_BITSIZE))
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
          requires Q_TEXTCLASS:    stream->bitpos == pos + 17;
          assigns                  stream->bitpos;
          assigns                  p->Q_TEXTCLASS;
          ensures  Q_TEXTCLASS:    stream->bitpos == pos + 19;
          ensures  Q_TEXTCLASS:    EqualBits(stream, pos + 17, pos + 19, p->Q_TEXTCLASS);
          ensures  Q_TEXTCLASS:    UpperBitsNotSet(p->Q_TEXTCLASS, 2);
        */
        {
            p->Q_TEXTCLASS        = Bitstream_Read(stream, 2);
        }

        /*@
          requires Q_TEXTDISPLAY:  stream->bitpos == pos + 19;
          assigns                  stream->bitpos;
          assigns                  p->Q_TEXTDISPLAY;
          ensures  Q_TEXTDISPLAY:  stream->bitpos == pos + 20;
          ensures  Q_TEXTDISPLAY:  EqualBits(stream, pos + 19, pos + 20, p->Q_TEXTDISPLAY);
          ensures  Q_TEXTDISPLAY:  UpperBitsNotSet(p->Q_TEXTDISPLAY, 1);
        */
        {
            p->Q_TEXTDISPLAY        = Bitstream_Read(stream, 1);
        }

        /*@
          requires D_TEXTDISPLAY:  stream->bitpos == pos + 20;
          assigns                  stream->bitpos;
          assigns                  p->D_TEXTDISPLAY;
          ensures  D_TEXTDISPLAY:  stream->bitpos == pos + 35;
          ensures  D_TEXTDISPLAY:  EqualBits(stream, pos + 20, pos + 35, p->D_TEXTDISPLAY);
          ensures  D_TEXTDISPLAY:  UpperBitsNotSet(p->D_TEXTDISPLAY, 15);
        */
        {
            p->D_TEXTDISPLAY        = Bitstream_Read(stream, 15);
        }

        /*@
          requires M_MODETEXTDISPLAY_0: stream->bitpos == pos + 35;
          assigns                  stream->bitpos;
          assigns                  p->M_MODETEXTDISPLAY_0;
          ensures  M_MODETEXTDISPLAY_0: stream->bitpos == pos + 39;
          ensures  M_MODETEXTDISPLAY_0: EqualBits(stream, pos + 35, pos + 39, p->M_MODETEXTDISPLAY_0);
          ensures  M_MODETEXTDISPLAY_0: UpperBitsNotSet(p->M_MODETEXTDISPLAY_0, 4);
        */
        {
            p->M_MODETEXTDISPLAY_0        = Bitstream_Read(stream, 4);
        }

        /*@
          requires M_LEVELTEXTDISPLAY_0: stream->bitpos == pos + 39;
          assigns                  stream->bitpos;
          assigns                  p->M_LEVELTEXTDISPLAY_0;
          ensures  M_LEVELTEXTDISPLAY_0: stream->bitpos == pos + 42;
          ensures  M_LEVELTEXTDISPLAY_0: EqualBits(stream, pos + 39, pos + 42, p->M_LEVELTEXTDISPLAY_0);
          ensures  M_LEVELTEXTDISPLAY_0: UpperBitsNotSet(p->M_LEVELTEXTDISPLAY_0, 3);
        */
        {
            p->M_LEVELTEXTDISPLAY_0        = Bitstream_Read(stream, 3);
        }

        if (p->M_LEVELTEXTDISPLAY_0 == 1)
        {
            {
                p->NID_NTC_0        = Bitstream_Read(stream, 8);
            }

        }

        {
            p->L_TEXTDISPLAY        = Bitstream_Read(stream, 15);
        }

        {
            p->T_TEXTDISPLAY        = Bitstream_Read(stream, 10);
        }

        {
            p->M_MODETEXTDISPLAY_1        = Bitstream_Read(stream, 4);
        }

        {
            p->M_LEVELTEXTDISPLAY_1        = Bitstream_Read(stream, 3);
        }

        if (p->M_LEVELTEXTDISPLAY_1 == 1)
        {
            {
                p->NID_NTC_1        = Bitstream_Read(stream, 8);
            }

        }

        {
            p->Q_TEXTCONFIRM        = Bitstream_Read(stream, 2);
        }

        if (p->Q_TEXTCONFIRM != 0)
        {
            {
                p->Q_CONFTEXTDISPLAY        = Bitstream_Read(stream, 1);
            }

            {
                p->Q_TEXTREPORT        = Bitstream_Read(stream, 1);
            }

        }

        if (p->Q_TEXTREPORT == 1)
        {
            {
                p->NID_TEXTMESSAGE        = Bitstream_Read(stream, 8);
            }

            {
                p->NID_C        = Bitstream_Read(stream, 10);
            }

            {
                p->NID_RBC        = Bitstream_Read(stream, 14);
            }

        }

        {
            p->L_TEXT        = Bitstream_Read(stream, 8);
        }

        {
            p->X_TEXT        = Bitstream_Read(stream, 8);
        }

        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert Q_SCALE:           EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE);
        //@ assert Q_TEXTCLASS:       EqualBits(stream, pos + 17,  pos + 19,  p->Q_TEXTCLASS);
        //@ assert Q_TEXTDISPLAY:     EqualBits(stream, pos + 19,  pos + 20,  p->Q_TEXTDISPLAY);
        //@ assert D_TEXTDISPLAY:     EqualBits(stream, pos + 20,  pos + 35,  p->D_TEXTDISPLAY);
        //@ assert M_MODETEXTDISPLAY_0: EqualBits(stream, pos + 35,  pos + 39,  p->M_MODETEXTDISPLAY_0);
        //@ assert M_LEVELTEXTDISPLAY_0: EqualBits(stream, pos + 39,  pos + 42,  p->M_LEVELTEXTDISPLAY_0);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert Q_SCALE:           UpperBitsNotSet(p->Q_SCALE,           2);
        //@ assert Q_TEXTCLASS:       UpperBitsNotSet(p->Q_TEXTCLASS,       2);
        //@ assert Q_TEXTDISPLAY:     UpperBitsNotSet(p->Q_TEXTDISPLAY,     1);
        //@ assert D_TEXTDISPLAY:     UpperBitsNotSet(p->D_TEXTDISPLAY,     15);
        //@ assert M_MODETEXTDISPLAY_0: UpperBitsNotSet(p->M_MODETEXTDISPLAY_0, 4);
        //@ assert M_LEVELTEXTDISPLAY_0: UpperBitsNotSet(p->M_LEVELTEXTDISPLAY_0, 3);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

int Packet_for_sending_plain_text_messages_Encode_Int(Packet_Info* data, kcg_int* stream, kcg_int startAddress, const Packet_for_sending_plain_text_messages_Core* p)
{
    return 0;
}

int Packet_for_sending_plain_text_messages_Decode_Int(const Packet_Info* data, const kcg_int* stream, Packet_for_sending_plain_text_messages_Core* p)
{
    return 0;
}

