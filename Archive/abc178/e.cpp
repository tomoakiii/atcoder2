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
    vector<ll> X(N), Y(N);
    ll mxa=-INF, mna=INF, mxb=-INF, mnb=INF;
    rep(i,N) {
        cin>>X[i]>>Y[i];
        ll alp = X[i] + Y[i], bet = X[i] - Y[i];
        chmax(mxa, alp);
        chmin(mna, alp);
        chmax(mxb, bet);
        chmin(mnb, bet);        
    }
    cout << max(abs(mxa-mna), abs(mxb-mnb)) << endl;
    return 0;
}