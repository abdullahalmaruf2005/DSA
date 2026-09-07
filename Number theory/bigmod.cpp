#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl 
#define MOD 1000000007

ll bigmod(ll b,ll p,ll m){

    ll ans=1;
    while (p)
    {
       if(p%2==1){
        ans*=b;
        ans%=m;
       }
       p/=2;
       b*=b;
       b%=m;
    }
    return ans;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<bigmod(10,100000,MOD);
    
}