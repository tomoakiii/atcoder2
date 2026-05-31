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
    ll H,W;
    cin >> H>>W;
    vector A(H, vector<ll>(W));
    rep(i,H)rep(j,W) cin>>A[i][j];

    rep(i,H) rep(j,W) {
        for(int i2=i+1; i2<H; i2++) for(int j2=j+1; j2<W; j2++) {
            if(A[i][j] + A[i2][j2] > A[i2][j] + A[i][j2]) {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;

    return 0;
}