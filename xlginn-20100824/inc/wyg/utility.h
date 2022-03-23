#ifndef         _UTILITY_
#define         _UTILITY_               1
#include        <time.h>
#if     !defined(EC_WIN32)
#include        <sys/time.h>
#endif
#include        <errno.h>
#define         MON_PER_YEAR            12
#define         HOUR_PER_DAY            24
#define         MIN_PER_HOUR            60
#define         SEC_PER_MIN             60
#define         ENDL                    "\r\n"

#define         WCFG_BUFSIZE            511

#define		XD_DISABLE		0x80000000
#define		XD_SHOWTIME		0x40000000
#define		XD_KERNELMODE		0x00020000
#define		XD_USERMODE		0x00010000
#define		XD_MODEMASK		(XD_KERNELMODE|XD_USERMODE)
#define		XD_FULLMASK		(XD_DISABLE|XD_SHOWTIME|XD_MODEMASK)
#define		XD_MAXLEVEL		0x0000FFFF

typedef unsigned short  wint16;
typedef unsigned long   wint32;

typedef int     (*WCFGFUNCPTR)(char *, void *);

typedef
        struct  {
        long    x[2];
}       GINN_TB;

enum    {
        P_CHAR, P_SPACE, P_HEX, P_DEC, P_HEX_RAW,
	P_MODE_MAX
};

enum    {
        F_RESET, F_COUNT
};

enum    {
        PT_STR, PT_LONG,
        PT_MAX
};

enum    {
        W_BO_LITTLEENDIAN, W_BO_BIGENDIAN,
        W_BO_MAX
};

#include        "cdefs.h"
__BEGIN_DECLS

GINNIMPORT      FILE    *wygfp;
GINNIMPORT      int     xshowtime;
GINNIMPORT      struct  wstat   *xst;
GINNIMPORT      struct  tm      *xtm;
GINNIMPORT      struct  timeval *xtimeval;
//extern  int     errno;

#if     defined(EC_WIN32)
GINNIMPORT      int     gettimeofday(struct timeval *tv, void *tz);
#endif
GINNIMPORT      int     wbyteorder(void);
GINNIMPORT      wint16  wl2b16(wint16 s);
GINNIMPORT      wint16  wb2l16(wint16 s);
GINNIMPORT      wint32  wl2b32(wint32 l);
GINNIMPORT      wint32  wb2l32(wint32 l);
GINNIMPORT      wint16  whtons(wint16 s);
GINNIMPORT      wint16  wntohs(wint16 s);
GINNIMPORT      wint32  whtonl(wint32 l);
GINNIMPORT      wint32  wntohl(wint32 l);
GINNIMPORT      int     xfprintime(FILE *fp);
GINNIMPORT      int     xfprintf(FILE *fp, const char *fmt, ...);
GINNIMPORT      void    xDsetMask(int mask);
GINNIMPORT      void    xDsetLevel(int level);
GINNIMPORT      int     xDfprintf(int maskLevel, FILE *fp, const char *fmt, ...);
GINNIMPORT      int     is_digit(char c);
GINNIMPORT      int     is_xdigit(char c);
GINNIMPORT      int     is_upper(char c);
GINNIMPORT      int     is_lower(char c);
GINNIMPORT      int     is_alpha(char c);
GINNIMPORT      int     to_upper(char c);
GINNIMPORT      int     to_lower(char c);
GINNIMPORT      int     xstricmp(const char *, const char *, int);
GINNIMPORT      int     wstricmp(const char *, const char *);
GINNIMPORT      char    *wstrlwr(char *);
GINNIMPORT      char    *wstrupr(char *);
GINNIMPORT      int     is_long(const char *buf, int n, long *value);
GINNIMPORT      int     is_digit_spc(const char *, const char *);
GINNIMPORT      int     is_digit_spc_t(const char *, const char *, const char *);
GINNIMPORT      int     is_alpha_spc(const char *, const char *);
GINNIMPORT      long    wtime(long *t);
GINNIMPORT      long    elapsed_time(int flag, long *t);
GINNIMPORT      int     reset_ginn_tb(GINN_TB *t);
GINNIMPORT      long    elapsed_10ms(int flag, GINN_TB *t);
GINNIMPORT      long    elapsed_utime(int flag, GINN_TB *t);
GINNIMPORT      long    diff_10ms(GINN_TB *f, GINN_TB *t);
GINNIMPORT      long    diff_utime(GINN_TB *f, GINN_TB *t);
GINNIMPORT      void    xfclose(FILE **fp);
GINNIMPORT      const   char    *xperror(int err);
GINNIMPORT      int     xstat(const char *filename, long *size);
GINNIMPORT      long    xfilelength(const char *filename);
GINNIMPORT      int     xrandom(int max);
GINNIMPORT      void    xstrncpy(char *dst, const char *src, int n);
GINNIMPORT      void    xmempcpy(char *dst, const char *src, int n);
GINNIMPORT      int     xfprintptr(FILE *fp, const char *ptr, int n, int mode);
GINNIMPORT      int     make_feb(int year);
GINNIMPORT      int     days_of_month(int year, int month);
GINNIMPORT      long    xlocaltime(int days);
GINNIMPORT      int     wsplitpath(const char *path);
GINNIMPORT      int     wcfggetlcnt(void);
GINNIMPORT      int     wcfggets(const char *cfg, int chan, WCFGFUNCPTR funcp, void *parmp);
GINNIMPORT      char    *wgetcfgparm(const char *cfg, int chan, const char *token, int type, void *dest);
GINNIMPORT      char    *wgetcfgstr(const char *cfg, int chan, const char *token, char *dest);

__END_DECLS

#endif
