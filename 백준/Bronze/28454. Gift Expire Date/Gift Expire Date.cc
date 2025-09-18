#include <iostream>
using namespace std;

int main() {
    string current_date;
    int n;
    
    cin >> current_date;
    cin >> n;
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        string expire_date;
        cin >> expire_date;
        
        if (expire_date >= current_date) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}