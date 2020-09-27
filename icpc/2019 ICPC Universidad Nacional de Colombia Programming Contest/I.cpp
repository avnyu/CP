#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    string s;
    cin >> s;

    if (s[0] < 48 || s[0] > 57) {cout << "-1\n"; return 0;}
    for(int i=0;i<s.size()&&s[i]>47&&s[i]<58;++i)cout<<s[i];
    cout<<'\n';

    return 0;
}