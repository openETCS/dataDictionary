
#ifndef ERROR_REPORTING_DATA_H_INCLUDED
#define ERROR_REPORTING_DATA_H_INCLUDED

#include "Bitstream.h"

struct Error_Reporting_Data
{
    // TransmissionMedia=RBC
    // Error reporting to the RBC
    // Packet Number = 4

    uint32_t  M_ERROR;          // # 8
};

typedef struct Error_Reporting_Data Error_Reporting_Data;

#define ERROR_REPORTING_DATA_BITSIZE 8

/*@
    logic integer BitSize{L}(Error_Reporting_Data* p) = ERROR_REPORTING_DATA_BITSIZE;

    logic integer MaxBitSize{L}(Error_Reporting_Data* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Error_Reporting_Data* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Error_Reporting_Data* p) =
      Invariant(p->M_ERROR);

    predicate ZeroInitialized(Error_Reporting_Data* p) =
      ZeroInitialized(p->M_ERROR);

    predicate EqualBits(Bitstream* stream, integer pos, Error_Reporting_Data* p) =
      EqualBits(stream, pos,       pos + 8,   p->M_ERROR);


    predicate UpperBitsNotSet(Error_Reporting_Data* p) =
      UpperBitsNotSet(p->M_ERROR,          8);

*/

#endif // ERROR_REPORTING_DATA_H_INCLUDED

