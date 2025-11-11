#include<iostream>
#include<vector>
using namespace std;
int map[102][102];
int main()
{
	int n;
	int x, y, w, h;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y >> w >> h;
		for (int a = x; a < x + w; a++)
		{
			for (int b = y; b < y + h; b++)
			{
				map[a][b] = i;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int a = 0; a < 101; a++)
		{
			for (int b = 0; b < 101; b++)
			{
				if (map[a][b] == i)
					sum++;
			}
		}
		cout << sum << endl;
	}
}