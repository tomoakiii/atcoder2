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
    vector<set<string>> st('z'-'a'+1);
    int N; cin>>N;
    string ok = "MARCH";

    rep(i,N) {
        string s; cin>>s;
        for(auto c: ok) {
            if(s[0] == c) st[c-'A'].insert(s);
        }
    }
    vector<ll> v;
    for(auto s: st) {
        if(s.size() > 0) v.push_back(s.size());
    }
    int sz = v.size();
    if(sz <= 2) {
        cout << 0 << endl;
    } else {
        ll ans = 0;
        rep(i,sz) for(int j=i+1; j<sz; j++) for(int k=j+1; k<sz; k++) ans += v[i] * v[j] * v[k];
        cout << ans << endl;
    }

    return 0;
}