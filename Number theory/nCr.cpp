#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl 
#define MOD 1000000007
#define M 1000000007
ll bigmod(ll b,ll p){
    ll ans=1;
    while (p)
    {
       if(p%2==1){
        ans*=b;
        ans%=M;
       }
       p/=2;
       b*=b;
       b%=M;
    }
    return ans;
}

const ll mx=2000000+1;
ll fac[mx];
ll invfac[mx];

void init(){
    fac[0]=1;
    invfac[0]=1;
    for(int i=1;i<=2e6;i++){
        fac[i]=(fac[i-1]*i)%M;
        invfac[i]=bigmod(fac[i],M-2)%M;
    }
}
ll nCr(ll x,ll y){
    ll ans1=(fac[x]*invfac[x-y])%M;
    ll ans=(ans1*invfac[y])%M;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
     init();
    
     int x;
     cin>>x;
    ll ans=0;
     for(int i=0;i<x;i++){
        ll a;
        cin>>a;
        ans+=(nCr(a+x-1,a-1));
     }
     cout<<ans<<endl;
   
}