#ifdef __cplusplus 
extern "C"
{
#endif

__declspec(dllexport)
int WINAPI getInputText(char *strInfo,CString strTitle);

__declspec(dllexport)
int WINAPI getInputTextEx(char *strInfo,CString strTitle,int inputLen);

__declspec(dllexport)
int WINAPI getSelectParamAndText(char *strParam,char *strText,CString strDispText,CString m_selectVal);

__declspec(dllexport)
int WINAPI getSelectLine(char *strLine,CString strDispText,CString m_selectVal);

__declspec(dllexport)
int WINAPI getImageString(char *strInfo,CString strBmpFileName);

__declspec(dllexport)
int WINAPI getImageString2(char *strInfo,CString strBmpFileName,CString strTitle);

__declspec(dllexport)
int WINAPI dispText(CString strInfo,CString strTitle,int clipFlag=0);

__declspec(dllexport)
int WINAPI getInputPass(char *strInfo,CString strTitle,int repeatFlag);

__declspec(dllexport)
int WINAPI getLogonInfo(char *strUserId,char *strPassWord,CString strTitle);

__declspec(dllexport)
int WINAPI getRegisterInfo(CString *strTishi,CString *strInput,int itemCounts,CString strTitle,int repairFlag);


///////////////////////////////////////////////////
__declspec(dllexport)
int WINAPI regOcx(CString strOcxFilename);

/////////
__declspec(dllexport)
void WINAPI b_writeTextToFile(CString m_strText,LPCTSTR filename,int traceFlag=0,CString currentApplicationPath="");
__declspec(dllexport)
void WINAPI b_writeTextToTrace(CString m_strText,LPCTSTR filename,int traceFlag,CString currentApplicationPath);

__declspec(dllexport)
void WINAPI b_getApplicationPath(char icechar,CString& strReturn);

__declspec(dllexport)
void WINAPI b_getCurrentTime(int flag,CString& strReturn);

__declspec(dllexport)
void WINAPI keepDigitString(CString& strText);

__declspec(dllexport)
int WINAPI icePub_readFileToHexString(char *strFilename,char *strHexString,int maxLen);

__declspec(dllexport)
int WINAPI icePub_writeHexStringToFile(char *strHexString,char *strFilename,int traceFlag);





//
__declspec(dllexport)
void WINAPI icePub_getExeName(char *strPathFilename,char *strPath,char *strFile);

__declspec(dllexport)
void WINAPI icePub_getApplicationName(char *strReturn);

__declspec(dllexport)
void WINAPI icePub_getApplicationPath(char icechar,char *strReturn);


//
__declspec(dllexport)
int WINAPI icePub_getInputText(char *strInfo,char *strTitle);

__declspec(dllexport)
int WINAPI icePub_getInputTextEx(char *strInfo,char *strTitle,int inputLen);

__declspec(dllexport)
int WINAPI icePub_dispText(char *strInfo,char *strTitle,int clipFlag);

__declspec(dllexport)
int WINAPI icePub_getLoginInfo(char *strUserId,char *strPassWord,char *strTitle);

__declspec(dllexport)
int WINAPI icePub_getInputPass(char *strInfo,char *strTitle,int repeatFlag);

__declspec(dllexport)
int WINAPI icePub_getImageString(char *strInfo,char *strBmpFileName);

__declspec(dllexport)
int WINAPI icePub_getImageString2(char *strInfo,char *strBmpFileName,char *strTitle);

__declspec(dllexport)
int WINAPI icePub_getRegisterInfo(char **strTishi,char **strInput,int itemCounts,char *strTitle,int repairFlag);

__declspec(dllexport)
int WINAPI getSelectPath(CString &strPath);

__declspec(dllexport)
int WINAPI icePub_getSelectPath(char *strPath,int maxLen);

__declspec(dllexport)
int WINAPI icePub_dispBmp(HWND hWnd,char *strBmpFilename,int x,int y);

__declspec(dllexport)
int WINAPI icePub_dispImg2(HWND hWnd,char *strImgFilename,int x,int y,int width,int height);

__declspec(dllexport)
int WINAPI icePub_dispImg(HWND hWnd,char *strImgFilename,int x,int y);

__declspec(dllexport)
int WINAPI icePub_dispImgBySizeForm(HWND hWnd,char *strImgFilename,int x,int y);

__declspec(dllexport)
int WINAPI icePub_dispImgFullScreen(HWND hWnd,char *strImgFilename);



//inet
__declspec(dllexport)
int WINAPI ice_openUrl(CString currentUrlString,CString &strHtmlText,CString strProxy);
__declspec(dllexport)
int WINAPI icePub_openUrl(char *currentUrlString,char *strHtmlText,int textMaxLen,char *strProxy);
__declspec(dllexport)
int WINAPI icePub_openUrl2(char *currentUrlString,char *strHtmlText,int textMaxLen,char *strProxy);

__declspec(dllexport)
int WINAPI ice_getUrl(CString hostAddress,CString strObject,CString m_param,CString Referer,CString &strHtmlText,CString strProxy);
__declspec(dllexport)
int WINAPI icePub_getUrl(char *hostAddress,char *strObject,char *m_param,char *Referer,char *strHtmlText,int textMaxLen,char *strProxy);


__declspec(dllexport)
int WINAPI ice_postUrl(CString hostAddress,CString strObject,CString m_param,CString Referer,CString &strHtmlText,CString strProxy);
__declspec(dllexport)
int WINAPI icePub_postUrl(char *hostAddress,char *strObject,char *m_param,char *Referer,char *strHtmlText,int textMaxLen,char *strProxy);
__declspec(dllexport)
int WINAPI icePub_postUrl2(char *hostAddress,char *strObject,char *m_param,char *Referer,char *strHtmlText,int textMaxLen,char *strProxy);

__declspec(dllexport)
int WINAPI ice_downLoad(CString hostAddress,CString strObject,CString m_param,CString Referer,CString strFilename,CString strProxy);
__declspec(dllexport)
int WINAPI icePub_downLoad(char *hostAddress,char *strObject,char *m_param,char *Referer,char *strFilename,char *strProxy);
__declspec(dllexport)
int WINAPI ice_downLoadUrl(CString strUrl,CString strFilename,CString strProxy);


//gzip
__declspec(dllexport)
long WINAPI icePub_gzipUncompress(char *compressBuffer,long bufferLen,char *strHtml,int maxHtmLen);




//socket

__declspec(dllexport)
int WINAPI icePub_tcpInit(char *m_server_ip,int m_server_port);

__declspec(dllexport)
int WINAPI icePub_tcpClose(unsigned int m_socket);

__declspec(dllexport)
int WINAPI icePub_tcpSend(unsigned int m_socket, char *point_send_buf, int int_sendSize, int int_timeoutSecs);

__declspec(dllexport)
int WINAPI icePub_tcpReceive(unsigned int m_socket, char *point_receive_buf, int int_receiveSize, int int_timeoutSecs);

__declspec(dllexport)
int WINAPI icePub_tcpSendAndReceive(char *point_packetBuff, int *point_packet_len,char* char_hostIP,int int_ProtocolType);

__declspec(dllexport)
int WINAPI icePub_tcpSendAndReceiveText(char *sendBuff, int sendBuffLen,char *recvBuff,int recvMaxLen,char* serverIP,int serverPort);

__declspec(dllexport)
int WINAPI icePub_tcpDomain2ip(char *strDomain,char *strIP);


__declspec(dllexport)
int WINAPI icePub_tcpSendFileB(unsigned int socket_client,char *strFilename,HWND hwnd,unsigned long msgID,int exVal);
__declspec(dllexport)
int WINAPI icePub_tcpSendFile2B(char *strFilename,char* serverIP,int serverPort,HWND hwnd,unsigned long msgID);
__declspec(dllexport)
int WINAPI icePub_tcpSendFile(unsigned int socket_client,char *strFilename);
__declspec(dllexport)
int WINAPI icePub_tcpReveiveFileB(unsigned int socket_client,char *strSavePath,HWND hwnd,unsigned long msgID);
__declspec(dllexport)
int WINAPI icePub_tcpReveiveFile(unsigned int socket_client,char *strSavePath);
__declspec(dllexport)
int WINAPI icePub_tcpSendFile2(char *strFilename,char* serverIP,int serverPort);
__declspec(dllexport)
int WINAPI icePub_tcpSendFile3B(char *strCommand,char *strFilename,char* serverIP,int serverPort,HWND hwnd,unsigned long msgID,int exVal);
__declspec(dllexport)
int WINAPI icePub_tcpSendFile3(char *strCommand,char *strFilename,char* serverIP,int serverPort);

__declspec(dllexport)
long WINAPI icePub_tcpSendDataFromFile(unsigned int socketHandle,char *strFilename);






//smtp
__declspec(dllexport)
int WINAPI icePub_sendMail(char *strUsername,char *strPassword,char *strSmtpServer,char *sendMail,char *toMailList,char *strSubject,char *strText,char *strAttachmentsList);
__declspec(dllexport)
int WINAPI icePub_sendMailText(char *strUsername,char *strPassword,char *strSmtpServer,char *sendMail,char *toMailList,char *strSubject,char *strText);
__declspec(dllexport)
int WINAPI icePub_speedMail(char *strMyname,char *sendMail,char *toMailList,char *strSubject,char *strText,char *strAttachmentsList);
__declspec(dllexport)
int WINAPI icePub_speedMailText(char *strMyname,char *sendMail,char *toMailList,char *strSubject,char *strText);


//pop3
__declspec(dllexport)
int WINAPI icePub_pop3Connect(char *strUsername,char *strPassword,char *strSmtpSever,int port);
__declspec(dllexport)
int icePub_pop3Quit(unsigned int sockClient);
__declspec(dllexport)
int WINAPI icePub_pop3GetMailCounts(unsigned int sockClient);
__declspec(dllexport)
int WINAPI icePub_pop3Receive(unsigned int sockClient,int indexMail,char * strDate,char *strFrom,char *strTo,char *strSubject,char *strText,int TextMaxLen,char *strFilename);
__declspec(dllexport)
int WINAPI icePub_pop3DeleteMails(unsigned int sockClient,int mailCounts);

//receive mails
__declspec(dllexport)
int WINAPI icePub_receiveMailText(char *strUsername,char *strPassword,char *strSmtpSever,char *strMailText,int TextMaxLen,char *strFenge,int deleteFlag);

__declspec(dllexport)
int WINAPI icePub_receiveMailTextToFile(char *strUsername,char *strPassword,char *strSmtpSever,char *strFenge,char *strFileName,int appendFlag,int deleteFlag);




/////////////////////////////
__declspec(dllexport)
int WINAPI icePub_hexStringToBCDHex(BYTE *strHexString,BYTE *hexBuffer,int hexStringLen);
__declspec(dllexport)
void WINAPI icePub_BCDHexToHexString(BYTE *hexBuffer,BYTE *strHexString,int hexBufferLen);

__declspec(dllexport)
void WINAPI icePub_LongToBcd(long LongData,BYTE *BcdStr,int BcdStrLen);
__declspec(dllexport)
long WINAPI icePub_BcdToLong(BYTE *BcdStr,int BcdStrLen);


__declspec(dllexport)
int WINAPI icePub_8byteTo16HexString(unsigned char *byteBuff8, unsigned char *hexBuff16);
__declspec(dllexport)
int WINAPI icePub_16HexStringTo8byte(unsigned char *byteBuff8, unsigned char *hexBuff16);


__declspec(dllexport)
int WINAPI icePub_dispValue(int val);

__declspec(dllexport)
int WINAPI icePub_getCurrentTimes(char *strTimes);

//des
__declspec(dllexport)
void WINAPI icePub_desDecryption(unsigned char *input, unsigned char *output, unsigned char *deskey);
__declspec(dllexport)
void WINAPI icePub_desEncryption(unsigned char *input, unsigned char *output, unsigned char *deskey);

__declspec(dllexport)
void WINAPI icePub_3desEncryption(unsigned char *input, unsigned char *output, unsigned char *doubleKeyStr);
__declspec(dllexport)
void WINAPI icePub_3desDecryption(unsigned char *input, unsigned char *output, unsigned char *doubleKeyStr);

__declspec(dllexport)
int WINAPI icePub_encryptText3(char *strInput, char *strOutputHexstring, char *strKey);
__declspec(dllexport)
int WINAPI icePub_decryptText3(char *strInputHexstring, char *strOutput, char *strKey);

//digest
__declspec(dllexport)
int WINAPI ice_getMD5FromFile(CString strFilePath,CString &strResult);
__declspec(dllexport)
int WINAPI icePub_getMD5FromFile(char *strFilePath,char *strResult);
__declspec(dllexport)
int WINAPI ice_getMD5(BYTE* pBuf, UINT nLength,CString &strResult);
__declspec(dllexport)
int WINAPI icePub_getMD5(BYTE* pBuf, UINT nLength,char *strResult);
__declspec(dllexport)
int WINAPI ice_getMD5FromString(CString strData,CString &strResult);
__declspec(dllexport)
int WINAPI icePub_getMD5FromString(char *strData,char *strResult);

__declspec(dllexport)
int WINAPI ice_sha1(char *bufferIn,int bufferLen,CString strResult);
__declspec(dllexport)
int WINAPI icePub_sha1(char *bufferIn,int bufferLen,char *bufferOut);
__declspec(dllexport)
int WINAPI ice_sha1FromString(CString strData,CString &strResult);
__declspec(dllexport)
int WINAPI icePub_sha1FromString(char *strData,char *strResult);




//base string
__declspec(dllexport)
int WINAPI ice_getSubString(CString strText,CString &strResult,CString strBegin,CString strEnd,int startIndex);
__declspec(dllexport)
int WINAPI icePub_getSubString(char *strText,char *strResult,char *strBegin,char *strEnd,int startIndex);
__declspec(dllexport)
int WINAPI ice_getSubStringEx(CString strText,CString &strResult,CString strOrientation,CString strBegin,CString strEnd,int startIndex);
__declspec(dllexport)
int WINAPI icePub_getSubStringEx(char *strText,char *strResult,char *strOrientation,char *strBegin,char *strEnd,int startIndex);
__declspec(dllexport)
int WINAPI icePub_getSubStringEx2(char *strText,char *strResult,int resultMaxLen,char *strOrientation,char *strBegin,char *strEnd,int startIndex);

__declspec(dllexport)
int WINAPI ice_countSubString(CString strInfo,CString strSubString);
__declspec(dllexport)
int WINAPI icePub_countSubString(char *strInfo,char *strSubString);

__declspec(dllexport)
int WINAPI icePub_countSubStringFromFile(char *strFilename,char *strSubString);


__declspec(dllexport)
int WINAPI icePub_getFormatString(char *sourceStr,int index,char *strFenge,char *strSubResult);


//bigInteger
__declspec(dllexport)
int WINAPI icePub_bigIntegerAddition(char *str1,char *str2,char *strResult);
__declspec(dllexport)
int WINAPI icePub_bigIntegerSubtraction(char *str1,char *str2,char *strResult);
__declspec(dllexport)
int WINAPI icePub_bigIntegerMultiplication(char *str1,char *str2,char *strResult);
__declspec(dllexport)
int WINAPI icePub_bigIntegerDivision(char *str1,char *str2,char *strResult,char *strRemainder);
__declspec(dllexport)
int WINAPI icePub_bigIntegerCalculate(char *strArithmetic,char *strResult);



//http string
__declspec(dllexport)
int WINAPI icePub_httpGetHeaderStateCode(char *strHeader);

__declspec(dllexport)
int WINAPI icePub_httpGetHttpVer(char *strHeader,char *strHttpVer);


__declspec(dllexport)
int WINAPI icePub_httpGetHeaderField(char *strHeader,char *strFieldName, char *strValue);

__declspec(dllexport)
int WINAPI icePub_httpGetHeaderLocalUrl(char *strHeader,char *strLocalUrl);

__declspec(dllexport)
int WINAPI icePub_httpGetHeaderCookies(char *strHeader,char *strCookies);

__declspec(dllexport)
int WINAPI icePub_httpGetHeaderContentEncoding(char *strHeader,char *strContentEncoding);

__declspec(dllexport)
int WINAPI icePub_httpGetHeaderContentLength(char *strHeader);

__declspec(dllexport)
int WINAPI icePub_httpDivHtmlHeaderAndBody(char *strHtmlText,char *strHeader,int maxHeaderLen,char *strBody,int maxBodyLen);



//html string
__declspec(dllexport)
int WINAPI ice_getHrefLinks(CString strText,CString &strLinkList,CString &strTextList,CString strFenge);
__declspec(dllexport)
int WINAPI icePub_getHrefLinks(char *strText,char *strLinkList,char *strTextList,char *strFenge);



//ini
__declspec(dllexport)
int WINAPI icePub_getIniString(char *strDefaultValue,char *strGroupName,char *strKeyName,char *strIniFilename,char *strResult);

__declspec(dllexport)
int WINAPI icePub_getIniValue(int valDefaultValue,char *strGroupName,char *strKeyName,char *strIniFilename);

__declspec(dllexport)
int WINAPI icePub_setIniString(char *strValue,char *strGroupName,char *strKeyName,char *strIniFilename);

__declspec(dllexport)
int WINAPI icePub_deleteIniKey(char *strGroupName,char *strKeyName,char *strIniFilename);
__declspec(dllexport)
int WINAPI icePub_deleteIniSection(char *strGroupName,char *strIniFilename);




//image
__declspec(dllexport)
int WINAPI icePub_jpgToBmp(char *strJpgFilename,char *strBmpFilename);

__declspec(dllexport)
int WINAPI icePub_gifToBmp(char *strGifFilename,char *strBmpFilename);

__declspec(dllexport)
int WINAPI icePub_imgToBmp(char *strImgFilename,char *strBmpFilename,int huiFlag);

__declspec(dllexport)
int WINAPI icePub_imgToImg(char *strFromImgFilename,char *strToImgFilename);




__declspec(dllexport)
HBITMAP WINAPI icePub_getScreenHBitmap();
__declspec(dllexport)
HBITMAP WINAPI icePub_getSubScreenHBitmap(int startX,int startY,int endX,int endY);
__declspec(dllexport)
HBITMAP WINAPI icePub_getHBitmapFromImgFile(char *strImgFilename);

__declspec(dllexport)
int WINAPI icePub_saveBmp(HBITMAP hBitmap,char *strBmpFileName);

__declspec(dllexport)
int WINAPI icePub_saveScreen(char *bmpFile);
__declspec(dllexport)
int WINAPI icePub_saveScreenJpg(char *jpgFile);

__declspec(dllexport)
int WINAPI icePub_copyFormToClipboard(HWND hWnd);
__declspec(dllexport)
int WINAPI icePub_formToClipboard(char *strFormTitle);
__declspec(dllexport)
int WINAPI icePub_copyForegroundFormToClipboard();


__declspec(dllexport)
int WINAPI icePub_HBitmapToClipboard(HBITMAP hbitmap);
__declspec(dllexport)
HBITMAP WINAPI icePub_getHBitmapFromClipboard();

__declspec(dllexport)
int WINAPI icePub_imgFileToClipboard(char *strImgFilename);
__declspec(dllexport)
int WINAPI icePub_saveClipboardToBmpFile(char *strBmpFilename);


__declspec(dllexport)
int WINAPI icePub_bmpToJpg(char *strBmpFilename,char *strJpgFilename);

__declspec(dllexport)
int WINAPI icePub_imgBufferReverse(char *mImageBuffer,char *strBmpFilename,int width,int height,int flag);
__declspec(dllexport)
int WINAPI icePub_imgReverse(char *strImgFilename,char *strBmpFilename,int flag);
__declspec(dllexport)
int WINAPI icePub_imgBufferCircumgyrate(char *mImageBuffer,WORD mImageWidth,WORD mImageHeight,char *mBuffer,WORD r,double ki);
__declspec(dllexport)
int WINAPI icePub_imgCircumgyrate(char *strImgFilename,char *strBmpFilename,int radian);

__declspec(dllexport)
int WINAPI icePub_imgBufferToFileTextdata(char *mImageBuffer,char *strFilename,int width,int height,char *strFenge,int flag);
__declspec(dllexport)
int WINAPI icePub_imgToFileTextdata(char *strImgFilename,char *strFilename,char *strFenge,int flag);

__declspec(dllexport)
int WINAPI icePub_getIconFromfile(char *strFilename,char *strIconFilename);

__declspec(dllexport)
int WINAPI icePub_createWordBmpFile(char *strWord,char *strBmpFilename,int bmpWidth,int bmpHeight) ;





__declspec(dllexport)
int WINAPI icePub_regionHBitmap(HWND mHwmd,HBITMAP hBitmap,COLORREF valTransparentColor,int flagIsTransparent);
__declspec(dllexport)
int WINAPI icePub_regionBitmapFile(HWND mHwmd,char *strBmpFilename,COLORREF valTransparentColor,int flagIsTransparent);
__declspec(dllexport)
int WINAPI icePub_regionBitmapSource(HWND mHwmd,unsigned int bmpID,char *szResourceType,COLORREF valTransparentColor,int flagIsTransparent);
__declspec(dllexport)
int WINAPI icePub_regionGifFileDisp(HWND mHwmd,char *strGifFilename,int regionFlag=1);
__declspec(dllexport)
int WINAPI icePub_regionGifSourceDisp(HWND mHwmd,unsigned int gifID,char *szResourceType,int regionFlag);



//database
#include <sqltypes.h>
#include <sqlext.h>
#include <odbcinst.h>

#define DBTYPE_SQLServer 0
#define DBTYPE_Access 1
#define DBTYPE_MySQL 2
#define DBTYPE_Oracle 3
#define DBTYPE_DB2 4


__declspec(dllexport)
int WINAPI icePub_databaseConnect(int typeDatabase,char *strDSNName,char *strDatabase,char *strDBPath,char *strServerName,char *strUsername,char *strPassword,SQLHENV *handleEnv,SQLHDBC *handleDbc);

__declspec(dllexport)
BOOL WINAPI icePub_databaseDisConnect(SQLHENV handleEnv, SQLHDBC handleDbc, SQLHSTMT m_hstmt);

__declspec(dllexport)
BOOL WINAPI icePub_databaseIsOpen(SQLHENV handleEnv, SQLHDBC handleDbc);

__declspec(dllexport)
int WINAPI icePub_databaseGetTablenameList(SQLHDBC handleDbc,CString &strTbList);
__declspec(dllexport)
int WINAPI icePub_databaseGetTableList(SQLHDBC handleDbc,SQLHSTMT *handleStmt,char *strTbList);

__declspec(dllexport)
int WINAPI icePub_databaseHaveTablename(SQLHDBC handleDbc,char *strTbName);


__declspec(dllexport)
int WINAPI icePub_databaseExeSQLDirect(SQLHDBC handleDbc, char *strSql,SQLHSTMT *handleStmt);

__declspec(dllexport)
int WINAPI icePub_databaseGetDefaultCType(long cType);

__declspec(dllexport)
int WINAPI icePub_databaseGetColsCount(SQLHSTMT handleStmt);

__declspec(dllexport)
int WINAPI icePub_databaseGetColsName(SQLHSTMT handleStmt, int indexCols, char *strSqlColName, int len);


__declspec(dllexport)
int WINAPI icePub_databaseSearch(SQLHDBC handleDbc, char * strTbName, char *strFields, char *strConditions, SQLHSTMT *handleStmt);

__declspec(dllexport)
BOOL WINAPI icePub_databaseIsEOF(SQLHSTMT handleStmt);

__declspec(dllexport)
int WINAPI icePub_databaseGetData(SQLHSTMT handleStmt, int i, char *strValue, int len);

__declspec(dllexport)
int WINAPI icePub_databaseQuerytoFile(SQLHSTMT handleStmt,char *strFilename,char *strFenge,int flag=0);
__declspec(dllexport)
int WINAPI icePub_databaseExportToFile(SQLHDBC handleDbc,char *strTableName,char *strFilename,char *strFenge,int flag=0);
__declspec(dllexport)
int WINAPI icePub_databaseImportFromFile(SQLHDBC handleDbc,char *strTableName,char *strFilename,char *strFenge,int flag=0);

__declspec(dllexport)
int WINAPI icePub_databaseBindCol(SQLHSTMT handleStmt,int nColNum,int TargetType,void *lpBuf,int nBufLength);
__declspec(dllexport)
int WINAPI icePub_databaseGetBindNextRow(SQLHSTMT handleStmt);




//
__declspec(dllexport)
int WINAPI icePub_open(char *strPath);
__declspec(dllexport)
unsigned long WINAPI icePub_run(char *strPathFilename);


__declspec(dllexport)
int WINAPI icePub_reboot(void);
__declspec(dllexport)
int WINAPI icePub_shutdown(void);

__declspec(dllexport)
int WINAPI icePub_toClipboard(char *strBuffer);

__declspec(dllexport)
int WINAPI icePub_getClipboardText(char *strBuffer,int maxLen);

__declspec(dllexport)
int WINAPI icePub_setAutorunByOS(char *strPathfilename,char *strKeyName);
__declspec(dllexport)
int WINAPI icePub_setRunBySysStart(char *strKeyName);
__declspec(dllexport)
int WINAPI icePub_clearRunBySysStart(char *strKeyName);

__declspec(dllexport)
int WINAPI icePub_getCurrentUser(char *strUserName);

__declspec(dllexport)
int WINAPI icePub_setHotKey(HWND hWnd,char *strHotKey,unsigned int id);

__declspec(dllexport)
int WINAPI icePub_renewByCmdLine(char *strAppCaption);


//path,file
__declspec(dllexport)
int WINAPI ice_makePaths(CString strPath);
__declspec(dllexport)
int WINAPI icePub_makePaths(char *strPath);

__declspec(dllexport)
int WINAPI ice_deleteFiles(CString strCurrentPath);
__declspec(dllexport)
int WINAPI icePub_deleteFiles(char *strCurrentPath);


__declspec(dllexport)
int WINAPI ice_searchFiles(CString strCurrentPath,CString strFileName,CString &strResult);
__declspec(dllexport)
int WINAPI icePub_searchFiles(char *strCurrentPath,char *strFileName,char *strResult,int resultMaxLen);

__declspec(dllexport)
int WINAPI icePub_compareFiles(char *strFilename1,char *strFilename2);


__declspec(dllexport)
int WINAPI icePub_fileHexToHexString(char *strBinFilename,char *strHexStringFilename,int flag);
__declspec(dllexport)
int WINAPI icePub_fileHexStringToHex(char *strHexStringFilename,char *strBinFilename);


__declspec(dllexport)
int WINAPI icePub_createShortcut(LPCSTR pszPathObj,LPSTR pszParam,LPSTR pszPath,LPSTR pszPathLink,LPSTR pszDesc);


__declspec(dllexport)
int WINAPI icePub_resourceIDSaveToFile(unsigned int wInteger,char *strTypeName,char *strFilename);




__declspec(dllexport)
int WINAPI icePub_makeDeskShortcut(LPCSTR pszPathObj,LPSTR pszPath,LPSTR strShortcut,LPSTR pszDesc);

__declspec(dllexport)
int WINAPI ice_makeDeskShortcut(CString strPathObj,CString strPath,CString strShortcut,CString strDesc);


__declspec(dllexport)
int WINAPI icePub_resourceIDSaveToFile(unsigned int wInteger,char *strTypeName,char *strFilename);






//machine
__declspec(dllexport)
int WINAPI icePub_machineGetInfo(int typeFlag,char *strInfo);


//windowns form
__declspec(dllexport)
int WINAPI icePub_activFormWnd(HWND hWnd);

__declspec(dllexport)
int WINAPI icePub_activForm(char *strFormTitle);


__declspec(dllexport)
int WINAPI ice_closeForm(CString strFilename);
__declspec(dllexport)
int WINAPI icePub_closeForm(char *strFormTitle);

__declspec(dllexport)
int WINAPI ice_closeFormFromFile(CString strFilename);
__declspec(dllexport)
int WINAPI icePub_closeFormFromFile(char *strFilename);


__declspec(dllexport)
int WINAPI icePub_sizeFormToScreen(HWND hWnd,int screenModel);
__declspec(dllexport)
int WINAPI icePub_fullFormToScreen(HWND hWnd);

__declspec(dllexport)
int WINAPI icePub_hideFormFromFile(char *strFilename,int flag);
__declspec(dllexport)
int WINAPI icePub_showFormFromFile(char *strFilename,int flag);



__declspec(dllexport)
int WINAPI icePub_terminatePID(unsigned long pid);


__declspec(dllexport)
int WINAPI ice_setHotKey(HWND hWnd,CString hotKey,unsigned int id);


//menu
__declspec(dllexport)
int WINAPI icePub_popMenu(HWND hWnd,unsigned int menuSrcId,unsigned int indexSubMenu);


//date time
__declspec(dllexport)
int WINAPI icePub_isLeapYear(int m_year);

//encode
__declspec(dllexport)
int WINAPI ice_UTF8toUnicode(CString strUtf8Info,CString &strInfo);
__declspec(dllexport)
int WINAPI icePub_UTF8toUnicode(char *strUtf8Info,char *strInfo,int strMaxLen);

__declspec(dllexport)
int WINAPI icePub_fileUTF8toUnicode(char *strUtf8Filename,char *strFilename);



//math
__declspec(dllexport)
int WINAPI ice_plusMinusCompute(CString strArithmetic,CString &strEnglish,CString &strNumber);
__declspec(dllexport)
int WINAPI icePub_plusMinusCompute(char *strArithmetic,char *strEnglish,char *strNumber);


//ie
__declspec(dllexport)
int WINAPI icePub_ClearCookies(char *strDomain);
__declspec(dllexport)
int WINAPI icePub_ClearCache(char *strDomain);

__declspec(dllexport)
int WINAPI ice_getFavoriteFolder(CString &strFav,int charFlag);
__declspec(dllexport)
int WINAPI icePub_getFavoriteFolder(char *strFav,int charFlag);

__declspec(dllexport)
int WINAPI icePub_setIEStartPage(char *strUrl);




//Multimedia
__declspec(dllexport)
int WINAPI icePub_playWavFile(char *strWavFilename);
__declspec(dllexport)
int WINAPI icePub_playWavResource(unsigned long soundResourceId);




#ifdef __cplusplus 
}
#endif

//#include "YuePrint.h"
