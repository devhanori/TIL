/*
	부분 퀵 정렬 알고리즘의 구현
	==> 벡터 V가 주어졌을 때, k개의 원소로 이루어진 정렬된 부분 벡터를 구함.
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

template <typename T>
auto partition(
	typename std::vector<T>::iterator begin,
	typename std::vector<T>::iterator end)
{
	auto pivot_val = *begin;
	auto left_iter = begin + 1;
	auto right_iter = end;

	while (true)
	{
		// 왼쪽부터 피벗보다 큰 값 탐색
		while (*left_iter <= pivot_val && std::distance(left_iter, right_iter) > 0)
		{
			left_iter++;
		}
			

		// 오른쪽부터 피벗보다 작은 값 탐색
		while (*right_iter > pivot_val && std::distance(left_iter, right_iter) > 0)
			right_iter--;

		if (left_iter == right_iter)
			break;
		else
			std::iter_swap(left_iter, right_iter);
	}

	if (pivot_val > *right_iter)
		std::iter_swap(begin, right_iter);

	return right_iter;
}

template <typename T>
void quick_sort(
	typename std::vector<T>::iterator begin,
	typename std::vector<T>::iterator end)
{
	if (std::distance(begin, end) >= 1)
	{
		auto partition_iter = partition<T>(begin, end);
		quick_sort<T>(begin, partition_iter-1);
		quick_sort<T>(partition_iter, end);
	}
}

template <typename T>
void part_quick_sort(
	size_t k,
	typename std::vector<T>::iterator begin,
	typename std::vector<T>::iterator end)
{
	if (std::distance(begin, end) >= 1)
	{
		auto partition_iter = partition<T>(begin, end);

		part_quick_sort<T>(k, begin, partition_iter - 1);

		if (std::distance(begin, partition_iter) < k)
			part_quick_sort<T>(k, partition_iter, end);
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
	std::vector<int> S1{ 45, 1, 56, 80, 32, 39, 2, 11, 23, 29, 6, 3, 67, 21, 78, 4, 99, 88, 34, 43, 91 };
	std::cout << "정렬되지 않은 벡터" << std::endl;
	print_vector<int>(S1);	// <int>는 명시적 Tamplate임
	part_quick_sort<int>(5,S1.begin(), --S1.end());
	std::cout << "정렬된 벡터" << std::endl;
	print_vector<int>(S1);
}
template <typename T>
auto generate_random_vector(T size)
{
	std::vector<T> V;
	V.reserve(size);

	std::random_device rd;
	std::mt19937 rand(rd());

	std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, size);

	for (T i = 0; i < size; i++)
		V.push_back(uniform_dist(rand));

	return std::move(V);
}
template <typename T>
void test_partial_quicksort(size_t size, size_t k)
{
	// 임의의 벡터를 생성하고, 복사본을 만들어 두 알고리즘에 각각 테스트 진행.
	auto random_vec = generate_random_vector<T>(size);
	auto random_vec_copy(random_vec);

	std::cout << "입력 벡터: " << std::endl;
	print_vector<T>(random_vec);

	// 부분 퀵 정렬 알고리즘 수행 시간 측정
	auto begin1 = std::chrono::steady_clock::now();
	part_quick_sort<T>(k, random_vec.begin(), random_vec.end() - 1);
	auto end1 = std::chrono::steady_clock::now();
	auto diff1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);

	std::cout << std::endl;
	std::cout << "부분 퀵 정렬 수행 시간: " << diff1.count() << "us" << std::endl;

	std::cout << "(처음 " << k << "개 원소만) 부분 정렬된 벡터: ";
	print_vector<T>(random_vec);

	// 전체 퀵 정렬 알고리즘 수행 시간 측정
	auto begin2 = std::chrono::steady_clock::now();
	quick_sort<T>(random_vec_copy.begin(), random_vec_copy.end() - 1);
	auto end2 = std::chrono::steady_clock::now();
	auto diff2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);

	std::cout << std::endl;
	std::cout << "전체 퀵 정렬 수행 시간: " << diff2.count() << "us" << std::endl;

	std::cout << "전체 정렬된 벡터: ";
	print_vector<T>(random_vec_copy);
}


int main()
{
	test_partial_quicksort<unsigned>(10000, 10);
	return 0;
}
