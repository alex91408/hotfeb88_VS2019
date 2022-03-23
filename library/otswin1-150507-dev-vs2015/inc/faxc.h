#pragma once

#include "libginn_.h"
#include "fcontrol.h"

//#if !defined(_GINN_FAXC_H_)
//#define _GINN_FAXC_H_ 1

__BEGIN_DECLS

GINNIMPORT vx		vxp;

GINNIMPORT unsigned int strncpyEx(char *dst, const char *src, unsigned int n);
GINNIMPORT void fdbopenfr(char *fname);
GINNIMPORT void fdbopenfa(char *fname);
GINNIMPORT void fdbopenf(char *fname);
GINNIMPORT void fdbclosef(void);
GINNIMPORT int fdb_check_rotate(void);
GINNIMPORT void fdbprintf(const char *fmt,...);
GINNIMPORT void fdbprintime(void);
GINNIMPORT char fdbDbgTimeStamp(char flag);
GINNIMPORT FILE *fdbfileptr(void);
GINNIMPORT void fdbprintBuffer(const char *label, const unsigned char *p, int len, int mode);
GINNIMPORT void fdbprintBufferEx(const char *label, const unsigned char *p, unsigned int len, unsigned int mode, unsigned int maskOffset, unsigned int maskLength, unsigned char maskByte);
GINNIMPORT void set_fxconvlog(int log);
GINNIMPORT void ginn_faxinit(void);
GINNIMPORT int	ginn_faxopenfxt(int fxt);
GINNIMPORT int	ginn_fxtaddline(const char *p);
GINNIMPORT int	ginn_fxtaddform(int form);
GINNIMPORT int	ginn_fxtnewpage(void);
GINNIMPORT int	ginn_fxtsetvar(char *p);
GINNIMPORT int	ginn_faxclosefxt(void);
GINNIMPORT int  ginn_faxconvertfxt(int fxt, char *tiff);
GINNIMPORT int  ibig(char *wka);
GINNIMPORT void ginn_keepAlive(int eventTimeOnly);
//GINNIMPORT void ginn_setAlarmEvent(int msgCode);
GINNIMPORT void ginn_setAlarmEvent(unsigned int msgCode, void *alarmData, unsigned int len);

__END_DECLS
  
//#endif
