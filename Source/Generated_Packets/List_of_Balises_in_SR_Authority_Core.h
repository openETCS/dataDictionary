
#ifndef LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_H_INCLUDED
#define LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "List_of_Balises_in_SR_Authority_Core_1.h"

struct List_of_Balises_in_SR_Authority_Core
{
    // TransmissionMedia=RBC
    // Used to list balise group(s) which the train can pass over
    // in SR mode        
    // Packet Number = 63

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint8_t   N_ITER_1;         // # 5
    List_of_Balises_in_SR_Authority_Core_1   sub_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const List_of_Balises_in_SR_Authority_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const List_of_Balises_in_SR_Authority_Core& a, const List_of_Balises_in_SR_Authority_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
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

inline bool operator!=(const List_of_Balises_in_SR_Authority_Core& a, const List_of_Balises_in_SR_Authority_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct List_of_Balises_in_SR_Authority_Core List_of_Balises_in_SR_Authority_Core;

#define LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_BITSIZE 2217

/*@
    logic integer BitSize{L}(List_of_Balises_in_SR_Authority_Core* p) = LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_BITSIZE;

    logic integer MaxBitSize{L}(List_of_Balises_in_SR_Authority_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, List_of_Balises_in_SR_Authority_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(List_of_Balises_in_SR_Authority_Core* p) = \true;

    predicate ZeroInitialized(List_of_Balises_in_SR_Authority_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, List_of_Balises_in_SR_Authority_Core* p) = \true;

    predicate UpperBitsNotSet(List_of_Balises_in_SR_Authority_Core* p) = \true;

*/

#endif // LIST_OF_BALISES_IN_SR_AUTHORITY_CORE_H_INCLUDED

