
#include "Onboard_telephone_numbers_Core_1.h"
#include "Bit64.h"

int Onboard_telephone_numbers_Core_1_UpperBitsNotSet(const Onboard_telephone_numbers_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->NID_RADIO,         64);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Onboard_telephone_numbers_Core_1_Encoder(Bitstream* stream, const Onboard_telephone_numbers_Core_1* p)
{
    if (Bitstream_Normal(stream, ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_BITSIZE))
    {
        if (Onboard_telephone_numbers_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 64, p->NID_RADIO);


            //@ assert NID_RADIO:         EqualBits(stream, pos,       pos + 64,  p->NID_RADIO);

            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

int Onboard_telephone_numbers_Core_1_Decoder(Bitstream* stream, Onboard_telephone_numbers_Core_1* p)
{
    if (Bitstream_Normal(stream, ONBOARD_TELEPHONE_NUMBERS_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

        /*@
          requires NID_RADIO:      stream->bitpos == pos + 0;
          assigns                  stream->bitpos;
          assigns                  p->NID_RADIO;
          ensures  NID_RADIO:      stream->bitpos == pos + 64;
          ensures  NID_RADIO:      EqualBits(stream, pos + 0, pos + 64, p->NID_RADIO);
          ensures  NID_RADIO:      UpperBitsNotSet(p->NID_RADIO, 64);
        */
        {
            p->NID_RADIO        = Bitstream_Read(stream, 64);
        }

        //@ assert NID_RADIO:         EqualBits(stream, pos,       pos + 64,  p->NID_RADIO);

        //@ assert NID_RADIO:         UpperBitsNotSet(p->NID_RADIO,         64);

        //@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

