#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    long long C = 0;
    map<int, int> depth;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;

        if (i == 0){
            depth[num] = 1; 

            cout << C << "\n";
            continue;
        }

        auto iterator = depth.upper_bound(num);

        int height = 0;

        if (iterator != depth.end()){
            height = iterator->second;

        }
        if (iterator != depth.begin()){
            iterator--;

            height = max(height, iterator->second);
        }


        C += height;

        cout << C << "\n";

        depth[num] = height + 1;


    }
    return 0;
}
