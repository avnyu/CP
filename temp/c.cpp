#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int st_n = 0;
int sav_n = 0;
int begin_n = 0;
vector<int> begin_pos(N);
vector<pair<int, int>> sav(N);
vector<int> st(N);

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int q;
    cin >> q;

    for (; q--;) {
        string s;
        int x;
        cin >> s;
        if (s == "push") {
            cin >> x;

            st[st_n++] = x;
            sav[sav_n++] = {0, 0};

        } else if (s == "top") {
            cin >> x;

            if (x >= st_n) cout << "0\n";
            else cout << st[st_n - 1 - x] << "\n";

        } else if (s == "pop") {
            cin >> x;

            while (st_n && x) {
                sav[sav_n++] = {1, st[st_n - 1]};

                st_n--;
                x--;
            }

        } else if (s == "begin"){

            begin_pos[begin_n++] = sav_n;
            sav[sav_n++] = {2, 0};

        } else if (s == "rollback") {
            if (begin_n == 0) {
                cout << "false\n";
                continue;
            }
            
            while (sav[sav_n - 1].first != 2) {
                int t = sav[sav_n - 1].first;
                int y = sav[sav_n - 1].second;
                sav_n--;

                if (t == 0) {
                    st_n--;
                } else {
                    st[st_n++] = y;
                }
            }
            
            begin_n--;
            sav_n--;
            cout << "true\n";
        } else if (s == "commit") {
            if (begin_n == 0) {
                cout << "false\n";
                continue;
            }
            
            for (int i = begin_pos[begin_n - 1]; i < sav_n - 1; ++i) sav[i] = sav[i + 1];
        
            begin_n--;
            sav_n--;
            cout << "true\n";
        }
    }

    return 0;
}