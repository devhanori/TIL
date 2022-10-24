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
	// map �˻� �����ϵ��� ������ ������
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

int nCellUnit;				// ��� �� �� ����
int nTotalStep;				// TotalStep ��
int nTotalLen;				// Total����
bool bStepflag;				// ID�� TotalStep�� �� ���� �Ḻ̌��� Check
bool bParseError;			// �Ľ̿��� �߻� �� �۵� *;�� Total ���� Check�� ����

map<string, vector<SRVCMD_LANG>> mapLANG;
char buf[20480];