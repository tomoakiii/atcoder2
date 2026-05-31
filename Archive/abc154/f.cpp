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
    ll N,M;
    cin >> N >> M;
    vector A0, A1;
    rep(i,N) {
        cin>>A[i];
        A[i] %= M;
    }
    ll c = 0;
    ll cnt = 0;
    sort(A.begin(), A.end());
    rep(i,N) {        
        A0.push_back(A[i]);
        if(i == (N+1)/2) swap(A0, A1);        
    }
    int sz = A0.size();
    ll mn = *A1.begin();
    ll mx = *A1.rbegin();
    rep(k, 1<<sz) {
        ll sm = 0;
        rep(i, sz) {
            sm += A0[i];
        }
    }
    return 0;
}