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
    vector<ll> P(N), P2(N);
    rep(i,N) cin>>P[i];
    rep(i,N) {
        P[i]--;
        P2[P[i]]=i;
    }
    while(Q--){
        int quer; cin>>quer;
        if(quer==2){
            swap(P,P2);
        } else{
            int x,y; cin>>x>>y; x--,y--;
            int a=P[x], b=P[y];
            swap(P[x],P[y]);
            P2[a]=y; P2[b]=x;
        }
    }
    rep(i,N){
        cout << P[i]+1 << " \n"[i==N-1];
    }
    return 0;
}