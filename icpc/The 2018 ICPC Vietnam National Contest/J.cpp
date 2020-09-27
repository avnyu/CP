#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    cout << ((s.size() + (s[0] == s[n - 1])) & 1 ? "Chikapu\n" : "Bash\n");
}

void play(string &s) {
    int cnt1 = 0, cnt2 = 0;

    if (s[0] != s[2]) {
        cnt1 = 1;
        if (s[0] != s[3]) cnt1 = 2;
    }

    if (s[1] != s[3]) {
        cnt2 = 1;
        if (s[0] != s[3]) cnt2 = 2;
    }

    if (cnt1 == 1 || cnt2 == 1) cout << "first " << s << '\n';
    // else
    //     cout << "second ";
}

void dfs(string &s) {
    if (s.size() == 4) {
        for (int i = 0; i < 3; ++i)
            if (s[i] == s[i + 1]) return;
        play(s);
        return;
    }
    s += 'a';
    dfs(s);
    s.pop_back();
    s += 'b';
    dfs(s);
    s.pop_back();
    s += 'c';
    dfs(s);
    s.pop_back();
    s += 'd';
    dfs(s);
    s.pop_back();
}

void test() {
    string s = "";
    dfs(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    // test();

    return 0;
}