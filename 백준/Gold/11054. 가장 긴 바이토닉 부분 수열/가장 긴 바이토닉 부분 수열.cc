#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0);

int n;
int arr[1001];
int lis_dp[1001]; 
int lds_dp[1001];

void solve() {
    for (int i = 0; i < n; i++) {
        lis_dp[i] = 1; 
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                lis_dp[i] = max(lis_dp[i], lis_dp[j] + 1);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        lds_dp[i] = 1; 
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[i]) {
                lds_dp[i] = max(lds_dp[i], lds_dp[j] + 1);
            }
        }
    }

    int max_len = 0;
    for (int i = 0; i < n; i++) {
        max_len = max(max_len, lis_dp[i] + lds_dp[i] - 1);
    }

    cout << max_len << endl;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    fastio;
    input();
    solve();
    return 0;
}