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
typedef pair<ll,ll> pll;
int main(){
    ll N, M;
    cin >> N >> M;        
    vector uv(N, vector<pll>{});
    vector<ll> U(M), V(M), W(M);
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
    }

    vector list(N, vector<bool>(1<<10));
    auto f = [&](auto f, int cur, ll p)->void {
        for(auto [nx, w]: uv[cur]) {
            p = p ^ w;
            if(!list[nx][p]) {
                list[nx][p] = true;
                f(f, nx, p);
            }      
            p = p ^ w;
        }
    };
    list[0][0] = true;
    f(f, 0, 0);

    rep(p, 1<<10) if(list[N-1][p]) {
        cout<<p<<endl;
        return 0;
    }
    
    cout<<-1<<endl;
    return 0;
}