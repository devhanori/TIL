/*
	퀵정렬 _ 시간복잡도
	최선: nlogn / 평균: nlogn / 최악: n^2
*/

#include <iostream>
#include <string>
#include <vector>

template <typename T>
auto partition(
	typename std::vector<T>::iterator begin,
	typename std::vector<T>::iterator end)
{
	// 3개의 반복자 생성
	// 피벗, 벡터의 시작, 마지막 원소
	auto pivot_val = *begin;
	auto left_iter = begin + 1;
	auto right_iter = end;

	while (true)
	{
		// 벡터의 원소부터 시작하여 피벗보다 큰 원소 탐색
		while (*left_iter <= pivot_val && std::distance(left_iter, right_iter) > 0)
			left_iter++;

		// 역순으로 피벗보다 작은 원소 탐색 
		while (*right_iter > pivot_val && std::distance(left_iter, right_iter) > 0)
			right_iter--;

		// left_iter와 right_iter이 같으면 교환할 원소가 없음 _ 종료
		// 그렇지 않으면 left_iter와 right_iter를 교환
		if (left_iter == right_iter)
			break;
		else
			std::iter_swap(left_iter, right_iter);	// 반복자 교환 _ 원소의 위치를 바꿈
	}

	if (pivot_val > *right_iter)
		std::iter_swap(begin, right_iter);
	
	return right_iter;
}

template<typename T>
void quick_sort(
	typename std::vector<T>::iterator begin,
	typename std::vector<T>::iterator last)
{
	// 만약 벡터에 하나 이상의 원소가 있다면
	if (std::distance(begin, last) >= 1)
	{
		// 분할작업 수행
		auto partition_iter = partition<T>(begin, last);

		// 분할 작업에 의해 생성된 벡터를 재귀적으로 정렬
		quick_sort<T>(begin, partition_iter - 1);
		quick_sort<T>(partition_iter, last);
	}
}

template<typename T>
void print_vector(std::vector<T> arr)
{
	for (auto i : arr)
		std::cout << i << " ";

	std::cout << std::endl;
}

void run_quick_sort_test()
{
	std::vector<int> S1{ 45, 1, 2, 56, 32, 32, 11, 23, 29, 6, 2, 3 };
	std::cout << "정렬되지 않은 벡터" << std::endl;
	print_vector<int>(S1);	// <int>는 명시적 Tamplate임
	quick_sort<int>(S1.begin(), --S1.end());
	std::cout << "정렬된 벡터" << std::endl;
	print_vector<int>(S1);

	std::vector<std::string> S2{ "abc", "cba", "good", "hahaha", "aaaa", "nana" };
	std::cout << "정렬되지 않은 벡터" << std::endl;
	print_vector<std::string>(S2);
	quick_sort<std::string>(S2.begin(), --S2.end());
	std::cout << "정렬된 벡터" << std::endl;
	print_vector<std::string>(S2);
}

int main()
{
	run_quick_sort_test();
	return 0;
}