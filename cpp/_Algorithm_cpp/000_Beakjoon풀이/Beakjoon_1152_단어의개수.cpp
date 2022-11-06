#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string strVal;
	getline(cin, strVal);

	long len = strVal.length();
	long STCount(0);

	for (long i = 0; i < len; i++)
	{
		if (strVal[i] != ' ')
		// char면 Check
		{
			if (i == len - 1) {
			// 마지막 char 처리
				if (strVal[i] == ' ') break;
				else {
				// 공백이 아니면 문장 하나더 있음
					STCount++;
					break;
				}
			}

			// char 다음 char이 공백이면 문장
			if(strVal[i+1] == ' ') STCount++;
		}
	}
	cout << STCount << endl; return 0;
}
