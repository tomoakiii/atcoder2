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
    vector<ll> X(N);
    rep(i,N) cin>>X[i];
    if(K==N){
        cout<<0<<endl;
        return 0;
    }
    sort(X.begin(),X.end());
    ll ok=1e10, ng=0;
    while(ok-ng>1){
        ll c=(ok+ng)/2;
        ll last = -INF;
        ll cnt=0;
        rep(i,N){
            if(X[i]>last+c){
                cnt++;
                last=X[i];
            }
        }
        if(cnt<=K) ok=c;
        else ng=c;
    }
    cout<<ok<<endl;
    return 0;
}