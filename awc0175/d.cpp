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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    ll ng=0;
    rep(i,N) {
        cin>>A[i];
        chmax(ng,A[i]);
    }
    ng--;
    ll ok=2e14;
    while(ok-ng>1){
        ll c=(ok+ng)/2;
        ll sm=0, cnt=1;
        rep(i,N){
            sm+=A[i];
            if(sm>c){
                sm=A[i];
                cnt++;
            }
        }
        if(cnt<=K)ok=c;
        else ng=c;
    }
    cout<<ok<<endl;
    return 0;
}