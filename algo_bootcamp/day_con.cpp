#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    srand(time(NULL));
    vector<int> a(10, rand() % 10);

    for (auto& i : a) cout << rand() % 10 + 1 << ' ';

    return 0;
}