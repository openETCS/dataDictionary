
#include "Packet.h"

#include "ErrorReporting.h"
#include "Level23TransitionInformation.h"
#include "TemporarySpeedRestriction.h"
#include "AdhesionFactor.h"
#include "EndOfInformation.h"

#include <assert.h>

int TrackToTrain_DecodeBit(PacketHeader* header, Bitstream* stream)
{
    switch (header->NID_PACKET)
    {
        case 65 :
        {
            TemporarySpeedRestriction* ptr = (TemporarySpeedRestriction*)(header);
            return TemporarySpeedRestriction_DecodeBit(stream, ptr);
        }

        case 71 :
        {
            AdhesionFactor* ptr = (AdhesionFactor*)(header);
            return AdhesionFactor_DecodeBit(stream, ptr);
        }

        default :
        {
            return 0;
        }
    };
}

int TrainToTrack_DecodeBit(PacketHeader* header, Bitstream* stream)
{
    switch (header->NID_PACKET)
    {
        case 4 :
        {
            ErrorReporting* ptr = (ErrorReporting*)(header);
            return ErrorReporting_DecodeBit(stream, ptr);
        }

        case 9 :
        {
            Level23TransitionInformation* ptr = (Level23TransitionInformation*)(header);
            return Level23TransitionInformation_DecodeBit(stream, ptr);
        }

        default :
        {
            return 0;
        }
    };
}

int BothWays_DecodeBit(PacketHeader* header, Bitstream* stream)
{
    switch (header->NID_PACKET)
    {
        case 255 :
        {
            EndOfInformation* ptr = (EndOfInformation*)(header);
            return EndOfInformation_DecodeBit(stream, ptr);
        }

        default :
        {
            return 0;
        }
    };
}

int Packet_DecodeBit(PacketHeader* header, Bitstream* stream)
{
    switch (header->list)
    {
        case 0 :
        {
            return TrainToTrack_DecodeBit(header, stream);
        }

        case 1 :
        {
            return TrackToTrain_DecodeBit(header, stream);
        }

        case 2 :
        {
            return BothWays_DecodeBit(header, stream);
        }

        default :
        {
            return 0;
        }
    };
}

void TrainToTrack_Print(FILE* stream, const PacketHeader* header)
{
    switch (header->NID_PACKET)
    {
        case 4 :
        {
            const ErrorReporting* ptr = (const ErrorReporting*)(header);
            ErrorReporting_Print(stream, ptr);
            break;
        }

        case 9 :
        {
            const Level23TransitionInformation* ptr = (const Level23TransitionInformation*)(header);
            Level23TransitionInformation_Print(stream, ptr);
            break;
        }

        default :
        {
            break;
        }
    };
}

void TrackToTrain_Print(FILE* stream, const PacketHeader* header)
{
    switch (header->NID_PACKET)
    {
        case 65 :
        {
            const TemporarySpeedRestriction* ptr = (const TemporarySpeedRestriction*)(header);
            TemporarySpeedRestriction_Print(stream, ptr);
            break;
        }

        case 71 :
        {
            const AdhesionFactor* ptr = (const AdhesionFactor*)(header);
            AdhesionFactor_Print(stream, ptr);
            break;
        }

        default :
        {
            break;
        }
    };
}

void BothWays_Print(FILE* stream, const PacketHeader* header)
{
    switch (header->NID_PACKET)
    {
        case 255 :
        {
            const EndOfInformation* ptr = (const EndOfInformation*)(header);
            EndOfInformation_Print(stream, ptr);
            break;
        }

        default :
        {
            break;
        }
    };
}

void Packet_Print(FILE* stream, const PacketHeader* header)
{
    switch (header->list)
    {
        case 0 :
        {
            TrainToTrack_Print(stream, header);
            break;
        }

        case 1 :
        {
            TrackToTrain_Print(stream, header);
            break;
        }

        case 2 :
        {
            BothWays_Print(stream, header);
            break;
        }

        default :
        {
            break;
        }
    };
}

uint32_t TrainToTrack_Length(const PacketHeader* header)
{
    switch (header->NID_PACKET)
    {
        case 4 :
        {
            const ErrorReporting* ptr = (const ErrorReporting*)(header);
            return (uint32_t) ptr->L_PACKET;
        }

        case 9 :
        {
            const Level23TransitionInformation* ptr = (const Level23TransitionInformation*)(header);
            return (uint32_t) ptr->L_PACKET;
        }

        default :
        {
            return 0;
        }
    };
}

uint32_t TrackToTrain_Length(const PacketHeader* header)
{
    switch (header->NID_PACKET)
    {
        case 65 :
        {
            const TemporarySpeedRestriction* ptr = (const TemporarySpeedRestriction*)(header);
            return (uint32_t) ptr->L_PACKET;
        }

        case 71 :
        {
            const AdhesionFactor* ptr = (const AdhesionFactor*)(header);
            return (uint32_t) ptr->L_PACKET;
        }

        default :
        {
            return 0;
        }
    };
}

uint32_t Packet_Length(const PacketHeader* header)
{
    switch (header->list)
    {
        case 0 :
        {
            return TrainToTrack_Length(header);
        }

        case 1 :
        {
            return TrackToTrain_Length(header);
        }

        default :
        {
            return 8; // for packet 255
        }
    };
}

int Packet_Delete(PacketHeader* header)
{
    switch (header->list)
    {
        case TRAINTOTRACK :
        {
            switch (header->NID_PACKET)
            {
                case 4 :
                {
                    ErrorReporting_Delete((ErrorReporting*)(header));
                    return 1;
                }

                case 9 :
                {
                    Level23TransitionInformation_Delete((Level23TransitionInformation*)(header));
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_Delete: unexpected value for header->NID_PACKET = %llu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case TRACKTOTRAIN :
        {
            switch (header->NID_PACKET)
            {
                case 65 :
                {
                    TemporarySpeedRestriction_Delete((TemporarySpeedRestriction*)(header));
                    return 1;
                }

                case 71 :
                {
                    AdhesionFactor_Delete((AdhesionFactor*)(header));
                    return 1;
                }

                default :
                {
                    fprintf(stderr, "Packet_Delete: unexpected value for header->NID_PACKET = %llu\n", header->NID_PACKET);
                    return 0;
                }
            };
        }

        case BOTHWAYS :
        {
            assert(header->NID_PACKET == 255);
            EndOfInformation_Delete((EndOfInformation*)header);
            return 1;
        }

        default:
        {
            fprintf(stderr, "Packet_Delete: unexpected value for header->list = %llu\n", header->list);
            return 0;
        }
    };
}
