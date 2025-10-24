#include <iostream>
using namespace std;

int main() {
    int total = 0;
    int score;
    
    for (int i = 0; i < 5; i++) {
        cin >> score;
        total += score;
    }
    
    cout << total << endl;
    
    return 0;
}