#include        "cdefs.h"
__BEGIN_DECLS

#define _GINN_SLEEPDEFAULT_     20000

GINNIMPORT      int     wfd_setsize(void);
GINNIMPORT      int     wsleep(int usec);
GINNIMPORT      int     is_ready(int fd, int microseconds);
GINNIMPORT      int     is_wready(int fd, int microseconds);
GINNIMPORT      int     is_xready(int fd[], int cnt, int microseconds);
GINNIMPORT      int     _is_xready(int fd1[], int cnt1, int fd2[], int cnt2, int microseconds);
GINNIMPORT      int     _is_xrwready(int fd1[], int cnt1, int wfd1[], int wcnt1, int fd2[], int cnt2, int microseconds);

__END_DECLS
