#include<bits/stdc++.h>
#include<stdio.h>
#define FIO ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long

using namespace std;

int n, m, q, whitei, x, y, mid;
bool isB;
vector<int>a;
vector<int>lazy;
map<pair<int, int>, int>mps;
string ans = "";

void push(int id) {
    a[id + id] += lazy[id];
    a[id + id + 1] += lazy[id];
    lazy[id + id] += lazy[id];
    lazy[id + id + 1] += lazy[id];
    lazy[id] = 0;
}
void upd(int ql, int qr, int val, int id = 1, int l = 0, int r = n) {
    if (l > qr || ql > r)return;
    if (ql <= l && r <= qr) {
        a[id] += val;
        lazy[id] += val;
        return;
    }
    push(id);
    mid = (l + r) >> 1;
    upd(ql, qr, val, id + id, l, mid);
    upd(ql, qr, val, id + id + 1, mid + 1, r);
    a[id] = min(a[id + id], a[id + id + 1]);
}

int get(int ql, int qr, int id = 1,  int l = 0, int r = n) {
    if (l > qr || ql > r)return int(1e9);
    if (ql <= l && r <= qr)return a[id];
    push(id);
    mid = (l + r) >> 1;
    return a[id] = min(get(ql, qr, id + id,  l, mid), get(ql, qr, id + id + 1, mid + 1, r));
}

int main() {
    //FIO;
    scanf("%d%d%d", &n, &m, &q);
    a.resize(4 * n + 8, 0);
    lazy.resize(4 * n + 8, 0);
    for (int i = 0; i < n; ++i) {
        whitei = (m & 1) ? m / 2 + ((i & 1) == 0) : m / 2;
        upd(0, i, m - whitei);
        upd(i + 1, n, whitei);
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &x, &y);
        isB = (x + y + (++mps[ {x, y}])) & 1;
        if (isB) {
            upd(0, x - 1, 1);
            upd(x, n, -1);
        }
        else {
            upd(0, x - 1, -1);
            upd(x, n, 1);
        }
        ans += to_string(get(0, n)) + '\n';
    }
    mps.clear();
    a.clear();
    lazy.clear();
    printf("%s", ans.c_str());
    return 0;
}
