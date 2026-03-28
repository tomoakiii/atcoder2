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
    ll N,T;
    cin >> N >> T;
    ll ans=0;
    rep(t,T) {
        vector<ll> mx(N);
        rep(i,N) cin>>mx[i];
        sort(mx.rbegin(),mx.rend());
        if(mx[0]>=2*mx[1])ans++;
    }
    cout<<ans<<endl;
    return 0;
}