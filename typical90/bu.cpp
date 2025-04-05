#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef pair<unsigned int, unsigned int> pll;
typedef modint1000000007 mint;

int main(){
    ll N;
    cin >> N;
    vector<int> c(N);
    rep(i,N) {
        char a;
        cin >> a;
        c[i] = a-'a';
    }
    vector uv(N, vector<ll>{});
    rep(i, N-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uv[a].emplace_back(b);
        uv[b].emplace_back(a);
    }
    
    vector<bool> visit(N, false);
    vector<mint> ans(N);
    auto func = [&](auto func, int cur) -> mint{
        visit[cur] = true;        
        vector<mint> branch{};
        for(auto nx: uv[cur]) {
            if(visit[nx]) continue;
            if(c[nx] != c[cur]) continue;
            branch.push_back(1);
            int id = branch.size() - 1;
            branch[id] += func(func, nx);
        }
        mint t = 1;
        if(branch.size() > 0) {            
            for(auto b: branch) t*=b;
            ans[cur] = t;
        } else {
            t = 0;
        }
        return t;
    };
    mint sm = 0;
    for(auto a: ans) sm += a;
    cout << sm.val() << endl;
    return 0;
}
