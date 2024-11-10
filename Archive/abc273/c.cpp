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
    vector<ll> A(N);
    rep(i,N) {
        ll a;
        cin>>a;
        A[i] = a;        
    }
    vector B = A;
    sort(B.begin(), B.end());
    auto ip = unique(B.begin(), B.end());
    B.resize(distance(B.begin(), ip));

    vector<ll> ans(N);
    rep(i, N) {
        auto idb = lower_bound(B.begin(), B.end(), A[i]+1);
        ans[(int)(B.end() - idb)]++;
    }
    rep(i, N) cout<<ans[i]<<endl;
    return 0;
}