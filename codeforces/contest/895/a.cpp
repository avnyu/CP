#include <bits/stdc++.h>
using namespace std;
int n, a[400], min_dif, one, start, i_start;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    one = a[0];
    min_dif = 360;
    start = a[0];
    i_start = 0;
    for (int i = 1; i < n; i++) {
        // cout << one << "  1" << endl;
        while (one > 180) {
            one -= start;
            min_dif = min(min_dif, 2 * abs(one - 180));
            i_start++;
            start = a[i_start];
        }
        min_dif = min(min_dif, 2 * abs(one - 180));
        // cout << one << endl;
        one += a[i];
        min_dif = min(min_dif, 2 * abs(one - 180));
    }
    while (one > 180) {
        one -= start;
        i_start++;
        start = a[i_start];
    }
    min_dif = min(min_dif, 2 * abs(one - 180));
    cout << min_dif;
    return 0;
}
