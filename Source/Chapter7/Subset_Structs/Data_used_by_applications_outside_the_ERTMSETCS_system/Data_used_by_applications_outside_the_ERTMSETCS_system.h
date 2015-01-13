
#ifndef DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_H_INCLUDED
#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_H_INCLUDED

#include "Bitstream.h"

struct Data_used_by_applications_outside_the_ERTMSETCS_system
{
    // TransmissionMedia=Any
    // Messages between trackside and on-board devices, which contain information used by applications outside the ERTMS/ETCS system.
    // Packet Number = 44

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_XUSER;        // # 9
    uint64_t  NID_NTC;          // # 8
    uint64_t  Other_data_depending_on__NID_XUSER;// # 
};

typedef struct Data_used_by_applications_outside_the_ERTMSETCS_system Data_used_by_applications_outside_the_ERTMSETCS_system;

#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_BITSIZE 40

/*@
    logic integer BitSize{L}(Data_used_by_applications_outside_the_ERTMSETCS_system* p) = DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_BITSIZE;

    logic integer MaxBitSize{L}(Data_used_by_applications_outside_the_ERTMSETCS_system* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Data_used_by_applications_outside_the_ERTMSETCS_system* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Data_used_by_applications_outside_the_ERTMSETCS_system* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_XUSER)         &&
      Invariant(p->NID_NTC)           &&
      Invariant(p->Other_data_depending_on__NID_XUSER);

    predicate ZeroInitialized(Data_used_by_applications_outside_the_ERTMSETCS_system* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_XUSER)         &&
      ZeroInitialized(p->NID_NTC)           &&
      ZeroInitialized(p->Other_data_depending_on__NID_XUSER);

    predicate EqualBits(Bitstream* stream, integer pos, Data_used_by_applications_outside_the_ERTMSETCS_system* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 32,  p->NID_XUSER)         &&
      EqualBits(stream, pos + 32,  pos + 40,  p->NID_NTC)           &&
      EqualBits(stream, pos + 40,  pos + 40,  p->Other_data_depending_on__NID_XUSER);


    predicate UpperBitsNotSet(Data_used_by_applications_outside_the_ERTMSETCS_system* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_XUSER,        9)   &&
      UpperBitsNotSet(p->NID_NTC,          8)   &&
      UpperBitsNotSet(p->Other_data_depending_on__NID_XUSER,);

*/

#endif // DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_H_INCLUDED

