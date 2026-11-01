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
    ll N,P1,Q1,P2,Q2;
    cin>>N>>P1>>Q1>>P2>>Q2;
    vector<ll> X(N),Y(N),A(N),B(N);
    rep(i,N)cin>>X[i]>>Y[i];
    rep(i,N)cin>>A[i]>>B[i];
    vector dist(N, vector<ll>(N));
    rep(i,N)rep(j,N){
        ll x=X[i],y=Y[i],a=A[j],b=B[j];
        ll cnt=0;
        ll dy=abs(y-b);
        while(b>y){
            ll y2=y*P2;
            y2 /= Q2;
            if(abs(y2-b) >= dy) {
                cnt=INF;
                break;
            }
            dy = abs(y2-b);
            cnt++;
        }

        rep(k,cnt){
            a/=
        }
    }
    return 0;
}