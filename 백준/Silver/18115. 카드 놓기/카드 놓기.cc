#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 0;
    cin >> T;

    vector<int> cmd(T);
    
    for(int i = 0 ; i < T; i++){
        cin >> cmd[i];
    }

    reverse(cmd.begin(), cmd.end());

    deque<int> dq;

    int num=1;

    for(int i : cmd){
        if(i == 1){
            dq.push_back(num);
        }

        else if(i == 2){
            int tmp = dq.back();
            dq.pop_back();
            dq.push_back(num);
            dq.push_back(tmp);
        }

        else {
            dq.push_front(num);
        }

        num++;
    }

    while(!dq.empty()){
        cout << dq.back() << " ";
        dq.pop_back();
    }

    return 0;
}