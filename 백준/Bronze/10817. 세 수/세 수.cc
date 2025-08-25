#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> V;
    int n;
    for(int i = 0 ;i < 3 ; i++){
        cin >> n;
        V.push_back(n);
    }
    
    sort(V.begin(), V.end());

    cout << V[1];
    return 0;
}
