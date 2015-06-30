
#ifndef TRAIN_RUNNING_NUMBER_FROM_RBC_CORE_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_FROM_RBC_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Train_running_number_from_RBC_Core
{
    // TransmissionMedia=RBC
    // Train running number from RBC      
    // Packet Number = 140

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  NID_OPERATIONAL;  // # 32
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Train_running_number_from_RBC_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.NID_OPERATIONAL;

    return stream;
}

inline bool operator==(const Train_running_number_from_RBC_Core& a, const Train_running_number_from_RBC_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NID_OPERATIONAL == b.NID_OPERATIONAL);

    return status;
}

inline bool operator!=(const Train_running_number_from_RBC_Core& a, const Train_running_number_from_RBC_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Train_running_number_from_RBC_Core Train_running_number_from_RBC_Core;

#define TRAIN_RUNNING_NUMBER_FROM_RBC_CORE_BITSIZE 4015

/*@
    logic integer BitSize{L}(Train_running_number_from_RBC_Core* p) = TRAIN_RUNNING_NUMBER_FROM_RBC_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Train_running_number_from_RBC_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Train_running_number_from_RBC_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Train_running_number_from_RBC_Core* p) = \true;

    predicate ZeroInitialized(Train_running_number_from_RBC_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Train_running_number_from_RBC_Core* p) = \true;

    predicate UpperBitsNotSet(Train_running_number_from_RBC_Core* p) = \true;

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Train_running_number_from_RBC_UpperBitsNotSet(const Train_running_number_from_RBC_Core* p);

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
int Train_running_number_from_RBC_Encoder(Bitstream* stream, const Train_running_number_from_RBC_Core* p);

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
int Train_running_number_from_RBC_Decoder(Bitstream* stream, Train_running_number_from_RBC_Core* p);

#endif // TRAIN_RUNNING_NUMBER_FROM_RBC_CORE_H_INCLUDED

