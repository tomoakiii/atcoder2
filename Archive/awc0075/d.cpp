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
    ll N,K,M;
    cin >> N >>K>>M;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(),A.end());
    ll ok=1e10,ng=-1;
    while(ok-ng>1){
      ll c=(ok+ng)/2;
      ll cnt=INF,mn=INF,mx=0;
      ll sm=0;
      rep(i,N){
        chmax(mx,A[i]);
        chmin(mn,A[i]);
        cnt++;
        if(cnt>M || (mx-mn)>c) {
          sm++;
          mx=mn=A[i];
          cnt=1;
        }
      }
      if(sm>K)ng=c;
      else ok=c;
    }
    cout<<ok<<endl;
    return 0;
}