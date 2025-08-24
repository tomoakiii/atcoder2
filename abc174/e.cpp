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
    vector<ll> A(N);
    ll mx = 0;
    ll sm = 0;
    rep(i,N) {
        cin>>A[i];
        chmax(mx, A[i]);
        sm += A[i];
    }
    if(mx == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(sm <= K) {
        cout << 1 << endl;
        return 0;
    }
    ll ng = 1, ok = 1E9;
    while(ok-ng > 1) {
        ll c = (ok+ng)/2;
        ll cnt = 0;
        rep(i,N) {
            cnt += ((A[i] + c - 1) / c) - 1;
        }
        if(cnt > K) ng = c;
        else ok = c;        
    }
    cout << ok << endl;
    return 0;
}