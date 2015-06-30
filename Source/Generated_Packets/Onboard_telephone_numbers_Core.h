
#ifndef ONBOARD_TELEPHONE_NUMBERS_CORE_H_INCLUDED
#define ONBOARD_TELEPHONE_NUMBERS_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Onboard_telephone_numbers_Core_1.h"

struct Onboard_telephone_numbers_Core
{
    // TransmissionMedia=RBC, RIU
    // Telephone numbers associated to the onboard equipment    
    // Packet Number = 3

    uint16_t  L_PACKET;         // # 13
    uint8_t   N_ITER_1;         // # 5
    Onboard_telephone_numbers_Core_1   sub_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Onboard_telephone_numbers_Core& p)
{
    stream 
       << +p.L_PACKET << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Onboard_telephone_numbers_Core& a, const Onboard_telephone_numbers_Core& b)
{
    bool status = true;
    
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

inline bool operator!=(const Onboard_telephone_numbers_Core& a, const Onboard_telephone_numbers_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Onboard_telephone_numbers_Core Onboard_telephone_numbers_Core;

#define ONBOARD_TELEPHONE_NUMBERS_CORE_BITSIZE 4537

/*@
    logic integer BitSize{L}(Onboard_telephone_numbers_Core* p) = ONBOARD_TELEPHONE_NUMBERS_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Onboard_telephone_numbers_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Onboard_telephone_numbers_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Onboard_telephone_numbers_Core* p) = \true;

    predicate ZeroInitialized(Onboard_telephone_numbers_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Onboard_telephone_numbers_Core* p) = \true;

    predicate UpperBitsNotSet(Onboard_telephone_numbers_Core* p) = \true;

*/

#endif // ONBOARD_TELEPHONE_NUMBERS_CORE_H_INCLUDED

