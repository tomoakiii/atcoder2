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
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
int main(){
    ll N, M, K; cin>>N>>M>>K;

    vector<tuple<int,int,ll,ll>> v(M);
    vector dep(N, vector<pli>{});

    rep(i,M) {
        ll a,s,b,t; cin>>a>>s>>b>>t;
        a--, b--;
        v[i] = make_tuple(s,t,a,b);
        dep[a].push_back({s,i});
    }
    sort(v.begin(), v.end());
    rep(i,N) sort(dep[i].begin(), dep[i].end());
    vector<priority_queue<pll,vector<pll>,greater<pll>>> ques(N);
    vector<ll> cnt(N);
    ll ans = 0;
    rep(i,M) {
        auto [s,t,a,b] = v[i];
        while(!ques[a].empty()) {
            auto [arr, nm] = ques[a].top();
            if(arr > s) break;
            ques[a].pop();
            chmax(cnt[a], nm);
        }
        ques[b].push({t+K, cnt[a]+1});
        chmax(ans, cnt[a]+1);
    }

    cout << ans << endl;
    return 0;
}