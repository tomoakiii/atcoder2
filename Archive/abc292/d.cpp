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
    vector A(N, 0);

    ll sm = 0;
    rep(i, N) {
        cin >> A[i];
        sm += A[i];
    }
    
    cout << sm << endl;
    return 0;
}#include <atcoder/all>
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
    ll N, M;
    cin >> N >> M;
    dsu d(N);
    vector<ll> U(M), V(M);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        U[i] = u, V[i] = v;
        if (d.same(u, v)) continue;
        d.merge(u, v);
    }
    vector<ll> l(N);
    
    rep(i, M) l[d.leader(U[i])]++;
    rep(i, N){
        if (l[d.leader(i)] != d.size(i)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}