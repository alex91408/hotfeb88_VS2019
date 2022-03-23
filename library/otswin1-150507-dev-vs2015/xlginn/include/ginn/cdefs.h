#if !defined(GINN_CDEFS_H)
#define GINN_CDEFS_H

//#ifndef         _CDEFS_
//#define         _CDEFS_               1

#if     defined(EC_WIN32) && defined(GINN_DLL)
#ifdef  GINN_EXPORTS
#define GINNIMPORT      __declspec (dllexport)
#else
#define GINNIMPORT      __declspec (dllimport)
#endif
#else
#define GINNIMPORT      extern
#endif

#if defined(EC_WIN32) || defined(WIN32) || defined(_GINN_WIN32_) || defined(_GINN_SOLARIS_) || defined(_GINN_SCOUNIX_)
#if defined(__cplusplus)
#define __BEGIN_DECLS   extern "C" {
#define __END_DECLS     }
//#define __END_DECLS     };
#else
#define __BEGIN_DECLS
#define __END_DECLS
#endif
#else
#include        <sys/cdefs.h>
#include        <sys/types.h>
#endif

#if defined(EC_WIN32)
typedef unsigned __int16   uint16_t;
typedef unsigned __int32   uint32_t;
typedef long off_t;
typedef unsigned __int32 in_addr_t;
#if defined(_MSC_VER) && (_MSC_VER <= 1911) // vs2017, C/C++ Optimizing Compiler Version 19.11.25507.1, vc14.11
typedef long ssize_t;
#endif
//typedef unsigned short sa_family_t;
//typedef unsigned short in_port_t;
//typedef int socklen_t;

//#define SOCK_CLOEXEC 0
#define         wstat           _stat
#define         wopen           _open
#define         wclose          _close
#define         wlseek          _lseek
#define         wread           _read
#define         wwrite          _write
#else
#include <stdint.h>
//typedef uint16_t   wint16;
//typedef uint32_t   wint32;
#ifndef O_BINARY
#define         O_BINARY        0
#endif
#define         wstat           stat
#define         _stat           stat
#define         wopen           open
#define         wclose          close
#define         wlseek          lseek
#define         wread           read
#define         wwrite          write
#endif

#endif
