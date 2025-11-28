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

void solve() {
    ll N,M; cin>>N>>M;
    vector<pair<ll,int>> X(N), Y(M);
    vector<set<pair<int,int>>> P(N*M + 1);
    vector G(N, vector<ll>(M));
    vector L(N, vector<ll>(M));
    rep(i,N) {
        cin>>X[i].first;
        X[i].second = i;
    }
    rep(i,M) {
        cin>>Y[i].first;
        Y[i].second = i;
    }
    sort(X.rbegin(), X.rend());
    sort(Y.rbegin(), Y.rend());

    rep(x,N) rep(y,M) {
        auto [r,i] = X[x];
        auto [c,j] = Y[y];
        ll m = min(r,c);
        L[i][j] = m;
        P[m].insert({i, j});
    }


    vector<bool> visit(N*M+1);
    auto upd = [&](int i, int j, ll v)->bool {
        if(visit[v] || G[i][j] != 0) return false;
        if(L[i][j] < v) return false;
        G[i][j] = v;
        visit[v] = true;
        P[L[i][j]].erase({i,j});
        return true;

    };

    rep(i,N) rep(j,M) if(X[i].first == Y[j].first) {
        upd(X[i].second, Y[j].second, X[i].first);
    }
    int r = 0, c = 0;

    for(auto [r,i]: X) {
        for(auto [c,j]: Y){
            if(c > r) upd(i,j,r);
        }
    }


    for(auto [c,j]: Y) {
        for(auto [r,i]: X) {
            if(c < r) upd(i,j,c);
        }
    }


    ll up = N*M;
    for(int v = N*M; v>0; v--) {
        if(visit[v]) continue;
        while(up > 0 && P[up].empty()) up--;
        if(up==0) {
            cout<<"No"<<endl;
            return;
        }
        auto [i,j] = *P[up].begin();
        upd(i,j,v);
    }
    rep(i,N) rep(j,M) if(G[i][j] == 0) {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    rep(i,N) {
        rep(j,M) cout<<G[i][j]<<" ";
        cout<<endl;
    }
}


int main(){
    int T; cin>>T;
    while(T--)solve();
    return 0;
}