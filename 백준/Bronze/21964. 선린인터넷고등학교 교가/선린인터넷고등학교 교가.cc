#include <iostream>
using namespace std;

int main(){

    int L; cin >> L;
    string s; cin >> s;
    for(int i = L-5 ; i < L ; i++){
        cout << s[i];
    }
    return 0;
}
