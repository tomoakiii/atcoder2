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
    ll mn = INF;
    ll l = 0, r = 2e9;
    vector<ll> H(N),S(N);
    rep(i,N) cin>>H[i]>>S[i];
    while(r - l > 1) {
        ll c = (l+r) / 2;
        bool flg = true;
        vector<int> T(N,0);
        rep(i, N) {
            if(c>H[i])T[i] = (c-H[i])/S[i];
        }
        sort(T.begin(),T.end());
        rep(i,N) {
            if(T[i]<i) {
                flg = false;
            } 
        }
        if(flg) r = c;
        else l = c;
    }
    cout << r << endl;
    return 0;
}