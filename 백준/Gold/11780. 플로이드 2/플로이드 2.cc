#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

int cost_matrix[101][101];
int nxt[101][101];

const int INF = 0x3f3f3f3f;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n_city;
    cin >> n_city;

    int n_bus; 
    cin >> n_bus;

    for(int i = 1 ; i <= n_city; i++){
        fill(cost_matrix[i], cost_matrix[i] + n_city + 1 , INF);
    }

    for(int i = 0 ; i < n_bus; i++){
        int start, end, cost;

        cin >> start >> end >> cost;
        cost_matrix[start][end] = min(cost, cost_matrix[start][end]);
        nxt[start][end] = end;
    }

    for(int i = 1 ; i <= n_city ; i++)cost_matrix[i][i] = 0;


    for(int k = 1 ; k <= n_city ; k++){
        for(int s = 1 ; s <= n_city; s++){
            for(int t = 1 ; t <= n_city; t++){
                if(cost_matrix[s][t] > cost_matrix[s][k] + cost_matrix[k][t]){
                    cost_matrix[s][t] = cost_matrix[s][k] + cost_matrix[k][t];
                    nxt[s][t] = nxt[s][k];
                }
            }
        }
    }

    //cout << "===============\n";

    for(int i = 1 ; i <= n_city ; i++){
        for(int j = 1 ; j <= n_city ; j++){
            if(cost_matrix[i][j] == INF){
                cout << "0 ";
            }else{
                cout << cost_matrix[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    for(int i = 1 ; i <= n_city; i++){
        for(int j = 1 ; j <= n_city ; j++){
            if(cost_matrix[i][j] == 0 || cost_matrix[i][j] == INF){
                cout << "0\n";
                continue;
            }

            vector<int> path;
            int start = i;

            while(start != j){
                path.push_back(start);
                start = nxt[start][j];
            }

            path.push_back(j);
            cout << path.size() << " ";
            for(auto x : path) cout << x << " ";
            cout << '\n';
        }
    }


}
