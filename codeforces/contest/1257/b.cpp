#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x == 1)
            cout << (y == 1 ? "YES\n" : "NO\n");
        else if (x == 2)
            cout << (y < 4 ? "YES\n" : "NO\n");
        else if (x == 3)
            cout << (y < 4 ? "YES\n" : "NO\n");
        else
            cout << "YES\n";
    }
    return 0;
}