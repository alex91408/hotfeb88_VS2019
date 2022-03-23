#pragma once

#include "fcontrol.h"
#include "parprog.h"
#include "otsconf.h"
#include "app.h"
#include "apgen.h"
#include "dialhead.h"
#include "getConf.h"
#include "faxc.h"
#include "_uaplib.h"

#define  KER_PRINT      1
#define GINN_MAXDTMF    4096
#define  _GINN_USEXPB_

#ifndef TX0400D
#define GINN_CHANFILE   "./channel.prm"
#else
#define GINN_CHANFILE   "./channel.telprm"
#endif
#define	GINN_KXNAME	"./kx.prm"
#define	GINN_FXEVTTOUT		180
#define	GINN_MINFXEVTTOUT	60
#define	GINN_MAXSENDLIST	10
#define	GINN_L_SYNTHEXT		16

enum    {
        GINN_ERROR = -1, GINN_NONE, GINN_DTI, GINN_AG,GINN_GC
};

typedef int     (*GINN_FUNCPTR)(void);
typedef int     (*GINN_STREAMPTR)(char *, int);
typedef GINN_FUNCPTR    (*GINN_SELCHKHOST)(char *);

//enum    {
//        GINN_TN_NONE, GINN_TN_BUSY, GINN_TN_SPECIAL
//};

enum    {
        GINN_TN_NONE, GINN_TN_DISCONNECT, GINN_TN_SPECIAL, GINN_TN_RINGBACK,
        GINN_TN_BUSY, GINN_TN_FAX,GINN_TN_MAX
};

enum    {
        GINN_ETN_NONE, GINN_ETN_SPEC, GINN_ETN_DIAL, GINN_ETN_EXTRA,
        GINN_ETN_MAX
};

enum    {
        GINN_SDC_NONE, GINN_SDC_TONEON, GINN_SDC_TONEOFF, GINN_SDC_TASKFAIL,
        GINN_SDC_DISCONNECTED, GINN_SDC_ABITON, GINN_SDC_ABITOFF,
        GINN_SDC_BBITON, GINN_SDC_BBITOFF, GINN_SDC_TN_DISCONNECT,
        GINN_SDC_TN_SPECIAL, GINN_SDC_LCOFF, GINN_SDC_REMOTEHANGUP,
        GINN_SDC_MAXSDC,GINN_SDC_TN_DTMF
};

/*
enum    {
        GINN_FMT_CONFMESS, GINN_FMT_ADPCM, GINN_FMT_ULAW, GINN_FMT_ALAW,
        GINN_FMT_WAVE_ULAW, GINN_FMT_WAVE_ALAW,GINN_FMT_CONFSYNTH,
        GINN_FMT_MAX
};

enum    {
        GINN_FNM_MESS, GINN_FNM_VOX, GINN_FNM_ULAW, GINN_FNM_ALAW,
        GINN_FNM_WAVE_ULAW, GINN_FNM_WAVE_ALAW,
        GINN_FNM_MAX
};
*/

enum    {
        GCF_NONE, GCF_DTMF, GCF_RESULT, GCF_CSPINIT, GCF_CSPEND, GCF_BARGEIN,
        GCF_TIMEOUT, GCF_HANGUP,
        GCF_MAX
};

/*
enum    {
        GINN_CR_NONE, GINN_CR_BUSY, GINN_CR_NOANS, GINN_CR_NORB, GINN_CR_CNCT,
        GINN_CR_CEPT, GINN_CR_STOPD, GINN_CR_NODIALTONE, GINN_CR_FAXTONE,
        GINN_CR_ERROR,GINN_CR_UNKNOWN,GINN_CR_MAXCR
};

enum    {
        GINN_FX_NONE, GINN_FX_HDRDISABLE, GINN_FX_HDRFMT1, GINN_FX_HDRFMT2,
        GINN_FX_MH, GINN_FX_MR, GINN_FX_MMR,
        GINN_FX_MH_ECM, GINN_FX_MR_ECM, GINN_FX_MMR_ECM,
        GINN_FX_BASE0, GINN_FX_AUTOPG,
        GINN_FX_AUTO, GINN_FX_MPS, GINN_FX_EOM, GINN_FX_MPG, GINN_FX_EOP,
	GINN_FX_TX, GINN_FX_RX,
        GINN_FX_MAXFX
};

enum    {
        GINN_FT_NORMAL, GINN_FT_VOICEREQ, GINN_FT_ERROR, GINN_FT_ABORT,
        GINN_FT_EVTTOUT, GINN_FT_TIMEOUT, GINN_FT_INVOKE,
        GINN_FT_MAXFT
};

#define	GINN_FXDF_NONE		0x0000
#define	GINN_FXDF_ISSUE_VRQ	0x0001
#define	GINN_FXDF_PHASEB	0x0002
#define	GINN_FXDF_PHASED	0x0004
#define	GINN_FXDF_RXRESHI	0x0008
#define	GINN_FXDF_TXRESHI	0x0008
#define	GINN_FXDF_RXRESLO	0x0010
#define	GINN_FXDF_TXRESLO	0x0010
*/

//extern  vx      vxp;
extern  ex      exVar;
extern  ex      comp;
extern  exx     exxp;
//extern  CONF    cf;
//extern  CONF0   cf0;
//extern  char    devnam[];
extern  int     erfd;
extern  CHANNEL chn;          /* for AP work file */
//extern  FILE    *fdbfd;
extern  FILE    *dbg_fdbfd;
extern  struct  tm      *tm;
extern  time_t  lt;
//extern  char    etab_buff[];
extern  char    host_buff[];
extern  int     wlog_pend;   /* 0 No pending, 1:pending 2:clear out */
extern  char    ckbuff[];
extern  int     ad_deduct;
extern  VTAB    vap1;
extern  vtab    vtabp;               /* for vap file */
extern  int     hup_stat;
extern  DRFDD   drfd;  /* for open drxxx AP file */

extern  char    ginn_drn[], ginn_typ[], ginn_kxname[];
extern  char    ginn_callingpn[];
extern  FUNCPTR    _uap_check_wtring;
extern  FUNCPTR    _uap_check_play;
extern  FUNCPTR    _uap_check_dial;
extern  FUNCPTR    _uap_check_rec;
extern  FUNCPTR    _uap_check_tone;
extern  FUNCPTR    _uap_check_dtmf;
extern  FUNCPTR    _uap_play_end;
//extern  FUNCPTR   _uap_fdial_check;
extern  FUNCXPTR   _uap_receive_dtmf;
extern  NFUNCPTR    _uap_host_check;
extern  FUNCFXSR   _uap_invalidApBranch;
extern  FUNCFXSR   _uap_func101CondDig;
extern  FUNCMIPTR  _uap_func101MsgInvalid;

extern  GINN_SELCHKHOST ginn_selchkhostp;
extern  GINN_FUNCPTR    ginn_cstfuncp;


void    conv_time(void);
int     get_dtmf(char *buf, unsigned maxd, int maxt, const char *termd);
int     v_playf(const char *fname, const char *termd, int clrdig, short vol_adj);
int     vm_play(int cnti, const char *termd, int clrdig, short vol_adj);
int     v_playtone(int freq1, int freq2, int maxt, const char *termd);
int     v_playx(const char *fname, const char *termd, int counter, GINN_FUNCPTR cfunc);
int     v_recf(const char *fname, unsigned rectm, const char *termd, char beep);
int     blind_dial(const char *xxx);
int     dial_out(const char *tel);

int     _ginn_srwaitevt();
int ginn_waitEvent(int ms);
int     _ginn_hangup(void);
int     ginn_anticipate(int func, int next, const char *p);
int     ginn_stopdx(int cause);
int     ginn_getxmitslot(long *ts);
int     ginn_listen(long ts);
int     ginn_unlisten(void);
int     ginn_dnis(char *p);
int     ginn_ani(char *p);
int     ginn_inservice(void);
int     ginn_outofservice(void);
int     voice_getxmitslot(long *ts);
int     voice_listen(long ts);
int     voice_unlisten(void);
int     ginn_setcallingpn(const char *p);
int     ginn_answercall(void);
int     ginn_playedbytes(void);
int     ginn_getdtmflen(void);
int     ginn_getdtmfbuf(char *p);
int     ginn_clrdtmfbuf(void);
int     ginn_clrcallend(void);
int     ginn_setcallend(int cause);
int     ginn_getcallend(void);
int     ginn_gettoneidx(void);
void    ginn_clrtoneidx(void);
int     ginn_clrbranch(void);
int     ginn_setbranch(int branch);
int     ginn_getbranch(void);
int     ginn_setringtm(int tm);
int     ginn_setexpv(int vcnt, unsigned short *v);
int     ginn_listenfe(int voie);
int     ginn_listendx(int voie);
int     voice_listenfe(int voie);
int     voice_listendx(int voie);

int     ginn_waitevt(GINN_FUNCPTR p);
int     ginn_clrexpvarbyuser(int flag);
int     ginn_clrexpvar(void);
int     ginn_setAA(int autoanswer_flag);
int     ginn_setautoanswer(int autoanswer_flag);
int     ginn_setplayfmtabs(int fmt);
int     ginn_setpreferedfnm(int fnm);
int     ginn_getrecordmode(void);
int     ginn_getrecordfnm(void);
int     ginn_setrecordfnm(int fnm);
int     ginn_setchkoldmsgheader(int flag);
int     ginn_cspfunc(int messno, int len, char *grammar, char *result);
int     ginn_setexpv(int vcnt, unsigned short *v);
int     ginn_closetmpsynthfd();
int     ginn_setplaymode(int mode);

int		  fax_check();
int     ginn_fxopen();
int     ginn_fxclose();
int	ginn_fxinitstat(int state);
int     ginn_fxsetrxcoding(int coding);
int     ginn_fxsettxcoding(int coding);
int     ginn_fxsethdrattrib(int attrib);
int     ginn_fxsethdruser(char *p);
int     ginn_fxgetremoteid(char *p);
int     ginn_fxsetlocalid(char *p);
int     ginn_fxgettxbaudrate(void);
int     ginn_fxgetrxbaudrate(void);
int     ginn_fxsettxbaudrate(int baud);
int     ginn_fxsetrxbaudrate(int baud);
int     ginn_fxsettfpgbase(int base);
int     ginn_fxsetsendcont(int cont);
int     ginn_fxsetevttout(int secs);
int     ginn_fxgetpagecount(void);
int     ginn_fxgetlasterr(void);
int     ginn_fxgetestat(void);
int     ginn_fxrecvex(char *fname, int mask);
int     ginn_fxrecv(char *fname, int vrq);
int     ginn_fxclrsendlist(void);
int     ginn_fxadd2sendlistex(char *fname, int cont);
int     ginn_fxadd2sendlist(char *fname);
int     ginn_fxgetsendlistcount(void);
int     ginn_fxsendex(int mask);
int     ginn_fxsend(int vrq);
//int     ginn_faxconvert(int form, char *tiff);
//void    set_fxconvlog(int log);
int     ginn_ringst(void);
int     ginn_abort(void);
int ginn_bufdigs(void);
void ginn_saveAMode(void);
void ginn_restoreAMode(void);
#ifdef	_GINN_DTI_
int     dial_t1(const char *tel);
#endif
