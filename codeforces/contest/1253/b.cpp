#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve() {
    int N = 1e6 + 7;
    vector<int> enter(N), in(N);
    int x, y, z, cnt;
    x = y = z = cnt = 0;
    queue<int> reset, res;

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    while (y < n) {
        while (z < n) {
            if (a[z] > 0) {
                if (in[a[z]] || enter[a[z]]) {
                    cout << "-1\n";
                    return;
                }
                cnt++;
                in[a[z]] = 1;
            } else {
                if (!in[-a[z]]) {
                    cout << "-1\n";
                    return;
                }
                cnt--;
                in[-a[z]] = 0;
                enter[-a[z]] = 1;
                reset.push(-a[z]);
            }

            z++;
            if (cnt == 0) break;
        }

        if(cnt != 0){
            cout << "-1\n";
            return;
        }

        while (!reset.empty()) {
            enter[reset.front()] = 0;
            reset.pop();
        }

        res.push(z - y);
        y = z;
    }

    cout << res.size() << '\n';
    while (!res.empty()) {
        cout << res.front() << ' ';
        res.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}