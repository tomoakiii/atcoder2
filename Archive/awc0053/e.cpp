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
typedef modint998244353 mint;

vector<vector<mint>> mul(vector<vector<mint>> &A, vector<vector<mint>> &B){
    int sz0 = A.size();
    int sz1 = B[0].size();
    int sz2 = A[0].size();
    vector out(sz0, vector<mint>(sz1));
    rep(i,sz0) {
        rep(j,sz1) {
            rep(k,sz2) {
                out[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return out;
}

void show(vector<vector<mint>> &A){
    cout<<"-----"<<endl;
    rep(i, A.size()) {
        rep(j, A[0].size()) {
            cout<<A[i][j].val()<<" \n"[j==A[0].size()-1];
        }
    }
    cout<<endl;
}

int main(){
    ll N,M,K; cin>>N>>M>>K;
    vector A(N, vector<mint>(N));
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--,v--;
        A[v][u] = w;
    }
    //show(A);
    vector E(N, vector<mint>(N));
    rep(i,N) E[i][i]=1;
    while(K) {
        if(K%2) E = mul(A, E);
        // show(E);
        A = mul(A, A);
        K/=2;
    }
    vector vec(N, vector<mint>(1,0));
    vec[0][0] = 1;

    auto out = mul(E, vec);
    cout << out[N-1][0].val() << endl;
    return 0;
}
