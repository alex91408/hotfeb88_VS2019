#if !defined(GINN_WSEARCH_H)
#define GINN_WSEARCH_H

#include        "ginn/cdefs.h"
__BEGIN_DECLS

GINNIMPORT      long    wfbsearch(const void *key, char *file, long width, int (*cmp)(const void *, const void *));

__END_DECLS
#endif
