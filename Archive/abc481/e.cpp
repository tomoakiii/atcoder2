#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long double ld;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

struct V {
  ll x, y; int i;
  V(ll x=0, ll y=0, int i=-1): x(x), y(y), i(i) {}
  ll cross(const V& a) const { return x*a.y - y*a.x;}
  bool up() const { return y > 0 || (y == 0 && x > 0);}
  bool operator<(const V& a) const {
    if (up() != a.up()) return up();
    return cross(a) > 0;
  }
};

void solve(){
    ll N; cin>>N;
    vector<V> ps(2*N);
    rep(i,N) {
        cin >> ps[i].x >> ps[i].y, ps[i].i = i;
        ps[i+N].x = -ps[i].x;
        ps[i+N].y = -ps[i].y;
        ps[i+N].i = ps[i].i+N;
    }
    sort(ps.begin(), ps.end());

    fenwick_tree<ll> FT(4*N);
    vector<ll> V(N),S(N);
    rep(i,2*N){
        int id = ps[i].i;
        if(id < N) {
            FT.add(i,1);
            S[id] = i;
        } else V[id-N]=i;
    }
    ll ans=0;
    rep(j,N){
        auto i = S[j];
        auto i2 = V[j];
        if(i2<i)swap(i,i2);
        ll len = FT.sum(i,i2);
        chmax(ans,len);
        chmax(ans,N-len);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}