#include <bits/stdc++.h>
using namespace std;

int k, s, c;
vector<char> v;
vector<int> sa, sb;
vector<int> a, b;

int dfs(int i, int isa, int isb) {
    if (i == k + k) {
        if (isa == isb)
            return 1;
        else if (isa > isb)
            return 2;
        else
            return 4;
    }

    return dfs(i + 1, isa + !(i & 1), isb + (i & 1)) | dfs(i + 1, isa, isb);
}

int cnt(int i, int isa, int isb) {
    if (i == s) return (isa == sa[s] && isb == sb[s]);

    int x = dfs(i, isa, isb);
    if (x == 1 || x == 2 || x == 4) return 0;
    return cnt(i + 1, isa + !(i & 1), isb + (i & 1)) + cnt(i + 1, isa, isb);
}

void solve() {
    cin >> k;

    v.resize(k + k);
    a.resize(k + k + 1);
    b.resize(k + k + 1);
    sa.resize(k + k + 1);
    sb.resize(k + k + 1);

    for (int i = 0; i < k + k; ++i) {
        cin >> v[i];
        a[i + 1] = a[i] + !(i & 1);
        b[i + 1] = b[i] + (i & 1);
        sa[i + 1] = sa[i] + !(i & 1) * (v[i] == 'E');
        sb[i + 1] = sb[i] + (i & 1) * (v[i] == 'E');
    }

    for (int i = 0; i < k + k + 1; ++i) {
        int x = dfs(i, sa[i], sb[i]);

        if (x == 1 || x == 2 || x == 4) {
            s = i;
            break;
        }
    }

    for (int i = 0; i < s + 1; ++i) {
        int x = cnt(i, sa[i], sb[i]);

        if (x == 1) {
            c = i;
            break;
        }
    }

    cout << s << ' ' << c << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in.txt", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}