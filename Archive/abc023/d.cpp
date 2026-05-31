#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef  long long ll;
const ll INF = 1ll<<60;
const int INFi = 1<<30;

int main(){
    ll N; cin >> N;
    vector<ll> H(N),S(N);
    rep(i,N) cin>>H[i]>>S[i];
    ll l = 0, r = INF;
    while(r - l > 1) {
        ll c = (l+r) / 2;
        bool flg = true;
        vector<ll> T(N,0);
        rep(i, N) {
            if(c>=H[i])T[i] = (c-H[i])/S[i];
            else flg = false;
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