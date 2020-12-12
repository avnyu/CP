#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    int bst = -1;
    for (int i = 0; i < n; ++i)
        if (a[i] != i + 1) bst = i;
    
    long double nosort = 1.0;
    for(int i = 0;i < m;++i){
        int r;
        long double p;
        cin >> r >> p;
        if (r - 1 >= bst) nosort *= (-p + 1.0); 
    }
    
    cout << fixed << setprecision(9);
    cout << (bst == -1 ? 1.0 : -nosort + 1.0) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}
