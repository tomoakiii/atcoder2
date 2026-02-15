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

int main() {
    int N,M; cin>>N>>M;
    vector<ll>A(N);
    rep(i,M){
        ll a,b; cin>>a>>b; a--,b--;
        A[a]++;
        A[b]++;
    }
    int ans = -1;
    ll mx = 0;
    rep(i,N) {
        if(chmax(mx,A[i])) ans = i;
    }
    cout << ans +1 << endl;
}