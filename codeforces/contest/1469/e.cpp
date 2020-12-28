/*
Suffix array O(n lg^2 n)
LCP table O(n)
*/
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

namespace SA {
const int MAXN = 1 << 21;
string S;
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

bool sufCmp(int i, int j) {
    if (pos[i] != pos[j]) return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA() {
    N = S.size();
    REP(i, N) sa[i] = i, pos[i] = S[i];
    for (gap = 1;; gap *= 2) {
        sort(sa, sa + N, sufCmp);
        REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
        REP(i, N) pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1) break;
    }
}

void buildLCP() {
    for (int i = 0, k = 0; i < N; ++i)
        if (pos[i] != N - 1) {
            for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];) ++k;
            lcp[pos[i]] = k;
            if (k) --k;
        }
}
}  // namespace SA

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;
    s += '!';

    SA::S = s;
    SA::buildSA();

    for (int i = 0; i < SA::N; ++i) cout << SA::sa[i] << " \n"[i == SA::N - 1];

    return 0;
}