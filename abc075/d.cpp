#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x7F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> X(N),Y(N);
    rep(i,N) cin>>X[i]>>Y[i];   
    vector X2 = X, Y2 = Y;
    sort(X2.begin(), X2.end());
    sort(Y2.begin(), Y2.end());
    ll mn = (X2[N-1] - X2[0]) * (Y2[N-1] - Y2[0]);
    rep(x0,N) for(int x1=x0+1;x1<N;x1++)
    rep(y0,N) for(int y1=y0+1;y1<N;y1++) {
        ll cnt = 0;
        rep(k,N) {
            if(X2[x0] <= X[k] && X[k] <= X2[x1] && Y2[y0] <= Y[k] && Y[k] <= Y2[y1]) cnt++;
        }
        if(cnt>=K) chmin(mn, (X2[x1]-X2[x0])*(Y2[y1]-Y2[y0]));
    }
    cout<<mn<<endl;
    return 0;
}