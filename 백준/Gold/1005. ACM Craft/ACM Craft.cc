#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
#define ll long long

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;

    while(T--){
        int D[1001] = {0, };
        int indegree[1001] = {0, };
        vector<int> adj[1001];
        int dp[1001] = {0, };
        vector<int> result;

        int N, K; // N : 건물 개수, K : 규칙의 총 개수
        cin >> N >> K;        

        for(int i = 1 ; i <= N ; i++){
            int time; cin >> time;
            D[i] = time;
        }

        // 건설 순서
        int x, y;
        for(int i = 0 ; i < K ; i++){
            cin >> x >> y;
            adj[x].push_back(y);
            indegree[y]++;
        }

        // 최종적으로 지어야하는 건물
        int aim_build_num;
        cin >> aim_build_num;

        queue<int> q;

        for(int i = 1 ; i <= N; i++){
            if(indegree[i] == 0){
                q.push(i);
                dp[i] = D[i];
            }
        }

        while(!q.empty()){
            int cur = q.front(); q.pop();
            result.push_back(cur);
            for(int next : adj[cur]){
                dp[next] = max(D[next] + dp[cur], dp[next]);
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }

        /*cout << "위상 정렬 디버깅용\n";
        for(auto x : result){
            cout << x << " ";
        }*/

        //cout << "result: ";
        cout << dp[aim_build_num]<<"\n";
    }


    return 0;
}