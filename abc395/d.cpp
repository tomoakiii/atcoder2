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
    vector<ll> nest(N);
    vector<ll> label(N);
    vector<ll> lpos(N);
    rep(i,N) {
        nest[i] = i;
        label[i] = i;
        lpos[i] = i;
    }
    vector<ll> lpos(N);
    while(Q--) {
        int p;
        cin >> p;
        if(p == 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            nest[a] = b;
        } else if(p == 2) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            swap(label[a], label[b]);
            
        } else {
            int a;
            cin >> a;
            a--;
            int n = nest[a];
            cout << nind[n] + 1 << endl;
        }
    }
    return 0;
}
