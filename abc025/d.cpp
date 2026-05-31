#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
typedef unsigned long long ull;

const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef modint1000000007 mint;
int main(){
    int N=5;
    auto xy2i = [&](int x, int y)->int{
        return x*N + y;
    };
    auto i2xy = [&](int i)->pair<int,int>{
        return {i/N, i%N};
    };
    vector A(N,vector<int>(N));
    vector<ll> pos(26,-1);
    rep(i,N)rep(j,N) {
        cin>>A[i][j];
        pos[A[i][j]] = xy2i(i,j);
    }
    ll full = 1ll<<25;
    vector<mint> dp(full, 0);
    dp[0] = 1;
    mint ans = 1;
    rep(S,full){
        int a = popcount(ull(S));
        a++;
        if(dp[S].val()==0) continue;
        rep(i,25) {
            if(S >> i & 1) continue; // visited
            auto [x,y] = i2xy(i);
            if(A[x][y]!=0 && A[x][y]!=a) continue; // fixed value but not matched
            if(pos[a]!=-1 && pos[a]!=i) continue;
            bool flg = true;
            if(x!=0 && x!=N-1) {
                int ni = xy2i(x+1,y);
                int pi = xy2i(x-1,y);
                if((S >> ni & 1) != (S >> pi & 1)) flg = false; // prohibited
            }
            if(y!=0 && y!=N-1) {
                int ni = xy2i(x,y+1);
                int pi = xy2i(x,y-1);
                if((S >> ni & 1) != (S >> pi & 1)) flg = false; // prohibited
            }
            if(flg) dp[S|(1ll<<i)] += dp[S];
        }
    }
    cout<<dp[full-1].val()<<endl;
    return 0;
}