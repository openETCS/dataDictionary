
#ifndef ERROR_REPORTING_H_INCLUDED
#define ERROR_REPORTING_H_INCLUDED

#include "Bitstream.h"

struct Error_Reporting
{
    // TransmissionMedia=RBC
    // Error reporting to the RBC      
    // Packet Number = 4

    uint16_t  L_PACKET;         // # 13
    uint32_t  M_ERROR;          // # 8
};

typedef struct Error_Reporting Error_Reporting;

#define ERROR_REPORTING_BITSIZE 21

/*@
    logic integer BitSize{L}(Error_Reporting* p) = ERROR_REPORTING_BITSIZE;

    logic integer MaxBitSize{L}(Error_Reporting* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Error_Reporting* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Error_Reporting* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->M_ERROR);

    predicate ZeroInitialized(Error_Reporting* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->M_ERROR);

    predicate EqualBits(Bitstream* stream, integer pos, Error_Reporting* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 21,  p->M_ERROR);


    predicate UpperBitsNotSet(Error_Reporting* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->M_ERROR,          8);

*/

#endif // ERROR_REPORTING_H_INCLUDED

