#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s1;
    cin >> s1;
    
    string s2;
    cin >> s2;
    
    for(int i = 1 ; i <= s1.length(); i++){
        for(int j = 1; j <= s2.length(); j++){
            
            if(s1[i-1] != s2[j-1]){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
            
            else{
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }
    
  /*  for(int i = 1 ; i <= s1.length() ; i++)
    {
        for(int j = 1 ; j <= s2.length() ; j++){
            cout << dp[i][j] << " ";
        }cout << endl;
    }*/
    
    cout << dp[s1.length()][s2.length()];

    return 0;
}
