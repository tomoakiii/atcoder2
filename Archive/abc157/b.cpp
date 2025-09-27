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
    int A[3][3];
    rep(i,3) rep(j,3) cin>>A[i][j];
    int N; cin>>N;
    while(N--){
        int b; cin>>b;
        rep(i,3) rep(j,3) if(A[i][j] == b) A[i][j] = -1;
    }
    bool f = false;
    rep(i,3) {
        int cnt = 0;
        rep(j,3) if(A[i][j] == -1) cnt++;
        if(cnt==3) f = true;
        cnt = 0;
        rep(j,3) if(A[j][i] == -1) cnt++;
        if(cnt==3) f = true;
    }
    int cnt = 0;
    rep(i,3) {
        if(A[i][i] == -1) cnt++;
    }
    if(cnt==3) f = true;
    cnt = 0;
    rep(i,3) {
        if(A[2-i][i] == -1) cnt++;
    }
    if(cnt==3) f = true;
    if(f) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}