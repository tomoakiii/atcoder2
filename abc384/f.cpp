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
typedef pair<ll, ll> pll;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll sm = 0;
    vector<pll> V(N);
    map<pll, int> mp;
    rep(i,N) {
        ll a = A[i];
        ll c = 0;
        while(a > 0 && a % 2 == 0) {
            c++;
            a/=2;
        }
        pll v = {c, a};
        V[i] = c;
        mp[c]++;
    }
    rep(i,N) {
        pll s = 
    }
    cout << sm << endl;


    return 0;
}