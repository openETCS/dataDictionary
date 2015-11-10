
#include "EurobaliseTelegram.h"
#include "PacketFactory.h"
#include "Packet_DecodeBit.h"
#include "Packet_EncodeBit.h"
#include "Packet_Length.h"

void EurobaliseTelegram_Print(const EurobaliseTelegram* t, FILE* stream)
{
    TelegramHeader_Print(&t->header, stream);
    PacketSequence_Print(&t->packets, stream);
}

void EurobaliseTelegram_Clear(EurobaliseTelegram* t)
{
    TelegramHeader_Init(&t->header);
    PacketSequence_Clear(&t->packets);
}

int EurobaliseTelegram_Equal(const EurobaliseTelegram* a, const EurobaliseTelegram* b)
{
    return TelegramHeader_Equal(&a->header,  &b->header) &&
           PacketSequence_Equal(&a->packets, &b->packets);
}


int EurobaliseTelegram_DecodeBit(EurobaliseTelegram* t, Bitstream* stream)
{
    //printf("EurobaliseTelegram_DecodeBit::enter\n");

    if (TelegramHeader_DecodeBit(stream, &t->header) != 1)
    {
        return 0;
    }

    //printf("EurobaliseTelegram_DecodeBit::t->header.Q_UPDOWN = %"PRIu64"\n", t->header.Q_UPDOWN);

    const uint32_t old_pos = stream->bitpos;
    uint32_t current_pos = stream->bitpos;

    while (stream->bitpos <= 1023 + old_pos)
    {
        //printf("in while %lu", stream->bitpos);
        if (current_pos != stream->bitpos)
        {
            //printf("problem here %lu is not %lu\n", current_pos, stream->bitpos);
            return 0;
        }

        PacketHeader packet_header = {0, 0};
        PacketHeader_DecodeBit(&packet_header, stream);
        //printf("EurobaliseTelegram_DecodeBit::packet_header = %d\n", packet_header.NID_PACKET);

        PacketHeader* ptr = 0;

        if (packet_header.NID_PACKET == 255)
        {
            ptr = PacketFactory_BothWays(packet_header);
            assert(ptr);

            // beware: no need to decode further fields
            EurobaliseTelegram_Add(t, ptr);
            //printf("EurobaliseTelegram_DecodeBit size after add = %d\n", EurobaliseTelegram_Size(t));
            break;
        }

        if (t->header.Q_UPDOWN == 1)
        {

            ptr = PacketFactory_TrackToTrain(packet_header);

            if (ptr)
            {
                EurobaliseTelegram_Add(t, ptr);
                //printf("EurobaliseTelegram_DecodeBit size after add = %d\n", EurobaliseTelegram_Size(t));
            }
            else
            {
                return 0;
            }
        }
        else
        {
            assert(t->header.Q_UPDOWN == 0);
            ptr = PacketFactory_TrainToTrack(packet_header);
            //PacketHeader_Print(&packet_header, stdout);

            if (ptr)
            {
                EurobaliseTelegram_Add(t, ptr);
                //printf("EurobaliseTelegram_DecodeBit size after add = %d\n", EurobaliseTelegram_Size(t));
            }
            else
            {
                return 0;
            }
        }

        if (ptr)
        {
            Packet_DecodeBit(ptr, stream);
            current_pos += Packet_Length(ptr);
        }
    }

    return 1;
}

int EurobaliseTelegram_EncodeBit(const EurobaliseTelegram* t, Bitstream* stream)
{
    if (TelegramHeader_EncodeBit(&t->header, stream) != 1)
    {
        return 0;
    }

    uint32_t old_pos = stream->bitpos;

    // check that last packet denotes end of message
    assert(PacketSequence_Back(&t->packets)->NID_PACKET == 255);

    for (uint32_t i = 0; i < EurobaliseTelegram_Size(t); ++i)
    {
        if (stream->bitpos > 1023 + old_pos)
        {
            return 0;
        }

        if (PacketHeader_EncodeBit(EurobaliseTelegram_Get(t, i), stream) != 1)
        {
            return 0;
        }

        if (Packet_EncodeBit(EurobaliseTelegram_Get(t, i), stream) != 1)
        {
            return 0;
        }

    }

    return 1;
}

// Note: the telegram header (t->header) is not used by this function
//
int EurobaliseTelegram_EncodeInt(const EurobaliseTelegram* t, CompressedPackets* packetStruct)
{
    return PacketSequence_EncodeInt(&(t->packets), packetStruct);
}

// Note: this function assumes that the telegram header, that is,
//       the field t->header.Q_UPDOWN has already been set to 0 or 1
//
int EurobaliseTelegram_DecodeInt(EurobaliseTelegram* t, const CompressedPackets* packetStruct)
{
    return PacketSequence_DecodeInt(&(t->packets), t->header.Q_UPDOWN, packetStruct);;
}

