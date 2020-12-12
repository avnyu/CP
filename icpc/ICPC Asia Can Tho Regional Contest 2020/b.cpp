#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

deque<pair<int,int>>path;

pair<int,int> add(int xf, int lx, int ly, int rx, int ry) {
    int cx = lx, cy = ly;
    if (xf) {
        while (1) {
            if (cx == lx) for (; cx != rx; cx += rx > lx ? 1 : -1) path.push_back(make_pair(cx, cy));
            else for (; cx != lx; cx += lx > rx ? 1 : -1) path.push_back(make_pair(cx, cy));
            
            if (cy == ry) break;
            else {
                path.push_back(make_pair(cx, cy));
                cy += ry > ly ? 1 : -1;
            }
        }
    } else {
        while (1) {
            if (cy == ly) for (; cy != ry; cy += ry > ly ? 1 : -1) path.push_back(make_pair(cx, cy));
            else for (; cy != ly; cy += ly > ry ? 1 : -1) path.push_back(make_pair(cy, cy));
            
            if (cx == rx) break;
            else {
                path.push_back(make_pair(cx, cy));
                cx += rx > ly ? 1 : -1;
            }
        }
    }
    return make_pair(cx, cy);
}
void solve() {
    int n, r, c;
    cin > n >> r >> c;

    if (n % 2 && (r + c) % 2) {
        cout << "NO\n";
        return;
    }
    
    if (n % 2) {
        
    } else {
        int x = 1, y = 1;
        tie(x, y) = add(1, x, y, n, 1);
        
    }
    
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    for (; t--;) solve();

    return 0;
}
