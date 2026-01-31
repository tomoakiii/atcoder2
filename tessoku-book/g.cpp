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
    ll D,N;
    cin >> D >> N;
    vector<ll> A(D+1);
    rep(i,N) {
        ll l,r; cin>>l>>r;
        l--, r--;
        A[l]++;
        A[r+1]--;
    }
    rep(i,D) {
        A[i+1] += A[i];
        cout<<A[i]<<endl;
    }
    return 0;
}