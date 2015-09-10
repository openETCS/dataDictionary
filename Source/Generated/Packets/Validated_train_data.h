
#ifndef VALIDATED_TRAIN_DATA_H_INCLUDED
#define VALIDATED_TRAIN_DATA_H_INCLUDED

#include "Bitstream.h"
#include "Validated_train_data_Core.h"
#include "BasePacket.h"

struct Validated_train_data : public BasePacket
{
    Validated_train_data_Core core;

    Validated_train_data() : BasePacket(11) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << header << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
        if (auto q = dynamic_cast<const Validated_train_data*>(&p))
        {
            return header == q->header && core == q->core;
        }

        return false;
    }

    uint16_t length() const override
    {
        return  core.L_PACKET;
    }
};

typedef std::shared_ptr<Validated_train_data> Validated_train_dataPtr;

#endif // VALIDATED_TRAIN_DATA_H_INCLUDED

