#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    
    ll ok = 1, ng = 1e16;
    while(ng-ok>1) {
        ll c=(ok+ng)/2;
        ll cnt = 0;
        ll sm = 0;
        rep(i,N) {
            if(sm < c) sm += A[i];
            else {
                sm = A[i];
                cnt++;
            }
        }
        if(sm >= c) cnt++;
        if(cnt >= K) ok = c;
        else ng = c;
    }
    cout << ok << endl;
    return 0;
}