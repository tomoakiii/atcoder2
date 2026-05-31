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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector uv(N, vector<int>{});
    rep(i,N-1) {
        int u, v; cin>>u>>v;
        u--, v--;
        uv[u].push_back(v);
        uv[v].push_back(u);
    }
    vector<int> par(N,-1);
    vector<int> bw(N);
    ll ans = 0; 
    rep(cntk,K) {
        ll mxv = 0;
        int mxi;
        vector<bool> visit(N);
        vector mx(N, vector<pair<int,ll>>(2));
        rep(i,N) rep(j,2) mx[i][j].second = i;    
        auto f = [&](auto f, int cur)->void{
            visit[cur] = true;        
            for(auto nx: uv[cur]) {
                if(visit[nx]) continue;
                if(bw[nx]) continue;
                par[nx] = cur;
                f(f, nx);
                if(mx[cur][1].first < mx[nx][0].first + A[nx]){
                    mx[cur][1].first = mx[nx][0].first + A[nx];
                    mx[cur][1].second = mx[nx][0].second;
                    sort(mx[cur].rbegin(), mx[cur].rend());
                }
            }
            ll v = mx[cur][0].first + mx[cur][1].first + A[cur];
            if(mxv < v) {
                mxv = v;
                mxi = cur;
            }
        };
        f(f, 0);
        rep(j,2) {
            int p = mx[mxi][j].second;            
            while(p!=mxi && p!=-1) {
                bw[p] = 1;
                p = par[p];
            }
        }
        bw[mxi] = 1;
        ans += mxv;        
    }
    cout << ans << endl;
    return 0;
}