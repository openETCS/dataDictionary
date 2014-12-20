
#include "Package_Foo.h"

void Package_Foo_Init(Package_Foo* p)
{
  p->ABC = 0;
  p->DEF = 0;
  p->GHI = 0;
}


int Package_Foo_Decoder(Bitstream* stream, Package_Foo* p)
{
  if (stream->bitpos + 28 <= 8 * stream->size)
  {
    //@ ghost uint32_t pos = stream->bitpos;

    p->ABC = Bitstream_Read(stream, 8);
    //@ assert stream->bitpos == pos + 8;
    //@ assert BitstreamEqual64(stream, pos, pos + 8,  p->ABC);
    //@ assert UpperBitsNotSet(p->ABC, 8);

    p->DEF = Bitstream_Read(stream, 3);
    //@ assert stream->bitpos == pos + 11;
    //@ assert BitstreamEqual64(stream, pos + 8,  pos + 11,  p->DEF);
    //@ assert UpperBitsNotSet(p->ABC, 3);

    p->GHI = Bitstream_Read(stream, 17);
    //@ assert stream->bitpos == pos + 28;
    //@ assert BitstreamEqual64(stream, pos + 11,  pos + 28,  p->GHI);
    //@ assert UpperBitsNotSet(p->ABC, 17);

    return 1;
  }
  else
  {
    return 0;
  }
}

