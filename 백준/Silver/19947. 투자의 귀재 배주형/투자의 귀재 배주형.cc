#include <iostream>
using namespace std;

int dp[16];

int main() {
	int H, Y;
	cin >> H >> Y;
	dp[5] = H;
    
	for(int i=6;i<=15;i++){
		dp[i] = max(max(dp[i-1] * 1.05, dp[i-3] * 1.2), dp[i-5] * 1.35);
	}
	cout << dp[Y + 5];
	return 0;
}