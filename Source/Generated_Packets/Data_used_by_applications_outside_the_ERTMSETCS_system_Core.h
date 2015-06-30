
#ifndef DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_H_INCLUDED
#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Data_used_by_applications_outside_the_ERTMSETCS_system_Core
{
    // TransmissionMedia=Any
    // Messages between trackside and on-board devices, which contain information used by
    // applications outside the ERTMS/ETCS system.      
    // Packet Number = 44

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint16_t  NID_XUSER;        // # 9
    uint8_t   NID_NTC;          // # 8
    uint8_t   Other_data_depending_on__NID_XUSER;// # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.NID_XUSER << ','
       << +p.NID_NTC << ','
       << +p.Other_data_depending_on__NID_XUSER;

    return stream;
}

inline bool operator==(const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& a, const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NID_XUSER == b.NID_XUSER);
    if (a.NID_XUSER == 102)
    {
    status = status && (a.NID_NTC == b.NID_NTC);
    }
    status = status && (a.Other_data_depending_on__NID_XUSER == b.Other_data_depending_on__NID_XUSER);

    return status;
}

inline bool operator!=(const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& a, const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Data_used_by_applications_outside_the_ERTMSETCS_system_Core Data_used_by_applications_outside_the_ERTMSETCS_system_Core;

#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_BITSIZE 1655

/*@
    logic integer BitSize{L}(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = \true;

    predicate ZeroInitialized(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = \true;

    predicate UpperBitsNotSet(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = \true;

*/

#endif // DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_H_INCLUDED

