
#ifndef NATIONAL_VALUES_CORE_H_INCLUDED
#define NATIONAL_VALUES_CORE_H_INCLUDED

#include "Bitstream.h"
#include "National_Values_Core_1.h"
#include "CompressedPackets.h"

struct National_Values_Core
{
    // TransmissionMedia=Any
    // Downloads a set of National Values to the train
    // Packet Number = 3

    uint64_t   Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t   Q_SCALE;          // # 2
    uint64_t  D_VALIDNV;        // # 15
    uint64_t   N_ITER_1;         // # 5
    National_Values_Core_1   sub_1[31];
    uint64_t   V_NVSHUNT;        // # 7
    uint64_t   V_NVSTFF;         // # 7
    uint64_t   V_NVONSIGHT;      // # 7
    uint64_t   V_NVUNFIT;        // # 7
    uint64_t   V_NVREL;          // # 7
    uint64_t  D_NVROLL;         // # 15
    uint64_t   Q_NVSRBKTRG;      // # 1
    uint64_t   Q_NVEMRRLS;       // # 1
    uint64_t   V_NVALLOWOVTRP;   // # 7
    uint64_t   V_NVSUPOVTRP;     // # 7
    uint64_t  D_NVOVTRP;        // # 15
    uint64_t   T_NVOVTRP;        // # 8
    uint64_t  D_NVPOTRP;        // # 15
    uint64_t   M_NVCONTACT;      // # 2
    uint64_t   T_NVCONTACT;      // # 8
    uint64_t   M_NVDERUN;        // # 1
    uint64_t  D_NVSTFF;         // # 15
    uint64_t   Q_NVDRIVER_ADHES; // # 1
};

typedef struct National_Values_Core National_Values_Core;

#define NATIONAL_VALUES_CORE_BITSIZE 168

/*@
    logic integer BitSize{L}(National_Values_Core* p) = NATIONAL_VALUES_CORE_BITSIZE;

    logic integer MaxBitSize{L}(National_Values_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, National_Values_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(National_Values_Core* p) =
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_VALIDNV);

    predicate ZeroInitialized(National_Values_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_VALIDNV);

    predicate EqualBits(Bitstream* stream, integer pos, National_Values_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_VALIDNV);

    predicate UpperBitsNotSet(National_Values_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_VALIDNV,        15);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int National_Values_UpperBitsNotSet(const National_Values_Core* p);

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
int National_Values_Encode_Bit(Bitstream* stream, const National_Values_Core* p);

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
int National_Values_Decode_Bit(Bitstream* stream, National_Values_Core* p);

int National_Values_Encode_Int(PacketInfo* data, kcg_int* stream, const National_Values_Core* p);

int National_Values_Decode_Int(PacketInfo* data, const kcg_int* stream, National_Values_Core* p);

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const National_Values_Core& p)
{
    stream
            << +p.Q_DIR << ','
            << +p.L_PACKET << ','
            << +p.Q_SCALE << ','
            << +p.D_VALIDNV << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
    stream << ','
            << +p.V_NVSHUNT << ','
            << +p.V_NVSTFF << ','
            << +p.V_NVONSIGHT << ','
            << +p.V_NVUNFIT << ','
            << +p.V_NVREL << ','
            << +p.D_NVROLL << ','
            << +p.Q_NVSRBKTRG << ','
            << +p.Q_NVEMRRLS << ','
            << +p.V_NVALLOWOVTRP << ','
            << +p.V_NVSUPOVTRP << ','
            << +p.D_NVOVTRP << ','
            << +p.T_NVOVTRP << ','
            << +p.D_NVPOTRP << ','
            << +p.M_NVCONTACT << ','
            << +p.T_NVCONTACT << ','
            << +p.M_NVDERUN << ','
            << +p.D_NVSTFF << ','
            << +p.Q_NVDRIVER_ADHES;

    return stream;
}

inline bool operator==(const National_Values_Core& a, const National_Values_Core& b)
{
    bool status = true;

    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_VALIDNV == b.D_VALIDNV);
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
    status = status && (a.V_NVSHUNT == b.V_NVSHUNT);
    status = status && (a.V_NVSTFF == b.V_NVSTFF);
    status = status && (a.V_NVONSIGHT == b.V_NVONSIGHT);
    status = status && (a.V_NVUNFIT == b.V_NVUNFIT);
    status = status && (a.V_NVREL == b.V_NVREL);
    status = status && (a.D_NVROLL == b.D_NVROLL);
    status = status && (a.Q_NVSRBKTRG == b.Q_NVSRBKTRG);
    status = status && (a.Q_NVEMRRLS == b.Q_NVEMRRLS);
    status = status && (a.V_NVALLOWOVTRP == b.V_NVALLOWOVTRP);
    status = status && (a.V_NVSUPOVTRP == b.V_NVSUPOVTRP);
    status = status && (a.D_NVOVTRP == b.D_NVOVTRP);
    status = status && (a.T_NVOVTRP == b.T_NVOVTRP);
    status = status && (a.D_NVPOTRP == b.D_NVPOTRP);
    status = status && (a.M_NVCONTACT == b.M_NVCONTACT);
    status = status && (a.T_NVCONTACT == b.T_NVCONTACT);
    status = status && (a.M_NVDERUN == b.M_NVDERUN);
    status = status && (a.D_NVSTFF == b.D_NVSTFF);
    status = status && (a.Q_NVDRIVER_ADHES == b.Q_NVDRIVER_ADHES);

    return status;
}

inline bool operator!=(const National_Values_Core& a, const National_Values_Core& b)
{
    return !(a == b);
}

inline int encode(Bitstream& stream, const National_Values_Core& p)
{
    return National_Values_Encode_Bit(&stream, &p);
}

inline int decode(Bitstream& stream, National_Values_Core& p)
{
    return National_Values_Decode_Bit(&stream, &p);
}

inline int encode(PacketInfo& data, kcg_int* stream, const National_Values_Core& p)
{
    std::cerr << "encode int function not implemented for packet 3 yet." << std::endl;

    return National_Values_Encode_Int(&data, stream, &p);
}

inline int decode(PacketInfo& data, const kcg_int* stream, National_Values_Core& p)
{
    std::cerr << "decode int function not implemented for packet 3 yet." << std::endl;

    return National_Values_Decode_Int(&data, stream, &p);
}

#endif // __cplusplus

#endif // NATIONAL_VALUES_CORE_H_INCLUDED

