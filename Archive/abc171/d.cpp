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
    vector<ll> A(N);
    ll sm = 0;
    map<ll,ll> mp;
    rep(i,N) {
        cin>>A[i];
        sm += A[i];
        mp[A[i]]++;
    }
    ll Q; cin >> Q;
    while(Q--) {
        ll b, c;
        cin >> b >> c;
        sm -= b * mp[b];
        sm += c * mp[b];
        mp[c] += mp[b];
        mp[b] = 0;
        cout << sm << endl;
    }
    return 0;
}