
#ifndef TRAIN_RUNNING_NUMBER_FROM_RBC_CORE_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_FROM_RBC_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Train_running_number_from_RBC_Core
{
    // TransmissionMedia=RBC
    // Train running number from RBC      
    // Packet Number = 140

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  NID_OPERATIONAL;  // # 32
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Train_running_number_from_RBC_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.NID_OPERATIONAL;

    return stream;
}

inline bool operator==(const Train_running_number_from_RBC_Core& a, const Train_running_number_from_RBC_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NID_OPERATIONAL == b.NID_OPERATIONAL);

    return status;
}

inline bool operator!=(const Train_running_number_from_RBC_Core& a, const Train_running_number_from_RBC_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Train_running_number_from_RBC_Core Train_running_number_from_RBC_Core;

#define TRAIN_RUNNING_NUMBER_FROM_RBC_CORE_BITSIZE 47

/*@
    logic integer BitSize{L}(Train_running_number_from_RBC_Core* p) = TRAIN_RUNNING_NUMBER_FROM_RBC_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Train_running_number_from_RBC_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Train_running_number_from_RBC_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Train_running_number_from_RBC_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_OPERATIONAL);

    predicate ZeroInitialized(Train_running_number_from_RBC_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_OPERATIONAL);

    predicate EqualBits(Bitstream* stream, integer pos, Train_running_number_from_RBC_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 47,  p->NID_OPERATIONAL);

    predicate UpperBitsNotSet(Train_running_number_from_RBC_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_OPERATIONAL,  32);

*/

#endif // TRAIN_RUNNING_NUMBER_FROM_RBC_CORE_H_INCLUDED

