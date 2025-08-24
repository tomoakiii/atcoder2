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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(M);
    rep(i,M) cin>>A[i];
    A.push_back(N+1);
    sort(A.begin(), A.end());
    ll t = 1, mn = INF;
    vector<ll> white;
    rep(i,M+1) {
        ll ln = A[i] - t;
        if(ln != 0) {
            white.push_back(ln);
            chmin(mn, ln);
        }
        t = A[i] + 1;
    }
    ll ans = 0; 
    for(auto w: white) {
        ans += (w+mn-1)/mn;
    }
    cout << ans << endl;
    return 0;
}