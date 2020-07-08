#include <bits/stdc++.h>
#define lli long long int
using namespace std;

long long H(long long previousHash, string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1e7, M = 1e9 + 7;

    vector<int> token(101, 0);

    for (int i = 0; i < 101; ++i) {
        lli X = (7LL * (31LL * i * t + 97)) % M;
        X = (i * t - X + M) % M;
        token[i] = X;
        if(X == 0 || X > int(1e9 - 1)){
            cout << i << ' ' << X << '\n';
        }
    }

    int v;
    cin >> v;
    cout << "a " << token[v / t] << '\n';
    cout << "a " << token[v / t] << '\n';

    return 0;
}
