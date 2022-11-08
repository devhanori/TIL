/*
	병합정렬 _ 시간복잡도
	최선: nlogn / 평균: nlogn / 최악: nlogn
*/

#include <iostream>
#include <string>	//test를 위해 include
#include <vector>

template <typename T>
std::vector<T> merge(std::vector<T>& arr1, std::vector<T>& arr2)
{
	std::vector<T> merged;

	auto iter1 = arr1.begin();
	auto iter2 = arr2.begin();

	while (iter1 != arr1.end() && iter2 != arr2.end())
	{
		if (*iter1 < *iter2)
		{
			merged.emplace_back(*iter1);
			iter1++;
		}
		else
		{
			merged.emplace_back(*iter2);
			iter2++;
		}
	}

	if (iter1 != arr1.end())
	{
		for (; iter1 != arr1.end(); iter1++)
			merged.emplace_back(*iter1);
	}
	else
	{
		for (; iter2 != arr2.end(); iter2++)
			merged.emplace_back(*iter2);
	}
	return merged;
}

template <typename T>
std::vector<T> merge_sort(std::vector<T>& arr)
{
	if (arr.size() > 1)
	{
		auto mid = size_t(arr.size()/2);
		auto temp1 = std::vector<T>(arr.begin(), arr.begin() + mid);
		auto left_half = merge_sort<T>(temp1);
		auto temp2 = std::vector<T>(arr.begin() + mid, arr.end());
		auto right_half = merge_sort<T>(temp2);
		return merge<T>(left_half, right_half);
	}

	return arr;
}

template <typename T>
void print_vector(std::vector<T>& arr)
{
	for (auto i : arr)
		std::cout << i << " ";

	std::cout << std::endl;
}

void run_merge_sort_test()
{
	std::vector<int> S1{ 45, 1, 2, 56, 32, 32, 11, 23, 29, 6, 2, 3 };
	std::cout << "정렬되지 않은 벡터" << std::endl;
	print_vector<int>(S1);	// <int>는 명시적 Tamplate임
	auto sorted_S1 = merge_sort<int>(S1);
	std::cout << "정렬된 벡터" << std::endl;
	print_vector<int>(sorted_S1);
	
	std::vector<std::string> S2{ "abc", "cba", "good", "hahaha", "aaaa", "nana" };
	std::cout << "정렬되지 않은 벡터" << std::endl;
	print_vector<std::string>(S2);
	auto sorted_S2 = merge_sort<std::string>(S2);
	std::cout << "정렬된 벡터" << std::endl;
	print_vector<std::string>(sorted_S2);

}

int main(void)
{
	run_merge_sort_test();
	return 0;
}