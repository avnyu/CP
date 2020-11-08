#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));

    int n, N = 1e7;
    double pi = acos(-1);

    vector<float> s(N), lis(6e4, -100);
    vector<int> pos(N, -1), prv(N, -1);
    int l = 1;

    for (int i = 0; i < N; ++i) s[i] = sin(i * -10);

    for (int i = 1; i < N; ++i) {
        int p = upper_bound(lis.begin(), lis.begin() + l, s[i]) - lis.begin();

        l += (p == l);

        lis[p] = s[i];
        pos[p] = i;
        prv[i] = pos[p - 1];
    }
    
    cout << l << '\n';
    
    return 0;
}