#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[50]; int b[50];

int main(){
    int N; cin >> N;
    
    for(int i = 0 ; i < N ; i++){
        cin >> a[i];
    }
    
    for(int i = 0 ; i < N ; i++){
        cin >> b[i];
    }
    
    sort(a, a + N);
    
    sort(b, b + N);
    
    int result = 0;
    
    for(int i = 0 ; i < N ; i++){
        result += a[i] * b[N-1-i];
    }
    
    cout << result << '\n';
    
    return 0;
}
