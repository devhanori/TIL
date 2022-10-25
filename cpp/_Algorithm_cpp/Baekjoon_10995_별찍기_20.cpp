#include <iostream>
using namespace std;
int main(void)
{
	int N; cin >> N;
	char star[200] = {};

	int count = N + (N - 1);

	for (int i = 0; i < count; i++)
	{
		if (i % 2 != 0)
			star[i] = ' ';
		else
			star[i] = '*';
	}

	for (int i = 0; i < N; i++)
	{
		if (i % 2 != 0)
			cout << ' ' << star << endl;
		else
			cout << star << endl;
	}

	return 0;
}