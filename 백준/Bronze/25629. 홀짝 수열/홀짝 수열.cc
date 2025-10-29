#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int odd = 0, even = 0;
	int N; cin >> N;
	while (N--) {
		int x; cin >> x;
		(x & 1) ? odd++ : even++;
	}
	if (odd == even || odd == even + 1) cout << 1;
	else cout << 0;
}