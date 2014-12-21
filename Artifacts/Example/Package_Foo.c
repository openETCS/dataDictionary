
#include "Package_Foo.h"
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"


int Package_Foo_Enocder(Bitstream* stream, const Package_Foo* p)
{
  if (stream->bitpos + 28 <= 8 * stream->size)
  {
     Bitstream_Write(stream, 8, p->ABC);
     Bitstream_Write(stream, 3, p->DEF);
     Bitstream_Write(stream, 17, p->GHI);

     return 1;
  }
  else
  {
     return 0;
  }
}
