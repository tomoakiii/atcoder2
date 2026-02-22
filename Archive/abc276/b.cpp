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
    int N, M;
    cin >> N >> M;
    vector uv(N, vector<int>{});    
    rep(i, M) {
        int u,v;
        cin >> u >> v;
        u--, v--;        
        uv[u].push_back(v);
        uv[v].push_back(u);
    }
    rep(i,N) {
        sort(uv[i].begin(), uv[i].end());
        cout << uv[i].size() << " ";
        for(auto c: uv[i]) {
            cout << c+1 << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}