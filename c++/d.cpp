#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N = 107, c, n;
string s;
vector<int> cut(N);

void in_ket_qua() {
    for (int i = 0; i < c - 1; ++i) {
        for (int j = cut[i]; j < cut[i + 1]; ++j) cout << s[j];
        cout << (i == c - 2 ? "\n" : ".");
    }
}

bool kiem_tra_so_ip(int trai, int phai) {
    if (trai + 1 == phai) return true;
    if (s[trai] == '0') return false;
    int so = 0;
    for (int i = trai; i < phai; ++i) so = 10 * so + s[i] - '0';
    return so >= 0 && so < 256;
}

void quaylui() {
    // cout << "quay lui " << cut[c - 1] << '\n';
    if (cut[c - 1] == n) {
        if (c == 5) in_ket_qua();
        return;
    }

    for (int i = cut[c - 1] + 1; i <= n; ++i) {
        if (kiem_tra_so_ip(cut[c - 1], i)) {
            cut[c] = i;
            c++;
            quaylui();
            c--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    n = s.size();

    c = 0;
    cut[c++] = 0;

    quaylui();

    return 0;
}