// Typical90-021, Count pairs of Each-reachable-nodes
// https://atcoder.jp/contests/typical90/tasks/typical90_u
// https://x.com/e869120/status/1385363292739104775/photo/1


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
typedef pair<int, ll> pil;
int main(){
    int N;
    cin >> N;
    vector uv(N, vector<pil>{}), vu(N, vector<pil>{});
    vector<ll> X(N), C(N);
    rep(i,N) {
        cin>>X[i];
        X[i]--;
    }
    rep(i,N) cin>>C[i];
    rep(i,N) {
        uv[X[i]].push_back({i, C[i]});
        vu[i].push_back({X[i], C[i]});
    }

    vector<bool> visit(N, false);
    vector<pair<int, int>> idx(N, {0, 0});
    int id = 0;
    auto f = [&](auto f, int cur)->void{
        visit[cur] = true;
        for(auto [nx, c]: uv[cur]) {
            if (visit[nx]) continue;
            f(f, nx);
        }
        idx[cur] = {id++, cur};
    };

    // 1st dsu --> index incresing at returning
    rep(i, N) {
        if(visit[i] != 0) continue;
        f(f, i);
    }

    // decrease sort
    sort(idx.rbegin(), idx.rend());
    
    vector<bool> visit2(N, false);    
    ll ans = 0;        

    // 2nd dsu --> grouping with reachable nodes
    for(auto [id, i] : idx) {
        set<int> st;
        set<ll> stc;
        bool flg = false;
        auto f2 = [&](auto f2, int cur)->void{        
            visit2[cur] = true;
            st.insert(cur);
            for(auto [nx, c]: vu[cur]) {
                stc.insert(c);
                if(st.contains(nx)) {
                    flg = true;
                }
                if (visit2[nx]) continue;
                f2(f2, nx);
            }      
        };        
        if(visit2[i]) continue;
        f2(f2, i);
        if(flg) {
            ans += *stc.begin();
        }
        
    }
    
    cout << ans << endl;
    return 0;
}