
#ifndef LINKING_CORE_H_INCLUDED
#define LINKING_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Linking_Core_1.h"

struct Linking_Core
{
    // TransmissionMedia=Any
    // Linking Information.         
    // Packet Number = 5

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_LINK;           // # 15
    uint32_t  Q_NEWCOUNTRY;     // # 1
    uint16_t  NID_C;            // # 10
    uint16_t  NID_BG;           // # 14
    uint32_t  Q_LINKORIENTATION;// # 1
    uint32_t  Q_LINKREACTION;   // # 2
    uint8_t   Q_LOCACC;         // # 6
    uint8_t   N_ITER_1;         // # 5
    Linking_Core_1   sub_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Linking_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_LINK << ','
       << +p.Q_NEWCOUNTRY << ','
       << +p.NID_C << ','
       << +p.NID_BG << ','
       << +p.Q_LINKORIENTATION << ','
       << +p.Q_LINKREACTION << ','
       << +p.Q_LOCACC << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
    

    return stream;
}

inline bool operator==(const Linking_Core& a, const Linking_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_LINK == b.D_LINK);
    status = status && (a.Q_NEWCOUNTRY == b.Q_NEWCOUNTRY);
    if (a.Q_NEWCOUNTRY == 1)
    {
    status = status && (a.NID_C == b.NID_C);
    }
    status = status && (a.NID_BG == b.NID_BG);
    status = status && (a.Q_LINKORIENTATION == b.Q_LINKORIENTATION);
    status = status && (a.Q_LINKREACTION == b.Q_LINKREACTION);
    status = status && (a.Q_LOCACC == b.Q_LOCACC);
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

    return status;
}

inline bool operator!=(const Linking_Core& a, const Linking_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Linking_Core Linking_Core;

#define LINKING_CORE_BITSIZE 120

/*@
    logic integer BitSize{L}(Linking_Core* p) = LINKING_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Linking_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Linking_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Linking_Core* p) = \true;

    predicate ZeroInitialized(Linking_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Linking_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_LINK)            &&
      EqualBits(stream, pos + 32,  pos + 33,  p->Q_NEWCOUNTRY)      &&
      EqualBits(stream, pos + 43,  pos + 57,  p->NID_BG)            &&
      EqualBits(stream, pos + 57,  pos + 58,  p->Q_LINKORIENTATION) &&
      EqualBits(stream, pos + 58,  pos + 60,  p->Q_LINKREACTION)    &&
      EqualBits(stream, pos + 60,  pos + 66,  p->Q_LOCACC);

    predicate UpperBitsNotSet(Linking_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_LINK,           15)  &&
      UpperBitsNotSet(p->Q_NEWCOUNTRY,     1)   &&
      UpperBitsNotSet(p->NID_BG,           14)  &&
      UpperBitsNotSet(p->Q_LINKORIENTATION,1)   &&
      UpperBitsNotSet(p->Q_LINKREACTION,   2)   &&
      UpperBitsNotSet(p->Q_LOCACC,         6)   &&
      UpperBitsNotSet(p->N_ITER_1           5;

*/

#endif // LINKING_CORE_H_INCLUDED

