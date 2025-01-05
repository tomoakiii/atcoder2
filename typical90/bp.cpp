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
    int N, Q;
    cin >> N >> Q;
    dsu UF(N);
    vector<bool> ifamb;
    vector<ll> qx, qy, qv;
    vector<ll> va(N);
    while(Q--){
        ll t, x, y, v;
        cin >> t >> x >> y >> v;
        x--; y--;
        if(t==0) {
            va[x] = v;
            UF.merge(x, y);    
        }
        else {
            ifamb.push_back(UF.same(y, x));
            qx.push_back(x);
            qy.push_back(y);
            qv.push_back(v);
        }
    }
    vector<ll> vb(N);
    rep(i,N-1) {
        vb[i+1] = va[i] - vb[i];
    }
    rep(i, ifamb.size()) {
        if(!ifamb[i]) {
            cout << "Ambiguous" << endl;
        } else {
            ll d = qv[i] - vb[qx[i]];
            if (abs(qy[i] - qx[i]) % 2 == 1) {
                d *= -1;
            }
            cout << vb[qy[i]] + d << endl;
        }
    }
    return 0;
}