#include <iostream>
#include <algorithm>

using namespace std;

#include <vector>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;
    
    for(int i = s.length() - 1 ; i >= 0 ; i--){
        cout << s[i];
    }
    
    return 0;
    
}
