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
    ll N,M;
    cin >> N >> M;
    vector<ll> T(N+1);
    rep(i,N) cin>>T[i+1];
    rep(i,N) T[i+1] += T[i];
    while(M--) {
        ll s,l,r; cin>>s>>l>>r;
        l--, r--;
        cout<<s+T[r+1]-T[l]<<endl;
    }
    return 0;
}