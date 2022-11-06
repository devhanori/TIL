#include <iostream>
using namespace std;

int N;				// ���� ��ǰ�� ��
int D[100000 + 10];	// ��ȣ��
int sol = -30001;	// ù��° ����� �ִ� ��ȣ��

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