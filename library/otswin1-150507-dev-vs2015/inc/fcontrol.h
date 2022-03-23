#pragma once
//#if !defined(vx_key)

#define L_ALARMDATA 128
typedef struct ALARMEVENT_ {
  unsigned int msgCode;     
  long occurDate; 
  unsigned int seqNo; // event/updated seqNo
  char alarmData[L_ALARMDATA];
} ALARMEVENT;

typedef struct TERMEVENT_ {
  int taskId;     
  long occurTime; 
  unsigned int count; // event/total count
} TERMEVENT;

typedef struct fctlf {
        int  taskid;
        int  kid;
        int  branch;
        int  typedir;
        int  messnum;
        int  nbappel;
        int  voie;
        int  error;

     /* start of logging */

        char command;  	/* 0:normal 3:abort after call 5:abort at once */
        char etatlig;	/* 1:start 2:call in 3:call end 8:abnrmal end */
        char writer;	/* 0:user 1:call end 2:abnormal end 3:system */
    	  char drtype;	/* V:voice M:modem H;host D:dated ... */
        char hook;      /* ' ' : Unknown, '1' : Onhook, '0' : Offhook */
        char applic[6];
        char datein[6];
        char timein[6];
        char message[32];
        char rcvdig[6];
        char timeout[6];
        char lineno[4];  //2

	      char setno[2];
        char userlog[190];
        char gap[2];     // make size of an entry 300 bytes
        char dbg;   //Y: dbg N:no debug
        // 2 bytes(padding) for alignment, 20141216
        char dbgTimeStamp; // 0 : no time, 1 : short, 2 : long
        char rfu;
        long alive; //-1 not start line, n(changing):alive , n(no change):dead
        long alive_tm; //write time //20040723
        //20131007
        char pathName[8];		// pathName of Co. shch as ots, cht,... 20060822 
		    int  pendingDial;		// when ringing transfer, dialing will be suspended to dial 2nd one.
		    int	 codec;				// forced Codec from uap (rfu1 : -24)
        long aliveEventTime; // 20161125 (rfu1 : -28)
        ALARMEVENT alarmEvent;// 20161209
        char rfu1[1024-28-sizeof(ALARMEVENT)-sizeof(TERMEVENT)];  //for future use //20040723
        TERMEVENT termEvent; // 20170223, for servMain
} VX, *vx;


#define vx_size sizeof(VX)
#define vx_key  41

//#endif