
#ifndef PACKAGE_FOO_H_INCLUDED
#define PACKAGE_FOO_H_INCLUDED

#include "FramaCBits.h"

struct Package_Foo
{
    uint64_t ABC;  // 8
    uint64_t DEF;  // 3
    uint64_t GHI;  // 17
};


typedef struct Package_Foo Package_Foo;

/*@
    requires \valid(p);

    assigns  *p;

    ensures  p->ABC == 0;
    ensures  p->DEF == 0;
    ensures  p->GHI == 0;
*/
void Package_Foo_Init(Package_Foo* p);

#endif // PACKAGE_FOO_H_INCLUDED
