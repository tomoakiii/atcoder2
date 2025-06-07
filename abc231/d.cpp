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
        cin >> u >> v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);        
    }
    int cnt;
    bool err = false;
    vector<bool> visit(N);    
    auto f = [&](auto f, int cur, int pre)->void{
        visit[cur] = true;
        if(uv[cur].size() == 1) cnt++;
        for(auto nx: uv[cur]){
            if(nx == pre)continue;
            if(visit[nx]){
                err = true;
                return;
            }
            f(f, nx, cur);
        }        
    };
    rep(i,N) {
        if(visit[i]) continue;
        cnt = 0;
        f(f, i, -1);
        if(cnt > 2 || err) {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
