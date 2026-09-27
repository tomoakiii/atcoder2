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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> ans(3);
    rep(i,N) {
        ll a; cin>>a;
        ll p = (a+999)/1000;
        p *= 1000;
        ll rm = p-a;
        rep(i,3){
            ans[i] += rm%10;
            rm/=10;
        }
    }
    rep(i,3) cout<<ans[i]<<" \n"[i==2];
    return 0;
}