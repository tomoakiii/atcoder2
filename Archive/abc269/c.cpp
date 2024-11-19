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
    ll x = 0;
    int k=0;
    vector<int> pos{};
    
    while(N) {
        if (N%2 == 1) {
            pos.push_back(k);
        }
        k++;
        N/=2;
    }
    ll l = pos.size();
    for(ll i=0; i<((ll)1<<l); i++) {
        ll x = 0;
        rep(k, l) {
            if((i>>k) & 1) {
                x += (((ll)1) << pos[k]);
            }
        }
        cout << x << endl;
    }
    return 0;
}