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
    ll N,C;
    cin >> N >> C;
    ll M = 2e5;
    vector A(C, vector<ll>(M));
    rep(i,N) {
        ll s,t,c;
        cin>>s>>t>>c;
        c--;
        A[c][s]++;
        A[c][t+1]--;
    }
    rep(i,C) rep(j,M-1) {
        A[i][j+1] += A[i][j];
    }
    rep(i,C) rep(j,M) if(A[i][j] >= 1) A[i][j] = 1;

    ll ans = 0;
    rep(j,M) {
        ll c = 0;
        rep(i,C){
            c += A[i][j];
        }
        chmax(ans, c);
    }
    cout<<ans<<endl;
    return 0;
}