#include <bits/stdc++.h>
#define lli long long int
using namespace std;

const int N = 1 << 20;
const int H = 21;
int it_max[N << 1], it_min[N << 1], lz[N];

void apply(int p, int v) {
    it_max[p] += v;
    it_min[p] += v;
    if (p < N) lz[p] += v;
}

void push(int p) {
    for (int s = H; s; --s) {
        int i = p >> s;
        if (lz[i] != 0) {
            apply(i << 1, lz[i]);
            apply(i << 1 | 1, lz[i]);
            lz[i] = 0;
        }
    }
}

void build(int p) {
    while (p > 1) {
        p >>= 1;
        it_max[p] = max(it_max[p << 1], it_max[p << 1 | 1]) + lz[p];
        it_min[p] = min(it_min[p << 1], it_min[p << 1 | 1]) + lz[p];
    }
}

void modify(int l, int r, int v) {
    l += N, r += N;

    for (int l0 = l, r0 = r; l0 < r0; l0 >>= 1, r0 >>= 1) {
        if (l0 & 1) apply(l0++, v);
        if (r0 & 1) apply(--r0, v);
    }

    build(l);
    build(r - 1);
}

pair<int, int> query(int l, int r) {
    l += N, r += N;
    pair<int, int> res = {0, 0};

    push(l);
    push(r - 1);
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            res.first = max(res.first, it_max[l]);
            res.second = min(res.second, it_min[l++]);
        }
        if (r & 1) {
            res.first = max(res.first, it_max[--r]);
            res.second = min(res.second, it_min[r]);
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p = 0;
    cin >> n;
    string a(N, '.');

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;

        if (c == 'L') {
            p = max(0, p - 1);
        } else if (c == 'R') {
            p++;
        } else if (c == '(') {
            if (a[p] == ')')
                modify(p, N, 2);
            else if (a[p] != '(')
                modify(p, N, 1);

            a[p] = c;
        } else if (c == ')') {
            if (a[p] == '(')
                modify(p, N, -2);
            else if (a[p] != ')')
                modify(p, N, -1);
            a[p] = c;
        } else {
            if (a[p] == '(')
                modify(p, N, -1);
            else if (a[p] == ')')
                modify(p, N, 1);

            a[p] = c;
        }

        pair<int, int> ls = query(N - 1, N);
        pair<int, int> seg = query(0, N);

        // cout << mx << ' ' << mn << ' ' << ls << ' '
        //      << (ls == 0 && mn == 0 ? mx : -1) << '\n';

        cout << (ls.first == 0 && seg.second == 0 ? seg.first : -1)
             << " \n"[i == n - 1];
    }

    return 0;
}