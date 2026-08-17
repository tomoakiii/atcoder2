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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll mxa=0;
    rep(i,N) {
      cin>>A[i];
      chmax(mxa,A[i]);
    }
    vector list(mxa+1,vector<int>{});
    rep(i,N) list[A[i]].push_back(i);
    for(ll x=2;x*x<=mxa;x++){
      rep(i,N) if(A[i]%x==0) {
        list[x].push_back(i);
        list[A[i]/x].push_back(i);
      }
    }
    dsu UF(N);
    ll ans = 0;
    for(ll x=mxa; x>=2; x--){
      if(list[x].size()<2) continue;
      for(auto i:list[x]){
        if(!UF.same(list[x][0], i)) {
          // cerr<<x<<" "<<list[x][0]<<" "<<i<<endl;
          ans+=x;
          UF.merge(list[x][0], i);
        }
      }
    }
    rep(i,N){
      if(!UF.same(0,i)){
        ans++; UF.merge(0, i);
      }
    }
    cout<<ans<<endl;
    return 0;
}