#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl 
#define MOD 1000000007
const ll mx=1e6+123;
vector<ll>primes;
bool isPrime[mx];
void sieve(ll n){
    for(int i=3;i<=n;i+=2)isPrime[i]=1;

    for(int i=3;i<=sqrt(n);i+=2){
        if(isPrime[i]){
        for(int j=i*i;j<=n;j+=i*2){
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

int main(){
    sieve(1e5);
ll n;
cin>>n;


}