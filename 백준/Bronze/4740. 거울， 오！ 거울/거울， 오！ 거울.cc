#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    
    while(s != "***"){
        reverse(s.begin(), s.end());
        cout << s << '\n';
        getline(cin, s);
    }
    
    return 0;
}
