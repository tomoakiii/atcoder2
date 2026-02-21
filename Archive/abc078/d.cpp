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
    ll N,Z,W;
    cin >> N >> Z >> W;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    if(N==1) {
        cout << abs(A[0]-W) << endl;
        return 0;
    }
    ll ans = abs(A[N-1]-A[N-2]);
    chmax(ans, abs(A[N-1]-W));
    cout<<ans<<endl;
    return 0;
}