#include "SRVParsingTest.h"

void LoadMapCMD()
{
	ifstream file;
	string line, strTemp[5];
	SRVCMD_LANG lengTemp;
	vector<SRVCMD_LANG> vecInfo;

	mapLANG.clear();

	file.open(".psr");

	if (file.getline(buf, sizeof(buf)).eof())
	{
		line = buf;
		lengTemp.clear();
		stringstream ss(line);
		getline(ss, strTemp[1], ';');

		nCellUnit = atoi(strTemp[1].c_str());
		return;
	}

	// 의미없는 Line 제거
	if (file.getline(buf, sizeof(buf)).eof())
	{
		return;
	}

	while (!file.getline(buf, sizeof(buf)).eof())
	{
		line = buf;
		lengTemp.clear();
		stringstream ss(line);

		for (int i = 0; i < 5; i++)
			getline(ss, strTemp[i], ';');

		lengTemp.num = strTemp[0];
		lengTemp.title = strTemp[1];
		lengTemp.content = strTemp[2];
		lengTemp.len = strTemp[3];
		lengTemp.check = atoi(strTemp[4].c_str());

		if (mapLANG.find(lengTemp.num) != mapLANG.end())
		{
			mapLANG.find(lengTemp.num)->second.push_back(lengTemp);
		}
		else
		{
			vecInfo.clear();
			vecInfo.push_back(lengTemp);
			mapLANG.insert(pair<string, vector<SRVCMD_LANG>>(lengTemp.num, vecInfo));
		}
	}
}

map<string, vector<vector<string>>> GetSRVLogInfoMapNew(string Message)
{
	map<string, vector<vector<string>>> mapVec;
	vector<vector<string>> result;

	// Log 길이에 문제 없으면
	size_t MessageLen = Message.length();
	if (MessageLen < 50)
	{
		mapVec.insert(pair <string, vector<vector<string>>>("LogData이상", result));
		return mapVec;
	}

	// CMD 정보 얻음
	string strTemp = Message;
	string commamd = strTemp.substr(21, 4);
	vector<SRVCMD_LANG> vecLogLeng = mapLANG[commamd];

	int nTotallen(0);
	string totallen = vecLogLeng.at(0).len;
	if (totallen.find('n') == string::npos)
		// n이 포함되어 있지 않으면
	{
		nTotallen = atoi(totallen.c_str());
	}

	int lenCount(0), totalstep(0);
	// CMD 파싱시작
	for (auto data : vecLogLeng)
	{
		switch (data.check)
		{
		case -1:			// TotalLeng 생략
			continue;
			break;
		case 1:			// n포함된 Length
		{
			size_t pos = data.len.rfind('*');
			int sublen = atoi(data.len.substr(0, pos).c_str());
			nTotallen = nTotallen + sublen * totalstep;	// Data 길이 계산
			
			for (int i = 0; i < totalstep; i++)
			{
				lenCount += sublen;
				if (nTotallen < lenCount)
				{
					// error
				}
				strTemp.substr(lenCount, sublen);

				//cmd와 data type 예외처리
			}
			totalstep = 0;
			break;
		}
		default:
		{
			int len = atoi(data.len.c_str());
			lenCount += len;
			if (nTotallen < lenCount)
			{
				// error
			}

			strTemp.substr(lenCount, len);
			if (data.content == "Total Step")
				totalstep = atoi(strTemp.c_str());
			break;
		}
		}
	}
	return mapVec;
}

int main(void)
{
	LoadMapCMD();
}