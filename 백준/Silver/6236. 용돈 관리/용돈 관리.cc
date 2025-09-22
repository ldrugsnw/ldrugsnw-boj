#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int N, M;

bool check(vector<int>& spends, int M, int K){ // K씩 withdraw
    int count = 1;
    int now_spend = K; // 잔액
    
    for(int spend : spends){
        
        if(now_spend - spend >= 0){
            now_spend -= spend;
        }
        
        // 돈을 쓰는 경우
        
        else if(K < spend){
            return false;
        }
        
        else{
            
            
            if(count >= M){
                return false;
            }
            
            now_spend = K; // 인출하기
            count++;
            now_spend -= spend;
        }
    }
    
    return true;
}

int main(){
    fastio;
    
    cin >> N >> M;
    
    vector<int> spend;
    
    int tmp;
    for(int i = 0 ; i < N ; i++){
        cin >> tmp;
        spend.push_back(tmp);
    }
    
    int left = *max_element(spend.begin(), spend.end());
    int right = 0;
    for(int s : spend) {
        right += s;
    }
    
    int answer = 0;
    
    while(left <= right){
        int mid = (left + right) / 2;
        
        if(check(spend, M, mid)){
            answer = mid;
            right = mid - 1;
        }
        
        else{
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
