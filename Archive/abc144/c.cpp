#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
int main(){
    ll N; cin>>N;
    ll ans = N;
    for(ll i=1; i*i<=N; i++)  {
      if(N%i == 0) {
        ll j = N/i;
        chmin(ans, i-1+j-1);
      }
    }
    cout<<ans<<endl;
    return 0;
}