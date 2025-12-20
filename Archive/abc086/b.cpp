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
    ll a,b; cin>>a>>b;
    int d = 10;
    if(b == 100) d=1000;
    else if(b>=10) d=100;
    ll x = d*a + b;
    for(ll k=1; k*k<=x; k++) {
        if(k*k == x) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout << "No" << endl;
}