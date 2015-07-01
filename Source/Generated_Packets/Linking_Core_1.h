
#ifndef LINKING_CORE_1_CORE_H_INCLUDED
#define LINKING_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Linking_Core_1
{

    uint16_t  D_LINK_k;         // # 15
    uint8_t   Q_NEWCOUNTRY_k;   // # 1
    uint16_t  NID_C_k;          // # 10
    uint16_t  NID_BG_k;         // # 14
    uint8_t   Q_LINKORIENTATION_k;// # 1
    uint8_t   Q_LINKREACTION_k; // # 2
    uint8_t   Q_LOCACC_k;       // # 6
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Linking_Core_1& p)
{
    stream 
       << +p.D_LINK_k << ','
       << +p.Q_NEWCOUNTRY_k << ','
       << +p.NID_C_k << ','
       << +p.NID_BG_k << ','
       << +p.Q_LINKORIENTATION_k << ','
       << +p.Q_LINKREACTION_k << ','
       << +p.Q_LOCACC_k;

    return stream;
}

inline bool operator==(const Linking_Core_1& a, const Linking_Core_1& b)
{
    bool status = true;
    
    status = status && (a.D_LINK_k == b.D_LINK_k);
    status = status && (a.Q_NEWCOUNTRY_k == b.Q_NEWCOUNTRY_k);
    if (a.Q_NEWCOUNTRY_k == 1)
    {
    status = status && (a.NID_C_k == b.NID_C_k);
    }
    status = status && (a.NID_BG_k == b.NID_BG_k);
    status = status && (a.Q_LINKORIENTATION_k == b.Q_LINKORIENTATION_k);
    status = status && (a.Q_LINKREACTION_k == b.Q_LINKREACTION_k);
    status = status && (a.Q_LOCACC_k == b.Q_LOCACC_k);

    return status;
}

inline bool operator!=(const Linking_Core_1& a, const Linking_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Linking_Core_1 Linking_Core_1;

#define LINKING_CORE_1_CORE_BITSIZE 120

/*@
    logic integer BitSize{L}(Linking_Core_1* p) = LINKING_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Linking_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Linking_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Linking_Core_1* p) = \true;

    predicate ZeroInitialized(Linking_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Linking_Core_1* p) =
      EqualBits(stream, pos + 71,  pos + 86,  p->D_LINK_k)          &&
      EqualBits(stream, pos + 86,  pos + 87,  p->Q_NEWCOUNTRY_k)    &&
      EqualBits(stream, pos + 97,  pos + 111, p->NID_BG_k)          &&
      EqualBits(stream, pos + 111, pos + 112, p->Q_LINKORIENTATION_k) &&
      EqualBits(stream, pos + 112, pos + 114, p->Q_LINKREACTION_k)  &&
      EqualBits(stream, pos + 114, pos + 120, p->Q_LOCACC_k);

    predicate UpperBitsNotSet(Linking_Core_1* p) =
      UpperBitsNotSet(p->D_LINK_k,         15)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY_k,   1)   &&
      UpperBitsNotSet(p->NID_BG_k,         14)  &&
      UpperBitsNotSet(p->Q_LINKORIENTATION_k,1)   &&
      UpperBitsNotSet(p->Q_LINKREACTION_k, 2)   &&
      UpperBitsNotSet(p->Q_LOCACC_k,       6);

*/

#endif // LINKING_CORE_1_CORE_H_INCLUDED

