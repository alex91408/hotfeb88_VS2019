#pragma once

#define	GINN_TP_MAXEXLO		10
#define	GINN_TP_MAXTELHEAD	40

typedef struct parms {
        int   version;
        int   ringtm;
        int   card_timeout;
        int   play_vol;
        int   rec_vol;
        char  dbport[24];
        int   dbg_iniflag ;
        int   flash_time;
        int   pause_time;
        int   dtmf_ontime;
        int   dtmf_offtime;
        char  dial_zero[8];
        char  lo_code[6];
        char  exlo_code[GINN_TP_MAXEXLO][6];
        int	  nexlo;
        int   siloff;
        int   sr1;
        int   sr2;
        int   filler[10];
        int	ntelhead;
        char  telhead[GINN_TP_MAXTELHEAD][20];
        int   len[GINN_TP_MAXTELHEAD];
        char  pmfile[GINN_TP_MAXTELHEAD][20];
        int   deft;                     // default position
        int   pos;
        int   callid;                   // call id flag
        int   lcd;			// loop current detection flag
        int	huplcof;		// hangup on loop current off
	int	cspxferbuffersize;
        int	autoanswer;
} TEL, *tel;
