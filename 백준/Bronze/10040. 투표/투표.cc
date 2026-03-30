#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> >games; // 비용, 추천받은 횟수

int main() 
{
	int n, m;
	int price;
	cin >> n >> m; //경기 수, 위원 수
	games.push_back(make_pair(0, 0)); // 0번 안씀

	for (int i = 0; i < n; i++)
	{
		cin >> price;
		games.push_back(make_pair(price, 0));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> price;
		for (int j = 1; j <= n; j++)
		{
			if (games[j].first <= price)// 경기가 감당가능한 비용이면
			{
				games[j].second++;
				break;
			}
		}
	}

	int answer=0;
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (max < games[i].second)
		{
			answer = i;
			max = games[i].second;
		}
	}

	cout << answer << endl;
	return 0;
}