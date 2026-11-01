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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> X(N), L(N), R(N);
    rep(i,N) cin>>X[i];
    rep(i,N){
        L[i] = X[i]-X[0];
        R[i] = X[N-1]-X[i];
    }
    rep(i,N){
        ll ans=INF;
        if(i==0){
            ans=R[0];
        } else if (i==N-1){
            ans=L[N-1];
        } else {
            chmin(ans, max(R[i], L[i+1]));
            chmin(ans, max(L[i], R[i-1]));
        }
        cout << ans/2 << endl;
    }
    return 0;
}