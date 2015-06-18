
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
       << +p.Other_data_depending_on__NID_XUSER;

    return stream;
}

inline bool operator==(const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& a, const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NID_XUSER == b.NID_XUSER);
    status = status && (a.Other_data_depending_on__NID_XUSER == b.Other_data_depending_on__NID_XUSER);

    return status;
}

inline bool operator!=(const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& a, const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Data_used_by_applications_outside_the_ERTMSETCS_system_Core Data_used_by_applications_outside_the_ERTMSETCS_system_Core;

#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_BITSIZE 40

/*@
    logic integer BitSize{L}(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_XUSER)         &&
      Invariant(p->Other_data_depending_on__NID_XUSER);

    predicate ZeroInitialized(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_XUSER)         &&
      ZeroInitialized(p->Other_data_depending_on__NID_XUSER);

    predicate EqualBits(Bitstream* stream, integer pos, Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 24,  p->NID_XUSER)         &&
      EqualBits(stream, pos + 32,  pos + 40,  p->Other_data_depending_on__NID_XUSER);

    predicate UpperBitsNotSet(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_XUSER,        9)   &&
      UpperBitsNotSet(p->Other_data_depending_on__NID_XUSER,8);

*/

#endif // DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_H_INCLUDED

