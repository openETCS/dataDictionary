
#ifndef POSITION_REPORT_PARAMETERS_CORE_H_INCLUDED
#define POSITION_REPORT_PARAMETERS_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Position_Report_Parameters_Core_1.h"

struct Position_Report_Parameters_Core
{
    // TransmissionMedia=RBC
    // This packet is intended to give parameters telling when and how
    // often the position has to be reported.    
    // Packet Number = 58

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint8_t   T_CYCLOC;         // # 8
    uint16_t  D_CYCLOC;         // # 15
    uint32_t  M_LOC;            // # 3
    uint8_t   N_ITER_1;         // # 5
    Position_Report_Parameters_Core_1   sub_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Position_Report_Parameters_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.T_CYCLOC << ','
       << +p.D_CYCLOC << ','
       << +p.M_LOC << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Position_Report_Parameters_Core& a, const Position_Report_Parameters_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.T_CYCLOC == b.T_CYCLOC);
    status = status && (a.D_CYCLOC == b.D_CYCLOC);
    status = status && (a.M_LOC == b.M_LOC);
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

inline bool operator!=(const Position_Report_Parameters_Core& a, const Position_Report_Parameters_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Position_Report_Parameters_Core Position_Report_Parameters_Core;

#define POSITION_REPORT_PARAMETERS_CORE_BITSIZE 2172

/*@
    logic integer BitSize{L}(Position_Report_Parameters_Core* p) = POSITION_REPORT_PARAMETERS_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Position_Report_Parameters_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Position_Report_Parameters_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Position_Report_Parameters_Core* p) = \true;

    predicate ZeroInitialized(Position_Report_Parameters_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Position_Report_Parameters_Core* p) = \true;

    predicate UpperBitsNotSet(Position_Report_Parameters_Core* p) = \true;

*/

#endif // POSITION_REPORT_PARAMETERS_CORE_H_INCLUDED

