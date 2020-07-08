#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define per(i,a,b) for(ll i=a;i>b;--i)
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,l;cin>>n>>l;
    int a[n];rep(i,0,n)cin>>a[i];
    sort(a,a+n);
    rep(i,0,n){
        int tmp=l/a[n-1-i];
        if(tmp*a[n-1-i]==l){
            cout<<tmp;
            break;
        }
    }
    return 0;
}
