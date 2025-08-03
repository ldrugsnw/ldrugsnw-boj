#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    vector<int> V;

    for(int i = 0 ; i < N ; i++){
        int num; cin >> num;

        V.push_back(num);
    }

    sort(V.begin(), V.end());

    auto it1 = V.begin();
    auto it2 = --V.end();

    int r1 = *it1;
    int r2 = *it2;

    int result = r1 + r2;

    //cout << "before roop : " << r1 << " , " << r2 << "\n";

    while(it2 > it1){
        int sum = *it1 + *it2;
        //cout << "it1 : " << *it1 <<  ", " << "it2 : " << *it2 << ", sum : " << sum << endl;

        if(abs(result) > abs(sum)){
                r1 = *it1;
                r2 = *it2;
                result = sum;
        }

        if(sum == 0){
            break;
        }

        if(sum > 0){
            it2--;
        }
        
        else if(sum < 0){
            it1++;
        }

    }

    //cout << "Result : " << r1 << " " << r2 << endl;
    cout << r1 << " " << r2;

    return 0;
   
}
