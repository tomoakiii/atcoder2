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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(),A.end());
    rep(i,M){
        ll b; cin>>b;
        if(A[0]<b && b<=A[N-1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll x = A[N/2];
    ll ans = 0;
    rep(i,N) {
        ans += abs(A[i]-x);
    }
    cout<<ans<<endl;
    return 0;
}