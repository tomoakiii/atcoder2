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
    cin >> N;
    map<int, ll> updt;
    rep(i, N) {
        ll a;
        cin>>a;
        updt[i] += a;
    }
    cin >> Q;
    ll lastx = 0;
    
    while(Q--){
        int t;
        cin >> t;
        if(t == 1){
            cin >> lastx;
            updt.clear();
        } else if (t == 2){
            int i;
            ll x;
            cin >> i >> x;
            i--;
            updt[i] += x;
        } else {
            int i;
            cin >> i;
            i--;
            cout << lastx + updt[i] << endl;
        }
    }
    return 0;
}