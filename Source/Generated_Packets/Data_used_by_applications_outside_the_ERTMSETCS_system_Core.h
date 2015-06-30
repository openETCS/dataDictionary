
#ifndef DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_H_INCLUDED
#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Data_used_by_applications_outside_the_ERTMSETCS_system_Core
{
    // TransmissionMedia=Any
    // Messages between trackside and on-board devices, which contain information used by
    // applications outside the ERTMS/ETCS system.      
    // Packet Number = 44

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint16_t  NID_XUSER;        // # 9
    uint8_t   NID_NTC;          // # 8
    uint8_t   Other_data_depending_on__NID_XUSER;// # 8
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.NID_XUSER << ','
       << +p.NID_NTC << ','
       << +p.Other_data_depending_on__NID_XUSER;

    return stream;
}

inline bool operator==(const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& a, const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NID_XUSER == b.NID_XUSER);
    if (a.NID_XUSER == 102)
    {
    status = status && (a.NID_NTC == b.NID_NTC);
    }
    status = status && (a.Other_data_depending_on__NID_XUSER == b.Other_data_depending_on__NID_XUSER);

    return status;
}

inline bool operator!=(const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& a, const Data_used_by_applications_outside_the_ERTMSETCS_system_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Data_used_by_applications_outside_the_ERTMSETCS_system_Core Data_used_by_applications_outside_the_ERTMSETCS_system_Core;

#define DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_BITSIZE 1655

/*@
    logic integer BitSize{L}(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = \true;

    predicate ZeroInitialized(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = \true;

    predicate UpperBitsNotSet(Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Data_used_by_applications_outside_the_ERTMSETCS_system_UpperBitsNotSet(const Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p);

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
int Data_used_by_applications_outside_the_ERTMSETCS_system_Encoder(Bitstream* stream, const Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p);

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
int Data_used_by_applications_outside_the_ERTMSETCS_system_Decoder(Bitstream* stream, Data_used_by_applications_outside_the_ERTMSETCS_system_Core* p);

#endif // DATA_USED_BY_APPLICATIONS_OUTSIDE_THE_ERTMSETCS_SYSTEM_CORE_H_INCLUDED

