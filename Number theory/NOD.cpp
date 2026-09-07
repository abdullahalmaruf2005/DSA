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
            for(int j=i*i;j<=n;j+=2*i){
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
int nod(ll n){
    ll res=1;
    for(auto u:primes){
        if(1LL*u*u>n)break;
        int c=1;
        if(n%u==0){
            while (n%u==0)
            {
              n/=u;
              c++;
            }
        }
        res*=c;
    }
    if(n>1)res*=2;
    return res;
}

int main(){
sieve(100);
cout<<(nod(6))<<endl;

}