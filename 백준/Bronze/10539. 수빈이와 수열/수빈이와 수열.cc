#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    
    vector<ll> B(N+1);
    vector<ll> A(N+1);
    
    for(int i = 1; i <= N; i++){
        cin >> B[i];
    }
    
    A[1] = B[1];
    
    for(int i = 2; i <= N; i++){
        A[i] = B[i] * i - B[i-1] * (i-1);
    }
    
    for(int i = 1; i <= N; i++){
        cout << A[i];
        if(i < N) cout << " ";
    }
    cout << "\n";
    
    return 0;
}