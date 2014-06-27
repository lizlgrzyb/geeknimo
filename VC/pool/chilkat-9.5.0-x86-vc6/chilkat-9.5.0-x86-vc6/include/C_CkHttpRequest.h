// This is a generated source file for Chilkat version 9.5.0.40
#ifndef _C_CkHttpRequest_H
#define _C_CkHttpRequest_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"

HCkHttpRequest CkHttpRequest_Create(void);
void CkHttpRequest_Dispose(HCkHttpRequest handle);
void CkHttpRequest_getCharset(HCkHttpRequest cHandle, HCkString retval);
void CkHttpRequest_putCharset(HCkHttpRequest cHandle, const char *newVal);
const char *CkHttpRequest_charset(HCkHttpRequest cHandle);
void CkHttpRequest_getContentType(HCkHttpRequest cHandle, HCkString retval);
void CkHttpRequest_putContentType(HCkHttpRequest cHandle, const char *newVal);
const char *CkHttpRequest_contentType(HCkHttpRequest cHandle);
void CkHttpRequest_getDebugLogFilePath(HCkHttpRequest cHandle, HCkString retval);
void CkHttpRequest_putDebugLogFilePath(HCkHttpRequest cHandle, const char *newVal);
const char *CkHttpRequest_debugLogFilePath(HCkHttpRequest cHandle);
void CkHttpRequest_getEntireHeader(HCkHttpRequest cHandle, HCkString retval);
void CkHttpRequest_putEntireHeader(HCkHttpRequest cHandle, const char *newVal);
const char *CkHttpRequest_entireHeader(HCkHttpRequest cHandle);
void CkHttpRequest_getHttpVerb(HCkHttpRequest cHandle, HCkString retval);
void CkHttpRequest_putHttpVerb(HCkHttpRequest cHandle, const char *newVal);
const char *CkHttpRequest_httpVerb(HCkHttpRequest cHandle);
void CkHttpRequest_getHttpVersion(HCkHttpRequest cHandle, HCkString retval);
void CkHttpRequest_putHttpVersion(HCkHttpRequest cHandle, const char *newVal);
const char *CkHttpRequest_httpVersion(HCkHttpRequest cHandle);
void CkHttpRequest_getLastErrorHtml(HCkHttpRequest cHandle, HCkString retval);
const char *CkHttpRequest_lastErrorHtml(HCkHttpRequest cHandle);
void CkHttpRequest_getLastErrorText(HCkHttpRequest cHandle, HCkString retval);
const char *CkHttpRequest_lastErrorText(HCkHttpRequest cHandle);
void CkHttpRequest_getLastErrorXml(HCkHttpRequest cHandle, HCkString retval);
const char *CkHttpRequest_lastErrorXml(HCkHttpRequest cHandle);
int CkHttpRequest_getNumHeaderFields(HCkHttpRequest cHandle);
int CkHttpRequest_getNumParams(HCkHttpRequest cHandle);
void CkHttpRequest_getPath(HCkHttpRequest cHandle, HCkString retval);
void CkHttpRequest_putPath(HCkHttpRequest cHandle, const char *newVal);
const char *CkHttpRequest_path(HCkHttpRequest cHandle);
BOOL CkHttpRequest_getSendCharset(HCkHttpRequest cHandle);
void CkHttpRequest_putSendCharset(HCkHttpRequest cHandle, BOOL newVal);
BOOL CkHttpRequest_getUtf8(HCkHttpRequest cHandle);
void CkHttpRequest_putUtf8(HCkHttpRequest cHandle, BOOL newVal);
BOOL CkHttpRequest_getVerboseLogging(HCkHttpRequest cHandle);
void CkHttpRequest_putVerboseLogging(HCkHttpRequest cHandle, BOOL newVal);
void CkHttpRequest_getVersion(HCkHttpRequest cHandle, HCkString retval);
const char *CkHttpRequest_version(HCkHttpRequest cHandle);
BOOL CkHttpRequest_AddBytesForUpload(HCkHttpRequest cHandle, const char *name, const char *remoteFileName, HCkByteData byteData);
BOOL CkHttpRequest_AddBytesForUpload2(HCkHttpRequest cHandle, const char *name, const char *remoteFileName, HCkByteData byteData, const char *contentType);
BOOL CkHttpRequest_AddFileForUpload(HCkHttpRequest cHandle, const char *name, const char *filePath);
BOOL CkHttpRequest_AddFileForUpload2(HCkHttpRequest cHandle, const char *name, const char *filePath, const char *contentType);
void CkHttpRequest_AddHeader(HCkHttpRequest cHandle, const char *name, const char *value);
void CkHttpRequest_AddParam(HCkHttpRequest cHandle, const char *name, const char *value);
BOOL CkHttpRequest_AddStringForUpload(HCkHttpRequest cHandle, const char *name, const char *filename, const char *strData, const char *charset);
BOOL CkHttpRequest_AddStringForUpload2(HCkHttpRequest cHandle, const char *name, const char *filename, const char *strData, const char *charset, const char *contentType);
BOOL CkHttpRequest_GenerateRequestText(HCkHttpRequest cHandle, HCkString outStr);
const char *CkHttpRequest_generateRequestText(HCkHttpRequest cHandle);
BOOL CkHttpRequest_GetHeaderField(HCkHttpRequest cHandle, const char *name, HCkString outStr);
const char *CkHttpRequest_getHeaderField(HCkHttpRequest cHandle, const char *name);
BOOL CkHttpRequest_GetHeaderName(HCkHttpRequest cHandle, int index, HCkString outStr);
const char *CkHttpRequest_getHeaderName(HCkHttpRequest cHandle, int index);
BOOL CkHttpRequest_GetHeaderValue(HCkHttpRequest cHandle, int index, HCkString outStr);
const char *CkHttpRequest_getHeaderValue(HCkHttpRequest cHandle, int index);
BOOL CkHttpRequest_GetParam(HCkHttpRequest cHandle, const char *name, HCkString outStr);
const char *CkHttpRequest_getParam(HCkHttpRequest cHandle, const char *name);
BOOL CkHttpRequest_GetParamName(HCkHttpRequest cHandle, int index, HCkString outStr);
const char *CkHttpRequest_getParamName(HCkHttpRequest cHandle, int index);
BOOL CkHttpRequest_GetParamValue(HCkHttpRequest cHandle, int index, HCkString outStr);
const char *CkHttpRequest_getParamValue(HCkHttpRequest cHandle, int index);
BOOL CkHttpRequest_GetUrlEncodedParams(HCkHttpRequest cHandle, HCkString outStr);
const char *CkHttpRequest_getUrlEncodedParams(HCkHttpRequest cHandle);
BOOL CkHttpRequest_LoadBodyFromBytes(HCkHttpRequest cHandle, HCkByteData byteData);
BOOL CkHttpRequest_LoadBodyFromFile(HCkHttpRequest cHandle, const char *filePath);
BOOL CkHttpRequest_LoadBodyFromString(HCkHttpRequest cHandle, const char *bodyStr, const char *charset);
void CkHttpRequest_RemoveAllParams(HCkHttpRequest cHandle);
BOOL CkHttpRequest_RemoveHeader(HCkHttpRequest cHandle, const char *name);
void CkHttpRequest_RemoveParam(HCkHttpRequest cHandle, const char *name);
BOOL CkHttpRequest_SaveLastError(HCkHttpRequest cHandle, const char *path);
void CkHttpRequest_SetFromUrl(HCkHttpRequest cHandle, const char *url);
BOOL CkHttpRequest_StreamBodyFromFile(HCkHttpRequest cHandle, const char *filePath);
void CkHttpRequest_UseGet(HCkHttpRequest cHandle);
void CkHttpRequest_UseHead(HCkHttpRequest cHandle);
void CkHttpRequest_UsePost(HCkHttpRequest cHandle);
void CkHttpRequest_UsePostMultipartForm(HCkHttpRequest cHandle);
void CkHttpRequest_UsePut(HCkHttpRequest cHandle);
void CkHttpRequest_UseUpload(HCkHttpRequest cHandle);
void CkHttpRequest_UseUploadPut(HCkHttpRequest cHandle);
void CkHttpRequest_UseXmlHttp(HCkHttpRequest cHandle, const char *xmlBody);
#endif
