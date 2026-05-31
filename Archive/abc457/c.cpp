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
    vector A(N,vector<ll>{});
    rep(i,N) {
        int L; cin>>L;
        rep(j,L){
            ll a; cin>>a;
            A[i].push_back(a);
        }
    }
    vector<ll> C(N);
    rep(i,N) cin>>C[i];

    int id=0;
    K--;

    for(int i=0; K>=C[i]*A[i].size(); i++,id++) {
        K-=C[i]*A[i].size();
    }
    cout<<A[id][K%A[id].size()]<<endl;
    return 0;
}