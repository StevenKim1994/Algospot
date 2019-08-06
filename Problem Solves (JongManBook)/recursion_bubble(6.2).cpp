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
	
	if ((_x >= x) || (_y >= y) || (_y <0)||(_x<0)) // �Էµ� ��ǥ�� ������ ����� ������ false (�̴� ���ȣ���� ������)
	{
		return false;
	}

	if (matrix[_x][_y] != _input[0]) // ù ���ڰ� �ƴϸ� ������ �ƴϴ� false
	{
		return false;
	}

	if (_input.length() == 1) // ������ ù���ڰ� �ƴ��� Ȯ���߰� �Է� ������ ���̰� 1�̸� �ϳ��� ������ ������ true��
	{
		
		return true;
	}
	
	for (int i = 0; i < 8; i++)
	{
		int nextX = _x + tX[i];
		int nextY = _y + tY[i];
		
		if (search(nextX, nextY, _input.substr(1)))// ��� �Լ� ȣ��κ� _input.substr(1)�� �ǹ̴� ȣ��ɋ����� ���ڸ��� ������� �� ���� �ٽ� ����Լ� ���ڿ� �ִ´ٴ� �ǹ̴�.
		{
			temp.push_back(matrix[nextX][nextY]);
			return true;
		}
	}
	
		return false; // ������ �ɷ����� ������ matrix�� ���ϴ� ���ڵ��� ���� ���̴�.
	

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