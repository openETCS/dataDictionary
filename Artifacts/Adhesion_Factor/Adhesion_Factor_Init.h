
#ifndef ADHESION_FACTOR_INIT_H_INCLUDED
#define ADHESION_FACTOR_INIT_H_INCLUDED

#include "Adhesion_Factor.h"


/*@
    requires valid:  \valid(p);

    assigns  *p;

    ensures  p->NID_PACKET == 0;
    ensures  p->Q_DIR      == 0;
    ensures  p->L_PACKET   == 0;
    ensures  p->Q_SCALE    == 0;
    ensures  p->D_ADHESION == 0;
    ensures  p->L_ADHESION == 0;
    ensures  p->M_ADHESION == 0;
*/
void Adhesion_Factor_Init(Adhesion_Factor* p);


#endif // ADHESION_FACTOR_INIT_H_INCLUDED

