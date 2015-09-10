
#ifndef DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_CORE_H_INCLUDED
#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_CORE_H_INCLUDED

#include "Bitstream.h"

struct Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core
{
    // TransmissionMedia=RBC, RIU
    // Messages between on-board and trackside devices, which contain information used by
    // applications outside the ERTMS or ETCS system.
    // Packet Number = 44

    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_XUSER;        // # 9
    uint64_t   Other_data_depending_on__NID_XUSER;// # 8
};

typedef struct Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core;

#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_CORE_BITSIZE 30

/*@
    logic integer BitSize{L}(Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p) = DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_XUSER)         &&
      Invariant(p->Other_data_depending_on__NID_XUSER);

    predicate ZeroInitialized(Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_XUSER)         &&
      ZeroInitialized(p->Other_data_depending_on__NID_XUSER);

    predicate EqualBits(Bitstream* stream, integer pos, Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 22,  p->NID_XUSER)         &&
      EqualBits(stream, pos + 22,  pos + 30,  p->Other_data_depending_on__NID_XUSER);

    predicate UpperBitsNotSet(Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_XUSER,        9)   &&
      UpperBitsNotSet(p->Other_data_depending_on__NID_XUSER,8);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_UpperBitsNotSet(const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p);

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid_read(p);
    requires invariant:         Invariant(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns stream->addr[0..(stream->size-1)];

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && UpperBitsNotSet{Pre}(p);

      assigns stream->bitpos;
      assigns stream->addr[0..(stream->size-1)];

      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures left:       Unchanged{Here,Old}(stream, 0, \old(stream->bitpos));
      ensures middle:     EqualBits(stream, \old(stream->bitpos), p);
      ensures right:      Unchanged{Here,Old}(stream, stream->bitpos, 8 * stream->size);

    behavior values_too_big:
      assumes Normal{Pre}(stream, MaxBitSize(p)) && !UpperBitsNotSet{Pre}(p);

      assigns \nothing;

      ensures result:        \result == -2;

    behavior invalid_bit_sequence:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result:       \result == -1;

    complete behaviors;
    disjoint behaviors;
*/
int Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Encoder(Bitstream* stream, const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p);

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          Unchanged{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures invariant:  Invariant(p);
      ensures result:     \result == 1;
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), p);
      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Decoder(Bitstream* stream, Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core& p)
{
    stream
            << +p.L_PACKET << ','
            << +p.NID_XUSER << ','
            << +p.Other_data_depending_on__NID_XUSER;

    return stream;
}

inline bool operator==(const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core& a, const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core& b)
{
    bool status = true;

    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NID_XUSER == b.NID_XUSER);
    status = status && (a.Other_data_depending_on__NID_XUSER == b.Other_data_depending_on__NID_XUSER);

    return status;
}

inline bool operator!=(const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core& a, const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Core& p)
{
    return Data_used_by_applications_outside_the_ERTMS_or_ETCS_system_Encoder(&stream, &p);
}

#endif // __cplusplus

#endif // DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMS_OR_ETCS_SYSTEM_CORE_H_INCLUDED

