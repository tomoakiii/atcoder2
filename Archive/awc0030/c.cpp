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
    ll N,K;
    cin >> N>>K;
    int ans=0, sm=0;
    rep(i,N) {
        ll s; cin>>s;
        if(s==1) {
            sm++;
        } else {
            if(sm >= K) ans++;
            sm = 0;
        }
    }
    if(sm >= K) ans++;
    cout<<ans<<endl;
    return 0;
}