
#include "PacketForSendingPlainTextMessages.h"
#include "Bit64.h"

// number of xells in allocation memory
#define PacketForSendingPlainTextMessagesMemoryMax 32

// end-of-freelist indicator
#define PacketForSendingPlainTextMessagesMemoryNil (-1)

// allocation memory
static PacketForSendingPlainTextMessages PacketForSendingPlainTextMessagesMemory[PacketForSendingPlainTextMessagesMemoryMax];

// lowest unused cell of allocation memory
static uint64_t PacketForSendingPlainTextMessagesMemoryTop = 0;

// index of first element of freelist
static uint64_t PacketForSendingPlainTextMessagesMemoryFreeList = PacketForSendingPlainTextMessagesMemoryNil;

PacketForSendingPlainTextMessages* PacketForSendingPlainTextMessages_New(void)
{
    PacketForSendingPlainTextMessages* ptr;

    if (PacketForSendingPlainTextMessagesMemoryFreeList != PacketForSendingPlainTextMessagesMemoryNil)
    {
         // allocate from freelist
	 ptr = &PacketForSendingPlainTextMessagesMemory[PacketForSendingPlainTextMessagesMemoryFreeList];
	 PacketForSendingPlainTextMessagesMemoryFreeList = PacketForSendingPlainTextMessagesMemory[PacketForSendingPlainTextMessagesMemoryFreeList].header.NID_PACKET;
    }
    else if (PacketForSendingPlainTextMessagesMemoryTop < PacketForSendingPlainTextMessagesMemoryMax)
    {
         // allocate from top
	 ptr = &PacketForSendingPlainTextMessagesMemory[PacketForSendingPlainTextMessagesMemoryTop];
	 PacketForSendingPlainTextMessagesMemoryTop += 1;
    }
    else
    {
         // memory exhausted
	 return 0;
    }

    PacketForSendingPlainTextMessages_Init(ptr);

    return ptr;
}


void PacketForSendingPlainTextMessages_Delete(PacketForSendingPlainTextMessages* ptr)
{
    // prepend to freelist
    ptr->header.NID_PACKET = PacketForSendingPlainTextMessagesMemoryFreeList;
    PacketForSendingPlainTextMessagesMemoryFreeList = ptr - PacketForSendingPlainTextMessagesMemory;
}


int PacketForSendingPlainTextMessages_UpperBitsNotSet(const PacketForSendingPlainTextMessages* p)
{
    int status = 1;

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
        status = status && UpperBitsNotSet64(p->NID_STM_0,         8) ;
    }
    status = status && UpperBitsNotSet64(p->L_TEXTDISPLAY,     15);
    status = status && UpperBitsNotSet64(p->T_TEXTDISPLAY,     10);
    status = status && UpperBitsNotSet64(p->M_MODETEXTDISPLAY_1, 4) ;
    status = status && UpperBitsNotSet64(p->M_LEVELTEXTDISPLAY_1, 3) ;
    if (p->M_LEVELTEXTDISPLAY_1 == 1)
    {
        status = status && UpperBitsNotSet64(p->NID_STM_1,         8) ;
    }
    status = status && UpperBitsNotSet64(p->Q_TEXTCONFIRM,     2) ;
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

int PacketForSendingPlainTextMessages_EncodeBit(const PacketForSendingPlainTextMessages* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, PACKETFORSENDINGPLAINTEXTMESSAGES_BITSIZE))
    {
        if (PacketForSendingPlainTextMessages_UpperBitsNotSet(p))
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
                Bitstream_Write(stream, 8,  p->NID_STM_0);
            }

            Bitstream_Write(stream, 15, p->L_TEXTDISPLAY);
            Bitstream_Write(stream, 10, p->T_TEXTDISPLAY);
            Bitstream_Write(stream, 4,  p->M_MODETEXTDISPLAY_1);
            Bitstream_Write(stream, 3,  p->M_LEVELTEXTDISPLAY_1);
            if (p->M_LEVELTEXTDISPLAY_1 == 1)
            {
                Bitstream_Write(stream, 8,  p->NID_STM_1);
            }

            Bitstream_Write(stream, 2,  p->Q_TEXTCONFIRM);
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

int PacketForSendingPlainTextMessages_DecodeBit(PacketForSendingPlainTextMessages* p, Bitstream* stream)
{
    if (Bitstream_Normal(stream, PACKETFORSENDINGPLAINTEXTMESSAGES_BITSIZE))
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
                p->NID_STM_0        = Bitstream_Read(stream, 8);
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
                p->NID_STM_1        = Bitstream_Read(stream, 8);
            }

        }

        {
            p->Q_TEXTCONFIRM        = Bitstream_Read(stream, 2);
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

int PacketForSendingPlainTextMessages_EncodeInt(const PacketForSendingPlainTextMessages* p, PacketInfo* data, kcg_int* stream)
{
    data->nid_packet = 72;
    data->q_dir = p->Q_DIR;
    data->valid = 1;

    kcg_int startAddress = data->startAddress;

    stream[startAddress++] = p->header.NID_PACKET;

    stream[startAddress++] = p->Q_DIR;
    stream[startAddress++] = p->L_PACKET;
    stream[startAddress++] = p->Q_SCALE;
    stream[startAddress++] = p->Q_TEXTCLASS;
    stream[startAddress++] = p->Q_TEXTDISPLAY;
    stream[startAddress++] = p->D_TEXTDISPLAY;
    stream[startAddress++] = p->M_MODETEXTDISPLAY_0;
    stream[startAddress++] = p->M_LEVELTEXTDISPLAY_0;
    stream[startAddress++] = p->NID_STM_0;
    stream[startAddress++] = p->L_TEXTDISPLAY;
    stream[startAddress++] = p->T_TEXTDISPLAY;
    stream[startAddress++] = p->M_MODETEXTDISPLAY_1;
    stream[startAddress++] = p->M_LEVELTEXTDISPLAY_1;
    stream[startAddress++] = p->NID_STM_1;
    stream[startAddress++] = p->Q_TEXTCONFIRM;
    stream[startAddress++] = p->L_TEXT;
    stream[startAddress++] = p->X_TEXT;

    data->endAddress = startAddress-1;

    return 1;
}

int PacketForSendingPlainTextMessages_DecodeInt(PacketForSendingPlainTextMessages* p, const PacketInfo* data, const kcg_int* stream)
{
    if(data->nid_packet != 72)
    {
         return 0;
    }

    kcg_int startAddress = data->startAddress;
    p->header.NID_PACKET = stream[startAddress++];

    p->Q_DIR = stream[startAddress++];
    p->L_PACKET = stream[startAddress++];
    p->Q_SCALE = stream[startAddress++];
    p->Q_TEXTCLASS = stream[startAddress++];
    p->Q_TEXTDISPLAY = stream[startAddress++];
    p->D_TEXTDISPLAY = stream[startAddress++];
    p->M_MODETEXTDISPLAY_0 = stream[startAddress++];
    p->M_LEVELTEXTDISPLAY_0 = stream[startAddress++];
    p->NID_STM_0 = stream[startAddress++];
    p->L_TEXTDISPLAY = stream[startAddress++];
    p->T_TEXTDISPLAY = stream[startAddress++];
    p->M_MODETEXTDISPLAY_1 = stream[startAddress++];
    p->M_LEVELTEXTDISPLAY_1 = stream[startAddress++];
    p->NID_STM_1 = stream[startAddress++];
    p->Q_TEXTCONFIRM = stream[startAddress++];
    p->L_TEXT = stream[startAddress++];
    p->X_TEXT = stream[startAddress++];

    if(startAddress-1 != data->endAddress)
    {
         return 0;
    }

    return 1;
}

