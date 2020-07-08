#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);

    int n;
    cin >> n;

    int n_pos, n_neg;
    vector<int> pos, neg;
    vector<long long> sum_pos, sum_neg;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x > 0)
            pos.push_back(x);
        else
            neg.push_back(-x);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    n_pos = pos.size();
    n_neg = neg.size();

    sum_pos.resize(n_pos + 1);
    sum_neg.resize(n_neg + 1);

    for (int i = 0; i < n_pos; ++i) sum_pos[i + 1] = sum_pos[i] + pos[i];
    for (int i = 0; i < n_neg; ++i) sum_neg[i + 1] = sum_neg[i] + neg[i];

    long long res = sum_pos[n_pos] + sum_neg[n_neg];

    for (int i = 0; i < n_pos; ++i) {
        int m = (i + n_pos) >> 1;
        int n_lef = m - i;
        int n_rig = n_pos - m;
        long long res_lef = 1LL * pos[m] * n_lef - sum_pos[m] + sum_pos[i];
        long long res_rig = sum_pos[n_pos] - sum_pos[m] - 1LL * pos[m] * n_rig;
        res = min(res, res_lef + res_rig + sum_pos[i] + sum_neg[n_neg]);
    }

    for (int i = 0; i < n_neg; ++i) {
        int m = (i + n_neg) >> 1;
        int n_lef = m - i;
        int n_rig = n_neg - m;
        long long res_lef = 1LL * neg[m] * n_lef - sum_neg[m] + sum_neg[i];
        long long res_rig = sum_neg[n_neg] - sum_neg[m] - 1LL * neg[m] * n_rig;
        res = min(res, res_lef + res_rig + sum_neg[i] + sum_pos[n_pos]);
    }

    cout << res << '\n';

    return 0;
}