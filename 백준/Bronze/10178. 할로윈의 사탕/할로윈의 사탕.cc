#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
#define ll long long
#define pp pair<int, int>

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;

    while(T--){
        int c, v;
        cin >> c >> v;

        cout << "You get " << c/v << " piece(s) and your dad gets " << c%v << " piece(s).\n";
    }

    return 0;
}   
