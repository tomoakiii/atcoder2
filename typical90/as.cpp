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
typedef modint1000000007 mint;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tiii;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> X(N), Y(N);
    rep(i,N) cin>>X[i]>>Y[i];
    vector mp(1<<N, vector<ll>(K+1, -1));
    vector dist(N, vector<ll>(N));
    rep(i,N) rep(j,N) {
        ll dy = Y[i]-Y[j], dx = X[i]-X[j];
        dist[i][j] = dy*dy+dx*dx;
    }
    rep(k,1<<N) {
        ll mx  = 0;
        rep(i,N) {
            if(k>>i & 1) {
                for(int j=i+1; j<N; j++) {
                    if(k>>j & 1) chmax(mx, dist[i][j]);
                }
            }
        }
        mp[k][1] = mx;
    }
    auto func = [&](auto func, ll q, ll d) -> ll{
        vector<int> p;
        rep(i,N) {
            if(q>>i & 1) p.push_back(i);
        }
        if(p.size() < d) return INF;
        if(d == 1) return mp[q][1];
        ll ret = INF;
        for(ll k = 1 ; k < (1<<p.size())-1 ; k++) {
            ll nsp = 0, nsn = 0;
            rep(i, p.size()) {
                if(k>>i & 1) {
                    nsp |= 1<<p[i];
                } else {
                    nsn |= 1<<p[i];
                }
            }
            for(int x = 1; x < d; x++) {
                int y = d - x;
                if(mp[nsp][x] == -1) {
                    mp[nsp][x] = func(func, nsp, x);
                }
                if(mp[nsn][y] == -1) {
                    mp[nsn][y] = func(func, nsn, y);
                }
                chmin(ret, max(mp[nsp][x], mp[nsn][y]));
            }
        }
        return ret;
    };
    cout << func(func, (1<<N)-1, K) << endl;
    return 0;
}