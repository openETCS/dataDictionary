
#ifndef ADHESION_FACTOR_INIT_H_INCLUDED
#define ADHESION_FACTOR_INIT_H_INCLUDED

#include "Adhesion_Factor.h"


/*@
    requires \valid(p);

    assigns  *p;

    ensures  p->ABC == 0;
    ensures  p->DEF == 0;
    ensures  p->GHI == 0;
*/
void Adhesion_Factor_Init(Adhesion_Factor* p);


#endif // ADHESION_FACTOR_INIT_H_INCLUDED

