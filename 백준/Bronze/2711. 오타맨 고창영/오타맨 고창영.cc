#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int pos;
        string s;
        cin >> pos >> s;
        
        for (int i = 0; i < s.length(); i++) {
            if (i != pos - 1) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
    
    return 0;
}