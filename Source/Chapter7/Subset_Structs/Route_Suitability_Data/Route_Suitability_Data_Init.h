
#ifndef ROUTE_SUITABILITY_DATA_INIT_H_INCLUDED
#define ROUTE_SUITABILITY_DATA_INIT_H_INCLUDED

#include "Route_Suitability_Data.h"

/*@
    requires valid:  \valid(p);

    assigns  *p;
 
    ensures  invariant: Invariant(p);
    ensures  init:      ZeroInitialized(p);
*/
void Route_Suitability_Data_Init(Route_Suitability_Data* p);


#endif // ROUTE_SUITABILITY_DATA_INIT_H_INCLUDED

