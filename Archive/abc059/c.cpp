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
    ll N;
    cin >> N;
    ll aans = INF;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    rep(kkk,2) {
        ll ans = 0;
        ll sm=0;
        int ix = kkk;
        rep(i,N) {
            if(ix == 1) {
                sm += A[i];
                if(sm >= 0) {
                    ans += (sm+1);
                    sm = -1;
                }
                ix = 0;
            } else {
                sm += A[i];
                if(sm <= 0) {
                    ans += (-sm + 1);
                    sm = 1;
                }
                ix = 1;
            }
        }
        chmin(aans, ans);
    }
    cout << aans << endl;
    return 0;
}