//#ifdef _GLINENO
//int _gLineno;
//#else
//extern int _gLineno;
//#endif


int wrtLog(const char* format, ...);
int wrtLogByLen(char* buf, int len, const char* apName, int apLine);
int wrtLogByLenX(const char* mark, char* buf, int len, const char* apName, int apLine);
int wrtLogUapName(int lineNo, char* format, ...);
