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
    ll a[2];
    cin >> a[0] >> a[1];
    ll ans[3] = {0,0,0};
    int i;
    rep(k,2){
        ll c = 1;
        rep(i,3){
            if(a[k]%2) ans[i]=c;
            a[k]/=2;
            c*=2;
        }
    }
    ll out=0;
    rep(i,3) out+=ans[i];
    cout << out << endl;
    return 0;
}