#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t1, t2;
    cin >> t1 >> t2; 
    int ans1 = 1e9, ans2 = 1e9;
    for (int v1 = 0; v1 <= 1000; ++v1) {
        for (int v2 = 0; v2 <= 1000; ++v2) {
            if (v1 + v2 == 0) {
                continue;
            }
            int x = t1 * v1 + t2 * v2;
            if ((v1 + v2) * 80 == x) {
                if (ans1 + ans2 > v1 + v2) {
                    ans1 = v1;
                    ans2 = v2;
                }
            }
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}
