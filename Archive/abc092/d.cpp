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
    ll A,B; cin>>A>>B;
    vector G(100, vector<int>(100));
    int i = 0, j = 0;
    rep(h, 50) rep(j,100) G[h][j] = 1;

    while(A>1) {
        while(j < 100 && A>1) {
            G[i][j] = 0;
            A--;
            j += 2;
        }
        j = 0;
        i += 2;
    }


    rep(i,100) reverse(G[i].begin(), G[i].end());
    reverse(G.begin(), G.end());
    i = 0, j = 0;

    while(B>1) {
        while(j < 100 && B>1) {
            G[i][j] = 1;
            B--;
            j += 2;
        }
        j = 0;
        i += 2;
    }


    cout<<"100 100"<<endl;
    rep(i,100) {
        rep(j,100) cout<<((G[i][j]==1)?'#':'.');
        cout<<endl;
    }
    return 0;
}