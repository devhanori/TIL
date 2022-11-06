/*
	이진탐색 연습문제 _ 예방접종 _ p167
*/

#include <iostream>
#include <vector>	
#include <chrono>
#include <algorithm>
#include <random>
#include <string>

using namespace std;

class Student
{
private:
	pair<int, int> name;
	bool vaccinated;
public:
	Student(pair<int, int> _name, bool _vaccinated):
		name(_name),
		vaccinated(_vaccinated)
	{};	
	bool operator<(const Student& S)
	{
		if(this->name.first != S.name.first)
			return this->name.first < S.name.first;
		else
			return this->name.second < S.name.second;
	}
	bool Check();
	pair<int,int> getName();
};

bool Student::Check()
{
	return this->vaccinated;
}

pair<int,int> Student::getName()
{
	return this->name;
}

bool binary_saerch(pair<int,int> _name, vector<Student>& vec)
{
	auto first = vec.begin();
	auto last = vec.end();

	while (true)
	{
		// 중간위치 index, 값 저장
		auto range_length = distance(first, last);
		auto mid_element_index = floor(range_length / 2);
		auto mid_element = *(first + mid_element_index);

		if (mid_element.getName() == _name)
			return mid_element.Check(); // 학생이 List에 있다면 예방접종 유무 Check
		else if (mid_element.getName() > _name)
			advance(last, -mid_element_index);
		else if (mid_element.getName() < _name)
			advance(first, mid_element_index);

		if(range_length == 1)
			return true;	// 학생이 List에 없다면 예방접종 맞아야 함
	}
}

// Test 함수
void test_binary_search(int size, pair<int,int>& stu)
{
	vector<Student> S;
	random_device rd;	// 비결정적 난수 생성 객체
	mt19937 rand(rd());	// mt19937 난수 엔진 -> rd로 초기화

	random_device rd2;
	default_random_engine eng(rd2());
	uniform_real_distribution<float> distr(0, 1);

	// [1,size] 범위 안에서 정수 난수 발생
	uniform_int_distribution<mt19937::result_type> uiform_dist(1, size);	//이름
	
	// S에 난수 추가
	for (auto i = 0; i < size; i++)
	{
		Student temp(pair<int, int>(uiform_dist(rand), uiform_dist(rand)), distr(eng));
		S.push_back(temp);
	}

	sort(S.begin(), S.end());	// 오름차순 정렬

	// 검색시간 측정 시작
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();

	bool search_result = binary_saerch(stu, S);

	// 검색시간 측정 종료
	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout << "이진 검색 수행 시간: " << diff.count() << endl;

	if (search_result)
		cout << "(" << stu.first << " " << stu.second << ") 학생은 예방 접종이 필요합니다." << endl;
	else
		cout << "(" << stu.first << " " << stu.second << ") 학생은 예방 접종이 필요하지 않습니다." << endl;

}

int main(void)
{
	pair<int, int> test(839, 118);
	test_binary_search(1000, test);
	test_binary_search(10000, test);
	test_binary_search(100000, test);
	test_binary_search(1000000, test);

	/* Small Test
	Student a(pair<int, int>(839, 123), true);
	Student b(pair<int, int>(839, 119), false);
	Student c(pair<int, int>(839, 120), false);
	Student d(pair<int, int>(839, 121), false);
	Student e(pair<int, int>(839, 122), false);

	vector<Student> vec = { a,b,c,d,e };
	pair<int, int> test(839, 118);
	bool search_result = binary_saerch(test, vec);

	if (search_result)
		cout << "(" << test.first << " " << test.second << ") 학생은 예방 접종이 필요합니다." << endl;
	else
		cout << "(" << test.first << " " << test.second << ") 학생은 예방 접종이 필요하지 않습니다." << endl;
	*/

	return 0;
}
