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
    ll N,L,K; cin>>N>>L>>K;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
    }
    A.push_back(L);
    ll ok = 0, ng = L+1;
    while(ng-ok > 1) {
        ll c = (ok+ng)/2;
        ll p = 0;
        ll last = 0;
        rep(i,N+1) {
            if(A[i] >= last + c) {
                p++;
                last = A[i];
            }
        }
        if(p >= K+1) {
            ok = c;
        } else {
            ng = c;
        }
    }
    cout << ok << endl;
}