#include <iostream>
#include <algorithm>

using namespace std;

#include <vector>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int NUM = 5;
    
    vector<int> answer;
   
    for(int t = 0 ; t < NUM ; t++){
        string s;
        cin >> s;
        
        for(int i = 0 ; i < s.length() - 2 ; i++){
            if(s[i] == 'F' && s[i+1] == 'B' && s[i+2] =='I'){
                answer.push_back(t+1);
                break;
            }
        }
    }
    
    if(answer.size() == 0){
        cout << "HE GOT AWAY!";
    }else {
        for(int v : answer){
            cout << v << " ";
        }
    }
    
    return 0;
    
}
