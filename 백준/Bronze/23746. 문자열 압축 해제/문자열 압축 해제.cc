#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pp pair<int, int>
#define ttt tuple<int, int, int>
#define tttt tuple<int, int, int, int>

// ------- Variable -------
int N;
map<char, string> pattern;
string compressed;
ll S, E;
// -----------------------


void input(){
cin >> N;
    cin.ignore();
    
    for(int i = 0; i < N; i++){
        string line;
        getline(cin, line);
        
        char upper = line.back();
        string lower = line.substr(0, line.length() - 2);
        
        pattern[upper] = lower;
    }
    
    cin >> compressed;
    cin >> S >> E;
}

void solve(){
 string result = "";
    ll currentPos = 0;
    
    for(char c : compressed){
        string decompressed = pattern[c];
        ll patternLen = decompressed.length();
        
        ll startPos = currentPos + 1;
        ll endPos = currentPos + patternLen;
        
        if(endPos >= S && startPos <= E){
            ll extractStart = max(0LL, S - startPos);
            ll extractEnd = min(patternLen - 1, E - startPos);
            
            for(ll i = extractStart; i <= extractEnd; i++){
                result += decompressed[i];
            }
        }
        
        currentPos += patternLen;
        
        if(currentPos >= E){
            break;
        }
    }
    
    cout << result << '\n';

}


int main(){
    fastio;
    input();
    solve();
    return 0;
}
