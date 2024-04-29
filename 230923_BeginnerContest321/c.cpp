#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
int main(){
    int K;
    cin >> K;
    vector dp(10, vector<ll>(11, 0));
    int cnt = 0;
    for(int p = 0; p < 10; p++){
        dp[0][p] = 1;
        cnt++;        
    }
    for(int k = 1; k < 10; k++){
        for(int p = 0; p < 10; p++){
            for (int q = 0; q < p ; q++){
                dp[k][p] += dp[k-1][q];
            }
        }
        dp[k][10] = INF;
    }

    ll sm = 0;
    ll bs = 1; for(int i=0; i<9; i++) bs*=10;
    ll ans = 0;
    auto func = [&] (auto func, int kk, ll bst) -> void {
        for (int i=0; i<10; i++){
            if (sm + dp[kk][i] < K) {
                sm += dp[kk][i];
            } if (sm + dp[kk][i] == K){
                ans +=  bst * ll(i-1);
                func(func, kk+1, bst/10);
                break;
            } else {
                ans +=  bst * ll(i);
                func(func, kk+1, bst/10);
                break;
            }
            
        }
    };
    func(func, 9, bs);
    cout << sm << endl;
    return 0;
}