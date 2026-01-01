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
    ll T,A; cin>>T>>A;
    rep(i,N-1) {
        ll t,a; cin>>t>>a;
        ll p = (T+t-1)/t;
        ll t1 = p * t;
        ll a1 = p * a;
        p = (A+a-1)/a;
        ll a2 = p * a;
        ll t2 = p * t;
        if(a1 < A) {
            T = t2, A = a2;
        } else if (t2 < T) {
            T = t1, A = a1;
        } else if(t1 < t2) {
            T = t1, A = a1;
        } else {
            T = t2, A = a2;
        }
        cerr << T << " " << A << endl;
    }
    cout << T + A << endl;
    return 0;
}