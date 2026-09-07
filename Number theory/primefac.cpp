#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mx=1e5+123;
vector<ll>primes;
bool isPrime[mx];

void sieve(ll n){
    for(int i=3;i<=n;i+=2)isPrime[i]=1;
    for(int i=3;i<=sqrt(n);i+=2){
        if(isPrime[i]==1){
        for(int j=i*i;j<=n;j+=2*i){
            isPrime[j]=0;
        }
    }
    }
    isPrime[2]=1;
    primes.push_back(2);
    for(int i=3;i<=n;i+=2){
        if(isPrime[i])primes.push_back(i);
    }
}

vector<ll>fact(ll n){
    vector<ll>f;

    for(auto u:primes){
        if(u*u>n)break;
        if(n%u==0){
            while (n%u==0)
            {
              f.push_back(u);
              n/=u;
            }
            
        }
    }
    if(n>1)f.push_back(n);
    return f;
}

int main(){
    sieve(1e5);
    // for(auto u:primes)cout<<u<<" ";
    // cout<<endl;
    vector<ll>ans=fact(50);
    for(auto u:ans)cout<<u<<" ";
}