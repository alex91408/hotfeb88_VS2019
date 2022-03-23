#pragma once

#include "otsconf.h"
#include "getConf.h"
#include "fControl.h"
#include "parprog.h"
#include "faxc.h"

//#if !defined(_GINN_HOTS_H_)
//#define _GINN_HOTS_H_ 1

__BEGIN_DECLS

GINNIMPORT ex      exVar;
GINNIMPORT exx     exxp;
GINNIMPORT int     chnum, comport;
GINNIMPORT char    nap[];
GINNIMPORT int     voie;

GINNIMPORT vx      ginn_getvxp(int voie);
GINNIMPORT ex      ginn_getexp(int voie);
GINNIMPORT exx     ginn_getexxp(int voie);
GINNIMPORT void    err_stop (int sig);
GINNIMPORT int     p100(void);
GINNIMPORT int     p900(void);

__END_DECLS
  
//#endif  