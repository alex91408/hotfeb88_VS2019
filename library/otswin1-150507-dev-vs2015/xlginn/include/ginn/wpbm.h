#if !defined(GINN_WPBM_H)
#define GINN_WPBM_H

/*
        form file tag description :

        tags must put at begining of line
        !F : Form feed
             !FoverlapPbmfiles.lst
        !Z : End of form
             !ZoverlapPbmfiles.lst
        !x : set horizontal gap size for 1 byte code
             !x0
        !X : set horizontal gap size for 2 byte code
             !X4
        !Y : set vertical gap size
             !Y4
        !M : variable with multiple loop
             put !V as value of first variable to terminate loop

        tags can put at any position
        !P : put pbmfile
             !Plogo.pbm
        !E : Exclamation mark (!)
        !N : line feed
        !V : put variable
*/

typedef enum    {
        WFT_UNKNOWN,
        WFT_PBM,
        WFT_PGM,
        WFT_PPM,
        WFT_PBM_RAW,
        WFT_PGM_RAW,
        WFT_PPM_RAW
}       WPBM_FILE_TYPES;

typedef struct  pbm_header      {
        WPBM_FILE_TYPES ftype;
        unsigned int             xsize;
        unsigned int             ysize;
        off_t offset;
        size_t length;
}       WPBM_HEADER;

enum    {
        WPBM_TXT2PBM,   WPBM_TXT2G3,    WPBM_TXT2TIFF
};

enum    {
        ASCFONT,        STDFONT,        SPCFONT,        SPCFSUPP,	USERFONT
};

enum    {
        FI_ASCII,       FI_UNICODE,     FI_MAX
};

enum    {
        WPBM_KEEPTMPOFF,         WPBM_KEEPTMPON
};

#define         DOT_LINE        1728
#define         BYTE_LINE       ((DOT_LINE/8)+((DOT_LINE%8)?1:0))
#define         L_MARGIN        0
#define         R_MARGIN        0
#define         MAX_FONTWIDTH   64
#define         MAX_FONTHEIGHT  64
#define         MAX_XGAP        MAX_FONTWIDTH
#define         MAX_YGAP        MAX_FONTHEIGHT
#define         DEF_X1GAP       0
#define         DEF_X2GAP       4
#define         DEF_YGAP        4

#if	defined(EC_WIN32) || defined (_GINN_WIN32_)
#define         DEFAULT_FONTPATH        ".\\pbm\\unicode"
#define         DEFAULT_BIG5UNIC        ".\\pbm\\unicode\\big5unic.dat"
#define         DEFAULT_PBM2G3          ".\\pbm\\bin\\pbm2g3.exe"
#define         DEFAULT_FAX2TIFF        ".\\pbm\\bin\\g32tiff.exe"
#else
#define         DEFAULT_FONTPATH        "./pbm/unicode"
#define         DEFAULT_BIG5UNIC        "./pbm/unicode/big5unic.dat"
#define         DEFAULT_PBM2G3          "./pbm/bin/pbm2g3"
#define         DEFAULT_FAX2TIFF        "./pbm/bin/g32tiff"
#endif
//#define         DEFAULT_ASCFONT         "mingliu36x20.pbm"
//#define         DEFAULT_UNICFONT        "mingliu36u.pbm"
#define         DEFAULT_ASCFONT         "ascii.pbm"
#define         DEFAULT_UNICFONT        "unicode.pbm"
#define         DEFAULT_FAX2TIFFOPT     "-M -1 -m"
#define         DEFAULT_ESCCHAR         '!'

#include        "ginn/cdefs.h"
__BEGIN_DECLS

GINNIMPORT      off_t   wpbm_getheader(const char *name, WPBM_HEADER *p);
GINNIMPORT      unsigned int     wpbm_xbyte(unsigned int xsize);
GINNIMPORT      off_t   wpbm_validrawpbm(const char *name, WPBM_HEADER *p);
GINNIMPORT      void    wpbm_logfp(FILE *fp);
GINNIMPORT      void    wpbm_fontpath(const char *p);
GINNIMPORT      void    wpbm_ascfont(const char *p);
GINNIMPORT      void    wpbm_unicfont(const char *p);
GINNIMPORT      void    wpbm_big5unic(const char *p);
GINNIMPORT      void    wpbm_pbm2g3(const char *p);
GINNIMPORT      void    wpbm_fax2tiff(const char *p);
GINNIMPORT      void    wpbm_fax2tiffopt(const char *p);
GINNIMPORT      void    wpbm_x1gap(unsigned int x);
GINNIMPORT      void    wpbm_x2gap(unsigned int x);
GINNIMPORT      void    wpbm_ygap(unsigned int y);
GINNIMPORT      void    wpbm_esc_char(unsigned char c);
GINNIMPORT      void    wpbm_keeptmpfile(int flag);
GINNIMPORT	int     wpbm_isBig5Code(unsigned char big5H, unsigned char big5L);
GINNIMPORT      int     wpbm_overlappbm(const char *dstpbm, const char *sx, const char *sy, const char *srcpbm);
GINNIMPORT      int     wpbm_overlaplist(const char *dstpbm, const char *srclist);
GINNIMPORT      int     wpbm_txt2pbm(const char *srcfile, const char *varfile, const char *datfile, int action);

__END_DECLS
#endif
