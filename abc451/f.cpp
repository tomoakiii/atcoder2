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
    ll N,Q;
    cin >> N >> Q;
    vector<bool> visit(N);
    vector<pair<int,int>> G(N);
    vectir<bool> flip(N);
    vector<int> col(N,-1);
    ll ans=0;
    bool ok=true;
    dsu UF(N);
    while(Q--) {
        int u,v; cin>>u>>v; u--,v--;
        if(visit[v] && !visit[u]) swap(u,v);
        int a=UF.leader(u), b=UF.leader(v);
        auto [b1,w1] = G[a];
        UF.merge(u,v);
        if(visit[u]) {
            if(!visit[v]) {
                ans -= max(b1,w1);
                col[v]=(col[u]+1)%2;
                if(col[v] == 0) w1++;
                else b1++;
                ans += min(b1,w1);
            } else {
                if(a == b) {
                    if( (!flip[b] && col[u] == col[v]) ||
                    (flip[b] && col[u] != col[v])){
                        ok = false;
                    } else {
                        int c=UF.leader(v);
                        G[c]=G[a];
                    }
                } else {
                    if(col[u] == col[v]) flip[b] = true;

                }
            }
        } else {
            int c=UF.leader(v);
            G[c]={1,1};
            col[u]=1, col[v]=0;
            ans++;
        }
        if(ok)cout << ans << endl;
        else cout<<-1<<endl;
        visit[u]=true;
        visit[v]=true;
    }
    return 0;
}