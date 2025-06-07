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
    ll N;
    cin >> N;
    vector uv(N, vector<ll>{});
    vector<int> U(N-1), V(N-1);
    rep(i, N-1) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        if(v<u) swap(u,v);
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);        
        U[i] = u;
        V[i] = v;
    }
    vector bw(2, vector<int>{});
    auto f = [&](auto f, int cur, int pre, bool b)->void{
        bw[(b)?1:0].emplace_back(cur);
        for(auto nx: uv[cur]) {
            if (nx == pre) continue;
            f(f, nx, cur, !b);
        }
    };
    f(f, 0, -1, false);    
    
    set<pair<int, int>> st;
    for(auto i: bw[0]) for(int j: bw[1]) {
        int ii = i, jj = j;
        if(j<i) swap(ii, jj);
        st.insert({ii+1, jj+1});
    }    
    rep(i,N-1) {        
        st.erase({U[i]+1, V[i]+1});        
    }
    if((int)st.size()%2==1) {
        cout << "First" << endl;    
        auto [i, j] = *(st.begin());
        cout << i << " " << j << endl;
        st.erase({i, j});
    } else {
        cout << "Second" << endl;
    }
    while(!st.empty()) {
        int i, j;
        cin >> i >> j;
        if(j<i) swap(i, j);
        st.erase({i, j});
        auto stb = st.begin();
        auto [ii, jj] = *stb;
        cout << ii << " " << jj << endl;
        st.erase({ii, jj});
    }
    int i, j;
    cin >> i >> j;
    if(i == -1) return 0;
    else cout << -1 << " " << -1 << endl;
    return 0;
}