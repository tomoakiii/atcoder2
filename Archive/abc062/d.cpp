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
    vector<ll> A(3*N);
    rep(i,3*N) cin>>A[i];
    ll ans = -INF;
    multiset<ll> a_hi, b_hi, b_lo;
    ll ahsm = 0;
    rep(i,N) {
        a_hi.insert(A[i]);
        ahsm += A[i];
    }
    for(int i=N; i<3*N; i++) {
        b_hi.insert(A[i]);
    }
    ll blsm = 0;
    rep(i,N) {
        auto it = b_hi.begin();
        b_lo.insert(*it);
        blsm += *it;
        b_hi.erase(it);
    }
    chmax(ans, (ahsm - blsm));
    for(int i=N; i<2*N; i++){
        if(b_hi.contains(A[i])) {
            b_hi.erase(b_hi.find(A[i]));
        } else {
            b_lo.erase(b_lo.find(A[i]));
            blsm -= A[i];
            auto it = b_hi.begin();
            b_lo.insert(*it);
            blsm += *it;
            b_hi.erase(it);
        }
        a_hi.insert(A[i]);
        ahsm += A[i];
        auto it = a_hi.begin();
        ahsm -= *it;
        a_hi.erase(it);
        chmax(ans, (ahsm - blsm));
    }
    cout<<ans<<endl;
    return 0;
}