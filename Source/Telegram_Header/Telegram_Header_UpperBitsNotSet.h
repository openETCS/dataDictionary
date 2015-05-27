
#ifndef TELEGRAM_HEADER_UPPERBITSNOTSET_H_INCLUDED
#define TELEGRAM_HEADER_UPPERBITSNOTSET_H_INCLUDED

#include "Telegram_Header.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Telegram_Header_UpperBitsNotSet(const Telegram_Header* p);

#endif // TELEGRAM_HEADER_UPPERBITSNOTSET_H_INCLUDED

