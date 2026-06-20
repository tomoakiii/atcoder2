#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N),L(N);
    rep(i,N)cin>>A[i]>>L[i];
    rep(i,M) {
        ll p,c; cin>>p>>c;
        p--;
        A[p] += c;
    }
    ll ans=0;
    rep(i,N) if(A[i]>L[i]) ans++;
    cout<<ans<<endl;
    return 0;
}