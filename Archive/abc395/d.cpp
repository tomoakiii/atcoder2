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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> p2b(N);
    vector<ll> b2n(N);
    vector<ll> n2b(N);
    rep(i,N) {
        p2b[i] = i;
        b2n[i] = i;
        n2b[i] = i;
    }
    vector<ll> lpos(N);
    while(Q--) {
        int p;
        cin >> p;
        if(p == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;            
            int to_b = n2b[y];
            p2b[x] = to_b;
        } else if(p == 2) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            int xo = n2b[x];
            int yo = n2b[y];
            swap(n2b[x], n2b[y]);
            swap(b2n[xo], b2n[yo]);
        } else {
            int a;
            cin >> a;
            a--;            
            cout << b2n[p2b[a]] + 1 << endl;
        }
    }
    return 0;
}
