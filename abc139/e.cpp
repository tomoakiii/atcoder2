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
typedef pair<int,int> pii;
int main(){
    ll N;
    cin >> N;  
    int M = N*N;
    vector uv(M, vector<ll>{});
    vector vu(M, vector<ll>{});
    ll last = -1;
    rep(i,N) rep(j,N-1) {
        ll a; cin>>a; a--;
        int id;        
        if(i>a) id = a*N + i;
        else id = i*N + a;
        if(j > 0) {
            uv[last].push_back(id);
            vu[id].push_back(last);
        }
        last = id;        
    }

    vector<bool> visit(M);
    bool f = true;
    auto dfs = [&](auto dfs, int cur, int st)->void{
        if(!f) return;
        visit[cur] = true;
        for(auto nx: uv[cur]){
            if(nx == st){
                f = false;
                return;
            }
            dfs(dfs, nx, st);
        }
    };
    rep(i,N){
        if(visit[i]) continue;
        dfs(dfs, i, i);
    }
    if(!f){
        cout<<-1<<endl;
        return 0;
    }

    ll mn=INF, mx=0;
    queue<pair<ll,ll>> que;
    vector<ll> dist(M,0);
    que.push({0,1});
    while(!que.empty()) {
        auto [d, q] = que.front();
        chmax(mx,d);
        que.pop();
        if(dist[q] != d) continue;
        for(auto nx : uv[q]){
            if(dist[nx] < d+1) {
                dist[nx] = d+1;
                que.push({d+1,nx});
            }
        }
    }
    queue<pair<ll,ll>> que2;    
    que2.push({0,1});
    while(!que2.empty()) {
        auto [d, q] = que2.front();
        chmin(mn,d);
        que2.pop();
        if(dist[q] != d) continue;
        for(auto nx : vu[q]){
            if(dist[nx] > d-1) {
                dist[nx] = d-1;
                que2.push({d+1,nx});
            }
        }
    }
    cout<<mx-mn+1<<endl;
    return 0;
}