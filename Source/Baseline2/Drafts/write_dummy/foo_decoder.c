
#include "foo_decoder.h"
#include "Bitstream_Read.h"

int foo_decoder(Bitstream* stream, foo* p)
{
    if (NormalBitstream(stream, FOO_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

	/*@
	   requires NID_C: stream->bitpos == pos + NID_C_B(p);
	   assigns         p->NID_C, stream->bitpos;
	   ensures  NID_C: stream->bitpos == pos + NID_C_E(p);

	   behavior read:
	     assumes NID_C:  p->Q_NEWCOUNTRY == 1;

             assigns         p->NID_C, stream->bitpos;

	     ensures  NID_C: NID_C_E(p) == NID_C_B(p) + 10;
	     ensures  NID_C: stream->bitpos == pos + NID_C_E(p);

	   behavior skip:
	     assumes NID_C:  p->Q_NEWCOUNTRY != 1;

	     assigns         \nothing;

	     ensures  NID_C: NID_C_E(p) == NID_C_B(p);
	     ensures  NID_C: stream->bitpos == pos + NID_C_E(p);

	       
	   disjoint behaviors;
	   complete behaviors;
	*/
        if (p->Q_NEWCOUNTRY == 1)
        {
	    /*@
	       requires NID_C: p->Q_NEWCOUNTRY == 1;

	       assigns         p->NID_C, stream->bitpos;

	       ensures  NID_C: NID_C_E(p) == NID_C_B(p) + 10;
	       ensures  NID_C: stream->bitpos == pos + NID_C_E(p);
	    */
            { p->NID_C		= Bitstream_Read(stream, 10); }
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

