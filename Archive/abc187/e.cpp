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
    cin >> N;
    M = N-1;
    vector uv(N, vector<ll>{});
    vector<int> A(N), B(N);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        A[i] = u, B[i] = v; 
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<ll> cld(N);
    vector<ll> ord;
    vector<ll> ordind(N);
    vector<ll> par(N);
    
    auto func = [&](auto func, int cur, int pre)->ll{
        ll ret = 0;
        ord.push_back(cur);
        ordind[cur] = ord.size() - 1;
        for(auto nx: uv[cur]) {
            if(nx == pre) continue;
            par[nx] = cur;
            ret += func(func, nx, cur);
        }
        cld[cur] = ret;        
        return ret + 1;
    };
    func(func, 0, -1);
    ll Q; cin>>Q;
    vector<ll> C(N+1);
    while(Q--) {
        int qt, e;
        ll x; 
        cin>>qt>>e>>x;
        e--; qt--;
        bool qb = qt;
        int a = A[e], b = B[e];
        if(par[a] == b) {
            swap(b,a);
            qb = !qb;
        } // a is parent, b is child;
        if(qb) {
            // count up all children
            C[ordind[b]] += x;
            C[ordind[b] + cld[b] + 1] -= x;
        } else {
            // count up other than all children
            C[0] += x;
            C[N] -= x;
            C[ordind[b]] -= x;
            C[ordind[b] + cld[b] + 1] += x;
        }
    }
    rep(i,N) C[i+1] += C[i];
    rep(i,N) {
        cout << C[ordind[i]]<<endl;
    }
    return 0;
}