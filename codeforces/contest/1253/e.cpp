#include <bits/stdc++.h>
#define lli long long int
using namespace std;

const int N = 1 << 20;
const int H = 20;
vector<int> it_max(N << 1, 0), it_min(N << 1, N), lz(N);

void apply(int p, int v) {
    it_max[p] += v;
    it_min[p] += v;
    if (p < N) lz[p] += v;
}

void push(int p) {
    for (int s = H; s; --s) {
        int i = p >> s;
        if (lz[i]) {
            apply(i << 1, lz[i]);
            apply(i << 1 | 1, lz[i]);
            lz[i] = 0;
        }
    }
}

void build(int i) {
    while (i > 1) {
        i >>= 1;
        it_max[i] = max(it_max[i << 1], it_max[i << 1 | 1]) + lz[i];
        it_min[i] = min(it_min[i << 1], it_min[i << 1 | 1]) + lz[i];
    }
}

void modify(int l, int r, int v) {
    l += N, r += N;
    int l0 = l + N, r0 = r + N;

    push(l);
    push(r - 1);
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) apply(l--, v);
        if (r & 1) apply(--r, v);
    }
    build(l0);
    build(r0 - 1);
}

int query_max(int l, int r) {
    l += N, r += N;
    int l0 = l, r0 = r, res = 0;

    push(l);
    push(r - 1);
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, it_max[l++]);
        if (r & 1) res = max(res, it_max[--r]);
    }
    build(l0);
    build(r0 - 1);
}

int query_min(int l, int r) {
    l += N, r += N;
    int l0 = l, r0 = r, res = N;

    push(l);
    push(r - 1);
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, it_min[l++]);
        if (r & 1) res = min(res, it_min[--r]);
    }
    build(l0);
    build(r0 - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p = 0;
    cin >> n;
    string a = (N, '.');

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;

        if (c == 'L')
            p = max(0, p - 1);
        else if (c == 'R')
            p++;
        else if (c == '(') {
            if (a[p] == ')')
                modify(p, N - 1, 2);
            else if (a[p] != '(')
                modify(p, N - 1, 1);

            a[p] = c;
        } else if (c == ')') {
            if (a[p] == '(')
                modify(p, N - 1, -2);
            else if (a[p] != ')')
                modify(p, N - 1, -1);
            a[p] = c;
        } else {
            if (a[p] = '(')
                modify(p, N - 1, -1);
            else if (a[p] == ')')
                modify(p, N - 1, 1);

            a[p] = c;
        }

        int ls = query_max(N - 1, N - 1);
        int mx = query_max(0, N - 1);
        int mn = query_min(0, N - 1);

        cout << (ls == 0 && mn == 0 ? mx : -1) << " \n"[i == n - 1];
    }

    return 0;
}