
#ifndef NATIONAL_VALUES_H_INCLUDED
#define NATIONAL_VALUES_H_INCLUDED

#include "Bitstream.h"

struct National_Values
{
    // TransmissionMedia=Balise, RBC
    // Downloads a set of National Values to the train
    // Packet Number = 3

    uint64_t  NID_PACKET;       // # 8
    uint64_t  Q_DIR;            // # 2
    uint64_t  L_PACKET;         // # 13
    uint64_t  Q_SCALE;          // # 2
    uint64_t  D_VALIDNV;        // # 15
    uint64_t  NID_C;            // # 10
    uint64_t  N_ITER;           // # 5// # 10
    uint64_t  V_NVSHUNT;        // # 7
    uint64_t  V_NVSTFF;         // # 7
    uint64_t  V_NVONSIGHT;      // # 7
    uint64_t  V_NVLIMSUPERV;    // # 7
    uint64_t  V_NVUNFIT;        // # 7
    uint64_t  V_NVREL;          // # 7
    uint64_t  D_NVROLL;         // # 15
    uint64_t  Q_NVSBTSMPERM;    // # 1
    uint64_t  Q_NVEMRRLS;       // # 1
    uint64_t  Q_NVGUIPERM;      // # 1
    uint64_t  Q_NVSBFBPERM;     // # 1
    uint64_t  Q_NVINHSMICPERM;  // # 1
    uint64_t  V_NVALLOWOVTRP;   // # 7
    uint64_t  V_NVSUPOVTRP;     // # 7
    uint64_t  D_NVOVTRP;        // # 15
    uint64_t  T_NVOVTRP;        // # 8
    uint64_t  D_NVPOTRP;        // # 15
    uint64_t  M_NVCONTACT;      // # 2
    uint64_t  T_NVCONTACT;      // # 8
    uint64_t  M_NVDERUN;        // # 1
    uint64_t  D_NVSTFF;         // # 15
    uint64_t  Q_NVDRIVER_ADHES; // # 1
    uint64_t  A_NVMAXREDADH1;   // # 6
    uint64_t  A_NVMAXREDADH2;   // # 6
    uint64_t  A_NVMAXREDADH3;   // # 6
    uint64_t  Q_NVLOCACC;       // # 6
    uint64_t  M_NVAVADH;        // # 5
    uint64_t  M_NVEBCL;         // # 4
    uint64_t  Q_NVKINT;         // # 1
    uint64_t  Q_NVKVINTSET;     // # 2
    uint64_t  A_NVP12;          // # 6
    uint64_t  A_NVP23;          // # 6
    uint64_t  V_NVKVINT;        // # 7
    uint64_t  M_NVKVINT;        // # 7
    uint64_t  N_ITER;           // # 5// # 7// # 7
    uint64_t  N_ITER;           // # 5// # 2// # 6// # 6// # 7// # 7// # 5// # 7// # 7
    uint64_t  L_NVKRINT;        // # 5
    uint64_t  M_NVKRINT;        // # 5
    uint64_t  N_ITER;           // # 5// # 5// # 5
    uint64_t  M_NVKTINT;        // # 5
};

typedef struct National_Values National_Values;

#define NATIONAL_VALUES_BITSIZE 369

/*@
    logic integer BitSize{L}(National_Values* p) = NATIONAL_VALUES_BITSIZE;

    logic integer MaxBitSize{L}(National_Values* p) = BitSize(p);

    predicate Separated(Bitstream* stream, National_Values* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(National_Values* p) =
      Invariant(p->NID_PACKET)        &&
      Invariant(p->Q_DIR)             &&
      Invariant(p->L_PACKET)          &&
      Invariant(p->Q_SCALE)           &&
      Invariant(p->D_VALIDNV)         &&
      Invariant(p->NID_C)             &&
      Invariant(p->N_ITER)            &&
      Invariant(p->NID_C(p))          &&
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
      Invariant(p->Q_NVKINT)          &&
      Invariant(p->Q_NVKVINTSET)      &&
      Invariant(p->A_NVP12)           &&
      Invariant(p->A_NVP23)           &&
      Invariant(p->V_NVKVINT)         &&
      Invariant(p->M_NVKVINT)         &&
      Invariant(p->N_ITER)            &&
      Invariant(p->V_NVKVINT(n))      &&
      Invariant(p->M_NVKVINT(n))      &&
      Invariant(p->N_ITER)            &&
      Invariant(p->Q_NVKVINTSET(k))   &&
      Invariant(p->A_NVP12(k))        &&
      Invariant(p->A_NVP23(k))        &&
      Invariant(p->V_NVKVINT(k))      &&
      Invariant(p->M_NVKVINT(k))      &&
      Invariant(p->N_ITER(k))         &&
      Invariant(p->V_NVKVINT(k,m))    &&
      Invariant(p->M_NVKVINT(k,m))    &&
      Invariant(p->L_NVKRINT)         &&
      Invariant(p->M_NVKRINT)         &&
      Invariant(p->N_ITER)            &&
      Invariant(p->L_NVKRINT(l))      &&
      Invariant(p->M_NVKRINT(l))      &&
      Invariant(p->M_NVKTINT);

    predicate ZeroInitialized(National_Values* p) =
      ZeroInitialized(p->NID_PACKET)        &&
      ZeroInitialized(p->Q_DIR)             &&
      ZeroInitialized(p->L_PACKET)          &&
      ZeroInitialized(p->Q_SCALE)           &&
      ZeroInitialized(p->D_VALIDNV)         &&
      ZeroInitialized(p->NID_C)             &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->NID_C(p))          &&
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
      ZeroInitialized(p->Q_NVKINT)          &&
      ZeroInitialized(p->Q_NVKVINTSET)      &&
      ZeroInitialized(p->A_NVP12)           &&
      ZeroInitialized(p->A_NVP23)           &&
      ZeroInitialized(p->V_NVKVINT)         &&
      ZeroInitialized(p->M_NVKVINT)         &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->V_NVKVINT(n))      &&
      ZeroInitialized(p->M_NVKVINT(n))      &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->Q_NVKVINTSET(k))   &&
      ZeroInitialized(p->A_NVP12(k))        &&
      ZeroInitialized(p->A_NVP23(k))        &&
      ZeroInitialized(p->V_NVKVINT(k))      &&
      ZeroInitialized(p->M_NVKVINT(k))      &&
      ZeroInitialized(p->N_ITER(k))         &&
      ZeroInitialized(p->V_NVKVINT(k,m))    &&
      ZeroInitialized(p->M_NVKVINT(k,m))    &&
      ZeroInitialized(p->L_NVKRINT)         &&
      ZeroInitialized(p->M_NVKRINT)         &&
      ZeroInitialized(p->N_ITER)            &&
      ZeroInitialized(p->L_NVKRINT(l))      &&
      ZeroInitialized(p->M_NVKRINT(l))      &&
      ZeroInitialized(p->M_NVKTINT);

    predicate EqualBits(Bitstream* stream, integer pos, National_Values* p) =
      EqualBits(stream, pos,       pos + 8,   p->NID_PACKET)        &&
      EqualBits(stream, pos + 8,   pos + 10,  p->Q_DIR)             &&
      EqualBits(stream, pos + 10,  pos + 23,  p->L_PACKET)          &&
      EqualBits(stream, pos + 23,  pos + 25,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 25,  pos + 40,  p->D_VALIDNV)         &&
      EqualBits(stream, pos + 40,  pos + 50,  p->NID_C)             &&
      EqualBits(stream, pos + 50,  pos + 55,  p->N_ITER)            &&
      EqualBits(stream, pos + 55,  pos + 65,  p->NID_C(p))          &&
      EqualBits(stream, pos + 65,  pos + 72,  p->V_NVSHUNT)         &&
      EqualBits(stream, pos + 72,  pos + 79,  p->V_NVSTFF)          &&
      EqualBits(stream, pos + 79,  pos + 86,  p->V_NVONSIGHT)       &&
      EqualBits(stream, pos + 86,  pos + 93,  p->V_NVLIMSUPERV)     &&
      EqualBits(stream, pos + 93,  pos + 100, p->V_NVUNFIT)         &&
      EqualBits(stream, pos + 100, pos + 107, p->V_NVREL)           &&
      EqualBits(stream, pos + 107, pos + 122, p->D_NVROLL)          &&
      EqualBits(stream, pos + 122, pos + 123, p->Q_NVSBTSMPERM)     &&
      EqualBits(stream, pos + 123, pos + 124, p->Q_NVEMRRLS)        &&
      EqualBits(stream, pos + 124, pos + 125, p->Q_NVGUIPERM)       &&
      EqualBits(stream, pos + 125, pos + 126, p->Q_NVSBFBPERM)      &&
      EqualBits(stream, pos + 126, pos + 127, p->Q_NVINHSMICPERM)   &&
      EqualBits(stream, pos + 127, pos + 134, p->V_NVALLOWOVTRP)    &&
      EqualBits(stream, pos + 134, pos + 141, p->V_NVSUPOVTRP)      &&
      EqualBits(stream, pos + 141, pos + 156, p->D_NVOVTRP)         &&
      EqualBits(stream, pos + 156, pos + 164, p->T_NVOVTRP)         &&
      EqualBits(stream, pos + 164, pos + 179, p->D_NVPOTRP)         &&
      EqualBits(stream, pos + 179, pos + 181, p->M_NVCONTACT)       &&
      EqualBits(stream, pos + 181, pos + 189, p->T_NVCONTACT)       &&
      EqualBits(stream, pos + 189, pos + 190, p->M_NVDERUN)         &&
      EqualBits(stream, pos + 190, pos + 205, p->D_NVSTFF)          &&
      EqualBits(stream, pos + 205, pos + 206, p->Q_NVDRIVER_ADHES)  &&
      EqualBits(stream, pos + 206, pos + 212, p->A_NVMAXREDADH1)    &&
      EqualBits(stream, pos + 212, pos + 218, p->A_NVMAXREDADH2)    &&
      EqualBits(stream, pos + 218, pos + 224, p->A_NVMAXREDADH3)    &&
      EqualBits(stream, pos + 224, pos + 230, p->Q_NVLOCACC)        &&
      EqualBits(stream, pos + 230, pos + 235, p->M_NVAVADH)         &&
      EqualBits(stream, pos + 235, pos + 239, p->M_NVEBCL)          &&
      EqualBits(stream, pos + 239, pos + 240, p->Q_NVKINT)          &&
      EqualBits(stream, pos + 240, pos + 242, p->Q_NVKVINTSET)      &&
      EqualBits(stream, pos + 242, pos + 248, p->A_NVP12)           &&
      EqualBits(stream, pos + 248, pos + 254, p->A_NVP23)           &&
      EqualBits(stream, pos + 254, pos + 261, p->V_NVKVINT)         &&
      EqualBits(stream, pos + 261, pos + 268, p->M_NVKVINT)         &&
      EqualBits(stream, pos + 268, pos + 273, p->N_ITER)            &&
      EqualBits(stream, pos + 273, pos + 280, p->V_NVKVINT(n))      &&
      EqualBits(stream, pos + 280, pos + 287, p->M_NVKVINT(n))      &&
      EqualBits(stream, pos + 287, pos + 292, p->N_ITER)            &&
      EqualBits(stream, pos + 292, pos + 294, p->Q_NVKVINTSET(k))   &&
      EqualBits(stream, pos + 294, pos + 300, p->A_NVP12(k))        &&
      EqualBits(stream, pos + 300, pos + 306, p->A_NVP23(k))        &&
      EqualBits(stream, pos + 306, pos + 313, p->V_NVKVINT(k))      &&
      EqualBits(stream, pos + 313, pos + 320, p->M_NVKVINT(k))      &&
      EqualBits(stream, pos + 320, pos + 325, p->N_ITER(k))         &&
      EqualBits(stream, pos + 325, pos + 332, p->V_NVKVINT(k,m))    &&
      EqualBits(stream, pos + 332, pos + 339, p->M_NVKVINT(k,m))    &&
      EqualBits(stream, pos + 339, pos + 344, p->L_NVKRINT)         &&
      EqualBits(stream, pos + 344, pos + 349, p->M_NVKRINT)         &&
      EqualBits(stream, pos + 349, pos + 354, p->N_ITER)            &&
      EqualBits(stream, pos + 354, pos + 359, p->L_NVKRINT(l))      &&
      EqualBits(stream, pos + 359, pos + 364, p->M_NVKRINT(l))      &&
      EqualBits(stream, pos + 364, pos + 369, p->M_NVKTINT);


    predicate UpperBitsNotSet(National_Values* p) =
      UpperBitsNotSet(p->NID_PACKET,       8)   &&
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_VALIDNV,        15)  &&
      UpperBitsNotSet(p->NID_C,            10)  &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->NID_C(p),         10)  &&
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
      UpperBitsNotSet(p->Q_NVKINT,         1)   &&
      UpperBitsNotSet(p->Q_NVKVINTSET,     2)   &&
      UpperBitsNotSet(p->A_NVP12,          6)   &&
      UpperBitsNotSet(p->A_NVP23,          6)   &&
      UpperBitsNotSet(p->V_NVKVINT,        7)   &&
      UpperBitsNotSet(p->M_NVKVINT,        7)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->V_NVKVINT(n),     7)   &&
      UpperBitsNotSet(p->M_NVKVINT(n),     7)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->Q_NVKVINTSET(k),  2)   &&
      UpperBitsNotSet(p->A_NVP12(k),       6)   &&
      UpperBitsNotSet(p->A_NVP23(k),       6)   &&
      UpperBitsNotSet(p->V_NVKVINT(k),     7)   &&
      UpperBitsNotSet(p->M_NVKVINT(k),     7)   &&
      UpperBitsNotSet(p->N_ITER(k),        5)   &&
      UpperBitsNotSet(p->V_NVKVINT(k,m),   7)   &&
      UpperBitsNotSet(p->M_NVKVINT(k,m),   7)   &&
      UpperBitsNotSet(p->L_NVKRINT,        5)   &&
      UpperBitsNotSet(p->M_NVKRINT,        5)   &&
      UpperBitsNotSet(p->N_ITER,           5)   &&
      UpperBitsNotSet(p->L_NVKRINT(l),     5)   &&
      UpperBitsNotSet(p->M_NVKRINT(l),     5)   &&
      UpperBitsNotSet(p->M_NVKTINT,        5);

*/

#endif // NATIONAL_VALUES_H_INCLUDED

