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
#include <set>
using namespace std;

int main(){
    int nA, nB;
    cin >> nA >> nB;
    
    set<int> sA, sB;
    
    for(int i = 0; i < nA; i++){
        int v; cin >> v;
        sA.insert(v);
    }
    
    for(int i = 0; i < nB; i++){
        int v; cin >> v;
        sB.insert(v);
    }
    
    int intersection = 0;
    for(auto it : sA){
        if(sB.find(it) != sB.end()){
            intersection++;
        }
    }
    
    cout << sA.size() + sB.size() - 2 * intersection;
    return 0;
}