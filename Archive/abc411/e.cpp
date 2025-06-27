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
typedef modint998244353 mint;
int main(){
    ll N;
    cin >> N;
    vector A(N, vector<ll>(6));
    vector<pair<ll, int>> ind(6*N);    
    rep(i,N) {
        rep(j,6) {
            cin>>A[i][j];
            ind[i*6+j] = {A[i][j], i};
        }
    }
    
    sort(ind.begin(), ind.end());
    vector<int> cnt(N);    
    mint e = 1;
    vector<mint> div6(7);
    for(int i = 1; i<=6; i++) {
        mint mp = i;
        div6[i] = 1/mp;
    }
    int rm = N;
    int st = 0;
    ll val = 0;
    while(rm > 0) {
        auto [a, j] = ind[st];
        cnt[j]++;
        st++;
        if(cnt[j] == 1) {
            rm--;
            val = a;
            if(rm == 0) break;
        }                
    }
    rep(i,N) {
        e *= (cnt[i] * div6[6]);
    }
    mint ans = e * val;
    for(int i = st; i < ind.size(); i++) {
        auto [a, j] = ind[i];
        ans += (a * e * div6[cnt[j]]);
        cnt[j]++;
        e *= cnt[j] * div6[cnt[j]-1];
    }
    cout << ans.val() << endl;
    return 0;
}