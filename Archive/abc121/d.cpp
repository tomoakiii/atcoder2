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
    auto func = [](auto func, ll x)->ll{
        if(x % 2 == 1) {
            if( (x+1) % 4 == 0) return 0;
            else return 1;
        } else {
            return (func(func, x+1) ^ (x+1));
        }
    };
    if(a==0) cout<<func(func,b)<<endl;
    else cout << (func(func, b) ^ func(func, a-1)) << endl;
    return 0;
}