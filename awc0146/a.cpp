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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M,Q;
    cin >> N >> M >> Q;
    vector<ll> S(N),U(N),F(N);
    rep(i,N)cin>>S[i]>>U[i]>>F[i];
    while(Q--){
        int d; char c; cin>>d>>c; d--;
        if(c=='+'){
            swap(U[d],F[d]);
            U[d]=7-U[d];
            S[d]++;
        } else {
            swap(U[d],F[d]);
            F[d]=7-F[d];
            S[d]--;
        }
    }
    rep(i,N){
        cout<<S[i]<<" "<<U[i]<<endl;
    }
    return 0;
}