/*
	������ _ �ð����⵵
	�ּ�: nlogn / ���: nlogn / �־�: n^2
*/

#include <iostream>
#include <string>
#include <vector>

template <typename T>
auto partition(
	typename std::vector<T>::iterator begin,
	typename std::vector<T>::iterator end)
{
	// 3���� �ݺ��� ����
	// �ǹ�, ������ ����, ������ ����
	auto pivot_val = *begin;
	auto left_iter = begin + 1;
	auto right_iter = end;

	while (true)
	{
		// ������ ���Һ��� �����Ͽ� �ǹ����� ū ���� Ž��
		while (*left_iter <= pivot_val && std::distance(left_iter, right_iter) > 0)
			left_iter++;

		// �������� �ǹ����� ���� ���� Ž�� 
		while (*right_iter > pivot_val && std::distance(left_iter, right_iter) > 0)
			right_iter--;

		// left_iter�� right_iter�� ������ ��ȯ�� ���Ұ� ���� _ ����
		// �׷��� ������ left_iter�� right_iter�� ��ȯ
		if (left_iter == right_iter)
			break;
		else
			std::iter_swap(left_iter, right_iter);	// �ݺ��� ��ȯ _ ������ ��ġ�� �ٲ�
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
	// ���� ���Ϳ� �ϳ� �̻��� ���Ұ� �ִٸ�
	if (std::distance(begin, last) >= 1)
	{
		// �����۾� ����
		auto partition_iter = partition<T>(begin, last);

		// ���� �۾��� ���� ������ ���͸� ��������� ����
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
	std::cout << "���ĵ��� ���� ����" << std::endl;
	print_vector<int>(S1);	// <int>�� ����� Tamplate��
	quick_sort<int>(S1.begin(), --S1.end());
	std::cout << "���ĵ� ����" << std::endl;
	print_vector<int>(S1);

	std::vector<std::string> S2{ "abc", "cba", "good", "hahaha", "aaaa", "nana" };
	std::cout << "���ĵ��� ���� ����" << std::endl;
	print_vector<std::string>(S2);
	quick_sort<std::string>(S2.begin(), --S2.end());
	std::cout << "���ĵ� ����" << std::endl;
	print_vector<std::string>(S2);
}

int main()
{
	run_quick_sort_test();
	return 0;
}