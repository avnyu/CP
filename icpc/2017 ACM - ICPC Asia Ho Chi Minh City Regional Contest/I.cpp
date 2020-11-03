#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("in", "r", stdin);

    int n;
    cin >> n;
    set<string>s;
    
    int c = 0;
    for(int i=0;i<n;++i){
        string u, x;
        cin >> u >> x;

        if(s.find(u) == s.end() && c < 12){
            cout << u << ' ' << x << '\n';
            c++;
            s.insert(u);
        }
    }

    return 0;
}