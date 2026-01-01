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
    string S; cin>>S;
    ll ans = 0;
    ll p = (S.size()+1)/2;
    ll q = S.size() - p;
    rep(i,p) {
        if(S[i] == 'p') ans--;
    }
    reverse(S.begin(), S.end());
    rep(i,q) {
        if(S[i] == 'g') ans++;
    }
    cout << ans << endl;
    return 0;
}