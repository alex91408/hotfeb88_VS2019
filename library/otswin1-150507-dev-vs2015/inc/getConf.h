//int get_conf0(conf0);
//extern "C" int get_conf0();
//int get_confx(conf,int voie);
//extern "C" int get_confx(int voie);

// for tgm-gcc-4.5.0
#pragma once

#include "libginn_.h"
#include "otsConf.h"			

//#if !defined(_GINN_GETCONF_H_)
//#define _GINN_GETCONF_H_ 1

__BEGIN_DECLS

GINNIMPORT CONFX cf;
GINNIMPORT CONF0 cf0;

GINNIMPORT int get_conf0();
GINNIMPORT int get_confx(int voie);
GINNIMPORT int servMain_get_confx(CONFX *cfPtr, int voie);
GINNIMPORT int checkVoieRange(char *c, size_t i, int *rb);

__END_DECLS
  
//#endif
