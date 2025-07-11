#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 9

int arr[MAX];
int input_arr[MAX];
int new_arr[MAX];
int n, m, cnt;

void func(int k, int start) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < cnt; i++) {
        arr[k] = new_arr[i];
        func(k + 1, i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> input_arr[i];
    }

    sort(input_arr, input_arr + n);

    new_arr[0] = input_arr[0];
    cnt = 1;
    for (int i = 1; i < n; i++) {
        if (input_arr[i] != input_arr[i-1]) {
            new_arr[cnt++] = input_arr[i];
        }
    }

    func(0, 0);
    return 0;
}