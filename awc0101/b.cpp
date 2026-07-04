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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ok=1e9, ng=0;
    while(ok-ng>1){
        ll c=(ok+ng)/2;
        ll nx=0;
        bool flg=true;
        rep(i,N){
            ll a=A[i]-(c+nx);
            if(a<=0)nx=1;
            else{
                flg=false;
                break;
            };
        }
        if(flg) ok=c;
        else ng=c;
    }
    cout<<ok<<endl;
    return 0;
}