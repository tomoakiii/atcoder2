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
    vector<ll> A(N),B(N),C(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    rep(i,N) cin>>C[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    
    vector<ll> cnt(N);
    rep(i,N) {
        auto c = upper_bound(C.begin(), C.end(), B[i]) - C.begin();
        cnt[i] = N-c;
    }
    for(int i=N-1; i>0; i--) cnt[i-1] += cnt[i];
    cnt.push_back(0);

    ll ans = 0;
    for(auto a:A) {
        auto b = upper_bound(B.begin(), B.end(), a) - B.begin();
        ans += cnt[b];
    }
    cout<<ans<<endl;
    return 0;
}