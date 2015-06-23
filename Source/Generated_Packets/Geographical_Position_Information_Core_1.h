
#ifndef GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_H_INCLUDED
#define GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Geographical_Position_Information_Core_1
{

    uint8_t   Q_NEWCOUNTRY_k;   // # 1
    uint16_t  NID_C_k;          // # 10
    uint16_t  NID_BG_k;         // # 14
    uint16_t  D_POSOFF_k;       // # 15
    uint8_t   Q_MPOSITION_k;    // # 1
    uint32_t  M_POSITION_k;     // # 24
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Geographical_Position_Information_Core_1& p)
{
    stream 
       << +p.Q_NEWCOUNTRY_k << ','
       << +p.NID_C_k << ','
       << +p.NID_BG_k << ','
       << +p.D_POSOFF_k << ','
       << +p.Q_MPOSITION_k << ','
       << +p.M_POSITION_k;

    return stream;
}

inline bool operator==(const Geographical_Position_Information_Core_1& a, const Geographical_Position_Information_Core_1& b)
{
    bool status = true;
    
    status = status && (a.Q_NEWCOUNTRY_k == b.Q_NEWCOUNTRY_k);
    if (a.Q_NEWCOUNTRY_k == 1)
    {
    status = status && (a.NID_C_k == b.NID_C_k);
    }
    status = status && (a.NID_BG_k == b.NID_BG_k);
    status = status && (a.D_POSOFF_k == b.D_POSOFF_k);
    status = status && (a.Q_MPOSITION_k == b.Q_MPOSITION_k);
    status = status && (a.M_POSITION_k == b.M_POSITION_k);

    return status;
}

inline bool operator!=(const Geographical_Position_Information_Core_1& a, const Geographical_Position_Information_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Geographical_Position_Information_Core_1 Geographical_Position_Information_Core_1;

#define GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_BITSIZE 152

/*@
    logic integer BitSize{L}(Geographical_Position_Information_Core_1* p) = GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Geographical_Position_Information_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Geographical_Position_Information_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Geographical_Position_Information_Core_1* p) = \true;

    predicate ZeroInitialized(Geographical_Position_Information_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Geographical_Position_Information_Core_1* p) =
      EqualBits(stream, pos + 87,  pos + 88,  p->Q_NEWCOUNTRY_k)    &&
      EqualBits(stream, pos + 98,  pos + 112, p->NID_BG_k)          &&
      EqualBits(stream, pos + 112, pos + 127, p->D_POSOFF_k)        &&
      EqualBits(stream, pos + 127, pos + 128, p->Q_MPOSITION_k)     &&
      EqualBits(stream, pos + 128, pos + 152, p->M_POSITION_k);

    predicate UpperBitsNotSet(Geographical_Position_Information_Core_1* p) =
      UpperBitsNotSet(p->Q_NEWCOUNTRY_k,   1)   &&
      UpperBitsNotSet(p->NID_BG_k,         14)  &&
      UpperBitsNotSet(p->D_POSOFF_k,       15)  &&
      UpperBitsNotSet(p->Q_MPOSITION_k,    1)   &&
      UpperBitsNotSet(p->M_POSITION_k,     24);

*/

#endif // GEOGRAPHICAL_POSITION_INFORMATION_CORE_1_CORE_H_INCLUDED

