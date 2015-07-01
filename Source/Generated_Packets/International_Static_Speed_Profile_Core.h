
#ifndef INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_H_INCLUDED
#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "International_Static_Speed_Profile_Core_1.h"
#include "International_Static_Speed_Profile_Core_2.h"

struct International_Static_Speed_Profile_Core
{
    // TransmissionMedia=Any
    // Static speed profile and optionally speed limits depending on the international
    // train category.         
    // Packet Number = 27

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_STATIC;         // # 15
    uint8_t   V_STATIC;         // # 7
    uint32_t  Q_FRONT;          // # 1
    uint8_t   N_ITER_1;         // # 5
    International_Static_Speed_Profile_Core_1   sub_1[31];
    uint8_t   N_ITER_2;         // # 5
    International_Static_Speed_Profile_Core_2   sub_2[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const International_Static_Speed_Profile_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_STATIC << ','
       << +p.V_STATIC << ','
       << +p.Q_FRONT << ','
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

inline bool operator==(const International_Static_Speed_Profile_Core& a, const International_Static_Speed_Profile_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_STATIC == b.D_STATIC);
    status = status && (a.V_STATIC == b.V_STATIC);
    status = status && (a.Q_FRONT == b.Q_FRONT);
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

inline bool operator!=(const International_Static_Speed_Profile_Core& a, const International_Static_Speed_Profile_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct International_Static_Speed_Profile_Core International_Static_Speed_Profile_Core;

#define INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_BITSIZE 112

/*@
    logic integer BitSize{L}(International_Static_Speed_Profile_Core* p) = INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_BITSIZE;

    logic integer MaxBitSize{L}(International_Static_Speed_Profile_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, International_Static_Speed_Profile_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(International_Static_Speed_Profile_Core* p) = \true;

    predicate ZeroInitialized(International_Static_Speed_Profile_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, International_Static_Speed_Profile_Core* p) =
      EqualBits(stream, pos,       pos + 2,   p->Q_DIR)             &&
      EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET)          &&
      EqualBits(stream, pos + 15,  pos + 17,  p->Q_SCALE)           &&
      EqualBits(stream, pos + 17,  pos + 32,  p->D_STATIC)          &&
      EqualBits(stream, pos + 32,  pos + 39,  p->V_STATIC)          &&
      EqualBits(stream, pos + 39,  pos + 40,  p->Q_FRONT);

    predicate UpperBitsNotSet(International_Static_Speed_Profile_Core* p) =
      UpperBitsNotSet(p->Q_DIR,            2)   &&
      UpperBitsNotSet(p->L_PACKET,         13)  &&
      UpperBitsNotSet(p->Q_SCALE,          2)   &&
      UpperBitsNotSet(p->D_STATIC,         15)  &&
      UpperBitsNotSet(p->V_STATIC,         7)   &&
      UpperBitsNotSet(p->Q_FRONT,          1);

*/

#endif // INTERNATIONAL_STATIC_SPEED_PROFILE_CORE_H_INCLUDED

