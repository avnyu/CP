#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n = s.size(), i = 0;
        int cnt[128] = {};
        while(i < n)
        {
            int j = i;
            while(s[j] == s[i])j++;
            if((j - i) & 1)cnt[s[i]] |= 1;
            else cnt[s[i]] |= 2;
            i = j;
        }
        for(int i = 0; i < 128; ++i)
            if(cnt[i] & 1)cout << char(i);
        cout << '\n';
    }

    return 0;
}