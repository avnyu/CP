#include<bits/stdc++.h>
#define FIO ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define endl '\n'
#define ll long long
 
using namespace std;
 
struct point {
    int x, y;
    point(int _x, int _y) {
        this->x = _x;
        this->y = _y;
    }
    double len() {
        return sqrt((ll)x * x + (ll)y * y);
    }
    point operator+(point const& other)const {
        return point(x + other.x, y + other.y);
    }
    point operator-(point const& other)const {
        return point(x - other.x, y - other.y);
    }
    bool operator<(point const& other)const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};
 
ll p_scalar(point a, point b) {
    return (ll)a.x * b.y - (ll)a.y * b.x;
}
 
ll scalar(point a, point b) {
    return (ll)a.x * b.x + (ll)a.y * b.y;
}
 
double get_dist(point a, point b, point c) {
    if (scalar(a - b, a - c) < 0 || scalar(b - a, b - c) < 0) {
        return min((a - c).len(), (b - c).len());
    }
    return abs(p_scalar(c - a, a - b) / (a - b).len());
}
 
double calc_dist(vector<point>&p, vector<point>&ip) {
    int c1 = 0, c2 = 0;
    point cur = p[0] + ip[0];
    double ans = 1e100;
    while (c1 < p.size() || c2 < ip.size()) {
        point shift(0, 0);
        int nxt1 = (c1 + 1) < int(p.size()) ? c1 + 1 : 0;
        int nxt2 = (c2 + 1) < int(ip.size()) ? c2 + 1 : 0;
        if (c1 == p.size() || (c2 != ip.size() && p_scalar(p[nxt1] - p[c1], ip[nxt2] - ip[c2]) < 0)) {
            shift = ip[nxt2] - ip[c2];
            c2++;
        }
        else {
            shift = p[nxt1] - p[c1];
            c1++;
        }
        ans = min(ans, get_dist(cur, cur + shift, point(0, 0)));
        cur = cur + shift;
    }
    return ans;
}
 
int main() {
    FIO;
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    vector<vector<point>>poly(n);
    vector<vector<point>>ipoly(n);
    vector<vector<double>>graph(n, vector<double>(n, 1e9 + 7));
    for (int i  = 0; i < n; ++i) {
        int k, x, y;
        cin >> k;
        int mem1 = 0, mem2 = 0;
        for (int j = 0; j < k; ++j) {
            cin >> x >> y;
            poly[i].push_back(point(x, y));
            ipoly[i].push_back(point(-x, -y));
            if (poly[i][j] < poly[i][mem1])
                mem1 = j;
            if (ipoly[i][j] < ipoly[i][mem2])
                mem2 = j;
        }
        rotate(poly[i].begin(), poly[i].begin() + mem1, poly[i].end());
        rotate(ipoly[i].begin(), ipoly[i].begin() + mem2, ipoly[i].end());
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            graph[i][j] = graph[j][i] = calc_dist(poly[i], ipoly[j]);
 
    vector<bool>visited(n, false);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>hq;
    hq.push(make_pair(0, a));
    while (1) {
        pair<double, int>head = hq.top();
        hq.pop();
        double l;
        int x;
        tie(l, x) = head;
        if (visited[x])
            continue;
        visited[x] = true;
        if (x == b) {
            cout << fixed << setprecision(15) << l << endl;
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            hq.push(make_pair(graph[x][i] + l, i));
        }
    }
    return 0;
}
