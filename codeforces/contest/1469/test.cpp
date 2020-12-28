#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    srand(time(NULL));

    cout << "1\n";
    cout << "1000000 500000\n";
    for (int i = 0; i < 1000000; ++i) cout << char(48 + rand() % 2);
    cout << '\n';

    return 0;
}