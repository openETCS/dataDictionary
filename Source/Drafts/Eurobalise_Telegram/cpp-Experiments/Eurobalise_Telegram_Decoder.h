
#ifndef EUROBALISE_TELEGRAM_DECODER_H_INCLUDED
#define EUROBALISE_TELEGRAM_DECODER_H_INCLUDED

#include "Eurobalise_Telegram.h"
#include "Eurobalise_Header_Decoder.h"
#include "Decoder_Branch.h"
#include "Packet_Header.h"
#include "Packet_Header_Decoder.h"

Eurobalise_Telegram Eurobalise_Telegram_Decoder(Bitstream* stream);

#endif // EUROBALISE_TELEGRAM_DECODER_H_INCLUDED

