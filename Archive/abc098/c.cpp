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
    string S;
    cin >> N >> S;
    vector<ll> A(N);
    rep(i,N) {
        char c = S[i];
        if(c=='E') A[i] = 0;
        else A[i] = 1;
    }
    ll ans = INF;
    rep(i,N-1) A[i+1] += A[i];
    rep(i,N) {
        ll c0=0, c1=0;
        if(i>0) {
            c0 = A[i];
        }
        if(i<N-1) {
            c1 = (N-1-i) - (A[N-1] - A[i]);
        }
        chmin(ans, c0+c1);
    }
    cout<<ans<<endl;
    return 0;
}