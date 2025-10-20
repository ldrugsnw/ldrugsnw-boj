#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
#define ll long long

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    int left = 0;
    int right = n - 1;
    int result = v[left] + v[right];
    
    while(left < right){
        int sum = v[left] + v[right];
        
        if(abs(sum) < abs(result)){
            result = sum;
        }
        
        if(sum < 0){
            left++;
        } else {
            right--;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}