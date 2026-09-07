#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl 
#define MOD 1000000007
// 1. Harmonic Series
// 2. Calculate the Number of divisors
// 3. Calculate the Sum of divisors
// 4. Get all the number of divisors
// complexity O(nln(n))
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            a[j]++;
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}