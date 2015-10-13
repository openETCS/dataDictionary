
#include "PacketFactory.h"

#include "AdhesionFactor.h"
#include "EndOfInformation.h"
#include "ErrorReporting.h"
#include "Level23TransitionInformation.h"
#include "TemporarySpeedRestriction.h"


PacketHeader* PacketFactory_TrackToTrain(PacketHeader header)
{
    switch (header.NID_PACKET)
    {
        case 65 :
        {
            TemporarySpeedRestriction* ptr = TemporarySpeedRestriction_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 71 :
        {
            AdhesionFactor* ptr = AdhesionFactor_New();
            PacketHeader*   p = &(ptr->header);
            //printf("71::ptr = %p\n", (void*)ptr);
            //printf("71::p = %p\n", (void*)p);
            //printf("p->NID_PACKET = %u\n", p->NID_PACKET);
            return p;
        }

        case 255 :
        {
            EndOfInformation* ptr = EndOfInformation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        default :
        {
            return NULL;
        }
    };
}

PacketHeader* PacketFactory_TrainToTrack(PacketHeader header)
{
    switch (header.NID_PACKET)
    {
        case 4 :
        {
            ErrorReporting* ptr = ErrorReporting_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 9 :
        {
            Level23TransitionInformation* ptr = Level23TransitionInformation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        case 255 :
        {
            EndOfInformation* ptr = EndOfInformation_New();
            PacketHeader*   p = &(ptr->header);
            return p;
        }

        default :
        {
            return 0;
        }
    };
}

