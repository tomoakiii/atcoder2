#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> B(N);
    rep(i,N) cin>>A[i]>>B[i];
    bool flg = true;
    rep(i,N) if(A[i]<M) flg=false;
    if(flg) {
        cout<<0<<endl;
        return 0;
    }
    ll ng=0, ok=M;
    while(ok-ng>1) {
        ll c = (ok+ng)/2;
        auto chk = [&](ll c)->bool{
            rep(i,N) {
                if(A[i]+c*B[i]<M) return false;
            }
            return true;
        };
        if(chk(c)) ok=c;
        else ng=c;
    }
    cout<<ok<<endl;
    return 0;
}