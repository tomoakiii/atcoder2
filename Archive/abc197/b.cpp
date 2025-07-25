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
    ll H,W,X,Y;
    cin >> H>>W>>Y>>X;
    vector<string> S(H);
    rep(i,H) cin>>S[i];

    X--,Y--;
    int x=X+1;
    int cnt = 0;
    while(x<=W-1)if(S[Y][x++]=='.')cnt++;else break;
    x=X-1;
    while(x>=0) if(S[Y][x--]=='.')cnt++;else break;
    int y=Y+1;
    while(y<=H-1) if(S[y++][X]=='.')cnt++;else break;
    y=Y-1;
    while(y>=0) if(S[y--][X]=='.')cnt++;else break;
    cout<<cnt+1<<endl;
    return 0;
}