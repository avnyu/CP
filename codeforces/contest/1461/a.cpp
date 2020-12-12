#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s = "";
    for (int i = 0; i < n; ++i) s += char(97 + i % 3);
    cout << s << '\n';
}
int main() {
    ios:: sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    for (; t--;) solve();
    
    return 0;
}
