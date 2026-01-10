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
    ll N,Q; cin>>N>>Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    A.push_back(INF);
    sort(A.begin(), A.end());
    while(Q--){
        ll X,Y; cin>>X>>Y;
        int it1 = lower_bound(A.begin(),A.end(),X)-A.begin();
        if(A[it1] - X >= Y) {
            cout << X+Y-1 << endl;
            continue;
        }
        ll ng = it1, ok = X+Y+N+10;
        while(ok-ng > 1) {
            int c = (ok+ng)/2;
            int it2 = upper_bound(A.begin(),A.end(),c)-A.begin();
            ll p = it2 - it1;
            if(c - X + 1 >= Y + p) ok = c;
            else ng = c;
        }
        cout << ok << endl;
    }
    return 0;
}