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
        return a > b;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int> , cmp> pq;
    
    int N; cin >> N;
    
    while(N--){
        int n;
        cin >> n;
        
        pq.push(n);
    }
    
    int nnn = 0;
    
    while(!pq.empty() && pq.size() != 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        nnn += first + second;
        
        pq.push(first + second);
    }
   
    cout << nnn << "\n";
    
    return 0;
}
