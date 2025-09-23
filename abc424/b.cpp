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
    ll sc[10][10];
    ll N,M,K; 
    cin >> N>>M>>K;
    rep(i,K) {
        ll a,b; cin>>a>>b;
        a--, b--;
        sc[a][b] = 100;
        bool f = true;
        rep(b,M) {
            if(sc[a][b] != 100) {
                f = false;
                break;
            }
        }
        if(f) cout << a+1 << endl;        
    }
    return 0;
}