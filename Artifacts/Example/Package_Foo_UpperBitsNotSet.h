
#ifndef PACKAGE_FOO_ENCODER_H_INCLUDED
#define PACKAGE_FOO_ENCODER_H_INCLUDED

#include "Package_Foo.h"

/*@
    requires \valid_read(p);

    assigns \nothing;

    ensures \result <==> UpperBitsNotSet(p);
*/
int Package_Foo_UpperBitsNotSet(const Package_Foo* p);


#endif // PACKAGE_FOO_ENCODER_H_INCLUDED

