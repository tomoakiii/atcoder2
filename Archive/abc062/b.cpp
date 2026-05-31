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
    ll H,W; cin>>H>>W;
    rep(i,W+2) cout<<'#';
    cout<<endl;
    rep(i,H) {
        cout<<'#';
        string S; cin>>S; cout<<S;
        cout<<'#'<<endl;
    }
    rep(i,W+2) cout<<'#';
    cout<<endl;
    return 0;
}