
#ifndef TRAIN_RUNNING_NUMBER_CORE_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Train_running_number_Core
{
    // TransmissionMedia=RBC
    // Train running number        
    // Packet Number = 5

    uint16_t  L_PACKET;         // # 13
    uint32_t  NID_OPERATIONAL;  // # 32
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Train_running_number_Core& p)
{
    stream 
       << +p.L_PACKET << ','
       << +p.NID_OPERATIONAL;

    return stream;
}

inline bool operator==(const Train_running_number_Core& a, const Train_running_number_Core& b)
{
    bool status = true;
    
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NID_OPERATIONAL == b.NID_OPERATIONAL);

    return status;
}

inline bool operator!=(const Train_running_number_Core& a, const Train_running_number_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Train_running_number_Core Train_running_number_Core;

#define TRAIN_RUNNING_NUMBER_CORE_BITSIZE 4603

/*@
    logic integer BitSize{L}(Train_running_number_Core* p) = TRAIN_RUNNING_NUMBER_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Train_running_number_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Train_running_number_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Train_running_number_Core* p) = \true;

    predicate ZeroInitialized(Train_running_number_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Train_running_number_Core* p) = \true;

    predicate UpperBitsNotSet(Train_running_number_Core* p) = \true;

*/

#endif // TRAIN_RUNNING_NUMBER_CORE_H_INCLUDED

