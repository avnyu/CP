#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a - 1; i >= b; --i)
#define vi vector<int>
#define piii pair<int, pair<int, int> >
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define m(i, j) map<i, j>
#define F first
#define S second
using namespace std;

void print_wrong(int n) {
    if (n < 6)
        cout << "-1\n";
    else {
        cout << "1 2\n1 3\n1 4\n2 5\n2 6\n";
        rep(i, 7, n + 1) {
            if (i % 2 == 0)
                cout << "1 " << i << '\n';
            else
                cout << "2 " << i << '\n';
        }
    }
}
void print_right(int n) {
    rep(i, 2, n + 1) cout << "1 " << i << '\n';
}
int main() {
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    print_wrong(n);
    print_right(n);
    return 0;
}