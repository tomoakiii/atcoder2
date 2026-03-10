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
    ll N,a,b;
    cin >> N>>a>>b;
    ll ans = b*N; // all b
    ll N2=N/2;
    if(N%2 == 1) chmax(ans, (a+b/2)*N2 + a);
    else {
        chmax(ans, (a+b/2)*N2);
    }
    chmax(ans, (a/2)*(N-1) + a);
    chmax(ans, (a/2)*(N-2) + a+b);

    cout<<ans<<endl;
    return 0;
}