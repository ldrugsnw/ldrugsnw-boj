#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int H, W;
        cin >> H >> W;
        
        string grid[11];
        for (int i = 0; i < H; i++) {
            cin >> grid[i];
        }
        
        for (int i = 0; i < H; i++) {
            for (int j = W - 1; j >= 0; j--) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
    
    return 0;
}