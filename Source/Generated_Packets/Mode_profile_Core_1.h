
#ifndef MODE_PROFILE_CORE_1_CORE_H_INCLUDED
#define MODE_PROFILE_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"

struct Mode_profile_Core_1
{

    uint16_t  D_MAMODE_k;       // # 15
    uint8_t   M_MAMODE_k;       // # 2
    uint8_t   V_MAMODE_k;       // # 7
    uint16_t  L_MAMODE_k;       // # 15
    uint16_t  L_ACKMAMODE_k;    // # 15
    uint8_t   Q_MAMODE_k;       // # 1
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<<(std::ostream& stream, const Mode_profile_Core_1& p)
{
    stream 
       << +p.D_MAMODE_k << ','
       << +p.M_MAMODE_k << ','
       << +p.V_MAMODE_k << ','
       << +p.L_MAMODE_k << ','
       << +p.L_ACKMAMODE_k << ','
       << +p.Q_MAMODE_k;

    return stream;
}

inline bool operator==(const Mode_profile_Core_1& a, const Mode_profile_Core_1& b)
{
    bool status = true;
    
    status = status && (a.D_MAMODE_k == b.D_MAMODE_k);
    status = status && (a.M_MAMODE_k == b.M_MAMODE_k);
    status = status && (a.V_MAMODE_k == b.V_MAMODE_k);
    status = status && (a.L_MAMODE_k == b.L_MAMODE_k);
    status = status && (a.L_ACKMAMODE_k == b.L_ACKMAMODE_k);
    status = status && (a.Q_MAMODE_k == b.Q_MAMODE_k);

    return status;
}

inline bool operator!=(const Mode_profile_Core_1& a, const Mode_profile_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Mode_profile_Core_1 Mode_profile_Core_1;

#define MODE_PROFILE_CORE_1_CORE_BITSIZE 55

/*@
    logic integer BitSize{L}(Mode_profile_Core_1* p) = MODE_PROFILE_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Mode_profile_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Mode_profile_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Mode_profile_Core_1* p) =
      Invariant(p->D_MAMODE_k)        &&
      Invariant(p->M_MAMODE_k)        &&
      Invariant(p->V_MAMODE_k)        &&
      Invariant(p->L_MAMODE_k)        &&
      Invariant(p->L_ACKMAMODE_k)     &&
      Invariant(p->Q_MAMODE_k);

    predicate ZeroInitialized(Mode_profile_Core_1* p) =
      ZeroInitialized(p->D_MAMODE_k)        &&
      ZeroInitialized(p->M_MAMODE_k)        &&
      ZeroInitialized(p->V_MAMODE_k)        &&
      ZeroInitialized(p->L_MAMODE_k)        &&
      ZeroInitialized(p->L_ACKMAMODE_k)     &&
      ZeroInitialized(p->Q_MAMODE_k);

    predicate EqualBits(Bitstream* stream, integer pos, Mode_profile_Core_1* p) =
      EqualBits(stream, pos,       pos + 15,  p->D_MAMODE_k)        &&
      EqualBits(stream, pos + 15,  pos + 17,  p->M_MAMODE_k)        &&
      EqualBits(stream, pos + 17,  pos + 24,  p->V_MAMODE_k)        &&
      EqualBits(stream, pos + 24,  pos + 39,  p->L_MAMODE_k)        &&
      EqualBits(stream, pos + 39,  pos + 54,  p->L_ACKMAMODE_k)     &&
      EqualBits(stream, pos + 54,  pos + 55,  p->Q_MAMODE_k);

    predicate UpperBitsNotSet(Mode_profile_Core_1* p) =
      UpperBitsNotSet(p->D_MAMODE_k,       15)  &&
      UpperBitsNotSet(p->M_MAMODE_k,       2)   &&
      UpperBitsNotSet(p->V_MAMODE_k,       7)   &&
      UpperBitsNotSet(p->L_MAMODE_k,       15)  &&
      UpperBitsNotSet(p->L_ACKMAMODE_k,    15)  &&
      UpperBitsNotSet(p->Q_MAMODE_k,       1);

*/

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Mode_profile_Core_1_UpperBitsNotSet(const Mode_profile_Core_1* p);

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
int Mode_profile_Core_1_Encoder(Bitstream* stream, const Mode_profile_Core_1* p);

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
int Mode_profile_Core_1_Decoder(Bitstream* stream, Mode_profile_Core_1* p);

#endif // MODE_PROFILE_CORE_1_CORE_H_INCLUDED

