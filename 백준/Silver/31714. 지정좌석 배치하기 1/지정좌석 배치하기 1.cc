#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
#define ll long long
#define pp pair<int, int>

int arr[1001][1001];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, D;
    cin >> N >> M >> D;
    // D <- 높이 차이

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            cin >> arr[i][j];
            arr[i][j] += i*D;
        }
    }

    for(int i = 1 ; i <= N ; i++){
        sort(arr[i] + 1, arr[i] + M +1);
    }

    for(int j = 1 ; j <= M ; j++){
        for(int i = 2 ; i <= N ; i++){
            if(arr[i][j] <= arr[i-1][j]){
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

    return 0;
}   
