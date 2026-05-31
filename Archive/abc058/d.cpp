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
int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> X(N),Y(M);
    rep(i,N) cin>>X[i];
    rep(i,M) cin>>Y[i];
    mint xsm = 0, ysm = 0;
    rep(kkk,2) {
        ll cnt = N-1;
        ll cnt2 = 1;
        for(int n=N-1; n>=1; n--) {
            xsm += cnt * X[n];
            cnt--;
        }
        for(int n=N-2; n>=0; n--) {
            xsm -= cnt2 * X[n];
            cnt2++;
        }
        swap(xsm,ysm);
        swap(X,Y);
        swap(N,M);
    }
    mint ans = xsm* ysm;
    cout<<ans.val()<<endl;
    return 0;
}