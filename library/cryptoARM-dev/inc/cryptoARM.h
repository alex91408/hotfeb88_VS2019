
#pragma once

#ifdef CRYPTOARM_EXPORTS  
#define CRYPTOARM_API __declspec(dllexport)   
#else  
#define CRYPTOARM_API __declspec(dllimport)   
#endif

//錯誤碼
#define DONGLE_SUCCESS             0x00000000 // 操作成功
#define DONGLE_NOT_FOUND           0xF0000001 // 未找到指定的設備
#define DONGLE_INVALID_HANDLE      0xF0000002 // 無效的句柄
#define DONGLE_INVALID_PARAMETER   0xF0000003 // 參數錯誤
#define DONGLE_COMM_ERROR          0xF0000004 // 通訊錯誤
#define DONGLE_INSUFFICIENT_BUFFER 0xF0000005 // 緩衝區空間不足
#define DONGLE_NOT_INITIALIZED     0xF0000006 // 產品尚未初始化 (即沒設置PID)
#define DONGLE_ALREADY_INITIALIZED 0xF0000007 // 產品已經初始化 (即已設置PID)
#define DONGLE_ADMINPIN_NOT_CHECK  0xF0000008 // 開發商密碼沒有驗證
#define DONGLE_USERPIN_NOT_CHECK   0xF0000009 // 用戶密碼沒有驗證
#define DONGLE_INCORRECT_PIN       0xF000FF00 // 密碼不正確 (後2位指示剩余次數)
#define DONGLE_PIN_BLOCKED         0xF000000A // PIN碼已鎖死
#define DONGLE_ACCESS_DENIED       0xF000000B // 訪問被拒絕 
#define DONGLE_FILE_EXIST          0xF000000E // 文件已存在
#define DONGLE_FILE_NOT_FOUND      0xF000000F // 未找到指定的文件
#define DONGLE_READ_ERROR          0xF0000010 // 讀取數據錯誤
#define DONGLE_WRITE_ERROR         0xF0000011 // 寫入數據錯誤
#define DONGLE_FILE_CREATE_ERROR   0xF0000012 // 創建文件錯誤
#define DONGLE_FILE_READ_ERROR     0xF0000013 // 讀取文件錯誤
#define DONGLE_FILE_WRITE_ERROR    0xF0000014 // 寫入文件錯誤
#define DONGLE_FILE_DEL_ERROR      0xF0000015 // 刪除文件錯誤
#define DONGLE_FAILED              0xF0000016 // 操作失敗
#define DONGLE_CLOCK_EXPIRE        0xF0000017 // 加密鎖時鐘到期
#define DONGLE_ERROR_UNKNOWN       0xFFFFFFFF // 未知的錯誤

#ifdef __cplusplus
extern "C" {
#endif

CRYPTOARM_API void cryptoARM_3DesEcbEncryptWithKeyValue(const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen, unsigned char *keyValue);

CRYPTOARM_API void cryptoARM_3DesEcbDecryptWithKeyValue(const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen, unsigned char *keyValue);

CRYPTOARM_API void cryptoARM_3DesCbcEncryptWithKeyValue(const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen, unsigned char *keyValue, const unsigned char *iv);

CRYPTOARM_API void cryptoARM_3DesCbcDecryptWithKeyValue(const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen, unsigned char *keyValue, const unsigned char *iv);

CRYPTOARM_API DWORD cryptoARM_3DesWriteKeyValue(unsigned int keyNo, unsigned char *keyValue, unsigned int keyLen);

CRYPTOARM_API DWORD cryptoARM_3DesEcbEncrypt(unsigned int keyNo, const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen);

CRYPTOARM_API DWORD cryptoARM_3DesEcbDecrypt(unsigned int keyNo, const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen);

CRYPTOARM_API DWORD cryptoARM_3DesCbcEncrypt(unsigned int keyNo, const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen, const unsigned char *iv);

CRYPTOARM_API DWORD cryptoARM_3DesCbcDecrypt(unsigned int keyNo, const unsigned char *dataIn, unsigned char *dataOut, unsigned int dataLen, const unsigned char *iv);

#ifdef __cplusplus 
}
#endif