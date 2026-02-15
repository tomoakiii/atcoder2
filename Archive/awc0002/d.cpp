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
    ll N, M;
    cin >> N >> M;
    vector<ll> C(N),R(M);
    rep(i,N) cin>>C[i];
    rep(i,M) cin>>R[i];
    sort(C.begin(), C.end());
    sort(R.begin(), R.end());
    ll ans = 0;
    while(!C.empty() && !R.empty()) {
        if(C.back() <= R.back()) {
            ans++;
            C.pop_back(); R.pop_back();
        } else {
            C.pop_back();
        }
    }
    cout<<ans<<endl;
    return 0;
}