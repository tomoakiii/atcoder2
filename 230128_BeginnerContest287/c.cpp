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
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<int>{});    
    rep(i,M){
        int u, v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<ll> visit(N);
    if(M!=N-1){
        cout<<"No"<<endl;
        return 0;
    }
    bool flg = true;
    auto f=[&](auto f, int cur, int pre)->void{
        visit[cur] = true;
        for(auto nx: uv[cur]) {            
            if(nx == pre) continue;
            if (visit[nx]) {
                flg = false;
                return;
            }            
            f(f, nx, cur);
            break;
        }
    };
    rep(i,N) if(uv[i].size() == 1) {
        f(f, i, -1);
        break;
    }
    rep(i,N) if(!visit[i]) flg = false;
    if (!flg) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}