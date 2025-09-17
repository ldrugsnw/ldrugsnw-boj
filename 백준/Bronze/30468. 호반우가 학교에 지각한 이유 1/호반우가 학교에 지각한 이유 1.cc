#include <iostream>
using namespace std;

int main(){
    int str, dex, INT, luk, N;
    cin >> str >> dex >> INT >> luk >> N;
    
    int avg = (str + dex + INT + luk);
    
    int result = 0;
    
    while(N*4 > avg){
        avg++;
        result++;
    }
    
    cout << result << endl;
}
