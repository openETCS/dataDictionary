
#ifndef VALIDATED_TRAIN_DATA_CORE_H_INCLUDED
#define VALIDATED_TRAIN_DATA_CORE_H_INCLUDED

#include "Bitstream.h"
#include "Validated_train_data_Core_1.h"
#include "Validated_train_data_Core_2.h"
#include "CompressedPackets.h"

struct Validated_train_data_Core
{
    // TransmissionMedia=Radio
    // Validated train data. For some variables, if the engine does not
    // know a data value, it may use the corresponding default value
    // Packet Number = 11

    uint64_t  L_PACKET;         // # 13
    uint64_t  NID_OPERATIONAL;  // # 32
    uint64_t  NC_TRAIN;         // # 15
    uint64_t  L_TRAIN;          // # 12
    uint64_t   V_MAXTRAIN;       // # 7
    uint64_t   M_LOADINGGAUGE;   // # 8
    uint64_t   M_AXLELOAD;       // # 7
    uint64_t   M_AIRTIGHT;       // # 2
    uint64_t   N_ITER_1;         // # 5
    Validated_train_data_Core_1   sub_1[31];
    uint64_t   N_ITER_2;         // # 5
    Validated_train_data_Core_2   sub_2[31];
};

typedef struct Validated_train_data_Core Validated_train_data_Core;

#define VALIDATED_TRAIN_DATA_CORE_BITSIZE 106

/*@
    logic integer BitSize{L}(Validated_train_data_Core* p) = VALIDATED_TRAIN_DATA_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Validated_train_data_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Validated_train_data_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Validated_train_data_Core* p) =
      Invariant(p->L_PACKET)          &&
      Invariant(p->NID_OPERATIONAL)   &&
      Invariant(p->NC_TRAIN)          &&
      Invariant(p->L_TRAIN)           &&
      Invariant(p->V_MAXTRAIN)        &&
      Invariant(p->M_LOADINGGAUGE)    &&
      Invariant(p->M_AXLELOAD)        &&
      Invariant(p->M_AIRTIGHT);

    predicate ZeroInitialized(Validated_train_data_Core* p) =
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->NID_OPERATIONAL)   &&
      ZeroInitialized(p->NC_TRAIN)          &&
      ZeroInitialized(p->L_TRAIN)           &&
      ZeroInitialized(p->V_MAXTRAIN)        &&
      ZeroInitialized(p->M_LOADINGGAUGE)    &&
      ZeroInitialized(p->M_AXLELOAD)        &&
      ZeroInitialized(p->M_AIRTIGHT);

    predicate EqualBits(Bitstream* stream, integer pos, Validated_train_data_Core* p) =
      EqualBits(stream, pos,       pos + 13,  p->L_PACKET)          &&
      EqualBits(stream, pos + 13,  pos + 45,  p->NID_OPERATIONAL)   &&
      EqualBits(stream, pos + 45,  pos + 60,  p->NC_TRAIN)          &&
      EqualBits(stream, pos + 60,  pos + 72,  p->L_TRAIN)           &&
      EqualBits(stream, pos + 72,  pos + 79,  p->V_MAXTRAIN)        &&
      EqualBits(stream, pos + 79,  pos + 87,  p->M_LOADINGGAUGE)    &&
      EqualBits(stream, pos + 87,  pos + 94,  p->M_AXLELOAD)        &&
      EqualBits(stream, pos + 94,  pos + 96,  p->M_AIRTIGHT);

    predicate UpperBitsNotSet(Validated_train_data_Core* p) =
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->NID_OPERATIONAL,  32)  &&
      UpperBitsNotSet(p->NC_TRAIN,         15)  &&
      UpperBitsNotSet(p->L_TRAIN,          12)  &&
      UpperBitsNotSet(p->V_MAXTRAIN,       7)   &&
      UpperBitsNotSet(p->M_LOADINGGAUGE,   8)   &&
      UpperBitsNotSet(p->M_AXLELOAD,       7)   &&
      UpperBitsNotSet(p->M_AIRTIGHT,       2);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Validated_train_data_UpperBitsNotSet(const Validated_train_data_Core* p);

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
int Validated_train_data_Encode_Bit(Bitstream* stream, const Validated_train_data_Core* p);

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
int Validated_train_data_Decode_Bit(Bitstream* stream, Validated_train_data_Core* p);

int Validated_train_data_Encode_Int(PacketInfo* data, kcg_int* stream, const Validated_train_data_Core* p);

int Validated_train_data_Decode_Int(PacketInfo* data, const kcg_int* stream, Validated_train_data_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Validated_train_data_Core& p)
{
    stream
            << +p.L_PACKET << ','
            << +p.NID_OPERATIONAL << ','
            << +p.NC_TRAIN << ','
            << +p.L_TRAIN << ','
            << +p.V_MAXTRAIN << ','
            << +p.M_LOADINGGAUGE << ','
            << +p.M_AXLELOAD << ','
            << +p.M_AIRTIGHT << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
    stream << ','
       << +p.N_ITER_2;
       for (uint32_t i = 0; i < p.N_ITER_2; ++i)
       {
           stream << ',' << p.sub_2[i];
       }
   

    return stream;
}

inline bool operator==(const Validated_train_data_Core& a, const Validated_train_data_Core& b)
{
    bool status = true;

    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.NID_OPERATIONAL == b.NID_OPERATIONAL);
    status = status && (a.NC_TRAIN == b.NC_TRAIN);
    status = status && (a.L_TRAIN == b.L_TRAIN);
    status = status && (a.V_MAXTRAIN == b.V_MAXTRAIN);
    status = status && (a.M_LOADINGGAUGE == b.M_LOADINGGAUGE);
    status = status && (a.M_AXLELOAD == b.M_AXLELOAD);
    status = status && (a.M_AIRTIGHT == b.M_AIRTIGHT);
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
    status = status && (a.N_ITER_2 == b.N_ITER_2);
    if (a.N_ITER_2 == b.N_ITER_2)
    {
        for (uint32_t i = 0; i < a.N_ITER_2; ++i)
        {
            status = status && (a.sub_2[i] == b.sub_2[i]);
        }
    }
    else
    {
        status = false;
    }

    return status;
}

inline bool operator!=(const Validated_train_data_Core& a, const Validated_train_data_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const Validated_train_data_Core& p)
{
    return Validated_train_data_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, Validated_train_data_Core& p)
{
    return Validated_train_data_Decode_Bit(&stream, &p);
}

inline int encode(PacketInfo& data, kcg_int* stream, const Validated_train_data_Core& p)
{
    std::cerr << "encode int function not implemented for packet 11 yet." << std::endl;

    return Validated_train_data_Encode_Int(&data, stream, &p);
}

inline int decode(PacketInfo& data, const kcg_int* stream, Validated_train_data_Core& p)
{
    std::cerr << "decode int function not implemented for packet 11 yet." << std::endl;

    return Validated_train_data_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // VALIDATED_TRAIN_DATA_CORE_H_INCLUDED

