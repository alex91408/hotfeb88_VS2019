#if !defined(GINN_WTCP_H)
#define GINN_WTCP_H

//#if !defined(_GINN_WTCP_)
//#define _GINN_WTCP_

#ifdef  EC_WIN32
#include        <winsock2.h>
#else
#include        <netinet/in.h>
#endif

#include        "ginn/cdefs.h"
#include        "ginn/wsocket.h"
enum    {
        TCP_C_ERROR = -1, TCP_C_NONE, TCP_C_SERVER, TCP_C_DATA, TCP_C_CONNECTED,
        TCP_C_CONNFAILED, TCP_C_CONNECTING,
        TCP_C_MAXSTATE
};

enum    {
        TCP_E_NONE, TCP_E_NOUSE, TCP_E_ACCEPT, TCP_E_MAXHANDLE,
        TCP_E_MAXERROR
};

enum    {
        TCP_M_BLOCKING, TCP_M_NONBLOCKING,
        TCP_M_MAXSTATE
};

typedef void *TCP_DATATYPE;

typedef
        struct  _TCP_SOCKADDR {
        //long addr;
        in_addr_t addr;
        //unsigned        short     port;
        in_port_t port;
}       TCP_SOCKADDR;

typedef
        struct  _TCP_HD {
        wSocketHandle_t handle;
        int     inprogress;
        TCP_DATATYPE data;
        TCP_SOCKADDR    l;
        TCP_SOCKADDR    r;
}       TCP_HD;

typedef unsigned int wTcpHandle_t;
//extern  int     tcptimeout;
//extern  int     tcpremoteinfo;
//extern  FILE    *tcpfp;
//extern  TCP_HD  *thd;
//extern  int     *hda;

//      2003.07.14
//      tcp_check_nh() now return TCP_C_NONE for unused handle,
//              TCP_C_CONNECTED for used and connected handle
//              TCP_C_CONNECTING for used and connection in progress handle
//
//	2004.06.30
//	add tcp_nodelay()
//

__BEGIN_DECLS

#ifdef  _GINN_SCO_
extern  int     h_errno;
#endif

GINNIMPORT      void    tcp_blockingmode(int mode);
GINNIMPORT      void    tcp_timeout(int microsec);
GINNIMPORT      void    tcp_remoteinfo(int flag);
GINNIMPORT      void    tcp_logfp(FILE *fp);
GINNIMPORT      void    tcp_nodelay(int flag);
GINNIMPORT      void    tcp_keepalive(int flag);
GINNIMPORT      void    tcp_reuseaddr(int flag);
GINNIMPORT      void    tcp_linger(int flag, int linger);
GINNIMPORT      int     tcp_server_getsockname(unsigned int no, char *addr, char *port);
GINNIMPORT      int     tcp_getsockname(unsigned int no, char *laddr, char *lport, char *raddr, char *rport);
GINNIMPORT      unsigned int     tcp_handle_count(void);
GINNIMPORT      unsigned int     tcp_nuse(void);
GINNIMPORT      unsigned int     tcp_ninprogress(void);
GINNIMPORT      int     tcp_check_nh(wTcpHandle_t no);
GINNIMPORT      int     tcp_handle_init(unsigned int cnt);
GINNIMPORT      unsigned int     tcp_server_handle_count(void);
GINNIMPORT      unsigned int     tcp_server_nuse(void);
GINNIMPORT      int     tcp_server_check_nh(wTcpHandle_t no);
GINNIMPORT      int     tcp_server_handle_init(unsigned int cnt);
GINNIMPORT      int     tcp_remote_addr(wTcpHandle_t no, char *p);
GINNIMPORT      int     tcp_server_close(wTcpHandle_t no);
GINNIMPORT      int     tcp_server_closeall(void);
GINNIMPORT      int     tcp_close(wTcpHandle_t no);
GINNIMPORT      int     tcp_closeall(void);
GINNIMPORT      int     tcp_server_xopenEx(wTcpHandle_t *no, const char *lif, const char *serv_name);
GINNIMPORT      int     tcp_server_openEx(wTcpHandle_t *no, const char *serv_name);
GINNIMPORT      int     tcp_server_xopen(const char *lif, const char *serv_name);
GINNIMPORT      int     tcp_server_open(const char *serv_name);
GINNIMPORT      int     tcp_server_readyEx(wTcpHandle_t no, wTcpHandle_t *rHd);
GINNIMPORT      wTcpHandle_t     tcp_server_ready(wTcpHandle_t no);
GINNIMPORT      int     tcp_xconnectEx(wTcpHandle_t *no, const char *host, const char *serv_name, const char *localif, const char *localport);
GINNIMPORT      int     tcp_connectEx(wTcpHandle_t *no, const char *host, const char *serv_name);
GINNIMPORT      int     tcp_connectEx_icmp(wTcpHandle_t *no, const char *host, const char *serv_name);
GINNIMPORT      int     tcp_xconnectEx_icmp(wTcpHandle_t *no, const char *host, const char *serv_name, const char *localif, const char *localport);
GINNIMPORT      int     tcp_xconnect(const char *host, const char *serv_name, const char *localif, const char *localport);
GINNIMPORT      int     tcp_connect(const char *host, const char *serv_name);
GINNIMPORT      int     tcp_connect_icmp(const char *host, const char *serv_name);
GINNIMPORT      int     tcp_xconnect_icmp(const char *host, const char *serv_name, const char *localif, const char *localport);
GINNIMPORT      ssize_t tcp_send(wTcpHandle_t no, const void *p, unsigned int len);
GINNIMPORT      int tcp_data_readyEx(wTcpHandle_t no, wTcpHandle_t *rHd);
GINNIMPORT      wTcpHandle_t     tcp_data_ready(wTcpHandle_t no);
GINNIMPORT      int     tcp_ready(wTcpHandle_t *no);
GINNIMPORT      ssize_t tcp_receive(wTcpHandle_t no, void *p, unsigned int len);
GINNIMPORT      ssize_t tcp_receive_peek(wTcpHandle_t no, void *p, unsigned int len);
GINNIMPORT      ssize_t tcp_xreceive(wTcpHandle_t no, void *p, unsigned int len);
GINNIMPORT      int     tcp_icmp_check(const char *host);
GINNIMPORT      int     tcp_nbytes_inq(wTcpHandle_t no);
GINNIMPORT      int     tcp_nbytes_outq(wTcpHandle_t no);
GINNIMPORT int tcp_setHandleData(wTcpHandle_t no, TCP_DATATYPE p);
GINNIMPORT int tcp_getHandleData(wTcpHandle_t no, TCP_DATATYPE *p);
//GINNIMPORT TCP_DATATYPE tcp_getHandleData(wTcpHandle_t no);
GINNIMPORT int tcp_getHandleInfo(wTcpHandle_t no);

__END_DECLS
#endif
