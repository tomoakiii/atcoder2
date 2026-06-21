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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) {
        ll k; cin >> k;
        vector<ll> a(k);
        rep(j,k) {
            cin >> a[j];
        }
        sort(a.rbegin(), a.rend());
        A[i] = a[k/2];
    }
    sort(A.rbegin(), A.rend());
    ll ans=0;
    rep(i,K) {
        if(A[i] < 0)break;
        ans += A[i];
    }
    cout<<ans<<endl;
    return 0;
}