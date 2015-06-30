
#ifndef STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_H_INCLUDED
#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Staff_Responsible_distance_Information_from_loop_Core_1.h"

struct Staff_Responsible_distance_Information_from_loop_Core
{
    // TransmissionMedia=Loop
    // Information for trains in staff responsible mode    
    // Packet Number = 13

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint8_t   Q_NEWCOUNTRY_0;   // # 1
    uint16_t  NID_C_0;          // # 10
    uint16_t  NID_BG_0;         // # 14
    uint8_t   Q_NEWCOUNTRY_1;   // # 1
    uint16_t  NID_C_1;          // # 10
    uint16_t  NID_BG_1;         // # 14
    uint16_t  D_SR;             // # 15
    uint8_t   N_ITER_1;         // # 5
    Staff_Responsible_distance_Information_from_loop_Core_1   sub_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Staff_Responsible_distance_Information_from_loop_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.Q_NEWCOUNTRY_0 << ','
       << +p.NID_C_0 << ','
       << +p.NID_BG_0 << ','
       << +p.Q_NEWCOUNTRY_1 << ','
       << +p.NID_C_1 << ','
       << +p.NID_BG_1 << ','
       << +p.D_SR << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Staff_Responsible_distance_Information_from_loop_Core& a, const Staff_Responsible_distance_Information_from_loop_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.Q_NEWCOUNTRY_0 == b.Q_NEWCOUNTRY_0);
    if (a.Q_NEWCOUNTRY_0 == 1)
    {
    status = status && (a.NID_C_0 == b.NID_C_0);
    }
    status = status && (a.NID_BG_0 == b.NID_BG_0);
    status = status && (a.Q_NEWCOUNTRY_1 == b.Q_NEWCOUNTRY_1);
    if (a.Q_NEWCOUNTRY_1 == 1)
    {
    status = status && (a.NID_C_1 == b.NID_C_1);
    }
    status = status && (a.NID_BG_1 == b.NID_BG_1);
    status = status && (a.D_SR == b.D_SR);
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

    return status;
}

inline bool operator!=(const Staff_Responsible_distance_Information_from_loop_Core& a, const Staff_Responsible_distance_Information_from_loop_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Staff_Responsible_distance_Information_from_loop_Core Staff_Responsible_distance_Information_from_loop_Core;

#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_BITSIZE 901

/*@
    logic integer BitSize{L}(Staff_Responsible_distance_Information_from_loop_Core* p) = STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Staff_Responsible_distance_Information_from_loop_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Staff_Responsible_distance_Information_from_loop_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Staff_Responsible_distance_Information_from_loop_Core* p) = \true;

    predicate ZeroInitialized(Staff_Responsible_distance_Information_from_loop_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Staff_Responsible_distance_Information_from_loop_Core* p) = \true;

    predicate UpperBitsNotSet(Staff_Responsible_distance_Information_from_loop_Core* p) = \true;

*/

#endif // STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_H_INCLUDED

