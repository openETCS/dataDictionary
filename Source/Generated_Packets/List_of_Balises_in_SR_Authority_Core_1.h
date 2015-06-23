
#ifndef LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_1_CORE_H_INCLUDED
#define LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct List_of_Balises_in_SR_Authority_Core_1
{

    uint8_t   Q_NEWCOUNTRY_k;   // # 1
    uint16_t  NID_C_k;          // # 10
    uint16_t  NID_BG_k;         // # 14
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const List_of_Balises_in_SR_Authority_Core_1& p)
{
    stream 
       << +p.Q_NEWCOUNTRY_k << ','
       << +p.NID_C_k << ','
       << +p.NID_BG_k;

    return stream;
}

inline bool operator==(const List_of_Balises_in_SR_Authority_Core_1& a, const List_of_Balises_in_SR_Authority_Core_1& b)
{
    bool status = true;
    
    status = status && (a.Q_NEWCOUNTRY_k == b.Q_NEWCOUNTRY_k);
    if (a.Q_NEWCOUNTRY_k == 1)
    {
    status = status && (a.NID_C_k == b.NID_C_k);
    }
    status = status && (a.NID_BG_k == b.NID_BG_k);

    return status;
}

inline bool operator!=(const List_of_Balises_in_SR_Authority_Core_1& a, const List_of_Balises_in_SR_Authority_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct List_of_Balises_in_SR_Authority_Core_1 List_of_Balises_in_SR_Authority_Core_1;

#define LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_1_CORE_BITSIZE 45

/*@
    logic integer BitSize{L}(List_of_Balises_in_SR_Authority_Core_1* p) = LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(List_of_Balises_in_SR_Authority_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, List_of_Balises_in_SR_Authority_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(List_of_Balises_in_SR_Authority_Core_1* p) = \true;

    predicate ZeroInitialized(List_of_Balises_in_SR_Authority_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, List_of_Balises_in_SR_Authority_Core_1* p) =
      EqualBits(stream, pos + 20,  pos + 21,  p->Q_NEWCOUNTRY_k)    &&
      EqualBits(stream, pos + 31,  pos + 45,  p->NID_BG_k);

    predicate UpperBitsNotSet(List_of_Balises_in_SR_Authority_Core_1* p) =
      UpperBitsNotSet(p->Q_NEWCOUNTRY_k,   1)   &&
      UpperBitsNotSet(p->NID_BG_k,         14);

*/

#endif // LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_1_CORE_H_INCLUDED

