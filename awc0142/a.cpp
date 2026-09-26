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
    ll N,M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i,N)cin>>S[i];
    ll x0=INF,y0=INF,x1=0,y1=0;
    rep(i,N)rep(j,M){
        if(S[i][j]=='#'){
            chmax(x1,j);
            chmax(y1,i);
            chmin(x0,j);
            chmin(y0,i);
        }
    }
    cout<<(y1-y0+1)*(x1-x0+1)<<endl;
    return 0;
}