/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1269                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ldrugsnw <boj.kr/u/ldrugsnw>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1269                           #+#        #+#      #+#    */
/*   Solved: 2025/07/28 09:34:35 by ldrugsnw      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
using namespace std;
#include <unordered_set>
#include <set>
#include <queue>
#include <cmath>

class cmp{
public:
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a>b;
        }
        return abs(a) > abs(b);
    }
};

int main(){
    priority_queue<int, vector<int> , cmp> pq;
    
    int N; cin >> N;
    
    while(N--){
        int n;
        cin >> n;
        
        if(n != 0){
            pq.push(n);
        }
        
        else{
            if(pq.empty()){
                cout << 0 << '\n';
                continue;
            }
            
            cout << pq.top() << '\n';
            pq.pop();
        }
    }
   
    
    return 0;
}
