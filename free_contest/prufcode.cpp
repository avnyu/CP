#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>pruf_code(n);
    vector<int>deg(n + 1 , 1);
    vector<pair<int, int>>ans;
    vector<vector<int>>graph(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> pruf_code[i];
        deg[--pruf_code[i]]++;
    }
    int ptr = 0, i = 0, leaf = 0;
    while (1) {
        if (deg[leaf] != 1) {
            while (deg[ptr] != 1)ptr++;
            leaf = ptr;
            if (leaf >= n)
                break;
        }
        cout << leaf << ' ' << pruf_code[i] << ' ' << i << endl;
        ans.push_back({leaf, pruf_code[i]});
        --deg[pruf_code[i]];
        --deg[leaf];
        if (deg[pruf_code[i]] == 1 && pruf_code[i] < leaf)
            leaf = pruf_code[i];
        i++;
    }
    for (auto&i : ans) {
        graph[i.first].push_back(i.second);
        graph[i.second].push_back(i.first);
    }
    for (int i = 0; i <= n; ++i) {
        cout << i + 1 << " :";
        for (auto&j : graph[i])cout << ' ' << j + 1;
        cout << endl;
    }
    return 0;
}
