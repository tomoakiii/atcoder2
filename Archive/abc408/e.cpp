#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<int> uv(M), vv(M);
    vector<ll> wv(M);
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;        
        uv[i] = u-1;
        vv[i] = v-1;
        wv[i] = w;
    }
    const int Y = 31;
    // const int Y = 2;
    ll mask = ((ll)1<<Y) - 1;
    ll ans = 0;
    
    for(int p = Y-1; p>=0; p--){
        dsu UF(N);
        rep(i,M) {
            ll mp = (mask >> p);
            mp ^= 1;
            if((wv[i]>>p | mp) != mp) {
                continue;
            } else {
                UF.merge(uv[i], vv[i]);
            }
            
        }
        
        if(UF.same(0, N-1)) {
            mask ^= (ll)1<<p;
        } else {
            continue;
        }
    }

    cout<<mask<<endl;
    return 0;
}
