/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7662                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ldrugsnw <boj.kr/u/ldrugsnw>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7662                           #+#        #+#      #+#    */
/*   Solved: 2025/07/28 09:05:05 by ldrugsnw      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
using namespace std;

#include <set>

int main(){
    int T;
    cin >> T;

    while(T--){
        int k; cin >> k;

        multiset<int> mts;

        while(k--){
            char cmd;
            cin >> cmd;


            if(cmd == 'D'){
                int aa; cin >> aa;

                if(mts.empty()){
                    continue;
                }

                if(aa == 1){
                    mts.erase(prev(mts.end()));
                }

                else if(aa == -1){
                    mts.erase(mts.begin());
                }
            }

            else if(cmd == 'I'){
                int n; cin >> n;
                mts.insert(n);
            }
        }

        if(mts.empty()){
            cout << "EMPTY\n";
        }
        
        else{
            cout << *prev(mts.end()) << " " << *mts.begin() << '\n';
        }
    }
}