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
    rep(i,N) cin>>A[i];
    ll ans = 0, ch = 0;
    ll eu = 0;
    rep(i,N) {
        ans += abs(A[i]);
        chmax(ch, abs(A[i]));
        eu += A[i]*A[i];
    }
    cout<<ans<<endl;
    printf("%.13f\n", sqrt((double)eu));
    cout<<ch<<endl;
        
    return 0;
}