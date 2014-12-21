
#include "Package_Foo_Encoder.h"
#include "Package_Foo_UpperBitsNotSet.h"
#include "Bitstream_Write.h"

int Package_Foo_Encoder(Bitstream* stream, const Package_Foo* p)
{
  if (stream->bitpos + 28 <= 8 * stream->size)
  {
    if (Package_Foo_UpperBitsNotSet(p))
    {
      Bitstream_Write(stream, 8, p->ABC);
      Bitstream_Write(stream, 3, p->DEF);
      Bitstream_Write(stream, 17, p->GHI);

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

