
#ifndef POSITION_REPORT_PARAMETERS_CORE_1_CORE_H_INCLUDED
#define POSITION_REPORT_PARAMETERS_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Position_Report_Parameters_Core_1
{

    uint16_t  D_LOC_k;          // # 15
    uint8_t   Q_LGTLOC_k;       // # 1
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Position_Report_Parameters_Core_1& p)
{
    stream 
       << +p.D_LOC_k << ','
       << +p.Q_LGTLOC_k;

    return stream;
}

inline bool operator==(const Position_Report_Parameters_Core_1& a, const Position_Report_Parameters_Core_1& b)
{
    bool status = true;
    
    status = status && (a.D_LOC_k == b.D_LOC_k);
    status = status && (a.Q_LGTLOC_k == b.Q_LGTLOC_k);

    return status;
}

inline bool operator!=(const Position_Report_Parameters_Core_1& a, const Position_Report_Parameters_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Position_Report_Parameters_Core_1 Position_Report_Parameters_Core_1;

#define POSITION_REPORT_PARAMETERS_CORE_1_CORE_BITSIZE 2172

/*@
    logic integer BitSize{L}(Position_Report_Parameters_Core_1* p) = POSITION_REPORT_PARAMETERS_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Position_Report_Parameters_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Position_Report_Parameters_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Position_Report_Parameters_Core_1* p) = \true;

    predicate ZeroInitialized(Position_Report_Parameters_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Position_Report_Parameters_Core_1* p) = \true;

    predicate UpperBitsNotSet(Position_Report_Parameters_Core_1* p) = \true;

*/

#endif // POSITION_REPORT_PARAMETERS_CORE_1_CORE_H_INCLUDED

