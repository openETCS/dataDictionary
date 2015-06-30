
#ifndef ROUTE_SUITABILITY_DATA_CORE_1_CORE_H_INCLUDED
#define ROUTE_SUITABILITY_DATA_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Route_Suitability_Data_Core_1
{

    uint16_t  D_SUITABILITY_k;  // # 15
    uint8_t   Q_SUITABILITY_k;  // # 2
    uint8_t   M_LINEGAUGE_k;    // # 8
    uint8_t   M_AXLELOADCAT_k;  // # 7
    uint8_t   M_VOLTAGE_k;      // # 4
    uint16_t  NID_CTRACTION_k;  // # 10
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Route_Suitability_Data_Core_1& p)
{
    stream 
       << +p.D_SUITABILITY_k << ','
       << +p.Q_SUITABILITY_k << ','
       << +p.M_LINEGAUGE_k << ','
       << +p.M_AXLELOADCAT_k << ','
       << +p.M_VOLTAGE_k << ','
       << +p.NID_CTRACTION_k;

    return stream;
}

inline bool operator==(const Route_Suitability_Data_Core_1& a, const Route_Suitability_Data_Core_1& b)
{
    bool status = true;
    
    status = status && (a.D_SUITABILITY_k == b.D_SUITABILITY_k);
    status = status && (a.Q_SUITABILITY_k == b.Q_SUITABILITY_k);
    if (a.Q_SUITABILITY_k == 0)
    {
    status = status && (a.M_LINEGAUGE_k == b.M_LINEGAUGE_k);
    }
    if (a.Q_SUITABILITY_k == 1)
    {
    status = status && (a.M_AXLELOADCAT_k == b.M_AXLELOADCAT_k);
    }
    if (a.Q_SUITABILITY_k == 2)
    {
    status = status && (a.M_VOLTAGE_k == b.M_VOLTAGE_k);
    }
    if ((a.Q_SUITABILITY_k == 2) && (a.M_VOLTAGE_k != 0))
    {
    status = status && (a.NID_CTRACTION_k == b.NID_CTRACTION_k);
    }

    return status;
}

inline bool operator!=(const Route_Suitability_Data_Core_1& a, const Route_Suitability_Data_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Route_Suitability_Data_Core_1 Route_Suitability_Data_Core_1;

#define ROUTE_SUITABILITY_DATA_CORE_1_CORE_BITSIZE 2746

/*@
    logic integer BitSize{L}(Route_Suitability_Data_Core_1* p) = ROUTE_SUITABILITY_DATA_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Route_Suitability_Data_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Route_Suitability_Data_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Route_Suitability_Data_Core_1* p) = \true;

    predicate ZeroInitialized(Route_Suitability_Data_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Route_Suitability_Data_Core_1* p) = \true;

    predicate UpperBitsNotSet(Route_Suitability_Data_Core_1* p) = \true;

*/

#endif // ROUTE_SUITABILITY_DATA_CORE_1_CORE_H_INCLUDED

