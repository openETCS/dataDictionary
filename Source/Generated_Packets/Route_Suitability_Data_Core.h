
#ifndef ROUTE_SUITABILITY_DATA_CORE_H_INCLUDED
#define ROUTE_SUITABILITY_DATA_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Route_Suitability_Data_Core_1.h"

struct Route_Suitability_Data_Core
{
    // TransmissionMedia=Any
    // The packet gives the characteristics needed to enter a route. 
    // Packet Number = 70

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint32_t  Q_TRACKINIT;      // # 1
    uint16_t  D_TRACKINIT;      // # 15
    uint16_t  D_SUITABILITY;    // # 15
    uint32_t  Q_SUITABILITY;    // # 2
    uint32_t  M_LINEGAUGE;      // # 8
    uint32_t  M_AXLELOADCAT;    // # 7
    uint32_t  M_VOLTAGE;        // # 4
    uint16_t  NID_CTRACTION;    // # 10
    uint8_t   N_ITER_1;         // # 5
    Route_Suitability_Data_Core_1   sub_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Route_Suitability_Data_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.Q_TRACKINIT << ','
       << +p.D_TRACKINIT << ','
       << +p.D_SUITABILITY << ','
       << +p.Q_SUITABILITY << ','
       << +p.M_LINEGAUGE << ','
       << +p.M_AXLELOADCAT << ','
       << +p.M_VOLTAGE << ','
       << +p.NID_CTRACTION << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Route_Suitability_Data_Core& a, const Route_Suitability_Data_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.Q_TRACKINIT == b.Q_TRACKINIT);
    if (a.Q_TRACKINIT == 1)
    {
    status = status && (a.D_TRACKINIT == b.D_TRACKINIT);
    }
    if (a.Q_TRACKINIT == 0)
    {
    status = status && (a.D_SUITABILITY == b.D_SUITABILITY);
    status = status && (a.Q_SUITABILITY == b.Q_SUITABILITY);
    if (a.Q_SUITABILITY == 0)
    {
    status = status && (a.M_LINEGAUGE == b.M_LINEGAUGE);
    }
    if (a.Q_SUITABILITY == 1)
    {
    status = status && (a.M_AXLELOADCAT == b.M_AXLELOADCAT);
    }
    if (a.Q_SUITABILITY == 2)
    {
    status = status && (a.M_VOLTAGE == b.M_VOLTAGE);
    }
    if ((a.Q_SUITABILITY == 2) && (a.M_VOLTAGE != 0))
    {
    status = status && (a.NID_CTRACTION == b.NID_CTRACTION);
    }
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
    }

    return status;
}

inline bool operator!=(const Route_Suitability_Data_Core& a, const Route_Suitability_Data_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Route_Suitability_Data_Core Route_Suitability_Data_Core;

#define ROUTE_SUITABILITY_DATA_CORE_BITSIZE 2746

/*@
    logic integer BitSize{L}(Route_Suitability_Data_Core* p) = ROUTE_SUITABILITY_DATA_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Route_Suitability_Data_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Route_Suitability_Data_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Route_Suitability_Data_Core* p) = \true;

    predicate ZeroInitialized(Route_Suitability_Data_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Route_Suitability_Data_Core* p) = \true;

    predicate UpperBitsNotSet(Route_Suitability_Data_Core* p) = \true;

*/

#endif // ROUTE_SUITABILITY_DATA_CORE_H_INCLUDED

