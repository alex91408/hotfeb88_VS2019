

//20220224 add
//#define CRT_SECURE_NO_WARNINGS           //20220224 



#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <io.h>
#include <time.h>
#include <stdarg.h>

#include "fcontrol.h"
#include "wlog.h"
#include "parprog.h"



//20220225 new
//#include "wrtLog.h"
extern int _gLineno;



/*
typedef struct {
  char *name;
  int  (*func)();
} UAP;
*/

extern ex   exp;    /* for exvar */
extern exx  exxp;

//20220225 old 
//extern vx   vxp;    /* for fcontrol */

//20220225 new 
vx   vxp;    /* for fcontrol */

//#define _FDBPRINTF_
#if defined(_FDBPRINTF_)
extern  void fdbprintf(const char *fmt,...);
//extern FILE *fdbfd;
#endif

log lgp;


//20220225 old
//extern long     lt;
//extern struct   tm *tm;

//20220225 new
extern long     lt;
extern struct   tm *tm;

//20220225 new
extern int _gLineno;



#define N_DAY_BEFORE  180
#define MAX_BYTE_ONE_LINE 500

extern char* gIvrIniFile;
int gMaxDay = 0;


// in this function, CAN NOT use wrtLog function,


int deleteNDayBefore(time_t now, int nDay)
{
  char xLogFyName[256];
  struct tm nDayBefore;

  //if (0 == gMaxDay) {
  //  gMaxDay = GetPrivateProfileInt("KEEP_LOG_DAY", "maxDay", nDay, gIvrIniFile);
  //}
  //time_t nDayBeforeSec = now - ((long)gMaxDay * 86400L);

  //20220224 old time_t nDayBeforeSec = now - ((long)nDay * 86400L);
  time_t nDayBeforeSec = now - (static_cast<long long>((long)nDay) * 86400L);

  //20220224 old 
  //nDayBefore = *localtime(&nDayBeforeSec);
  
  //20220224 new
  //time_t now = 0;
  //struct tm newTime {};
  //time(&now);

  errno_t errNoT = localtime_s(&nDayBefore, &nDayBeforeSec);





  //20220224 old sprintf(xLogFyName, ".\\log_feb88\\%04d%02d%02d.txt", nDayBefore.tm_year + 1900,
  sprintf_s(xLogFyName, ".\\log_feb88\\%04d%02d%02d.txt", nDayBefore.tm_year + 1900,
                                         nDayBefore.tm_mon + 1,
                                         nDayBefore.tm_mday);

  //time(&lt);
  //tm = localtime(&lt);
  //conv_time();

  if (_access(xLogFyName, 0) == -1) {
    // YYYYMMDD.txt not exist
    return 0;
  }

  // delete nDay before file
  //sprintf(vxp->message, "<<%s>>", xLogFyName);
  _unlink(xLogFyName);

  return 1;
}


int wrtLog(const char* format, ...)
{
  time_t now;
  struct tm newTime, myOldTm;
  int ofy;
  char logFyName[256], wrtBuf[8 * 1024] = {0}, tmpWrtBuf[8 * 1024] = {0};

  myOldTm = *tm;  // backup tm

  //20220224 old
  //time(&now);
  //newTime = *localtime(&now);

  //20220224 new
  //time_t now=0;
  //struct tm newTime {};
  time(&now);
  errno_t errNoT = localtime_s(&newTime, &now);




  deleteNDayBefore(now, N_DAY_BEFORE);
  //20220224 old sprintf(logFyName, ".\\log_feb88\\%04d%02d%02d.txt", newTime.tm_year + 1900,
  sprintf_s(logFyName, ".\\log_feb88\\%04d%02d%02d.txt", newTime.tm_year + 1900,
                                         newTime.tm_mon + 1,
                                         newTime.tm_mday);

  if (_access(logFyName, 0) == -1) {
    // YYYYMMDD.txt not exist, create it
    //20220224 old 
    //  ofy = _open(logFyName, O_CREAT|O_RDWR, S_IREAD|S_IWRITE);
 
    //20220224 new       , _O_RDWR, _SH_DENYNO,
      
    errno_t myErrNoT = _sopen_s(&ofy, logFyName, O_CREAT | O_RDWR, _SH_DENYNO, S_IREAD | S_IWRITE );
    //  //fdbprintf("myErrNoT=[%d]", myErrNoT);
    //
    if (myErrNoT != 0)
    {  //err
    }
  }
  else {
    //20220224 old 
    // ofy = _open(logFyName, O_APPEND|O_RDWR);

    //20220224 new
      //errno_t myErrNoT = _sopen_s(&ofy, logFyName, O_APPEND | O_RDWR);
      errno_t myErrNoT = _sopen_s(&ofy, logFyName, O_APPEND | O_RDWR, _SH_DENYNO, S_IREAD | S_IWRITE);
      
      //  //fdbprintf("myErrNoT=[%d]", myErrNoT);
      //
      if (myErrNoT != 0)
      {  //err
      }

  }

  if (ofy == -1) {

#if defined(_FDBPRINTF_)
    fdbprintf( "Cannot open %s. %s(%i)\n", logFyName, __FILE__, __LINE__);
#endif

    *tm = myOldTm;  // restore tm

    return ofy;
  }

  {
    char flowName[8] = {0};

    memcpy(flowName, vxp->applic, sizeof(vxp->applic));
    //20220224 old sprintf(tmpWrtBuf, (0 == vxp->branch) ?
    sprintf_s(tmpWrtBuf, (0 == vxp->branch) ?
                         "%02d:%02d:%02d %02d %s(L%3d) " :
                         "%02d:%02d:%02d %02d %s(%4d) ",
                                                       newTime.tm_hour,
                                                       newTime.tm_min,
                                                       newTime.tm_sec,
                                                       vxp->voie,
                                                       flowName,
                             (0 == vxp->branch) ? _gLineno : vxp->branch);

  }

  {
    va_list ap;

    va_start(ap, format);

    //20220224 old vsprintf(wrtBuf, format, ap);
    vsprintf_s(wrtBuf, format, ap);

    //20220224 old strcat(tmpWrtBuf, wrtBuf);
    strcat_s(tmpWrtBuf, wrtBuf);

    va_end(ap);
  }

#ifdef MAX_BYTE_ONE_LINE
  {
    int i, myLen, lastPos = 0;

    myLen = strlen(tmpWrtBuf);

    for (i = 0; i < myLen / MAX_BYTE_ONE_LINE; i++) {
      char myTmp[1024] = {0};

      if (i == 0) {
        memcpy(myTmp, &tmpWrtBuf[i * MAX_BYTE_ONE_LINE], MAX_BYTE_ONE_LINE);
      }
      else {

          //20220224 old strcpy(myTmp, "____");
        strcpy_s(myTmp, "____");
        
        memcpy(&myTmp[strlen(myTmp)], &tmpWrtBuf[i * MAX_BYTE_ONE_LINE], MAX_BYTE_ONE_LINE);
      }
      lastPos += MAX_BYTE_ONE_LINE;

      _write(ofy, myTmp, strlen(myTmp));
      _write(ofy, "\n", strlen("\n"));
    }

    if (i == 0) {
      _write(ofy, tmpWrtBuf, strlen(tmpWrtBuf));
    }
    else if (strlen(&tmpWrtBuf[lastPos]) != 0) {
      char myTmp[1024] = {0};

      //20220224 old strcpy(myTmp, "____");
      strcpy_s(myTmp, "____");
      memcpy(&myTmp[strlen(myTmp)], &tmpWrtBuf[lastPos], myLen - lastPos);
      _write(ofy, myTmp, strlen(myTmp));
    }
  }
#else
  _write(ofy, tmpWrtBuf, strlen(tmpWrtBuf));
#endif

  _close(ofy);

  *tm = myOldTm;  // restore tm

  return strlen(tmpWrtBuf);
}


int wrtLogByLen(char* buf, int len, const char* apName, int apLine)
{
  int ofy, i;
  time_t now;
  struct tm myTm, myOldTm;
  char fyName[64], wrtEndBuf[128] = {0}, tmpWrtBuf[8 * 1024] = {0};

  myOldTm = *tm; // backup tm

  //20220224 old
  //time(&now);
  //myTm = *localtime(&now);

  //20220224 new
  //time_t now = 0;
  struct tm newTime {};
  time(&now);
  errno_t errNoT = localtime_s(&myTm, &now);



  deleteNDayBefore(now, N_DAY_BEFORE);

  //20220224 old sprintf(fyName, ".\\log_feb88\\%04d%02d%02d.txt", myTm.tm_year + 1900,
  sprintf_s(fyName, ".\\log_feb88\\%04d%02d%02d.txt", myTm.tm_year + 1900,
                                      myTm.tm_mon + 1,
                                      myTm.tm_mday);

  //20220224 old 
  //ofy = _open(fyName, O_CREAT|O_APPEND|O_RDWR, 0666);

  //20220224 new
      //errno_t myErrNoT = _sopen_s(&ofy, logFyName, O_APPEND | O_RDWR);
  errno_t myErrNoT = _sopen_s(&ofy, fyName, O_CREAT | O_APPEND | O_RDWR, _SH_DENYNO, S_IREAD | S_IWRITE);

  //  //fdbprintf("myErrNoT=[%d]", myErrNoT);
  //
  if (myErrNoT != 0)
  {  //err
  }

  if (ofy == -1) {

#if defined(_FDBPRINTF_)
    fdbprintf( "Cannot open %s. %s(%i)\n", fyName, __FILE__, __LINE__);
#endif

    *tm = myOldTm; // restore tm

    return 0;
  }

  {
    char flowName[8] = {0};

    memcpy(flowName, vxp->applic, sizeof(vxp->applic));
    //20220224 old sprintf(tmpWrtBuf, (0 == vxp->branch) ?
    sprintf_s(tmpWrtBuf, (0 == vxp->branch) ?
                         "%02d:%02d:%02d %02d %s(L%3d) [" :
                         "%02d:%02d:%02d %02d %s(%4d) [",
                                                        myTm.tm_hour,
                                                        myTm.tm_min,
                                                        myTm.tm_sec,
                                                        vxp->voie,
                                                        flowName,
                             (0 == vxp->branch) ? _gLineno : vxp->branch);
  }

  for (i = 0; i < len; i++) {
    char tmpBuf[8] = {0};

    //20220224 old sprintf(tmpBuf, ((unsigned int)buf[i] < 0x20 || (unsigned int)buf[i] >= 0x7f)? "<%02X>" : "%c", (unsigned char)buf[i]);
    sprintf_s(tmpBuf, ((unsigned int)buf[i] < 0x20 || (unsigned int)buf[i] >= 0x7f)? "<%02X>" : "%c", (unsigned char)buf[i]);
    //printf("%d, [%s]\r\n", i, tmpBuf);
    // 
    //20220224 old strcat(tmpWrtBuf, tmpBuf);
    strcat_s(tmpWrtBuf, tmpBuf);
  }

  //20220224 old sprintf(wrtEndBuf, "] %s(%i)\n", apName, apLine);
  sprintf_s(wrtEndBuf, "] %s(%i)\n", apName, apLine);

  //20220224 old strcat(tmpWrtBuf, wrtEndBuf);
  strcat_s(tmpWrtBuf, wrtEndBuf);

#ifdef MAX_BYTE_ONE_LINE
  {
    int i, myLen, lastPos = 0;

    myLen = strlen(tmpWrtBuf);

    for (i = 0; i < myLen / MAX_BYTE_ONE_LINE; i++) {
      char myTmp[1024] = {0};

      if (i == 0) {
        memcpy(myTmp, &tmpWrtBuf[i * MAX_BYTE_ONE_LINE], MAX_BYTE_ONE_LINE);
      }
      else {
          //20220224 old strcpy(myTmp, "____");
        strcpy_s(myTmp, "____");
        memcpy(&myTmp[strlen(myTmp)], &tmpWrtBuf[i * MAX_BYTE_ONE_LINE], MAX_BYTE_ONE_LINE);
      }
      lastPos += MAX_BYTE_ONE_LINE;

      _write(ofy, myTmp, strlen(myTmp));
      _write(ofy, "\n", strlen("\n"));
    }

    if (i == 0) {
      _write(ofy, tmpWrtBuf, strlen(tmpWrtBuf));
    }
    else if (strlen(&tmpWrtBuf[lastPos]) != 0) {
      char myTmp[1024] = {0};

      //20220224 old strcpy(myTmp, "____");
      strcpy_s(myTmp, "____");

      memcpy(&myTmp[strlen(myTmp)], &tmpWrtBuf[lastPos], myLen - lastPos);
      _write(ofy, myTmp, strlen(myTmp));
    }
  }
#else
  _write(ofy, tmpWrtBuf, strlen(tmpWrtBuf));
#endif

  _close(ofy);

  *tm = myOldTm; // restore tm

  return strlen(tmpWrtBuf);
}

int wrtLogByLenX(const char* mark, char* buf, int len, const char* apName, int apLine)
{
  int ofy, i;
  time_t now;
  struct tm myTm, myOldTm;
  char fyName[64], wrtEndBuf[128] = {0}, tmpWrtBuf[8 * 1024] = {0};

  myOldTm = *tm; // backup tm

  //20220224 old 
  //time(&now);
  //myTm = *localtime(&now);


  //20220224 new
  //time_t now = 0;
  struct tm newTime {};
  time(&now);
  errno_t errNoT = localtime_s(&myTm, &now);


  deleteNDayBefore(now, N_DAY_BEFORE);

  //20220224 old sprintf(fyName, ".\\log_feb88\\%04d%02d%02d.txt", myTm.tm_year + 1900,
  sprintf_s(fyName, ".\\log_feb88\\%04d%02d%02d.txt", myTm.tm_year + 1900,
                                      myTm.tm_mon + 1,
                                      myTm.tm_mday);
  
  //20220224 old 
  //ofy = _open(fyName, O_CREAT|O_APPEND|O_RDWR, 0666);

  //20220224 new
      //errno_t myErrNoT = _sopen_s(&ofy, logFyName, O_APPEND | O_RDWR);
  errno_t myErrNoT = _sopen_s(&ofy, fyName, O_CREAT|O_APPEND|O_RDWR, _SH_DENYNO, S_IREAD | S_IWRITE);

  //  //fdbprintf("myErrNoT=[%d]", myErrNoT);
  //
  if (myErrNoT != 0)
  {  //err
  }



  if (ofy == -1) {

#if defined(_FDBPRINTF_)
    fdbprintf( "Cannot open %s. %s(%i)\n", fyName, __FILE__, __LINE__);
#endif

    *tm = myOldTm; // restore tm

    return 0;
  }

  {
    char flowName[8] = {0};

    memcpy(flowName, vxp->applic, sizeof(vxp->applic));
    //20220224 old sprintf(tmpWrtBuf, (0 == vxp->branch) ?
    sprintf_s(tmpWrtBuf, (0 == vxp->branch) ?
                         "%02d:%02d:%02d %02d %s(L%3d) %s[" :
                         "%02d:%02d:%02d %02d %s(%4d) %s[",
                                                        myTm.tm_hour,
                                                        myTm.tm_min,
                                                        myTm.tm_sec,
                                                        vxp->voie,
                                                        flowName,
                             (0 == vxp->branch) ? _gLineno : vxp->branch,
                                                        mark);
  }

  for (i = 0; i < len; i++) {
    char tmpBuf[8] = {0};

    if ('H' == mark[0])
        //20220224 old sprintf(tmpBuf, "<%02X>", (unsigned char)buf[i]);
      sprintf_s(tmpBuf, "<%02X>", (unsigned char)buf[i]);
    else
        //20220224 old sprintf(tmpBuf, ((unsigned int)buf[i] < 0x20 || (unsigned int)buf[i] >= 0x7f)? "<%02X>" : "%c", (unsigned char)buf[i]);
      sprintf_s(tmpBuf, ((unsigned int)buf[i] < 0x20 || (unsigned int)buf[i] >= 0x7f)? "<%02X>" : "%c", (unsigned char)buf[i]);

    //printf("%d, [%s]\r\n", i, tmpBuf);
    //20220224 old strcat(tmpWrtBuf, tmpBuf);
    strcat_s(tmpWrtBuf, tmpBuf);
  }

  //20220224 old sprintf(wrtEndBuf, "] %s(%i)\n", apName, apLine);
  sprintf_s(wrtEndBuf, "] %s(%i)\n", apName, apLine);

  //20220224 old strcat(tmpWrtBuf, wrtEndBuf);
  strcat_s(tmpWrtBuf, wrtEndBuf);

#ifdef MAX_BYTE_ONE_LINE
  {
    int i, myLen, lastPos = 0;

    myLen = strlen(tmpWrtBuf);

    for (i = 0; i < myLen / MAX_BYTE_ONE_LINE; i++) {
      char myTmp[1024] = {0};

      if (i == 0) {
        memcpy(myTmp, &tmpWrtBuf[i * MAX_BYTE_ONE_LINE], MAX_BYTE_ONE_LINE);
      }
      else {
          //20220224 old strcpy(myTmp, "____");
        strcpy_s(myTmp, "____");

        memcpy(&myTmp[strlen(myTmp)], &tmpWrtBuf[i * MAX_BYTE_ONE_LINE], MAX_BYTE_ONE_LINE);
      }
      lastPos += MAX_BYTE_ONE_LINE;

      _write(ofy, myTmp, strlen(myTmp));
      _write(ofy, "\n", strlen("\n"));
    }

    if (i == 0) {
      _write(ofy, tmpWrtBuf, strlen(tmpWrtBuf));
    }
    else if (strlen(&tmpWrtBuf[lastPos]) != 0) {
      char myTmp[1024] = {0};

      //20220224 old strcpy(myTmp, "____");
      strcpy_s(myTmp, "____");

      memcpy(&myTmp[strlen(myTmp)], &tmpWrtBuf[lastPos], myLen - lastPos);
      _write(ofy, myTmp, strlen(myTmp));
    }
  }
#else
  _write(ofy, tmpWrtBuf, strlen(tmpWrtBuf));
#endif

  _close(ofy);

  *tm = myOldTm; // restore tm

  return strlen(tmpWrtBuf);
}

int wrtLogUapName(int lineNo, char* format, ...)
{
  time_t now;
  struct tm newTime, myOldTm;
  int ofy;
  char logFyName[256], wrtBuf[8 * 1024] = {0}, tmpWrtBuf[8 * 1024] = {0};

  myOldTm = *tm;  // backup tm

  //20220224 old 
  //time(&now);
  //newTime = *localtime(&now);

  //20220224 new
  //time_t now = 0;
  //struct tm newTime {};
  time(&now);
  errno_t errNoT = localtime_s(&newTime, &now);



  // deleteNDayBefore(now, N_DAY_BEFORE);
  //20220224 old sprintf(logFyName, ".\\log_feb88\\%04d%02d%02d_%02d.txt", newTime.tm_year + 1900,
  sprintf_s(logFyName, ".\\log_feb88\\%04d%02d%02d_%02d.txt", newTime.tm_year + 1900,
                                              newTime.tm_mon + 1,
                                              newTime.tm_mday,
                                              lineNo);

  if (_access(logFyName, 0) == -1) {
    // YYYYMMDD.txt not exist, create it
   //20220224 old
   // ofy = _open(logFyName, O_CREAT|O_RDWR, S_IREAD|S_IWRITE);

//20220224 new
      errno_t myErrNoT = _sopen_s(&ofy, logFyName, O_CREAT|O_RDWR, _SH_DENYNO, S_IREAD | S_IWRITE);

      //  //fdbprintf("myErrNoT=[%d]", myErrNoT);
      //
      if (myErrNoT != 0)
      {  //err
      }


  }
  else {
    
      
   //20220224 
   //   old    ofy = _open(logFyName, O_APPEND|O_RDWR);

//20220224 new
      errno_t myErrNoT = _sopen_s(&ofy, logFyName, O_APPEND|O_RDWR, _SH_DENYNO, S_IREAD | S_IWRITE);

      //  //fdbprintf("myErrNoT=[%d]", myErrNoT);
      //
      if (myErrNoT != 0)
      {  //err
      }


  }

  if (ofy == -1) {
    *tm = myOldTm;  // restore tm
    return ofy;
  }

  {
    char flowName[8] = {0};

    memcpy(flowName, vxp->applic, sizeof(vxp->applic));
    //20220224 old sprintf(tmpWrtBuf, (0 == vxp->branch) ?
    sprintf_s(tmpWrtBuf, (0 == vxp->branch) ?
                         "%02d:%02d:%02d %s-L%d " : "%02d:%02d:%02d %s-%d ",
                         newTime.tm_hour,
                         newTime.tm_min,
                         newTime.tm_sec,
                         flowName,
                         (0 == vxp->branch) ? lineNo : vxp->branch);

  }

  {
    va_list ap;

    va_start(ap, format);

    //20220224 old vsprintf(wrtBuf, format, ap);
    vsprintf_s(wrtBuf, format, ap);

    //20220224 old strcat(tmpWrtBuf, wrtBuf);
    strcat_s(tmpWrtBuf, wrtBuf);

    va_end(ap);
  }

#ifdef MAX_BYTE_ONE_LINE
  {
    int i, myLen, lastPos = 0;

    myLen = strlen(tmpWrtBuf);

    for (i = 0; i < myLen / MAX_BYTE_ONE_LINE; i++) {
      char myTmp[1024] = {0};

      if (i == 0) {
        memcpy(myTmp, &tmpWrtBuf[i * MAX_BYTE_ONE_LINE], MAX_BYTE_ONE_LINE);
      }
      else {
          //20220224 old strcpy(myTmp, "____");
        strcpy_s(myTmp, "____");

        memcpy(&myTmp[strlen(myTmp)], &tmpWrtBuf[i * MAX_BYTE_ONE_LINE], MAX_BYTE_ONE_LINE);
      }
      lastPos += MAX_BYTE_ONE_LINE;

      _write(ofy, myTmp, strlen(myTmp));
      _write(ofy, "\n", strlen("\n"));
    }

    if (i == 0) {
      _write(ofy, tmpWrtBuf, strlen(tmpWrtBuf));
    }
    else if (strlen(&tmpWrtBuf[lastPos]) != 0) {
      char myTmp[1024] = {0};

      //20220224 old strcpy(myTmp, "____");
      strcpy_s(myTmp, "____");

      memcpy(&myTmp[strlen(myTmp)], &tmpWrtBuf[lastPos], myLen - lastPos);
      _write(ofy, myTmp, strlen(myTmp));
    }
  }
#else
  _write(ofy, tmpWrtBuf, strlen(tmpWrtBuf));
#endif

  _close(ofy);

  *tm = myOldTm;  // restore tm

  return strlen(tmpWrtBuf);
}
