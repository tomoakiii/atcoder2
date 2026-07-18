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

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> D(N);
    rep(i,N) cin>>D[i];
    vector<ll> P(N,-1);
    rep(i,M) {
        ll p,s; cin>>p>>s;
        p--;
        P[p] = s;
    }
    rep(i,N-1){
        K-=D[i];
        if(P[i] != -1) {
            chmax(K,P[i]);
        }
        if(K<=0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}