
#pragma once

#ifdef GETJSON_EXPORTS  
#define GETJSON_API __declspec(dllexport)   
#else  
#define GETJSON_API __declspec(dllimport)   
#endif

#ifdef __cplusplus
extern "C" {
#endif

// 檢查 Parse 後是否有 Error
GETJSON_API unsigned int GetJsonHasParseError(void);

// 取 Parse 的 Error 值
GETJSON_API int GetJsonParseError(void);

// 取產生 Error 的位移值
GETJSON_API unsigned int GetJsonErrorOffset(void);

// 由 JSON 資料取字串值, 取不到值時用 defaultValue 
// { appName : { keyName : value } }
GETJSON_API unsigned int  GetJsonString(const char *appName, const char *keyName, const char *defaultValue, char *returnedString, unsigned int size, const char *jsonStr);

// 由 JSON 資料取整數值, 取不到值時用 defaultValue 
// { appName : { keyName : value } }
GETJSON_API int  GetJsonInt(const char *appName, const char *keyName, int defaultValue, const char *jsonStr);

// 由 JSON 資料取整數值, 取不到值或取出的值小於 0 時用 defaultValue  
// { appName : { keyName : value } }
GETJSON_API int  GetJsonIntMinZero(const char *appName, const char *keyName, int defaultValue, const char *jsonStr);

// 由 JSON 資料取整數值, 取不到值或取出的值小於 defaultValue 時用 defaultValue  
// { appName : { keyName : value } }
GETJSON_API int  GetJsonIntMinDefaultValue(const char *appName, const char *keyName, int defaultValue, const char *jsonStr);

// 由 JSON 陣列資料取字串值
// JSON 陣列的大小會由 elementCount 回傳
// 以 elementPos(0 ~ elementCount-1) 指定取值時的陣列位址
// { arrayName : [ {keyName : value }, ...] }
GETJSON_API unsigned int  GetJsonArrayString(const char *arrayName, unsigned int elementPos, const char *keyName, const char *defaultValue, char *returnedString, unsigned int size, const char *jsonStr, unsigned int *elementCount);

// 由 JSON 陣列資料取整數值 
// JSON 陣列的大小會由 elementCount 回傳
// 以 elementPos(0 ~ elementCount-1) 指定取值時的陣列位址
// { arrayName : [ {keyName : value }, ...] }
GETJSON_API int GetJsonArrayInt(const char *arrayName, unsigned int elementPos, const char *keyName, int defaultValue, const char *jsonStr, unsigned int *elementCount);

#ifdef __cplusplus 
}
#endif