#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    string tmp = "0246813579";
    int p = 0;
    for (int i = 0; i < n; ++i)if (s[i] == 'x') {
            p = i;
            break;
        }
    if (p == n - 1) {
        int sm = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (i & 1)sm += tmp[s[i] - 48] - 48;
            else sm += s[i] - 48;
        }
        sm *= 9;
        sm %= 10;
        cout << sm;
    }
    else {
        int sm = s[n - 1] - 48 + 1000000;
        for (int i = 0; i < n - 1; ++i) {
            if (i == p) continue;
            if (i & 1) sm -= 9 * (tmp[s[i] - 48] - 48);
            else sm -= 9 * (s[i] - 48);
        }
        sm %= 10;
        cout << (10 - sm) % 10;
    }
    return 0;
}
