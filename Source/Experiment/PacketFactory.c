
#include "PacketFactory.h"

#include "AdhesionFactor.h"
#include "EndOfInformation.h"
#include "ErrorReporting.h"
#include "Level23TransitionInformation.h"
#include "TemporarySpeedRestriction.h"

struct TrackToTrain_PacketPool
{
    TemporarySpeedRestriction p65;
    EndOfInformation p255;
};

typedef struct TrackToTrain_PacketPool TrackToTrain_PacketPool;

static TrackToTrain_PacketPool tracktotrain_pool;

struct TrainToTrack_PacketPool
{
    ErrorReporting p4;
    Level23TransitionInformation p9;
    EndOfInformation p255;
};

typedef struct TrainToTrack_PacketPool TrainToTrack_PacketPool;

static TrainToTrack_PacketPool traintotrack_pool;

PacketHeader* PacketFactory_TrackToTrain(PacketHeader header)
{
    switch (header.NID_PACKET)
    {
        case 65 :
        {
            tracktotrain_pool.p65.header = header;
            return &tracktotrain_pool.p65.header;
        }

        case 71 :
        {
            AdhesionFactor* ptr = AdhesionFactor_New();
            printf("71::ptr = %p\n", ptr);
            PacketHeader*   p = &(ptr->header);
            printf("71::p = %p\n", p);
            printf("p->NID_PACKET = %u\n", p->NID_PACKET);
            return p;
        }

        case 255 :
        {
            tracktotrain_pool.p255.header = header;
            return &tracktotrain_pool.p255.header;
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
            traintotrack_pool.p4.header = header;
            return &traintotrack_pool.p4.header;
        }

        case 9 :
        {
            traintotrack_pool.p9.header = header;
            return &traintotrack_pool.p9.header;
        }

        case 255 :
        {
            traintotrack_pool.p255.header = header;
            return &traintotrack_pool.p255.header;
        }

        default :
        {
            return 0;
        }
    };
}

