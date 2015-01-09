
#ifndef PACKAGE_FOO_INIT_H_INCLUDED
#define PACKAGE_FOO_INIT_H_INCLUDED

#include "Package_Foo.h"


/*@
    requires \valid(p);

    assigns  *p;

    ensures  ZeroInitialized(p);
*/
void Package_Foo_Init(Package_Foo* p);


#endif // PACKAGE_FOO_INIT_H_INCLUDED

