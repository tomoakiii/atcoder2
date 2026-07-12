#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

typedef long long ll;
typedef modint998244353 mint;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string Ns;
    cin >> Ns;
    ll len = Ns.size();
    ll ful = 1ll<<10;

    vector dp1(vector(3, vector(2, vector<mint>(ful)))); // mod3, isLow, visit
    for(int j=1;j<Ns[0]-'0';j++){
        dp1[j%3][1][1ll<<j]++;
    }
    int j=Ns[0]-'0';
    dp1[j%3][0][1ll<<j]++;


    for(int i=1;i<len;i++){
        vector dp2(vector(3, vector(2, vector<mint>(ful)))); // mod3, isLow, visit
        int a = Ns[i]-'0';
        for(int j=1;j<=9;j++) {
            dp2[j%3][1][1ll<<j] = 1;
        }
        for(int j=0;j<=9;j++) {
            for(ll S=1; S<ful; S++) {
                ll nS = S | (1ll<<j);
                for(int k=0;k<=2;k++){
                    int nk=(k+j)%3;
                    dp2[nk][1][nS] += dp1[k][1][S];
                    if(j < a) dp2[nk][1][nS] += dp1[k][0][S];
                    else if(j == a) dp2[nk][0][nS] += dp1[k][0][S];
                }
            }
        }
        swap(dp1,dp2);
    }

    mint ans = 0;

    for(ll S=1; S<ful; S++) {
        int f2 = ((S & (1ll << 3))) > 0; // include 3???
        ll cnt=0;
        rep(i,10) if(S>>i & 1) cnt++; // how many numbers???
        int f3 = (cnt==3);

        for(int k=0; k<=2; k++) {
            int f1 = (k == 0);
            int mc = f1 + f2 + f3;
            if (mc == 1) {
                ans += dp1[k][0][S] + dp1[k][1][S];
            }
        }
    }

    cout << ans.val() << endl;
    return 0;
}