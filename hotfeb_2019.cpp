//----------------------------------------------------------------------------------------------
// 每次更改請在此區註解    最新放最上面 CHING2  p400()  
// ver 要改   #define VERSION XXXX   每次異動版本需要修改
//
//----------------------------------------------------------------------------------------------

#define VERSION1   "20220304 V6.50 vs2019 "



//20220304 V6.5 ching2  E692 E690 mode    Now HOST UNISYS is mode 1   bug
//20220303 V6.4 ching2  modify hotfeb 弱掃
//20220302 V6.3 ching2  modify hotfeb 弱掃
//20220302 V6.2 ching2  modify wrtLog.cpp 因編譯無法過, 移到 hotfeb_2019.cpp 中
//20220218 V6.1 ching2  modify hotfeb for VS2019  及弱掃

//

//1060209 ching2  exVar 無法使用 要在 main 指定  exVar = exVar;
//1060327 exVar = exVar; bug  需在 P100() 以後, 否則chk_exe_emis() 會當


// V1.44  1070522  ching2    p400() add fdb_check_rotate();  for  dbg058 --> dbg058.dd      

// 以 hotdbg(hotpar 中 fprintf(1:yes, 0 : no)     CBA) 控制 debug 的參數
// A 為 '0' 時, vxp->dbg 為 'N', 否則 vxp->dbg 為 'Y'
// B 為 '0' 時, 用 fdbopenf(), 否則用 fdbopenfr()
// C 為 '1' 時, vxp->dbgTimeStamp 為 '1', fdbprintf() 加印 "YYYY-MM-DD hh:mm:ss ==> "// C 為 '2' 時, vxp->dbgTimeStamp 為 '2', fdbprintf() 加印 "YYYY-MM-DD hh:mm:ss.uuuuuu 

//otsconf  --> hotepar59     fprintf(1:yes,0:no) 	011    



//

//1060209 ching2  exVar 無法使用 要在 main 指定  exVar = exVar;
//1060327 exVar = exVar; bug  需在 P100() 以後, 否則chk_exe_emis() 會當


// V1.44  1070522  ching2    p400() add fdb_check_rotate();  for  dbg058 --> dbg058.dd      

// 以 hotdbg(hotpar 中 fprintf(1:yes, 0 : no)     CBA) 控制 debug 的參數
// A 為 '0' 時, vxp->dbg 為 'N', 否則 vxp->dbg 為 'Y'
// B 為 '0' 時, 用 fdbopenf(), 否則用 fdbopenfr()
// C 為 '1' 時, vxp->dbgTimeStamp 為 '1', fdbprintf() 加印 "YYYY-MM-DD hh:mm:ss ==> "// C 為 '2' 時, vxp->dbgTimeStamp 為 '2', fdbprintf() 加印 "YYYY-MM-DD hh:mm:ss.uuuuuu 

//otsconf  --> hotepar59     fprintf(1:yes,0:no) 	011    



//1090211 以下為弱掃參考

//1.  sprintf()  --> sprintf_s(A , sizeof(A), );
//2.  sscanf()   --> sscanf_s( , "%s " ,A , sizeof(A) )
//3.  strcat()   --> strcat_s(A , sizeof(A), );
//4.  memcpy()   --> memcpy_s(A , sizeof(A), );
//5.  _sopen()   --> _sopen_s(&

//  //fh = _sopen("D:\\otsfax\\URL_LOG_API\\000_API_Lock.txt", _O_RDWR, _SH_DENYNO, _S_IREAD | _S_IWRITE);
//  errno_t myErrNoT = _sopen_s(&fh, "D:\\otsfax\\URL_LOG_API\\000_API_Lock.txt", _O_RDONLY, _SH_DENYNO, _S_IREAD | _S_IWRITE);
//  //fdbprintf("myErrNoT=[%d]", myErrNoT);
//
//  if (myErrNoT != 0)
//  {  err

//6.  fopen()    --> errno_t myErrNoT = fopen_s(

//    if ((fd = fopen(tmp, "r")) == NULL) {
// 改
//    errno_t myErrNoT = fopen_s(&fd, "./conf/hotchk.txt", "r");     //1060211 原 hotchk 改讀 hotchk.txt
//    if (myErrNoT != 0)

//1090121 show_dbg有執行LOG，會咬住log檔無法寫檔，改
//    //1090106 old 
//    //if ((fp = fopen(sFile, "a")) == NULL)
//    //1090121 old 讀取檔案失敗bug
//    //errno_t myErrNoT = fopen_s(&fp, sFile, "a");
//    if ((fp = _fsopen(sFile, "a", _SH_DENYWR)) == NULL)

//7.  strcpy()   --> strcpy_s(A , sizeof(A), );
//8.  strncpy()   --> strncpy_s(A , sizeof(A), );

//9.  ctime      --> 改成下面
//
//OLD
//
//  struct   tm *tm;
//  long     lt;
//  time(&lt);
//  tm = localtime(&lt);
//  tm->tm_year - 11, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec

//1060211 new
//  time_t now;
//  struct tm newTime;
//  time(&now);
//    errno_t errNoT = localtime_s(&newTime, &now);

//  newTime.tm_year - 11, newTime.tm_mon + 1, newTime.tm_mday, newTime.tm_hour, newTime.tm_min, newTime.tm_sec
//

//  now += (-60 * 60 * 24);    //bofore day      //開前一天 只有這裏不同  1060217 by ching2
//  errno_t errNoT1 = localtime_s(&now_tm, &now);
//  now_tm.tm_year + 1900, now_tm.tm_mon + 1, now_tm.tm_mday, now_tm.tm_hour, now_tm.tm_min


// 1060211 new
// time_t now;
// struct tm now_tm;
// time(&now);
// errno_t errNoT = localtime_s(&now_tm, &now);
// //now_tm.tm_year - 11, now_tm.tm_mon + 1, now_tm.tm_mday, now_tm.tm_hour, now_tm.tm_min, now_tm.tm_sec


//10.strlen(fax_v25) --> strnlen_s(fax_v25, sizeof(fax_v25)

//11._itoa(iTemp, d, 10) --> _itoa_s(iTemp, d, sizeof(d), 10);


//12.system() --> system_new(scmd)

//int  system_new(char *scmd)
//{
//	FILE *pPipe = NULL;
//
//	if ((pPipe = _popen(scmd, "rt")) == NULL)
//	{
//		printf("執行失敗. %s-%s(%d)\r\n", __FILE__, __FUNCTION__, __LINE__);
//		return(-1);
//	}
//	else
//	{
//		printf("執行成功. %s-%s(%d)\r\n", __FILE__, __FUNCTION__, __LINE__);
//		_pclose(pPipe);
//		return(0);
//	}
//}

//13.fscanf() --> fscanf_s( , "%s " ,A , sizeof(A) )
//14.strtok() --> strtok_s()

// //1081230 new 
// char* next_token;

// //1081230 old 
// //token = strtok(temp1, seps); 
// token = strtok_s(temp1, seps, &next_token);  

// fdbprintf("[token]=[%s] \r\n", token );
// //1081230 old
// //token = strtok(NULL, seps);   
// token = strtok_s(NULL, seps, &next_token);  



// ver     date    user      meno
// ------ -------- --------- -------------------------------------------------------
//
// v1.3  1030815   jcwang    E691 send again 2014-08-15
// v1.2  1000406   sven      不檢查是否有資料要繼續下來(buf[19]= '1'), 已檢查過error code  
// v1.1   971211   ching2    add p400()  write ./moni/Lxx.txt for hotmoni
// v1.0   971211   ching2    old ver

// fund and transId mapping file is "TranId.dat"

//#define _OTS_FOR_TEST      -D _OTS_FOR_TEST

/*
* minor  /dev/sync01  Modify 1999/10/08             Copyright   - Dong Dong - *
*        complier batch : clfe88 Address : 0x41, 0x42  port 0   -  Shirley  - *
*        Address 0x41  : On-Line  ,  0x42  : Off-Line                         *
* add genman 920923 get total acc & pwd check                                 *
*/
//960911 kajfkpcst modify hdlc->tcpip
//verson 1.0 960920 bamer
//verson 1.1 960928
//verson 1.2 961029
//verson 1.3 961031 FOR TEST MODE_ASSIGN=2->1
//verson 1.4 961102 for add 2 len data before tota
//verson 1.5 961106 for modify mark intrest,exchange and fund 5 len
//verson 1.6 961107 for modify in trade=K62 TXCD=K61->K60
//verson 1.7 961108 for modify when tson=7 ,mode=4->1
//verson 1.8 961115 for intrest test_one_send       
//verson 1.9 961121 for int and ex bug
//verson 2.0 961214 for trans=k10 vuk->vup  
//verson 2.1 961222 add trade=g52,g53  
//verson 2.2 970102 add for change mod

// 970103 add for upload root history  







////1070224 add  

#define NO_WARN_MBCS_MFC_DEPRECATION           //1070224 ching2 add warning C4996: 'MBCS_Support_Deprecated_In_MFC': MBCS  support in MFC is deprecated and may be removed in a future version of MFC.



#include  <stdio.h>
#include  <stdlib.h> 
#include  <signal.h>
#include  <fcntl.h>
#include  <sys/types.h>
#include  <process.h>       //2008 new netbank
#include  <sys/stat.h>
#include  <io.h>
#include  <share.h>
#include  <sys/locking.h>

#include  <afx.h> 
#include  <afxdb.h>

#include "datalink.h"       // for database

#include  <string.h>
#include  <time.h>          // for difftime

//20220225 old #include  <libginn_.h>

//20220225 old 
//#if defined (_USE_GINNLIB_)
//#include  <wyg/wselect.h>
//#include  <wyg/wsocket.h>
//#include  <wyg/wicmp.h>
//20220208 OLD #include  <wyg/wtcp.h>
//#else
////20220225 old #include  <ginn/wselect.h>
////20220225 old #include  <ginn/wsocket.h>
////20220225 old #include  <ginn/wicmp.h>
////20220208 OLD #include  <ginn/wtcp.h>
//#endif

#include <hots.h>





#include  <parprog.h>
#include  <fcontrol.h>
#include  <otsconf.h>

#include <direct.h>               // _chdir()       //V2.39

//#include  "datalink.h"						// for dblink

//20220208 OLD #include "hotLOG.h"


//20220225 old 
//#include <wyg/utility.h>
#include <wyg/wtcp.h>
//#include <wyg/wcode.h>



//20220225 add 
//#define _GLINENO
//#include "wrtLog.h"

int _gLineno;      



//extern int wrtLog(const char* format, ...);
//extern int wrtLogByLen(char* buf, int len, const char* apName, int apLine);
//extern int wrtLogByLenX(const char* mark, char* buf, int len, const char* apName, int apLine);
//extern int wrtLogUapName(int lineNo, char* format, ...);




long     lt;
struct   tm* tm;


typedef unsigned char   uchar;
//typedef unsigned char   BYTE;


//-----------------------------------------------------------------------------
// for trol kernel
//-----------------------------------------------------------------------------

extern  void err_stop(int);
extern  int  p100(void);
extern  int  p900(void);
extern  void fdbprintf(const char *fmt, ...);
//extern  vx	    vxp;
//ex exVar;

//20220208 NEW
//extern  ex      exVar;




// V2.33
int       DB2Stop = 0;


//-----------------------------------------------------------------------------
// for trol kernel end
//-----------------------------------------------------------------------------







int			chk_pos;














//-----------------------------------------------------------------------------
// 本程使用
//-----------------------------------------------------------------------------

char sTemp[9000];

//-----------------------------------------------------------------------------
// 970630 add thread 
//-----------------------------------------------------------------------------
DWORD  id;
HANDLE hThread_all[200];     //hThread 
DWORD  retCode_all[200];
int    retCode_all_flag[200];
char   sIN_all[200][200];
int    L01_flag = 1;    // 0: no call thread L01 , 1:yes call thread L01 
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// FAR LOG 使用
//-----------------------------------------------------------------------------


#define  ACK            0x06
#define  NAK            0x15
#define  ACKTIME        8       /* Time wait for return ACK/NAK  */
#define  TRYTIMES       7       /* re-send times on NAK received */
#define  INLG           1024
#define  OULG           2048
#define  RC             0x0d
#define  SESSION        4
#define  NORMAL         1
#define  ERR            0
#define  TRUE           1
#define  FALSE          0
#define  LOCTEL         "02"
#define  EX_BUF         650        /* exchange rate write buf len */
#define  INT_BUF        512        /* intrest rate write buf len */
#define  FAX_BUF        1024       /* fax for P00 K00 X00 R00 86.5.14 */
#define  OPEN_BUF       5          /* open system write buf len */
#define  LOG_SIZE       256
#define  test           0
#define  SENDERROR      20
#define  MAX_CLIENT     2
#define  SENDALIVESEC   5

#define N_DAY_BEFORE  180



extern  int  chnum;
//extern	void err_stop(int);
//extern	int  p100(void);
//extern  int  p900(void);
//extern  void fdbprintf(const char* fmt, ...);

//extern ex       exVar;
extern exx      exxp;
extern vx       vxp;
vx      wvxp;  // point to header vxp share memory

int      linepos, lineno;

//20220225 new
extern   int      voie;



char     chk_buf[65][8], bufou[OULG], bufin[INLG], ibuf[256];
char     transcode[65][4], sync_mess, sync_int;
int      tskid, len, i, trans_flag[64], off_time = 0, evdeb, evfin;
int      SessNO;
char     PORT1 = '0';
char     ADDR1, ADDR2, ADDR3;
char     BRNO[4] = "001";
char     TRM1[3];
char     TRM2[3] = "02";
char     set_no[3], Line[3];

int      hdlcflag = 0;
int      intrest_ctn = 0, exchange_flag = 0, open_flag = 0, fund_flag = 0;
int      intrest_time, exchange_time, open_time, fund_time;
int      intrest_flag = 0, seq_flag = 0;
int      mode_assign = 2;   /* 1: on-ine 2: off-line */

int      len_int, len_ex, mode_flag, int_counter;
long     trmno;
int      set_seq;
int			 LineTotal;
long     this_time, init_time, hdlc_time;
int      syncfd;

FILE* exfp, * intfp, * openfp;
FILE* faxfp[64];

int      len_fund, fund_counter, fax_ctn[64], fax_flag[64]; // 86.5.14
char     FaxAcc[64][16], FaxPwd[64][6], FaxSdate[64][8], FaxEdate[64][8]; // 86.5.14

char     databuff[INLG];
char     cTCPConnect, sRemoteHost[20], date[12], sTime[12], cSendCount;
char     sLineNo[3];

long     lSendTime;
int      iSendTimes, iRecvTimes, iLineOk;
int      SendDataFlag = 0;
int      DataCtn = 0;
int      stcp;

time_t   tcpReConnTimeOld = 0L;
time_t   gTcpSendTime = 0L;
int      gTcpSent = 0;

int      gFlag2300 = 1;
int      gFlag0830 = 1;
int      gFlag0100 = 1;

char gIvrIniFile[] = ".\\ivr.ini";

#if (0)  //961031
typedef  struct dect
{
	char  port;               /* port 0 */
	char  addr;               /* 0x41 : on-line , 0x42 : off-line */
	char  it_atmc_ta[2];      /* space */
	char  it_atmc_txcd[3];    /* transaction code */

	char  it_atmc_atmver[6];  /* system date */
	char  it_atmc_atmno[3];   /* brno */
	char  it_atmc_atmno1[2];
	char  it_atmc_device[12]; /* all ZEROS */
	char  it_atmc_service;    /* 0:atm in service 1:atm off */
	char  it_atmc_mode;       /* 0:transaction of today (before 15:30) */
							  /* 1:transcation of next business dat (after 15:30) */
	char  it_atmc_dd[2];      /* business day */
	char  it_atmc_depmode;    /* value : 0 */
	char  it_atmc_atmseq[4];  /* transaction seq no */
}  INPUT_TITA;

INPUT_TITA atm;

#elif (1)

typedef  struct dect
{
	char  it_atmc_ta[2];      /* space */
	char  it_atmc_txcd[3];    /* transaction code */

	char  it_atmc_atmver[6];  /* system date */
	char  it_atmc_atmno[3];   /* brno */
	char  it_atmc_atmno1[2];
	char  it_atmc_device[12]; /* all ZEROS */
	char  it_atmc_service;    /* 0:atm in service 1:atm off */
	char  it_atmc_mode;       /* 0:transaction of today (before 15:30) */
							  /* 1:transcation of next business dat (after 15:30) */
	char  it_atmc_dd[2];      /* business day */
	char  it_atmc_depmode;    /* value : 0 */
	char  it_atmc_atmseq[4];  /* transaction seq no */
}  INPUT_TITA;

INPUT_TITA atm;
#endif

typedef struct dect1
{
	char  kinbr[3];           /* branch no. */
	char  trmseq[2];          /* terminal ID */
	char  txtno[5];           /* transcation seq no  set + sync+"["+lineno */
	char  ttskid[2];          /* task ID */
	char  trmtyp;             /* terminal type  "1" */
	char  txcd[3];            /* transcation code */
	char  ptype;              /* prcess type "0" */
	char  dscpt1[3];
	char  hcode;              /* "0" */
	char  ycode;              /* "0" */
	char  actno[14];          /* exVar->var[11] or exVar->var[18] account no. */
	char  txtype[2];          /* "M ", "00","U ","  " */
	char  crdb;               /* "1","2","0" */
	char  spcd[2];            /* "00" */
	char  nbcd;               /* "0", "1" */
	char  tlrno[2];           /* "87" */
	char  trnsbt;             /* "0" */
	char  curcd[2];           /* "00" */
	char  txamt1[11];         /* " " */
	char  txamt2[2];
	char  viopw[4];           /* p_a_s_s_w_o_r_d */                 //20220302 V6.3 ching2  modify hotfeb 弱掃  L508
	char  filler[8];
	char  onend;
} INPUT_ONLINE;

INPUT_ONLINE  tita;

int    strfax[64];
int    tmpsync[64];

char emion(char*, int, int, const char*, int);

typedef struct {
	int   cmd;
	int   port;
	char  addr;
	int   flush;
} IOC;

IOC     ioc[1];


//960911 add for host------
int     chandle;
char    cHostTCPConnect;
int     iHostSendTimes, iHostRecvTimes;
time_t  tcpReConnHostTimeOld = 0L;
int     iSeqNo = 2;
int     one_send = 0;
char    sRecvBuf[5400];  //961121
int     RecvLen = 0, RecvOtherLen = 0;
int     rootflag = 0;  //970103

typedef struct {
	char filler1[2];
	char atmtxcd[3];
	char atmver[6];
	char atmno[5];
	char filler2[12];
	char service;
	char mode;
	char dd[2];
	char filler3;
	char atmseq[4];
} ATMC;

ATMC atmc;


int gHotfeb88Start = 1;




//20220225 new   gtr6.h

typedef struct {
  char txcd[4];
  char curcd[4];
  char txamt[16];
  char rateno1[16];
  char xrate1[16];
  char crate1[16];
  char bchgamt[16];
  char id[16];
} GTR6;

GTR6 gQ20, gQ10;



//20220302 V6.2 ching2  modify wrtLog.cpp 因編譯無法過, 移到 hotfeb_2019.cpp 中
//20220301  add     wrtlog  move here 

#define N_DAY_BEFORE  180
#define MAX_BYTE_ONE_LINE 500

//20220301 old extern char* gIvrIniFile;


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
	struct tm newTime;  //20220224 old    , myOldTm;
	int ofy;
	char logFyName[256], wrtBuf[8 * 1024] = { 0 }, tmpWrtBuf[8 * 1024] = { 0 };

	//20220224 old myOldTm = *tm;  // backup tm

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

		errno_t myErrNoT = _sopen_s(&ofy, logFyName, O_CREAT | O_RDWR, _SH_DENYNO, S_IREAD | S_IWRITE);
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
		fdbprintf("Cannot open %s. %s(%i)\n", logFyName, __FILE__, __LINE__);
#endif

		//20220224 old  *tm = myOldTm;  // restore tm

		return ofy;
	}

	{
		char flowName[8] = { 0 };

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
			char myTmp[1024] = { 0 };

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
			char myTmp[1024] = { 0 };

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

	//20220224 old  *tm = myOldTm;  // restore tm

	return strlen(tmpWrtBuf);
}


int wrtLogByLen(char* buf, int len, const char* apName, int apLine)
{
	int ofy, i;
	time_t now;
	struct tm myTm;    //20220224 old  , myOldTm;
	char fyName[64], wrtEndBuf[128] = { 0 }, tmpWrtBuf[8 * 1024] = { 0 };

	//20220224 old  myOldTm = *tm; // backup tm

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
		fdbprintf("Cannot open %s. %s(%i)\n", fyName, __FILE__, __LINE__);
#endif

		//20220224 old  *tm = myOldTm; // restore tm

		return 0;
	}

	{
		char flowName[8] = { 0 };

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
		char tmpBuf[8] = { 0 };

		//20220224 old sprintf(tmpBuf, ((unsigned int)buf[i] < 0x20 || (unsigned int)buf[i] >= 0x7f)? "<%02X>" : "%c", (unsigned char)buf[i]);
		sprintf_s(tmpBuf, ((unsigned int)buf[i] < 0x20 || (unsigned int)buf[i] >= 0x7f) ? "<%02X>" : "%c", (unsigned char)buf[i]);
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
			char myTmp[1024] = { 0 };

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
			char myTmp[1024] = { 0 };

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

	//20220224 old  *tm = myOldTm; // restore tm

	return strlen(tmpWrtBuf);
}

int wrtLogByLenX(const char* mark, char* buf, int len, const char* apName, int apLine)
{
	int ofy, i;
	time_t now;
	struct tm myTm;   //20220224 old  , myOldTm;
	char fyName[64], wrtEndBuf[128] = { 0 }, tmpWrtBuf[8 * 1024] = { 0 };

	//20220224 old  myOldTm = *tm; // backup tm

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
		fdbprintf("Cannot open %s. %s(%i)\n", fyName, __FILE__, __LINE__);
#endif

		//20220224 old  *tm = myOldTm; // restore tm

		return 0;
	}

	{
		char flowName[8] = { 0 };

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
		char tmpBuf[8] = { 0 };

		if ('H' == mark[0])
			//20220224 old sprintf(tmpBuf, "<%02X>", (unsigned char)buf[i]);
			sprintf_s(tmpBuf, "<%02X>", (unsigned char)buf[i]);
		else
			//20220224 old sprintf(tmpBuf, ((unsigned int)buf[i] < 0x20 || (unsigned int)buf[i] >= 0x7f)? "<%02X>" : "%c", (unsigned char)buf[i]);
			sprintf_s(tmpBuf, ((unsigned int)buf[i] < 0x20 || (unsigned int)buf[i] >= 0x7f) ? "<%02X>" : "%c", (unsigned char)buf[i]);

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
			char myTmp[1024] = { 0 };

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
			char myTmp[1024] = { 0 };

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

	//20220224 old  *tm = myOldTm; // restore tm

	return strlen(tmpWrtBuf);
}

int wrtLogUapName(int lineNo, char* format, ...)
{
	time_t now;
	struct tm newTime;   //20220224 old  , myOldTm;
	int ofy;
	char logFyName[256], wrtBuf[8 * 1024] = { 0 }, tmpWrtBuf[8 * 1024] = { 0 };

	//20220224 old  myOldTm = *tm;  // backup tm

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
		errno_t myErrNoT = _sopen_s(&ofy, logFyName, O_CREAT | O_RDWR, _SH_DENYNO, S_IREAD | S_IWRITE);

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
		errno_t myErrNoT = _sopen_s(&ofy, logFyName, O_APPEND | O_RDWR, _SH_DENYNO, S_IREAD | S_IWRITE);

		//  //fdbprintf("myErrNoT=[%d]", myErrNoT);
		//
		if (myErrNoT != 0)
		{  //err
		}


	}

	if (ofy == -1) {
		//20220224 old  *tm = myOldTm;  // restore tm
		return ofy;
	}

	{
		char flowName[8] = { 0 };

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
			char myTmp[1024] = { 0 };

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
			char myTmp[1024] = { 0 };

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

	//20220224 old  *tm = myOldTm;  // restore tm

	return strlen(tmpWrtBuf);
}









//-----------------------------------------------------------------------------
//  NO:1 funMake_Time(char *sOut)
//
//        取得時間用
//
//  IN :
//  OUT: 
//-----------------------------------------------------------------------------
void funMake_Time(char *sOut, int sizeof_sOut)
{
	//new 

	time_t now;
	struct tm newTime;

	time(&now);
	errno_t errNoT = localtime_s(&newTime, &now);

	sprintf_s(sOut, sizeof_sOut, "[%02d/%02d %02d:%02d:%02d] ", newTime.tm_mon + 1, newTime.tm_mday, newTime.tm_hour, newTime.tm_min, newTime.tm_sec);

}





//-----------------------------------------------------------------------------
//  NO:2 funPrint_Log(char *data)
//
//       寫入dbg檔案  , 全部都寫
//
//  IN :
//  OUT: 
//-----------------------------------------------------------------------------
void funPrint_Log(char *sData_in)
{
	char   sFile[80];
	FILE   *fp;

	time_t now;
	struct tm newTime;

	time(&now);
	errno_t errNoT = localtime_s(&newTime, &now);

	//newtm->tm_year+1900
	//newtm->tm_mon+1
	//newtm->tm_mday
	//newtm->tm_wday  星期
	//newtm->tm_hour
	//newtm->tm_min
	//newtm->tm_sec 

	//20220208 OLD sprintf_s(sFile, sizeof(sFile), ".\\log_LOG\\LOG_%02d%02d_%02d.txt", newTime.tm_mon + 1, newTime.tm_mday, voie);
	sprintf_s(sFile, sizeof(sFile), ".\\log_FAR\\LOG_%02d%02d_%02d.txt", newTime.tm_mon + 1, newTime.tm_mday, voie);


	errno_t myErrNoT22 = fopen_s(&fp, sFile, "a");
	if (myErrNoT22 != 0) {
		sprintf_s(sTemp, sizeof(sTemp), "\r\nsOpen [%s] error!!! ", sFile);
		return;
	}
	else {
		char   sTime[30];

		if ((strcmp(sData_in, ".") == 0) || (strcmp(sData_in, "x") == 0)) {
			strcpy_s(sTime, sizeof(sTime), "");
		}
		else {
			funMake_Time(sTime, sizeof(sTime));
			fdbprintf("%s", sTime);      //dbg 顯示
			//fflush(fdbfd);

			fprintf(fp, "%s", sTime);    //寫檔
			fflush(fp);
		}

		fdbprintf("%s", sData_in);      //dbg 顯示
		//fflush(fdbfd);

		fprintf(fp, "%s", sData_in);    //寫檔
		fflush(fp);

		fclose(fp);
	}
}



//-----------------------------------------------------------------------------
//  NO:3 funKill_Log()
//
//        
//        
//  IN :
//  OUT: 
//-----------------------------------------------------------------------------
void funKill_Log()
{
	char   sFile[80];
	FILE   *fp;

	//1060211 new
	time_t now_time_t;
	struct tm now_tm;
	time(&now_time_t);
	now_time_t += (60 * 60 * 24);    //bofore day      //開前一天 只有這裏不同  1060217 by ching2 
	errno_t errNoT1 = localtime_s(&now_tm, &now_time_t);

	//20220208 OLD sprintf_s(sFile, sizeof(sFile), ".\\log_LOG\\LOG_%02d%02d_%02d.txt", now_tm.tm_mon + 1, now_tm.tm_mday, voie);
	sprintf_s(sFile, sizeof(sFile), ".\\log_FAR\\LOG_%02d%02d_%02d.txt", now_tm.tm_mon + 1, now_tm.tm_mday, voie);


	errno_t myErrNoT22 = fopen_s(&fp, sFile, "w");
	if (myErrNoT22 != 0)
	{
		sprintf_s(sTemp, sizeof(sTemp), "\r\nsOpen [%s] error!!! ", sFile);
		return;
	}
	else
	{
		fclose(fp);
	}


}



//-----------------------------------------------------------------------------
//  NO:4 show_time()
//
//       顯示時間用 
//        
//  IN : 無
//  OUT: 無
//-----------------------------------------------------------------------------
int show_time()
{
	//struct   tm* tm;
	//20220208 OLD long     lt;

	//20220208 OLD
	//time(&lt);
	//tm = localtime(&lt);

	time_t now;
	struct tm newTime;

	time(&now);
	errno_t errNoT = localtime_s(&newTime, &now);


	fdbprintf("[%02d/%02d/%02d]-[%02d:%02d:%02d] \r\n", newTime.tm_year - 11, newTime.tm_mon + 1, newTime.tm_mday, newTime.tm_hour, newTime.tm_min, newTime.tm_sec);
	return(0);
}



//------------------------------------------------------------------------------
//  NO:4 Toupper(int )
// 
//        
//  IN :
//  OUT: 
//------------------------------------------------------------------------------
int Toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return('A' + c - 'a');
	return(c);
}


//------------------------------------------------------------------------------
//  NO:5 *PackHEX( uchar *str, uchar *hex, int sz )
// 
//        
//  IN :
//  OUT: 
//------------------------------------------------------------------------------
char *PackHEX(uchar *str, uchar *hex, int sz)
{
	int i = 0, j = 0;

	while (sz-- > 0) {
		int c;

		if ((c = Toupper(*(hex + j++))) >= 'A')
			*(str + i) = (c - 'A' + 10) << 4;
		else
			*(str + i) = (c - '0') << 4;
		if ((c = Toupper(*(hex + j++))) >= 'A')
			*(str + i++) += c - 'A' + 10;
		else
			*(str + i++) += c - '0';
	}
	return((char *)str);
}


//---------------------------------------------------------------------------
char* UnpackCHARS(uchar* hex, uchar* str, int sz)
{
	int  i = 0, j = 0, va;

	while (sz-- > 0) {
		if ((va = *(str + j) >> 4) >= 10)
			*(hex + i++) = va - 10 + 'A';
		else
			*(hex + i++) = va + '0';
		if ((va = *(str + j++) & 0x0f) >= 10)
			*(hex + i++) = va - 10 + 'A';
		else
			*(hex + i++) = va + '0';
	}
	return((char*)hex);
}


















/*961030 add */
char ATMCtita(char* buf)
{
	char acc[4], systemdate[6];


	//20220223 old
	//time(&lt);
	//tm = localtime(&lt);

	//20220223 new
	time_t now;
	struct tm newTime;

	time(&now);
	errno_t errNoT = localtime_s(&newTime, &now);

	this_time = newTime.tm_hour * 60 * 60 + newTime.tm_min * 60 + newTime.tm_sec;

	//20220224 old sprintf(systemdate,"%02d%02d%02d", (newTime.tm_year - 11) % 100, newTime.tm_mon + 1, newTime.tm_mday);
	//20220303 old sprintf_s(systemdate, "%02d%02d%02d", (newTime.tm_year - 11) % 100, newTime.tm_mon + 1, newTime.tm_mday);
	sprintf_s(systemdate, sizeof(systemdate) +1 , "%02d%02d%02d", (newTime.tm_year - 11) % 100, newTime.tm_mon + 1, newTime.tm_mday);

	wrtLog("ATMCtita 11-11 %s(%i)\n", __FILE__, __LINE__);

	memset(&atm, '0', sizeof(atm));
	bufou[0] = 0;

	//20220224 old sprintf(atm.it_atmc_ta, "%2s", " ");
	sprintf_s(atm.it_atmc_ta, 3, "%2s", " ");

	wrtLog("ATMCtita 11-22 %s(%i)\n", __FILE__, __LINE__);

	//20220225 old if (strcmp(exVar[linepos].etran, "G52") == 0 || strcmp(exVar[linepos].etran, "G53") == 0)     /* 961222 */
	if (strcmp(exVar[linepos].etran, "G52") == 0 || strcmp(exVar[linepos].etran, "G53") == 0)     /* 961222 */

		//20220224 old sprintf(atm.it_atmc_txcd, "%03s", "VRE");
		sprintf_s(atm.it_atmc_txcd, sizeof(atm.it_atmc_txcd)+1, "%03s", "VRE");



	//20220225 old else if (strcmp(exVar[linepos].etran, "G01") == 0)  // pIdNo and
	else if (strcmp(exVar[linepos].etran, "G01") == 0)  // pIdNo and
	{
		wrtLog("ATMCtita 11-33  G01 11   %s(%i)\n", __FILE__, __LINE__);

		//20220225 old if (strlen(exVar[linepos].var[21]) == 14)
		if (strlen(exVar[linepos].var[21]) == 14)
		{
			//20220224 old sprintf(atm.it_atmc_txcd, "%03s", "VRE");
			sprintf_s(atm.it_atmc_txcd, sizeof(atm.it_atmc_txcd)+1, "%03s", "VRE");
			wrtLog("ATMCtita 11-33  G01 22   %s(%i)\n", __FILE__, __LINE__);


		}
		else
		{
			//20220224 old sprintf(atm.it_atmc_txcd, "%03s", "VIB");
			sprintf_s(atm.it_atmc_txcd, sizeof(atm.it_atmc_txcd) + 1, "%03s", "VIB");

			wrtLog("ATMCtita 11-33  G01 33   %s(%i)\n", __FILE__, __LINE__);
		}

	}
	else
	{
		//20220224 old sprintf(atm.it_atmc_txcd, "%03s", "   ");
		sprintf_s(atm.it_atmc_txcd, sizeof(atm.it_atmc_txcd) + 1, "%03s", "   ");
		wrtLog("ATMCtita 11-33  G01 44   %s(%i)\n", __FILE__, __LINE__);

	}

	//20220224 old sprintf(atm.it_atmc_atmver, "%06s", systemdate);
	sprintf_s(atm.it_atmc_atmver, sizeof(atm.it_atmc_atmver) + 1, "%06s", systemdate);

	wrtLog("ATMCtita 11-33  G01 55   %s(%i)\n", __FILE__, __LINE__);

	//20220224 old strncpy(acc,exVar[linepos].var[11], 3);
	//20220225 old strncpy_s(acc, exVar[linepos].var[11], 3);
	strncpy_s(acc, exVar[linepos].var[11], 3);

	acc[3] = 0;

	//20220224 old sprintf(atm.it_atmc_atmno, "%03s", "001");
	sprintf_s(atm.it_atmc_atmno, sizeof(atm.it_atmc_atmno) + 1, "%03s", "001");

	wrtLog("ATMCtita 11-33  G01 66   %s(%i)\n", __FILE__, __LINE__);

	//20220224 old sprintf(atm.it_atmc_atmno1, "%02s", "99");
	sprintf_s(atm.it_atmc_atmno1, sizeof(atm.it_atmc_atmno1) + 1, "%02s", "99");

	wrtLog("ATMCtita 11-33  G01 77   %s(%i)\n", __FILE__, __LINE__);

	//20220224 old sprintf(atm.it_atmc_device, "%012s", "0");
	sprintf_s(atm.it_atmc_device, sizeof(atm.it_atmc_device) + 1, "%012s", "0");

	wrtLog("ATMCtita 11-33  G01 88   %s(%i)\n", __FILE__, __LINE__);

	atm.it_atmc_service = '1';

	atm.it_atmc_mode = '0' + mode_assign;   /* 1: transaction of next business day ( after 15:30 ) */

	//20220224 old sprintf(atm.it_atmc_dd, "%02d", newTime.tm_mday);
	sprintf_s(atm.it_atmc_dd, sizeof(atm.it_atmc_dd) + 1, "%02d", newTime.tm_mday);

	wrtLog("ATMCtita 11-33  G01 99   %s(%i)\n", __FILE__, __LINE__);

	atm.it_atmc_depmode = '0';

	//20220224 old  sprintf(systemdate, "%04d", iSeqNo);
	sprintf_s(systemdate, "%04d", iSeqNo);

	wrtLog("ATMCtita 11-33  G01 AA   %s(%i)\n", __FILE__, __LINE__);


	memcpy(atm.it_atmc_atmseq, systemdate, 4);

	// size = strlen( bufou );
	memcpy(bufou, &atm, sizeof(atm));          /* put tita to buffer */
	bufou[sizeof(atm)] = 0;

	//fdbprintf("in emitita bufou = [%s] %s(%i)\n",bufou,__FILE__,__LINE__);

	wrtLog("ATMCtita 11-33  G01 BB   %s(%i)\n", __FILE__, __LINE__);

	return 0;
}





//960911 add for ByteToHex
int ByteToHex(char* Hex, char* Byte, int byte_len)
{
	int i = 0;
	char stemp[3] = { 0 };

	for (i = 0;i < byte_len;i++) {
		//wrtLog("Hex=[%s] %s(%i)\n",Hex,__FILE__,__LINE__);

		//20220224 old sprintf(stemp,"%02X",(unsigned char)Byte[i]);
		sprintf_s(stemp, "%02X", (unsigned char)Byte[i]);

		memcpy(Hex + i * 2, stemp, 2);
		//wrtLog("Hex=[%s] %s(%i)\n",Hex,__FILE__,__LINE__);
		//fdbprintf("Byte[%d]=[%d],Hex=[%s]\n",i,Byte[i],Hex);
	}
	if (i == 0)
		return 0;
	else
		return 1;
}


//960911 add for HexToByte
int HexToByte(char* Hex, unsigned char* Byte) {

	int HexLen = strlen(Hex);
	int i = 0;
	char stmp[5];

	//fdbprintf("HexLen=[%d]\n",HexLen);


	if ((HexLen % 2) == 0) {
		for (i = 0;i < (HexLen / 2);i++) {

			//20220224 old strcpy(stmp,"0x");
			strcpy_s(stmp, "0x");

			//20220224 old strncat(stmp,Hex+i*2,2);
			strncat_s(stmp, Hex + i * 2, 2);

			//Byte[i] = atoi(stmp);
			Byte[i] = (unsigned char)strtol(stmp, NULL, 16);
			//fdbprintf("stmp=[%s],byte[%d]=%d\n",stmp,i,Byte[i]);
		}
		return 1;
	}
	else
		return 0;
}





void ReConnect(char* buf)
{
	FILE* dfile;
	char sTfile[30], sNowTime[15];

	//20220223 old
	 //time(&lt);
	 //tm = localtime(&lt);

	 //20220223 new
	time_t now;
	struct tm newTime;

	time(&now);
	errno_t errNoT = localtime_s(&newTime, &now);

	//sprintf(sTfile, "/test/%02d.hot", newTime.tm_year, newTime.tm_mon + 1, newTime.tm_mday);
	//20220224 old sprintf(sTfile, "/test/%02d.hot", newTime.tm_year);
	sprintf_s(sTfile, "/test/%02d.hot", newTime.tm_year);


	//20220224 old
	//if ((dfile = fopen(sTfile, "a+")) == NULL)
	//  return ;

	//20220224 new  
	errno_t myErrNoT = fopen_s(&dfile, sTfile, "a+");
	if (myErrNoT != 0)
	{
		// open error 
		return;
	}

	//20220224 old sprintf(sNowTime, "%02d:%02d:%02d", newTime.tm_hour, newTime.tm_min, newTime.tm_sec);
	sprintf_s(sNowTime, "%02d:%02d:%02d", newTime.tm_hour, newTime.tm_min, newTime.tm_sec);
	fprintf(dfile, "%s ->[%s]\n", sNowTime, buf);

	fclose(dfile);
}



/*------------------------------- check voice send data ---------------------*/
int chk_exe_emis()
{
	static int j = -1;

	//wrtLog("chk_exe_emis chnum=[%d] %s(%i)\n", chnum, __FILE__, __LINE__);
	for (i = 0; i < chnum; i++) {
		j++;
		j %= chnum;

		//20220225 old if (exVar[j].eemis == 64) {
		if (exVar[j].eemis == 64) {
			lineno = j + 1;
			linepos = j;
			_gLineno = lineno;

			//20220225 old fdbprintf("line=[%d], tran=[%s]\n", lineno, exVar[linepos].etran);
			fdbprintf("line=[%d], tran=[%s]\n", lineno, exVar[linepos].etran);
			//20220225 old wrtLog("line=[%d], tran=[%s] %s(%i)\n", lineno, exVar[linepos].etran, __FILE__, __LINE__);
			wrtLog("line=[%d], tran=[%s] %s(%i)\n", lineno, exVar[linepos].etran, __FILE__, __LINE__);

			//20220225 old if (strcmp(exVar[linepos].etran, "G01") != 0)
			if (strcmp(exVar[linepos].etran, "G01") != 0)
				return 0;


			/**** Add Transaction for CTC GW Tran No. 000 999 OP1 OP2 CIN ****/
			/**** hotfe88 do nothing                           2003.Dec   ****/
				  /*
			if (strcmp(exVar[linepos].etran, "000") == 0 ||
				strcmp(exVar[linepos].etran, "999") == 0 ||
				strcmp(exVar[linepos].etran, "OP1") == 0 ||
				strcmp(exVar[linepos].etran, "OP2") == 0 ||
				strcmp(exVar[linepos].etran, "CIN") == 0 ||
				strcmp(exVar[linepos].etran, "L01") == 0 ||
				strcmp(exVar[linepos].etran, "OP3") == 0) {
			  //wrtLog("return here %s(%i)\n", __FILE__, __LINE__);

			  return 0;
			}
				  */
				  /****************************************************************/
			//20220225 old  if (exVar[j].etran[0] >= 0x30 && exVar[j].etran[0] <= 0x39) {
			if (exVar[j].etran[0] >= 0x30 && exVar[j].etran[0] <= 0x39) {
				fdbprintf("SendDataFlag = %d, cTCPConnect = %d\n", SendDataFlag, cTCPConnect);
				// if (SendDataFlag == 0 && cTCPConnect == 1)    90.10.04
				if (cTCPConnect == 1) {
					//wrtLog("AS400 data, check_exe_emis return 1 %s(%i)\n", __FILE__, __LINE__);

					return 1;
				}
			}
			else {
				wrtLog("UNISYS HOST data, check_exe_emis return 2 %s(%i)\n", __FILE__, __LINE__);
				//20220225 old  wrtLog("UNISYS HOST data exVar[%d].remis=[%d] %s(%i)\n", linepos, (int)exVar[linepos].remis, __FILE__, __LINE__);
				wrtLog("UNISYS HOST data exVar[%d].remis=[%d] %s(%i)\n", linepos, (int)exVar[linepos].remis, __FILE__, __LINE__);


				return 2;
			}
		}
	}

	//wrtLog("return here %s(%i)\n", __FILE__, __LINE__);
	return 0;
}





/*--------------------------- change p_a_s_s_w_o_r_d service ----------------------*/    //20220302 V6.3 ching2  modify hotfeb 弱掃  L1086
void emi004p(char* buf) {              /* deposit change p_a_s_s_w_o_r_d P50 */          //20220302 V6.3 ching2  modify hotfeb 弱掃  L1087
	struct atohbuf {
		char  end;
		//20220224 old } endbuf;
	} endbuf{};

	endbuf.end = 0;
	//20220224 old strcat( bufou, (const char *)&endbuf );
	strcat_s(bufou, (const char*)&endbuf);

}





/*------------------------- get send on-line data --------------------------*/
char emion(char* buf, int tson, int chon, const char* frFile, int frLine)
{
  char onchoice = '?', onacc[4];
  int size, cash_item;
  int changeIDpasswd = 0;

  wrtLog("emion be called from %s-%d, v15=[%s] %s(%i)\n", frFile, frLine, exVar[linepos].var[15], __FILE__, __LINE__);

	if (exVar[linepos].var[2][0] == '$')
		//20220224 old strncpy(onacc, exVar[linepos].var[18], 3);
	{
		wrtLog("emion 1111 %s(%i)\n", __FILE__, __LINE__);
		strncpy_s(onacc, exVar[linepos].var[18], 3);
		wrtLog("emion 3333 %s(%i)\n", __FILE__, __LINE__);
	}
	else
		//20220224 old strncpy(onacc, exVar[linepos].var[11], 3);
	{
		wrtLog("emion 2222 %s(%i)\n", __FILE__, __LINE__);
		strncpy_s(onacc, exVar[linepos].var[11], 3);
		wrtLog("emion 4444 %s(%i)\n", __FILE__, __LINE__);
	}



  onacc[3] = 0;
  sync_int += 1;   /* 0-9 */

	wrtLog("emion 5555 %s(%i)\n", __FILE__, __LINE__);

  if (sync_int > 9)
    sync_int = 0;

	wrtLog("emion 6666 %s(%i)\n", __FILE__, __LINE__);

  sync_mess = sync_int + 0x30;
  exVar[linepos].esync = sync_mess;

	wrtLog("emion 7777 %s(%i)\n", __FILE__, __LINE__);

  //20220224 old sprintf(tita.kinbr, "%03s", onacc);
	
	//20220303 V6.4 ching2  modify hotfeb 弱掃
	//20220303 old sprintf_s(tita.kinbr, "%03s", onacc);
  sprintf_s(tita.kinbr, sizeof(tita.kinbr)+1, "%03s", onacc);

	wrtLog("emion 8888 %s(%i)\n", __FILE__, __LINE__);

  //20220224 old sprintf(tita.trmseq, "%02s", TRM1);
	//20220303 V6.4 ching2  modify hotfeb 弱掃
	//20220303 old sprintf_s(tita.trmseq, "%02s", TRM1);
  sprintf_s(tita.trmseq, sizeof(tita.trmseq)+1, "%02s", TRM1);

	wrtLog("emion 9999 %s(%i)\n", __FILE__, __LINE__);

  //20220224 old sprintf(tita.txtno, "%d%c%c%02d", set_seq, exVar[linepos].esync, '0', lineno);
	//20220303 V6.4 ching2  modify hotfeb 弱掃
	//20220303 old sprintf_s(tita.txtno, "%d%c%c%02d", set_seq, exVar[linepos].esync, '0', lineno);
  sprintf_s(tita.txtno, sizeof(tita.txtno)+1, "%d%c%c%02d", set_seq, exVar[linepos].esync, '0', lineno);

	wrtLog("emion AAAA %s(%i)\n", __FILE__, __LINE__);

  //20220224 old sprintf(chk_buf[linepos], "%d%3s%c%02d", set_seq, exVar[linepos].etran, exVar[linepos].esync, lineno);
  sprintf_s(chk_buf[linepos], "%d%3s%c%02d", set_seq, exVar[linepos].etran, exVar[linepos].esync, lineno);

	wrtLog("emion BBBB %s(%i)\n", __FILE__, __LINE__);

  chk_buf[linepos][7] = 0;

  wrtLog("tcp to UNISYS header7Bytes=[%s] %s(%i)\n", chk_buf[linepos], __FILE__, __LINE__);
  wrtLog("emion tson=[%d] %s(%i)\n", tson, __FILE__, __LINE__);

  
  switch (tson) {
  case 1:                                                 /* balance */
    onchoice = '?';
    if (strcmp(exVar[linepos].etran, "P00") == 0 ) {       /* deposit */
      //20220224 old sprintf(tita.ttskid, "%02s", "PI");
      sprintf_s(tita.ttskid, sizeof(tita.ttskid)+1, "%02s", "PI");
      onchoice = 'p';
    }
    if (strcmp(exVar[linepos].etran,"K00") == 0 ) {      /* cash */
      //20220224 old sprintf(tita.ttskid, "%02s", "KI");
      sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s", "KI");
      onchoice = 'k';
    }
    tita.trmtyp = '1';

    memcpy(tita.txcd, exVar[linepos].etran, 3);     

    tita.ptype = '0';

    if (exVar[linepos].var[2][0] == '*')
        //20220224 old sprintf(tita.dscpt1, "%03s", "099");
      sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s", "099");
    else
        //20220224 old sprintf(tita.dscpt1, "%03s", "001");
      sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s", "001");
    break;
  case 2 :              /* transfer  */
    onchoice = '?';

    wrtLog("etran=[%s] %s(%i)\n", exVar[linepos].etran, __FILE__, __LINE__);

    if (strcmp(exVar[linepos].etran, "P10") == 0) {
      
        //20220224 old sprintf(tita.ttskid, "%02s", "PU");
      sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s", "PU");

      tita.trmtyp = '1';
      memcpy(tita.txcd, exVar[linepos].etran, 3);
      tita.ptype = '0';

      if (exVar[linepos].var[2][0] == '$') {   /* for Fund Service 89.10.05 */
        fdbprintf( "Fund Service !! var[2] = %c, var[3] = %c\n",   exVar[linepos].var[2][0], exVar[linepos].var[3][0]);
        if (exVar[linepos].var[3][0] == '1')
          //20220224 old sprintf(tita.dscpt1, "%03s", "152");
          sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s", "152");

        if (exVar[linepos].var[3][0] == '3')
          //20220224 old sprintf(tita.dscpt1, "%03s", "153");
          sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s", "153");

        // 2010-02-06  voice line v12 should be "XXXX"
        memcpy(tita.viopw, exVar[linepos].var[12], 4); // fund 扣款, new/old flow all put "XXXX" to password
        wrtLog("put [%s] to tita.viopw %s(%i)\n", exVar[linepos].var[12], __FILE__, __LINE__);

        onchoice = 'f';
      }
      else {
        fdbprintf( "Transfer Service !! var[2] = %s, var[3] = %s\n",   exVar[linepos].var[2][0], exVar[linepos].var[3][0]);

        switch (exVar[linepos].var[3][0]) {
        case '1':
        case '2':
          onchoice = 'p';
          //20220224 old sprintf(tita.dscpt1,"%03s","082");
          sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","082");
          break;
        case '5':
          onchoice = 'p';
          //20220224 old sprintf(tita.dscpt1,"%03s","131");
          sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","131");
          break;
        case '6':
          onchoice = 'p';
          //20220224 old sprintf(tita.dscpt1,"%03s","166");
          sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","166");
          break;
        case '7':
          onchoice = 'h';
          //20220224 old sprintf(tita.dscpt1,"%03s","082");
          sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","082");
          break;
        }
      }
    }

    if (strcmp(exVar[linepos].etran, "P70") == 0)  {    /* P70 */
      //20220224 old sprintf(tita.ttskid,"%02s","PU");
      sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","PU");
      tita.trmtyp = '1';
      memcpy(tita.txcd,exVar[linepos].etran,3);
      tita.ptype = '0';

      //961206 modify
      //20220224 old if (exVar[linepos].var[5][0] == '1') sprintf(tita.dscpt1, "%03s", "029");
      if (exVar[linepos].var[5][0] == '1') sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s", "029");

      //20220224 old if (exVar[linepos].var[5][0] == '2') sprintf(tita.dscpt1, "%03s", "030");
      if (exVar[linepos].var[5][0] == '2') sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s", "030");

      //20220224 old if (exVar[linepos].var[5][0] == '3') sprintf(tita.dscpt1, "%03s", "031");
      if (exVar[linepos].var[5][0] == '3') sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s", "031");

      //sprintf(tita.dscpt1,"%03s","0");
      onchoice = 'x';
    }

    if (strcmp(exVar[linepos].etran, "P12") == 0)  {    /* P12 */ //K12 961115 modify
      if (strncmp(exVar[linepos].var[11] + 3, "031", 3) == 0 ||
          strncmp(exVar[linepos].var[11] + 3, "033", 3) == 0) {  //K12

        //20220224 old sprintf(tita.ttskid, "%02s", "KU");
        sprintf_s(tita.ttskid, 3, "%02s", "KU");

        memcpy(tita.txcd, "K12", 3);
      }
      else {
        //20220224 old sprintf(tita.ttskid, "%02s", "PU");
        sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s", "PU");
        memcpy(tita.txcd, exVar[linepos].etran, 3);
      }
      tita.trmtyp = '1';
      tita.ptype = '0';
      //20220224 old sprintf(tita.dscpt1, "%03s", "084");
      sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s", "084");
      onchoice = 'g';
    }

    if (strcmp(exVar[linepos].etran,"K10") == 0) {    /* K10 */
      //20220224 old sprintf(tita.ttskid,"%02s","KU");
      sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1,  "%02s","KU");
      tita.trmtyp = '1';
      memcpy(tita.txcd,exVar[linepos].etran,3);
      tita.ptype = '0';
      if ( exVar[linepos].var[3][0] == '1'|| exVar[linepos].var[3][0] == '2' )
        //20220224 old sprintf(tita.dscpt1,"%03s","082");
        sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","082");

      //20220224 old if (exVar[linepos].var[3][0] == '5') sprintf(tita.dscpt1,"%03s","131");
      if (exVar[linepos].var[3][0] == '5') sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","131");

      //20220224 old if (exVar[linepos].var[3][0] == '6') sprintf(tita.dscpt1,"%03s","166");
      if (exVar[linepos].var[3][0] == '6') sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","166");
      onchoice = 'k';

      if (exVar[linepos].var[3][0] == '7') {
          //20220224 old sprintf(tita.dscpt1,"%03s","082");
        sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","082");
        onchoice = 'i';
      }
    }
    break;
  case 3 :                                               /* lost */
    onchoice = '?';
    //wrtLog("123 %s(%i)\n", __FILE__, __LINE__);
    if (strcmp(exVar[linepos].etran, "G66") == 0 ) {     /* ATM lost */
      //20220224 old sprintf(tita.ttskid, "%02s", "GU");
      sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s", "GU");
      tita.trmtyp = '1';
      memcpy(tita.txcd, exVar[linepos].etran, 3);
      tita.ptype = '0';
      //20220224 old sprintf(tita.dscpt1, "%03s", "0");
      sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s", "0");
      onchoice = 'g';
    }

    if (strcmp(exVar[linepos].etran, "K60") == 0 ) {     /* cash lost */
      // 空白支票掛失預約登記
      //20220224 old sprintf(tita.ttskid,"%02s", "KU");
      sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s", "KU");
      tita.trmtyp = '1';
      memcpy(tita.txcd, exVar[linepos].etran, 3);
      tita.ptype = '0';
      //20220224 old sprintf(tita.dscpt1, "%03s", "011");
      sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1,  "%03s", "011");
      onchoice = 'k';
    }

    if (strcmp(exVar[linepos].etran, "P60") == 0) {     /* deposit lost */
      //20220224 old sprintf(tita.ttskid, "%02s", "PU");
      sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1,  "%02s", "PU");
      tita.trmtyp = '1';
      memcpy(tita.txcd, exVar[linepos].etran, 3);
      tita.ptype = '0';
      //20220224 old sprintf(tita.dscpt1, "%03s", exVar[linepos].var[13] );/* 001 or 006 */
      sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1,  "%03s", exVar[linepos].var[13] );/* 001 or 006 */
      onchoice = 'p';
    }

    break;
  case 4 :                                               /* change p_a_s_s_w_o_r_d */  //20220302 V6.3 ching2  modify hotfeb 弱掃  L1335
      //20220224 old sprintf(tita.ttskid,"%02s","GU");
      sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1,  "%02s","GU");
      tita.trmtyp = '1';
      memcpy(tita.txcd,exVar[linepos].etran,3);
      tita.ptype = '0';
      //20220224 old sprintf(tita.dscpt1,"%03s",exVar[linepos].var[14]);
      sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1,  "%03s",exVar[linepos].var[14]);
      onchoice = 'g';
      break;
  case 5 :                                               /* cash action */
      if ( strcmp(exVar[linepos].etran,"K61") == 0 ) {
      //20220224 old sprintf(tita.ttskid,"%02s","KU");
      sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","KU");
      tita.trmtyp = '1';
      memcpy(tita.txcd,exVar[linepos].etran,3);
      tita.ptype = '0';
      //20220224 old sprintf(tita.dscpt1,"%03s","013");
      sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","013");
      onchoice = 'k';
      break;
      }
      if ( strcmp(exVar[linepos].etran,"K62") == 0 ) {
          //20220224 old sprintf(tita.ttskid,"%02s","KU");
         sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","KU");
         tita.trmtyp = '1';

#if (0)
         sprintf(tita.txcd,"%03s","K61");  //961107 modify K61->K60
         tita.ptype = '0';
         sprintf(tita.dscpt1,"%03s","014"); //961107 modify 014->001
         onchoice = 'g';
#else
         //20220224 old sprintf(tita.txcd, "%03s","K60");  //2009-04-23 modify K61->K60
         sprintf_s(tita.txcd, sizeof(tita.txcd) + 1, "%03s","K60");  //2009-04-23 modify K61->K60
         tita.ptype = '0';
         //20220224 old sprintf(tita.dscpt1, "%03s","001"); //2009-04-23 modify 014->001
         sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","001"); //2009-04-23 modify 014->001
         onchoice = 'g';
#endif

         break;
      }
  case 6 :                                               /* reset */
      //20220224 old sprintf(tita.ttskid,"%02s","GU");
      sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","GU");
      tita.trmtyp = '1';
      memcpy(tita.txcd,exVar[linepos].etran,3);
      tita.ptype = '0';
      //20220224 old sprintf(tita.dscpt1,"%3s",exVar[linepos].var[18]);
      sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%3s",exVar[linepos].var[18]);
      onchoice = 'k';
      break;
  case 7 :                                               /* fax */
      if ( strcmp(exVar[linepos].etran,"P00") == 0 && exVar[linepos].var[3][0] == '1' ) {
          //20220224 old sprintf(tita.ttskid,"%02s","PI");
         sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","PI");
         tita.trmtyp = '1';
         memcpy(tita.txcd,exVar[linepos].etran,3);
         tita.ptype = '0';
         //20220224 old sprintf(tita.dscpt1,"%03s","001");
         sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","001");
         onchoice = 'p';
         break;
      }
      if ( strcmp(exVar[linepos].etran,"P00") == 0 && exVar[linepos].var[3][0] == '2') {
          //20220224 old sprintf(tita.ttskid,"%02s","PI");
         sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","PI");
         tita.trmtyp = '1';
         memcpy(tita.txcd,exVar[linepos].etran,3);
         tita.ptype = '0';
         //20220224 old sprintf(tita.dscpt1,"%03s","007");
         sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","007");
         onchoice = 'p';
         break;
      }
      if ( strcmp(exVar[linepos].etran,"K00") == 0 && exVar[linepos].var[3][0] == '1' ) {
         //20220224 old sprintf(tita.ttskid,"%02s","KI");
         sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","KI");
         tita.trmtyp = '1';
         memcpy(tita.txcd,exVar[linepos].etran,3);
         tita.ptype = '0';
         //20220224 old sprintf(tita.dscpt1,"%03s","001");
         sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","001");
         onchoice = 'k';
         break;
      }
      if ( strcmp(exVar[linepos].etran,"K00") == 0 && exVar[linepos].var[3][0] == '2') {
         //20220224 old sprintf(tita.ttskid,"%02s","KI");
         sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","KI");
         tita.trmtyp = '1';
         memcpy(tita.txcd,exVar[linepos].etran,3);
         tita.ptype = '0';
         //20220224 old sprintf(tita.dscpt1,"%03s","007");
         sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","007");
         onchoice = 'k';
         break;
      }
      if ( strcmp(exVar[linepos].etran,"R00") == 0 ) {
          //20220224 old sprintf(tita.ttskid,"%02s","RI");
         sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","RI");
         tita.trmtyp = '1';
         memcpy(tita.txcd,exVar[linepos].etran,3);
         tita.ptype = '0';
         //20220224 old sprintf(tita.dscpt1,"%03s","010");
         sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","010");
         onchoice = 'r';
         break;
      }
      if (strcmp(exVar[linepos].etran,"P00") == 0 && exVar[linepos].var[2][0] == '#') {
        // for yuan2_zhi4_da4_xue2(元智大學), the dscpt1 value is "021"
         //20220224 old sprintf(tita.ttskid, "%02s", "PI");
         sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s", "PI");
         tita.trmtyp = '1';
         memcpy(tita.txcd, exVar[linepos].etran, 3);
         tita.ptype = '0';
         //20220224 old sprintf(tita.dscpt1, "%03s", "021");
         sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s", "021");
         onchoice = 's';
         break;
      } // * for pc banking 88.01.03

      if (strcmp(exVar[linepos].etran,"P00") == 0 && exVar[linepos].var[2][0] == '@') {
        // for ya3_dong1_qi2_huo4(亞東期貨), the dscpt1 value is "121"
        // var[2][0] = '@' is assigned at uapm.c t_hos2_1() function
        //20220224 old sprintf(tita.ttskid, "%02s", "PI");
        sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s", "PI");
        tita.trmtyp = '1';
        memcpy(tita.txcd, exVar[linepos].etran, 3);
        tita.ptype = '0';
        //20220224 old sprintf(tita.dscpt1, "%03s", "121");
        sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s", "121");
        onchoice = 's';
        break;
      }
  case 8 :                                               /* fax */
      if ( strcmp(exVar[linepos].etran,"K00") == 0 ) {
          //20220224 old sprintf(tita.ttskid,"%02s","KI");
         sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","KI");
         tita.trmtyp = '1';
         memcpy(tita.txcd,exVar[linepos].etran,3);
         tita.ptype = '0';
         //20220224 old sprintf(tita.dscpt1,"%03s","027");
         sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","027");
         onchoice = 'k';
         break;
      }
      if ( strcmp(exVar[linepos].etran,"X00") == 0 ) {
         //20220224 old sprintf(tita.ttskid,"%02s","XI");
         sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","XI");
         tita.trmtyp = '1';
         memcpy(tita.txcd,exVar[linepos].etran,3);
         tita.ptype = '0';
         //20220224 old sprintf(tita.dscpt1,"%03s","001");
         sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","001");
         onchoice = 'x';
         break;
      }
      break;
  case 9 :                                        /* mobile banking */
      if ( strcmp(exVar[linepos].etran,"K61") == 0 ) {
         //20220224 old sprintf(tita.ttskid,"%02s","KU");
         sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","KU");
         tita.trmtyp = '1';
         memcpy(tita.txcd,exVar[linepos].etran,3);
         tita.ptype = '0';
         //20220224 old sprintf(tita.dscpt1,"%03s","012");
         sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","012");
         onchoice = 'k';
         break;
      }
      if ( strcmp(exVar[linepos].etran,"P61") == 0 ) {
         //20220224 old sprintf(tita.ttskid,"%02s","PU");
         sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","PU");
         tita.trmtyp = '1';
         memcpy(tita.txcd,exVar[linepos].etran,3);
         tita.ptype = '0';
         if (exVar[linepos].var[15][0] == '1')
             //20220224 old sprintf(tita.dscpt1,"%03s","012");
            sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","012");
         else
             //20220224 old sprintf(tita.dscpt1,"%03s","013");
            sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s","013");
         onchoice = 'p';
         break;
      }
      break;
  /* genman 920923 get total acc & pwd check */
  case 10:
      if (strcmp(exVar[linepos].etran,"G00") == 0 ) {

         /* test acc pwd.. */
      /*
         sprintf(exVar[linepos].var[11],"%014s","00500411111112");
         sprintf(exVar[linepos].var[12],"%4s","6284");
      */
         //20220224 old strncpy(onacc,exVar[linepos].var[11],3);
         strncpy_s(onacc,exVar[linepos].var[11],3);
         
         memcpy(tita.kinbr, onacc, 3);

         //20220224 old sprintf(tita.ttskid,"%02s","GI");
         sprintf_s(tita.ttskid, sizeof(tita.ttskid) + 1, "%02s","GI");
         tita.trmtyp = '1';
         memcpy(tita.txcd,exVar[linepos].etran,3);
         tita.ptype = '0';
         //20220224 old sprintf(tita.dscpt1, "%03s", "002");
         sprintf_s(tita.dscpt1, sizeof(tita.dscpt1) + 1, "%03s", "002");
         onchoice = 'g'; //useless
         break;
     }
     break;
  
  
  case 11:
    //wrtLogByLen(bufou, 64, __FILE__, __LINE__);

    // '1': first check pidno p_a_s_s_w_o_r_d is XXXX; '2': secnod check pidno and p_a_s_s_w_o_r_d    //20220302 V6.3 ching2  modify hotfeb 弱掃  L1552
    wrtLog("exVar[%d].var[22]=[%s] %s(%i)\n", linepos, exVar[linepos].var[22], __FILE__, __LINE__);
    onchoice = (strcmp(exVar[linepos].var[22], "XXXX") == 0) ? '1' : '2';

   if( strlen(exVar[linepos].var[21]) == 14  )
   {
       
       char onacc[10];
       //strncpy(onacc,exVar[linepos].var[21],3);
       //memcpy(tita.kinbr, onacc, 3);  onacc[3]=0x00;
       
       wrtLog("case 11, put tita.actno=[%s] %s(%i)\n", exVar[linepos].var[21], __FILE__, __LINE__);
       memcpy(tita.actno, exVar[linepos].var[21], 14);
 

       memcpy(tita.kinbr, "001", 3);

       memcpy(tita.ttskid, "GU", 2);
       tita.trmtyp = '1';
       memcpy(tita.txcd, "G52", 3);
       tita.ptype = '0';

       //202220224 old char onacc1[10];
       char onacc1[10] = { 0x00 };


       //20220224 old strncpy(onacc,exVar[linepos].var[21]+3,3); onacc1[3]=0x00;
       strncpy_s(onacc,exVar[linepos].var[21]+3,3); onacc1[3]=0x00;
 
       if( strcmp(onacc1, "001")==0  || strcmp(onacc1, "004")==0  || strcmp(onacc1, "003")==0 ) 
          memcpy(tita.dscpt1, "001", 3);
       else if( strcmp(onacc1, "001")==0 ) 
          memcpy(tita.dscpt1, "002", 3);
       else
          memcpy(tita.dscpt1, "000", 3);

   }
   else
   {
      
      memcpy(tita.kinbr, "001", 3);
      memcpy(tita.ttskid, "GI", 2);
      tita.trmtyp = '1';
      memcpy(tita.txcd, "G01" , 3);     //G01 or other
      tita.ptype = '0';
      memcpy(tita.dscpt1, "002", 3);
   }
  

   
    break;


  case 13:
    //wrtLogByLen(bufou, 64, __FILE__, __LINE__);
    wrtLog("exVar[%d].var[12]=[%s], exVar[%d].var[13]=[%s] %s(%i)\n",
            linepos, exVar[linepos].var[12], linepos, exVar[linepos].var[13], __FILE__, __LINE__);

    // 1: first check accNo and p_a_s_s_w_o_r_d, new p_a_s_s_w_o_r_d is XXXX, see, uapx.c chkNo   //20220302 V6.3 ching2  modify hotfeb 弱掃  L1610
    // 2: second send accNo, p_a_s_s_w_o_r_d and new p_a_s_s_w_o_r_d to Host                      //20220302 V6.3 ching2  modify hotfeb 弱掃  L1611
    onchoice =
      (strlen(exVar[linepos].var[12]) != 0 && strcmp(exVar[linepos].var[13], "XXXX") == 0) ? '1' : '2';

    memcpy(tita.kinbr, "001", 3);
    memcpy(tita.ttskid, "GU", 2);
    tita.trmtyp = '1';
    memcpy(tita.txcd, exVar[linepos].etran, 3);
    tita.ptype = '0';
    memcpy(tita.dscpt1, "001", 3);

    {
      char dscpt[128] = {0};

      //20220224 old sscanf(exxp[linepos].chain, "%s", dscpt);
      sscanf_s(exxp[linepos].chain, "%s", dscpt, sizeof(dscpt) );

      // see uapx.c newpw1()
      if (strcmp(dscpt, "002") == 0) {
        onchoice = '3';
        memcpy(tita.dscpt1, dscpt, 3);
        changeIDpasswd = 1;

        wrtLog("onchoice='3' and dscpt=002 %s(%i)\n", __FILE__, __LINE__);
      }
    }

    break;

  case 14:
    //wrtLogByLen(bufou, 64, __FILE__, __LINE__);

    wrtLog("exVar[%d].var[11]=[%s] %s(%i)\n", linepos, exVar[linepos].var[11], __FILE__, __LINE__);
    onchoice = '1';

    memcpy(tita.kinbr, "001", 3);
    memcpy(tita.ttskid, "GI", 2);
    tita.trmtyp = '1';
    memcpy(tita.txcd, exVar[linepos].etran, 3);
    tita.ptype = '0';
    memcpy(tita.dscpt1, "069", 3);
    wrtLog("case 14, put tita.actno=[%s] %s(%i)\n", exVar[linepos].var[11], __FILE__, __LINE__);
    memcpy(tita.actno, exVar[linepos].var[11], 14);
    memcpy(tita.viopw, "XXXX", 4);

    break;
  case 15:  // foregin Balance OR foregin detail FAX: Q01
    //wrtLogByLen(bufou, 64, __FILE__, __LINE__);
    wrtLog("exVar[%d].var[12]=[%s], exVar[%d].var[13]=[%s] %s(%i)\n",
            linepos, exVar[linepos].var[12], linepos, exVar[linepos].var[13], __FILE__, __LINE__);

    onchoice = exVar[linepos].var[2][0];  // v2 = '1' balance query; v2 = '3' detail FAX

    memcpy(tita.kinbr, exVar[linepos].var[11], 3);
    memcpy(tita.ttskid, "QI", 2);
    tita.trmtyp = '1';
    memcpy(tita.txcd, exVar[linepos].etran, 3);
    tita.ptype = '0';

    memcpy(tita.dscpt1, ('1' == onchoice) ? "001" : "007", 3);

    break;
  case 16:  // foregin Balance FAX: Q00
    //wrtLogByLen(bufou, 64, __FILE__, __LINE__);
    wrtLog("exVar[%d].var[12]=[%s], exVar[%d].var[13]=[%s] %s(%i)\n",
            linepos, exVar[linepos].var[12], linepos, exVar[linepos].var[13], __FILE__, __LINE__);

    onchoice = '1';

    memcpy(tita.kinbr, exVar[linepos].var[11], 3);
    memcpy(tita.ttskid, "QI", 2);
    tita.trmtyp = '1';
    memcpy(tita.txcd, exVar[linepos].etran, 3);
    tita.ptype = '0';
    memcpy(tita.dscpt1, "001", 3);

    break;

  case 17:  // foregin Transfer Q20
    //wrtLogByLen(bufou, 64, __FILE__, __LINE__);
    //wrtLogByLenX("v25=", exxp[linepos].chain, strlen(exxp[linepos].chain), __FILE__, __LINE__);

    onchoice = '1';

    memcpy(tita.kinbr, exVar[linepos].var[11], 3);
    memcpy(tita.ttskid, "QQ", 2);
    tita.trmtyp = '1';
    memcpy(tita.txcd, exVar[linepos].etran, 3);
    tita.ptype = '0';
    memcpy(tita.dscpt1, "083", 3);

    break;

  case 18:  // foregin Transfer NT or SAME foregin Q10
    //wrtLogByLen(bufou, 64, __FILE__, __LINE__);
    wrtLogByLenX("v25=", exxp[linepos].chain, strlen(exxp[linepos].chain), __FILE__, __LINE__);

    onchoice = exVar[linepos].var[23][0];  // v23 = '2' Foregin->NT; v23 = '3' Same Foregin transfer

    memcpy(tita.kinbr, exVar[linepos].var[11], 3);
    memcpy(tita.ttskid, "QQ", 2);
    tita.trmtyp = '1';
    memcpy(tita.txcd, exVar[linepos].etran, 3);
    tita.ptype = '0';

    //memcpy(tita.dscpt1, '2' == onchoice ? "082" : "156", 3);
    memcpy(tita.dscpt1, "082", 3);

    break;
  case 19:  // foregin book or stamp LOST: Q60
    //wrtLogByLen(bufou, 64, __FILE__, __LINE__);
    wrtLogByLenX("v25=", exxp[linepos].chain, strlen(exxp[linepos].chain), __FILE__, __LINE__);

    onchoice = exVar[linepos].var[22][0];  // v22 = '2' Foregin BOOK LOST; v22 = '3' Foregin STAMP LOST

    memcpy(tita.kinbr, exVar[linepos].var[11], 3);
    memcpy(tita.ttskid, "QU", 2);
    tita.trmtyp = '1';
    memcpy(tita.txcd, exVar[linepos].etran, 3);
    tita.ptype = '0';

    memcpy(tita.dscpt1, '2' == onchoice ? "006" : "001", 3);

    break;
  case 20:  // get foregin exchange RATE
    //wrtLogByLen(bufou, 64, __FILE__, __LINE__);
    wrtLogByLenX("v25=", exxp[linepos].chain, strlen(exxp[linepos].chain), __FILE__, __LINE__);

    onchoice = '1';

    memcpy(tita.kinbr, "001", 3);
    memcpy(tita.ttskid, "AU", 2);
    tita.trmtyp = '1';
    memcpy(tita.txcd, exVar[linepos].etran, 3);
    tita.ptype = '0';

    memcpy(tita.dscpt1, "002", 3);

    break;

  default :
     return('?');
     break;
  }

  tita.hcode = '0';
  tita.ycode = '0';

	wrtLog("emion 33-11 %s(%i)\n", __FILE__, __LINE__);

  wrtLogByLenX("...v2=", exVar[linepos].var[2], 1, __FILE__, __LINE__);

	wrtLog("emion 33-22 %s(%i)\n", __FILE__, __LINE__);

  if (exVar[linepos].var[2][0] == '$') { /* for Fund Service 89.10.05 */
    wrtLog("exVar[linepos].var[2][0] == '$', put tita.actno=[%s] %s(%i)\n", exVar[linepos].var[18], __FILE__, __LINE__);
    //20220224 old sprintf(tita.actno, "%014s", exVar[linepos].var[18]);
    sprintf_s(tita.actno, sizeof(tita.actno) + 1, "%014s", exVar[linepos].var[18]);
    fdbprintf( "exVar[linepos].var[18] = %s\n", exVar[linepos].var[18]);
  }
  else {

		wrtLog("emion 33-33 %s(%i)\n", __FILE__, __LINE__);

    /* for Bank Service */
    wrtLog("for bank service, put tita.actno=[%s] %s(%i)\n", exVar[linepos].var[11], __FILE__, __LINE__);

		wrtLog("emion 33-44 %s(%i)\n", __FILE__, __LINE__);

    //20220224 old sprintf(tita.actno, "%014s", exVar[linepos].var[11]);
    sprintf_s(tita.actno, sizeof(tita.actno) + 1, "%014s", exVar[linepos].var[11]);
    fdbprintf( "exVar[linepos].var[11] = %s\n", exVar[linepos].var[11]);


    //1010605
    if( strlen(exVar[linepos].var[21]) == 14  )
    { 
      //20220224 old sprintf(tita.actno, "%014s", exVar[linepos].var[21]);
      sprintf_s(tita.actno, sizeof(tita.actno) + 1, "%014s", exVar[linepos].var[21]);
      fdbprintf( "exVar[linepos].var[21] = %s\n", exVar[linepos].var[21]);
    }


    switch (tson) {
    case 20:  // A81
      memcpy(tita.actno, "00100000000000", 14);
      break;
    case 18:  // Q10
      //20220224 old sprintf(tita.actno, "%014s", exVar[linepos].var[11]);
      sprintf_s(tita.actno, sizeof(tita.actno) + 1, "%014s", exVar[linepos].var[11]);
      break;
    case 17:  // Q20
      //20220224 old sprintf(tita.actno, "%014s", (strlen(exVar[linepos].var[13]) == 16) ? &exVar[linepos].var[13][2] : exVar[linepos].var[13]);
      sprintf_s(tita.actno, sizeof(tita.actno) + 1, "%014s", (strlen(exVar[linepos].var[13]) == 16) ? &exVar[linepos].var[13][2] : exVar[linepos].var[13]);
      break;
    }
  }

  wrtLog("exVar[linepos].etran=[%s] %s(%i)\n", exVar[linepos].etran, __FILE__, __LINE__);
  if (strcmp(exVar[linepos].etran, "P10") == 0 ||
      strcmp(exVar[linepos].etran, "P12") == 0 ||
      strcmp(exVar[linepos].etran, "P70") == 0 ||
      strcmp(exVar[linepos].etran, "K10") == 0) {  /* transfer */
    //20220224 old sprintf(tita.txtype, "%02s", "M ");
    sprintf_s(tita.txtype, sizeof(tita.txtype) + 1, "%02s", "M ");
    tita.crdb = '1';
  }
  else if (strcmp(exVar[linepos].etran, "Q10") == 0 ||  // foregin transfer foregin -> NT
           strcmp(exVar[linepos].etran, "Q60") == 0) {  // foregin LOST book and LOST stamp
    //20220224 old sprintf(tita.txtype, "%02s", "M ");
    sprintf_s(tita.txtype, sizeof(tita.txtype) + 1, "%02s", "M ");
    tita.crdb = '1';
  }
  else if (strcmp(exVar[linepos].etran, "Q20") == 0) {  // foregin transfer NT -> foregin
    //20220224 old sprintf(tita.txtype, "%02s", "M ");
    sprintf_s(tita.txtype, sizeof(tita.txtype) + 1, "%02s", "M ");
    tita.crdb = '2';
  }
  else {
    //20220224 old sprintf(tita.txtype, "%02s", "  ");
    sprintf_s(tita.txtype, sizeof(tita.txtype) + 1, "%02s", "  ");
    tita.crdb = '0';
  }

  //20220224 old sprintf(tita.spcd, "%02s", "0");
  sprintf_s(tita.spcd, sizeof(tita.spcd) + 1, "%02s", "0");
  tita.nbcd = '0';
  //20220224 old sprintf(tita.tlrno, "%02s", "87");
  sprintf_s(tita.tlrno, sizeof(tita.tlrno) + 1, "%02s", "87");

  tita.trnsbt = '0';

  //20220224 old sprintf(tita.curcd, "%02s", "00");  // initial curcd is NT
  sprintf_s(tita.curcd, sizeof(tita.curcd) + 1, "%02s", "00");  // initial curcd is NT

  if (20 == tson && strcmp(exVar[linepos].etran, "A81") == 0) {
    memcpy(tita.curcd, exVar[linepos].var[24], 2);   // 外幣幣別
    /*
    switch (atoi(exVar[linepos].var[23])) {
    case 1: // NT->foregin
      memcpy(tita.curcd, "00", 2);                     // 扣帳幣別
      //memcpy(tita.curcd, exVar[linepos].var[24], 2);   // 入帳幣別
      break;
    case 2: // foregin->NT
      memcpy(tita.curcd, exVar[linepos].var[24], 2);   // 扣帳幣別
      //memcpy(tita.curcd, "00", 2);               // 入帳幣別
      break;
    }
    */
  }

  if (18 == tson && strcmp(exVar[linepos].etran, "Q10") == 0) {
    // foregin -> NT or same foregin transfer
    wrtLog("V24 curcd=[%s] %s(%i)\n", exVar[linepos].var[24], __FILE__, __LINE__);
    memcpy(tita.curcd, exVar[linepos].var[24], 2);  // 扣帳幣別
  }

  if (17 == tson && strcmp(exVar[linepos].etran, "Q20") == 0) {
    // NT -> foregin
    //memcpy(tita.curcd, "00", 2);
    wrtLog("V24 curcd=[%s] %s(%i)\n", exVar[linepos].var[24], __FILE__, __LINE__);
    memcpy(tita.curcd, exVar[linepos].var[24], 2); // 入帳幣別
  }

  if (16 == tson && strcmp(exVar[linepos].etran, "Q00") == 0) {
    if (2 == atoi(exVar[linepos].var[23])) {
      // user select FOEGIN accountNo, FAX curr assign "99", meaning ALL currcd
      memcpy(tita.curcd, "99", 2);
    }
  }

  if (15 == tson && strcmp(exVar[linepos].etran, "Q01") == 0) {
    if (2 == atoi(exVar[linepos].var[23])) {
      // user select FOEGIN accountNo
      memcpy(tita.curcd, exVar[linepos].var[24], 2);
    }
  }

  if (3 == tson && strcmp(exVar[linepos].etran, "K60") == 0) {
    cash_item = atoi(exVar[linepos].var[15]);
    if (2 == cash_item) {
      //20220224 old sprintf(tita.txamt1, "%011s", exVar[linepos].var[13]);
      sprintf_s(tita.txamt1, sizeof(tita.txamt1) + 1, "%011s", exVar[linepos].var[13]);
      //20220224 old sprintf(tita.txamt2, "%02s", "0");
      sprintf_s(tita.txamt2, sizeof(tita.txamt2) + 1, "%02s", "0");
    }
    else {
        //20220224 old sprintf(tita.txamt1, "%011s", "0");
      sprintf_s(tita.txamt1, sizeof(tita.txamt1) + 1, "%011s", "0");
      //20220224 old sprintf(tita.txamt2, "%02s", "0");
      sprintf_s(tita.txamt2, sizeof(tita.txamt2) + 1, "%02s", "0");
    }
  }
  else {
    if (2 == tson) {   // NT -> NT transfer service
      if (exVar[linepos].var[2][0] == '$') /* for Fund Service 89.10.05 */
        //20220224 old sprintf(tita.txamt1, "%011s", exVar[linepos].var[22]);
        sprintf_s(tita.txamt1, sizeof(tita.txamt1) + 1, "%011s", exVar[linepos].var[22]);
      else                              /* for Bank Service */
        //20220224 old sprintf(tita.txamt1, "%011s", exVar[linepos].var[14]);
        sprintf_s(tita.txamt1, sizeof(tita.txamt1) + 1, "%011s", exVar[linepos].var[14]);

      //20220224 old sprintf(tita.txamt2, "%02s", "0");
      sprintf_s(tita.txamt2, sizeof(tita.txamt2) + 1, "%02s", "0");
    }
    else {
      //20220224 old sprintf(tita.txamt1, "%011s", "0");
      sprintf_s(tita.txamt1, sizeof(tita.txamt1) + 1, "%011s", "0");
      //20220224 old sprintf(tita.txamt2, "%02s", "0");
      sprintf_s(tita.txamt2, sizeof(tita.txamt2) + 1, "%02s", "0");
    }
  }

  if (17 == tson) {   // NT -> Foregin currd transfer
    memcpy(tita.txamt1, gQ20.txamt, 11);
    memcpy(tita.txamt2, &gQ20.txamt[12], 2);
  }
  else if (18 == tson) {   // Foregin -> NT or same Foregin currd transfer
    memcpy(tita.txamt1, gQ10.txamt, 11);
    memcpy(tita.txamt2, &gQ10.txamt[12], 2);
  }

  //wrtLog("....v2=[%c] %s(%i)\n", exVar[linepos].var[2][0], __FILE__, __LINE__);
  wrtLogByLenX(";;;v2=", exVar[linepos].var[2], 1, __FILE__, __LINE__);

	wrtLog("emion 22-11 %s(%i)\n", __FILE__, __LINE__);

  if ('$' == exVar[linepos].var[2][0]) { /* for Fund Service 89.10.05 */
    //sprintf(tita.viopw, "%11s%d", " ", mode_assign);
    // 2010-02-08
    wrtLog("fund P10 transfer mode_assign=[%d]... %s(%i)\n", mode_assign, __FILE__, __LINE__);
    memcpy(tita.viopw, exVar[linepos].var[12], 4);  // voice line v12 should be "XXXX"
    //20220224 old sprintf(tita.filler, "%7s%d", " ", mode_assign);
    sprintf_s(tita.filler, sizeof(tita.filler) + 1, "%7s%d", " ", mode_assign);
  }
  else {                          /* for Bank Service */

		wrtLog("emion 22-22 %s(%i)\n", __FILE__, __LINE__);

    //20220224 old sprintf(tita.viopw, "%04s", exVar[linepos].var[12]);
    sprintf_s(tita.viopw, sizeof(tita.viopw) + 1, "%04s", exVar[linepos].var[12]);

		wrtLog("emion 22-33 %s(%i)\n", __FILE__, __LINE__);

    if (11 == tson) {
      // v22 come from uapx.c gtChar()
#if (1) // 1: despass do in uapx.c; 0: despass do in hotfeb88.c
      memcpy(tita.viopw, exVar[linepos].var[22], 4);  // v22 come from uapx.c gtChar()
#else
      if ('1' == onchoice) {
        // now v22 is "XXXX"
        memcpy(tita.viopw, exVar[linepos].var[22], 4);  // v22 come from uapx.c gtChar()
      }
      else {
        char desPasswd[5] = {0};

        desPass(exVar[linepos].var[22], desPasswd);
        memcpy(tita.viopw, desPasswd, 4);
      }
#endif
    }
    else if (13 == tson) {
      // v13 come from uapx.c chkNo, v12 come from drXidin L1090
      // v12 is accountNo p_a_s_s_w_o_r_d, v12 does NOT des            //20220302 V6.3 ching2  modify hotfeb 弱掃  L1958
      if (1 == changeIDpasswd) {
        // change ID's p_a_s_s_w_o_r_d drXebk L2640                  //20220302 V6.3 ching2  modify hotfeb 弱掃  L1960
        // set voipw to XXXX
        memcpy(tita.viopw, "XXXX", 4);
      }
    }
    else if (14 == tson) {
      // v11 is transOut accNo
      ;
    }

    if (4 == tson) {
        //20220224 old sprintf(tita.filler, "%04s%3s%d", exVar[linepos].var[13], " ", mode_assign);
      sprintf_s(tita.filler, sizeof(tita.filler) + 1, "%04s%3s%d", exVar[linepos].var[13], " ", mode_assign);
    }
    else if (7 == tson || 8 == tson) {       //fax mode=4
      //sprintf(tita.filler, "%7s%d"," ", 4); //961108 modify for test mode=4->1
      sprintf_s(tita.filler, sizeof(tita.filler) + 1, "%7s%d", " ", mode_assign);
    }
    else {
      //20220224 old sprintf(tita.filler, "%7s%d", " ", mode_assign);
      sprintf_s(tita.filler, sizeof(tita.filler) + 1, "%7s%d", " ", mode_assign);
    }
  }

  //genman 920923
  if (10 == tson) {
      //20220224 old sprintf(tita.filler, "%7s%d", " ", mode_assign); //mode fix to '1'
    sprintf_s(tita.filler, sizeof(tita.filler) + 1, "%7s%d", " ", mode_assign); //mode fix to '1'
  }


	wrtLog("emion 22-44 %s(%i)\n", __FILE__, __LINE__);


  tita.onend = 0;
  size = sizeof(tita);


	wrtLog("emion 22-55 %s(%i)\n", __FILE__, __LINE__);


  //961031 modify
  ATMCtita(bufou);


	wrtLog("emion 22-66 %s(%i)\n", __FILE__, __LINE__);


  //sprintf(bufou + sizeof(atm), "%c%c%03d", PORT1, ADDR1, iSeqNo);
  //bufou[5+sizeof(atm)] = 0;

  memcpy(bufou + sizeof(atm), &tita, size);          /* put tita to buffer */

  return onchoice;
}




/*------------------------------- hdlc to avr fail ---------------------------*/
int hdlc_to_avr_fail(char* buf, int set_len)
{
	if (lineno < 1 || lineno > chnum) {

		//20220223 old
		 //time(&lt);
		 //tm = localtime(&lt);

		 //20220223 new
		time_t now;
		struct tm newTime;

		time(&now);
		errno_t errNoT = localtime_s(&newTime, &now);

		//sprintf(vxp->message, "Recv Mess error [%d] %02d:%02d", lineno, newTime.tm_hour, newTime.tm_min);
		return(0);
	}
	linepos = lineno - 1;
	memcpy(exxp[linepos].chain, buf, set_len);

	//20220224 old strncpy(exVar[linepos].rtran, transcode[lineno], 3);
	strncpy_s(exVar[linepos].rtran, transcode[lineno], 3);

	exVar[linepos].rtran[3] = 0;
	exVar[linepos].rsync = exVar[linepos].esync;

	wrtLog("exVar[%d].remis be set to 64 %s(%i)\n", linepos, __FILE__, __LINE__);
	exVar[linepos].remis = 64;

	return (0);
}





/*960911------ for HOST Connect --------------------------------------*/
// receive TCPIP data from UNISYS host
int host_tcpip_recv(char* buf)
{
	int iLen, iCt, ii;
	char sTemp[13];
	char sTemp1[1024];
	//FILE *dfile;
	char reclen[8] = { 0 };
	char sTemp2[4] = { 0 };

	if (0 == RecvOtherLen) {
		memset(sRecvBuf, 0, sizeof(sRecvBuf));
		memset(sTemp, 0, sizeof(sTemp));
		//wrtLog("======host_tcpip_recv start======\r\n");

		if ((iLen = tcp_receive(chandle, sTemp, 12)) == -1) {

			//20220224 old sprintf(vxp->message, "Connection closed by UNISYS");
			sprintf_s(vxp->message, 30, "Connection closed by UNISYS");

			fdbprintf("tcp_receive==[%d]\n", iLen);
			wrtLog("Host_tcp_receive() = -1, Host_tcp_close() %s(%i)\n", __FILE__, __LINE__);
			tcp_close(chandle);
			cHostTCPConnect = 0;
			wrtLog("set cHostTCPConnect to 0 %s(%i)\n", __FILE__, __LINE__);


			return 0;
		}

		sTemp[iLen] = 0;
		memcpy(sTemp2, sTemp + 3, 3);
		//wrtLogByLen(sTemp, iLen, __FILE__, __LINE__);
		//wrtLogByLen(sTemp2, iLen, __FILE__, __LINE__);

		ByteToHex(reclen, sTemp2, 3);
		//wrtLog("11111111111111 sTemp2=[%s],reclen=[%s] ,iLen =[%d] ii=[%d] %s(%d)\n",sTemp2,reclen, iLen,ii,__FILE__,__LINE__);

		ii = atoi(reclen) - 12;
		//wrtLog("11111111111111 iLen =[%d] ii=[%d] %s(%d)\n",iLen,ii,__FILE__,__LINE__);

		if (iLen > 0 && ii > 0) {
			//wrtLog("11111111111111 iLen =[%d] ii=[%d] %s(%d)\n",iLen,ii,__FILE__,__LINE__);
			//wrtLogByLen(sTemp, iLen, __FILE__, __LINE__);

			if ((iLen = tcp_receive(chandle, sRecvBuf, ii)) == -1) {

				//20220224 old sprintf(vxp->message, "Connection closed by UNISYS");
				sprintf_s(vxp->message, 32, "Connection closed by UNISYS");

				fdbprintf("Host_tcp_receive==[%d]\n", iLen);
				wrtLog("Host_tcp_receive() = -1, UNISYS Host_tcp_close %s(%i)\n", __FILE__, __LINE__);
				tcp_close(chandle);
				cHostTCPConnect = 0;
				wrtLog("set cHostTCPConnect to 0 %s(%i)\n", __FILE__, __LINE__);


				return 0;
			}
			//wrtLogByLen(sRecvBuf, iLen, __FILE__, __LINE__);

			//wrtLog("recvFr Host=[%s%s] len=[%d] %s(%i)\n", sTemp, sRecvBuf, iLen, __FILE__, __LINE__);

			//20220224 old sprintf(vxp->message, "From UNISYS len=%d", iLen);
			sprintf_s(vxp->message, 32, "From UNISYS len=%d", iLen);

			if (iLen > 0) {
				RecvLen = iLen;
				RecvOtherLen = ii - iLen;

				if (RecvOtherLen != 0)
					return 0;

				wrtLogByLenX("sTemp first 12 bytes=", sTemp, 12, __FILE__, __LINE__);
				//wrtLog("recvFr Host=[%s] len=[%d] %s(%i)\n", sRecvBuf, iLen, __FILE__, __LINE__);
				memcpy(buf, sRecvBuf, iLen);
				buf[iLen] = 0;
			}
			//wrtLogByLen(sRecvBuf, iLen, __FILE__, __LINE__);

			//20220223 old time(&lt);
			//tm = localtime(&lt);

			//20220223 new
			time_t now;
			struct tm newTime;

			time(&now);
			errno_t errNoT = localtime_s(&newTime, &now);


			//20220223 old sprintf(date, "%02d/%02d/%02d", newTime.tm_year, newTime.tm_mon + 1, newTime.tm_mday);
			sprintf_s(date, "%02d/%02d/%02d", newTime.tm_year, newTime.tm_mon + 1, newTime.tm_mday);

			//20220223 old sprintf(sTime, "%02d:%02d:%02d",newTime.tm_hour, newTime.tm_min, newTime.tm_sec);
			sprintf_s(sTime, "%02d:%02d:%02d", newTime.tm_hour, newTime.tm_min, newTime.tm_sec);

			fdbprintf("%s %s Recv Len:[%d] Data:[", date, sTime, strlen(buf));

			for (iCt = 0; iCt < (int)strlen(buf); iCt++) {
				if (buf[iCt] < 0x20)
					fdbprintf("(%02x)", (unsigned char)buf[iCt]);
				else
					fdbprintf("%c", buf[iCt]);
			}
			fdbprintf("]\r\n");
		}
	}
	else {   //recv len < ii
		memset(sTemp1, 0, sizeof(sTemp1));
		if ((iLen = tcp_receive(chandle, sTemp1, RecvOtherLen)) == -1) {

			//20220224 old sprintf(vxp->message, "Connection closed by UNISYS");
			sprintf_s(vxp->message, 30, "Connection closed by UNISYS");

			fdbprintf("Host_tcp_receive==[%d]\n", iLen);
			wrtLog("UNISYS Host_tcp_receive() = -1, Host_tcp_close %s(%i)\n", __FILE__, __LINE__);
			tcp_close(chandle);
			cHostTCPConnect = 0;
			wrtLog("set cHostTCPConnect to 0 %s(%i)\n", __FILE__, __LINE__);


			return 0;
		}

		//20220224 old sprintf(vxp->message, "From UNISYS-len=%d", iLen);
		sprintf_s(vxp->message, 30, "From UNISYS-len=%d", iLen);

		if (iLen > 0) {
			RecvOtherLen = RecvOtherLen - iLen;
			memcpy(sRecvBuf + RecvLen, sTemp1, iLen);
			RecvLen = RecvLen + iLen;

			memcpy(buf, sRecvBuf, RecvLen);
			buf[RecvLen] = 0;
		}
	}

	//wrtLog("======host_tcpip_recv end======\r\n");
	return strlen(buf);
}













/*
ping XXX.XXX.XXX.XXX | grep "packet loss"
  if XXX.XXX.XXX.XXX is not connect, it will need 10 seconds check, then timu out
  return "1 packets, transmitted, ........., 100% packet loss"
*/
int pingHost(char* cmd, const char* frFile, int frLine)
{
	FILE* ptr;
	char sRdLine[1024] = { 0 };
	int connectFlag = 1;

	return connectFlag;

	//wrtLog("popen cmd=[%s] come from %s-%d, %s(%i)\n", cmd, frFile, frLine, __FILE__, __LINE__);

	ptr = _popen(cmd, "r");
	if (ptr == NULL) {
		wrtLog("popen ERROR[%s] %s(%i)\n", cmd, __FILE__, __LINE__);
		return connectFlag;
	}

	while (fgets(sRdLine, sizeof(sRdLine), ptr)) {
		char s100Lost[] = ", 100% packet loss";
		//wrtLog("%s %s(%i)\n", sRdLine, __FILE__, __LINE__);

		if (strstr(sRdLine, s100Lost) != NULL) {
			// host ip is not conncet
			connectFlag = 0;
			break;
		}
	}
	_pclose(ptr);

	//wrtLog("connectFlag=[%d] %s(%i)\n", connectFlag, __FILE__, __LINE__);

	return connectFlag;
}



/*------------------------ print send & receive data to tty12 ---------------*/
void  print_rxtx(char* buf, int len, int type)
{
	int  m;

	switch (type) {
	case 1: fdbprintf("Recv %d |", len);
		break;
	case 2: fdbprintf("Send %d |", len);
		break;
	case 3: fdbprintf("Recv timeout %d |", len);
		break;
	}
	fdbprintf(" [");
	for (m = 0; m < len; m++) {
		if (buf[m] < 0x20) fdbprintf("(%x)", buf[m] & 0xff);
		else               fdbprintf("%c", buf[m]);
	}
	fdbprintf("]\r\n");
}




/*---------------------------------- pro_send_sync --------------------------*/
int pro_data(char* buf)
{
	char pork;

	wrtLog("etran=[%s] %s(%i)\n", exVar[linepos].etran, __FILE__, __LINE__);


	if (strcmp(exVar[linepos].etran, "G01") == 0) {
		FILE* fp;
		char idAllAccNoFile[32] = { 0 };

		fax_flag[lineno] = 0;
		fax_ctn[lineno] = 0;

		// first ID check
		wrtLog("first ID check, and v22 passwd is setting to XXXX %s(%i)\n", __FILE__, __LINE__);
		wrtLog("G01 id=[%s] %s(%i)\n", exxp[linepos].chain, __FILE__, __LINE__);
		wrtLog("exVar[%d].var[21]=[%s] %s(%i)\n", linepos, exVar[linepos].var[21], __FILE__, __LINE__);
		wrtLog("exVar[%d].var[22]=[%s] %s(%i)\n", linepos, exVar[linepos].var[22], __FILE__, __LINE__);

		//20220224 old sprintf(idAllAccNoFile, "idAllAccNoFile%02d.dat", linepos + 1);
		sprintf_s(idAllAccNoFile, "idAllAccNoFile%02d.dat", linepos + 1);

		// truncat idAllAccNoFileNN.dat
		//20220224 old if ((fp = fopen(idAllAccNoFile, "w+")) != NULL)
		//20220224 new  
		errno_t myErrNoT = fopen_s(&fp, idAllAccNoFile, "w+");
		if (myErrNoT != 0)
		{
			// open error 
		}
		fclose(fp);




		pork = emion(bufou, 11, 0, __FILE__, __LINE__);
		wrtLog("pork=[%c] %s(%i)\n", pork, __FILE__, __LINE__);

		{
			struct {
				char pidNo[10];
				char pidNoErr;
				char userNo[4];
				char myNull;
			} TIG01;


			struct {
				char pidNo[10];
				char pidNoErr;
				char userNo[4];
				char accno[14];
				char myNull;
			} TIG51;



			memset(&TIG01, 0, sizeof(TIG01));
			memset(&TIG51, 0x20, sizeof(TIG51));

			if (strlen(exVar[linepos].var[21]) == 14)
			{
				memcpy(TIG51.accno, exVar[linepos].var[21], 14);


				//20220224 old strcat(bufou, (const char *)&TIG51);
				strcat_s(bufou, (const char*)&TIG51);

				wrtLogByLenX("ACC G51 First check", bufou, strlen(bufou), __FILE__, __LINE__);

			}
			else
			{

				memcpy(TIG01.pidNo, exVar[linepos].var[21], sizeof(TIG01.pidNo));
				TIG01.pidNoErr = '0';
				memcpy(TIG01.userNo, "0000", 4);

				//20220224 old strcat(bufou, (const char *)&TIG01);
				strcat_s(bufou, (const char*)&TIG01);

				wrtLogByLenX("Id G01 First check", bufou, strlen(bufou), __FILE__, __LINE__);
			}

		}

		wrtLog("return len=[%d] %s(%i)\n", strlen(bufou), __FILE__, __LINE__);
		return strlen(bufou);
	}






	return 0;
}




/*---------------------- write exchange rate data to exchange.dat -------------*/
int recv_ex_data(char* buf, int len)
{
	char msgend, filename[30], time_ctn[8] = { 0 };
	char exdata[EX_BUF] = { 0 }, ex_ctn[EX_BUF] = { 0 };
	int  exsave;

	wrtLog("recv_ex_data exchange_flag=[%d] %s(%i)\n", exchange_flag, __FILE__, __LINE__);
	wrtLogByLen(buf, len, __FILE__, __LINE__);

	if (exchange_flag == 1) {

		//20220224 old sprintf(filename, "%12s", "exchange.dat");
		sprintf_s(filename, "%12s", "exchange.dat");

		//202202224 old 
		// if ((exfp = fopen(filename, "w+b")) == NULL) {
		//  //sprintf(vxp->message, "Cannot exchange.dat file ");
		//  return 0;
		//}

		//20220224 new  
		errno_t myErrNoT = fopen_s(&exfp, filename, "w+b");
		if (myErrNoT != 0)
		{
			// open error 
			//sprintf(vxp->message, "Cannot intrest.dat file ");
			return 0;
		}


		//20220223 old
			//time(&lt);
			//tm = localtime(&lt);

			//20220223 new
		time_t now;
		struct tm newTime;

		time(&now);
		errno_t errNoT = localtime_s(&newTime, &now);

		//sprintf(time_ctn, "%02d%02d%02d", newTime.tm_year - 11, newTime.tm_mon + 1, newTime.tm_mday);
		//time_ctn[7] = 0;

		//20220223 oldsprintf(time_ctn, "%03d%02d%02d", newTime.tm_year - 11, newTime.tm_mon + 1, newTime.tm_mday);
		sprintf_s(time_ctn, "%03d%02d%02d", newTime.tm_year - 11, newTime.tm_mon + 1, newTime.tm_mday);
	}

	if (1 == exchange_flag) {

		//20220224 old strcpy(exdata, time_ctn);
		strcpy_s(exdata, time_ctn);

		//20220224 old strncpy(ex_ctn, buf + 7, len - 7);
		strncpy_s(ex_ctn, buf + 7, len - 7);

		//ex_ctn[len - 6] = 0;

		//20220224 old strcat(exdata, ex_ctn);
		strcat_s(exdata, ex_ctn);

		exchange_flag = 0;
	}
	else {

		//20220224 old strncpy(exdata, buf, len);
		strncpy_s(exdata, buf, len);

	}

	exdata[len] = 0;

	wrtLog("fseek len_ex=[%d], EX_BUF=[%d], len_ex * EX_BUF=[%d] %s(%i)\n", len_ex, EX_BUF, len_ex * EX_BUF, __FILE__, __LINE__);
	fseek(exfp, len_ex * EX_BUF, 0);


	wrtLogByLen(exdata, EX_BUF * sizeof(char), __FILE__, __LINE__);
	exsave = fwrite(exdata, EX_BUF * sizeof(char), 1, exfp);

	wrtLog("exsave=[%d], %s(%i)\n", exsave, __FILE__, __LINE__);

	len_ex++;

	msgend = exdata[19];
	//msgend = exdata[20];

	wrtLog("exdata[19]=[%c], exdata[20]=[%c] %s(%i)\n", exdata[19], exdata[20], __FILE__, __LINE__);

	if (msgend == '1') {
		//sprintf(vxp->message, "write exchange rate OK!!");
		wrtLog("write exchange rate OK!! %s(%i)\n", __FILE__, __LINE__);
		fclose(exfp);
	}

	return 0;
}




/*----------------------write intrest rate data to intrest.dat------------ - */
int recv_int_data(char* buf, int len)
{
	char msgend, filename[40];
	char intdata[INT_BUF];
	int intsave;

	if (intrest_flag == 1) {

		//20220224 old sprintf(filename,"%11s","intrest.dat");
		sprintf_s(filename, "%11s", "intrest.dat");

		//20220224 old 
		// if ((intfp = fopen(filename, "w+b")) == NULL) {
		//  //sprintf(vxp->message, "Cannot intrest.dat file ");
		//  return 0;
		//}

		//20220224 new  
		errno_t myErrNoT = fopen_s(&intfp, filename, "w+b");
		if (myErrNoT != 0)
		{
			// open error 
			//sprintf(vxp->message, "Cannot intrest.dat file ");
			return 0;
		}

		intrest_flag = 0;
	}

	//20220224 old strncpy(intdata, buf, len);
	strncpy_s(intdata, buf, len);

	intdata[len] = 0;

	fseek(intfp, len_int * INT_BUF, 0);

	intsave = fwrite(intdata, sizeof(char), sizeof(intdata), intfp);

	len_int++;
	int_counter++;

	msgend = intdata[19];

	if (msgend == '1') {
		intrest_ctn = 1;
		int_counter = 0;
		//sprintf(vxp->message, "write intrest rate OK!!");
		fclose(intfp);
	}
	else {
		//961114
		//strncpy(data_reset,intdata+449,16);
		//data_reset[16] = 0;
		//k = emiint( "019", data_reset );
		//send_len=send_data(bufou,93);
	}

	return 0;
}




/*------------------------------ update date and time -----------------------*/
//1000318 modify, 修正時間確認問題
int update(int hour, int min)
{
	long int tt;
	int  year, month, day;
	int myYear, myMonth, myDay, myHour, myMin;
	SYSTEMTIME sysTime;

	//20220223 old
	   //time(&lt);
	   //tm = localtime(&lt);

	   //20220223 new
	time_t now;
	struct tm newTime;

	time(&now);
	errno_t errNoT = localtime_s(&newTime, &now);

	//20220223 old
	//myYear = newTime.tm_year;
	//myMonth = newTime.tm_mon;
	//myDay = newTime.tm_mday;
	//myHour = newTime.tm_hour;
	//myMin = newTime.tm_min;

	myYear = newTime.tm_year;
	myMonth = newTime.tm_mon;
	myDay = newTime.tm_mday;
	myHour = newTime.tm_hour;
	myMin = newTime.tm_min;

	if (abs(myHour - hour) >= 2)
	{
		wrtLog("stime() does not work, now system time=[%02d : %02d]; UNISYS time=[%02d : %02d],%s(%i)\r\n",
			myHour, myMin, hour, min, __FILE__, __LINE__);
		return 0;
	}

	year = newTime.tm_year;
	month = newTime.tm_mon;
	day = newTime.tm_mday;

	newTime.tm_year = year;
	newTime.tm_mon = month;
	newTime.tm_mday = day;

	newTime.tm_hour = hour;
	newTime.tm_min = min;

	tt = mktime(tm);

	if (tt != (time_t)-1) {
		GetLocalTime(&sysTime);
		sysTime.wHour = hour;
		sysTime.wMinute = min;
		wrtLog("stime hour=[%d], min=[%d] %s(%i)\n", hour, min, __FILE__, __LINE__);
		SetLocalTime(&sysTime);
		//stime(&tt);
	}
	else {
		wrtLog("ERROR mktime() function %s(%i)\n", __FILE__, __LINE__);
	}

	return 0;
}











//-----------------------------------------------------------------------------
//  NO:7 chk_exe_emis()
//
//       檢查語音線,是否收送
//        
//  IN : 無
//  OUT: 無
//-----------------------------------------------------------------------------
//
//int chk_exe_emis(void)
//{
//	int i;
//
//	for (i = chk_pos; i < chnum; i++) {
//		if (exVar[i].eemis == 64) {
//			lineno = i + 1;
//			linepos = i;
//			chk_pos = i + 1;
//			if (chk_pos >= chnum) chk_pos = 0;
//			return (1);
//		}
//	}
//	chk_pos = 0;
//	return (0);
//}
//
//




//-----------------------------------------------------------------------------
//  NO:8 p400()
//
//       主迴圈
//        
//  IN : 無
//  OUT: 無
//-----------------------------------------------------------------------------
//int p400(void)
//{
//
//
//	char myEtran[50];
//	int  iKill = 0;
//
//
//	//20220208 OLD
//	//struct tm* newtm;
//	//long   lt;
//
//	//1000318 for reset sno
//  //	FILE *fd;
//	char sFile[200] = { 0 };
//	char sNo[10] = { 0 };
//
//	////test md5  ching2 980425 
//
//	////void md5(char* lMessage,char *md5_str);    //lMessage為待加密字符串，md5_str為得到的md5
//	////  6789000000000 -->  86f60893d3c7918b3c4265560872fdda
//	//char md5_str[40];
//	//char s[100];
//	//strcpy(s,"6789000000000");
//
//	//md5( s, md5_str);
//	//fdbprintf("md5_str=[%s]  \r\n", md5_str);
//
//
//
//
//
//	//---------------------------------------------------------------------------
//	  // ching2 test start
//	//---------------------------------------------------------------------------
//	//TEST 
//	  //char sOut[3000];
//  /*
//	funRead_set();   // ./cfg/hotFAR.txt
//	  linepos=1;
//	//v25=[INQ 01 TreaoutAcc_check 501794 093125017949 END]
//
//	  sprintf( exxp[linepos].chain , "CALL TreaOutAcc_Check('%s', '%s')", "000002" , "000000000022");
//	//sprintf( exxp[linepos].chain , "CALL aaa");
//	  funCALL_SQL( conf_DSN1_PWD, conf_SQLID1_PWD, conf_SQLPW1_PWD , exxp[linepos].chain , sOut  );
//	  fdbprintf("TreaOutAcc_Check......  sOut=[%s]\r\n" , sOut );
//  */
//  //---------------------------------------------------------------------------
//	// ching2 test end
//  //---------------------------------------------------------------------------
//
//
//
//
//
//  // ========================================================================
//  // (0).AP START 
//  // ========================================================================
//
//	//20220208 OLD
//	//time(&lt);
//	//newtm = localtime(&lt);
//
//	time_t now;
//	struct tm newtm;
//
//	time(&now);
//	errno_t errNoT = localtime_s(&newtm, &now);
//
//
//	funPrint_Log("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
//	funPrint_Log(" ==========================================================================\r\n");
//	funPrint_Log(" ==========================================================================\r\n");
//	funPrint_Log(" ==========================================================================\r\n");
//
//	//20220208 OLD funPrint_Log(" == 程式 hotFAR 開始啟動        AP by ots ching2 1030416 V5.7            ==\r\n");
//	sprintf_s(sTemp, " == 程式 hotFAR 開始啟動        AP by ots ching2 [%s]            ==\r\n", VERSION1);
//	funPrint_Log(sTemp);
//
//	funPrint_Log(" ==========================================================================\r\n");
//	funPrint_Log(" ==========================================================================\r\n");
//	funPrint_Log(" ==========================================================================\r\n\r\n\r\n");
//	funPrint_Log("p400() start !!! --- \r\n");
//	funPrint_Log("\r\n");
//
//	//20220218 old sprintf_s(vxp->message, 32-2, "1030416 V5.7");
//	sprintf_s(vxp->message, 32-2, "%s", VERSION1);
//	Sleep(2000);
//
//
//	//---------------------------------------------------------------------------
//	  // 970702 add thread
//	//---------------------------------------------------------------------------
//	for (int i = 0; i < 65; i++)
//	{
//		hThread_all[i] = NULL;
//		retCode_all_flag[i] = 0;
//		memset(sIN_all[i], 0x00, sizeof(sIN_all[i]));
//	}
//
//
//
//
//
//	while (1)
//	{
//
//		// ========================================================================
//		// (1).check time 00:05:00 do delete log file 
//		// ========================================================================
//		//20220208 OLD
//		//time(&lt);
//		//newtm = localtime(&lt);
//
//		//20220208 NEW
//		time(&now);
//		errno_t errNoT = localtime_s(&newtm, &now);
//
//
//
//		if (newtm.tm_hour == 0 && newtm.tm_min == 5)  //00:05:00
//		{
//			iKill = 1;
//		}
//		if (newtm.tm_hour == 0 && newtm.tm_min == 6 && iKill == 1)
//		{
//			Sleep(2000);
//			funPrint_Log("\r\n\r\n");
//			funPrint_Log(" ==========================================================================\r\n");
//			funPrint_Log(" == 00:06:00 每日零晨刪除 去年次日之log檔  !!!!                          ==\r\n");
//			funPrint_Log(" ==========================================================================\r\n");
//			funKill_Log();
//			iKill = 0;
//		}
//		//1000318 add for sno reset
//		if (newtm.tm_hour == 0 && newtm.tm_min == 0 && newtm.tm_sec <= 5)
//		{
//			Sleep(3000);
//			funPrint_Log("\r\n\r\n");
//			funPrint_Log(" ==========================================================================\r\n");
//			funPrint_Log(" == 00:00:00 每日重置流水編號                                            ==\r\n");
//			funPrint_Log(" ==========================================================================\r\n");
//
//
//			////1030416  V5.7 ching2  add i02 抓 uap_sno 流水號
//	  /*
//			sprintf(sFile, ".\\conf\\uap_sNo.txt");
//			if( (fd= fopen(sFile, "w")) ==NULL)
//			{
//				sprintf(sFile, "read uap_sno.txt error\r\n");
//				funPrint_Log(sFile);
//				return(-1);
//			}
//			fseek(fd,0,0);
//			sprintf(sNo,"001");
//			fwrite(&sNo, sizeof(char), sizeof(sNo), fd);
//			fclose(fd);
//	  */
//
//	  //1030416  V5.7 ching2  add i02 抓 uap_sno 流水號
//			char sSQL[100];
//			char sOut[3000];
//			char s1[3000];
//
//			strcpy_s(sSQL, "CALL ivr_i02('001')");
//			//funCALL_SQL(sSQL, sOut, sizeof(sOut) );
//			sprintf_s(s1, "sOut=[%s]\r\n", sOut);
//			funPrint_Log(s1);
//
//
//
//		}
//		// ========================================================================
//		// (2).check 使用者關線
//		// ========================================================================
//		if ((vxp->command == '5') || (vxp->command == '3'))
//		{
//			funPrint_Log("\r\n\r\n");
//			funPrint_Log(" ==========================================================================\r\n");
//			funPrint_Log(" == IVR與HOST不連線,使用者關線                                           ==\r\n");
//			funPrint_Log(" ==========================================================================\r\n");
//			sprintf_s(vxp->message, 32-2, "使用者關線");
//			return(0);
//		}
//
//		// ========================================================================
//		// (3).check retCode_all_flag
//		// ========================================================================
//
//		for (int i = 0; i < 65; i++)
//		{
//			if (retCode_all_flag[i] == -1)
//			{
//				char s[1000];
//				sprintf_s(s, " CloseHandle()[i]=[%02d]  start !!!!\r\n", i);
//				funPrint_Log(s);
//				CloseHandle(hThread_all[i]);
//				Sleep(10);   //971219 ching2 remark  be. too slow 40 line  50-> 10
//				sprintf_s(s, " CloseHandle()[i]=[%02d]  end   !!!!\r\n", i);
//				funPrint_Log(s);
//				retCode_all_flag[i] = 0;
//				memset(sIN_all[i], 0x00, sizeof(sIN_all[i]));
//			}
//		}
//
//
//
//		while (chk_exe_emis())
//		{
//
//			if ((vxp->command == '5') || (vxp->command == '3'))
//			{
//				funPrint_Log("\r\n\r\n");
//				funPrint_Log(" ==========================================================================\r\n");
//				funPrint_Log(" == IVR與HOST不連線,使用者關線                                           ==\r\n");
//				funPrint_Log(" ==========================================================================\r\n");
//				sprintf_s(vxp->message, 32-2, "使用者關線");
//				return(0);
//			}
//
//			memcpy(myEtran, exVar[linepos].etran, 3);        myEtran[3] = 0;
//
//
//
//			// 970702 改成 thread
//		  //------------------------------------------------------------------------------------------
//				// drxxx  send [S01]   寫 LOG 進DB
//			//------------------------------------------------------------------------------------------
//			if ((strcmp(myEtran, "S01") == 0))
//			{
//				sprintf_s(sTemp, "\r\n\r\nvoie=[%02d], lineno=[%02d] \r\n", voie, lineno);
//				funPrint_Log(sTemp);
//				sprintf_s(sTemp, "\r\n\r\nmyEtran=[%s], v25=[%s] \r\n\r\n", myEtran, exxp[linepos].chain);
//				funPrint_Log(sTemp);
//
//				if (retCode_all_flag[linepos] == -1)
//				{
//					char s[1000];
//					sprintf_s(s, " P400 S01 CloseHandle()[linepos]=[%02d]  start !!!!\r\n", linepos);
//					funPrint_Log(s);
//					CloseHandle(hThread_all[linepos]);
//					Sleep(50);
//					sprintf_s(s, " P400 [S01] CloseHandle()[linepos]=[%02d]  End   !!!!\r\n", linepos);
//					funPrint_Log(s);
//					retCode_all_flag[linepos] = 0;
//					memset(sIN_all[linepos], 0x00, sizeof(sIN_all[linepos]));
//				}
//
//				exVar[linepos].eemis = 0;    //啟動音樂
//
//				sprintf_s(sIN_all[linepos], "%02d", linepos);
//				sprintf_s(sTemp, "sIN_all=[%s], [S01] : 寫 LOG 進DB \r\n", sIN_all[linepos]);
//				funPrint_Log(sTemp);
//
//
//				//20220225 old
//				//// 970630 add 
//				//if ((hThread_all[linepos] = CreateThread(NULL, 0, Thread_funCALL_S01, (LPVOID)&sIN_all[linepos], 0, &id)) == NULL)
//				//{
//				//	//1-1 
//				//	sprintf_s(sTemp, "linepos  = [%d] , CreateThread() Thread_funCALL_S01() error error error !!!!!!!!!!!!! \r\n", linepos);
//				//	funPrint_Log(sTemp);
//				//	Sleep(1000);
//				//	//return 0;
//				//}
//				//else
//				//{
//				//	//1-2 CreateThread() OK SLEEP 避免 sIN 在 CreateThread() 被別線蓋走
//				//	Sleep(100);
//				//}  //if( ( hThread_all[linepos] ....
//
//			}  //if ( (strcmp(myEtran, "S01" ) == 0) )
//
//
//
//
//		// 改成 thread
//	  //------------------------------------------------------------------------------------------
//			// drxxx  send [L01]  寫 LOG 進DB
//		//------------------------------------------------------------------------------------------
//			if ((strcmp(myEtran, "L01") == 0))
//			{
//				sprintf_s(sTemp, "\r\n\r\nvoie=[%02d], lineno=[%02d] \r\n", voie, lineno);
//				funPrint_Log(sTemp);
//				sprintf_s(sTemp, "\r\n\r\nmyEtran=[%s], v25=[%s] \r\n\r\n", myEtran, exxp[linepos].chain);
//				funPrint_Log(sTemp);
//
//				if (retCode_all_flag[linepos] == -1)
//				{
//					char s[1000];
//					sprintf_s(s, " P400 [L01] CloseHandle()[linepos]=[%02d]  start !!!!\r\n", linepos);
//					funPrint_Log(s);
//					CloseHandle(hThread_all[linepos]);
//					Sleep(50);
//					sprintf_s(s, " P400 [L01] CloseHandle()[linepos]=[%02d]  End   !!!!\r\n", linepos);
//					funPrint_Log(s);
//					retCode_all_flag[linepos] = 0;
//					memset(sIN_all[linepos], 0x00, sizeof(sIN_all[linepos]));
//				}
//
//				exVar[linepos].eemis = 0;    //啟動音樂
//
//				sprintf_s(sIN_all[linepos], "%02d", linepos);
//				sprintf_s(sTemp, "sIN_all=[%s], [L01] : 寫 LOG 進DB \r\n", sIN_all[linepos]);
//				funPrint_Log(sTemp);
//
//				//20220225 old
//				// 970630 add 
//				//if ((hThread_all[linepos] = CreateThread(NULL, 0, Thread_funCALL_L01, (LPVOID)&sIN_all[linepos], 0, &id)) == NULL)
//				//{
//				//	//1-1 
//				//	sprintf_s(sTemp, "linepos  = [%d] , CreateThread() Thread_funCALL_L01() error error error !!!!!!!!!!!!! \r\n", linepos);
//				//	funPrint_Log(sTemp);
//				//	Sleep(1000);
//				//	//return 0;
//				//}
//				//else
//				//{
//				//	//1-2 CreateThread() OK SLEEP 避免 sIN 在 CreateThread() 被別線蓋走
//				//	Sleep(100);
//				//}  //if( ( hThread_all[linepos] ....
//
//			}  //if ( (strcmp(myEtran, "S01" ) == 0) )
//
//
//
//
//	  //Sleep(100);     //971219 500-> 100  ching2 不可等 因為會有40路同時進線會迼成 等40*500
//
//
//
//
//		} //while (chk_exe_emis()) {
//
//		Sleep(10);  //971219 500-> 100    --> 10 980106
//
//
//	} //while (1) {
//
//
//}
//







/*---------------------------------------------------------------------------*/
int recvsync(unsigned char* buff)
{
	int ct, sct = 0, rdct = 0;
	int change = 0;

	//20220224 old unsigned char tmpbuf[1024];
	unsigned char tmpbuf[1024] = { 0x00 };

	//rdct = read(syncfd, buff, 1024);
	rdct = host_tcpip_recv((char*)buff);
	buff[rdct] = 0;

	//960911
	//fdbprintf("---------recvsync start---------\n");
	//flush(fdbfd);
	if (rdct > 0) {
		sct = 0;

		for (ct = 0; ct < rdct; ct++) {
			if (buff[ct] == 0x0F) {
				ct++;
				buff[ct] = buff[ct] - 0x30;
			}

			if (buff[ct] == 0x1B) {
				ct++;
				if (buff[ct] == 0x24) {
					ct++;
					if (buff[ct] == 0x40) {
						buff[ct] = 0x9E;
						tmpbuf[sct++] = buff[ct];
						ct++;
						change = 1;
					}
					else {
						ct = ct - 2;
					}
				}
				else if (buff[ct] == 0x28) {
					ct++;
					if (buff[ct] == 0x48) {
						buff[ct] = 0x9F;
						change = 0;
					}
					else {
						ct = ct - 2;
					}
				}
				else {
					ct--;
				}
			}

			if (change == 1) {
				if (buff[ct] == 0x0F) {
					ct++;
					buff[ct] = buff[ct] - 0x30;
				}

				if (buff[ct] != 0x0E)
					buff[ct] = buff[ct] + 0x80;
				else
					ct++;
			}
			tmpbuf[sct++] = buff[ct];
		}
		tmpbuf[sct] = 0;

		rdct = sct;
		memset(buff, ' ', sizeof(bufin));

		//20220224 old strcpy((char *)buff, (char *)tmpbuf);
		strcpy_s((char*)buff, sizeof(bufin), (char*)tmpbuf);

		//wrtLogByLen(buff,sct,__FILE__,__LINE__);
		print_rxtx((char*)buff, rdct, 1);
	}

	return rdct;
}



// to avoid new ID flow jump to old flow unexpect
// because new ID flow, its flowName is drX????
int checkIsOldFlowAndPwdIsXXXX(char* flowName, char* buf, int len, int bgnPos)
{
	wrtLog("flowName=[%s] len=[%d], %s(%i)\n", flowName, len, __FILE__, __LINE__);
	wrtLogByLenX("xbuf=", &buf[bgnPos], len, __FILE__, __LINE__);

#if (0)  // 1: for test; 0: for normal
	if (1) {
#else
	if (flowName[0] != 'X' && flowName[0] != 'G' && flowName[0] != 'A' && flowName[0] != 'D') {
#endif

		// is OLD flow, p_a_s_s_w_o_r_d CANNOT be XXXX, find XXXX and place it with blank     //20220302 V6.3 ching2  modify hotfeb 弱掃   L3097
		// to avoid new ID flow jump to old flow unexpect
		int i;

		for (i = 0; i <= len - 4; i++) {
			//wrtLog(".....i=[%d], len-4=[%d] %s(%i)\n", i, len - 4, __FILE__, __LINE__);
			//wrtLogByLen(&buf[bgnPos + i], 4, __FILE__, __LINE__);
			if ('X' == buf[bgnPos + i] && 'X' == buf[bgnPos + i + 1] && 'X' == buf[bgnPos + i + 2] && 'X' == buf[bgnPos + i + 3]) {
				// find XXXX at &buf[bgnPos + i]
				buf[bgnPos + i] = ' ';
				buf[bgnPos + i + 1] = ' ';
				buf[bgnPos + i + 2] = ' ';
				buf[bgnPos + i + 3] = ' ';

				wrtLog("WARNING....replace XXXX to blank %s(%i)\n", __FILE__, __LINE__);


				break;
			}
		}

		wrtLogByLenX("xbuf=", &buf[bgnPos], len, __FILE__, __LINE__);
	}

	return 0;
	}




/*---------- send data to UNISYS host by TCP/IP ---------------------------*/
// TCP/IP 960911 add
// 961029 modify
int send_data(char* bufx, int slen)
{
	int sendlen, m;
	char bufou_head[12];
	char bufou_all[5124];
	char  sErrorData[256];
	char buf_len[7] = { 0 };
	char sSeqNo[7] = { 0 };
	unsigned char head_byte[4] = { 0 };
	unsigned char Seq_byte[4] = { 0 };

	for (m = 0; m < 3; m++) {
		//fdbprintf( "slen = %d | bufx = [%s]\n", slen, bufx);
		//wrtLogByLen(bufx, slen, __FILE__, __LINE__);
		//wrtLog("lineno=[%d], sendToHost=[%s], len=[%d] %s(%i)\n", lineno, bufx, slen+sizeof(bufou_head), __FILE__, __LINE__);
		{
			// get now seconds, and put it to this line var[25],
			// if   sendlen = write(syncfd, bufx, slen);   not halt, put 0 to this line var[25]
			// if   sendlen = write(syncfd, bufx, slen);   halt, this line var[25] is now

			// hotdlcc1 will check this line var[25], if it is 0, meaning HDLC driver OK
			// else HDLC driver halt; after 7 secnods, hotdlcc1 will shut down this line
			// and reload HDLC driver, after reload finish, it will restart hotfeb88

			time_t myNow;

			time(&myNow);
			wrtLog("vxp->voie=%d myNow=[%ld], %s(%i)\n", vxp->voie, myNow, __FILE__, __LINE__);

			//20220223old  sprintf(exVar[vxp->voie - 1].var[25], "%ld", myNow);
			//20220223 old 'sprintf_s(exVar[vxp->voie - 1].var[25], "%lld", myNow);
			//20220224 old sprintf_s(exVar[vxp->voie - 1].var[25], "%l64d", myNow);
			sprintf_s(exVar[vxp->voie - 1].var[25], "%lld", myNow);

		}
		// write data to TCP/IP
		wrtLog("if THIS LINE show here and screen NOT scroll up, meaning UNISYS Host halt now... %s(%i)\n", __FILE__, __LINE__);
		//sendlen = write(syncfd, bufx, slen);

		//960911 modify------

		//20220224 old sprintf(buf_len, "%06d", slen + sizeof(bufou_head));
		sprintf_s(buf_len, "%06d", slen + sizeof(bufou_head));

		HexToByte(buf_len, head_byte);

		//20220224 old sprintf(sSeqNo, "%06d", iSeqNo);
		sprintf_s(sSeqNo, "%06d", iSeqNo);

		HexToByte(sSeqNo, Seq_byte);
		iSeqNo++;
		if (iSeqNo > 9999)
			iSeqNo = 1;


		memset(bufou_head, 0, sizeof(bufou_head));
		memset(bufou_all, 0, sizeof(bufou_all));

		bufou_head[0] = 0x0f;
		bufou_head[1] = 0x0f;
		bufou_head[2] = 0x0f;
		bufou_head[3] = head_byte[0];
		bufou_head[4] = head_byte[1];
		bufou_head[5] = head_byte[2];
		bufou_head[6] = 0x01;
		bufou_head[7] = Seq_byte[0];
		bufou_head[8] = Seq_byte[1];
		bufou_head[9] = Seq_byte[2];
		bufou_head[10] = 0x0f;
		bufou_head[11] = 0x0f;

		//wrtLogByLen(bufx, strlen(bufx), __FILE__, __LINE__);
		memcpy(bufou_all, bufou_head, sizeof(bufou_head));
		memcpy(bufou_all + sizeof(bufou_head), bufx, strlen(bufx));
		memcpy(bufx, bufou_all, slen + sizeof(bufou_head));
		//fdbprintf("bufou=[%s]\n",bufou);

		{
			char flowName[16] = { 0 };

			memcpy(flowName, wvxp[linepos].applic, sizeof(wvxp[linepos].applic));
			wrtLog("hotfeb88 get flowName=[%s] linepos=[%d] bufou_head size=[%d] %s(%i)\n", flowName, linepos, sizeof(bufou_head), __FILE__, __LINE__);

			// to avoid new ID flow jump to old flow unexVarect
			// because new ID flow, its flowName is drX????
			checkIsOldFlowAndPwdIsXXXX(flowName, bufou, len, sizeof(bufou_head));
		}
		wrtLogByLenX("TCP to UNISYS=", bufou, len + sizeof(bufou_head), __FILE__, __LINE__);
		wrtLog("CHANDLE=[%d] %s(%i)\n", chandle, __FILE__, __LINE__);

		{
			char flowName[16] = { 0 };
			int nextFlowLine;

			memcpy(flowName, wvxp[linepos].applic, sizeof(wvxp[linepos].applic));
			nextFlowLine = wvxp[linepos].branch;

			wrtLog("TCPIP to UNISY lineNo=[%d] apName=[%s], flowNext=[%d], len=[%d] %s(%i)\n", lineno, flowName, nextFlowLine, slen + sizeof(bufou_head), __FILE__, __LINE__);
		}

		if ((sendlen = tcp_send(chandle, bufou, slen + sizeof(bufou_head))) == -1) {
			cHostTCPConnect = 0;
			wrtLog("set cHostTCPConnect to 0 %s(%i)\n", __FILE__, __LINE__);
			tcp_close(chandle);

			//20220224 old sprintf(sErrorData, "SendError bufou=[%s] Error Position 1\n", bufou);
			sprintf_s(sErrorData, "SendError bufou=[%s] Error Position 1\n", bufou);

			fdbprintf("%s", sErrorData);

			wrtLog("ERROR: Send TCPIP to UNISY FAIL lineNo=[%d] retcode=[%d] len=[%d] %s(%i)\n", lineno, sendlen, slen + sizeof(bufou_head), __FILE__, __LINE__);
			//wrtLogByLenX("TCPIP Send buf]", bufou, slen + sizeof(bufou_head), __FILE__, __LINE__);
		}
		else {
			// TCPIP sent to UNISYS OK

#ifdef _OTS_FOR_TEST  // 1: for test; 0: for normal
			char LF[2] = "\n";

			tcp_send(chandle, LF, strlen(LF));
			fdbprintf("Send line=%d len=%d  bufout=[%s]\n", lineno, len + sizeof(bufou_head), bufou);
#endif

			wrtLog("TCPIP to UNISYS OK lineNo=[%d], retcode=[%d] len=[%d] %s(%i)\n", lineno, sendlen, slen + sizeof(bufou_head), __FILE__, __LINE__);
			//wrtLogByLenX("TCPIP Send buf=", bufou, slen + sizeof(bufou_head), __FILE__, __LINE__);

			wrtLog("sSeqNo=[%s] %s(%i)\n", &sSeqNo[2], __FILE__, __LINE__);

			//20220224 old sprintf(vxp->message, "To UNISYS len=%d", sendlen);
			sprintf_s(vxp->message, 30, "To UNISYS len=%d", sendlen);

		}
		//--------------------------

		// if go to here, meaning:
		// TCP/IP write OK(not halt in write(), reset this line var[25] to 0
		// this action will disable hotdlcc1 to reload HDLC driver

		// if you want to test, comment follow two lines, hotdlcc1 will reload
		// HDLC Driver after 7 seconds. see hotdlcc1.c line 328
		wrtLog("set exVar[%d].var[25] to 0 %s(%i)\n", vxp->voie - 1, __FILE__, __LINE__);

		//20220224 old sprintf(exVar[vxp->voie - 1].var[25], "%ld", 0L);
		sprintf_s(exVar[vxp->voie - 1].var[25], "%ld", 0L);

		fdbprintf("send return code = %d %s(%i)\n", sendlen, __FILE__, __LINE__);
		wrtLog("lineno=[%d], send return code=%d %s(%i)\n", lineno, sendlen, __FILE__, __LINE__);

		if (sendlen > 0)
			break;
		else if (sendlen == 0) {
			Sleep(100);
			fdbprintf("send UNISYS Again %s(%i)\n\r", __FILE__, __LINE__);
		}
		else if (sendlen < 0) {
			fdbprintf("send UNISYS host Error rtn = %d %s(%i)\n\r", sendlen, __FILE__, __LINE__);
			break;
		}
		else
			break;
	}    //for (m=0; m < 3; m++) {

	if (sendlen < 0) {
		vxp->etatlig = '8';  /* error beep beep */


		//20220223 old
		//time(&lt);
		//tm = localtime(&lt);

		//20220223 new
		time_t now;
		struct tm newTime;

		time(&now);
		errno_t errNoT = localtime_s(&newTime, &now);


		//20220223 old sprintf(vxp->message, "UNISYS Off %02d/%02d %02d:%02d:%02d",
		//        newTime.tm_mon + 1, newTime.tm_mday, newTime.tm_hour, newTime.tm_min, newTime.tm_sec);

		//20220224 old sprintf(vxp->message, "UNISYS Off %02d/%02d %02d:%02d:%02d",
		sprintf_s(vxp->message, 30, "UNISYS Off %02d/%02d %02d:%02d:%02d",
			newTime.tm_mon + 1, newTime.tm_mday, newTime.tm_hour, newTime.tm_min, newTime.tm_sec);

		//20220223 old fdbprintf( "UNISYS Host Off %02d/%02d %02d:%02d:%02d %s(%i)\n",
		//       newTime.tm_mon + 1, newTime.tm_mday, newTime.tm_hour, newTime.tm_min, newTime.tm_sec, __FILE__, __LINE__);

		fdbprintf("UNISYS Host Off %02d/%02d %02d:%02d:%02d %s(%i)\n",
			newTime.tm_mon + 1, newTime.tm_mday, newTime.tm_hour, newTime.tm_min, newTime.tm_sec, __FILE__, __LINE__);



		wrtLog("UNISYS Host write() return < 0 %s(%i)\n", __FILE__, __LINE__);

		//hdlc_to_avr_fail( "E000", 4 );

		return 0;
	}
	else {
		vxp->etatlig = '1';
	}

	print_rxtx(bufx, sendlen, 2);

	return sendlen;
}








/*------------------------------- receive data to avr -----------------------*/
int set_exr_emis(char* buf, int set_len)
{
	char tato_sync, tato_line[4], recv_nap, recv_buf[9];
	char errorcode[5], tato_head[7];
	char  up_hour[3], up_min[3];  //data_ex[655] date_time[16],
	int  change_flag = 0, shour, smin;   //recv_len, 
	char testbuf[2048] = { 0 };
	int  send_len;  //, bufou_len;
	char msglen[4] = { 0 };

	int reSendTcpAgainFlag = 0;  // 2014-08-15 modify @@@@@

	/*
	move to after lineno = atoi(tato_line);
	if (strcmp(transcode[lineno], "G52") == 0 || strcmp(transcode[lineno], "G53") == 0)
	  return 0;
	*/

	//961102 modify for new tota basic label add 2 len (00)

	//20220224 old strncpy(testbuf, "00", 2);
	strncpy_s(testbuf, "00", 2);

	wrtLog("set_exr_emis 11111 %s(%i)\n", __FILE__, __LINE__);


	//20220224 old strcat(testbuf, buf);
	strcat_s(testbuf, buf);

	wrtLog("set_exr_emis 22222 %s(%i)\n", __FILE__, __LINE__);

	//20220224 old strcpy(buf, testbuf);
	//20220304 V6.5 ching2  E692 E690 mode    Now HOST UNISYS is mode 1   bug
	//20220304 old strcpy_s(buf, set_len, testbuf);
	strcpy_s(buf, sizeof(testbuf) , testbuf);

	wrtLog("set_exr_emis 3333 %s(%i)\n", __FILE__, __LINE__);

	wrtLogByLenX("buf=", buf, strlen(buf), __FILE__, __LINE__);

	//20220224 old strncpy(tato_head, buf + 10, 5);               // TXTNO 9(5)
	strncpy_s(tato_head, buf + 10, 5);               // TXTNO 9(5)

	tato_head[5] = 0;
	wrtLog("tato_head=[%s] %s(%i)\n", tato_head, __FILE__, __LINE__);

	recv_nap = tato_head[0];                       // nap
	tato_sync = tato_head[1];                      // sync

	//20220224 old strncpy(tato_line, tato_head + 3, 2);          // line no
	strncpy_s(tato_line, tato_head + 3, 2);          // line no

	tato_line[2] = 0;

	//20220224 old strncpy(tato_head, buf + 15, 2);
	strncpy_s(tato_head, buf + 15, 2);

	tato_head[2] = 0;

	//20220224 old strncpy(errorcode, buf + 20, 4);                 // MTYPR+MSGNO   error code
	strncpy_s(errorcode, buf + 20, 4);                 // MTYPR+MSGNO   error code

	errorcode[4] = 0;

	wrtLog("errorcode=[%s] %s(%i)\n", errorcode, __FILE__, __LINE__);

	//20220224 old strncpy(msglen, buf + 24, 3);                     // msglen 961121
	strncpy_s(msglen, buf + 24, 3);                     // msglen 961121

	msglen[3] = 0;

	lineno = atoi(tato_line);
	_gLineno = lineno;

	wrtLog("lineno=[%d], tota_sync=[%c], len=[%d], recvFrUnisys=[%s] %s(%d)\n", lineno, tato_sync, set_len, buf, __FILE__, __LINE__);

	if (strcmp(transcode[lineno], "G52") == 0 || strcmp(transcode[lineno], "G53") == 0)
		return 0;

	if (lineno < 1 || lineno > chnum) {

		//20220223 old
		 //time(&lt);
		 //tm = localtime(&lt);

		 //20220223 new
		time_t now;
		struct tm newTime;

		time(&now);
		errno_t errNoT = localtime_s(&newTime, &now);


		// sprintf(vxp->message, "Recv Mess error [%d] %02d:%02d", lineno, newTime.tm_hour, newTime.tm_min);
		return 0;
	}

	linepos = lineno - 1;

	//20220224 old sprintf(recv_buf, "%c%03s%c%02d", recv_nap, transcode[lineno], tato_sync, lineno);
	sprintf_s(recv_buf, "%c%03s%c%02d", recv_nap, transcode[lineno], tato_sync, lineno);

	recv_buf[7] = 0;

	wrtLog("recv header_7_bytes chk_buf[%d]=[%s], recv_buf=[%s] %s(%i)\n", linepos, chk_buf[linepos], recv_buf, __FILE__, __LINE__);

	if (strcmp(chk_buf[linepos], recv_buf) != 0)
		return 0;

	buf[0] = '0';


	//20220304 V6.5 ching2  E692 E690 mode    Now HOST UNISYS is mode 1   bug

	if (strcmp(errorcode, "E692") == 0 || strcmp(errorcode, "E690") == 0) {  // 2014-08-18 modify ###@@
	  // ERROR 692 will change system time

		wrtLog("E692, Now HOST UNISYS is mode 1 %s(%d)\n", __FILE__, __LINE__);
		//mode_assign = 1;  //970102 mark
		 //buf[0] = '1';

		//strncpy(up_hour, buf+45, 2);
		//strncpy(up_min, buf+47, 2);

		// 2009-04-07
		//20220224 old strncpy(up_hour, buf + 48, 2);
		strncpy_s(up_hour, buf + 48, 2);

		//20220224 old strncpy(up_min, buf + 50, 2);
		strncpy_s(up_min, buf + 50, 2);

		up_hour[2] = 0;
		up_min[2] = 0;

		shour = atoi(up_hour);
		smin = atoi(up_min);

		//20220223 old
		 //time(&lt);
		 //tm = localtime(&lt);

		 //20220223 new
		time_t now;
		struct tm newTime;

		time(&now);
		errno_t errNoT = localtime_s(&newTime, &now);

		// update system time
		update(shour, smin);

		mode_assign = 1;  //970102 modify
		buf[0] = '1';

		//20220224 old sprintf(exVar[LineTotal - 3].var[9], "%04d", 1);
		sprintf_s(exVar[LineTotal - 3].var[9], "%04d", 1);

		exVar[LineTotal - 3].var[9][4] = 0;

		//20220224 old (exVar[LineTotal - 3].var[2], "%04d", 1);
		sprintf_s(exVar[LineTotal - 3].var[2], "%04d", 1);

		exVar[LineTotal - 3].var[2][4] = 0;

		fdbprintf("E692 -- exVar[LineTotal-3].var[2] = %d\n", atoi(exVar[LineTotal - 3].var[2]));
		wrtLog("E692 -- exVar[%d].var[2]=%d %s(%i)\n", LineTotal - 3, atoi(exVar[LineTotal - 3].var[2]), __FILE__, __LINE__);

		if (strcmp(exVar[linepos].etran, "G01") == 0)
		{
			// mode 2 -> 1
			// send again, but atmseq++, meaning host mode now is 1, so I send again mode use 1
			int pork;

			wrtLog("E692 send again............%s(%i)\n", __FILE__, __LINE__);
			pork = emion(bufou, 11, 0, __FILE__, __LINE__);
			wrtLog("pork=[%c] %s(%i)\n", pork, __FILE__, __LINE__);


			struct {
				char pidNo[10];
				char pidNoErr;
				char userNo[4];
				char myNull;
			} TIG01;


			struct {
				char pidNo[10];
				char pidNoErr;
				char userNo[4];
				char accno[14];
				char myNull;
			} TIG51;


			memset(&TIG01, 0, sizeof(TIG01));
			memset(&TIG51, 0x20, sizeof(TIG51));

			if (strlen(exVar[linepos].var[21]) == 14)
			{
				memcpy(TIG51.accno, exVar[linepos].var[21], 14);

				//20220224 old strcat(bufou, (const char *)&TIG51);
				strcat_s(bufou, (const char*)&TIG51);

				wrtLogByLenX("ACC G51 First check", bufou, strlen(bufou), __FILE__, __LINE__);

			}
			else
			{

				memcpy(TIG01.pidNo, exVar[linepos].var[21], sizeof(TIG01.pidNo));
				TIG01.pidNoErr = '0';
				memcpy(TIG01.userNo, "0000", 4);

				//20220224 old strcat(bufou, (const char *)&TIG01);
				strcat_s(bufou, (const char*)&TIG01);

				wrtLogByLenX("Id G01 First check", bufou, strlen(bufou), __FILE__, __LINE__);
			}


			send_len = send_data(bufou, strlen(bufou));
			reSendTcpAgainFlag = 1;    // 2014-08-18 modify ###@@

		}

		if (strcmp(exVar[linepos].etran, "G04") == 0) {
			// mode 2 -> 1
			// send again, but atmseq++, meaning host mode now is 1, so I send again mode use 1
			int pork;

			pork = emion(bufou, 14, 0, __FILE__, __LINE__);
			wrtLog("pork=[%c] %s(%i)\n", pork, __FILE__, __LINE__);

			{
				struct {
					char itemCd[2];
					char bkNo[4];
					char myNull;
				} TIG69;

				memset(&TIG69, 0, sizeof(TIG69));

				memcpy(TIG69.itemCd, "01", 2);
				memcpy(TIG69.bkNo, (atoi(exVar[linepos].var[22]) == 1) ? "805" : exVar[linepos].var[15], 3);

				//20220224 old strcat(bufou, (const char *)&TIG69);
				strcat_s(bufou, (const char*)&TIG69);

				wrtLogByLen(bufou, strlen(bufou), __FILE__, __LINE__);
			}

			send_len = send_data(bufou, strlen(bufou));
			reSendTcpAgainFlag = 1;    // 2014-08-18 modify ###@@

		}
	}

	// 2010-01-28
	if (strcmp(errorcode, "E691") == 0) {
		// ERROR 691, we should send host again with mode 2

		wrtLog("E691, Now HOST UNISYS is mode 2 %s(%d)\n", __FILE__, __LINE__);
		//mode_assign = 2;  //970102 mark
		 //buf[0] = '1';

		//strncpy(up_hour, buf+45, 2);
		//strncpy(up_min, buf+47, 2);

		// 2009-04-07
		//20220224 old strncpy(up_hour, buf + 48, 2);
		strncpy_s(up_hour, buf + 48, 2);

		//20220224 old strncpy(up_min, buf + 50, 2);
		strncpy_s(up_min, buf + 50, 2);

		up_hour[2] = 0;
		up_min[2] = 0;

		shour = atoi(up_hour);
		smin = atoi(up_min);

		//20220223 old
		 //time(&lt);
		 //tm = localtime(&lt);

		 //20220223 new
		time_t now;
		struct tm newTime;

		time(&now);
		errno_t errNoT = localtime_s(&newTime, &now);

		// update system time
		//update(shour, smin);

		mode_assign = 2;  //970102 modify
		buf[0] = '1';

		//20220224 old sprintf(exVar[LineTotal - 3].var[9], "%04d", 1);
		sprintf_s(exVar[LineTotal - 3].var[9], "%04d", 1);

		exVar[LineTotal - 3].var[9][4] = 0;

		//20220224 old sprintf(exVar[LineTotal - 3].var[2], "%04d", 1);
		sprintf_s(exVar[LineTotal - 3].var[2], "%04d", 1);

		exVar[LineTotal - 3].var[2][4] = 0;

		fdbprintf("E691 -- exVar[LineTotal-3].var[2] = %d\n", atoi(exVar[LineTotal - 3].var[2]));
		wrtLog("E691 -- exVar[%d].var[2]=%d %s(%i)\n", LineTotal - 3, atoi(exVar[LineTotal - 3].var[2]), __FILE__, __LINE__);

		if (strcmp(exVar[linepos].etran, "G01") == 0) {
			// mode 1 -> 2
			// send again, but atmseq++, meaning host mode now is 2, so I send again mode use 2
			int pork;

			wrtLog("E691 send again............%s(%i)\n", __FILE__, __LINE__);
			pork = emion(bufou, 11, 0, __FILE__, __LINE__);
			wrtLog("pork=[%c] %s(%i)\n", pork, __FILE__, __LINE__);


			struct {
				char pidNo[10];
				char pidNoErr;
				char userNo[4];
				char myNull;
			} TIG01;

			struct {
				char pidNo[10];
				char pidNoErr;
				char userNo[4];
				char accno[14];
				char myNull;
			} TIG51;



			memset(&TIG01, 0, sizeof(TIG01));
			memset(&TIG51, 0x20, sizeof(TIG51));

			if (strlen(exVar[linepos].var[21]) == 14)
			{
				memcpy(TIG51.accno, exVar[linepos].var[21], 14);

				//20220224 old strcat(bufou, (const char *)&TIG51);
				strcat_s(bufou, (const char*)&TIG51);

				wrtLogByLenX("ACC G51 First check", bufou, strlen(bufou), __FILE__, __LINE__);

			}
			else
			{

				memcpy(TIG01.pidNo, exVar[linepos].var[21], sizeof(TIG01.pidNo));
				TIG01.pidNoErr = '0';
				memcpy(TIG01.userNo, "0000", 4);

				//20220224 old strcat(bufou, (const char *)&TIG01);
				strcat_s(bufou, (const char*)&TIG01);

				wrtLogByLenX("Id G01 First check", bufou, strlen(bufou), __FILE__, __LINE__);
			}


			send_len = send_data(bufou, strlen(bufou));

			reSendTcpAgainFlag = 1;    // 2014-08-15 modify @@@@@
		}

	}

	if (strcmp(errorcode, "E690") == 0) {
		mode_assign = 1;
		buf[0] = '3';

		//20220224 old sprintf(exVar[LineTotal - 3].var[9], "%04d", 1);
		sprintf_s(exVar[LineTotal - 3].var[9], "%04d", 1);

		exVar[LineTotal - 3].var[9][4] = 0;
	}

	if (strcmp(errorcode, "E691") == 0) {
		mode_assign = 2;
		buf[0] = '2';

		//20220224 old sprintf(exVar[LineTotal - 3].var[9], "%04d", 2);
		sprintf_s(exVar[LineTotal - 3].var[9], "%04d", 2);

		exVar[LineTotal - 3].var[9][4] = 0;
	}

	//970102 add

	//20220224 old sprintf(exVar[LineTotal - 3].var[9], "%04d", mode_assign);
	sprintf_s(exVar[LineTotal - 3].var[9], "%04d", mode_assign);

	exVar[LineTotal - 3].var[9][4] = 0;

	if (change_flag == 1)
		fdbprintf("write open.dat OK !! mode = %d\n", mode_assign);

	buf[set_len - 1] = 0;

	if (strcmp(transcode[lineno], "P70") == 0 || strcmp(transcode[lineno], "P10") == 0) {
		if (errorcode[0] != 'E') {
			if (trans_flag[linepos] != 1)
				return 0;
			else
				trans_flag[linepos] = 0;
		}
	}

	fdbprintf(" etran = %s \n", exVar[linepos].etran);
	fdbprintf(" errorcode = %s \n", errorcode);

	wrtLog("exVar[%d].etran=[%s] errorcode[0]=[%c] %s(%i)\n", linepos, exVar[linepos].etran, errorcode[0], __FILE__, __LINE__);


	if (strcmp(exVar[linepos].etran, "G01") == 0) {
		if (errorcode[0] != 'E') {
			wrtLog("buf[19]=[%c] %s(%i)\n", buf[19], __FILE__, __LINE__);

			//1000406 sven add, 不檢查是否有資料要繼續下來, 這邊已檢查過error code 
			buf[19] = '1';

			if (buf[19] != '1') {         // '1' no data    '0' wait data
				wrtLog("wait NEXT data to write .... (idAllAccNoFile%02d.dat) %s(%i)\n", linepos + 1, __FILE__, __LINE__);
				return 0;
			}
			else
				wrtLog("write FINISH (idAllAccNoFile%02d.dat) %s(%i)\n", linepos + 1, __FILE__, __LINE__);
		}
	}





	if (errorcode[0] != 'E' && strcmp(exVar[linepos].etran, "G00") != 0)
		//20220224 old strcpy(exVar[linepos].var[8], "SUCC");
		strcpy_s(exVar[linepos].var[8], "SUCC");

	memcpy(exxp[linepos].chain, buf, set_len - 1);
	exxp[linepos].chain[set_len - 1] = 0;


	wrtLog("exVar[%d].eemis = [%d] %s(%i)\n", linepos, (int)exVar[linepos].eemis, __FILE__, __LINE__);
	wrtLog("exVar[%d].etran = [%s] transcode[%d] = [%s] %s(%i)\n", linepos, exVar[linepos].etran, lineno, transcode[lineno], __FILE__, __LINE__);
	wrtLog("exVar[%d].esync = [%d] tota_sync=[%d] %s(%i)\n", linepos, (int)exVar[linepos].esync, (int)tato_sync, __FILE__, __LINE__);


	//strncpy(exVar[linepos].rtran, transcode[lineno], 3);

	  //20220224 old strncpy(exVar[linepos].rtran, exVar[linepos].etran, 3); 
	strncpy_s(exVar[linepos].rtran, exVar[linepos].etran, 3);

	exVar[linepos].rtran[3] = 0;

	//exVar[linepos].rsync = tato_sync;
	exVar[linepos].rsync = exVar[linepos].esync;


	wrtLog("..exVar[%d].remis=[%d] %s(%i)\n", linepos, (int)exVar[linepos].remis, __FILE__, __LINE__);
	wrtLog(".....exVar[%d].etran=[%s] transcode[%d]=[%s] %s(%i)\n", linepos, exVar[linepos].etran, lineno, transcode[lineno], __FILE__, __LINE__);
	wrtLog(".....exVar[%d].rtran=[%s] transcode[%d]=[%s] %s(%i)\n", linepos, exVar[linepos].rtran, lineno, transcode[lineno], __FILE__, __LINE__);

	wrtLog("..exVar[%d].rsync=[%d] tota_sync=[%d] %s(%i)\n", linepos, (int)exVar[linepos].rsync, (int)tato_sync, __FILE__, __LINE__);
	wrtLog("..exVar[%d].esync=[%d] tota_sync=[%d] %s(%i)\n", linepos, (int)exVar[linepos].esync, (int)tato_sync, __FILE__, __LINE__);

	//wrtLog("exVar[%d].remis be set to 64 %s(%i)\n", linepos, __FILE__, __LINE__);  // 2014-08-18 modify ###@@

	if (0 == reSendTcpAgainFlag) {  // 2014-08-18 modify ###@@
		wrtLog("exVar[%d].remis be set to 64 %s(%i)\n", linepos, __FILE__, __LINE__);  // 2014-08-18 modify ###@@
		exVar[linepos].remis = 64;    // 2014-08-18 modify ###@@
	}                             // 2014-08-18 modify ###@@


	 //20220223 old
	  //time(&lt);
	  //tm = localtime(&lt);

	  //20220223 new
	time_t now;
	struct tm newTime;

	time(&now);
	errno_t errNoT = localtime_s(&newTime, &now);

	/*
	sprintf(vxp->message, "Recv ln=%02d[%s]%d %02d:%02d %d",lineno,transcode[lineno],
			 len, newTime.tm_hour, newTime.tm_min, mode_assign);
	*/
	return 0;
}





/*---loop=> intrest : 0802-15:20 exchange : 08:05-15:20 open : 08:00-15:40 ---*/
int p400(void)
{

	int   ll = 0, send_len;
	char  sErrorData[256];
	int    stran, live_flag = 0;
	FILE* fptcp;
	char remoteAdd[32] = { 0 }, remotePort[8] = { 0 }, localAdd[32] = { 0 }, localPort[8] = { 0 };
	char host_ip[32], host_port[8];

	int restatus;
	int Hostlive_flag = 0;
	int PingAS400 = 0;


	//971211 ching2
	FILE* cfp;
	char sTemp[200];



	//20220223 old
	//time_t lt;
	//struct tm* tm;

	//20220223 new
	time_t now;
	struct tm newTime;

	time(&now);
	errno_t errNoT = localtime_s(&newTime, &now);


	wvxp = &vxp[-vxp->voie + 1];


	fdbprintf("!!! Star hotfeb88.cpp's p400.c !!!\r\n");
	wrtLog("!!! hotfeb88.cpp p400 begin !!! %s(%i)\n", __FILE__, __LINE__);


	fptcp = NULL;
	tcp_logfp(fptcp);

	memset(TRM1, 0, sizeof(TRM1));
	GetPrivateProfileString("HDLCPAR", "TRMNO", 0, TRM1, sizeof(TRM1), gIvrIniFile);

	//960911
	restatus = tcp_handle_init(MAX_CLIENT);
	fdbprintf("tcp_handle_init restatus=[%d]\n", restatus);


	iSendTimes = 0;
	iRecvTimes = 0;
	cTCPConnect = 0;
	iLineOk = 0;


	//960911 add connect host2------
	// for UNISY TCP/IP IP and port
	GetPrivateProfileString("UNISYS", "ip", 0, host_ip, sizeof(host_ip), gIvrIniFile);
	GetPrivateProfileString("UNISYS", "port", 0, host_port, sizeof(host_port), gIvrIniFile);

	iHostSendTimes = 0;
	iHostRecvTimes = 0;
	cHostTCPConnect = 0;

	// tcp connect to UNISY
	chandle = tcp_connect(host_ip, host_port);

	fdbprintf("UNISYS host IP and Port Num[%s][%s] chandle=(%d) \n", host_ip, host_port, chandle);
	wrtLog("UNISYS IP and Port Num[%s][%s] chandle=(%d) %s(%i)\n", host_ip, host_port, chandle, __FILE__, __LINE__);

	if (tcp_check_nh(chandle) == TCP_C_CONNECTED) {
		cHostTCPConnect = 1;

		//20220224 old sprintf(vxp->message, "Connect to UNISYS Ok.");
		sprintf_s(vxp->message, 30, "Connect to UNISYS Ok.");

		wrtLog("Connect to UNISYS Ok, chandle=%d %s(%i)\n", chandle, __FILE__, __LINE__);
		//time(&lSendTime);
	}
	wrtLog("...UNISYS...chandle=[%d] %s(%i)\n", chandle, __FILE__, __LINE__);

	cSendCount = 0;

	//20220223 new
	//time_t now;
	//struct tm newTime;

	time(&now);
	errNoT = localtime_s(&newTime, &now);



	wrtLog("...UNISYS...chandle=[%d] %s(%i)\n", chandle, __FILE__, __LINE__);

	BRNO[3] = 0;
	open_time = 0;
	mode_flag = 0;
	wrtLog("...UNISYS...chandle=[%d] %s(%i)\n", chandle, __FILE__, __LINE__);

	GetPrivateProfileString("SYSCONF", "SetSequenceNo", "01", cf0.setno, sizeof(cf0.setno), gIvrIniFile);

	//20220224 old sprintf(set_no, "%02s", cf0.setno);           // set no
	sprintf_s(set_no, "%02s", cf0.setno);           // set no

	set_no[2] = 0;

	wrtLog("...UNISYS...chandle=[%d] %s(%i)\n", chandle, __FILE__, __LINE__);
	set_seq = atoi(set_no);

	wrtLog("...UNISYS...chandle=[%d] %s(%i)\n", chandle, __FILE__, __LINE__);

	GetPrivateProfileString("SYSCONF", "TotalTaskLines", "16", cf0.mxln, sizeof(cf0.mxln), gIvrIniFile);

	//20220224 old sprintf(Line, "%02s", cf0.mxln);
	sprintf_s(Line, "%02s", cf0.mxln);

	Line[2] = 0;
	LineTotal = atoi(Line);

	wrtLog("..UNISYS....chandle=[%d] %s(%i)\n", chandle, __FILE__, __LINE__);

	{
		char flowName[16] = { 0 };

		wrtLog("LineTotal=[%d] %s(%i)\n", LineTotal, __FILE__, __LINE__);
		memcpy(flowName, wvxp[LineTotal - 3].applic, sizeof(wvxp[LineTotal - 3].applic));
		wrtLog("apName=[%s]... %s(%i)\n", flowName, __FILE__, __LINE__);
	}

	fdbprintf("set_no = %s set_seq = %d\n", set_no, set_seq);
	trmno = newTime.tm_min + 100;
	intrest_time = newTime.tm_min + 3;

	if (intrest_time > 59)
		intrest_time -= 60;

	exchange_time = newTime.tm_min + 10;

	if (exchange_time > 59)
		exchange_time -= 60;

	fdbprintf("intrest rate ask time = %d\n", intrest_time);
	fdbprintf("exchange rate ask time = %d\n", exchange_time);
	fdbprintf("AVR -> HOST Ready\r\n");

	mode_assign = 2;

#if (0) // 1: for test; 0: for normal
	mode_assign = 1;
#endif

	wrtLog("LineTotal=[%d] %s(%i)\n", LineTotal, __FILE__, __LINE__);

	//20220224 old sprintf(exVar[LineTotal - 3].var[9], "%04d", 2);
	sprintf_s(exVar[LineTotal - 3].var[9], "%04d", 2);

	exVar[LineTotal - 3].var[9][4] = 0;


	while (1)
	{

		// v1.1   971211   ching2    add chkOpen & chk_In  write ./moni/Lxx.txt for hotmoni
		//20220223 new
		time_t now;
		struct tm newTime;

		time(&now);
		errno_t errNoT = localtime_s(&newTime, &now);

		if (newTime.tm_sec == 0)
		{
			Sleep(1000);

			//20220224 old sprintf(sTemp, ".\\moni\\L%02d.txt", voie );
			sprintf_s(sTemp, ".\\moni\\L%02d.txt", voie);

			//20220224 old 
			//if ((cfp = fopen(sTemp,"w+")) == NULL) 
			//{
			//  fdbprintf( "open %s error !!\n", sTemp);
			//}

		  //20220224 new  
			errno_t myErrNoT = fopen_s(&cfp, sTemp, "w+");
			if (myErrNoT != 0)
			{
				// open error 
				//fdbprintf( "open %s error !!\n", sTemp);
			}

			else
			{
				fdbprintf("open %s ok & write time !!\n", sTemp);
				fprintf(cfp, "%02d:%02d:%02d \n", newTime.tm_hour, newTime.tm_min, newTime.tm_sec);
				fclose(cfp);
			}
		}

		//usleep(1000);
		if (vxp->command == '5')
		{
			wrtLog("tcp_close() stcp=[%d] %s(%i)\n", stcp, __FILE__, __LINE__);

			wrtLog("tcp_close() chandle=[%d] %s(%i)\n", chandle, __FILE__, __LINE__);
			tcp_close(chandle);  //960911
			cHostTCPConnect = 0;
			wrtLog("set cHostTCPConnect to 0 %s(%i)\n", __FILE__, __LINE__);

			if (NULL != fptcp)
				fclose(fptcp);

			return 0;
		}

		vxp->nbappel = iRecvTimes;

		//20220224 old sprintf(vxp->rcvdig, "%5d", iSendTimes);
		sprintf_s(vxp->rcvdig, 6, "%5d", iSendTimes);

		memset(bufou, ' ', sizeof(bufou));

		/* send Fund Alive 90.10.04 */
		//20220223 new
		//time_t now;
		//struct tm newTime;

		time(&now);
		errNoT = localtime_s(&newTime, &now);

		if ((newTime.tm_sec % 30) == 0 && cTCPConnect == 1) {
			if (live_flag == 0) {

				//20220224 old strcpy(bufou, "0010*ALIVE");
				strcpy_s(bufou, "0010*ALIVE");

				len = strlen(bufou);

				tcp_getsockname(stcp, localAdd, localPort, remoteAdd, remotePort);
				fdbprintf("Send alive bufou = (%s), len = (%d) \n", bufou, len);

				// send 0010*ALIVE
				if (tcp_send(stcp, bufou, len) == -1) {
					tcp_close(stcp);
					cTCPConnect = 0;

					//20220224 old sprintf(sErrorData, "SendError bufou=[%s] Error Alive\n", bufou);
					sprintf_s(sErrorData, "SendError bufou=[%s] Error Alive\n", bufou);

					wrtLog("SendError bufou=[%s] Error Alive %s(%i)\n", bufou, __FILE__, __LINE__);
				}
				else {

					if (gTcpSent == 0) {
						gTcpSent = 1;
						time(&gTcpSendTime);
					}

					live_flag = 1;
					fdbprintf("Send Alive Ok !!\r\n");
					//wrtLog("Send Alive Ok %s(%i)\n", __FILE__, __LINE__);
				}
			}
			// sleep(1);
		}
		else {
			live_flag = 0;
		}

		//960911 add connect host2------
		if ((newTime.tm_sec % 30) == 0 && cHostTCPConnect == 1) {
			if (Hostlive_flag == 0) {
				int isHostConnect;
				char pingCmd[256];

				//20220224 old sprintf(pingCmd, "ping -c 1 %s | grep \"packet loss\"", host_ip);
				sprintf_s(pingCmd, "ping -c 1 %s | grep \"packet loss\"", host_ip);

				//fdbprintf("pingCmd=[%s]\n",pingCmd);
				// because tcp_connect will need 180 seconds if host ip is not connect
				// so, first use pingHost to check host ip is connected or not
				isHostConnect = pingHost(pingCmd, __FILE__, __LINE__);

				// pingHost just need 10 seconds if host ip is not connect
				if (isHostConnect != 1) {
					// host ip now is NOT connect, do not execute tcp_connect
					tcp_close(chandle);  //960911
					cHostTCPConnect = 0;
					wrtLog("set cHostTCPConnect to 0 %s(%i)\n", __FILE__, __LINE__);

					wrtLog("cmd=[%s] return 100%% packet loss %s(%i)\n", pingCmd, __FILE__, __LINE__);
				}
				Hostlive_flag = 1;
			}
		}
		else {
			Hostlive_flag = 0;
		}

		//-------------------------

		if ((stran = chk_exe_emis())) {  /* send Host ACK/NAK pending */
			wrtLog("stran=%d, %s(%i)\n", stran, __FILE__, __LINE__);
			wrtLog("UNISYS HOST TCP Data %s(%i)\n", __FILE__, __LINE__);

			if ((len = pro_data(bufou)) > 0) {

				wrtLog("linepos=%d, etran=[%s], mode=%d %s(%i)\n", linepos, exVar[linepos].etran, mode_assign, __FILE__, __LINE__);

				//20220224 old sprintf(transcode[lineno], "%03s", exVar[linepos].etran);
				sprintf_s(transcode[lineno], "%03s", exVar[linepos].etran);

				transcode[lineno][3] = 0;


				char flowName[16] = { 0 };
				memcpy(flowName, wvxp[linepos].applic, sizeof(wvxp[linepos].applic));
				wrtLog("hotfeb88 get flowName=[%s] linepos=[%d] %s(%i)\n", flowName, linepos, __FILE__, __LINE__);

				wrtLogByLenX("TCP SEND UNISYS HOST=", bufou, len, __FILE__, __LINE__);
				send_len = send_data(bufou, len);
				exVar[linepos].eemis = 0;     //9301
			}

		}




		//------ 960911 add for host tcp/ip --------
		// check TCPIP RECEIVE from UNISYS host

		if (cHostTCPConnect == 1)
		{
			memset(bufin, 0, sizeof(bufin));

			if ((len = recvsync((unsigned char*)bufin)) > 0)
			{
				/* data from host */
				wrtLog("TCP RECV FROM UNISYS HOST len=%d %s(%i)\n", len, __FILE__, __LINE__);
				wrtLogByLenX("TCP RECV bufin=", bufin, len, __FILE__, __LINE__);
				set_exr_emis(bufin, len);
				//wrtLog("after set_exr_emis bufin=[%s] %s(%i)\n", bufin, __FILE__, __LINE__);
			}
		}
		else
		{
			// try connect to HOSTServer
			// now cTCPConnect is 0
			time_t reConnHostNow;
			time(&reConnHostNow);
			//wrtLog("%ld %ld %s(%i)\n", reConnHostNow, tcpReConnHostTimeOld, __FILE__, __LINE__);

			if (labs(reConnHostNow - tcpReConnHostTimeOld) >= 5L)
			{
				tcpReConnHostTimeOld = reConnHostNow;
				wrtLog("try reConnect Host_connect() %s(%i)\n", __FILE__, __LINE__);

				//20220224 old sprintf(vxp->message, "trying ReConnect UNISYS");
				sprintf_s(vxp->message, 30, "trying ReConnect UNISYS");

				{
					int isHostConnect;
					char pingCmd[256];

					//20220224 old sprintf(pingCmd, "ping -c 1 %s | grep \"packet loss\"", host_ip);
					sprintf_s(pingCmd, "ping -c 1 %s | grep \"packet loss\"", host_ip);

					// because tcp_connect will need 180 seconds if host ip is not connect
					// so, first use pingHost to check host ip is connected or not
					isHostConnect = pingHost(pingCmd, __FILE__, __LINE__);

					// pingHost just need 10 seconds if host ip is not connect
					if (isHostConnect == 1) {
						// host ip now is connect, execute tcp_connect to UNISYS
						chandle = tcp_connect(host_ip, host_port);
						wrtLog("reConnect UNISYS HOST tcp_connect() chandle=[%d] %s(%i)\n", chandle, __FILE__, __LINE__);
					}
					else {
						// host ip now is NOT connect UNISYS, do not execute tcp_connect
						wrtLog("cmd=[%s] return 100%% packet loss to UNISYS %s(%i)\n", pingCmd, __FILE__, __LINE__);
					}
				}

				if (tcp_check_nh(chandle) == TCP_C_CONNECTED) {
					cHostTCPConnect = 1;

					//20220224 old sprintf( vxp->message, "ReConnect to UNISYS Ok.");
					sprintf_s(vxp->message, 30, "ReConnect to UNISYS Ok.");

					wrtLog("ReConnect to UNISYS Ok handle=%d %s(%i)\n", chandle, __FILE__, __LINE__);
					tcpReConnHostTimeOld = 0L;
				}
			}   //if (lab)
			Sleep(100);
		}

	}

}






//-----------------------------------------------------------------------------
//  NO:0 funSet_Priority()   create by ching2 961116
//
//       set priority 設該程式的執行優先權 
//        
//  IN : 
//
//       "Realtime"          24
//       "High"              13
//       "Above Normal"      10
//       "Normal"             8
//       "Below Normal"       6
//       "Idle"               4
//
//  OUT: 無

/*
Realtime        24
High            13
Above Normal    10
Normal          8
Below Normal    6
Idle            4


REALTIME_PRIORITY_CLASS      0x00000100;
HIGH_PRIORITY_CLASS          0x00000080;
ABOVE_NORMAL_PRIORITY_CLASS  0x00008000;
NORMAL_PRIORITY_CLASS        0x00000020;
BELOW_NORMAL_PRIORITY_CLASS  0x00004000;
IDLE_PRIORITY_CLASS          0x00000040;

// 所有都Normal   hot 設 High
//                語音設 Realtime  drint64ip.exe hotcodec.exe  SipRegSvr.exe
//                trol SerMain 設 Realtime


*/

//-----------------------------------------------------------------------------
int funSet_Priority(char* set)
{

	if (strcmp(set, "Realtime") == 0)
	{
		fdbprintf("Realtime 24 \r\n");
		if (SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS) == false)    //1.
		{
			fdbprintf(" SET NOK \r\n");
			return(-1);
		}

	}
	else if (strcmp(set, "High") == 0)
	{
		fdbprintf("High 13 \r\n");
		if (SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS) == false)        //2.
		{
			fdbprintf(" SET NOK \r\n");
			return(-1);
		}
	}

	else if (strcmp(set, "Above Normal") == 0)
	{
		fdbprintf("Above Normal 10 \r\n");
		//SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS);  //3.
		if (SetPriorityClass(GetCurrentProcess(), 0x00008000) == false)
		{
			fdbprintf(" SET NOK \r\n");
			return(-1);
		}
	}

	else if (strcmp(set, "Normal") == 0)
	{
		fdbprintf("Normal 8 \r\n");
		if (SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS) == false)      //4.
		{
			fdbprintf(" SET NOK \r\n");
			return(-1);
		}
	}

	else if (strcmp(set, "Below Normal") == 0)
	{
		fdbprintf("Below Normal 6 \r\n");
		//SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);  //5.
		if (SetPriorityClass(GetCurrentProcess(), 0x00004000) == false)
		{
			fdbprintf(" SET NOK \r\n");
			return(-1);
		}
	}
	else if (strcmp(set, "Idle") == 0)
	{
		fdbprintf("Idle 4 \r\n");
		if (SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS) == false)         //6.
		{
			fdbprintf(" SET NOK \r\n");
			return(-1);
		}
	}
	else
	{
		return(-1);
	}


	fdbprintf(" SET OK \r\n");
	return(1);

}






//-----------------------------------------------------------------------------
//  NO:12 main()
//
//       主程式
//        
//  IN : 無
//  OUT: 無
//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{
	signal(SIGTERM, err_stop);
	signal(SIGINT, SIG_IGN);

	funSet_Priority("High");   // 所有都Normal   hot 設 High  語音設 Realtime  drint64ip.exe hotcodec.exe  SipRegSvr.exe  trol SerMain 設 Realtime

	voie = atoi(argv[1]) + 1;


	//fdbprintf("hotGen v1.2 970312");  //970312
	//1060327 bug  需在 P100() 以後, 否則chk_exe_emis() 會當
	// exVar = exVar;

	if (p100() >= 0)
	{
		//20220208 add
		exVar = exVar;  //1060327 bug  需在 P100() 以後, 否則chk_exe_emis() 會當

		fdbprintf("voie %d......\n", voie);       //voie 47......
		fdbprintf("max chnum = %d \n", chnum);
		fdbprintf("comport = %d \n", comport);
		p400();
	}
	else
	{
		//fdbprintf("dbg......2");
	}
	p900();

	return 0;

}






//20220208 OLD
//
//DWORD WINAPI Thread_funCALL_L01(LPVOID lpparam)
//{
//	int  linepos_thread = 0;
//
//	CDataLink db;
//	FILE *fd1;
//	char s1[9999] = { 0 };
//	char sOne[10000];
//
//	//FILE *fd1;
//	char sLog_file[500] = { 0 };
//	char myValue[5000] = { 0 };
//	int i = 0;
//
//	number num_t;
//	number *num1_t;
//
//	char *psIN = (char*)lpparam;    // psIN指向了傳遞進來的字串
//	linepos_thread = atoi(psIN);
//	sprintf_s(s1, sizeof(s1), "\r\n\r\n\r\nThread_funCALL_L01() start, linepos_thread=[%d]----sizeof(exxp[linepos_thread].chain)=[%d] %s(%i)\r\n", linepos_thread, sizeof(exxp[linepos_thread].chain), __FILE__, __LINE__);
//	funPrint_Log(s1);
//
//
//
//	char myEtran[50] = { 0 };
//	memcpy_s(myEtran, sizeof(myEtran), exVar[linepos_thread].etran, 3);  // L01
//
//	
//
//	HANDLE hMutex = NULL;
//
//	hMutex = CreateMutex(NULL, FALSE, "L01");
//	DWORD result = WaitForSingleObject(hMutex, 10 * 1000);
//
//	
//
//	switch (result) {
//	case WAIT_FAILED:
//		sprintf_s(s1, sizeof(s1), "WaitForSingleObject WAIT_FAILED return %s(%i)\n", __FILE__, __LINE__);
//		funPrint_Log(s1);
//
//		ReleaseMutex(hMutex);
//		CloseHandle(hMutex);
//
//		memcpy_s(exxp[linepos_thread].chain, sizeof(exxp[linepos_thread].chain), "REP WAIT_FAILED END", 19);
//
//		strncpy_s(exVar[linepos_thread].rtran, exVar[linepos_thread].etran, 3);
//		exVar[linepos_thread].rtran[3] = 0;
//		exVar[linepos_thread].rsync = exVar[linepos_thread].esync;
//		exVar[linepos_thread].remis = 64;
//		retCode_all_flag[linepos_thread] = -1;
//
//		return 0;
//		break;
//	case WAIT_OBJECT_0:
//		break;
//	case WAIT_TIMEOUT:
//		sprintf_s(s1, sizeof(s1), "WaitForSingleObject WAIT_TIMEOUT return %s(%i)\n", __FILE__, __LINE__);
//		funPrint_Log(s1);
//
//		ReleaseMutex(hMutex);
//		CloseHandle(hMutex);
//
//		memcpy_s(exxp[linepos_thread].chain, sizeof(exxp[linepos_thread].chain), "REP WAIT_TIMEOUT END", 20);
//
//		strncpy_s(exVar[linepos_thread].rtran, exVar[linepos_thread].etran, 3);
//		exVar[linepos_thread].rtran[3] = 0;
//		exVar[linepos_thread].rsync = exVar[linepos_thread].esync;
//		exVar[linepos_thread].remis = 64;
//		retCode_all_flag[linepos_thread] = -1;
//
//		return 0;
//		break;
//	}
//
//	//-------------------------------------------------------------------------------------------
//	// 111111.
//	// 1.先做寫入  TABLOG
//	//-------------------------------------------------------------------------------------------
//
//	//uap的log 寫在log_skh的logXX.txt
//
//	// V2.2.0 1090226  ching2   .\\log_skh --> .\\log_tph_L
//	//old sprintf_s(sLog_file, sizeof(sLog_file), ".\\log_skh\\log%02d.txt", linepos_thread + 1);
//	sprintf_s(sLog_file, sizeof(sLog_file), ".\\log_LOG\\log%02d.txt", linepos_thread + 1);
//
//	errno_t myErrNoT = fopen_s(&fd1, sLog_file, "r");
//
//
//
//	fseek(fd1, 0, SEEK_SET);
//	fread(&num_t.shead, sizeof(char), sizeof(num_t), fd1);
//	fclose(fd1);
//
//
//
//	num1_t = (number *)&num_t.shead;
//	sprintf_s(s1, sizeof(s1), "totalnum=[%s]\r\n", num1_t->totalnum);
//	funPrint_Log(s1);
//
//
//	
//
//	//-----------------------------------------------------------------------------------------
//	//1.開資料庫
//	//失敗 先寫一筆到 write_db_err.txt  在由funDo_write_db_err()  補寫log
//	//-----------------------------------------------------------------------------------------
//	if (!db.OpenDatabase(conf_DSN, conf_SQLID, conf_SQLPW)) {
//
//		CTime now(time(NULL));	//1070221
//		char  sTIME[150] = { 0 };
//		
//
//		sprintf_s(sTIME, sizeof(sTIME), "%02d%02d%02d%02d", now.GetMonth(), now.GetDay(), now.GetHour(), now.GetMinute());			  //1070221
//		sprintf_s(s1, sizeof(s1), "ERROR: OpenDatabase() DSN=[%s]. (資料庫開啟錯誤) %s(%i)\r\n", conf_DSN, __FILE__, __LINE__);		//1070221
//		funPrint_Log(s1);
//
//		num1_t = (number *)&num_t.shead;
//		sprintf_s(s1, sizeof(s1), "totalnum=[%s]\r\n", num1_t->totalnum);
//		funPrint_Log(s1);
//
//		for (i = 0;i<atoi(num1_t->totalnum);i++) {
//
//
//			
//			//  YYYY/MM/DD_hh:mm:ss   --> 去除底線為空白  YYYY/MM/DD hh:mm:ss
//			num_t.v25[i].line_time_in[10] = ' ';
//			num_t.v25[i].line_time_out[10] = ' ';
//			num_t.v25[i].trid_time_in[10] = ' ';
//			num_t.v25[i].trid_time_out[10] = ' ';
//
//
//			if (i > 6) break;
//
//			// V2.10  1080219  ching2   v25_1新增hot_rep[500 + 1]記錄查詢結果
//			//V2.41 NEW
//			//	              							  1    2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22      23      24
//			sprintf_s(sOne, sizeof(sOne), "  '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s' , '%s'  , '%s' ",
//
//				num_t.v25[i].num, num_t.v25[i].ivr_set, num_t.v25[i].line_no, num_t.v25[i].line_hour, num_t.v25[i].line_time_in,
//				num_t.v25[i].line_time_out, num_t.v25[i].trid_time_in, num_t.v25[i].trid_time_out, num_t.v25[i].lag, num_t.v25[i].trid,
//				num_t.v25[i].errcode, num_t.v25[i].stat1, num_t.v25[i].stat2, num_t.v25[i].pa_no, num_t.v25[i].id,
//				num_t.v25[i].order_date, num_t.v25[i].time_scale, num_t.v25[i].dep, num_t.v25[i].room, num_t.v25[i].dr_no,
//				num_t.v25[i].dr_name, num_t.v25[i].seqno, num_t.v25[i].caller, num_t.v25[i].hot_rep
//			);
//			//V2.41 OLD
//			////													1        2          3          4           5             6              7             8              9    10    11        12     13     14     15  16          17          18  19     20     21       22     23                 1    2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22      23
//			//sprintf_s(sOne, sizeof(sOne)," insert into tabLog ( num  ,   ivr_set  , line_no  , line_hour , line_time_in, line_time_out, trid_time_in, trid_time_out, lag, trid, errcode , stat1, stat2, pa_no, id, order_date, time_scale, dep, room, dr_no, dr_name, seqno, caller ) values ( '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s' , '%s'  ) , ",
//
//			//	num_t.v25[i].num, num_t.v25[i].ivr_set, num_t.v25[i].line_no, num_t.v25[i].line_hour, num_t.v25[i].line_time_in,
//			//	num_t.v25[i].line_time_out, num_t.v25[i].trid_time_in, num_t.v25[i].trid_time_out, num_t.v25[i].lag, num_t.v25[i].trid,
//			//	num_t.v25[i].errcode, num_t.v25[i].stat1, num_t.v25[i].stat2, num_t.v25[i].pa_no, num_t.v25[i].id,
//			//	num_t.v25[i].order_date, num_t.v25[i].time_scale, num_t.v25[i].dep, num_t.v25[i].room, num_t.v25[i].dr_no,
//			//	num_t.v25[i].dr_name, num_t.v25[i].seqno, num_t.v25[i].caller
//			//);
//
//			fdbprintf("---------\r\n num_t.v25[i].num            ==%s \n", num_t.v25[i].num);             // 1 
//			fdbprintf("---------\r\n num_t.v25[i].ivr_set        ==%s \n", num_t.v25[i].ivr_set);         // 2          
//			fdbprintf("---------\r\n num_t.v25[i].line_no        ==%s \n", num_t.v25[i].line_no);         // 3
//			fdbprintf("---------\r\n num_t.v25[i].line_hour      ==%s \n", num_t.v25[i].line_hour);       // 4
//			fdbprintf("---------\r\n num_t.v25[i].line_time_in   ==%s \n", num_t.v25[i].line_time_in);    // 5
//
//			fdbprintf("---------\r\n num_t.v25[i].line_time_out  ==%s \n", num_t.v25[i].line_time_out);   // 6
//			fdbprintf("---------\r\n num_t.v25[i].trid_time_in   ==%s \n", num_t.v25[i].trid_time_in);    // 7
//			fdbprintf("---------\r\n num_t.v25[i].trid_time_out  ==%s \n", num_t.v25[i].trid_time_out);   // 8
//			fdbprintf("---------\r\n num_t.v25[i].lag            ==%s \n", num_t.v25[i].lag);             // 9
//			fdbprintf("---------\r\n num_t.v25[i].trid           ==%s \n", num_t.v25[i].trid);            // 10
//
//			fdbprintf("---------\r\n num_t.v25[i].errcode        ==%s \n", num_t.v25[i].errcode);         // 11
//			fdbprintf("---------\r\n num_t.v25[i].stat1          ==%s \n", num_t.v25[i].stat1);           // 12 
//			fdbprintf("---------\r\n num_t.v25[i].stat2          ==%s \n", num_t.v25[i].stat2);           // 13
//
//			fdbprintf("---------\r\n num_t.v25[i].pa_no          ==%s \n", num_t.v25[i].pa_no);           // 14
//			fdbprintf("---------\r\n num_t.v25[i].id             ==%s \n", num_t.v25[i].id);              // 15
//			fdbprintf("---------\r\n num_t.v25[i].order_date     ==%s \n", num_t.v25[i].order_date);      // 16
//			fdbprintf("---------\r\n num_t.v25[i].time_scale     ==%s \n", num_t.v25[i].time_scale);      // 17
//			fdbprintf("---------\r\n num_t.v25[i].dep            ==%s \n", num_t.v25[i].dep);             // 18
//
//			fdbprintf("---------\r\n num_t.v25[i].room           ==%s \n", num_t.v25[i].room);            // 19
//			fdbprintf("---------\r\n num_t.v25[i].dr_no          ==%s \n", num_t.v25[i].dr_no);           // 20
//			fdbprintf("---------\r\n num_t.v25[i].dr_name        ==%s \n", num_t.v25[i].dr_name);         // 21
//			fdbprintf("---------\r\n num_t.v25[i].seqno          ==%s \n", num_t.v25[i].seqno);           // 22
//
//			fdbprintf("---------\r\n num_t.v25[i].caller         ==%s \n", num_t.v25[i].caller);          // 23
//
//			// V2.10  1080219  ching2   v25_1新增hot_rep[500 + 1]記錄查詢結果
//			fdbprintf("---------\r\n num_t.v25[i].hot_rep         ==%s \n", num_t.v25[i].hot_rep);          // 24
//			
//			errno_t myErrNoT = fopen_s(&fd1, ".\\mdb\\write_db_err.txt", "a");			//1070221
//			fprintf(fd1, "%s \r\n", sOne);
//			fclose(fd1);
//		}
//
//
//		ReleaseMutex(hMutex);
//		CloseHandle(hMutex);
//
//		memcpy_s(exxp[linepos_thread].chain, sizeof(exxp[linepos_thread].chain), "REP OPEN_DB_ERROR END  ", 22);
//
//		strncpy_s(exVar[linepos_thread].rtran, exVar[linepos_thread].etran, 3);
//		exVar[linepos_thread].rtran[3] = 0;
//		exVar[linepos_thread].rsync = exVar[linepos_thread].esync;
//		exVar[linepos_thread].remis = 64;
//
//		retCode_all_flag[linepos_thread] = -1;
//
//		sprintf_s(s1, sizeof(s1), "Thread_funCALL_L01() END !!! --------------------------------------------- %s(%i)\r\n", __FILE__, __LINE__);
//		funPrint_Log(s1);
//		return 0;
//	}
//
//	// DB OpenDatabase success
//	//sprintf_s(s1, sizeof(s1), "connect to database DSN=%s successful. %s(%i)\n", gDSN_icbcLog, __FILE__, __LINE__);
//
//	
//
//	//-----------------------------------------------------------------------------------------
//	// 增加 資料庫開啟成功, 要寫入 tabLog
//	//-----------------------------------------------------------------------------------------
//	char  table_name1[] = "tabLog";
//
//	char *pFields =
//
//		"num, "               // 1  筆數
//		"ivr_set, "           // 2  套數別 第一套= "1" 第二套="2" 
//		"line_no, "           // 3  線路別 1 2     
//		"line_hour, "         // 4  進線時段
//		"line_time_in, "      // 5  進線起始時間 YYYY/MM/DD hh:mm:ss 
//
//		"line_time_out, "     // 6  出線起始時間 YYYY/MM/DD hh:mm:ss 
//		"trid_time_in, "      // 7  交易起始時間 YYYY/MM/DD hh:mm:ss 
//		"trid_time_out, "     // 8  交易結束時間 YYYY/MM/DD hh:mm:ss 
//		"lag, "               // 9  語言別 1:國語  2:台語
//		"trid, "              // 10  交易代碼  v[1]選項   ( 依按鍵 選項填入)
//
//		"errcode, "           // 11 錯誤代碼   0000: 成功  E****
//		"stat1, "             // 12 0:success 1:failure 2:busy  保留用 
//		"stat2, "             // 13 cancel or not   H:host sent 
//
//		"pa_no, "             // 14 pa_no 病歷號碼
//		"id, "                // 15 id
//		"order_date, "        // 16 date
//		"time_scale, "        // 17 time_scale
//		"dep, "               // 18 dep
//
//		"room, "              // 19 room
//		"dr_no, "             // 20 dr_no
//		"dr_name, "           // 21 dr_name
//		"seqno, "        		  // 22 seqno     
//		"caller, "	          // 23 caller     
//
//	  // V2.10  1080219  ching2   v25_1新增hot_rep[500 + 1]記錄查詢結果
//		"hot_rep ";		        // 24 hot_rep		//**** " **** 後不可有 ,  ching2 語法錯誤!!
//	
//		
//		sprintf_s(s1, sizeof(s1), "pFields=[%s] %s(%d) \r\n", pFields, __FILE__, __LINE__);
//	funPrint_Log(s1);
//
//	for (i = 0; i < atoi(num1_t->totalnum); i++)
//	{
//
//		//  YYYY/MM/DD_hh:mm:ss   --> 去除底線為空白  YYYY/MM/DD hh:mm:ss
//		num_t.v25[i].line_time_in[10] = ' ';
//		num_t.v25[i].line_time_out[10] = ' ';
//		num_t.v25[i].trid_time_in[10] = ' ';
//		num_t.v25[i].trid_time_out[10] = ' ';
//
//
//		// V2.10  1080219  ching2   v25_1新增hot_rep[500 + 1]記錄查詢結果
//		//							               		    1    2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22     23       24
//		sprintf_s(myValue, sizeof(myValue), " '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s' , '%s'  , '%s'",
//
//			num_t.v25[i].num,					       // 1.第幾筆
//			num_t.v25[i].ivr_set,				     // 2.套數別 第一套= "1" 第二套="2" 
//			num_t.v25[i].line_no,				     // 3.線路別 1 2
//			num_t.v25[i].line_hour,				   // 4.進線時段
//			num_t.v25[i].line_time_in,			 // 5.進線起始時間 YYYY/MM/DD hh:mm:ss (共19位)
//			num_t.v25[i].line_time_out,			 // 6.出線起始時間 YYYY/MM/DD hh:mm:ss (共19位)
//			num_t.v25[i].trid_time_in,			 // 7.交易起始時間 YYYY/MM/DD hh:mm:ss (共19位) 
//			num_t.v25[i].trid_time_out,			 // 8.交易結束時間 YYYY/MM/DD hh:mm:ss (共19位)
//			num_t.v25[i].lag,					       // 9.語言別 1:國語  2:台語 v[1]
//			num_t.v25[i].trid,					     // 10.交易代碼
//			num_t.v25[i].errcode,				     // 11.錯誤代碼   0000: 成功  E****
//			num_t.v25[i].stat1,					     // 12. 0:success 1:failure 2:busy  保留用
//			num_t.v25[i].stat2,					     // 13. cancel or not   H:host sent
//			num_t.v25[i].pa_no,					     // 14. 病歷號碼 12345678  v[7]
//			num_t.v25[i].id,				    	   // 15. 身份證 A123456789  v[3]
//			num_t.v25[i].order_date,			   // 16. 看診日 yyymmdd v[4]
//			num_t.v25[i].time_scale,			   // 17. 看診時段 1:上午,2:下午,3:夜間 v[5]
//			num_t.v25[i].dep,		   			     // 18. 科別
//			num_t.v25[i].room,					     // 19. 診別
//			num_t.v25[i].dr_no,					     // 20. 醫師代號
//			num_t.v25[i].dr_name,				     // 21. 醫師姓名
//			num_t.v25[i].seqno,					     // 22. 看診號
//			num_t.v25[i].caller,					   // 23. caller     
//
//      // V2.10  1080219  ching2   v25_1新增hot_rep[500 + 1]記錄查詢結果
//			num_t.v25[i].hot_rep					   // 23. caller    
//
//		);
//
//
//		sprintf_s(s1, sizeof(s1), "myValue=[%s] %s(%d) \r\n", myValue, __FILE__, __LINE__);
//		funPrint_Log(s1);
//
//		sprintf_s(s1, sizeof(s1), "INSERT INTO %s (%s) VALUES (%s) %s(%i)\r\n", table_name1, pFields, myValue, __FILE__, __LINE__);
//		funPrint_Log(s1);
//
//		db.AddNewRecorder(table_name1, pFields, myValue);
//		Sleep(200);
//		CString msg1 = db.GetErrMsg();
//		sprintf_s(s1, "db.AddNewRecorder ..[%s] %s(%i) \r\n", (LPCTSTR)msg1, __FILE__, __LINE__);
//		funPrint_Log(s1);
//
//	}//for(i = 0;i<atoi(num1->totalnum);i++)
//
//	funPrint_Log("\r\n\r\n");
//
//	db.CloseDatabase();
//	Sleep(200);
//
//	ReleaseMutex(hMutex);
//	CloseHandle(hMutex);
//
//
//	memcpy_s(exxp[linepos_thread].chain, sizeof(exxp[linepos_thread].chain), "ERP 0000 END ", 12);
//
//	strncpy_s(exVar[linepos_thread].rtran, exVar[linepos_thread].etran, 3);
//	exVar[linepos_thread].rtran[3] = 0;
//	exVar[linepos_thread].rsync = exVar[linepos_thread].esync;
//	exVar[linepos_thread].remis = 64;
//
//	retCode_all_flag[linepos_thread] = -1;
//	sprintf_s(s1, sizeof(s1), "Thread_funCALL_L01() END !!!, return 1 %s(%i)------------------------------- \r\n", __FILE__, __LINE__);
//	funPrint_Log(s1);
//	return 1;
//}
//
//
//
//
//
//
////-----------------------------------------------------------------------------
////  NO:8 p400()
////
////       主迴圈
////        
////  IN : 無
////  OUT: 無
////-----------------------------------------------------------------------------
//int p400(void)
//{
//	char myEtran[50];
//	int  iKill = 0;
//
//
//
//	funPrint_Log("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
//	funPrint_Log(" ==========================================================================\r\n");
//	funPrint_Log(" ==========================================================================\r\n");
//	funPrint_Log(" ==========================================================================\r\n");
//
//	sprintf_s(sTemp, sizeof(sTemp), " == 程式 hotTPH_L 開始啟動    AP by ots ching2  %s   ==\r\n", VERSION);
//	funPrint_Log(sTemp);
//
//	funPrint_Log(" ==========================================================================\r\n");
//	funPrint_Log(" ==========================================================================\r\n");
//	funPrint_Log(" ==========================================================================\r\n\r\n\r\n");
//	funPrint_Log("p400() start !!! --- \r\n");
//	funPrint_Log("\r\n");
//
//	//1070522    V3.33 ching2   修正版本顯示,VERSION, 每次異動版本需要修改
//	sprintf_s(vxp->message, sizeof(vxp->message), "%s", VERSION);
//	Sleep(1000);
//
//
//	//---------------------------------------------------------------------------
//	// add thread
//	//---------------------------------------------------------------------------
//	for (int i = 0; i < 200; i++)
//	{
//		hThread_all[i] = NULL;
//		retCode_all_flag[i] = 0;
//		memset(sIN_all[i], 0x00, sizeof(sIN_all[i]));
//	}
//
//	// ========================================================================
//	// (0.3).讀 ./conf/hotTPH_L.txt
//	// ========================================================================
//
//	strcpy_s(conf_ivr_start, sizeof(conf_ivr_start), "1");           //4   1      
//	strcpy_s(conf_ivr_end, sizeof(conf_ivr_end), "120");           //5   120
//
//
//	funRead_set();   // ./conf/hotTPH_L.txt
//	
//	while (1)
//	{
//
//
//
//		// V1.44  1070522  ching2    p400() add fdb_check_rotate();  for  dbg058 --> dbg058.dd  
//		fdb_check_rotate();
//		
//
//
//		// ========================================================================
//		// (1).check time 00:05:00 do delete log file 
//		// ========================================================================
//		time_t now;
//		struct tm now_tm;
//		time(&now);
//
//		errno_t errNoT = localtime_s(&now_tm, &now);
//		//now_tm.tm_year - 11, now_tm.tm_mon + 1, now_tm.tm_mday, now_tm.tm_hour, now_tm.tm_min, now_tm.tm_sec
//
//		if (now_tm.tm_hour == 0 && now_tm.tm_min == 5)  //00:05:00
//		{
//			iKill = 1;
//		}
//		if (now_tm.tm_hour == 0 && now_tm.tm_min == 6 && iKill == 1)
//		{
//			Sleep(2000);
//			funPrint_Log("\r\n\r\n");
//			funPrint_Log(" ==========================================================================\r\n");
//			funPrint_Log(" == 00:06:00 每日零晨刪除 去年次日之log檔  !!!!                          ==\r\n");
//			funPrint_Log(" ==========================================================================\r\n");
//			funKill_Log();
//			iKill = 0;
//		}
//
//
//
//
//
//
//		// V2.20  1071130  CW		從 hotslog1 搬來
//		// ========================================================================
//		// (1).每10分鐘 處理  ./mdb/write_db_err.txt   
//		// ========================================================================
//		//time(&lt);
//		//newtm = localtime(&lt);
//		time(&now);
//		errNoT = localtime_s(&now_tm, &now);
//		//fdbprintf(" %02d  %02d:%02d:%02d",newtm->tm_mday, newtm->tm_hour, newtm->tm_min, newtm->tm_sec );
//
//		if ((now_tm.tm_min == 10 || now_tm.tm_min == 20 || now_tm.tm_min == 30 || now_tm.tm_min == 40 || now_tm.tm_min == 50 || now_tm.tm_min == 0) && now_tm.tm_sec == 0)  //00:05:00
//		{
//			Sleep(2000);
//			//show_time();
//			funPrint_Log("\r\n\r\n");
//
//			funPrint_Log(" ==========================================================================\r\n");
//			funPrint_Log(" == (1).每10分鐘 處理  ./mdb/write_db_err.txt                            ==\r\n");
//			funPrint_Log(" ==========================================================================\r\n\r\n\r\n");
//			funDo_write_db_err();
//			Sleep(500);
//		}
//
//
//
//		// V2.30  1090316  ching2   del funDateAdd_yyyymm() 及 funDel_old_db_move() 功能
//
//		//// V2.20  1071130  CW		從 hotslog1 搬來
//		//// ========================================================================
//		//// (2).00:15:00 每月1/2/3 日零15分晨 搬log 到 上個月 , 並刪除之前 conf_log_exVarire 個月前 tablog_yyyymm 的資料
//		//// ========================================================================
//		//
//		////time(&lt);
//		////newtm = localtime(&lt);
//		//time(&now);
//		//errNoT = localtime_s(&now_tm, &now);
//		////fdbprintf(" %02d  %02d:%02d:%02d",newtm->tm_mday, newtm->tm_hour, newtm->tm_min, newtm->tm_sec );
//
//
//		//
//		//if ((now_tm.tm_mday == 1 || now_tm.tm_mday == 2 || now_tm.tm_mday == 3) && now_tm.tm_hour == 0 && now_tm.tm_min == 15 && now_tm.tm_sec <= 1)  //00:15:00
//		//{
//		//	Sleep(2000);
//		//	//show_time();
//		//	funPrint_Log("\r\n\r\n");
//		//	funPrint_Log(" ==========================================================================\r\n");
//		//	funPrint_Log(" == 00:15:00 每月1/2/3 日零15分晨 搬log 到 上個月 ,                       ==\r\n");
//		//	funPrint_Log(" == 並刪除之前 conf_log_exVarire 個月前 tablog_yyyymm 的資料 !!!           ==\r\n");
//		//	funPrint_Log(" ==========================================================================\r\n\r\n\r\n");
//		//	funDel_old_db_move();
//		//}
//
//		if (now_tm.tm_sec  == 0 )			funPrint_Log(".");
//
//		
//		// ========================================================================
//		// (4).check 使用者關線
//		// ========================================================================
//		// 991026  V1.3 CHING2  adjust commnad = 5
//		if ((vxp->command == '5')) //|| (vxp->command == '3') )      //5  
//		{
//			funPrint_Log("\r\n\r\n");
//			funPrint_Log(" ==========================================================================\r\n");
//			funPrint_Log(" == IVR與HOST不連線,使用者關線      vxp->command == '5'   立即           ==\r\n");
//			funPrint_Log(" ==========================================================================\r\n");
//			sprintf_s(vxp->message, 32, "使用者關線");
//
//			return(0);
//		}
//
//
//		// ========================================================================
//		// (4).check 使用者關線
//		// ========================================================================
//		// 991026  v1.3  ching2 add vxp->taskid == 0 自動關線 
//		if ((vxp->command == '3'))      //3  全關 -- 掛線  
//		{
//
//			int iEnd;
//			iEnd = 1;     //先設結束
//
//			for (int j = atoi(conf_ivr_start) - 1; j < atoi(conf_ivr_end); j++)
//			{
//				//sprintf(sTemp, " vxp->command == '3', j=[%d], vxp[j-156+1].taskid =[%d] \r\n", j, vxp[j-156+1].taskid );
//				//funPrint_Log(sTemp);
//				if (vxp[j - 156 + 1].taskid != 0)                      // 線路結束後 vxp->taskid 設為 0
//				{
//					iEnd = 0;     //有任何語音線使用中, 設不可結束
//					break;
//				}
//				else
//				{
//					sprintf_s(sTemp, sizeof(sTemp), " vxp->command == '3', j=[%d], vxp[j-156+1].taskid =[%d] \r\n", j, vxp[j - 156 + 1].taskid);
//					funPrint_Log(sTemp);
//				}
//			}
//
//
//			if (iEnd == 1)
//			{
//				funPrint_Log(" 1111 vxp->command == '3' \r\n");
//				funPrint_Log("\r\n\r\n");
//				funPrint_Log(" ==========================================================================\r\n");
//				funPrint_Log(" == IVR與HOST不連線,使用者關線    vxp->command == '3'    全關 -- 掛線    ==\r\n");
//				funPrint_Log(" ==========================================================================\r\n");
//				sprintf_s(vxp->message, 32, "使用者關線");
//				return(0);
//			}
//			else
//			{
//				//funPrint_Log(" 還有語音線路使用中    ==\r\n");
//			}
//		}
//
//
//
//
//		// ========================================================================
//		// (3).check retCode_all_flag
//		// ========================================================================
//		for (int i = 0; i < 200; i++)
//		{
//			if (retCode_all_flag[i] == -1)
//			{
//				//char s[1000];
//				//sprintf_s(s, sizeof(s), " CloseHandle()[i]=[%02d]  start !!!!\r\n", i);
//				//funPrint_Log(s);
//				CloseHandle(hThread_all[i]);
//				Sleep(10);   //too slow 40 line  50-> 10
//				//sprintf_s(s, sizeof(s), " CloseHandle()[i]=[%02d]  end   !!!!\r\n", i);
//				//funPrint_Log(s);
//				retCode_all_flag[i] = 0;
//				memset(sIN_all[i], 0x00, sizeof(sIN_all[i]));
//			}
//		}
//
//
//		while (chk_exe_emis())
//		{
//
//			if ((vxp->command == '5'))   // || (vxp->command == '3') )  
//			{
//				funPrint_Log("\r\n\r\n");
//				funPrint_Log(" ==========================================================================\r\n");
//				funPrint_Log(" == IVR與HOST不連線,使用者關線                                           ==\r\n");
//				funPrint_Log(" ==========================================================================\r\n");
//				sprintf_s(vxp->message, 32, "使用者關線");
//				return(0);
//
//			}
//
//			// ========================================================================
//			// (4).check 使用者關線
//			// ========================================================================
//			if ((vxp->command == '3'))      //3  全關 -- 掛線  
//			{
//				int iEnd;
//				iEnd = 1;     //先設結束
//
//				for (int j = atoi(conf_ivr_start) - 1; j < atoi(conf_ivr_end); j++)
//				{
//					//sprintf(sTemp, " vxp->command == '3', j=[%d], vxp[j-156+1].taskid =[%d] \r\n", j, vxp[j-156+1].taskid );
//					//funPrint_Log(sTemp);
//					if (vxp[j - 156 + 1].taskid != 0)                      // 線路結束後 vxp->taskid 設為 0
//					{
//						iEnd = 0;     //有任何語音線使用中, 設不可結束
//						break;
//					}
//					else
//					{
//						sprintf_s(sTemp, sizeof(sTemp), " vxp->command == '3', j=[%d], vxp[j-156+1].taskid =[%d] \r\n", j, vxp[j - 156 + 1].taskid);
//						funPrint_Log(sTemp);
//					}
//				}
//
//				if (iEnd == 1)
//				{
//					funPrint_Log(" 2222 vxp->command == '3' \r\n");
//					funPrint_Log("\r\n\r\n");
//					funPrint_Log(" ==========================================================================\r\n");
//					funPrint_Log(" == IVR與HOST不連線,使用者關線    vxp->command == '3'    全關 -- 掛線    ==\r\n");
//					funPrint_Log(" ==========================================================================\r\n");
//					sprintf_s(vxp->message, 30, "使用者關線");
//					return(0);
//				}
//				else
//				{
//					//funPrint_Log(" 還有語音線路使用中    ==\r\n");
//				}
//
//			}
//
//
//			memcpy_s(myEtran, sizeof(myEtran), exVar[linepos].etran, 3);        myEtran[3] = 0;
//
//			
//
//			// 改成 thread
//			//------------------------------------------------------------------------------------------
//			// 1.drxxx  send [L01]  寫LOG     
//			//------------------------------------------------------------------------------------------
//			if (strcmp(myEtran, "L01") == 0) {
//
//				if (retCode_all_flag[linepos] == -1) {
//					char s[1024] = { 0 };
//
//					sprintf_s(s, " P400 [L01] CloseHandle()[linepos]=[%02d] start !!!! %s(%i)\r\n", linepos, __FILE__, __LINE__);
//					funPrint_Log(s);
//					CloseHandle(hThread_all[linepos]);
//					Sleep(50);
//					sprintf_s(s, " P400 [L01] CloseHandle()[linepos]=[%02d]  End !!!! %s(%i)\r\n", linepos, __FILE__, __LINE__);
//					funPrint_Log(s);
//					retCode_all_flag[linepos] = 0;
//					memset(sIN_all[linepos], 0, sizeof(sIN_all[linepos]));
//				}
//	
//				exVar[linepos].eemis = 0;    //啟動音樂
//				sprintf_s(sIN_all[linepos], "%02d", linepos);
//				
//
//				if ((hThread_all[linepos] = CreateThread(NULL, 0, Thread_funCALL_L01, (LPVOID)&sIN_all[linepos], 0, &id)) == NULL) {
//					//1-1 
//					sprintf_s(sTemp, "linepos=[%d], CreateThread() Thread_funCALL_L01() error error error !!!!!!!!!!!!! %s(%i)\r\n", linepos, __FILE__, __LINE__);
//					funPrint_Log(sTemp);
//					Sleep(100);
//				}
//				else {
//					//1-2 CreateThread() OK SLEEP 避免 sIN 在 CreateThread() 被別線蓋走
//					Sleep(100);
//				}  //if( ( hThread_all[linepos] ....
//			}  //if ( (strcmp(myEtran, "A99" ) == 0) )
//
//
//
//			//Sleep(100);     //971219 500-> 100  ching2 不可等 因為會有40路同時進線會迼成 等40*500
//
//		} //while (chk_exe_emis()) {
//
//
//
//		Sleep(10);  //971219 500-> 100    --> 10 980106	
//
//
//	} //while (1) {
//
//
//}
//
//
//
//
//
//
////-----------------------------------------------------------------------------
////
////-----------------------------------------------------------------------------
//int main(int argc, char **argv)
//{
//	signal(SIGTERM, err_stop);
//	signal(SIGINT, SIG_IGN);
//
//
//	//fdbprintf("hotGen v1.2 970312");  //970312
//	//1060327 bug  需在 P100() 以後, 否則chk_exe_emis() 會當
//	// exVar = exVar;
//
//	voie = atoi(argv[1]) + 1;
//	if (p100() >= 0)
//	{
//		exVar = exVar;  //1060327 bug  需在 P100() 以後, 否則chk_exe_emis() 會當
//		p400();
//	}
//	p900();
//	return 0;
//
//}
//
//
//
