
#ifndef NATIONAL_VALUES_CORE_H_INCLUDED
#define NATIONAL_VALUES_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "National_Values_Core_1.h"
#include "National_Values_Core_2.h"
#include "National_Values_Core_3.h"
#include "National_Values_Core_4.h"

struct National_Values_Core
{
    // TransmissionMedia=Balise, RBC
    // Downloads a set of National Values to the train  
    // Packet Number = 3

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_VALIDNV;        // # 15
    uint16_t  NID_C;            // # 10
    uint8_t   N_ITER_1;         // # 5
    National_Values_Core_1   sub_1[31];
    uint8_t   V_NVSHUNT;        // # 7
    uint8_t   V_NVSTFF;         // # 7
    uint8_t   V_NVONSIGHT;      // # 7
    uint8_t   V_NVLIMSUPERV;    // # 7
    uint8_t   V_NVUNFIT;        // # 7
    uint8_t   V_NVREL;          // # 7
    uint16_t  D_NVROLL;         // # 15
    uint32_t  Q_NVSBTSMPERM;    // # 1
    uint32_t  Q_NVEMRRLS;       // # 1
    uint32_t  Q_NVGUIPERM;      // # 1
    uint32_t  Q_NVSBFBPERM;     // # 1
    uint32_t  Q_NVINHSMICPERM;  // # 1
    uint8_t   V_NVALLOWOVTRP;   // # 7
    uint8_t   V_NVSUPOVTRP;     // # 7
    uint16_t  D_NVOVTRP;        // # 15
    uint8_t   T_NVOVTRP;        // # 8
    uint16_t  D_NVPOTRP;        // # 15
    uint32_t  M_NVCONTACT;      // # 2
    uint8_t   T_NVCONTACT;      // # 8
    uint32_t  M_NVDERUN;        // # 1
    uint16_t  D_NVSTFF;         // # 15
    uint32_t  Q_NVDRIVER_ADHES; // # 1
    uint8_t   A_NVMAXREDADH1;   // # 6
    uint8_t   A_NVMAXREDADH2;   // # 6
    uint8_t   A_NVMAXREDADH3;   // # 6
    uint8_t   Q_NVLOCACC;       // # 6
    uint8_t   M_NVAVADH;        // # 5
    uint32_t  M_NVEBCL;         // # 4
    uint32_t  Q_NVKINT;         // # 1
    uint32_t  Q_NVKVINTSET;     // # 2
    uint8_t   A_NVP12;          // # 6
    uint8_t   A_NVP23;          // # 6
    uint8_t   V_NVKVINT;        // # 7
    uint8_t   M_NVKVINT;        // # 7
    uint8_t   N_ITER_2;         // # 5
    National_Values_Core_2   sub_2[31];
    uint8_t   N_ITER_3;         // # 5
    National_Values_Core_3   sub_3[31];
    uint32_t  L_NVKRINT;        // # 5
    uint8_t   M_NVKRINT;        // # 5
    uint8_t   N_ITER_4;         // # 5
    National_Values_Core_4   sub_4[31];
    uint8_t   M_NVKTINT;        // # 5
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const National_Values_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_VALIDNV << ','
       << +p.NID_C << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
    stream << ','
       << +p.V_NVSHUNT << ','
       << +p.V_NVSTFF << ','
       << +p.V_NVONSIGHT << ','
       << +p.V_NVLIMSUPERV << ','
       << +p.V_NVUNFIT << ','
       << +p.V_NVREL << ','
       << +p.D_NVROLL << ','
       << +p.Q_NVSBTSMPERM << ','
       << +p.Q_NVEMRRLS << ','
       << +p.Q_NVGUIPERM << ','
       << +p.Q_NVSBFBPERM << ','
       << +p.Q_NVINHSMICPERM << ','
       << +p.V_NVALLOWOVTRP << ','
       << +p.V_NVSUPOVTRP << ','
       << +p.D_NVOVTRP << ','
       << +p.T_NVOVTRP << ','
       << +p.D_NVPOTRP << ','
       << +p.M_NVCONTACT << ','
       << +p.T_NVCONTACT << ','
       << +p.M_NVDERUN << ','
       << +p.D_NVSTFF << ','
       << +p.Q_NVDRIVER_ADHES << ','
       << +p.A_NVMAXREDADH1 << ','
       << +p.A_NVMAXREDADH2 << ','
       << +p.A_NVMAXREDADH3 << ','
       << +p.Q_NVLOCACC << ','
       << +p.M_NVAVADH << ','
       << +p.M_NVEBCL << ','
       << +p.Q_NVKINT << ','
       << +p.Q_NVKVINTSET << ','
       << +p.A_NVP12 << ','
       << +p.A_NVP23 << ','
       << +p.V_NVKVINT << ','
       << +p.M_NVKVINT << ','
       << +p.N_ITER_2;
       for (uint32_t i = 0; i < p.N_ITER_2; ++i)
       {
           stream << ',' << p.sub_2[i];
       }
    stream << ','
       << +p.N_ITER_3;
       for (uint32_t i = 0; i < p.N_ITER_3; ++i)
       {
           stream << ',' << p.sub_3[i];
       }
    stream << ','
       << +p.L_NVKRINT << ','
       << +p.M_NVKRINT << ','
       << +p.N_ITER_4;
       for (uint32_t i = 0; i < p.N_ITER_4; ++i)
       {
           stream << ',' << p.sub_4[i];
       }
    stream << ','
       << +p.M_NVKTINT;

    return stream;
}

inline bool operator==(const National_Values_Core& a, const National_Values_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_VALIDNV == b.D_VALIDNV);
    status = status && (a.NID_C == b.NID_C);
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
    status = status && (a.V_NVLIMSUPERV == b.V_NVLIMSUPERV);
    status = status && (a.V_NVUNFIT == b.V_NVUNFIT);
    status = status && (a.V_NVREL == b.V_NVREL);
    status = status && (a.D_NVROLL == b.D_NVROLL);
    status = status && (a.Q_NVSBTSMPERM == b.Q_NVSBTSMPERM);
    status = status && (a.Q_NVEMRRLS == b.Q_NVEMRRLS);
    status = status && (a.Q_NVGUIPERM == b.Q_NVGUIPERM);
    status = status && (a.Q_NVSBFBPERM == b.Q_NVSBFBPERM);
    status = status && (a.Q_NVINHSMICPERM == b.Q_NVINHSMICPERM);
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
    status = status && (a.A_NVMAXREDADH1 == b.A_NVMAXREDADH1);
    status = status && (a.A_NVMAXREDADH2 == b.A_NVMAXREDADH2);
    status = status && (a.A_NVMAXREDADH3 == b.A_NVMAXREDADH3);
    status = status && (a.Q_NVLOCACC == b.Q_NVLOCACC);
    status = status && (a.M_NVAVADH == b.M_NVAVADH);
    status = status && (a.M_NVEBCL == b.M_NVEBCL);
    status = status && (a.Q_NVKINT == b.Q_NVKINT);
    if (a.Q_NVKINT == 1)
    {
    status = status && (a.Q_NVKVINTSET == b.Q_NVKVINTSET);
    if (a.Q_NVKVINTSET == 1)
    {
    status = status && (a.A_NVP12 == b.A_NVP12);
    status = status && (a.A_NVP23 == b.A_NVP23);
    }
    status = status && (a.V_NVKVINT == b.V_NVKVINT);
    status = status && (a.M_NVKVINT == b.M_NVKVINT);
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
    status = status && (a.N_ITER_3 == b.N_ITER_3);
    if (a.N_ITER_3 == b.N_ITER_3)
    {
        for (uint32_t i = 0; i < a.N_ITER_3; ++i)
        {
            status = status && (a.sub_3[i] == b.sub_3[i]);
        }
    }
    else
    {
        status = false;
    }
    status = status && (a.L_NVKRINT == b.L_NVKRINT);
    status = status && (a.M_NVKRINT == b.M_NVKRINT);
    status = status && (a.N_ITER_4 == b.N_ITER_4);
    if (a.N_ITER_4 == b.N_ITER_4)
    {
        for (uint32_t i = 0; i < a.N_ITER_4; ++i)
        {
            status = status && (a.sub_4[i] == b.sub_4[i]);
        }
    }
    else
    {
        status = false;
    }
    status = status && (a.M_NVKTINT == b.M_NVKTINT);
    }

    return status;
}

inline bool operator!=(const National_Values_Core& a, const National_Values_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct National_Values_Core National_Values_Core;

#define NATIONAL_VALUES_CORE_BITSIZE 232

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
      Invariant(p->D_VALIDNV)         &&
      Invariant(p->NID_C)             &&
      Invariant(p->V_NVSHUNT)         &&
      Invariant(p->V_NVSTFF)          &&
      Invariant(p->V_NVONSIGHT)       &&
      Invariant(p->V_NVLIMSUPERV)     &&
      Invariant(p->V_NVUNFIT)         &&
      Invariant(p->V_NVREL)           &&
      Invariant(p->D_NVROLL)          &&
      Invariant(p->Q_NVSBTSMPERM)     &&
      Invariant(p->Q_NVEMRRLS)        &&
      Invariant(p->Q_NVGUIPERM)       &&
      Invariant(p->Q_NVSBFBPERM)      &&
      Invariant(p->Q_NVINHSMICPERM)   &&
      Invariant(p->V_NVALLOWOVTRP)    &&
      Invariant(p->V_NVSUPOVTRP)      &&
      Invariant(p->D_NVOVTRP)         &&
      Invariant(p->T_NVOVTRP)         &&
      Invariant(p->D_NVPOTRP)         &&
      Invariant(p->M_NVCONTACT)       &&
      Invariant(p->T_NVCONTACT)       &&
      Invariant(p->M_NVDERUN)         &&
      Invariant(p->D_NVSTFF)          &&
      Invariant(p->Q_NVDRIVER_ADHES)  &&
      Invariant(p->A_NVMAXREDADH1)    &&
      Invariant(p->A_NVMAXREDADH2)    &&
      Invariant(p->A_NVMAXREDADH3)    &&
      Invariant(p->Q_NVLOCACC)        &&
      Invariant(p->M_NVAVADH)         &&
      Invariant(p->M_NVEBCL)          &&
      Invariant(p->Q_NVKINT);

    predicate ZeroInitialized(National_Values_Core* p) =
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_VALIDNV)         &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->V_NVSHUNT)         &&
      ZeroInitialized(p->V_NVSTFF)          &&
      ZeroInitialized(p->V_NVONSIGHT)       &&
      ZeroInitialized(p->V_NVLIMSUPERV)     &&
      ZeroInitialized(p->V_NVUNFIT)         &&
      ZeroInitialized(p->V_NVREL)           &&
      ZeroInitialized(p->D_NVROLL)          &&
      ZeroInitialized(p->Q_NVSBTSMPERM)     &&
      ZeroInitialized(p->Q_NVEMRRLS)        &&
      ZeroInitialized(p->Q_NVGUIPERM)       &&
      ZeroInitialized(p->Q_NVSBFBPERM)      &&
      ZeroInitialized(p->Q_NVINHSMICPERM)   &&
      ZeroInitialized(p->V_NVALLOWOVTRP)    &&
      ZeroInitialized(p->V_NVSUPOVTRP)      &&
      ZeroInitialized(p->D_NVOVTRP)         &&
      ZeroInitialized(p->T_NVOVTRP)         &&
      ZeroInitialized(p->D_NVPOTRP)         &&
      ZeroInitialized(p->M_NVCONTACT)       &&
      ZeroInitialized(p->T_NVCONTACT)       &&
      ZeroInitialized(p->M_NVDERUN)         &&
      ZeroInitialized(p->D_NVSTFF)          &&
      ZeroInitialized(p->Q_NVDRIVER_ADHES)  &&
      ZeroInitialized(p->A_NVMAXREDADH1)    &&
      ZeroInitialized(p->A_NVMAXREDADH2)    &&
      ZeroInitialized(p->A_NVMAXREDADH3)    &&
      ZeroInitialized(p->Q_NVLOCACC)        &&
      ZeroInitialized(p->M_NVAVADH)         &&
      ZeroInitialized(p->M_NVEBCL)          &&
      ZeroInitialized(p->Q_NVKINT);

    predicate EqualBits(Bitstream* stream, integer pos, National_Values_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_VALIDNV)         &&
      EqualBits(stream, pos + 32,  pos + 42,  p->NID_C)             &&
      EqualBits(stream, pos + 42,  pos + 49,  p->V_NVSHUNT)         &&
      EqualBits(stream, pos + 49,  pos + 56,  p->V_NVSTFF)          &&
      EqualBits(stream, pos + 56,  pos + 63,  p->V_NVONSIGHT)       &&
      EqualBits(stream, pos + 63,  pos + 70,  p->V_NVLIMSUPERV)     &&
      EqualBits(stream, pos + 70,  pos + 77,  p->V_NVUNFIT)         &&
      EqualBits(stream, pos + 77,  pos + 84,  p->V_NVREL)           &&
      EqualBits(stream, pos + 84,  pos + 99,  p->D_NVROLL)          &&
      EqualBits(stream, pos + 99,  pos + 100, p->Q_NVSBTSMPERM)     &&
      EqualBits(stream, pos + 100, pos + 101, p->Q_NVEMRRLS)        &&
      EqualBits(stream, pos + 101, pos + 102, p->Q_NVGUIPERM)       &&
      EqualBits(stream, pos + 102, pos + 103, p->Q_NVSBFBPERM)      &&
      EqualBits(stream, pos + 103, pos + 104, p->Q_NVINHSMICPERM)   &&
      EqualBits(stream, pos + 104, pos + 111, p->V_NVALLOWOVTRP)    &&
      EqualBits(stream, pos + 111, pos + 118, p->V_NVSUPOVTRP)      &&
      EqualBits(stream, pos + 118, pos + 133, p->D_NVOVTRP)         &&
      EqualBits(stream, pos + 133, pos + 141, p->T_NVOVTRP)         &&
      EqualBits(stream, pos + 141, pos + 156, p->D_NVPOTRP)         &&
      EqualBits(stream, pos + 156, pos + 158, p->M_NVCONTACT)       &&
      EqualBits(stream, pos + 158, pos + 166, p->T_NVCONTACT)       &&
      EqualBits(stream, pos + 166, pos + 167, p->M_NVDERUN)         &&
      EqualBits(stream, pos + 167, pos + 182, p->D_NVSTFF)          &&
      EqualBits(stream, pos + 182, pos + 183, p->Q_NVDRIVER_ADHES)  &&
      EqualBits(stream, pos + 183, pos + 189, p->A_NVMAXREDADH1)    &&
      EqualBits(stream, pos + 189, pos + 195, p->A_NVMAXREDADH2)    &&
      EqualBits(stream, pos + 195, pos + 201, p->A_NVMAXREDADH3)    &&
      EqualBits(stream, pos + 201, pos + 207, p->Q_NVLOCACC)        &&
      EqualBits(stream, pos + 207, pos + 212, p->M_NVAVADH)         &&
      EqualBits(stream, pos + 212, pos + 216, p->M_NVEBCL)          &&
      EqualBits(stream, pos + 216, pos + 217, p->Q_NVKINT);

    predicate UpperBitsNotSet(National_Values_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_VALIDNV,        15)  &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->V_NVSHUNT,        7)   &&
      UpperBitsNotSet(p->V_NVSTFF,         7)   &&
      UpperBitsNotSet(p->V_NVONSIGHT,      7)   &&
      UpperBitsNotSet(p->V_NVLIMSUPERV,    7)   &&
      UpperBitsNotSet(p->V_NVUNFIT,        7)   &&
      UpperBitsNotSet(p->V_NVREL,          7)   &&
      UpperBitsNotSet(p->D_NVROLL,         15)  &&
      UpperBitsNotSet(p->Q_NVSBTSMPERM,    1)   &&
      UpperBitsNotSet(p->Q_NVEMRRLS,       1)   &&
      UpperBitsNotSet(p->Q_NVGUIPERM,      1)   &&
      UpperBitsNotSet(p->Q_NVSBFBPERM,     1)   &&
      UpperBitsNotSet(p->Q_NVINHSMICPERM,  1)   &&
      UpperBitsNotSet(p->V_NVALLOWOVTRP,   7)   &&
      UpperBitsNotSet(p->V_NVSUPOVTRP,     7)   &&
      UpperBitsNotSet(p->D_NVOVTRP,        15)  &&
      UpperBitsNotSet(p->T_NVOVTRP,        8)   &&
      UpperBitsNotSet(p->D_NVPOTRP,        15)  &&
      UpperBitsNotSet(p->M_NVCONTACT,      2)   &&
      UpperBitsNotSet(p->T_NVCONTACT,      8)   &&
      UpperBitsNotSet(p->M_NVDERUN,        1)   &&
      UpperBitsNotSet(p->D_NVSTFF,         15)  &&
      UpperBitsNotSet(p->Q_NVDRIVER_ADHES, 1)   &&
      UpperBitsNotSet(p->A_NVMAXREDADH1,   6)   &&
      UpperBitsNotSet(p->A_NVMAXREDADH2,   6)   &&
      UpperBitsNotSet(p->A_NVMAXREDADH3,   6)   &&
      UpperBitsNotSet(p->Q_NVLOCACC,       6)   &&
      UpperBitsNotSet(p->M_NVAVADH,        5)   &&
      UpperBitsNotSet(p->M_NVEBCL,         4)   &&
      UpperBitsNotSet(p->Q_NVKINT,         1);

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
int National_Values_Encoder(Bitstream* stream, const National_Values_Core* p);

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
int National_Values_Decoder(Bitstream* stream, National_Values_Core* p);

#endif // NATIONAL_VALUES_CORE_H_INCLUDED

