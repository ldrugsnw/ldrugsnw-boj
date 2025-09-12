#include <iostream>
using namespace std;

int main()
{
    int S = 0, T = 0, tmp = 0;
    
    for(int i = 0; i < 4; i++){
        cin >> tmp;
        S += tmp;
    }
    for(int i = 0; i < 4; i++){
        cin >> tmp;
        T += tmp;
    }
    
    if(S >= T)
        cout << S << '\n';
    else
        cout << T << '\n';
        
    return 0;
}