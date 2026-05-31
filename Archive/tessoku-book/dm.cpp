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
    ll N; cin>>N;
    map<int,int> mp;
    vector<ll> A(N);
    rep(i,N) {
        ll a; cin>>a; a%=100;
        mp[a]++;
        A[i] = a;
    }
    ll ans = 0;
    rep(i,N) {
        if(A[i] == 50) ans += mp[50] - 1;
        else if(A[i] == 0) ans += mp[0] - 1;
        else ans += mp[100-A[i]];
    }
    cout << ans/2 << endl;
    return 0;
}