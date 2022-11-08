/*
	�κ� �� ���� �˰����� ����
	==> ���� V�� �־����� ��, k���� ���ҷ� �̷���� ���ĵ� �κ� ���͸� ����.
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
		// ���ʺ��� �ǹ����� ū �� Ž��
		while (*left_iter <= pivot_val && std::distance(left_iter, right_iter) > 0)
		{
			left_iter++;
		}
			

		// �����ʺ��� �ǹ����� ���� �� Ž��
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
	std::cout << "���ĵ��� ���� ����" << std::endl;
	print_vector<int>(S1);	// <int>�� ����� Tamplate��
	part_quick_sort<int>(5,S1.begin(), --S1.end());
	std::cout << "���ĵ� ����" << std::endl;
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
	// ������ ���͸� �����ϰ�, ���纻�� ����� �� �˰��� ���� �׽�Ʈ ����.
	auto random_vec = generate_random_vector<T>(size);
	auto random_vec_copy(random_vec);

	std::cout << "�Է� ����: " << std::endl;
	print_vector<T>(random_vec);

	// �κ� �� ���� �˰��� ���� �ð� ����
	auto begin1 = std::chrono::steady_clock::now();
	part_quick_sort<T>(k, random_vec.begin(), random_vec.end() - 1);
	auto end1 = std::chrono::steady_clock::now();
	auto diff1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);

	std::cout << std::endl;
	std::cout << "�κ� �� ���� ���� �ð�: " << diff1.count() << "us" << std::endl;

	std::cout << "(ó�� " << k << "�� ���Ҹ�) �κ� ���ĵ� ����: ";
	print_vector<T>(random_vec);

	// ��ü �� ���� �˰��� ���� �ð� ����
	auto begin2 = std::chrono::steady_clock::now();
	quick_sort<T>(random_vec_copy.begin(), random_vec_copy.end() - 1);
	auto end2 = std::chrono::steady_clock::now();
	auto diff2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);

	std::cout << std::endl;
	std::cout << "��ü �� ���� ���� �ð�: " << diff2.count() << "us" << std::endl;

	std::cout << "��ü ���ĵ� ����: ";
	print_vector<T>(random_vec_copy);
}


int main()
{
	test_partial_quicksort<unsigned>(10000, 10);
	return 0;
}
