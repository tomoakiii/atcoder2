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
    string X;
    cin>>X;
    const int N = X.size();
    vector<ll> A(X.size()), out(N);
    rep(i, N) {
        A[i] = X[i] - '0';
    }
    vector<ll> imos(N + 1);
    rep(i, X.size()) {
        imos[i]+=A[i];
        imos[N]-=A[i];
    }
    rep(i,N) {
        imos[i+1] += imos[i];
    }
    ll rm = 0;
    for(int i=N-1; i>=0; i--) {
        ll k = imos[i] + rm;
        out[i] = k%10;
        rm = k/10;
    }
    if(rm > 0) {
        cout << rm;
    }
    rep(i,N) {
        cout << out[i];
    }
    cout << endl;
    return 0;
}