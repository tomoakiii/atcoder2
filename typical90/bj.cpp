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

using S = ll;
using F = ll;
S op(S l, S r) {return max(l, r);}
S e() {return 0;}
S mapping (F l, S r) {return r+=l;}
F composition (F l, F r) {return l+r;}
F id() {return 0;}



int main(){
    ll N; cin>>N;
    vector uv(N, vector<int>{});
    rep(i,N) {
        ll u, v; cin>>u>>v; u--,v--;
        uv[u].push_back(i); // u, vを持っているもののリストにiを追加する
        uv[v].push_back(i);
    }
    vector<deque<int>> dque;
    vector<int> visit(N, -1);
    vector<int> nxnode{};
    rep(i,N) {
        if(visit[i]!=-1) continue;
        dque.push_back({});
        nxnode.push_back(-1);
        int sz = dque.size() - 1;
        visit[i] = sz;
        queue<int> que;
        que.push(i);
        while(!que.empty()) {
            auto q = que.front();
            que.pop();
            dque[sz].push_back(q);
            for(auto nx: uv[q]) {
                if(visit[nx] == -1) {
                    visit[nx] = sz;
                    que.push(nx);
                    continue;
                } else {
                    if(visit[nx] != sz) nxnode[sz] = visit[nx];
                }
            }
        }
    }

    vector<int> ans;
    int c = dque.size()-1;
    while(true) {
        for(auto d: dque[c]) {
            ans.push_back(d);
        }
        c = nxnode[c];
        if(c == -1) break;
    }
    if(ans.size() != N) {
        cout<<-1<<endl;
        return 0;
    }
    //reverse(ans.begin(), ans.end());
    for(auto a:ans) cout<<1+a<<endl;
    return 0;
}