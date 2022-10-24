#include <iostream>
using namespace std;

void starblank(int num, int nBlank)
{
	for (int i = 0; i < num; i++)
	{
		if (i < nBlank-1)
			cout << " ";
		else
			cout << "*";
	}
	cout << endl;
}

int main(void)
{
	int num(0), loop(0);
	
	cin >> num;
	loop = num * 2 - 1;
	int blank = num;
	
	for (int i = 1; i < num*2; i++)
	{
		if (i < num)
		{						
			starblank(num,blank);
			blank--;
		}
		else if (i > num)
		{
			blank++;
			starblank(num, blank);
		}
		else
		{
			starblank(num, 1);
		}
	}

	return 0;
}