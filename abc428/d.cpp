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
    ll T;
    cin >> T;
    ll mxC = 2E8;
    ll mxD = 5E9;
    auto f = [](ll x, ll y)->ll{
        return stoll(to_string(x) + to_string(y));
    };
    vector<ll> sqlist;
    ll mmx = f(mxC, mxD);
    for(ll i = 3; i*i <= mmx; i++) {
        sqlist.push_back(i*i);
    }

    while(T--){
        ll C, D; cin>>C>>D;
        ll mn = f(C, C+1);
        ll mx = f(C, C+1);


    }
    
    return 0;
}