#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int x = 0, repeat = 0, input = 0;
    cin >> repeat;

    for (int i = 0; i < repeat; i++){
        cin >> input;
        x ^= input;
    }

    if (x == 0) cout << "cubelover";
    else cout << "koosaga";
}