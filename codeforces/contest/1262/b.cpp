#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> max_q(n), res(n);
        set<int> rm;

        for (int i = 0; i < n; ++i) {
            cin >> max_q[i];
            rm.insert(i + 1);
        }

        res[0] = max_q[0];
        rm.erase(res[0]);
        //cout << "0 " << res[0] << ' ' << max_q[0] << '\n';

        char chk = 1;
        for (int i = 1; i < n; ++i) {
            if (max_q[i] == max_q[i - 1]) {
                res[i] = *rm.begin();
                rm.erase(rm.begin());
            } else {
                res[i] = max_q[i];
                rm.erase(res[i]);
            }

            //cout << i << ' ' << res[i] << ' ' << max_q[i] << '\n';
            if (res[i] > max_q[i]) chk = 0;
        }

        if (!chk) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; ++i) cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}