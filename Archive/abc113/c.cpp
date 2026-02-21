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

string to_str(ll x, int d=6){
    string ret;
    ret = to_string(x);
    ret.insert(0, d - ret.length(), '0');
    return ret;
}

int main(){
    ll N,M; cin>>N>>M;
    vector PC(N, vector<pair<ll,ll>>{});
    rep(i,M){
        ll p,y; cin>>p>>y;
        p--;
        PC[p].emplace_back(y, i);
    }
    vector<string> ans(M);
    rep(p, N) {
        sort(PC[p].begin(), PC[p].end());
        rep(j, PC[p].size()){
            auto [y, i] = PC[p][j];
            string s;
            s = to_str(p+1) + to_str(j+1);
            ans[i] = s;
        }
    }
    for(auto a:ans) cout<<a<<endl;
    return 0;
}