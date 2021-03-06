#pragma once

//#if !defined(__GINN__UAPLIB_H__)
//#define __GINN__UAPLIB_H__ 1

enum    {
  GINN_FMT_CONFMESS, GINN_FMT_ADPCM, GINN_FMT_ULAW, GINN_FMT_ALAW,
  GINN_FMT_WAVE_ULAW, GINN_FMT_WAVE_ALAW,GINN_FMT_CONFSYNTH,
  GINN_FMT_MAX
};

enum    {
  GINN_FNM_MESS, GINN_FNM_VOX, GINN_FNM_ULAW, GINN_FNM_ALAW,
  GINN_FNM_WAVE_ULAW, GINN_FNM_WAVE_ALAW,
  GINN_FNM_MAX
};

enum    {
  GINN_FX_NONE = -1, GINN_FX_HDRDISABLE, GINN_FX_HDRFMT1, GINN_FX_HDRFMT2,
  GINN_FX_MH, GINN_FX_MR, GINN_FX_MMR,
  GINN_FX_MH_ECM, GINN_FX_MR_ECM, GINN_FX_MMR_ECM,
  GINN_FX_BASE0, GINN_FX_AUTOPG,
  GINN_FX_AUTO, GINN_FX_MPS, GINN_FX_EOM, GINN_FX_MPG, GINN_FX_EOP,
	GINN_FX_TX, GINN_FX_RX,
  GINN_FX_MAXFX
};

enum    {
  GINN_FT_NORMAL, GINN_FT_VOICEREQ, GINN_FT_ERROR, GINN_FT_ABORT,
  GINN_FT_EVTTOUT, GINN_FT_TIMEOUT, GINN_FT_INVOKE,
  GINN_FT_MAXFT
};

enum    {
        GINN_CR_NONE, GINN_CR_BUSY, GINN_CR_NOANS, GINN_CR_NORB, GINN_CR_CNCT,
        GINN_CR_CEPT, GINN_CR_STOPD, GINN_CR_NODIALTONE, GINN_CR_FAXTONE,
        GINN_CR_ERROR,GINN_CR_UNKNOWN,GINN_CR_MAXCR
};

#define	GINN_FXDF_NONE		0x0000
#define	GINN_FXDF_ISSUE_VRQ	0x0001
#define	GINN_FXDF_PHASEB	0x0002
#define	GINN_FXDF_PHASED	0x0004
#define	GINN_FXDF_RXRESHI	0x0008
#define	GINN_FXDF_TXRESHI	0x0008
#define	GINN_FXDF_RXRESLO	0x0010
#define	GINN_FXDF_TXRESLO	0x0010

//#endif