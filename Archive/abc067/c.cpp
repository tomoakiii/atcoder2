#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N; cin>>N;
    vector<ll> A(N);
    ll sm = 0;
    rep(i,N) {
      cin>>A[i];
      sm += A[i];
    }
    
    ll ans = INF;
    ll tmp = 0;
    for(int i=0; i<=N-2; i++) {
        tmp += A[i];
        ll rem = sm - tmp;
        chmin(ans, abs(rem - tmp));
    }
    cout<<ans<<endl;
    return 0;
}