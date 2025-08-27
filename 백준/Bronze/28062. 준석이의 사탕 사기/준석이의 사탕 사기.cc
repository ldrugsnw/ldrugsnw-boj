#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int a[N]; for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N);

    int result = 0, odd = 0;
    for (int i = N - 1; i >= 0; i--){ 
        if (a[i] & 1){ 
            if (odd) 
                result += odd + a[i], odd = 0;
            else odd = a[i];
        }
        else 
            result += a[i];
    }

    cout << result;
}