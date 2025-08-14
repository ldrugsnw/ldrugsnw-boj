#include <iostream>
#include <algorithm>
using namespace std;

int arr[100002];
int dp[100002];

int main(){
    int N;
    cin >> N;

    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }

    int result = arr[0];
    dp[0] = arr[0];

    for(int i = 1 ; i < N ; i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        result = max(result , dp[i]);
    }

    cout << result << '\n';

    return 0;
}