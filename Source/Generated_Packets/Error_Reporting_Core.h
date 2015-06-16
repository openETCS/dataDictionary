
#ifndef ERROR_REPORTING_CORE_H_INCLUDED
#define ERROR_REPORTING_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Error_Reporting_Core
{
    // TransmissionMedia=RBC
    // Error reporting to the RBC      
    // Packet Number = 4

    uint16_t  L_PACKET;         // # 13
    uint32_t  M_ERROR;          // # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Error_Reporting_Core& p)
{
    stream 
       << +p.L_PACKET << ','
       << +p.M_ERROR;

    return stream;
}

inline bool operator==(const Error_Reporting_Core& a, const Error_Reporting_Core& b)
{
    bool status = true;
    
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.M_ERROR == b.M_ERROR);

    return status;
}

inline bool operator!=(const Error_Reporting_Core& a, const Error_Reporting_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Error_Reporting_Core Error_Reporting_Core;

#define ERROR_REPORTING_CORE_BITSIZE 21

/*@
    logic integer BitSize{L}(Error_Reporting_Core* p) = ERROR_REPORTING_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Error_Reporting_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Error_Reporting_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Error_Reporting_Core* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->M_ERROR);

    predicate ZeroInitialized(Error_Reporting_Core* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->M_ERROR);

    predicate EqualBits(Bitstream* stream, integer pos, Error_Reporting_Core* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);

    predicate UpperBitsNotSet(Error_Reporting_Core* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->M_ERROR,          8);

*/

#endif // ERROR_REPORTING_CORE_H_INCLUDED

