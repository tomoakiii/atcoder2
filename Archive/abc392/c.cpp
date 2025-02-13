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
    vector<ll> P(N), Q(N), Q2(N);
    rep(i,N) {
        cin>>P[i];
        P[i]--;
    }

    rep(i,N) {
        ll q;
        cin>>q;
        q--;
        Q[i] = q;
        Q2[q] = i; 
    }

    rep(i,N) {
        int ps = Q2[i];
        int pt = P[ps];
        cout << Q[pt]+1 << " ";
    }
    cout << endl;
    return 0;
}