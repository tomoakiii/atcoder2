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
vector<pair<char, int>> encode(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll A,B;cin>>A>>B;
    string T; cin>>T;
    int r=0;
    for(auto t:T){
        if(t=='R') r++;
    }
    if(r!=A){
        cout<<-1<<endl;
        return 0;
    }
    auto enc = encode(T);
    ll ans=0;
    for(auto [c,v]:enc){
        if(c=='R')ans++;
    }
    if(enc[0].first == 'R') {
        ans--;
    }
    cout<<ans<<endl;
    return 0;
}