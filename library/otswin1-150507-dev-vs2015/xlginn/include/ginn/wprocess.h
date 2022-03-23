#if !defined(GINN_WPROCESS_H)
#define GINN_WPROCESS_H

#include        "ginn/cdefs.h"
__BEGIN_DECLS

int     ginn_fork(void);
int     ginn_waitpid(void);
int     wpgrp(void);
int     wsystem(char *cmd);

__END_DECLS
#endif
