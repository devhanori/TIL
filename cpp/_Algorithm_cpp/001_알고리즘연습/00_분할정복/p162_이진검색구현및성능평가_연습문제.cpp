#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

// 선형검색함수
bool linear_search(int N, std::vector<int>& S)
{
	for (auto i : S)
	{
		if (i == N)
			return true;
	}
}

// 이진검색함수
bool binary_search(int N, std::vector<int>& S)
{
	auto first = S.begin();
	auto last = S.end();

	while (true)
	{
		// 현재 검색 범위의 중간 원소를 mid_element에 저장
		auto range_length = distance(first, last);	// frist에서 end까지 얼마나 거리를 가지는지 반환, distance
		auto mid_element_index = std::floor(range_length / 2);	// floor -> 내림
		auto mid_element = *(first + mid_element_index);

		// mid_element와 N 값을 비교
		if (mid_element == N)
			return true;
		else if (mid_element > N)
			std::advance(last, -mid_element_index);	// advance iter를 원하는 곳으로 이동시키는 함수
		else if (mid_element < N)
			std::advance(first, mid_element_index);

		// 현재 검색 범위에 있는 하나의 원소만 남아 있다면 false를 반환
		if (range_length == 1)
			return false;
	}
}

// Tset 함수들
void run_small_search_test()
{
	auto N = 2;
	vector<int> S{ 1,3,2,4,5,7,9,8,6 };
	sort(S.begin(), S.end());

	if (linear_search(N, S))
		cout << "선형 검색으로 원소를 찾았습니다." << endl;
	else
		cout << "선형 검색으로 원소를 찾지 못했습니다." << endl;

	if (binary_search(N, S))
		cout << "이진 검색으로 원소를 찾았습니다." << endl;
	else
		cout << "이진 검색으로 원소를 찾지 못했습니다." << endl;
}

void run_large_search_test(int size, int N)
{
	vector<int> S;
	random_device rd;	// 비결정적 난수 생성 객체
	mt19937 rand(rd());	// mt19937 난수 엔진 -> rd로 초기화

	// [1,size] 범위 안에서 정수 난수 발생
	uniform_int_distribution<mt19937::result_type> uiform_dist(1, size);

	// S에 난수 추가
	for (auto i = 0; i < size; i++)
	{
		S.push_back(uiform_dist(rand));
	}

	sort(S.begin(), S.end());

	// 검색시간 측정 시작
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	
	bool search_result = binary_search(N, S);

	// 검색시간 측정 종료
	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout << "이진 검색 수행 시간: " << diff.count() << endl;

	if (search_result)
		cout << "원소를 찾았습니다." << endl;
	else
		cout << "원소를 찾지 못했습니다." << endl;
}


int main(void)
{
	run_small_search_test();

	run_large_search_test(100000, 36543);
	run_large_search_test(1000000, 36543);
	run_large_search_test(10000000, 36543);

	return 0;
}