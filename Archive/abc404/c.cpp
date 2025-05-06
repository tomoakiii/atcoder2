

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
typedef pair<ll, int> pli;
int main(){
    int N, M;
    cin >> N >> M;    
    vector uv(N, vector<int>{});
    
    rep(i,M){
        int u, v;
        cin >> u >> v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);        
    }

    vector<bool> visit(N);
    auto f = [&](auto f, int cur)->void{
        visit[cur] = true;
        if(uv[cur].size() > 2) return;
        for(auto nx: uv[cur]) {
            if(visit[nx]) continue;
            f(f, nx);
        }
    };
    f(f, 0);

    bool ans = true;
    rep(i,N) if(!visit[i]) ans = false;
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}