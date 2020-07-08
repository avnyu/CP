#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define per(i,a,b) for(ll i=a;i>b;--i)
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,pos,l,r,rs=0;cin>>n>>pos>>l>>r;
    if(pos>r){
        rs=pos-r+1+(l!=1)*(r-l+1);
    }
    else if(pos<l){
        rs=l-pos+1+(r!=n)*(r-l+1);
    }
    else{
        if(l==1&&r==n){
            rs=0;
        }
        else if(r==n){
            rs=pos-l+1;
        }
        else if(l==1){
            rs=r-pos+1;
        }
        else{
            rs=r-l+2+min(pos-l,r-pos);
        }
    }
    cout<<rs;
    return 0;
}
