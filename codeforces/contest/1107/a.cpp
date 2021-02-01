#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n > 2) {
        cout << "YES\n2\n";
        cout << s[0] << ' ' << s.substr(1, -1 + s.size()) << endl;
    } else if (s[0] < s[1]) {
        cout << "YES\n2\n";
        cout << s[0] << ' ' << s.substr(1, -1 + s.size()) << endl;
    } else
        cout << "NO\n";
}
int main() {
    FIO;
    // srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
