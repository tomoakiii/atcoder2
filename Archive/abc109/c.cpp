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
    ll N,X;
    cin >> N >> X;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    A.push_back(X);
    sort(A.begin(), A.end());
    ll g = A[1]-A[0];
    rep(i,N) {
        g = gcd(g, A[i+1]-A[i]);
    }
    cout<<g<<endl;
    return 0;
}