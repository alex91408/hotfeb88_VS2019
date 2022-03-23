#if !defined(GINN_WINDOW_H)
#define GINN_WINDOW_H

enum    {
        F_LEFT_TOP,     F_TOP,          F_RIGHT_TOP,    F_LEFT,
        F_CENTER,       F_RIGHT,        F_LEFT_BOTTOM,  F_BOTTOM,
        F_RIGHT_BOTTOM, F_HORIZENTAL,   F_VERTICAL,     F_CHARACTER
};

enum    {
        FE_SINGLE,      FE_DOUBLE,
        FC_SINGLEA,     FC_SINGLEC,
        FC_DOUBLEA,     FC_DOUBLEC,
        F_TYPE
};

enum    {
        ATTRF_BLACK,    ATTRF_RED,      ATTRF_GREEN,    ATTRF_BROWN,
        ATTRF_BLUE,     ATTRF_MAGENTA,  ATTRF_CYAN,     ATTRF_WHITE,
        ATTRF_GRAY,     ATTRF_LRED,     ATTRF_LGREEN,   ATTRF_YELLOW,
        ATTRF_LBLUE,    ATTRF_LMAGENTA, ATTRF_LCYAN,    ATTRF_HWHITE,
        ATTRB_BLACK,    ATTRB_RED,      ATTRB_GREEN,    ATTRB_BROWN,
        ATTRB_BLUE,     ATTRB_MAGENTA,  ATTRB_CYAN,     ATTRB_WHITE,
        ATTR_NORMAL,    ATTR_LIGHT,     ATTR_UNDERSCORE,ATTR_BLINK,
        ATTR_REVERSE,   ATTR_INVISIBLE, ATTR_UNDERLINE, ATTR_UUNDERLINE,
        ATTR_PFONT,     ATTR_A1FONT,    ATTR_A2FONT,    ATTR_TYPE
};

typedef
        struct  {
        int     x1, y1, x2, y2;
        char    *p;
}       SCRMEM;

#include        "ginn/cdefs.h"
__BEGIN_DECLS

/*
int     active_screen(int no);
int     get_screen(int x1, int y1, int x2, int y2, SCRMEM *buf);
int     put_screen(SCRMEM *buf);
int     keybrd_init(void);
int     keybrd_reset(void);
*/
int     textattr(int color);
void    clrscr(void);
void    clrblk(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, int fore, int back);
void    gotoxy(unsigned int x, unsigned int y);
//void    draw_box(int x1, int y1, int x2, int y2, int fore, int back, int type);
void draw_box(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, int fore, int back, int type);
//void    draw_hline(int x1, int y1, int x2, int y2, int fore, int back, int type);
void    draw_hline(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, int fore, int back, int type);
//void    draw_vline(int x1, int y1, int x2, int y2, int fore, int back, int type);
void    draw_vline(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, int fore, int back, int type);
void    draw_buffer(unsigned int x, unsigned int y, int fore, int back, const char *buf, int len);
int     getfcolor(const char *name);
int     getbcolor(const char *name);
int     getwtype(const char *name);
int     wputch(unsigned char c);
//int     pcgetsw(int x, int y, char *str, int watchlen, int maxlen, int acode1, int acode2, int *keyptr, int beep)
int     pcgetsw(unsigned int, unsigned int, char *, unsigned int, unsigned int, int, int, int *, int);

__END_DECLS
#endif
