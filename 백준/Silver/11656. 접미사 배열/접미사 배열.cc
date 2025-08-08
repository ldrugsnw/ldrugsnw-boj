#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<string> jubs;

    for(int i = 0 ; i < s.length(); i++){
        string aa = s.substr(i);
        jubs.push_back(aa);
    }

    sort(jubs.begin(), jubs.end());

    for(string P : jubs){
        cout << P << '\n';
    }

    return 0;
}
