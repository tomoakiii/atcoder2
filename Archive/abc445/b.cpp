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
    ll N;
    cin >> N;
    vector<string>S(N);
    ll mx = 0;
    rep(i,N) {
        cin>>S[i];
        ll s = S[i].size();
        chmax(mx,s);
    }
    rep(i,N) {
        ll rm =  mx - S[i].size();
        string ans = "";
        rep(i,rm/2) ans.push_back('.');
        for(auto c:S[i]) ans.push_back(c);
        rep(i,rm/2) ans.push_back('.');
        cout<<ans<<endl;
    }
    return 0;
}
