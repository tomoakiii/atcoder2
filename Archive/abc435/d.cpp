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
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[v].emplace_back(u);
    }
    vector<bool> isOK(N);
    int Q; cin>>Q;
    while(Q--){
        int op; cin>>op;
        int v; cin>>v; v--;
        if(op==1) {
            if(isOK[v]) continue;
            auto func = [&](auto func, int cur, int pre)->void{
                isOK[cur] = true;
                for(auto nx: uv[cur]) {
                    if(nx == pre) continue;
                    if(isOK[nx]) continue;
                    func(func, nx, cur);
                }
            };
            func(func, v, -1);
        } else {
            if(isOK[v]) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}