#if !defined(GINN_CGI_H)
#define GINN_CGI_H

#define         CGI_MSGQ        0x01131996
#define         VAR_LEN         128

enum    {
        _V_BRANCH_,
        _V_PATH_,
        _V_DEBUG_,
        _V_LANGUAGE_,
        _V_COMMAND_,
        _V_SHLEVEL_,
        _V_BROWSER_,
        _V_HREF_,
        _V_REMOTE_ADDR_,
        CGI_VAR
};

#define         VAR_OFFSET              (CGI_VAR-1)
#define         D_QUOTE                 '"'
#define         _DEBUG_OFF_             0
#define         _DEBUG_ON_              1
#define         RWORD_BRANCH            "_BRANCH_"
#define         RWORD_PATH              "_PATH_"
#define         RWORD_DEBUG             "_DEBUG_"
#define         RWORD_LANGUAGE          "_LANGUAGE_"
#define         RWORD_COMMAND           "_COMMAND_"
#define         RWORD_SHLEVEL           "_SHLEVEL_"
#define         RWORD_BROWSER           "_BROWSER_"
#define         RWORD_HREF              "_HREF_"
#define         RWORD_REMOTE_ADDR       "_REMOTE_ADDR_"
#define         DEBUG_OFF               "_OFF_"
#define         DEBUG_ON                "_ON_"
#define         VAR_DEFAULT             "</FORM>"
#define         LVD                     strlen(VAR_DEFAULT)
#define         VAR_CONTROL             "<!-- VARIABLE "
#define         LVC                     strlen(VAR_CONTROL)
#define         VAR_CANCEL_ALL          "!ALL -->"
#define         LVCA                    strlen(VAR_CANCEL_ALL)
#define         VAR_CANCEL_SPC          "!SPC -->"
#define         LVCS                    strlen(VAR_CANCEL_SPC)
#define         VAR_SAVE_ALL            "ALL -->"
#define         LVSA                    strlen(VAR_SAVE_ALL)
#define         VAR_SAVE_SPC            "SPC -->"
#define         LVSS                    strlen(VAR_SAVE_SPC)
#define         VAR_CANCEL_ONE          "!V"
#define         LVCO                    strlen(VAR_CANCEL_ONE)
#define         VAR_SAVE_ONE            "V"
#define         LVSO                    strlen(VAR_SAVE_ONE)
#define         VAR_CANCEL__            "!_"
#define         LVC_                    strlen(VAR_CANCEL__)
#define         VAR_SAVE__              "_"
#define         LVS_                    strlen(VAR_SAVE__)

#include        "ginn/cdefs.h"
__BEGIN_DECLS

extern  char    html[];
extern  char    ptr[];
extern  char    str[];
extern  int     _CGI_DEBUG_;
extern  const char    *envvar[];
extern  const char    *rword[];
extern  char    v[][VAR_LEN+2];
extern  int     _max_var;

int     chk_debug();
int     xerror(char *);
int     xprintf(const char *, ...);
int     xprintenv(const char *, int);
int     xprintenvall(int);
int     dec2v(char *, const char *, size_t *);
int     hex2ch(char *, char *);
int     rword2v(char *, char, size_t *);
int     shell_escape(char *, char *);
int     html_escape(char *, char *);
int     xsystem(char *cmd);
int     chk_var();
int     chk_branch();
int     chk_href();
int     get_var(char *, int);
int     get_html();
int     cgimain(int argc, char *argv[]);

__END_DECLS
#endif
