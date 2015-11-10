
#include "PacketSequence.h"
#include "Packet_Delete.h"
#include "Packet_Equal.h"
#include "Packet_Print.h"
#include "PacketFactory.h"
#include "Packet_EncodeInt.h"
#include "Packet_DecodeInt.h"

void PacketSequence_Init(PacketSequence* s)
{
    for (uint32_t i = 0; i < 50; ++i)
    {
        s->header[i] = 0;
    }

    s->size = 0;
}

void PacketSequence_Print(const PacketSequence* p, FILE* stream)
{
    fprintf(stream, "[");

    for (uint32_t i = 0; i < p->size; ++i)
    {
        if (i == 0)
        {
            Packet_Print(p->header[i], stream);
        }
        else
        {
            fprintf(stream, ",");
            Packet_Print(p->header[i], stream);
        }
    }

    fprintf(stream, "]\n");
}


void PacketSequence_Clear(PacketSequence* p)
{
    for (uint32_t i = 0; i < p->size; ++i)
    {
        Packet_Delete(p->header[i]);
    }

    p->size = 0;
}

int PacketSequence_Equal(const PacketSequence* a, const PacketSequence* b)
{
    if (a->size == b->size)
    {
        int status = 1;

        for (uint32_t i = 0; i < a->size; ++i)
        {
            status = status && Packet_Equal(a->header[i], b->header[i]);
        }

        return status;
    }
    else
    {
        return 0;
    }
}

int PacketSequence_EncodeInt(const PacketSequence* p,  CompressedPackets* packetStruct)
{
    kcg_int startAddress = 0;

    for (uint32_t i = 0; i < p->size; ++i)
    {
        packetStruct->PacketHeaders[i].startAddress = startAddress;
        if (Packet_EncodeInt(PacketSequence_Get(p, i), &(packetStruct->PacketHeaders[i]), packetStruct->PacketData) != 1)
	{
             return 0;
        }
        startAddress = packetStruct->PacketHeaders[i].endAddress + 1;
    }

    if (packetStruct->PacketHeaders[p->size-1].nid_packet != 255)
    {
        return 0;
    }

    return 1;
}

int PacketSequence_DecodeInt(PacketSequence* p, uint64_t q_updown, const CompressedPackets* packetStruct)
{
    for (uint32_t i = 0; i < 50; ++i)
    {
        if (packetStruct->PacketHeaders[i].valid == 1)
        {
	    PacketHeader packet_header = {0, 0};
            PacketHeader* ptr = 0;
	    
	    packet_header.NID_PACKET = packetStruct->PacketHeaders[i].nid_packet;

	    if (packet_header.NID_PACKET == 255)
	    {
                ptr = PacketFactory_BothWays(packet_header);
		assert(ptr);

		PacketSequence_Add(p, ptr);
		break;
	    }

	    if (q_updown == 1)
	    {
                ptr = PacketFactory_TrackToTrain(packet_header);

		if (ptr)
		{
                    PacketSequence_Add(p, ptr);
		}
		else
		{
		    return 0;
		}
	    }
	    else
	    {
                assert(q_updown == 0);
		ptr = PacketFactory_TrainToTrack(packet_header);

		if (ptr)
		{
                    PacketSequence_Add(p, ptr);
		}
		else
		{
		    return 0;
		}
	    }

	    if (ptr)
	    {
                Packet_DecodeInt(ptr, &(packetStruct->PacketHeaders[i]), packetStruct->PacketData);
	    }
	    else
	    {
                return 0;
	    }
        }
    }
    return 1;
}

