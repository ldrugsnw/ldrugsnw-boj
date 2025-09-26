#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int arr[1000001];
int n;

int binary_search(vector<int>& lis, int start, int end, int element) {
    // 그리고 꼭 & 붙여서 참조형으로 가져와야해
    //이분 탐색으로 lis 벡터 내에서 element의 위치를 반환
    //lis 벡터의 start - end 구간에서만 확인
    while (start < end) {
        int mid = (start + end) / 2;
        if (element > lis[mid]) start = mid + 1;
        else end = mid;
    }
    return end;
}
 
int LIS_BS() {
    int ret = 0;
    vector<int> lis;
    lis.push_back(arr[0]);
 
    for (int i = 1; i < n; i++) {
        //만약 lis 벡터의 마지막 수보다 i번째 수가 크다면, 그냥 뒤에 붙인다.
        if (arr[i] > lis.back()) {
            lis.push_back(arr[i]);
            ret = lis.size() - 1;
        }
        else{
            //i번째 수에 대해, lis 벡터 내에서 그 수의 위치를 찾는다.
            int pos = binary_search(lis, 0, ret, arr[i]);
            lis[pos] = arr[i];
        }
       
    }
 
    return ret + 1;
}

int main() {
    fastio;
    
    cin >> n;
    
    for (int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    
    cout << LIS_BS();
    
    return 0;
}
