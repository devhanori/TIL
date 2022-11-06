//병합정렬연습

#include <iostream>
using namespace std;

void merge(int* arr, int first, int mid, int last)
{
	int* sorted = new int[last - first + 1];
	int i = first, j = mid+1, k = 0;
	while (i <= mid && j <= last)
	{
		if (arr[i] <= arr[j])
		{
			sorted[k++] = arr[i++];
		}
		else
		{
			sorted[k++] = arr[j++];
		}
	}

	if (i > mid)
		while (j <= last)	sorted[k++] = arr[j++];
	else
		while (i <= mid)	sorted[k++] = arr[i++];

	for (i = first, k = 0; i <= last; i++, k++)
		arr[i] = sorted[k];
}

void mergeSort(int* arr, int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergeSort(arr, first, mid);
		mergeSort(arr, mid+1, last);
		merge(arr, first, mid, last);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N; cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	mergeSort(arr, 0, N-1);

	for (int i = 0; i < N; i++)
		cout << arr[i] <<'\n';

	return 0;
}


