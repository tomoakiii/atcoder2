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
    int N, M;
    cin >> N >> M;
    vector<ll> A(N+1);
    rep(t, M){
        int l, r;
        cin>>l>>r;
        l--;
        A[l]++; A[r]--;
    }
    rep(i,N) {
        A[i+1] += A[i];
    }
    ll mn = INF;
    rep(i,N) {
        chmin(mn, A[i]);
    }
    cout << mn << endl;
    return 0;
}