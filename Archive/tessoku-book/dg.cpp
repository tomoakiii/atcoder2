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
typedef pair<ll, pair<int,int>> pl;
typedef modint1000000007 mint;

int main(){
    ll N,X,Y; cin>>N>>X>>Y;
    int cnt = 0;
    ll p = 0;
    rep(i,N) {
        ll a; cin>>a; a%=5;
        ll x = 0;
        if(a == 4) x = 2;
        else if(a >= 2) x = 1;
        p ^= x;
    }

    if(p != 0) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
