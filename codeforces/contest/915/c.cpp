#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define per(i,a,b) for(ll i=a;i>b;--i)
using namespace std;

bool cmp(char ar,char br){return (ar>br);}
bool check(int tmp[],int num_of_b[],int pos,string b){
    int num_of_a[10];
    rep(i,0,10)num_of_a[i]=tmp[i];
    num_of_a[b[pos]-48]--;
    //rep(i,0,10)cout<<num_of_a[i]<<endl;
    rep(i,pos+1,b.length()){
        rep(j,0,b[i]-48)if(num_of_a[j]>0)return true;
        if(num_of_a[b[i]-48]==0)return false;
        num_of_a[b[i]-48]--;
    }
    return true;
}
void solve(string c,string d){
    string a=c,b=d;
    int num_of_a[10]={0};
    int num_of_b[10]={0};
    rep(i,0,a.length()){
        num_of_a[a[i]-48]++;
    }
    rep(i,0,b.length()){
        num_of_b[b[i]-48]++;
    }
    if(b.length()>a.length()){
        sort(a.begin(),a.end(),cmp);
        cout<<a;
        return;
    }
    else{
        int used=0,pos=0,len=b.length();
        string rs;
        while(pos<len){
            if(num_of_a[b[pos]-48]>0){
                if(!check(num_of_a,num_of_b,pos,b)){break;}
                num_of_a[b[pos]-48]--;
                num_of_b[b[pos]-48]--;
                rs+=b[pos];
                pos++;
            }
            else break;
        }
        //cout<<rs<<" after1"<<endl;
        if(pos<len){
            int i=b[pos]-48-1;
            while(num_of_a[i]==0)i--;
            rs+=(char)(i+48);
            num_of_a[i]--;
            num_of_b[i]--;
            pos++;
        }
        //cout<<rs<<" after2"<<endl;
        if(pos<len){
            per(i,9,-1){
                rep(j,0,num_of_a[i]){
                    rs+=(char)(i+48);
                }
            }
        }
        cout<<rs<<endl;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //string a,b;cin>>a>>b;
    srand(time(NULL));
    string a,b;cin>>a>>b;
    solve(a,b);
    return 0;
}
