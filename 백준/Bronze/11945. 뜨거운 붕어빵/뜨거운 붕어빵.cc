#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        
        reverse(line.begin(), line.end());
        
        cout << line << endl;
    }
    
    return 0;
}