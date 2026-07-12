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

/* encode: ランレングス圧縮を行う
*/

vector<pair<ll, int>> encode(vector<ll> &v) {
    int n = (int)v.size();
    vector<pair<ll, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && v[l] == v[r]; r++) {};
        ret.push_back({v[l], r - l});
        l = r;
    }
    return ret;
}

int main(){
    ll N,K; cin>>N>>K;
    vector<ll> S(N);
    rep(i,N) cin>>S[i];
    auto en = encode(S);
    for(auto [a, c]:en){
        if(c>=K) rep(i,c) cout<<a<<" ";
    }
    cout << endl;
    return 0;
}