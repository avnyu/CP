#include<bits/stdc++h.>
#define endl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << -1;
        return 0;
    }
    if (n == 2 && s[0] != s[1]) {
        cout << -1;
        return 0;
    }
    if (s[0] == s[n - 1])
        cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << endl;
    else {
        int i = 0, j = n - 1;
        while (s[i] == s[0])++i;
        while (s[j] == s[n - 1])--j;
        if (i < n - 1 - j)
            cout << i << ' ' << n - 1 << ' ' << i + 1 << ' ' << n << endl;
        else
            cout << 1 << ' ' << j << ' ' << 2 << ' ' << j + 1 << endl;
    }
    return 0;
}
