// uap(Kerinter.lib) 中 exp 已改為 exVar
// 如果要在 uap*.cpp 中使用 exp
//   1. 在任一 uapX.cpp 中加
//      ex exp = exVar;
//   2. 在其他 uap*.cpp 中加
//      extern ex exp;
// 或
//   1. 將 uapVar.cpp 加入專案
//   2. 在 uap*.cpp 中加
//      #include "uapVar.h"
//   3. 專案中 define _GINN_UAP_USE_EXP_

#pragma once

#include <uaplib.h>

//#if !defined(_GINN_UAPVAR_H_)
//#define _GINN_UAPVAR_H_ 1

#if defined(_GINN_UAP_USE_EXP_)
extern ex exp;
#endif

extern FUNCVXPTR   ginn_getvxp;
extern FUNCEXPTR   ginn_getexp;
extern FUNCEXXPTR  ginn_getexxp;

extern FUNCSVPTR   ginn_setexpv;
extern FUNCANTPTR  ginn_anticipate;
extern FUNCMITPTR  ginn_getxmitslot;
extern FUNCMITPTR  voice_getxmitslot;

extern FUNCLSPTR   ginn_listen;
extern FUNCLSPTR   voice_listen;
extern FUNCCT      conv_time;

extern FUNCPTR     get_comport;
extern FUNCPTR     get_maxport;
extern FUNCTMPTR   get_newtime;
extern FUNCAERR    ibig;

extern FUNCWTE     ginn_waitevt;

extern FUNCPTR   wrtlog ;
extern FUNCPTR   func_writelog;
extern FUNCPTR   ginn_unlisten ;
extern FUNCPTR   voice_unlisten ;
extern FUNCPTR   ginn_playedbytes ;
extern FUNCPTR   ginn_clrexpvar ;
extern FUNCPTR   ginn_getrecordfnm ;
extern FUNCPTR   ginn_answercall ;

extern FUNCXPTR  play_phrase ;

extern FUNCXPTR  ginn_setringtm ;
extern FUNCXPTR  ginn_listenfe ;
extern FUNCXPTR  ginn_listendx ;
extern FUNCXPTR  voice_listenfe ;
extern FUNCXPTR  voice_listendx ;
extern FUNCXPTR  ginn_clrexpvarbyuser ;
extern FUNCXPTR  ginn_setautoanswer ;
extern FUNCXPTR  ginn_setplayfmtabs ;
extern FUNCXPTR  ginn_setpreferedfnm ;
extern FUNCXPTR  ginn_setrecordfnm ;
extern FUNCXPTR  ginn_setchkoldmsgheader ;

extern FUNCCPTR  ifx;
extern FUNCCPTR  bnam;
extern FUNCCPTR  ginn_bnam;

extern FUNCPTPTR play_tone;
extern FUNCIFMPTR  ifm;

extern FUNCPTR   asrCheck;
extern FUNCAERR  get_AsrErrcode ;
extern FUNCAERR  set_AsrRecFilename;
extern FUNCASRRECP get_AsrRecPath;
extern FUNCASRRECP get_AsrRecFilename;
extern FUNCASRRECP get_AsrRecFormat;
extern FUNCASRRECRES  get_AsrRecResult  ;

extern FUNCPTR   ginn_clrdtmf;
extern FUNCPTR   ginn_outofservice;  //20040206
extern FUNCXPTR  ginn_setbranch;
extern FUNCPTR   ginn_clrbranch;
extern FUNCPTR   ginn_getbranch;
extern FUNCPTR  	ginn_gettoneidx;
extern FUNCAERR  ginn_ani;
extern FUNCAERR  ginn_dnis;

extern FUNCXPTR  ginn_setusetmpsynth;
extern FUNCAERR  ginn_setsynthext;
extern FUNCXPTR  ginn_setsynthplayfmt;
extern FUNCCT fdbprintime;
extern FUNCDBGTIMESTAMP fdbDbgTimeStamp;
extern FUNCPTR ginn_bufdigs;
extern FUNCCT ginn_saveAMode;    //20150506
extern FUNCCT ginn_restoreAMode; //20150506


//for fax

extern FUNCPTR		fax_check;
extern FUNCPTR		ginn_fxopen;
extern FUNCPTR		ginn_fxclose;
extern FUNCXPTR  ginn_fxinitstat;
extern FUNCXPTR  ginn_fxsetrxcoding;
extern FUNCXPTR  ginn_fxsettxcoding;
extern FUNCXPTR	ginn_fxsethdrattrib;
extern FUNCAERR	ginn_fxsethdruser;
extern FUNCAERR  ginn_fxgetremoteid;
extern FUNCAERR	ginn_fxsetlocalid;
extern FUNCPTR   ginn_fxgettxbaudrate;
extern FUNCPTR   ginn_fxgetrxbaudrate;	
extern FUNCXPTR  ginn_fxsettxbaudrate;
extern FUNCXPTR  ginn_fxsetrxbaudrate;
extern FUNCXPTR  ginn_fxsettfpgbase;
extern FUNCXPTR  ginn_fxsetsendcont;
extern FUNCXPTR  ginn_fxsetevttout;
extern FUNCPTR   ginn_fxgetpagecount;
extern FUNCPTR   ginn_fxgetlasterr;
extern FUNCPTR   ginn_fxgetestat;
extern FUNCFXSR	ginn_fxrecvex;
extern FUNCFXSR	ginn_fxrecv;
extern FUNCPTR   ginn_fxclrsendlist;
extern FUNCFXSR  ginn_fxadd2sendlistex;
extern FUNCAERR  ginn_fxadd2sendlist;
extern FUNCPTR   ginn_fxgetsendlistcount;
extern FUNCXPTR	ginn_fxsendex;	
extern FUNCXPTR	ginn_fxsend;
extern FUNCFXSTLOG   set_fxconvlog;

extern FUNCXPTR  ginn_faxopenfxt;
extern FUNCAERR  ginn_fxtaddline;
extern FUNCXPTR  ginn_fxtaddform;
extern FUNCPTR   ginn_fxtnewpage;
extern FUNCAERR  ginn_fxtsetvar;
extern FUNCPTR   ginn_faxclosefxt;
extern FUNCFXCONV  ginn_faxconvertfxt;
extern FUNCFXSTLOG  ginn_keepAlive;
//extern FUNCFXSTLOG  ginn_setAlarmEvent; // 20170109
extern FUNCSETALARMEVENT  ginn_setAlarmEvent; // 20170331

extern int init_get_funcpt();

//#endif