#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    int n; cin >> n;
    vector<int>a(n);
    vector<int>ans;
    for (auto&i : a)cin >> i;
    sort(a.begin(), a.end());
    if (n & 1) {
        int i = n / 2;
        int j = i;
        ans.push_back(a[i]);
        while (i) {
            --i, ++j;
            ans.push_back(a[i]);
            ans.push_back(a[j]);
        }
    }
    else {
        int i = (n - 1) / 2;
        int j = n / 2;
        ans.push_back(a[i]);
        ans.push_back(a[j]);
        while (i) {
            --i, ++j;
            ans.push_back(a[i]);
            ans.push_back(a[j]);
        }
    }
    for (auto&i : ans)cout << i << ' ';
    return 0;
}
