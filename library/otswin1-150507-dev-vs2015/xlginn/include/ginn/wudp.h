#if !defined(GINN_WUDP_H)
#define GINN_WUDP_H

#define         UDP_F_ALL       0
#define         UDP_F_ADDR      1
#define         UDP_L_ADDR      (sizeof(short)+4)

#include        "ginn/cdefs.h"
__BEGIN_DECLS

#ifdef	_GINN_SCO_
extern  int     h_errno;
#endif

void	udp_logfp(FILE *fp);
int     udp_remote_info(int flag, char *addr);
void    udp_close(void);
int     udp_open(const char *host, const char *serv_name);
ssize_t udp_xsend(const char *host, const char *serv_name, const char *ptr, size_t len);
ssize_t udp_isend(char *p, size_t len);
ssize_t udp_rsend(char *p, size_t len);
ssize_t udp_receive(char *p, size_t len);

__END_DECLS
#endif
