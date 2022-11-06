#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int num; cin >> num;
	string strNum;
	unsigned long result(0);
	vector<int> list(num);
	
	cin >> strNum;

	for (int i = 0; i < num; i++)
		list[i] = strNum.at(i) - '0';
	
	for (auto value : list)
		result += value;

	cout << result << endl;

	return 0;
}