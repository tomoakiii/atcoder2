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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(N);
    rep(i,N) cin>>X[i];    
    vector uv(N, vector<ll>{});
    int M = N-1;
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector rank(N, vector<ll>{});
    vector<bool> visit(N);    
    auto merge = [&](vector<ll> &s1, vector<ll> &s2)->vector<ll>{
        vector<ll> ret;
        int k = 0;
        int t1 = 0, t2 = 0;
        while(ret.size() < 20) {
            if(t1 == s1.size() && t2 == s2.size()) break;
            else if(t1 == s1.size()) {
                ret.push_back(s2[t2++]);
            } else if (t2 == s2.size()) {
                ret.push_back(s1[t1++]);
            } else {
                if(s1[t1] > s2[t2]) ret.push_back(s1[t1++]);
                else ret.push_back(s2[t2++]);    
            }
        }
        return ret;
    };

    auto f = [&](auto f, int cur)->void{
        visit[cur] = true;
        rank[cur].push_back(X[cur]);
        for(int nx: uv[cur]) {
            if(visit[nx]) continue;
            f(f, nx);
            rank[cur] = merge(rank[cur], rank[nx]);
        }
    };
    f(f, 0);
    while(Q--) {
        int v,k;
        cin>>v>>k;
        v--;
        auto it = rank[v].begin();
        rep(i, k-1) it++;
        cout << (*it) << endl;

    }
    return 0;
}