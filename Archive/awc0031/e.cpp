//https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bp
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

int main() {
    int N,K,M;
    cin>>N>>K>>M;
    mf_graph<ll> G(N+K+2);
    vector<ll> W(K);
    int St=N+K;
    int Gl=St+1;
    ll alP=0;
    rep(i,N) {
        ll b; cin>>b;
        alP+=b;
        G.add_edge(i, Gl, b);
    }
    rep(i,K) cin>>W[i];
    rep(i,M) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--, v--;
        G.add_edge(u, v, c);
        G.add_edge(v, u, c);
    }

    vector<bool> use(K,true);
    int Q; cin>>Q;
    vector<ll> S(Q);
    rep(i,Q) {
        cin>>S[i];
        S[i]--;
        use[S[i]]=false;
    }
    rep(k,K) {
        if(use[k]) G.add_edge(St, k+N, W[k]);
    }

    vector<bool> ans(Q);
    reverse(S.begin(),S.end());
    ll last=0;
    rep(i,Q) {
        ll res = G.flow(St, Gl);
        // cerr << res << endl;
        last+=res;
        if(last >= alP) {
            ans[i] = true;
        }
        int j=S[i];
        // cerr << "+++ " << St << " " << N+j << " " << W[j] << endl;
        G.add_edge(St, N+j, W[j]);
    }
    reverse(ans.begin(), ans.end());
    for(auto a:ans) {
        cout<<(a?"Yes":"No")<<endl;
    }
    return 0;
}