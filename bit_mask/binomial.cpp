#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll gcd(ll x, ll y)
{
    while (y)
    {
        ll t = y;
        y = x % y;
        x = t;
    }
    return x;
}
long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
} 
void precompute_factorials(int max_n, vector<long long>& fact, vector<long long>& inv_fact) {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= max_n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[max_n] = power(fact[max_n], MOD - 2, MOD);
    for (int i = max_n - 1; i >= 1; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}
long long binomial_coefficient(int n, int r, const vector<long long>& fact, const vector<long long>& inv_fact) {
    if (r > n || r < 0) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}
int main() {
    ll t;
    cin >> t;
    int max_n = 200000;
    vector<long long> fact(max_n + 1);
    vector<long long> inv_fact(max_n + 1);
    precompute_factorials(max_n, fact, inv_fact);
    while (t--) {
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++)cin>>v[i];
        sort(v.begin(),v.end());
        if(k==1){
          ll s=0;
          for(int i=1;i<=n;i++){
            if(v[i]==1)s++;
          }
          cout<<s<<endl;
          continue;
        }
        ll z=(k+1)/2;
        ll sm=0;
        for(int i=z;i<=n-z+1;i++){
          ll cm=binomial_coefficient(i-1,z-1,fact,inv_fact);
          ll cm2=binomial_coefficient(n-i,z-1,fact,inv_fact);
          ll combinactories=(cm*cm2)%MOD;
          sm=(sm+v[i]*combinactories)%MOD;
        
        // cout<<nPr(i-1,z-1)<<" "<<nPr(n-i,z-1)<<endl;

      

        }
        cout<<sm<<endl;

    }
}
