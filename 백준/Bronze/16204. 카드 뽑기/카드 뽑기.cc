#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    int O_match = min(M, K);
    
    int X_match = min(N - M, N - K);
    
    int result = O_match + X_match;
    
    cout << result << endl;
    
    return 0;
}