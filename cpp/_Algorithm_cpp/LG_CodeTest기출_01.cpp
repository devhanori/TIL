#include <iostream>
using namespace std;

int N;				// 협찬 물품의 수
int D[100000 + 10];	// 선호도
int sol = -30001;	// 첫번째 방법의 최대 선호도

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> D[i];
	}
}

void Solve()
{
	int i, sum = 0;
	for (i = 0; i < N - 2; i++)
	{
		sum = D[i] + D[i + 1] + D[i + 2];
		if (sum > sol)	sol = sum;
	}
}

void Solve2()
{
	int i, sum = 0;
	int index = 0;
	while (index < N)
	{

		for (i = 0; i < N - index; i++)
		{
			sum += D[i];
			if (sum > sol)	sol = sum;
		}

		sum = 0;

		for (i = N - index; i < N ; i++)
		{
			sum += D[i];
			if (sum > sol)	sol = sum;
		}

		sum = 0;
		index++;
	}
}

int main() {
	InputData();
	Solve2();
	cout << sol << endl;
	return 0;
}