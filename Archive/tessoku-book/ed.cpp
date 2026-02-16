// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bd
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
typedef pair<ll, pair<int,int>> pl;
typedef modint998244353 mint;


int main(){
    ll N,K; cin>>N>>K;
    auto func = [](ll x)->ll {
        ll sm = 0;
        ll X = x;
        while(x > 0) {
            sm += x % 10;
            x /= 10;
        }
        X -= sm;
        return X;
    };
    vector dp(100, vector<ll>(N+1));
    rep(i,N+1) {
        dp[0][i] = i;
    }
    rep(i,N) {
        dp[1][i+1] = func(i+1);
    }
    for(int j=2;j<100;j++) {
        rep(i,N+1) {
            ll nx = dp[j-1][i];
            dp[j][i] = dp[j-1][nx];
        }
    }

    vector<int> nm;
    int c = 1;
    while(K) {
        if(K%2) nm.push_back(c);
        K/=2;
        c++;
    }

    rep(i,N) {
        int p = i+1;
        for(auto n: nm){
            p = dp[n][p];
        }
        cout << p << endl;
    }

    return 0;
}