#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

string encode(int d, int h, int m) {
    vi a;
    for (int i = 5; i--;) a.push_back(d & (1 << i) ? 1 : 0);
    for (int i = 5; i--;) a.push_back(h & (1 << i) ? 1 : 0);
    for (int i = 6; i--;) a.push_back(m & (1 << i) ? 1 : 0);
    
    vvi x = {
        {1, 1, 0, 0, 0}, {1, 0, 1, 0, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 1}, {0, 0, 0, 1, 1}, {1, 1, 1, 0, 0}, {1, 1, 0, 1, 0},
        {1, 1, 0, 0, 1}, {1, 0, 1, 1, 0}, {1, 0, 1, 0, 1}, {1, 0, 0, 1, 1}};

    vi b(5, 0);
    for (int i = 0; i < 16; ++i) for (int j = 0; j < 5; ++j) if (x[i][j]) b[j] ^= a[i];

    string s = "";
    for (int i = 0; i < 16; ++i) s += '0' + a[i];
    for (int i = 0; i < 5; ++i) s += '0' + b[i]; 

    return s;
}
tuple<int, int, int>decode(string enc) {
    string s = enc;
    
    
    vvi x = {
        {1, 1, 0, 0, 0}, {1, 0, 1, 0, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 1}, {0, 0, 0, 1, 1}, {1, 1, 1, 0, 0}, {1, 1, 0, 1, 0},
        {1, 1, 0, 0, 1}, {1, 0, 1, 1, 0}, {1, 0, 1, 0, 1}, {1, 0, 0, 1, 1}};
        
    
    vi b(21, 0);
    for (int i = 0; i < 21; ++i) b[i] = s[i] - '0';
    for (int i = 0; i < 16; ++i) for (int j = 0; j < 5; ++j) if (x[i][j]) b[16 + j] ^= b[i];
    
    for (int i = 0; i < 16; ++i) {
        bool oke = true;
        for (int j = 0; j < 5; ++j) if (x[i][j] != b[16 + j]) oke = false;
        if (oke) {
            b[i] ^= 1;
            break;
        }
    }
    
    int d = 0, h = 0, m = 0;
    
    for (int i = 0 ; i < 5; ++i) if (b[4 - i]) d += 1 << i;
    for (int i = 0 ; i < 5; ++i) if (b[9 - i]) h += 1 << i;
    for (int i = 0 ; i < 5; ++i) if (b[15 - i]) m += 1 << i;
    
    return make_tuple(d, h, m);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    srand(time(NULL));

    int d = rand() % 31 + 1, h = rand() % 24, m = rand() % 60;

    cout << "org\n";
    cout << setw(2) << d << " " << setw(2) << h << " " << setw(2) << m << '\n';
    
    cout << "test\n";
    string s = encode(d, h, m);
    
    for (int i = 0; i < 21; ++i) {
        s[i] = s[i] == '1' ? '0' : '1';
        auto [dx, hx, my] = decode(s);
        cout << setw(2) << dx << " " << setw(2) << hx << " " << setw(2) << my << '\n';
        s[i] = s[i] == '1' ? '0' : '1';
    }
    
    auto [dx, hx, my] = decode(s);
    cout << setw(2) << dx << " " << setw(2) << hx << " " << setw(2) << my << '\n';

    return 0;
}
