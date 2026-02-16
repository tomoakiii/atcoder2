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
typedef pair<ll, pair<int,int>> pl;
typedef modint1000000007 mint;

int main(){
    ll N; cin>>N;
    vector A(N, vector<ll>(N));
    rep(i,N) rep(j,N) cin>>A[i][j];
    vector<int> ord(N);
    rep(i,N) ord[i] = i;
    int Q; cin>>Q;
    while(Q--) {
        int q,x,y; cin>>q>>x>>y;
        x--; y--;
        if(q==1) {
            swap(ord[x], ord[y]);
        } else {
            cout << A[ord[x]][y] << endl;
        }
    }
    return 0;
}