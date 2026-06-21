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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    if(M!=N-1){
        cout << "NO" << endl;
        return 0;
    }
    struct node{
        int child[2];
        ll l, r, p, q;
        int par;
    };
    vector<node> uv(N);
    rep(i,N){
        ll l,r,p,q;
        cin >> l >> r >> p >> q;
        uv[i] = { {-1, -1}, l, r, p, q, -1 };
    }
    rep(i,M) {
        int u,v,b;
        cin>>u>>v>>b;
        u--, v--;
        if(uv[v].par != -1) {
            cout << "NO" << endl;
            return 0;
        }
        uv[v].par = u;
        if(v == 0) {
            cout << "NO" << endl;
            return 0;
        }
        if( (uv[u].child[b] != -1 ) || 
            (uv[u].q != uv[v].p) || 
            (uv[u].l >= uv[v].l) ||
            (uv[u].r <= uv[v].r) )
        {
            cout << "NO" << endl;
            return 0;
        }
        uv[u].child[b] = v;
    }
    rep(i,N) {
        if(uv[i].child[0] == -1 || uv[i].child[1] == -1) continue;
        int x=uv[i].child[0];
        int y=uv[i].child[1];
        if(uv[x].r < uv[y].l) continue;
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}