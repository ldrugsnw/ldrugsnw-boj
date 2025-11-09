#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
using pp = pair<int,int>;

const ll INF = (ll)1e18;
#define MAX 1e9;
const int MOD = 1000000007;

bool isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
    fastio;

    int T; cin >> T;
    
    while(T--){
        string s;
        cin >> s;

        int n = (int)s.length();

        vector<int> vowelPos;

        for(int i = 0 ; i < n ; i++){
            if(isVowel(s[i])){
                vowelPos.push_back(i);
            }
        }

        if(vowelPos.empty()){
            cout << -1 << '\n';
            continue;
        }

        ll result = 1;

        for(int i = 0 ; i < vowelPos.size() - 1 ; i++){
            int count = vowelPos[i+1] - vowelPos[i];

            result = (result * (count)) % MOD;
        }

        cout << result << '\n';
    }

    return 0;
}