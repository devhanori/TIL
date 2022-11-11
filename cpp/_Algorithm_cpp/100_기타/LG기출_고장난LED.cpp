#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<vector<int>, int> mapLED = {
		{{1,1,1,1,1,1,0}, 0 },
		{{0,0,1,1,0,0,0}, 1 },
		{{0,1,1,0,1,1,1}, 2 },
		{{0,1,1,1,1,0,1}, 3 },
		{{1,0,1,1,0,0,1}, 4 },
		{{1,1,0,1,1,0,1}, 5 },
		{{1,1,0,1,1,1,1}, 6 },
		{{1,1,1,1,0,0,0}, 7 },
		{{1,1,1,1,1,1,1}, 8 },
		{{1,1,1,1,1,0,1}, 9 },
};

map<int, int> mapBi = {
	{1,2},
	{2,4},
	{3,8},
	{4,16},
	{5,32},
	{6,64},
	{7,128}
};

int main()
{
	vector<int> result;
	vector<int> brokenLED;
	int count(0);
	string light; cin >> light;
	for(int i = 0; i < 7; i++)
	{
		int temp = light.at(i) - '0';
		brokenLED.push_back(temp);
		if (temp == 0)
			count++;
	}

	int loop = mapBi[count];
	for (int i = 0; i < loop; i++)
	{
		int test = i;
		vector<int> TempLED(brokenLED);
		for (int j = 0; j < 7; j++)
		{
			if (test == 0)
			{
				break;
			}

			if (TempLED[j] == 1)
			{
				continue;
			}
			else
			{
				TempLED[j] = test % 2;
			}

			test /= 2;
		}
		if(mapLED.find(TempLED) != mapLED.end())
			result.push_back(mapLED[TempLED]);
	}

	sort(result.begin(), result.end());

	for (auto i : result)
	{
		cout << i << endl;
	}

	return 0;
}