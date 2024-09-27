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
    ll L;
    cin >> L;
    ll N1, N2;
    cin >> N1 >> N2;
    vector<ll> va(N1), la(N1), vb(N2), lb(N2);
    vector lasm = la, lbsm = lb;
    rep(i, N1) cin >> va[i] >> la[i];
    rep(i, N2) cin >> vb[i] >> lb[i];
    rep(i, N1-1) lasm[i+1] += lasm[i];
    rep(i, N2-1) lbsm[i+1] += lbsm[i];
    ll cnta = 0, cntb = 0;
    int ca = 0, cb = 0;
    ll ans = 0;
    while(true){
        ll nx = 
        if (va[ca] == vb[cb]) {

        }
        if(cnta + la[ca] > cntb + lb[cb])

    }
    
    cout << sm << endl;
    return 0;
}