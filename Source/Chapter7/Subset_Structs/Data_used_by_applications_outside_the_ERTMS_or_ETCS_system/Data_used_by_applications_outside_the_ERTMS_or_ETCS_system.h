
#ifndef DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_H_INCLUDED
#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_H_INCLUDED

#include "Bitstream.h"

struct Data_used_by_applications_outside_the_ERTMS_or_ETCS_system
{
    // TransmissionMedia=RBC, RIU
    // Messages between on-board and trackside devices, which contain information used by applications outside the ERTMS or ETCS system.
    // Packet Number = 44

    uint64_t  NID_PACKET;       // # 8
    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_XUSER;        // # 9
    uint64_t  Other_data_depending_on__NID_XUSER;// # 
};

typedef struct Data_used_by_applications_outside_the_ERTMS_or_ETCS_system Data_used_by_applications_outside_the_ERTMS_or_ETCS_system;

#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_BITSIZE 30

/*@
    logic integer BitSize{L}(Data_used_by_applications_outside_the_ERTMS_or_ETCS_system* p) = DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_BITSIZE;

    logic integer MaxBitSize{L}(Data_used_by_applications_outside_the_ERTMS_or_ETCS_system* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Data_used_by_applications_outside_the_ERTMS_or_ETCS_system* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Data_used_by_applications_outside_the_ERTMS_or_ETCS_system* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_XUSER)         &&
      Invariant(p->Other_data_depending_on__NID_XUSER);

    predicate ZeroInitialized(Data_used_by_applications_outside_the_ERTMS_or_ETCS_system* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_XUSER)         &&
      ZeroInitialized(p->Other_data_depending_on__NID_XUSER);

    predicate EqualBits(Bitstream* stream, integer pos, Data_used_by_applications_outside_the_ERTMS_or_ETCS_system* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 21,  p->L_PACKET)          &&
      EqualBits(stream, pos + 21,  pos + 30,  p->NID_XUSER)         &&
      EqualBits(stream, pos + 30,  pos + 30,  p->Other_data_depending_on__NID_XUSER);


    predicate UpperBitsNotSet(Data_used_by_applications_outside_the_ERTMS_or_ETCS_system* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_XUSER,        9)   &&
      UpperBitsNotSet(p->Other_data_depending_on__NID_XUSER,);

*/

#endif // DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_H_INCLUDED

