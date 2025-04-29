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
    ll N;
    string T;
    cin>>N>>T;
    int d=0;
    int x=0, y=0;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,-1,0,1};

    rep(i,N){
        if(T[i]=='S') {
            y+=dy[d];
            x+=dx[d];
        } else {
            d++;
            d%=4;
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}