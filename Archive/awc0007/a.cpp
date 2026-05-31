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
    ll N, M;
    cin >> N >> M;
    ll E=INF;
    rep(i,N) {
        ll e; cin>>e; chmin(E,e);
    }
    ll sm = 0;
    rep(i,M) {
        ll c; cin>>c;
        sm+=c;
    }
    cout<<sm*E<<endl;
    return 0;
}