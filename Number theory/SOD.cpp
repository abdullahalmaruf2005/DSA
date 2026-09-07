#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl 
const ll mx=1e5;
vector<ll>primes;
bool isprime[mx];
void sieve(ll n){
    for(int i=3;i<=n;i+=2){
        isprime[i]=1;
    }
    for(int i=3;i<=sqrt(n);i+=2){
        if(isprime[i]){
            for(int j=i*i;j<=n;j+=i*2){
                isprime[j]=0;
            }
        }
    }
    isprime[2]=1;
    primes.push_back(2);
    for(int i=3;i<=n;i+=2){
        if(isprime[i])primes.push_back(i);
    }
}
ll SOD(ll n){
ll result=1;
for(auto u:primes){
    if(1LL*u*u>n)break;
    if(n%u==0){
        ll fm=1,bal=1;
        while (n%u==0)
        {  fm*=u;
           n/=u;
           bal+=fm;
        }
        result*=bal;
    }
}
if(n>1){
    result*=(n+1);
}
return result;
}


int main(){
sieve(1e5);
cout<<SOD(12)<<endl;
}