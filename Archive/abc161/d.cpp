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
    ll K;
    cin >> K;
    if(K<=9) {
        cout<<K<<endl;
        return 0;
    }
    int M = 100000;
    vector dp(M, vector<ll>(10,0));
    ll cnt = 0;
    rep(i,10) {
        dp[0][i] = 1;
    }
    cnt = 9;
    rep(i, M-1) {
        rep(j, 10) {
            for(int p=-1; p<=1; p++){
                if(j+p>=0 && j+p<=9){
                    dp[i+1][j] += dp[i][j+p];          
                }
            }
            if(j!=0) cnt += dp[i+1][j];
            if(cnt<K) continue;
            cout<<j;
            rep(k,i+1){
                for(int t=1; t<=9; t++){
                    K -= dp[k][t];
                }
            }
            for(int k=1; k<j; k++){                
                K -= dp[i+1][k];
            }
            int nj = j;
            for(int k=i; k>=0; k--) {
                for(int p=-1; p<=1; p++){
                    if(nj+p>=0 && nj+p<=9 && dp[k][nj+p]<K) {
                        K-=dp[k][nj+p];
                    } else {
                        cout<<nj+p;
                        nj = nj+p;
                        break;
                    }
                }
            }
            cout<<endl;
            return 0;
        }
    }        
    return 0;
}