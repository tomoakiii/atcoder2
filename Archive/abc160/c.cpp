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
    ll K,N;
    cin >> K >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll md = 0;
    rep(i,N-1) {
        chmax(md, A[i+1]-A[i]);
    }
    chmax(md, K-A[N-1]+A[0]);
    cout<<K-md<<endl;
    return 0;
}