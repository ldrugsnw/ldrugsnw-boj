#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9

int N;
int arr[1001][3];
int dp[1001][3];
int ans = MAX;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a,b;
    cin >> a >> b;

    if(a>b){
        cout << "flight\n";
    } else {
        cout << "high speed rail\n";
    }

    return 0;
}