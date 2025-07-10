/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13414                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ldrugsnw <boj.kr/u/ldrugsnw>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13414                          #+#        #+#      #+#    */
/*   Solved: 2025/07/10 14:50:04 by ldrugsnw      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <algorithm>

bool compare(pair<string, int> a, pair<string, int> b){
    return a.second < b.second;
}

int n, m;

unordered_map<string, int>map;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0 ; i < m; i++){
        string stuNum;
        cin >> stuNum;
        map[stuNum] = i;
    }

    vector<pair<string, int>> V;

    for(auto a : map){
        V.push_back(a);
    }

    sort(V.begin(), V.end(), compare);

    //min(n, (int)V.size())

    for(int i = 0 ; i < min(n, (int)V.size()) ; i++){
        cout << V[i].first << '\n';
    }

    return 0;
}