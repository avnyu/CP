#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    clock_t s, e;
    s = clock();

    srand(time(NULL));
    vector<vector<int>> a(1e7, vector<int>(3));
    for (auto& i : a)
        for (auto& j : i) j = rand();

    e = clock();

    cout << (e - s) * 1000 << '\n';

    return 0;
}