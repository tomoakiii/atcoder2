//https://atcoder.jp/contests/awc0105/tasks/awc0105_d

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
    ll N,D,Q;
    cin >> N >> D >> Q;
    vector<ll> X(N),V(N),L(N);

    rep(i,N) {
        cin>>X[i]>>V[i]>>L[i];
    }
    auto func = [&]()->void{
        auto get = [&](ll c)->ll{
            ll ret = 0;
            ll mn=INF, mx=-INF;
            rep(i,N) {
                chmin(mn, X[i]+c*V[i]-L[i]);
                chmax(mx, X[i]+c*V[i]+L[i]);
            }
            return mx-mn;
        };
        ll l=0, r=D;
        while(r-l > 2) {
            ll cr = (2*r+l)/3;
            ll cl = (r+2*l)/3;
            if (get(cl) < get(cr)) {
                r = cr;
            } else {
                l = cl;
            }
        }
        ll ans = INF;
        for(ll k=l; k<=r; k++) chmin(ans, get(k));
        cout<<ans<<endl;
    };
    func();
    while(Q--){
        ll p,a,b,c; cin>>p>>a>>b>>c;
        p--;
        X[p]=a,V[p]=b,L[p]=c;
        func();
    }
    return 0;
}