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
    ll N,Q;
    cin >> N >> Q;
    ll K=100;
    fenwick_tree<ll> FT(N);
    rep(i,N) {
        ll s; cin>>s;
        FT.add(i,s);
    }
    vector<ll> memo(K+1);
    while(Q--) {
        int p; cin>>p;
        if(p==1) {
            int k; ll v; cin>>k>>v;
            if(k<K) {
                memo[k]+=v;
            } else {
                for(int i=k-1; i<N; i+=k) {
                    FT.add(i,v);
                }
            }
        } else {
            int x; cin>>x; x;
            ll ans = FT.sum(0,x);
            for(int i=1; i<=K; i++) {
                ans += memo[i] * (x/i);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}