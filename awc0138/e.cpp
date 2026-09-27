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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M,K,T;
    cin >> N >> M >> K >> T;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    while(K--){
        int y,x,l;cin>>y>>x>>l;
        string P; cin>>P;
        y--,x--;
        for(auto c:P){
            int ny=y,nx=x;
            if(c=='R')x++;
            if(c=='L')x--;
            if(c=='U')y--;
            if(c=='D')y++;
            if(x<0||x>=M||y<0||y>=N){
                y=ny,x=nx;
            } else if (S[y][x] == '#') {
                y=ny,x=nx;
            }
        }
        cout<<y+1<<" "<<x+1<<endl;
    }
    return 0;
}