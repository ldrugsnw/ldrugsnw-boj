#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	stack<pair<int, int>> s;
	int n; cin >> n;
	int nowTop = 0;
	for (int i = 0; i < n; i++) {
		cin >> nowTop;
		while (!s.empty()) {
			if (s.top().second > nowTop) {
				cout << s.top().first << "\n";
				break;
			}
			s.pop();
		}
		if (s.empty())cout << 0 << " ";
		s.push(make_pair(i + 1, nowTop));
	}
	return 0;
}