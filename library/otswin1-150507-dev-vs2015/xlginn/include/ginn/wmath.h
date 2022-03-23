#if !defined(GINN_WMATH_H)
#define GINN_WMATH_H

#define         DL_MAX          1000000000L
typedef
        struct  {
        long    v[2];
}       DLONG;

#include        "ginn/cdefs.h"
__BEGIN_DECLS

char    *dl_print(DLONG *dl);
DLONG   *dl_assign(DLONG *dl, long x);
DLONG   *dl_add(DLONG *dl, DLONG *p1, DLONG *p2);
DLONG   *dl_sub(DLONG *dl, DLONG *p1, DLONG *p2);

__END_DECLS
#endif
