#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dist[100002];
int subinwalk[100002];
int subin, sebin;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> subin >> sebin;

    fill(dist, dist + 100001, -1);

    dist[subin] = 0;
    subinwalk[subin] = subin;

    queue<int> Q;
    Q.push(subin);


    while (dist[sebin] == -1)
    {
        int cur = Q.front();
        Q.pop();

        for(int nv : {cur+1, cur-1, cur*2}){
            if(nv < 0 || nv > 100000){
                continue;
            }
            if(dist[nv] != -1){
                continue;
            }
            dist[nv] = dist[cur] + 1;
            subinwalk[nv] = cur;
            Q.push(nv);
        }
    }

    // fin

    cout << dist[sebin];
    cout << endl;

    deque<int> track = {sebin};
    while (track.front() != subin)
        track.push_front(subinwalk[track.front()]);
    for (int p : track) cout << p << ' ';
}
