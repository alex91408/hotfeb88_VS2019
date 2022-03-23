#if !defined(GINN_UKEYDEF_H)
#define GINN_UKEYDEF_H

#define         KEY_ALT         0x4e00
#define         K_WYG           0x7fffffff
#define         K_STOP          0x7ffffffe

#define         K_BACKSPACE     0x08
#define         K_TAB           0x09
#define         K_ENTER         0x0d
#define         K_RETURN        K_ENTER
#define         K_ESC           0x1b
#define         K_DELETE        0x7f
#define         K_F1            0x83
#define         K_F2            0x84
#define         K_F3            0x85
#define         K_F4            0x86
#define         K_F5            0x87
#define         K_F6            0x88
#define         K_F7            0x89
#define         K_F8            0x8a
#define         K_F9            0x8b
#define         K_F10           0x8c
#define         K_F11           0x8d
#define         K_F12           0x8e
#define         K_HOME          0xb3
#define         K_UP            0xb4
#define         K_PGUP          0xb5
#define         K_LEFT          0xb7
#define         K_PAD           0xb8
#define         K_RIGHT         0xb9
#define         K_END           0xbb
#define         K_DOWN          0xbc
#define         K_PGDN          0xbd
#define         K_INSERT        0xbe

#define         SCO             0
#define         MITUX           1

//#if !defined(EC_WIN32)
#include        "ginn/cdefs.h"
__BEGIN_DECLS

extern  int     OS_BRAND;

int     con_ioctl_init(int vtime);
int     con_ioctl_reset(void);
int     seq_init(int vtime);
int     seq_reset();
int     kbHit(void);
int     getkey(void);
int     kbhits(void);
int     getkeys(void);
int     user_break(char *exitstr);

__END_DECLS
//#endif
#endif
