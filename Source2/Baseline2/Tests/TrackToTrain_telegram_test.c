
#include "AllPackets.h"
#include "EurobaliseTelegram.h"
#include <assert.h>

int main (void)
{
    printf("\nstart TrackToTrain_telegram_test\n");

    TelegramHeader header;
    {
        header.Q_UPDOWN  = 1;
        header.M_VERSION = 32;
        header.Q_MEDIA	 = 0;
        header.N_PIG	 = 1;
        header.N_TOTAL	 = 1;
        header.M_DUP	 = 0;
        header.M_MCOUNT	 = 0;
        header.NID_C	 = 64;
        header.NID_BG	 = 3;
        header.Q_LINK	 = 1;
    }

    AdhesionFactor* a = AdhesionFactor_New();
    {
        // NID_PACKET = 71;
        a->Q_DIR = 1;
        a->L_PACKET = 56;
	a->Q_SCALE = 1;
	a->D_ADHESION = 9;
	a->L_ADHESION = 24;
	a->M_ADHESION = 0;
    }

    GradientProfile* b = GradientProfile_New();
    {
        // NID_PACKET = 21;
	b->Q_DIR = 1;
	b->L_PACKET = 102;
	b->Q_SCALE = 1;
	b->D_GRADIENT = 2393;
	b->Q_GDIR = 0;
	b->G_A = 210;
	b->N_ITER_1 = 2;

	b->sub_1[0].D_GRADIENT = 1999;
	b->sub_1[0].Q_GDIR = 1;
	b->sub_1[0].G_A = 98;
	b->sub_1[1].D_GRADIENT = 938;
	b->sub_1[1].Q_GDIR = 0;
	b->sub_1[1].G_A = 8;
    }
/*
    Level23MovementAuthority* c = level23MovementAuthority_New();
    {
        // NID_PACKEET = 15;
	c.Q_DIR = 1;
	c.L_PACKET = 218; 
	c.Q_SCALE = 0;
	c.V_LOA = 110;
	c.T_LOA = 5;
	c.N_ITER_1 = 1;

	c.sub_1[0].L_SECTION = 245;
	c.sub_1[0].Q_SECTIONTIMER = 0;
	c.sub_1[0].T_SECTIONTIMER = 23;
	c.sub_1[0].D_SECTIONTIMERSTOPLOC = 990;

	c.L_ENDSECTION = 8739;
	c.Q_SECTIONTIMER = 0;
	c.T_SECTIONTIMER = 93;
	c.D_SECTIONTIMERSTOPLOC = 99;
	c.Q_ENDTIMER = 1;
	c.T_ENDTIMER = 138;
	c.D_ENDTIMERSTARTLOC = 7368;
	c.Q_DANGERPOINT = 0;
	c.D_DP = 933;
	c.V_RELEASEDP = 100;
	c.Q_OVERLAP = 0;
	c.D_STARTOL = 4;
	c.T_OL = 9;
	c.D_OL =  445;
	c.V_RELEASEOL = 45;
    }

    LevelTransitionOrder d;
    {
        // NID_PACKET = 41;
        d.Q_DIR = 1;
	d.L_PACKET = 73; 
	d.Q_SCALE = 1;
	d.D_LEVELTR = 389;
	d.M_LEVELTR = 2;
	d.NID_NTC = 234;
	d.L_ACKLEVELTR = 873;
	d.N_ITER_1 = 1;

	d.sub_1[0].M_LEVELTR = 3;
	d.sub_1[0].NID_NTC = 200;
	d.sub_1[0].L_ACKLEVELTR = 9210;
    }

    ListOfBalisesForSHArea e;
    {
        // NID_PACKET = 49;
	e.Q_DIR = 1;
	e.L_PACKET = 50;
	e.N_ITER_1 = 2;

	e.sub_1[0].Q_NEWCOUNTRY = 0;
	e.sub_1[0].NID_C = 399;
	e.sub_1[0].NID_BG = 1000;
	e.sub_1[1].Q_NEWCOUNTRY = 1;
	e.sub_1[1].NID_C = 4;
	e.sub_1[1].NID_BG = 3000;
    }

    ModeProfile f;
    {
        f.Q_DIR = 1;
        f.L_PACKET = 132;
        f.Q_SCALE = 0;
        f.D_MAMODE = 600;
        f.M_MAMODE = 0;
        f.V_MAMODE = 2;
        f.L_MAMODE = 23;
        f.L_ACKMAMODE = 23;
        f.Q_MAMODE = 1;
        f.N_ITER_1 = 1;

        f.sub_1[0].D_MAMODE = 400;
        f.sub_1[0].M_MAMODE = 2;
        f.sub_1[0].V_MAMODE = 2;
        f.sub_1[0].L_MAMODE = 399;
        f.sub_1[0].L_ACKMAMODE = 1000;
        f.sub_1[0].Q_MAMODE = 0;
    }
*/
    PacketForSendingPlainTextMessages* g = PacketForSendingPlainTextMessages_New();
    {
        g->Q_DIR = 1;
        g->L_PACKET = 116;
        g->Q_SCALE = 1;
        g->Q_TEXTCLASS = 0;
        g->Q_TEXTDISPLAY = 0;
        g->D_TEXTDISPLAY = 400;
        g->M_MODETEXTDISPLAY_0 = 3;
        g->M_LEVELTEXTDISPLAY_0 = 1;
        g->NID_STM_0 = 200;
        g->L_TEXTDISPLAY = 700;
        g->T_TEXTDISPLAY = 80;
        g->M_MODETEXTDISPLAY_1 = 3;
        g->M_LEVELTEXTDISPLAY_1 = 1;
        g->NID_STM_1 = 23;
        g->Q_TEXTCONFIRM = 1;
        g->L_TEXT = 2;
        g->X_TEXT = 30;
    }
/*
    Linking h;
    {
	h.Q_DIR = 1;
	h.L_PACKET = 61;
	h.Q_SCALE = 0;
        h.D_LINK = 792;
        h.Q_NEWCOUNTRY = 1;
        h.NID_C = 1000;
        h.NID_BG = 4;
        h.Q_LINKORIENTATION = 1;
        h.Q_LINKREACTION = 2;
        h.Q_LOCACC = 41;
	h.N_ITER_1 = 0;
    }

    DataUsedByApplicationsOutsideTheERTMSETCSSystem i;
    {
        i.Q_DIR = 1;
	i.L_PACKET = 96;
	i.NID_XUSER = 102;
	i.NID_NTC = 100;
	i.Other_data_depending_on__NID_XUSER = 32928;
    }

    TrackConditionChangeOfTractionPower j;
    {
        j.Q_DIR = 1;
        j.L_PACKET = 46;
        j.Q_SCALE = 2;
        j.D_TRACTION = 100;
        j.M_VOLTAGE = 5;
        j.NID_CTRACTION = 761;
    }

    PacketForSendingFixedTextMessages k;
    {
        k.Q_DIR = 2;
        k.L_PACKET = 84;
        k.Q_SCALE = 2;
        k.Q_TEXTCLASS = 0;
        k.Q_TEXTDISPLAY = 0;
        k.D_TEXTDISPLAY = 100;
        k.M_MODETEXTDISPLAY_0 = 0;
        k.M_LEVELTEXTDISPLAY_0 = 0;
        k.NID_NTC_0 = 142;
        k.L_TEXTDISPLAY = 400;
        k.T_TEXTDISPLAY = 300;
        k.M_MODETEXTDISPLAY_1 = 0;
        k.M_LEVELTEXTDISPLAY_1 = 0;
        k.NID_NTC_1 = 38;
        k.Q_TEXTCONFIRM = 0;
        k.Q_CONFTEXTDISPLAY = 0;
        k.Q_TEXTREPORT = 0;
        k.NID_TEXTMESSAGE = 99;
        k.NID_C = 100;
        k.NID_RBC = 16;
        k.Q_TEXT = 1;
    }

    AxleLoadSpeedProfile l;
    {
        l.Q_DIR = 1;
        l.L_PACKET = 82;
        l.Q_SCALE = 1;
        l.Q_TRACKINIT = 0;
        l.D_TRACKINIT = 100;
        l.D_AXLELOAD = 77;
        l.L_AXLELOAD = 10;
        l.Q_FRONT = 0;
        l.N_ITER_1 = 0;

        l.N_ITER_2 = 1;

	l.sub_2[0].D_AXLELOAD = 15;
	l.sub_2[0].L_AXLELOAD = 12;
	l.sub_2[0].Q_FRONT = 0;
	l.sub_2[0].N_ITER_2_1 = 2;
	l.sub_2[0].sub_2_1[0].M_AXLELOADCAT = 120;
	l.sub_2[0].sub_2_1[0].V_AXLELOAD = 0;
	l.sub_2[0].sub_2_1[1].M_AXLELOADCAT = 36;
	l.sub_2[0].sub_2_1[1].V_AXLELOAD = 13;
    }

    GeographicalPositionInformation m;
    {
        m.Q_DIR = 2;
        m.L_PACKET = 187;
        m.Q_SCALE = 1;
        m.Q_NEWCOUNTRY = 0;
        m.NID_C = 100;
        m.NID_BG = 9;
        m.D_POSOFF = 600;
        m.Q_MPOSITION = 1;
        m.M_POSITION = 1500;
        m.N_ITER_1 = 2;
	
        m.sub_1[0].Q_NEWCOUNTRY = 0;
        m.sub_1[0].NID_C = 10;
        m.sub_1[0].NID_BG = 189;
        m.sub_1[0].D_POSOFF = 6778;
        m.sub_1[0].Q_MPOSITION = 0;
        m.sub_1[0].M_POSITION = 70;

        m.sub_1[1].Q_NEWCOUNTRY = 1;
        m.sub_1[1].NID_C = 90;
        m.sub_1[1].NID_BG = 0;
        m.sub_1[1].D_POSOFF = 700;
        m.sub_1[1].Q_MPOSITION = 1;
        m.sub_1[1].M_POSITION = 10000;
    }

    PositionReportParameters n;
    {
        n.Q_DIR = 2;
        n.L_PACKET = 64;
        n.Q_SCALE = 2;
        n.T_CYCLOC = 156;
        n.D_CYCLOC = 233;
        n.M_LOC = 3;
        n.N_ITER_1 = 1;

        n.sub_1[0].D_LOC = 569;
        n.sub_1[0].Q_LGTLOC = 0;
    }

    TrackCondition o;
    {
        o.Q_DIR = 0;
        o.L_PACKET = 33;
        o.Q_SCALE = 0;
        o.Q_TRACKINIT = 1;
        o.D_TRACKINIT = 1000;
        o.D_TRACKCOND = 500;
        o.L_TRACKCOND = 10;
        o.M_TRACKCOND = 5;
        o.N_ITER_1 = 1;
        o.sub_1[0].D_TRACKCOND = 100;
        o.sub_1[0].L_TRACKCOND = 8;
        o.sub_1[0].M_TRACKCOND = 3;
    }

    RouteSuitabilityData p;
    {
        p.Q_DIR = 0;
        p.L_PACKET = 33;
        p.Q_SCALE = 2;
        p.Q_TRACKINIT = 1;
        p.D_TRACKINIT = 300;
        p.D_SUITABILITY = 400;
        p.Q_SUITABILITY = 1;
        p.M_LINEGAUGE = 156;
        p.M_AXLELOADCAT = 15;
        p.M_VOLTAGE = 3;
        p.NID_CTRACTION = 100;
        p.N_ITER_1 = 1;

        p.sub_1[0].D_SUITABILITY = 500;
        p.sub_1[0].Q_SUITABILITY = 0;
        p.sub_1[0].M_LINEGAUGE = 240;
        p.sub_1[0].M_AXLELOADCAT = 15;
        p.sub_1[0].M_VOLTAGE = 0;
        p.sub_1[0].NID_CTRACTION = 1000;
    }

    InternationalStaticSpeedProfile q;
    {
        q.Q_DIR = 2;
        q.L_PACKET = 104;
        q.Q_SCALE = 2;
        q.D_STATIC =  1000;
        q.V_STATIC = 78;
        q.Q_FRONT = 1;
        q.N_ITER_1 = 1;
        q.N_ITER_2 = 1;

	q.sub_1[0].Q_DIFF = 0;
	q.sub_1[0].NC_CDDIFF = 14;
	q.sub_1[0].NC_DIFF = 0;
	q.sub_1[0].V_DIFF = 120;

	q.sub_2[0].D_STATIC = 400;
	q.sub_2[0].V_STATIC = 70;
	q.sub_2[0].Q_FRONT = 1;
	q.sub_2[0].N_ITER_2_1 = 1;

	q.sub_2[0].sub_2_1[0].Q_DIFF = 1;
	q.sub_2[0].sub_2_1[0].NC_CDDIFF = 0;
	q.sub_2[0].sub_2_1[0].NC_DIFF = 12;
	q.sub_2[0].sub_2_1[0].V_DIFF = 18;
    }

    NationalValues r;
    {
        // NID_PACKET = 3;
        r.Q_DIR = 1;
        r.L_PACKET = 230;
        r.Q_SCALE = 1;
        r.D_VALIDNV = 0;
        r.NID_C = 0;
        r.N_ITER_1 = 0;
        r.V_NVSHUNT = 6;
        r.V_NVSTFF = 8;
        r.V_NVONSIGHT = 6;
        r.V_NVLIMSUPERV = 20;
        r.V_NVUNFIT = 20;
        r.V_NVREL = 8;
        r.D_NVROLL = 2;
        r.Q_NVSBTSMPERM = 1;
        r.Q_NVEMRRLS = 0;
        r.Q_NVGUIPERM = 0;
        r.Q_NVSBFBPERM = 0;
        r.Q_NVINHSMICPERM = 0;
        r.V_NVALLOWOVTRP = 0;
        r.V_NVSUPOVTRP = 6;
        r.D_NVOVTRP = 200;
        r.T_NVOVTRP = 60;
        r.D_NVPOTRP = 200;
        r.M_NVCONTACT = 1;
        r.T_NVCONTACT = 255;
        r.M_NVDERUN = 1;
        r.D_NVSTFF = 32767;
        r.Q_NVDRIVER_ADHES = 0;
        r.A_NVMAXREDADH1 = 20;
        r.A_NVMAXREDADH2 = 14;
        r.A_NVMAXREDADH3 = 14;
        r.Q_NVLOCACC = 12;
        r.M_NVAVADH = 1;
        r.M_NVEBCL = 1;
        r.Q_NVKINT = 0;
    }
*/
    EndOfInformation* s = EndOfInformation_New();
    {
        // NID_PACKET = 255;
    }

    EurobaliseTelegram t1;
    EurobaliseTelegram_Init(&t1);
    t1.header = header;
    EurobaliseTelegram_Add(&t1, &a->header);
    EurobaliseTelegram_Add(&t1, &b->header);
    /*
    EurobaliseTelegram_Add(&t1, &c->header);
    EurobaliseTelegram_Add(&t1, &d->header);
    EurobaliseTelegram_Add(&t1, &e->header);
    EurobaliseTelegram_Add(&t1, &f->header);
    */
    EurobaliseTelegram_Add(&t1, &g->header);
    /*
    EurobaliseTelegram_Add(&t1, &h->header);
    EurobaliseTelegram_Add(&t1, &i->header);
    EurobaliseTelegram_Add(&t1, &j->header);
    EurobaliseTelegram_Add(&t1, &k->header);
    EurobaliseTelegram_Add(&t1, &l->header);
    EurobaliseTelegram_Add(&t1, &m->header);
    EurobaliseTelegram_Add(&t1, &n->header);
    EurobaliseTelegram_Add(&t1, &o->header);
    EurobaliseTelegram_Add(&t1, &p->header);
    EurobaliseTelegram_Add(&t1, &q->header);
    EurobaliseTelegram_Add(&t1, &r->header);
    */
    EurobaliseTelegram_Add(&t1, &s->header);

    CompressedPackets container;

    EurobaliseTelegram_Print(&t1, stdout);
    EurobaliseTelegram_EncodeInt(&t1, &container);

    EurobaliseTelegram t2;
    EurobaliseTelegram_Init(&t2);
    t2.header = header;

    EurobaliseTelegram_DecodeInt(&t2, &container);
    EurobaliseTelegram_Print(&t2, stdout);

    assert(EurobaliseTelegram_Equal(&t1, &t2));

    printf("end TrackToTrain_telegram_test \n");
    return EXIT_SUCCESS;
}

