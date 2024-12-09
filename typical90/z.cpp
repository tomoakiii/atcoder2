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
typedef pair<ll, int> pli;

int main(){
    int N;
    cin >> N;
    vector uv(N, vector<int>{});

    rep(i,N-1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }

    vector<bool> bw(N);
    int cnt[2] = {0, 0};
    auto f=[&](auto f, int cur, int pre, bool b)->void{
        bw[cur] = b;
        cnt[(int)b]++;
        for(auto nx:uv[cur]){
            if(nx == pre) continue;
            f(f, nx, cur, !b);
        }
    };
    f(f, 0, -1, false);
    bool bp = false;
    if(cnt[0] < cnt[1]) bp = true;
    int id = 0;
    rep(i, N) {
        if(bw[i] == bp) {
            cout << (i+1) << " ";
            id++;
        }
        if(id == N/2) {
            break;
        }
    }
    return 0;
}