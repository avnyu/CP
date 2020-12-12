#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 10;
    cin >> n;
    vector<int> a(n);
    for(auto&i:a)cin>>i;
    
    string s;
    cin >> s;
    
    if (s.size() == 1) {
        cout << a[0];
        for (int i = 1; i < n; ++i) cout << s << a[i];
        cout << '\n'; 
    } else if (s.size() == 3 || s == "+*" || s == "*+") {
        cout << a[0];
        for (int i = 1; i < n; ++i) cout << (a[i - 1] < 2 || a[i] < 2 ? "+" : "*") << a[i];
        cout << '\n';
    } else if (s == "+-" || s == "-+") {
        cout << a[0];
        for (int i = 1; i < n; ++i) cout << "+" << a[i];
        cout << '\n';
    } else {
        cout << a[0];
        for (int i = 1; i < n; ++i) cout << (a[i] == '0' ? "-" : "*" ) << a[i];
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    srand(time(NULL));

    int t = 1;
    // cin >> t;
    for (; t--;) solve();

    return 0;
}
