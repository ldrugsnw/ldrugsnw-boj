#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int days; cin >> days;
    
    int math, kor; cin >> math >> kor;
    
    int mathCan, korCan; cin >> mathCan >> korCan;
    
    while(days > 0 && (math > 0 || kor > 0)){
        math -= mathCan;
        kor -= korCan;
        days--;
    }
    
    cout << days;
    
    return 0;
}
