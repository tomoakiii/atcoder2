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
typedef modint1000000007 mint;
int main(){
    ll N; cin >> N;
    map<ll, int> mp;
    for(ll K = 2; K <= N; K++){
        ll k = K;
        ll i=2;
        while(true){
            while(k%i == 0) {
                mp[i]++;
                k /= i;
            }
            if(i*i > K) break; // break here. for(; i*i<=K ;) is NG
            i++;
        }
        if (k!=1) mp[k]++; // don't forget to add the last piece (10=2x5)
    }
    mint ans = 1;
    for(auto [v,c]: mp) {
        ans *= (c+1);
    }
    cout << ans.val() << endl;

    return 0;
}