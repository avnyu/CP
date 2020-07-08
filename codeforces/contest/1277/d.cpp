#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> cnt(4);

    vector<string> save(n);
    set<string> in;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        in.insert(s);
        save[i] = s;
        reverse(save[i].begin(), save[i].end());
        int index = (s[0] == '1') * 2 + (s.back() == '1');
        cnt[index].push_back(i);
    }

    //for (int i = 0; i < 4; ++i) cout << cnt[i].size() << " \n"[i == 3];
    int i0 = 0, i1 = 0, i2 = 0, i3 = 0;

    if (cnt[0].size() && cnt[3].size() && !cnt[1].size() && !cnt[2].size()) {
        cout << "-1\n";
        return;
    }

    if (!cnt[1].size() && !cnt[2].size()) {
        cout << "0\n";
        return;
    }

    vector<int> res;
    int m1 = cnt[1].size(), m2 = cnt[2].size();
    if (m1 > m2) {
        int dif = m1 - m2;
        while (dif > 1) {
            while (i1 < m1) {
                if (in.find(save[cnt[1][i1]]) != in.end())
                    i1++;
                else
                    break;
            }

            if (i1 == m1) break;
            res.push_back(cnt[1][i1++]);
            dif -= 2;
        }

        if (dif > 1) {
            cout << "-1\n";
            return;
        }
        cout << res.size() << '\n';
        for (int i = 0; i < res.size(); ++i) cout << res[i] + 1 << " \n"[i == res.size() - 1];
    } else {
        int dif = m2 - m1;
        while (dif > 1) {
            while (i2 < m2) {
                if (in.find(save[cnt[2][i2]]) != in.end())
                    i2++;
                else
                    break;
            }

            if (i2 == m2) break;
            res.push_back(cnt[2][i2++]);
            dif -= 2;
        }
        if (dif > 1) {
            cout << "-1\n";
            return;
        }
        cout << res.size() << '\n';
        for (int i = 0; i < res.size(); ++i) cout << res[i] + 1 << " \n"[i == res.size() - 1];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}