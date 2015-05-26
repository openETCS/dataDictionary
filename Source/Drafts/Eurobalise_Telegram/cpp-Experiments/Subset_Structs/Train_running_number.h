
#ifndef TRAIN_RUNNING_NUMBER_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_H_INCLUDED

#include "Bitstream.h"
#include "BasePacket.h"
#include "Train_running_number_Core.h"

struct Train_running_number : public BasePacket
{
    Train_running_number_Core core;

    Train_running_number() : BasePacket(5) {}
};

#ifdef __cplusplus

inline bool operator==(const Train_running_number& a, const Train_running_number& b)
{
     return (a.core == b.core);
}

inline bool operator!=(const Train_running_number& a, const Train_running_number& b)
{
     return !(a == b);
}

#endif // __cplusplus

typedef std::shared_ptr<Train_running_number> Train_running_numberPtr;

#endif // TRAIN_RUNNING_NUMBER_H_INCLUDED

