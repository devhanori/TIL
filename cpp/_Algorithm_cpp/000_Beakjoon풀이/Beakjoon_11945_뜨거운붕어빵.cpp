#include <iostream>

using namespace std;

int main(void)
{
	int N(0), M(0);
	char bread[11][11] = {};

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> bread[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = M-1; j >= 0; j--)
			cout << bread[i][j];
		cout << endl;
	}
	
	return 0;
}