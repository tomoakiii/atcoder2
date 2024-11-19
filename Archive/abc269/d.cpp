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
    dsu UF(N);
    int nx[] = {-1, -1,  0, 0, 1, 1};
    int ny[] = {-1,  0, -1, 1, 0, 1};
    vector<ll> X(N), Y(N);
    rep(i,N) {
        cin >> X[i] >> Y[i];        
    }
    rep(i, N) rep(j, N) rep(k,6) {
        if (X[i] + nx[k] == X[j] && Y[i] + ny[k] == Y[j]) UF.merge(i, j);
    }
    cout << (int)UF.groups().size() << endl;
    return 0;
}