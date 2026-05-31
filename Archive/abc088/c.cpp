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
    vector C(3, vector<int>(3));
    rep(i,3) rep(j,3) cin>>C[i][j];
    int a[] = {-200,-200,-200}, b[]={-200,-200,-200};
    for(a[0] = 0 ; a[0] <= 100; a[0]++) {
        rep(k,3) b[k] = C[0][k] - a[0];
        a[1] = C[1][0] - b[0];
        a[2] = C[2][0] - b[0];
        bool t = true;
        rep(i,3) rep(j,3) {
            if(C[i][j] != a[i] + b[j]) t = false;
        }
        if(t) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;

    return 0;
}