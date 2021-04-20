// Example program
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for_each(a.begin(), a.end(), [](int &x) { cin >> x; });
    for_each(b.begin(), b.end(), [](int &x) { cin >> x; });

    vector<int> c(n + m);
    for (int i = 0, j = 0; i < a.size() | j < b.size();)
        if (j == b.size() || (i < a.size() && a[i] < b[j]))
            c[i + j] = a[i++];
        else
            c[i + j] = b[j++];

    for_each(c.begin(), c.end(),
             [&](int &x) { cout << x << " \n"[&x == &c.back()]; });

    return 0;
}
