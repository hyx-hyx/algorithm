// ---------------------------------------------------------------

// FlieNmae:

// SofInfo.h

// Remark:

// 通过读取注册表获得本机已安装软件信息。

// ---------------------------------------------------------------

#pragma once

#include <vector>
#include <stdafx.h>
#include <SoftInfo.h>

struct SoftInfo

{

// 软件名

CString m_strSoftName;

// 软件版本号

CString m_strSoftVersion;

// 软件安装目录

CString m_strInstallLocation;

// 软件发布厂商

CString m_strPublisher;

// 主程序所在完整路径

CString m_strMainProPath;

// 卸载exe所在完整路径

CString m_strUninstallPth;

};

class CSoftInfo

{

private:

// 保存已安装常用软件安装信息

std::vector<SoftInfo> m_SoftInfoArr;

// 保存系统补丁信息

std::vector<SoftInfo> m_SystemPatchesArr;

public:

CSoftInfo();

~CSoftInfo(){}

// 获取一个包含常用软件安装信息的Vector

std::vector<SoftInfo> GetSoftInfo (void) const;

// 获取所有已安装常用软件名

void GetSoftName (std::vector<LPCTSTR>& lpszSoftName);

// 获取所有已安装常用软件版本号

void GetSoftVersion (std::vector<LPCTSTR>& lpszSoftVersion);

// 获取所有已安装常用软件安装目录

void GetInstallLocation (std::vector<LPCTSTR>& lpszInstallLocation);

// 获取所有已安装常用软件发布厂商

void GetPublisher (std::vector<LPCTSTR>& lpszPublisher);

// 获取所有已安装常用软件主程序所在路径

void GetMainProPath (std::vector<LPCTSTR>& lpszMainProPath);

// 获取所有已安装常用软件卸载程序所在路径

void GetUninstallPth (std::vector<LPCTSTR>& lpszSoftName);

// 获取一个包含系统补丁信息的Vector

std::vector<SoftInfo> GetSystemPatchesInfo (void) const;

// 获取所有已安装系统补丁名

void GetSystemPatchesName (std::vector<LPCTSTR>& lpszSoftName);

};

或者

// FlieNmae: Softinfo.cpp


CSoftInfo::CSoftInfo()

{

struct SoftInfo softinfo;

HKEY RootKey; // 主键

LPCTSTR lpSubKey; // 子键名称

HKEY hkResult; // 将要打开键的句柄

HKEY hkRKey;

LONG lReturn; // 记录读取注册表是否成功

CString strBuffer;

CString strMidReg;

DWORD index = 0;

TCHAR szKeyName[255] = {0}; // 注册表项名称

TCHAR szBuffer[255] = {0};

DWORD dwKeyLen = 255;

DWORD dwNameLen = 255;

DWORD dwType = REG_BINARY|REG_DWORD|REG_EXPAND_SZ|REG_MULTI_SZ|REG_NONE|REG_SZ;

RootKey = HKEY_LOCAL_MACHINE;

lpSubKey = _T("SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall");

lReturn = RegOpenKeyEx(RootKey, lpSubKey, 0, KEY_ALL_ACCESS, &hkResult);

if (lReturn == ERROR_SUCCESS)

{

while (ERROR_NO_MORE_ITEMS !=RegEnumKeyEx(hkResult, index, szKeyName, &dwKeyLen, 0, NULL, NULL, NULL))

{

index++;

strBuffer.Format(_T("%s"), szKeyName);

if (!strBuffer.IsEmpty())

{

strMidReg = (CString)lpSubKey +_T("\") + strBuffer;

if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, strMidReg, 0, KEY_ALL_ACCESS, &hkRKey)==ERROR_SUCCESS)

{

RegQueryValueEx(hkRKey, _T("DisplayName"), 0, &dwType, (LPBYTE)szBuffer,&dwNameLen);

softinfo.m_strSoftName = szBuffer;

dwNameLen = 255;

memset(szBuffer, 0, 255);

RegQueryValueEx(hkRKey, _T("DisplayVersion"), 0, &dwType, (LPBYTE)szBuffer,&dwNameLen);

softinfo.m_strSoftVersion = szBuffer;

dwNameLen = 255;

memset(szBuffer, 0, 255);

RegQueryValueEx(hkRKey, _T("InstallLocation"), 0, &dwType, (LPBYTE)szBuffer,&dwNameLen);

softinfo.m_strInstallLocation = szBuffer;

dwNameLen = 255;

memset(szBuffer, 0, 255);

RegQueryValueEx(hkRKey, _T("Publisher"), 0, &dwType, (LPBYTE)szBuffer,&dwNameLen);

softinfo.m_strPublisher = szBuffer;

dwNameLen = 255;

RegQueryValueEx(hkRKey, _T("InstallLocation"), 0, &dwType, (LPBYTE)szBuffer,&dwNameLen);

softinfo.m_strMainProPath = szBuffer;

dwNameLen = 255;

memset(szBuffer, 0, 255);

RegQueryValueEx(hkRKey, _T("UninstallString"), 0, &dwType, (LPBYTE)szBuffer,&dwNameLen);

softinfo.m_strUninstallPth = szBuffer;

dwNameLen = 255;

memset(szBuffer, 0, 255);

if(!softinfo.m_strSoftName.IsEmpty())

{

if(strBuffer.GetAt(0) == 'K' && strBuffer.GetAt(1) == 'B')

{

m_SystemPatchesArr.push_back(softinfo);

}

else

{

m_SoftInfoArr.push_back(softinfo);

}

}

}

dwKeyLen = 255;

memset(szKeyName,0, 255);

}

}

RegCloseKey(hkResult);

}

else

{

::MessageBox(NULL, _T("打开注册表失败!"), NULL, MB_ICONWARNING);

}

}

std::vector<SoftInfo> CSoftInfo::GetSoftInfo (void) const

{

return m_SoftInfoArr;

}

void CSoftInfo::GetSoftName (std::vector<LPCTSTR>& lpszSoftName)

{

std::vector<SoftInfo>::iterator iter;

for (iter = m_SoftInfoArr.begin(); iter != m_SoftInfoArr.end(); iter++)

{

lpszSoftName.push_back(iter->m_strSoftName);

}

}

void CSoftInfo::GetSoftVersion (std::vector<LPCTSTR>& lpszSoftVersion)

{

std::vector<SoftInfo>::iterator iter;

for (iter = m_SoftInfoArr.begin(); iter != m_SoftInfoArr.end(); iter++)

{

if (!(iter->m_strSoftVersion).IsEmpty())

{

lpszSoftVersion.push_back(iter->m_strSoftVersion);

}

}

}

void CSoftInfo::GetInstallLocation (std::vector<LPCTSTR>& lpszInstallLocation)

{

std::vector<SoftInfo>::iterator iter;

for (iter = m_SoftInfoArr.begin(); iter != m_SoftInfoArr.end(); iter++)

{

if (!(iter->m_strInstallLocation).IsEmpty())

{

lpszInstallLocation.push_back(iter->m_strInstallLocation);

}

}

}

void CSoftInfo::GetPublisher (std::vector<LPCTSTR>& lpszPublisher)

{

std::vector<SoftInfo>::iterator iter;

bool bSign;

for (iter = m_SoftInfoArr.begin(); iter != m_SoftInfoArr.end(); iter++)

{

bSign = true;

// 初步去重复厂商

std::vector<LPCTSTR>::iterator itr;

for (itr = lpszPublisher.begin(); itr != lpszPublisher.end(); itr++)

{

if (iter->m_strPublisher == (CString)*itr)

{

bSign = false;

}

}

if (bSign)

{

lpszPublisher.push_back(iter->m_strPublisher);

}

}

}

void CSoftInfo::GetMainProPath (std::vector<LPCTSTR>& lpszMainProPath)

{

std::vector<SoftInfo>::iterator iter;

for (iter = m_SoftInfoArr.begin(); iter != m_SoftInfoArr.end(); iter++)

{

if (!(iter->m_strMainProPath).IsEmpty())

{

lpszMainProPath.push_back(iter->m_strMainProPath);

}

}

}

void CSoftInfo::GetUninstallPth (std::vector<LPCTSTR>& lpszSoftName)

{

std::vector<SoftInfo>::iterator iter;

for (iter = m_SoftInfoArr.begin(); iter != m_SoftInfoArr.end(); iter++)

{

if (!(iter->m_strUninstallPth).IsEmpty())

{

lpszSoftName.push_back(iter->m_strUninstallPth);

}

}

}

std::vector<SoftInfo> CSoftInfo::GetSystemPatchesInfo (void) const

{

return m_SystemPatchesArr;

}

void CSoftInfo::GetSystemPatchesName (std::vector<LPCTSTR>& lpszSoftName)

{

std::vector<SoftInfo>::iterator iter;

for (iter = m_SystemPatchesArr.begin(); iter != m_SystemPatchesArr.end(); iter++)

{

lpszSoftName.push_back(iter->m_strSoftName);

}

}