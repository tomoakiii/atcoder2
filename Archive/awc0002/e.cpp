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
    ll N,S;
    cin >> N>>S;
    ll N2 = N/2;
    ll N3 = N-N2;
    vector<ll> A(N2), B(N3);
    rep(i,N2) cin>>A[i];
    rep(i,N3) cin>>B[i];
    unordered_map<ll,ll> mp1,mp2;
    rep(kkk,2) {
        rep(k, 1ll<<N2) {
            ll sm = 0;
            rep(i, N2) {
                if(k>>i & 1) sm += A[i];
            }
            mp1[sm]++;
        }
        swap(mp1, mp2);
        swap(A,B);
        swap(N2,N3);
    }
    ll ans = 0;
    for(auto [v, cnt] :mp1) {
        if(!mp2.contains(S-v)) continue;
        ans += cnt * mp2[S-v];
    }
    cout<<ans<<endl;
    return 0;
}