
#ifndef STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_H_INCLUDED
#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Staff_Responsible_distance_Information_from_loop_Core_1
{

    uint8_t   Q_NEWCOUNTRY_k;   // # 1
    uint16_t  NID_C_k;          // # 10
    uint16_t  NID_BG_k;         // # 14
    uint16_t  D_SR_k;           // # 15
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Staff_Responsible_distance_Information_from_loop_Core_1& p)
{
    stream 
       << +p.Q_NEWCOUNTRY_k << ','
       << +p.NID_C_k << ','
       << +p.NID_BG_k << ','
       << +p.D_SR_k;

    return stream;
}

inline bool operator==(const Staff_Responsible_distance_Information_from_loop_Core_1& a, const Staff_Responsible_distance_Information_from_loop_Core_1& b)
{
    bool status = true;
    
    status = status && (a.Q_NEWCOUNTRY_k == b.Q_NEWCOUNTRY_k);
    if (a.Q_NEWCOUNTRY_k == 1)
    {
    status = status && (a.NID_C_k == b.NID_C_k);
    }
    status = status && (a.NID_BG_k == b.NID_BG_k);
    status = status && (a.D_SR_k == b.D_SR_k);

    return status;
}

inline bool operator!=(const Staff_Responsible_distance_Information_from_loop_Core_1& a, const Staff_Responsible_distance_Information_from_loop_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Staff_Responsible_distance_Information_from_loop_Core_1 Staff_Responsible_distance_Information_from_loop_Core_1;

#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_BITSIZE 127

/*@
    logic integer BitSize{L}(Staff_Responsible_distance_Information_from_loop_Core_1* p) = STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Staff_Responsible_distance_Information_from_loop_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Staff_Responsible_distance_Information_from_loop_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Staff_Responsible_distance_Information_from_loop_Core_1* p) = \true;

    predicate ZeroInitialized(Staff_Responsible_distance_Information_from_loop_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Staff_Responsible_distance_Information_from_loop_Core_1* p) =
      EqualBits(stream, pos + 87,  pos + 88,  p->Q_NEWCOUNTRY_k)    &&
      EqualBits(stream, pos + 98,  pos + 112, p->NID_BG_k)          &&
      EqualBits(stream, pos + 112, pos + 127, p->D_SR_k);

    predicate UpperBitsNotSet(Staff_Responsible_distance_Information_from_loop_Core_1* p) =
      UpperBitsNotSet(p->Q_NEWCOUNTRY_k,   1)   &&
      UpperBitsNotSet(p->NID_BG_k,         14)  &&
      UpperBitsNotSet(p->D_SR_k,           15);

*/

#endif // STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_CORE_1_CORE_H_INCLUDED

