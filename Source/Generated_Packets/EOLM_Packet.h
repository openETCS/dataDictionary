
#ifndef EOLM_PACKET_H_INCLUDED
#define EOLM_PACKET_H_INCLUDED

#include "Bitstream.h"
#include "EOLM_Packet_Core.h"
#include "BasePacket.h"

struct EOLM_Packet : public BasePacket
{
    EOLM_Packet_Core core;

    EOLM_Packet() : BasePacket(134) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << uint64_t(id) << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const EOLM_Packet*>(&p))
	{
	    return
                (core.Q_DIR == q->core.Q_DIR) &&
                (core.L_PACKET == q->core.L_PACKET) &&
                (core.Q_SCALE == q->core.Q_SCALE) &&
                (core.NID_LOOP == q->core.NID_LOOP) &&
                (core.D_LOOP == q->core.D_LOOP) &&
                (core.L_LOOP == q->core.L_LOOP) &&
                (core.Q_LOOPDIR == q->core.Q_LOOPDIR) &&
                (core.Q_SSCODE == q->core.Q_SSCODE);
	}
	return false;
     }
};

typedef std::shared_ptr<EOLM_Packet> EOLM_PacketPtr;

#endif // EOLM_PACKET_H_INCLUDED

