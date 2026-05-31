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
typedef modint1000000007 mint;

int main() {
    int N,W,L,R; cin>>N>>W>>L>>R;
    vector<ll> X(N+2);
    rep(i,N) cin>>X[i+1];
    X[N+1] = W;
    N+=2;
    vector<mint> cnt(N);
    vector<mint> SM(N);
    cnt[0] = 1; SM[0] = 1;
    for(int i=1; i<N; i++) {
        int l = lower_bound(X.begin(), X.end(), X[i]-R) - X.begin();
        int r = upper_bound(X.begin(), X.end(), X[i]-L) - X.begin();
        if(l<r) {
            if(l>0) cnt[i] = SM[r-1] - SM[l-1];
            else cnt[i] = SM[r-1];
        }
        SM[i] = SM[i-1] + cnt[i];
    }
    cout << cnt[N-1].val() << endl;
}