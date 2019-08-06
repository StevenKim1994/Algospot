#include <array>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
int x, y;
array<char, 1000> matrix[1000];
/* 
x

 0:[-1, 1] 1:[-1, 0] 2:[-1, 1]
 3:[0, -1]   [point] 4:[0,  1]
 5:[1, -1] 6:[1,  0] 7:[1,  1]
			
								y
*/          

array<int, 8> tX = { -1,-1,-1,0,0,1,1,1 };
array<int, 8> tY = { 1,0,1,-1,1,-1,0,1 };
vector<char> temp;
bool search(int _x, int _y, string _input)
{
	
	if ((_x >= x) || (_y >= y) || (_y <0)||(_x<0)) // 입력된 좌표가 범위를 벗어나면 무조건 false (이는 재귀호출을 위함임)
	{
		return false;
	}

	if (matrix[_x][_y] != _input[0]) // 첫 문자가 아니면 무조건 아니니 false
	{
		return false;
	}

	if (_input.length() == 1) // 위에서 첫문자가 아닌지 확인했고 입력 문자의 길이가 1이면 하나만 맞으면 무조건 true임
	{
		
		return true;
	}
	
	for (int i = 0; i < 8; i++)
	{
		int nextX = _x + tX[i];
		int nextY = _y + tY[i];
		
		if (search(nextX, nextY, _input.substr(1)))// 재귀 함수 호출부분 _input.substr(1)의 의미는 호출될떄마다 앞자리가 사라지고 그 값을 다시 재귀함수 인자에 넣는다는 의미다.
		{
			temp.push_back(matrix[nextX][nextY]);
			return true;
		}
	}
	
		return false; // 위에서 걸러지지 않으면 matrix에 원하는 문자들이 없는 것이다.
	

}

int main()
{
	string input;


	vector<char> answer;

	cin >> x;
	cin >> y;
	bool check = false;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cin >> input;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (search(i, j, input))
			{
				
				check = true;
				break;
			}
		}
		if (check == true)
		{
			break;
		}
	}
	
	if (check == true)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}





	return 0;
}