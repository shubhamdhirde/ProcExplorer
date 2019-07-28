#pragma warning(disable:4996)
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>
#include<iostream>
#include<string.h>
#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <io.h>

typedef struct LogFile
{
	char ProcessName[100];
	unsigned int pid;
	unsigned int ppid;
	unsigned int thread_cnt;
}LOGFILE;

class ThreadInfo
{
private:
	DWORD PID;
	HANDLE hThreadSnap;
	THREADENTRY32 te32;

public:
	ThreadInfo(DWORD);
	BOOL ThreadDisplay();
};

class DLLInfo
{
private:
	DWORD PID;
	MODULEENTRY32 me32;
	HANDLE hProcessSnap;

public:
	DLLInfo(DWORD);
	BOOL DependentDLLDisplay();
};

class ProcessInfo
{
private:
	DWORD PID;
	DLLInfo * pdobj;
	ThreadInfo *ptobj;
	HANDLE hProcessSnap;
	PROCESSENTRY32 pe32;

public:
	ProcessInfo();
	BOOL ProcessDisplay(char *);
	BOOL ProcessLog();
	BOOL ReadLog(DWORD, DWORD, DWORD, DWORD);
	BOOL ProcessSearch(char *);
	BOOL KillProcess(char *);
};