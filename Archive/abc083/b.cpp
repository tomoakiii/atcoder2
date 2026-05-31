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
    ll N,A,B;
    cin >> N >> A >> B;
    ll ans = 0;
    for(ll i = 1; i <= N; i++) {
        ll k = i;
        ll sm = 0;
        while(k) {
            sm += k%10;
            k/=10;
        }
        if(A<=sm && sm<=B)  ans+=i;
    }
    cout<<ans<<endl;
    return 0;
}