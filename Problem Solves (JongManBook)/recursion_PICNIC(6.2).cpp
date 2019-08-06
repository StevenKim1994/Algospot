#include <iostream>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;

vector<pair<int, int> > Friends; // 친구쌍...
vector<pair<int, bool> > Person; // first : 사람번호, second : true면 선택된지 확인...
int main()
{
	int C;
	int N;
	int M;

	cin >> C;
	for (int testcase = 0; testcase < C; testcase++)
	{
		if(Friends.size() != 0)
			Friends.clear();

		if (Person.size() != 0)
			Person.clear();

		cin >> N;
		cin >> M;

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				pair<int, bool> person_temp; // 0부터 N-1 까지 만큼 사람 리스트에 넣음 초기는 선택안됬으니 bool값은 false임.
				person_temp.first = j;
				person_temp.second = false;
				Person.push_back(person_temp);

				pair<int, int> person_set; // 친구쌍 입력
				cin >> person_set.first;
				cin >> person_set.second;
				
				Friends.push_back(person_set);

			}

			if (Friends.size() == 1 && N == 2) // 학생이 2명이고 친구쌍이 1쌍이면 무조건 경우의 수는 1
			{
				cout << "1" << endl;
			}
			else // 완탐ㄱㄱ 19.08.06 ...
			{
				for (int j = 0; j < N; j++)
				{
					
				}
			}
		}

	}
	return 0;
}