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
vector<pair<char, ll>> encode(const string& str) {
    int n = (int)str.size();
    vector<pair<char, ll>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}
int main(){
    int N; cin>>N;
    string S; cin>>S;
    auto re = encode(S);
    int M=re.size();
    ll ans=0;
    rep(i,M-2){
        if(re[i].first == re[i+2].first) ans += re[i].second*re[i+2].second;
    }
    cout<<ans<<endl;
    return 0;
}