
#ifndef TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_H_INCLUDED
#define TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_H_INCLUDED

#include "Bitstream.h"
#include "Track_Ahead_Free_up_to_level_23_transition_location_Core.h"
#include "BasePacket.h"

struct Track_Ahead_Free_up_to_level_23_transition_location : public BasePacket
{
    Track_Ahead_Free_up_to_level_23_transition_location_Core core;

    Track_Ahead_Free_up_to_level_23_transition_location() : BasePacket(90) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Track_Ahead_Free_up_to_level_23_transition_location*>(&p))
        {
            return header == q->header && core == q->core;
        }

        return false;
    }

    uint16_t length() const override
    {
        return  core.L_PACKET;
    }

    int encode(Bitstream& stream) const override
    {
        return ::encode(stream, core);
    }

    int decode(Bitstream& stream) override
    {
        return ::decode(stream, core);
    }

};

typedef std::shared_ptr<Track_Ahead_Free_up_to_level_23_transition_location> Track_Ahead_Free_up_to_level_23_transition_locationPtr;

#endif // TRACK_AHEAD_FREE_UP_TO_LEVEL_23_TRANSITION_LOCATION_H_INCLUDED

