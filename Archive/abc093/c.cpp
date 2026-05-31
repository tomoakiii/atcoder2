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
    vector<ll> A(3);
    rep(i,3) cin>>A[i];
    sort(A.begin(), A.end());
    ll ans = 0;
    if((A[1]-A[0])%2==1) {
        A[1]++; A[2]++; ans++;
    }
    ans += (A[1]-A[0])/2;
    ans += A[2]-A[1];
    cout<<ans<<endl;
    return 0;
}