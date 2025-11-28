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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N), F(N);
    ll sm = 0;
    rep(i,N) {
        cin>>A[i];
        sm += A[i];
    }
    sm -= K;
    rep(i,N) cin>>F[i];
    if(sm <= 0) {
        cout << 0 << endl;
        return 0;
    }
    sort(A.rbegin(), A.rend());
    sort(F.begin(), F.end());
    ll ng = 0, ok = 2e12;
    while(ok - ng > 1) {
        ll c = (ok + ng) / 2;
        ll cnt = 0;
        rep(i,N) {            
            ll t = c/F[i];
            ll p = A[i] - t;
            if(p > 0) cnt += p;
        }
        if(cnt <= K) ok = c;
        else ng = c;
    }
    cout << ok << endl;
    return 0;
}