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
    vector<ll> H(N);
    const int M = 3001;    
    rep(i,N) cin>>H[i];
    ll ans = 1;
    rep(i,N) {
        for(int j=1; j<N; j++) {
            ll c = 0;
            for(int nx = i; nx < N; nx += j) {
                if(H[nx] != H[i]) break;
                else c++;
            } 
            chmax(ans, c);
        }        
    }

    cout << ans << endl;
    return 0;
}