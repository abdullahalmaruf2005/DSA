#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl 
#define MOD 1000000007
const int INF = 1e9;
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
ll dx[]={1,0,-1,0};
ll dy[]={0,-1,0,1};



void solve(){
string s,p;
cin>>s>>p;
ll n=s.size();
ll m=p.size();
vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
vector<vector<ll>>cnt(n+1,vector<ll>(m+1,0));
for(int i=0;i<=n;i++){
    dp[i][0]=0;
    cnt[i][0]=1;
}
for(int i=0;i<=m;i++){
    dp[0][i]=0;
    cnt[0][i]=1;
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(s[i-1]==p[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
            cnt[i][j]=cnt[i-1][j-1];
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                 dp[i][j]=dp[i-1][j];
                 cnt[i][j]=cnt[i-1][j];
            }else if(dp[i-1][j]<dp[i][j-1]){
                 dp[i][j]=dp[i][j-1];
                 cnt[i][j]=cnt[i][j-1];
            }else{
                 dp[i][j]=dp[i][j-1];
                  cnt[i][j]=cnt[i][j-1]+cnt[i-1][j];

            }
        }
    }
}

ll i=n,j=m;
string ans;

while (i>0&&j>0)
{
    if(s[i-1]==p[j-1]){
        ans.push_back(s[i-1]);
        i--;
        j--;
    }else if(dp[i-1][j]>dp[i][j-1]){
        ans.push_back(s[i-1]);
        i--;
    }else{
        ans.push_back(p[j-1]);
        j--;

    }
}
while (i>0)
{
     ans.push_back(s[i-1]);
     i--;
}
while (j>0)
{
     ans.push_back(p[j-1]);
     j--;
}

cout<<ans.size()<<" "<<cnt[n][m]<<endl;

}

int main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0);       
  cout.tie(0);
//   solve();
  int t;
  cin>>t;
  for (int i=1;i<=t;i++)
  {
    cout<<"Case "<<i<<": ";
   solve();
  }
  }