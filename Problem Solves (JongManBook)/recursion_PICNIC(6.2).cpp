#include <iostream>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;

vector<pair<int, int> > Friends; // ģ����...
vector<pair<int, bool> > Person; // first : �����ȣ, second : true�� ���õ��� Ȯ��...
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
				pair<int, bool> person_temp; // 0���� N-1 ���� ��ŭ ��� ����Ʈ�� ���� �ʱ�� ���þȉ����� bool���� false��.
				person_temp.first = j;
				person_temp.second = false;
				Person.push_back(person_temp);

				pair<int, int> person_set; // ģ���� �Է�
				cin >> person_set.first;
				cin >> person_set.second;
				
				Friends.push_back(person_set);

			}

			if (Friends.size() == 1 && N == 2) // �л��� 2���̰� ģ������ 1���̸� ������ ����� ���� 1
			{
				cout << "1" << endl;
			}
			else // ��Ž���� 19.08.06 ...
			{
				for (int j = 0; j < N; j++)
				{
					
				}
			}
		}

	}
	return 0;
}