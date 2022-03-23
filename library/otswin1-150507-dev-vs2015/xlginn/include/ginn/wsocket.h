#if !defined(GINN_WSOCKET_H)
#define GINN_WSOCKET_H

#ifdef  EC_WIN32
#include        <winsock2.h>

typedef unsigned short sa_family_t;
typedef unsigned short in_port_t;
typedef int socklen_t;
typedef int wSize_t;
#define SOCK_CLOEXEC 0

typedef SOCKET  wSocketHandle_t;
#define ERRNO           (WSAGetLastError())
#define H_ERRNO         (WSAGetLastError())

#else

typedef size_t wSize_t;
typedef int wSocketHandle_t;
#define SOCKET_ERROR    (-1)
#define INVALID_SOCKET  (-1)
#define ERRNO           (errno)
#define H_ERRNO         (h_errno)

#include        <sys/socket.h>
#include        <netinet/in.h>
#include        <net/if.h>
#ifdef  _GINN_SCO_
extern  int     h_errno;
#endif
#endif

#ifdef  _GINN_SOLARIS_
#define INADDR_NONE     -1
#endif

#include        "ginn/cdefs.h"
__BEGIN_DECLS

GINNIMPORT int socket_getHostName(char *name, size_t len);
GINNIMPORT      in_addr_t    socket_get_ipaddr(const char *host, FILE *fp);
GINNIMPORT      long    socket_get_servport(const char *serva_name, const char *proto, FILE *fp);
#ifdef  EC_WIN32
GINNIMPORT      int     socket_startup(void);
GINNIMPORT      int     socket_cleanup(void);
#else
GINNIMPORT      in_addr_t    socket_get_if(char *ifname, FILE *fp);
GINNIMPORT      unsigned int    socket_get_ifconf(struct ifreq *ifr, unsigned int n, FILE *fp);
#endif

__END_DECLS
#endif
