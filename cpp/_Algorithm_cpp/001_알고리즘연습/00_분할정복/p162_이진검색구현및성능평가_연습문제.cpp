#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

// �����˻��Լ�
bool linear_search(int N, std::vector<int>& S)
{
	for (auto i : S)
	{
		if (i == N)
			return true;
	}
}

// �����˻��Լ�
bool binary_search(int N, std::vector<int>& S)
{
	auto first = S.begin();
	auto last = S.end();

	while (true)
	{
		// ���� �˻� ������ �߰� ���Ҹ� mid_element�� ����
		auto range_length = distance(first, last);	// frist���� end���� �󸶳� �Ÿ��� �������� ��ȯ, distance
		auto mid_element_index = std::floor(range_length / 2);	// floor -> ����
		auto mid_element = *(first + mid_element_index);

		// mid_element�� N ���� ��
		if (mid_element == N)
			return true;
		else if (mid_element > N)
			std::advance(last, -mid_element_index);	// advance iter�� ���ϴ� ������ �̵���Ű�� �Լ�
		else if (mid_element < N)
			std::advance(first, mid_element_index);

		// ���� �˻� ������ �ִ� �ϳ��� ���Ҹ� ���� �ִٸ� false�� ��ȯ
		if (range_length == 1)
			return false;
	}
}

// Tset �Լ���
void run_small_search_test()
{
	auto N = 2;
	vector<int> S{ 1,3,2,4,5,7,9,8,6 };
	sort(S.begin(), S.end());

	if (linear_search(N, S))
		cout << "���� �˻����� ���Ҹ� ã�ҽ��ϴ�." << endl;
	else
		cout << "���� �˻����� ���Ҹ� ã�� ���߽��ϴ�." << endl;

	if (binary_search(N, S))
		cout << "���� �˻����� ���Ҹ� ã�ҽ��ϴ�." << endl;
	else
		cout << "���� �˻����� ���Ҹ� ã�� ���߽��ϴ�." << endl;
}

void run_large_search_test(int size, int N)
{
	vector<int> S;
	random_device rd;	// ������� ���� ���� ��ü
	mt19937 rand(rd());	// mt19937 ���� ���� -> rd�� �ʱ�ȭ

	// [1,size] ���� �ȿ��� ���� ���� �߻�
	uniform_int_distribution<mt19937::result_type> uiform_dist(1, size);

	// S�� ���� �߰�
	for (auto i = 0; i < size; i++)
	{
		S.push_back(uiform_dist(rand));
	}

	sort(S.begin(), S.end());

	// �˻��ð� ���� ����
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	
	bool search_result = binary_search(N, S);

	// �˻��ð� ���� ����
	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout << "���� �˻� ���� �ð�: " << diff.count() << endl;

	if (search_result)
		cout << "���Ҹ� ã�ҽ��ϴ�." << endl;
	else
		cout << "���Ҹ� ã�� ���߽��ϴ�." << endl;
}


int main(void)
{
	run_small_search_test();

	run_large_search_test(100000, 36543);
	run_large_search_test(1000000, 36543);
	run_large_search_test(10000000, 36543);

	return 0;
}