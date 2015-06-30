
#ifndef GEOGRAPHICAL_POSITION_INFORMATION_CORE_H_INCLUDED
#define GEOGRAPHICAL_POSITION_INFORMATION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Geographical_Position_Information_Core_1.h"

struct Geographical_Position_Information_Core
{
    // TransmissionMedia=Balise, RBC
    // This packet gives geographical location information for one or multiple references
    // to the train.        
    // Packet Number = 79

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint32_t  Q_NEWCOUNTRY;     // # 1
    uint16_t  NID_C;            // # 10
    uint16_t  NID_BG;           // # 14
    uint16_t  D_POSOFF;         // # 15
    uint32_t  Q_MPOSITION;      // # 1
    uint32_t  M_POSITION;       // # 24
    uint8_t   N_ITER_1;         // # 5
    Geographical_Position_Information_Core_1   sub_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Geographical_Position_Information_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.Q_NEWCOUNTRY << ','
       << +p.NID_C << ','
       << +p.NID_BG << ','
       << +p.D_POSOFF << ','
       << +p.Q_MPOSITION << ','
       << +p.M_POSITION << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Geographical_Position_Information_Core& a, const Geographical_Position_Information_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.Q_NEWCOUNTRY == b.Q_NEWCOUNTRY);
    if (a.Q_NEWCOUNTRY == 1)
    {
    status = status && (a.NID_C == b.NID_C);
    }
    status = status && (a.NID_BG == b.NID_BG);
    status = status && (a.D_POSOFF == b.D_POSOFF);
    status = status && (a.Q_MPOSITION == b.Q_MPOSITION);
    status = status && (a.M_POSITION == b.M_POSITION);
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

inline bool operator!=(const Geographical_Position_Information_Core& a, const Geographical_Position_Information_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Geographical_Position_Information_Core Geographical_Position_Information_Core;

#define GEOGRAPHICAL_POSITION_INFORMATION_CORE_BITSIZE 3222

/*@
    logic integer BitSize{L}(Geographical_Position_Information_Core* p) = GEOGRAPHICAL_POSITION_INFORMATION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Geographical_Position_Information_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Geographical_Position_Information_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Geographical_Position_Information_Core* p) = \true;

    predicate ZeroInitialized(Geographical_Position_Information_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Geographical_Position_Information_Core* p) = \true;

    predicate UpperBitsNotSet(Geographical_Position_Information_Core* p) = \true;

*/

#endif // GEOGRAPHICAL_POSITION_INFORMATION_CORE_H_INCLUDED

