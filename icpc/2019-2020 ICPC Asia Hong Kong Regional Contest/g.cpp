#include <bits/stdc++.h>
using namespace std;

const int INF1 = 1e9;
const int INF2 = 1e7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> k;
    if (k == 1) {
        cout << "2\n1\n1 2\n";
        return 0;
    }
    int pos = -1;
    vector<int> best;
    for (int i = 0; i <= 100000; ++i) {
        int t = k - i;
        if (t <= 0) {
            break;
        }
        vector<int> tmp;
        int iter = 2;
        int sum = i;
        int st = int(sqrt(t)) + 1;
        while (iter <= st) {
            if (t % iter == 0) {
                while (t % iter == 0) {
                    t /= iter;
                    tmp.push_back(iter);
                    sum += iter;
                }
            }
            ++iter;
        }
        if (t != 1) {
            tmp.push_back(t);
            sum += t;
        }
        if (sum <= 100000) {
            pos = i;
            best = tmp;
            break;
        }
    }
    int n = 1 + pos + 1;
    int sum = 0;
    for (auto i : best) {
        n += i;
        sum += i;
    }
    vector<int> w(n + 1);
    vector<int> p(n + 1);
    w[1] = 1000000000;
    for (int i = 2; i <= pos + 1; ++i) {
        w[i] = best.size();
        p[i] = i - 1;
    }
    w[pos + 2] = 1000000000;
    p[pos + 2] = pos + 1;
    int cur = pos + 2;
    for (auto i : best) {
        ++cur;
        p[cur] = pos + 2;
        w[cur] = 1;
        for (int j = 1; j < i; ++j) {
            ++cur;
            w[cur] = 1;
            p[cur] = cur - 1;
        }
    }
    cout << n << "\n";
    for (int i = 2; i <= n; ++i) {
        cout << p[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << w[i] << " ";
    }
    cout << "\n";
    // cerr << fixed << setprecision(3) << double(clock()) * 1000 /
    // CLOCKS_PER_SEC << " ms\n";
    return 0;
}