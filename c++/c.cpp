#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N = 107, c, n;
string s;
vector<int> cut(N);

void in_ket_qua() {
    for (int i = 0; i < c - 1; ++i) {
        for (int j = cut[i]; j < cut[i + 1]; ++j) cout << s[j];
        cout << (i == c - 2 ? "\n" : " ");
    }
}

bool kiem_tra_panlindrome(int trai, int phai) {
    while (trai < phai) {
        if (s[trai] != s[phai]) return false;
        trai++;
        phai--;
    }
    return true;
}

void quaylui() {
    // cout << "quay lui " << cut[c - 1] << '\n';
    if (cut[c - 1] == n) {
        in_ket_qua();
        return;
    }

    for (int i = n; i > cut[c - 1]; --i) {
        if (kiem_tra_panlindrome(cut[c - 1], i - 1)) {
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