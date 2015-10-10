
#include "PacketFactory.h"
#include "ErrorReporting.h"
#include "Level23TransitionInformation.h"
#include "TemporarySpeedRestriction.h"
#include "AdhesionFactor.h"
#include "EndOfInformation.h"

struct TrackToTrain_PacketPool
{
    TemporarySpeedRestriction p65;
    AdhesionFactor p71;
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
            tracktotrain_pool.p71.header = header;
            return &tracktotrain_pool.p71.header;
        }

        case 255 :
        {
            tracktotrain_pool.p255.header = header;
            return &tracktotrain_pool.p255.header;
        }

        default :
        {
            return 0;
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

