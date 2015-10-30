
#include "EurobaliseTelegram.h"
#include "AllPackets.h"
#include <assert.h>

int main(void)
{
    uint8_t raw[1024];
    Bitstream stream1;
    Bitstream_Init(&stream1, raw, 1024, 0);

    TelegramHeader header;
    {
        header.Q_UPDOWN  = 1;
        header.M_VERSION = 32;
        header.Q_MEDIA	 = 0;
        header.N_PIG	 = 0;
        header.N_TOTAL	 = 1;
        header.M_DUP	 = 0;
        header.M_MCOUNT	 = 0;
        header.NID_C	 = 64;
        header.NID_BG	 = 3;
        header.Q_LINK	 = 1;
    }

    SessionManagement* a = SessionManagement_New();
    {
        // NID_PACKET = 42;
        a->Q_DIR =1;
        a->L_PACKET = 113;
        a->Q_RBC= 1;
        a->NID_C= 352;
        a->NID_RBC= 1515;
        a->NID_RADIO = 14185023402016767;
        a->Q_SLEEPSESSION= 0;
    }

    NationalValues* b = NationalValues_New();
    {
        // NID_PACKET = 3;
        b->Q_DIR = 1;
        b->L_PACKET = 176;
        b->Q_SCALE = 1;
        b->D_VALIDNV = 0;
        b->N_ITER_1 = 0;
        b->V_NVSHUNT = 6;
        b->V_NVSTFF = 8;
        b->V_NVONSIGHT = 6;
	b->V_NVUNFIT = 20;
	b->V_NVREL = 8;
        b->D_NVROLL = 2;
	b->Q_NVSRBKTRG = 0;
        b->Q_NVEMRRLS = 0;
        b->V_NVALLOWOVTRP = 0;
        b->V_NVSUPOVTRP = 6;
        b->D_NVOVTRP = 200;
        b->T_NVOVTRP = 60;
        b->D_NVPOTRP = 200;
        b->M_NVCONTACT = 1;
        b->T_NVCONTACT = 255;
        b->M_NVDERUN = 1;
        b->D_NVSTFF = 32767;
        b->Q_NVDRIVER_ADHES = 0;
    }

    LevelTransitionOrder* c = LevelTransitionOrder_New();
    {
        // NID_PACKET = 41;
        c->Q_DIR = 1;
        c->L_PACKET = 63;
        c->Q_SCALE = 1;
        c->D_LEVELTR = 300;
        c->M_LEVELTR = 3;
        c->L_ACKLEVELTR = 100;
        c->N_ITER_1 = 0;
    }

    EndOfInformation* d = EndOfInformation_New();

    EurobaliseTelegram t1;
    EurobaliseTelegram_Init(&t1);
    t1.header = header;
    EurobaliseTelegram_Add(&t1, &a->header);
    EurobaliseTelegram_Add(&t1, &b->header);
    EurobaliseTelegram_Add(&t1, &c->header);
    EurobaliseTelegram_Add(&t1, &d->header);

    EurobaliseTelegram_Print(&t1, stdout);
    EurobaliseTelegram_EncodeBit(&t1, &stream1);

    EurobaliseTelegram t2;
    EurobaliseTelegram_Init(&t2);

    stream1.bitpos = 0; // reset bitpos
    EurobaliseTelegram_DecodeBit(&t2, &stream1);
    EurobaliseTelegram_Print(&t2, stdout);

    assert(EurobaliseTelegram_Equal(&t1, &t2));

    return EXIT_SUCCESS;
}

