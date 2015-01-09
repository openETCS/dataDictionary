
#ifndef PACKAGE_FOO_INIT_H_INCLUDED
#define PACKAGE_FOO_INIT_H_INCLUDED

#include "Package_Foo.h"


/*@
    requires \valid(p);

    assigns  *p;

    ensures  p->ABC == 0;
    ensures  p->DEF == 0;
    ensures  p->GHI == 0;
*/
void Package_Foo_Init(Package_Foo* p);


#endif // PACKAGE_FOO_INIT_H_INCLUDED

