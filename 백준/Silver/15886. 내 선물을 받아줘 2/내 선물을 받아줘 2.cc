#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
#define ll long long
#define pp pair<int, int>

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;

    string s; cin >> s;

    int count = 0;
    for(int i = 0 ; i < N-1 ; i++){
        if(s[i] == 'E' && s[i+1] == 'W'){
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}   
