#if !defined(GINN_WREGEX_H)
#define GINN_WREGEX_H

#include        "ginn/cdefs.h"

__BEGIN_DECLS

GINNIMPORT      void    wregex_logfp(FILE *fp);
GINNIMPORT      int     wregex_errorcode(void);
GINNIMPORT      int     wregex_matching(char *matchPattern, char *dataString);
GINNIMPORT      int     wregexTranslate(char *matchPattern, char *replacePattern, char *matchFlags, char *dataString, char *translatedString);
GINNIMPORT      int     wregex_translate(char *matchPattern, char *replacePattern, char *dataString, char *translatedString);
GINNIMPORT      int     wregexFileTranslate(char *fileName, char *matchFlags, char *dataString, char *translatedString, int mode);
GINNIMPORT      int     wregex_fileTranslate(char *fileName, char *dataString, char *translatedString, int mode);

__END_DECLS
#endif
