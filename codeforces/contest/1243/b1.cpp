#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) {
                s[i] = t[i] = '.';
                continue;
            }

            bool chk = false;
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == s[i] && s[j] != t[j]) {
                    chk = true;
                    swap(t[i], s[j]);

                    s[i] = t[i] = '.';
                    break;
                }
            }

            break;
        }

        cout << (s == t ? "Yes\n" : "No\n");
    }

    return 0;
}