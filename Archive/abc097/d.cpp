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
    vector<ll> P(N);
    vector<ll> O(N);
    rep(i,N) {
        cin>>P[i];
        P[i]--;
        O[P[i]] = i;
    }

    dsu UF(N);
    rep(i,M) {
        int x,y; cin>>x>>y; x--,y--;
        UF.merge(P[x], P[y]);
    }
    ll ans = 0;
    for(auto g: UF.groups()) {
        set<ll> sti, stv;
        for(auto gg: g) {
            sti.insert(P[gg]);
            stv.insert(gg);
        }
        for(auto s: sti) {
            if(stv.contains(s)) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}