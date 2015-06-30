
#ifndef VALIDATED_TRAIN_DATA_CORE_H_INCLUDED
#define VALIDATED_TRAIN_DATA_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Validated_train_data_Core_1.h"
#include "Validated_train_data_Core_2.h"

struct Validated_train_data_Core
{
    // TransmissionMedia=RBC
    // Validated train data.        
    // Packet Number = 11

    uint16_t  L_PACKET;         // # 13
    uint32_t  NC_CDTRAIN;       // # 4
    uint32_t  NC_TRAIN;         // # 15
    uint16_t  L_TRAIN;          // # 12
    uint8_t   V_MAXTRAIN;       // # 7
    uint32_t  M_LOADINGGAUGE;   // # 8
    uint32_t  M_AXLELOADCAT;    // # 7
    uint32_t  M_AIRTIGHT;       // # 2
    uint16_t  N_AXLE;           // # 10
    uint8_t   N_ITER_1;         // # 5
    Validated_train_data_Core_1   sub_1[31];
    uint8_t   N_ITER_2;         // # 5
    Validated_train_data_Core_2   sub_2[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Validated_train_data_Core& p)
{
    stream 
       << +p.L_PACKET << ','
       << +p.NC_CDTRAIN << ','
       << +p.NC_TRAIN << ','
       << +p.L_TRAIN << ','
       << +p.V_MAXTRAIN << ','
       << +p.M_LOADINGGAUGE << ','
       << +p.M_AXLELOADCAT << ','
       << +p.M_AIRTIGHT << ','
       << +p.N_AXLE << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
    stream << ','
       << +p.N_ITER_2;
       for (uint32_t i = 0; i < p.N_ITER_2; ++i)
       {
           stream << ',' << p.sub_2[i];
       }
   

    return stream;
}

inline bool operator==(const Validated_train_data_Core& a, const Validated_train_data_Core& b)
{
    bool status = true;
    
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NC_CDTRAIN == b.NC_CDTRAIN);
    status = status && (a.NC_TRAIN == b.NC_TRAIN);
    status = status && (a.L_TRAIN == b.L_TRAIN);
    status = status && (a.V_MAXTRAIN == b.V_MAXTRAIN);
    status = status && (a.M_LOADINGGAUGE == b.M_LOADINGGAUGE);
    status = status && (a.M_AXLELOADCAT == b.M_AXLELOADCAT);
    status = status && (a.M_AIRTIGHT == b.M_AIRTIGHT);
    status = status && (a.N_AXLE == b.N_AXLE);
    status = status && (a.N_ITER_1 == b.N_ITER_1);
    if (a.N_ITER_1 == b.N_ITER_1)
    {
        for (uint32_t i = 0; i < a.N_ITER_1; ++i)
        {
            status = status && (a.sub_1[i] == b.sub_1[i]);
        }
    }
    else
    {
        status = false;
    }
    status = status && (a.N_ITER_2 == b.N_ITER_2);
    if (a.N_ITER_2 == b.N_ITER_2)
    {
        for (uint32_t i = 0; i < a.N_ITER_2; ++i)
        {
            status = status && (a.sub_2[i] == b.sub_2[i]);
        }
    }
    else
    {
        status = false;
    }

    return status;
}

inline bool operator!=(const Validated_train_data_Core& a, const Validated_train_data_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Validated_train_data_Core Validated_train_data_Core;

#define VALIDATED_TRAIN_DATA_CORE_BITSIZE 4750

/*@
    logic integer BitSize{L}(Validated_train_data_Core* p) = VALIDATED_TRAIN_DATA_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Validated_train_data_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Validated_train_data_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Validated_train_data_Core* p) = \true;

    predicate ZeroInitialized(Validated_train_data_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Validated_train_data_Core* p) = \true;

    predicate UpperBitsNotSet(Validated_train_data_Core* p) = \true;

*/

#endif // VALIDATED_TRAIN_DATA_CORE_H_INCLUDED

