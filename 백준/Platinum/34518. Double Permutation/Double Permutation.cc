#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pp pair<int, int>
#define ttt tuple<int, int, int>
#define tttt tuple<int, int, int, int>

// ------- Variable -------
int N;
deque<int> row1, row2;
// -----------------------


void input(){
   cin >> N;
}

void solve(){

    if(N == 1){
        cout << 1 << '\n' << 1;
        return;
    }

    if(N%4 == 2 || N%4 == 3){
        cout << -1;
        return;
    }

    if(N % 4 == 2 || N % 4 == 3){
        cout << -1 << '\n';
        return;
    }
    
    row1.clear();
    row2.clear();
    
    if(N % 4 == 0){
        for(int i = 0; i < N / 4; i++){
            int base = 4 * i;
            row1.push_front(3 + base);
            row1.push_front(2 + base);
            row1.push_back(2 + base);
            row1.push_back(4 + base);
            
            row2.push_front(1 + base);
            row2.push_front(4 + base);
            row2.push_back(1 + base);
            row2.push_back(3 + base);
        }
    }
    else { 
        int k = N / 4;
        for(int i = 0; i < k; i++){
            int base = 4 * i + 1; 
            if(i == 0){
                row1.push_back(1);
            }
            row1.push_front(2 + 4 * i);
            row1.push_front(5 + 4 * i);
            row1.push_back(2 + 4 * i);
            row1.push_back(4 + 4 * i);


            if(i == 0){
                row2.push_back(1);
            }
            
            row2.push_front(4 + 4 * i);
            row2.push_front(3 + 4 * i);
            row2.push_back(3 + 4 * i);
            row2.push_back(5 + 4 * i);
        }
    }
    
    for(int i = 0; i < N; i++){
        cout << row1[i];
        if(i < N-1) cout << ' ';
    }
    cout << '\n';
    
    for(int i = 0; i < N; i++){
        cout << row2[i];
        if(i < N-1) cout << ' ';
    }
    cout << '\n';
}


int main(){
    fastio;
    input();
    solve();
    return 0;
}
