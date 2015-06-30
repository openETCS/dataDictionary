
#ifndef MODE_PROFILE_CORE_H_INCLUDED
#define MODE_PROFILE_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Mode_profile_Core_1.h"

struct Mode_profile_Core
{
    // TransmissionMedia=Any
    // Mode profile associated to an MA     
    // Packet Number = 80

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint16_t  D_MAMODE;         // # 15
    uint32_t  M_MAMODE;         // # 2
    uint8_t   V_MAMODE;         // # 7
    uint16_t  L_MAMODE;         // # 15
    uint16_t  L_ACKMAMODE;      // # 15
    uint32_t  Q_MAMODE;         // # 1
    uint8_t   N_ITER_1;         // # 5
    Mode_profile_Core_1   sub_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Mode_profile_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.D_MAMODE << ','
       << +p.M_MAMODE << ','
       << +p.V_MAMODE << ','
       << +p.L_MAMODE << ','
       << +p.L_ACKMAMODE << ','
       << +p.Q_MAMODE << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Mode_profile_Core& a, const Mode_profile_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.D_MAMODE == b.D_MAMODE);
    status = status && (a.M_MAMODE == b.M_MAMODE);
    status = status && (a.V_MAMODE == b.V_MAMODE);
    status = status && (a.L_MAMODE == b.L_MAMODE);
    status = status && (a.L_ACKMAMODE == b.L_ACKMAMODE);
    status = status && (a.Q_MAMODE == b.Q_MAMODE);
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

inline bool operator!=(const Mode_profile_Core& a, const Mode_profile_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Mode_profile_Core Mode_profile_Core;

#define MODE_PROFILE_CORE_BITSIZE 3354

/*@
    logic integer BitSize{L}(Mode_profile_Core* p) = MODE_PROFILE_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Mode_profile_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Mode_profile_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Mode_profile_Core* p) = \true;

    predicate ZeroInitialized(Mode_profile_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Mode_profile_Core* p) = \true;

    predicate UpperBitsNotSet(Mode_profile_Core* p) = \true;

*/

#endif // MODE_PROFILE_CORE_H_INCLUDED

