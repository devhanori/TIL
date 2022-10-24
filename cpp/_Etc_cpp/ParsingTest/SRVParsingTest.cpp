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

	// �ǹ̾��� Line ����
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

	// Log ���̿� ���� ������
	size_t MessageLen = Message.length();
	if (MessageLen < 50)
	{
		mapVec.insert(pair <string, vector<vector<string>>>("LogData�̻�", result));
		return mapVec;
	}

	// CMD ���� ����
	string strTemp = Message;
	string commamd = strTemp.substr(21, 4);
	vector<SRVCMD_LANG> vecLogLeng = mapLANG[commamd];

	int nTotallen(0);
	string totallen = vecLogLeng.at(0).len;
	if (totallen.find('n') == string::npos)
		// n�� ���ԵǾ� ���� ������
	{
		nTotallen = atoi(totallen.c_str());
	}

	int lenCount(0), totalstep(0);
	// CMD �Ľ̽���
	for (auto data : vecLogLeng)
	{
		switch (data.check)
		{
		case -1:			// TotalLeng ����
			continue;
			break;
		case 1:			// n���Ե� Length
		{
			size_t pos = data.len.rfind('*');
			int sublen = atoi(data.len.substr(0, pos).c_str());
			nTotallen = nTotallen + sublen * totalstep;	// Data ���� ���
			
			for (int i = 0; i < totalstep; i++)
			{
				lenCount += sublen;
				if (nTotallen < lenCount)
				{
					// error
				}
				strTemp.substr(lenCount, sublen);

				//cmd�� data type ����ó��
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