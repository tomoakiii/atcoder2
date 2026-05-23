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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    ll mx=0;
    rep(i,N) {
        cin>>A[i];
        chmax(mx,A[i]);
    }
    ll ng=mx-1, ok=1e15;
    while(ok-ng > 1) {
        ll c= (ok+ng)/2;
        ll sm=0,cnt=1;
        rep(i,N) {
            if(sm+A[i]>c) {
                cnt++;
                sm=A[i];
            } else {
                sm+=A[i];
            }
        }
        if(cnt > K)ng=c;
        else ok=c;
    }

    cout<<ok<<endl;
    return 0;
}