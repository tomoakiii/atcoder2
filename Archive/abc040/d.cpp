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
typedef pair<ll, pair<ll,ll>> ppl;
int main(){
    ll N, M;
    cin >> N >> M;
    deque<ppl> UV(M);
    rep(i,M) {
        cin>>UV[i].second.first>>UV[i].second.second>>UV[i].first;
        UV[i].second.first--;
        UV[i].second.second--;
    }
    sort(UV.rbegin(), UV.rend());
    priority_queue<ppl> que;
    int Q; cin>>Q;
    rep(i,Q) {
        int v; ll w; cin>>v>>w; v--;
        que.push({w, {v, i}});
    }
    vector<ll> ans(Q);
    dsu UF(N);
    while(!que.empty()) {
        auto [w, vi] = que.top();
        que.pop();
        auto [v, i] = vi;
        while(!UV.empty() && UV.begin()->first > w){
            auto [y, ab] = *UV.begin();
            auto [a,b] = ab;
            UF.merge(a,b);
            UV.pop_front();
        }
        int ld = UF.leader(v);
        ans[i] = UF.size(ld);
    }
    for(auto a:ans) cout<<a<<endl;
    return 0;
}