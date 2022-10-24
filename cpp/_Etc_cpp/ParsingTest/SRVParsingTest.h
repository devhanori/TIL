#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

typedef struct log_datetime
{
	string logTime;
	string logDate;
	bool operator <(const log_datetime& var) const
	// map 검색 가능하도록 연산자 재정의
	{
		if (logDate != var.logDate) {
			return logDate < var.logDate;
		}
		else {
			return logTime < var.logTime;
		}
	}
	void clear()
	{
		logTime = "", logDate = "";
	}
}DATETIME;

typedef struct log_info
{
	string State;
	string TEXT;
	string Module;
	string backdata;
	string CmdNum;
	void clear()
	{
		State = "", Module = "", TEXT = "", backdata = "", CmdNum = "";
	}
}LOGINFO;

typedef struct log_data
{
	DATETIME dt;
	LOGINFO info;
	bool flag;
	void clear()
	{
		dt.clear();
		info.clear();
		flag = false;
	}
}LOGDATA;

typedef struct server_log_lang
{
	string num;
	string title;
	string content;
	string len;
	int check;
	void clear()
	{
		num = ""; title = ""; content = ""; len = ""; check = 0;
	}
}SRVCMD_LANG;

int nCellUnit;				// 모듈 당 셀 갯수
int nTotalStep;				// TotalStep 값
int nTotalLen;				// Total길이
bool bStepflag;				// ID가 TotalStep일 때 다음 파싱길이 Check
bool bParseError;			// 파싱오류 발생 시 작동 *;와 Total 길이 Check로 구분

map<string, vector<SRVCMD_LANG>> mapLANG;
char buf[20480];