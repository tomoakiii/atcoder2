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
    ll N,M,X,T,D;
    cin >> N >> M >> X >> T >> D;
    vector<int> l(N+1);
    l[X] = T;
    for(int i=X-1; i>=0; i--) {
        l[i] = l[i+1] - D;
    }
    if(M >= X) cout << T << endl;
    else cout << l[M] << endl;
    return 0;
}