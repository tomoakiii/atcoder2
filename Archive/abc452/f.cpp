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
    ll N,K;
    cin >> N >> K;
    vector<ll> P(N);
    rep(i,N) {
        cin>>P[i];
        P[i]--;
    }

    auto get = [&](ll K)->ll {
        fenwick_tree<ll> FT(N+1);
        ll ret=0;
        ll r=0, sm=0;
        rep(l,N) {
            while( (r<N && sm<K) || r<=l ) {
                FT.add(P[r],1);
                sm += FT.sum(P[r]+1,N+1);
                r++;
            }
            if(sm>=K) ret += (N-r+1);
            sm -= FT.sum(0,P[l]);
            FT.add(P[l],-1);
        }
        return ret;
    };
/*
    for(ll k=1; k<N*N/2; k++) {
        cerr<<get(k)<<endl;
    }
*/
    cout << get(K)-get(K+1) << endl;
    return 0;
}