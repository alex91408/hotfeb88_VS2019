#pragma once

#include <parprog.h>
#include <fcontrol.h>
#include <_uaplib.h>

//#if !defined(_GINN_UAPLIB_H_)
//#define _GINN_UAPLIB_H_ 1
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
*/

extern  ex    exVar, comp;    /* for exvar */
extern  exx   exxp;
extern  vx    vxp;    /* for fcontrol */
extern  FUNCPFDB    fdbprintf;

//the follow two line is importent
extern  NFUNCPTR  getFuncPointFromKer;
extern  FUNCSETToKer  setFuncPointToKer;


//typedef int   (*FUNCPTPTR)(int,int,int,char *);  // 20150430
typedef int   (*FUNCANTPTR)(int,int,char *);
typedef int   (*FUNCIFMPTR)(char *,char *,int,int);
typedef int   (*FUNCSVPTR)(int,unsigned short *);
typedef int   (*FUNCMITPTR)(long *);
typedef int   (*FUNCLSPTR)(long);
typedef void  (*FUNCCT)(void);
typedef int   (*FUNCWTE)(FUNCPTR);
typedef vx    (*FUNCVXPTR)(int);
typedef ex    (*FUNCEXPTR)(int);
typedef exx   (*FUNCEXXPTR)(int);
typedef int   (*FUNCFXCONV)(int,char *);
typedef void  (*FUNCFXSTLOG)(int);
typedef struct tm *(*FUNCTMPTR)();
typedef char *(*FUNCRPTR)();
typedef char (*FUNCDBGTIMESTAMP)(char);
//define your own func name got from kernel 

#define  MaxPhoneNo    4
#define  MaxExtPerPhone 64
#define  MaxZJ      4

typedef struct {
  char extno[8];
  char fwd_no[8];
  char busy_fwd_no[8];
  char noans_fwd_no[8];
  char grp[4];
  int  use_flag;
  int  type;
  char pbx_no[32];
  char fill[512];
}Ext;

//#endif