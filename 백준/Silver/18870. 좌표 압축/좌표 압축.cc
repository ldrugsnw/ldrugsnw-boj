#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int chance = 0;
    cin >> chance;
    
    vector<int> v(chance);

    
    for(int i = 0 ; i < chance ; i++){
        cin >> v[i];
    }
    
    vector<int> cv(v);
    
    sort(cv.begin(), cv.end());
    
    cv.erase(unique(cv.begin(), cv.end()), cv.end());
    
    for(int i= 0;i < chance; i++){
        auto it = lower_bound(cv.begin(), cv.end(), v[i]);
        
        cout << it - cv.begin() << " ";
    }
    /*
    for(int i = 0;i < chance; i++){
        int count = 0;
        long save_int = 10000000001;
        for(int j = 0; j < chance; j++){
            if(v[i] > v[j] && v[j] != save_int){
                save_int = v[j];
                count++;
            }
        }
        v_count.push_back(count);
    }
     */
    return 0;
}
