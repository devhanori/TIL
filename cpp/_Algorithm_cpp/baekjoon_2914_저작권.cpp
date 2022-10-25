#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
	double A(0), I(0), result(0);	cin >> A >> I;
	for (double i = A*I; ;i--)
	{
		if (round(i / A * 1000) / 1000 != (I - 1))
			continue;
		else if (round(i / A * 100) / 100 != (I - 1))
			continue;
		else if (round(i / A * 10) / 10 != (I - 1))
			continue;
		else if (round(i / A) != (I - 1))
			continue;
		else
		{
			result = i+1;
			break;
		}	
	}
	cout << result << endl;
	return 0;
}