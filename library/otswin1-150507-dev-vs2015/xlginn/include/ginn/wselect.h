#if !defined(GINN_WSELECT_H)
#define GINN_WSELECT_H

#if defined(EC_WIN32)
#if !defined(FD_SETSIZE)
#define FD_SETSIZE 512
#endif
#endif

#include        "ginn/cdefs.h"
#include        "ginn/wsocket.h"
__BEGIN_DECLS

#define _GINN_SLEEPDEFAULT_     20000

GINNIMPORT      int     wfd_setsize(void);
GINNIMPORT      int     wsleep(int usec);
GINNIMPORT      int     is_ready(wSocketHandle_t fd, int microseconds);
GINNIMPORT      int     is_wready(wSocketHandle_t fd, int microseconds);
GINNIMPORT      int     is_xready(wSocketHandle_t fd[], unsigned int cnt, int microseconds);
GINNIMPORT      int     _is_xready(wSocketHandle_t fd1[], unsigned int cnt1, wSocketHandle_t fd2[], unsigned int cnt2, int microseconds);
GINNIMPORT      int     _is_xrwready(wSocketHandle_t fd1[], unsigned int cnt1, wSocketHandle_t wfd1[], unsigned int wcnt1, wSocketHandle_t fd2[], unsigned int cnt2, int microseconds);

__END_DECLS
#endif
