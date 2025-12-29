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
    ll W,a,b; cin>>W>>a>>b;
    ll ans = 0;
    if(a+W < b) {
        ans = b-(a+W);
    } else if(b+W<a) {
        ans = a - (b+W);
    }
    cout<<ans<<endl;
    return 0;
}