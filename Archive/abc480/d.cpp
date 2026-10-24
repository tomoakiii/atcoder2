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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    rep(i,N-1) A[i+1]+=A[i];
    auto B=A;
    rep(i,N-1) B[i+1]+=B[i];

    while(Q--){
        auto func= [&](ll x)->ll{
            if(x==1) {
                return B[0];
            }
            ll ok=1, ng=N;
            while(ng-ok>1){
                ll c=(ok+ng)/2;
                if(c*(c+1)<2*x) ok=c;
                else ng=c;
            }
            ll ret=0;
            ret += B[ok-1];
            ll p = ok*(ok+1)/2;
            ll rem = x-p;
            rem--;
            if(rem>=0) ret += A[rem];
            return ret;
        };

        ll l,r; cin>>l>>r;
        if(l==1) cout<< func(r) << endl;
        else cout << func(r) - func(l-1) << endl;
    }
    return 0;
}