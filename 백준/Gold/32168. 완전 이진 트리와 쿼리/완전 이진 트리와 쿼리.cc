#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio 

ll N, Q;
ll sumAll;

ll rangeSum(ll L, ll R) {
    if (L > R) return 0;
    return (L + R) * (R - L + 1) / 2;
}

ll getSubtreeSum(ll v) {
    ll res = 0;
    ll left = v, right = v;
    while (left <= N) {
        ll r = min(right, N);
        res += rangeSum(left, r);
        left *= 2;
        right = (right * 2) + 1;
    }
    return res;
}

ll query(ll root, ll v) {
    if (root == v) return sumAll; 
    
    ll cur = root;
    while (cur > 0) {
        if (cur == v) break;
        cur = cur / 2;
    }
    
    if (cur != v) {
        return getSubtreeSum(v);
    } else {
        ll child = root;
        ll parent = child / 2;
        while (parent != v) {
            child = parent;
            parent = parent / 2;
        }
        return sumAll - getSubtreeSum(child);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    sumAll = (N * (N + 1)) / 2;

    ll root = 1;
    while (Q--) {
        int t;
        ll v;
        cin >> t >> v;
        if (t == 1) {
            root = v;
        } else {
            cout << query(root, v) << "\n";
        }
    }
    return 0;
}
