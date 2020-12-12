#include <bits/stdc++.h>

using namespace std;

typedef vector<long double> vd;
typedef vector<int> vi;

int n, k;
long double x, bst;
vd a;
vi p;

int response() {
    int t;
    cin >> t;
    return t;
    t = max_element(a.begin() + 1, a.begin() + 1 + n) - a.begin();
    return max(1, t - k + 1);
}
void pour1() {
    long double s = x;
    for (auto &i : p) s += a[i];
    s /= p.size();
    cout << "POUR " << p.size() << " ";
    for (auto &i: p) {
        cout << i << " " << s - a[i] << " \n"[&i == &p.back()];
        a[i] = s;
    }
    cout.flush();
    int t = response();
    for (int i = t; i < t + k; ++i) a[i] = 0;
}
void pour2() {
    int r = 0;
    for (int i = 0; i < (int)p.size(); ++i)
        if (a[p[i]] < 0.5) {
            r = i;
            break;
        }
    p.erase(p.begin() + r);

    if (p.size() > 1)
        cout << "POUR " << p.size() << " ";
    else
        cout << "FINAL " << p.size() << " ";
    
    for (auto &i: p) {
        cout << i << " " << x / p.size() << " \n"[&i == &p.back()];
        a[i] += x / p.size();
    }
    cout.flush();

    if (p.size() > 1) {
        int t = response();
        for (int i = t; i < t + k; ++i) a[i] = 0;
    } else {
        p.clear();
    }
}
int main() {
    cin >> n >> k >> x;

    if (n == k) {
        cout << "FINAL 1 1 " << x << endl;
        return 0;
    }

    cout << fixed << setprecision(32);

    bst = x;
    int t = (n - 1) / k + 1;
    for (int i = 1; i < t; ++i) bst += x / i;

    a.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        if (p.empty()) p.push_back(i);
        else if (i - p.back() >= k) p.push_back(i);

    int cnt = 0;

    for (int i = 2000 - t; i--;) {
        pour1();
        cnt++;
    }

    for (; p.size();) {
        pour2();
        cnt++;
    }

    return 0;
}
