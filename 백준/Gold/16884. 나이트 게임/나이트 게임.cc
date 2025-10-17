#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n % 2) cout << "koosaga" << "\n";
		else cout << "cubelover" << "\n";
	}

	return 0;
}