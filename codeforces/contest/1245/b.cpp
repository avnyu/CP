#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b, c;
        string s;
        cin >> n >> a >> b >> c >> s;
        vector<int> res(n, 0);

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R' && b) {
                b--;
                res[i] = 2;
            }
            if (s[i] == 'P' && c) {
                c--;
                res[i] = 3;
            }
            if (s[i] == 'S' && a) {
                a--;
                res[i] = 1;
            }
        }

        if (n - a - a - b - b - c - c >= 0) {
            cout << "YES\n";
            for (auto& i : res) {
                if (i == 0) {
                    if (a) {
                        cout << "R";
                        a--;
                    } else if (b) {
                        cout << "P";
                        b--;
                    } else {
                        cout << "S";
                        c--;
                    }
                } else if (i == 1)
                    cout << "R";
                else if (i == 2)
                    cout << "P";
                else
                    cout << "S";
            }
        } else {
            cout << "NO";
        }
        cout << '\n';
    }

    return 0;
}