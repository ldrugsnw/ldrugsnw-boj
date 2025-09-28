
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)

int arr[1000001];
int n;

int binary_search(vector<int>& lis, int start, int end, int element) {
    while (start < end) {
        int mid = (start + end) / 2;
        if (element > lis[mid]) start = mid + 1;
        else end = mid;
    }
    return end;
}
 
int LIS_BS(vector<int>& result) {
    vector<int> lis;          // LIS 후보 값 관리
    vector<int> pos(n);       // arr[i]가 LIS에서 몇 번째 위치에 들어가는지 기록

    lis.push_back(arr[0]);
    pos[0] = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > lis.back()) {
            lis.push_back(arr[i]);
            pos[i] = lis.size() - 1;
        } else {
            int idx = binary_search(lis, 0, lis.size(), arr[i]); // ⬅ 직접 구현한 이분탐색 사용
            lis[idx] = arr[i];
            pos[i] = idx;
        }
    }

    int len = lis.size();

    // 실제 LIS 복원
    result.resize(len);
    int idx = len - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (pos[i] == idx) {
            result[idx] = arr[i];
            idx--;
        }
    }

    return len;
}

int main() {
    fastio;
    
    cin >> n;
    for (int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int> vv;
    int len = LIS_BS(vv);
    
    cout << len << '\n';
    for (int a : vv) cout << a << " ";
    return 0;
}
