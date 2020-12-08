#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
int k, R, r[1010];

ld get(ld x) {
    ld ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += x * r[i] / (x + r[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k >> R;
    for (int i = 0; i < k; ++i) {
        cin >> r[i];
    }
    long long lef = 0;
    long long rig = 1e18;
    ld ans = -1;
    while (lef <= rig) {
        long long mid = (lef + rig) >> 1;
        ld rmid = mid / 1e7;
        if (get(rmid) <= R) {
            ans = rmid;
            lef = mid + 1;
        } else {
            rig = mid - 1;
        }
    }
    cout << fixed << setprecision(10) << (ld)(ans) << "\n";
    return 0;
}
