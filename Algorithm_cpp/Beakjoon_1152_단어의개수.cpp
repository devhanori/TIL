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
		// char�� Check
		{
			if (i == len - 1) {
			// ������ char ó��
				if (strVal[i] == ' ') break;
				else {
				// ������ �ƴϸ� ���� �ϳ��� ����
					STCount++;
					break;
				}
			}

			// char ���� char�� �����̸� ����
			if(strVal[i+1] == ' ') STCount++;
		}
	}
	cout << STCount << endl; return 0;
}
