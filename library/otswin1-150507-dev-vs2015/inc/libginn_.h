#pragma once

#if defined(_XLGINN_VER_)
#define XLGINN_VERSION_ (_XLGINN_VER_ ", ")
#else
#define XLGINN_VERSION_ ""
#endif

#if defined (_USE_GINNLIB_)
#include <wyg/cdefs.h>
#include <wyg/utility.h>
#include <wyg/wcode.h>
#include <wyg/wpbm.h>
#include <wyg/wtiff.h>
#include <wyg/wriff.h>
#pragma comment(lib, "ginn.lib")
#else
#include <ginn/cdefs.h>
#include <ginn/utility.h>
#include <ginn/wcode.h>
#include <ginn/wpbm.h>
#include <ginn/wtiff.h>
#include <ginn/wriff.h>
#pragma comment(lib, "libginn.lib")
#endif
